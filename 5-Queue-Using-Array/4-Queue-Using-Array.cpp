#include <iostream>

using namespace std;

class Queue{

    private:
        int *queue, *front, *rear, *temp, size, num;
    public:
        Queue();
        void EnQueue(int val);
        void DeQueue();
        void Print();
};

Queue::Queue(){
    size = 5;
    queue = new int [size];
    for (int i = 0; i < size; i++){
        queue[i] = 0;
    }
    front = temp = rear = NULL;
}

void Queue::EnQueue(int val){

    num = val;

    if(rear == NULL){
        rear = queue;
        // cout << "Enter: ";
        *rear = num;
        front = queue;
        return;
    }

    else if (rear == queue+size-1 && front != queue){
        rear = queue;
        // cout << "Enter: ";
        *rear = num;
        return;
    }

    else if ( (rear + 1 != front) && (rear != queue+size-1 ) ){
        rear++;
        // cout << "Enter: ";
        *rear = num;
        return;  

    }
	// else if ((front == queue && rear == queue+(size-1)) || front-1 == rear) 
	// {
    else{
		cout<<"Overflow"<<endl;
		return;
    }
	// }
}

void Queue::DeQueue(){
    if (front == NULL){
        cout << "Queue is Empty.\n";
    }

    else if (front == rear){
        front = rear = NULL;
        return;
    }

    else if(front == queue+size-1){
        front = queue;
        return;
    }
    else{
        front++;
    }
}


void Queue::Print(){
    cout << "Output: ";
    temp = front;
    if(front == NULL){
        cout << "Empty!\n";
    }
    else{
        do{
            cout << *temp << " ";
            if (temp == queue+(size-1) && front != queue){
			    temp = queue;
		    }    
            else
                temp++;        
        }while(temp != rear+1);
    }
    // for (temp = front; temp != rear; temp++){
    //     cout << *temp << " ";
    // }
    cout << endl;
}

int main(){
    Queue q;
    q.EnQueue(8);
    q.EnQueue(7);
    q.DeQueue();
    q.EnQueue(9);
    q.EnQueue(8);
    q.EnQueue(7);
    q.EnQueue(6);
    q.EnQueue(5);
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    q.Print();


}