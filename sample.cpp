//Project : X11-CW
//Author : Supratik Chatterjee
//Please do not make changes to the function names in the associated files
//Write your procedures in the functions provided under the 'events' and 'display' folders.

#include<iostream>
#include"core/x11.hpp" //mandatory include

using namespace std;

int main(int argc, char *argv[]){
	//Set properties here.
	fullscreen = 0;
	window_height = 300;
	window_width = 600;
	strcpy(appname, "Application Name");
	//The following is a mandatory command for setting up everything
	startx();
	//Post completion code
	return 0;
}
