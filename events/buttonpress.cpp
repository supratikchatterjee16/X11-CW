int buttonPressHandler(XEvent event){
	char text[255];
	Color c(20,20,150);
	int x,y;
	x = event.xbutton.x;
	y = event.xbutton.y;
	strcpy(text,"Bullshit");
	std::cout<<x<<", "<<y<<std::endl;
	XSetForeground(display,xgraphics, c.decimal);
	XDrawString(display, mainWindow, xgraphics, x, y, text, strlen(text));
	XPoint points[]={{100,100},{100,101},{100,102},{100,103},{100,104},{100,105},{100,106},{100,107},{100,108},{100,109},{100,110}};
	XDrawPoints(display, mainWindow, xgraphics, points, 11,  CoordModeOrigin);
	return 0;
}
