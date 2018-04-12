# shapeware
shape plug-ins

## Prerequisites

- Git
- Cmake
- shape https://github.com/logimic/shape 

### Windows

Install vcpkg to e.g: **c:\devel\vcpkg** https://github.com/Microsoft/vcpkg

Install via vcpkg:
```
C:\devel\vcpkg>vcpkg install cpprestsdk:x86-windows
...
C:\devel\vcpkg>vcpkg install cpprestsdk:x64-windows
...
```
It installs all other dependecies like BOOST, SSL, ZLIB, ... After succesfull instalation you would have:
```
C:\devel\vcpkg>vcpkg list cpprestsdk
cpprestsdk:x64-windows                             2.10.2           C++11 JSON,
REST, and OAuth library The C++ REST...
cpprestsdk:x86-windows                             2.10.2           C++11 JSON,
REST, and OAuth library The C++ REST...
```
### Linux

Install cpprestsdk:

$ sudo apt-get libcpprest-dev

## Build

```bash
$ git clone https://github.com/logimic/shapeware.git
$ cd shapeware
$ py shape.py --build
or
$ build32.bat         #for Win x86
$ build64.bat         #for Win x64
$ ./buildMake.sh      #for Linux
$ ./buildEclipse.sh   #for Linux Eclipse IDE
```
