# Introduction #

After you fetch the code, the next step is to build it.  For this you need to use a compiler.

The server side of the code can be built using GCC on Linux and other platforms.  It should also build on windows under Visual Studio with the correct configuration.

The client side makes heavy use of MFC/ATL and needs to be built under windows with Visual Studio.  In the future, maybe the MFC portions can be ported to Windows Forms and could be built using cross-platform Mono, or at least an Express version of the Microsoft Visual Studio family.  In its production days, the client code was built using Microsoft Visual Studio 6.0.  Later (prototype) revisions have been built using Visual Studio .NET 2003.  To have any real success you're probably going to want to obtain a copy of Visual Studio 2005.

Unfortunately, the current version of Visual C++ 2005 Express Edition does not support MFC/ATL.

According to the FAQ -- http://msdn.microsoft.com/vstudio/express/support/faq/ :


_42. 	Does Visual C++ 2005 Express Edition include MFC and ATL?_


_No, MFC and ATL are not included with Visual C++ 2005 Express. MFC and ATL will be included in all other Visual Studio 2005 Editions._


# Details #

Details of the build process should go here.

Moving forward perhaps we can use a tool like SCons or NAnt.





