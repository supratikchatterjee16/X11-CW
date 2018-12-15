//Project : X11-CW
//Author : Supratik Chatterjee
//Please do not make changes to the function names in the associated files
//Write your procedures in the functions provided under the 'events' and 'display' folders.
#ifndef __X11EVENTS
#define __X11EVENTS
#include"buttonpress.cpp"
#include"buttonrelease.cpp"
#include"keypress.cpp"
#include"keyrelease.cpp"
#include"pointermotion.cpp"
#include"colormapnotify.cpp"
#include"focuschange.cpp"
#include"exposed.cpp"
#include"clientmessage.cpp"

int eventsHandler(){
	XEvent event;
	XNextEvent (display, &event);
  	switch(event.type){
		case Expose: ;break;
		case KeyPress: keyPressHandler(event);break;
		case KeyRelease : keyReleaseHandler(event);break;
		case ButtonPress : buttonPressHandler(event);break;
		case MotionNotify : pointerMotionHandler(event);break;
		case ColormapNotify : colormapNotify(event);break;
		case ClientMessage : clientMessageHandler(event);break;
		//case ResizeRequest : resizeHandler(event);break;
		//default : cout<<"No Idea what to do..."<<endl;
	}
	return 0;
};

#endif
