/*
Take a string from the user that consists of the '+' symbol. Process the string such that the final string does not include the '+' symbol
and the immediate left non-'+' symbol. Select and choose the optimal ADT. Implement the program by includingthe appropriate header file.
*/
//Evaluating Expressions
#include<iostream>
using namespace std;

class list{
    private:
        struct node{
            char data;
            struct node* nextptr;
        };
        struct node* head;
        int count;
    public:
    list(){
        head=nullptr;
        count=0;
    }
        int insertbeg(char);
        int insertend(char);
        int display();
        int deleteend();
        
};

int main(){
    class list l1;
    string s1;
    cout<<"Enter the string"<<" ";
    cin>>s1;
    for (int i=0;i<s1.size();i++){
        if (s1[i]=='+'){
            l1.deleteend();
        }
        else{
            l1.insertend(s1[i]);
        }
    }
    l1.display();
    return 0;
}
//Function to insert a new node in the beginning of the list
int list::insertbeg(char val){
    struct node* newnode=new struct node();
    newnode->data=val;
    newnode->nextptr=head;
    head=newnode;
    count++;
    return 0;
}
//Function to insert a new node in the end of the list
int list::insertend(char val){
    if (head==nullptr){
        return insertbeg(val);
    }
    struct node* newnode=new struct node();
    newnode->data=val;
    newnode->nextptr=nullptr;
    struct node* temp=head;
    while(temp->nextptr!=nullptr){
        temp=temp->nextptr;
    }
    temp->nextptr=newnode;
    count++;
    return 0;
}

// Function to delete the end of the list
int list::deleteend(){
    struct node* temp=head;
    struct node* t1=nullptr;
    if (temp==nullptr){
        cout<<"Empty list"<<endl;
        return -1;
    }
    while (temp->nextptr->nextptr!=nullptr){
        temp=temp->nextptr;
    }
    t1=temp->nextptr;
    temp->nextptr=nullptr;
    count--;
    return t1->data;
}


// Function to display the list
int list::display(){
    struct node* temp=head;
    if (temp==nullptr){
        cout<<"The list is empty";
        return -1;
    }
    else{
        while(temp!=nullptr){
            cout<<temp->data<<"";
            temp=temp->nextptr;
        }   
        cout<<endl;
    }
    return 0;
}
