Display *display;
Window rootWindow, mainWindow;
GC xgraphics;
Colormap xcolormap;

int defaultScreen;
int window_height=200, window_width=200, window_position_x = 0, window_position_y = 0, window_border_width = 1;
int connectionNumber;
int fullscreen;
char appname[255] = "some app";

//void* displayHandler(void*);
int  displayHandler();
