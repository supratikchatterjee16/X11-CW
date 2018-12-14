#ifndef __X11NORMAL
#define __X11NORMAL
#include<X11/Xlib.h>
#include<X11/Xutil.h>
#include<X11/Xos.h>

//X11 variables
Display *display;
int defaultScreen;
Window window;
GC graphics;
struct Size{
	int height,width;
};
#include<iostream>
class Color{
	public:
		int r,g,b;
		unsigned long decimal;//Decimal representation for the r,g,b
		Color(){
			r = g = b = 0;
			decimal  = 0;
		}
		Color(unsigned long d){
			decimal = d;
			b = d & 0xff;
			g = (d >> 8) & 0xff;
			r = (d >> 16) & 0xff;
		}
		Color(int red, int green, int blue){
			r = red;
			g = green;
			b = blue;
			decimal = b + (g * 256) + (r * 65536);
		}
		unsigned long printDecimal(){
			return decimal;
		}
};

struct DisplayProp{
	int height, width, depth;
}DefaultDisplayProp;

int init_x() {
/* get the colors black and white (see section for details) */        
	Color black(0), white(255,255,255);
	display = XOpenDisplay((char *)0);
   	defaultScreen = DefaultScreen(display);
	DefaultDisplayProp.height = XDisplayHeight(display, defaultScreen);
	DefaultDisplayProp.width = XDisplayWidth(display, defaultScreen);
	DefaultDisplayProp.depth = XDefaultDepth(display, defaultScreen);
	
	window =XCreateSimpleWindow(display,DefaultRootWindow(display),0,0,1300, 600, 5,black.decimal, white.decimal);
	XSetStandardProperties(display,window,"Application Title","Program Name?",None,NULL,0,NULL);
	XSelectInput(display, window, KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | Button1MotionMask | Button2MotionMask | Button3MotionMask | Button4MotionMask | Button5MotionMask | ButtonMotionMask | ColormapChangeMask);
    
    graphics=XCreateGC(display, window, 0,0);
	XSetBackground(display,graphics,white.decimal);
	XSetForeground(display,graphics,black.decimal);
	
	XClearWindow(display, window);
	XMapRaised(display, window);
	
	return 0;
};

int close_x() {
	//XFreeGC(display, graphics);
	//XDestroyWindow(display,window);
	XCloseDisplay(display);	
};

int redraw() {
	XClearWindow(display, window);
};

#include"../events/events.hpp"

int startx(){
	XEvent event;		// the XEvent declaration !!! 
	if(!init_x()){//If succesful start endless loop
		while(1) {		
			XNextEvent(display, &event);
			//cout<<"Event Type : "<<event.type<<endl;
			switch(event.type){
				case Expose: redraw();break;
				case KeyPress: keyPressHandler(event);break;
				case KeyRelease : keyReleaseHandler(event);break;
				case ButtonPress : buttonPressHandler(event);break;
				case MotionNotify : pointerMotionHandler(event);break;
				case ColormapNotify : colormapNotify(event);break;
				//case ResizeRequest : resizeHandler(event);break;
				//default : cout<<"No Idea what to do..."<<endl;
			}
		}
	}
}

#endif
