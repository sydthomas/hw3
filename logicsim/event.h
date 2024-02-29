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
    
    bool operator() (Event* e1, Event* e2) const{
        // compare the events times 
        if(e1->time < e2->time){
            return true;
        }
        else{
            return false;
        }
        // ?then create a min heap of the events 
    }
    
    
    
} EventLess;
	
#endif
