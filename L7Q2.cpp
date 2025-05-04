/*
Write a separate C++ menu-driven program to implement Circular Queue ADT using an integer array of size 5. Maintain proper boundary conditions and follow good 
coding practices. The Circular Queue ADT has the following operations,

1. Enqueue
2. Dequeue
3. Peek
4. Exit

*/
//Implementation of queue using circular linked list
#include<iostream>
using namespace std;

class queue{
    private:
        struct node{
            int data;
            node* next;
        };
        node* front;
        node* rear;
    public:
    queue(){
        front=nullptr;
        rear=nullptr;
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
    struct node* newnode=new struct node();
    newnode->data=val;
    newnode->next=nullptr;
    if (front==nullptr){
        front=newnode;
        rear=newnode;
        rear->next=newnode;
        return 1;
    }
    rear->next=newnode;
    newnode->next=front;
    rear=rear->next;
    return 1;
}
//Function to dequeue an element
int queue::dequeue(){
    int temp;
    temp=front->data;
    if (front==nullptr){
        cout<<"The queue is empty";
        return 0;
    }
    front=front->next;
    rear->next=front;
    return temp;
}
//Function to peek at the queue
int queue::peek(){
    if (front==nullptr){
        cout<<"The queue is empty"<<endl;
        return 0;
    }
    cout<<front->data<<endl;
    return 1;
}
