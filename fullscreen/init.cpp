int init() {
/* get the colors black and white (see section for details) */        
	Color black(0), white(255,255,255);
	XInitThreads();
	display = XOpenDisplay((char *)0);
   	defaultScreen = DefaultScreen(display);
	rootWindow = DefaultRootWindow(display);
	
	DefaultDisplayProp.height = XDisplayHeight(display, defaultScreen);
	DefaultDisplayProp.width = XDisplayWidth(display, defaultScreen);
	DefaultDisplayProp.depth = XDefaultDepth(display, defaultScreen);
	connectionNumber = ConnectionNumber(display);
	
	unsigned long valuemask = 0;
	XSetWindowAttributes attributes;
	if(fullscreen){
		valuemask |= CWOverrideRedirect;
		attributes.override_redirect = True;
	}
	mainWindow =XCreateWindow(display,rootWindow,0,0,DefaultDisplayProp.width, DefaultDisplayProp.height, 0,CopyFromParent, InputOutput, CopyFromParent, valuemask, &attributes);
	XSetStandardProperties(display,mainWindow, appname, "Program Name",None,NULL,0,NULL);
	XSelectInput(display, mainWindow, KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | Button1MotionMask | Button2MotionMask | Button3MotionMask | Button4MotionMask | Button5MotionMask | ButtonMotionMask | ColormapChangeMask | ExposureMask);
	
    xgraphics = XCreateGC(display, mainWindow, 0,0);
	XSetBackground(display,xgraphics,white.decimal);
	XSetForeground(display,xgraphics,black.decimal);
	XSync(display, True);
//	Hints hints;
//	Atom property;
//	
//	hints.flags = 2;
//	hints.decorations = 0;
//	
//	property = XInternAtom(display,"_MOTIF_WM_HINTS", True);
//	XChangeProperty(display,mainWindow,property,property,32,PropModeReplace,(unsigned char *)&hints,5);
//	XF86VidModeSwitchToMode(display,defaultScreen,video_mode);
//    XF86VidModeSetViewPort(display,defaultScreen,0,0);
//    XMoveResizeWindow(display,mainWindow,0,0,DefaultDisplayProp.width,DefaultDisplayProp.height);
//    XMapRaised(display,mainWindow);
//    XGrabPointer(display,mainWindow,True,0,GrabModeAsync,GrabModeAsync,mainWindow,0L,CurrentTime);
//    XGrabKeyboard(display,mainWindow,False,GrabModeAsync,GrabModeAsync,CurrentTime);
//		
	XClearWindow(display, mainWindow);
	XMapRaised(display, mainWindow);
	
	return 0;
};

