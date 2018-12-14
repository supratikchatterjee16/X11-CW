#include<iostream>

#include"fullscreen/x11.hpp"

using namespace std;
void *displayHandler(void* args){
	cout<<connectionNumber<<endl;
	Color c(50,50,250);
	int width = 40, height = 60,x = 500, y = 100;
	for(int i=0;i<1300;i++){
		XSetForeground(display, xgraphics, c.decimal);
		XDrawRectangle(display, mainWindow, xgraphics, x, y, width, height);
		XFlush(display);
	}
	return NULL;
};

int displayFunction(){
	Color c(50,50,250);
//	for (int t = 0; t < 100; t++){
//       XSetForeground( display, xgraphics, c.decimal);
//       XFillArc( display, mainWindow, xgraphics, t*5+80, t*3+40, 80, 40, 0, 360*64);
//       XSetForeground( display, xgraphics, c.decimal);
//       usleep(200000);
//       XFillArc( display, mainWindow, xgraphics, t*5+80, t*3+40, 80, 40, 0, 360*64);
//    }
	int width = 40, height = 60,x = 500, y = 100;
	for(int i=0;i<1300;i++){
		XSetForeground(display, xgraphics, c.decimal);
		XDrawRectangle(display, mainWindow, xgraphics, x, y, width, height);
		XFlush(display);
	}
}
int main(int argc, char *argv[]){
	fullscreen = 1;
	startx();
}
