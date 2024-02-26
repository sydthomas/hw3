#ifndef HEAP_H
#define HEAP_H
#include <functional> 
#include <stdexcept>
#include <vector>


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap_vec;
  void trickleDown(int i);
  void trickleUp(int i);

};

// Add implementation of member functions here
void trickleDown(int i){
  // idenitfy left & right children 
  int leftChild = (2*i)+1;
  int rightChild = (2*i)+2;
  int itemIndex = i;

  if(leftChild < heap_vec.size() && c(heap_vec[itemIndex], heap_vec[leftChild])){
    itemIndex = leftChild;
  }

  if(rightChild < heap_vec.size() && c(heap_vec[itemIndex], heap_vec[rightChild])){
    itemIndex = rightChild;
  }

  if(itemIndex != i){
    //swap the two elements 
    std::swap(heap_vec[i], heap_vec[itemIndex]);
    trickleDown(itemIndex);
  }
}

void trickleUp(int i){
  int parent = (i-1)/2;

  while(parent >= 0 && c(heap_vec[i], heap_vec[parent])){
    std::swap(heap_vec[i], heap_vec[parent]);
    i = parent;
    parent = (i-1)/2;
  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::range_error("List is empty!");
  }
  return heap_vec.front();
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::range_error("List is empty!");
  }
  // swap items 
  std::swap(heap_vec[0], heap_vec[heap_vec.size() - 1]);

  // pop item 
  heap_vec.pop_back();

  // trickle down
  trickleDown(0);
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  heap_vec.push_back(item);
  trickleUp(heap_vec.size() - 1);

}

bool Heap<T,PComparator>::empty() const{
  return heap_vec.empty();

}

size_t Heap<T,PComparator>::size() const{
  return heap_vec.size();

}



#endif

