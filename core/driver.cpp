//Project : X11-CW
//Author : Supratik Chatterjee
//Please do not make changes to the function names in the associated files
//Write your procedures in the functions provided under the 'events' and 'display' folders.
int mutexDisplay(){
	while(1)
		if(XPending(display)){
			eventsHandler();
		}
		else{
			displayHandler();
		} 
}

int startx(){
	if(init())return 1;
	mutexDisplay();
    return 0;
};
