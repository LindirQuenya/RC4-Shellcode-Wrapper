/*
This is just a nice header file to ensure that the "abra" function is exported
properly from the DLL, and imported properly into the loader.
It is #include'd in both. If you want to export more functions, add them to the end
of the file.
*/

#ifndef RC4_ENC_DLL_H
#define RC4_ENC_DLL_H

//Checks for the building macro.
//Note: This should be defined if and only if we are building the DLL.
#ifdef DLLEXPORT
//If we have the building macro, export the functions.
#define EXPORTSTATE __declspec(dllexport)
#else
//If we don't have the building macro, the functions should be imported.
#define EXPORTSTATE __declspec(dllimport)
#endif

EXPORTSTATE void abra(unsigned char key[], int keylen);

//Add any extra functions below, remembering to use EXPORTSTATE.

#endif // RC4_ENC_DLL_H
