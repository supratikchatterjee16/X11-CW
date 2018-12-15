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
