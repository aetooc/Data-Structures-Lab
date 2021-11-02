#include <iostream>

using namespace std;

struct node{

    int info;
    node* prev;
};

class Stack{
    private:
        node *top, *temp;
        int val = 0;

    public:
        Stack();
        void Push();
        void Pop();
        void Print();
};

Stack::Stack(){
    top = temp = NULL;
}

void Stack::Push(){
    if (top == NULL){
        top = new node;
        cout << "Enter value: ";
        cin >> top->info;
        top->prev = NULL;
    }
    else{
        temp = new node;
        cout << "Enter value: ";
        cin >> temp->info;
        temp->prev = top;
        top = temp;
        temp = NULL;
    }

}

void Stack::Pop(){
    if (top != NULL){
        temp = top;
        top = top->prev;
        delete temp;
        temp = NULL;
    }
    else{
        cout << "Stack Underflow!\n";
        return;
    }
}

void Stack::Print(){
    temp = top;
    if (top == NULL)
        cout << "Stack Underflow!\n";
    else{
            do{
                cout << top->info << " ";
                Pop();
            }while(top != NULL);
            cout << endl;
    }


}

int main(){
    Stack stack;
    stack.Push();
    stack.Push();
    stack.Push();
    stack.Print();
    stack.Pop();
    stack.Push();
    stack.Push();
    stack.Push();


}