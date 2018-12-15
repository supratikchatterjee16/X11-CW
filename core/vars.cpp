//X11 globals
Display *display;
Window rootWindow, mainWindow;
GC xgraphics;
Colormap xcolormap;

//Environment globals
int connectionNumber;
int defaultScreen;

int window_height=200, window_width=200, window_position_x = 0, window_position_y = 0, window_border_width = 1;

int fullscreen;

char appname[255] = "some app";

//Auxillary global functions
int  displayHandler();

