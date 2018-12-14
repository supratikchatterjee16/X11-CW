#include<pthread.h>
void* eventsHandler(void *args){
	XEvent event;		// the XEvent declaration !!! 
	int pendingRedraws = 0;
	if(!init()){//If succesful start endless loop
		while(1) {	
			if (XPending(display) || !pendingRedraws) {
				// if an event is pending, fetch it and process it
				// otherwise, we have neither events nor pending redraws, so we can
				// safely block on the event queue
				XNextEvent (display, &event);
				
			  	switch(event.type){
					case Expose: pendingRedraws = 1;break;
					case KeyPress: keyPressHandler(event);break;
					case KeyRelease : keyReleaseHandler(event);break;
					case ButtonPress : buttonPressHandler(event);break;
					case MotionNotify : pointerMotionHandler(event);break;
					case ColormapNotify : colormapNotify(event);break;
					//case ResizeRequest : resizeHandler(event);break;
					//default : cout<<"No Idea what to do..."<<endl;
				}
				
			  }
		  else {
			// we must have a pending redraw
			redraw();
			pendingRedraws = 0;
		  }
		}
	}
	return NULL;
};
int startx(){
	pthread_t eventsThread, displayThread;
	char msg1[15] ="Events Thread", msg2[15] = "Display Thread";
	int pid1, pid2;
	pid1 = pthread_create( &eventsThread, NULL, eventsHandler, (void*) msg1);
	pid2 = pthread_create( &displayThread, NULL, displayHandler, (void*) msg2);
	pthread_join(eventsThread, NULL);
    //pthread_join(displayThread, NULL); 
    return 0;
};
