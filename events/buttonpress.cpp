int buttonPressHandler(XEvent event){
	char text[255];
	Color c(20,20,150);
	int x,y;
	x = event.xbutton.x;
	y = event.xbutton.y;
	strcpy(text,"Bullshit");
	//std::cout<<x<<", "<<y<<std::endl;
	XSetForeground(display,xgraphics, c.decimal);
	XDrawString(display, mainWindow, xgraphics, x, y, text, strlen(text));
	return 0;
}
