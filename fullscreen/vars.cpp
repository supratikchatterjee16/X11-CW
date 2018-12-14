Display *display;
Window rootWindow, mainWindow;
GC xgraphics;
Colormap xcolormap;

int defaultScreen;
int window_height, window_width;
int connectionNumber;
int fullscreen;
char appname[255] = "some app";

void* displayHandler(void*);
int displayFunction();
