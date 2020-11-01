#include <iostream>
using namespace std;

template <typename T>
class GenStack{

  public:
    int maxStack; //Maximum size of stack
    int top;
    T *mArray;

    //Default constructor
    GenStack();
    //Overloaded constructor
    GenStack(int maxSize);
    //Destructor
    ~GenStack();

    //functions
    void push(T data); //Push
    T pop(); //Pop

    //helper functions
    bool isFull();
    bool isEmpty();
    T peek();
};
