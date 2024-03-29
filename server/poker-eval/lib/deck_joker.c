#include <stdio.h>
#include <ctype.h>
#include "poker_defs.h"
#include "deck_joker.h"

const char JokerDeck_rankChars[] = "23456789TJQKA";
const char JokerDeck_suitChars[] = "hdcs";

/*
 * These implementations assume that the card indices and suit bit fields
 * between StdDeck and JokerDeck are the same!
 */

int 
JokerDeck_cardToString(int cardIndex, char *outString) {
  if (JokerDeck_IS_JOKER(cardIndex)) {
    *outString++ = 'X';
    *outString++ = 'x';
    *outString   = '\0';
    return 2;
  }
  else 
    return StdDeck_cardToString(cardIndex, outString);
}


int
JokerDeck_maskToCards(void *cardMask, int cards[]) {
  int i, n=0;
  JokerDeck_CardMask c = *((JokerDeck_CardMask *) cardMask);

  for (i=JokerDeck_N_CARDS-1; i >= 0; i--) 
    if (JokerDeck_CardMask_CARD_IS_SET(c, i)) 
      cards[n++] = i;

  return n;
}


int 
JokerDeck_stringToCard(char *inString, int *cardIndex) {

  if ((toupper(inString[0]) == 'X') && toupper(inString[1]) == 'X') {
    *cardIndex = JokerDeck_JOKER;
    return 2;
  }
  else 
    return StdDeck_stringToCard(inString, cardIndex);
}


Deck JokerDeck = { 
  JokerDeck_N_CARDS, 
  "JokerDeck", 
  JokerDeck_cardToString, 
  JokerDeck_stringToCard,
  JokerDeck_maskToCards 
};
