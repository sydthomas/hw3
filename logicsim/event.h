#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
    /*
    Event&* const operator() (Event* e1, Event* e2){
        // compare the events times 
        if(e1.time <= e2.time){
            //create a vector that first stores the e1 event and then the e2 event 
        }
        // here do e2 first then e1

        // ?then create a min heap of the events 
    }
    
    
    */
} EventLess;
	
#endif
