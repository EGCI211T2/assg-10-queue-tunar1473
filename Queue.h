
#ifndef queue_h
#define queue_h
#include "Node.h"
class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};


void Queue::enqueue(int x){
  NodePtr new_node= new NODE(x);
if(new_node){ 
  if(size == 0)
  {
    headPtr = new_node;
    tailPtr = new_node;
  }
  else
  {
    tailPtr -> set_next(new_node);
    tailPtr = new_node;
  }
	size++;
 }
}

int Queue::dequeue(){
  if(headPtr!=NULL){
     NodePtr t=headPtr;
     headPtr = headPtr ->get_next();
     int value= t->get_value();  
     if(size == 1){
      headPtr = NULL;
      tailPtr = NULL;
     } 
     size--;
     cout<<"dequeing "<<value<<endl;
     delete t;
     return value;
  }
  cout<<"Empty queue";
  return -1;
}


Queue::Queue(){
    size = 0;
    headPtr = NULL;
    tailPtr = NULL;
}
Queue::~Queue(){
  int i;
  cout<<"Clearing Queue"<<endl;
  for(i=size;i>0;i--){
    dequeue();
  }
}


#endif
