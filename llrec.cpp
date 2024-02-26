#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  Node* current = head; // just added 
  if(head==nullptr){
    head = nullptr;
    // smaller = nullptr;
    // larger = nullptr;
    return;
  }
  else{
    head = current->next;// just added 
    if(current->val <= pivot){
      current->next = smaller; // just added 
      //smaller = head;
      smaller = current;
      //llpivot(head, smaller, larger, pivot);
    }
    else{ //might night need else if
      //larger = head;
      current->next = larger; // new line 
      larger = current; // new line 
      //llpivot(head, smaller, larger, pivot);
    }
    llpivot(head, smaller, larger, pivot);
  }

  // if head == nullptr
      //return;

      // might need this next part 
  //if curr == null 
      // head = nullptr 
      // return;
  
  //else:
      // IF(head.val <= pivot){
          //add to smaller 
          // recursively call 
      
      // IF(head.val > pivot){
          //add to larger 
          // recursively call


}


