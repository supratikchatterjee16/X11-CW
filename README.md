# X11-CW

## Introduction

A C++ Template for easy rendering and controlling of actions to develop applications.
This is intended to be used parallely with computation libraries such as OpenGL, OpenCL, CUDA, etc. However, it is optional
to use them.


## Prerequisites

Requirements are X11 packages on linux: xorg-server xorg-dev

```shell
sudo apt install xorg xorg-dev xorg-docs
```

On windows there exists an alternative distributed by Cygwin : [Cygwin/X](https://x.cygwin.com/)

## Suggested
Below are the suggested tools that you might need for development :

* OpenCL(And dependencies, look ICD )
* CUDA(And dependencies)

## Using it

Things have been simplified to the point where everything can be managed seperately without bothering about the underlying details. This is based on the Xlib header, so most of the program is easy to understand. Learn abit about the Xlib functions to use this.

There is a sample program given. Modifications must be made in the 'events' and 'display' folders of the template code. Use the following code to execute it:

```shell
g++ yourprogram.cpp -o yourprogram -lX11
```

Please refer to any Xlib manual to use the functions. Here is a link for some popular Xlib manuals:

* [Xlib Manual from Wake Forest University](http://csweb.cs.wfu.edu/~torgerse/Kokua/Irix_6.5.21_doc_cd/usr/share/Insight/library/SGI_bookshelves/SGI_Developer/books/XLib_PG/sgi_html/index.html)
* [Xlib manual by Cristophe Tronche](https://tronche.com/gui/x/xlib/)


**Note**
Project has been completed
