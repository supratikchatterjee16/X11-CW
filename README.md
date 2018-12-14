# X11-CW

## Introduction

A C++ Wrapper and template for easy rendering and controlling of actions to develop applications, games or any other object.
This is intended to be used parallely with computation libraries such as OpenGL, OpenCL, CUDA, etc. However, it is optional
to use them. It makes use of a triple buffering strategy inside so that one doesn't have to work with much except 
building the matrices, pushing them to the display API and setting controls for every event.


## Prerequisites

Requirements are X11 packages: xorg-server xorg-dev

'''
sudo apt install xorg xorg-dev xorg-docs
'''

## Suggested
Below are the suggested tools that you might need for development :

* OpenCL(And dependencies, look ICD )
* CUDA(And dependencies)

**Note**
This is a project under development. At the moment there is a problem with the display thread. Unless it isn't resolved, 
this project is at a stand still. However, you can utilize it if you are currently working on XLib development. 

