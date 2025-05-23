// heap.cpp
// Jarek Pascua

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int i = vdata.size() - 1; //indicates the index where the value is inserted 
  int parent = (i -1) / 2; //indicates the index of the parent 
  while (i > 0 && vdata[i] < vdata[parent]){
      std::swap(vdata[i], vdata[parent]);
      i = parent;
      parent = (i -1) / 2;
  }


  
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.empty()){
    return;
  }
  vdata[0] = vdata.back();
  vdata.pop_back();

  int i = 0; 
  int n = vdata.size();
  while(true) {
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    
    if (left >= n) {
      break;
    }
    int smallest = left; 
    
    if (right < n && vdata[left] > vdata[right]) {
      smallest = right;
    }
    if(vdata[i] <= vdata[smallest]) {
      break;
    }
    std::swap(vdata[i], vdata[smallest]);
    i = smallest;
   }

}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if (vdata.size() == 0) {
    return true;
  }
  return false;
}
    