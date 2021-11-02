#include <iostream>

using namespace std;

class Stack{

    private:
        int* top, *temp;
        int size;
        int* stack;
    
    public:
        Stack();
        void Push();
        void Pop();
        void Top();
        void Display();
};

Stack::Stack(){
    top = temp = NULL;
    // cin >> size;
    size = 3;
    stack = new int [size];
    for(int i = 0; i < size; i++)
        stack[i] = 0; 
}

void Stack::Push(){
    if (top != stack + size-1 ){
        if (top == NULL){
            top = stack;
            cout << "Enter data: ";
            cin >> *top;
        }
        else{
            top++;
            cout << "Enter data: ";
            cin >> *top;
        }
    }
    else
        cout << "Stack Overflow!\n";

}

void Stack::Pop(){
    if (top != NULL){
        if( top != stack)
            top--;
        else
            top = NULL;
    }
    else
        cout << "Stack Underflow!\n";
}

void Stack::Top(){
    cout << *top << endl;
}

void Stack::Display(){
    
    do{
        cout << *top << " ";
        Pop();
    }while(top != NULL);
    cout << endl;
}

int main(){
    Stack arr;
    arr.Push();
    arr.Push();
    arr.Push();
    arr.Push();
    arr.Display();
    arr.Pop();
    arr.Push();
    arr.Push();
    arr.Push();
    arr.Push();

}