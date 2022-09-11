# RC4-Shellcode-Wrapper
A small template for loading and running RC4-encrypted shellcode.

The same idea can be extended to other encryption algos, but RC4 was the easiest to implement by hand.

## Prerequisites
First, install `mingw-w64` or equivalent (`llvm-mingw` should work, might need some fiddling).

You'll need a payload from somewhere. For metasploit, it's something along the lines of
```bash
msfvenom --format c --encrypt rc4 --encrypt-key KEY -p PAYLOAD OPT1=VALUE1 OPT2=VALUE2...
```
I don't know much about other exploitation frameworks, but I imagine they have similar things.

Put the payload (and size) into `rc4_enc_dll.cpp`, and the key (and size) into `example_exe.cpp`.
I think recent versions of msfvenom will print out the payload size for you, so you won't have to count it.

