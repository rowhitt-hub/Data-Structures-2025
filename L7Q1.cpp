/*
Write a separate C++ menu-driven program to implement Queue ADT using an integer array of size 5. Maintain proper boundary conditions and follow good coding practices.
The Queue ADT has the following operations,

1. Enqueue
2. Dequeue
3. Peek
4. Exit
*/
//Implementtation of queue using Array

#include <iostream>
using namespace std;
#define size 5

class queue{
    private:
    int arr[size];
    int curr;
    int front;
    int rear;
    public:
    queue(){
        front=-1;
        rear=-1;
    }
        int enqueue(int);
        int dequeue();
        int peek();
        
};



int main(){
    class queue q1;
    int inf;
    int ch;
    inf=1;
    while (inf==1){
        cout<<"Enter 1 to enqueue an element"<<endl;
        cout<<"Enter 2 to dequeue an element"<<endl;
        cout<<"Enter 3 to peek"<<endl;
        cout<<"Enter 4 to exit"<<" ";
        cin>>ch;
        if(ch==1){
            int val;
            cout<<"Enter the value you want to enqueue ";
            cin>>val;
            q1.enqueue(val);
        }
        else if (ch==2){
            q1.dequeue();
        }
        else if (ch==3){
            q1.peek();
        }
        else if (ch==4){
            break;
        }
        else{
            cout<<"Enter valid choice"<<endl;
        }
    }
    return 0;
}
//Function to enqueue an element
int queue::enqueue(int val){
    if (front==-1){
        arr[0]=val;
        rear++;
        front++;
        return 1;
    }
    if (rear==size-1){
        cout<<"The queue is full"<<endl;
        return 0;
    }
    arr[rear+1]=val;
    rear++;
    return 1;
}
//Funtion to dequeue an element
int queue::dequeue(){
    int temp;
    temp=arr[front];
    if (front==-1){
        cout<<"The queue is empty"<<endl;
        return 0;
    }
    for (int i=0;i<rear;i++){
        arr[i]=arr[i]+1;
    }
    rear--;
    return front;
}
//Function to peek at the queue
int queue::peek(){
    if (front==-1){
        cout<<"Nothing in the queue"<<endl;
        return 0;
    }
    cout<<arr[0]<<endl;
    return 1;
}
