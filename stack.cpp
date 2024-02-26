#include "stack.h"


//  stack is first in last out 

Stack::Stack(){

}

~Stack(){

}


bool Stack::empty() const{
  return empty();    // Vector<T>::
}

size_t Stack::size() const{
  return size();   // Vector<T>::
}

void Stack::push(const T& item){
  stack_vec.push_back(item);

}

void Stack::pop(){
  if(Stack<T>::empty()){
    throws std::underflow_error("Stack is empty");
  }
  else{
    stack_vec.pop_back();
  }
} 

const T& Stack::top() const{
  if(Stack<T>::empty()){
    throws std::underflow_error("Stack is empty");
  }
  else{
    return stack_vec.back();
  }
} 



// Add other members only if necessary