#ifndef __X11NORMAL
#define __X11NORMAL
#include<X11/Xlib.h>
#include<X11/Xutil.h>
#include<X11/Xos.h>
#include<X11/extensions/xf86vmode.h>

#include<iostream>
#include<stdlib.h>
#include"vars.cpp" //This contains all useful variable names to be used.
#include"structs.cpp" // Contains the datastructure for the controls
#include"init.cpp" // This stores the init function
#include"close.cpp" // This stores the closing procedure
#include"redraw.cpp" //This stores the redraw function 

#include"../events/events.hpp" // This exists in the 'events' folder and is to be kept seperate

#include"driver.cpp"// This stores the startx function that joins all together and is responsible for the main program execution.
#endif
