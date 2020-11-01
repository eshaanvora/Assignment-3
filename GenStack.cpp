#include "GenStack.h"

//Default constructor
template <typename T>
GenStack<T>::GenStack(){
  //Default array size for stack (before resize)
  mArray = new T[128];
  maxStack = 128;
  top = -1;
}

//Overloaded constructor
template <typename T>
GenStack<T>::GenStack(int maxSize){
  mArray = new T[maxSize];
  maxStack = maxSize;
  top = -1;
}

//Destructor
template <typename T>
GenStack<T> :: ~GenStack(){
  delete mArray;
}

template <typename T>
bool GenStack<T>::isFull(){
  return (top == maxStack-1);
}

template <typename T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}

//Check if stack is full before pushing
template <typename T>
void GenStack<T>::push(T data){
  if(isFull()){
    //If stack is full, double the size (by making new stack with double size and copying stack over)
    T* copyStack = new T[maxStack * 2];
    copyStack = mArray;

    delete mArray;
    mArray = new T[maxStack * 2];

    mArray = copyStack;
    delete copyStack;
    maxStack *= 2;
  }

  mArray[++top] = data;
}

//Check if stack is empty before removing
template <typename T>
T GenStack<T>::pop(){
  //If stack is empty, throw exception
  if(isEmpty()){
    throw "Error. Stack is empty!";
  }
  return mArray[top--];
}

template <typename T>
T GenStack<T>::peek(){
    return mArray[top];
}
