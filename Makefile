CPP=x86_64-w64-mingw32-g++
CFLAGS=-Os
LDFLAGS=-s

loader.exe: example_exe.cpp rc4_enc_dll.hpp rc4_shellcode.dll
	$(CPP) $(CFLAGS) $(LDFLAGS) -o loader.exe example_exe.cpp -L. -l:rc4_shellcode.dll -static-libgcc

rc4_shellcode.dll: rc4_enc_dll.hpp rc4_enc_dll.cpp
	$(CPP) $(CFLAGS) $(LDFLAGS) -D DLLEXPORT rc4_enc_dll.cpp -o rc4_shellcode.dll -shared

.PHONY: clean
clean:
	rm -f rc4_shellcode.dll loader.exe
