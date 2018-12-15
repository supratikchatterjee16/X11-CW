#include<iostream>

#include"core/x11.hpp"

using namespace std;
int x = 500, y=100, togglex =1, toggley =1;

int displayHandler(){
	Color c(50,250,250);
	int modif = 2;
	XSetForeground(display, xgraphics, c.decimal);
	for(int i=0;i<DefaultDisplayProp.width;i+=modif)
		for(int j=0;j<DefaultDisplayProp.height;j+=modif){
			XDrawPoint(display, mainWindow, xgraphics, i, i);
		}
	return 0;
};

int main(int argc, char *argv[]){
	fullscreen = 1;
	startx();
}
