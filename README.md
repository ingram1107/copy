# copy
A trivial POSIX API based system util program that copies files.

## Warning
### Windows
This software is only using POSIX API to do all the systemcall and might crash in Windows environment. However, you can still download this software and tweak it to fit into Win32 API.

### Mac OS X and BSD Distribution
Be aware that ptrace() is specificly implemented in Linux Distribution. Its counterpart will be dtrace() so you can tweak the ptrace() into dtrace(). Other libraries probably will fit into your OS due to same implementation on POSIX API.

## Dependency
gcc
git
make

## Installation
```bash
git clone https://github.com/ingram1107/copy.git
make
```

## Usage
```bash
copy [FILE1] [FILE2]
```
