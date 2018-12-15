int buttonPressHandler(XEvent event){
	char text[]="crap";
	Color c(20,20,150);
	int x,y;
	x = event.xbutton.x;
	y = event.xbutton.y;
	XSetForeground(display,xgraphics, c.decimal);
	XDrawString(display, mainWindow, xgraphics, x, y, text, strlen(text));
	return 0;
}
