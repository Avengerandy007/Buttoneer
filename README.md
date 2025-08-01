# Buttoneer
Game for GMTK2025, inspired by the job that Stanley from The Stanley Parable has.

# Build instructions
Make sure you have Make installed and in your system PATH and the MinGW version of G++. 
Download the binaries for SDL2 and the dev files.
Place them in your desired directory.
Change
```Make
SDL2Win_PATH = /usr/include/SDL2Win
```
to point to your SDL2 dev directory. **MAKE SURE THAT THE PATH DOES *NOT* INCLUDE ANY SUBDIRECTORIES!**

To actually build the binary:
```Powershell
cd Path\To\Makefile
make
```
