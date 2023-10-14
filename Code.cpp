# Linkedlist
//
//  main.cpp
//  linked lists
//
//

#include <iostream>
using namespace::std;
struct Node{
    int data;
    struct Node *next;
}*start=NULL;
void create(int A[],int n){
    int i;
    struct Node *t,*last;
    start=new struct Node;
    start->data=A[0];
    start->next=NULL;
    last=start;
    
    for(i=1;i<n;i++){
        t=new struct Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node *p){
    while (p!=NULL) {
        cout<<"->"<<p->data;
        p=p->next;
    }
    cout<<endl;
}
void Rdisplay(struct Node *p)
{
    
    if(p!=NULL)
    {
        Rdisplay(p->next);
        cout<<"<-"<<p->data;
    }
}
void ins_in_middle(int pos,int val){
    struct Node *newnode=new struct Node;
    struct Node *temp=start;
    for(int i=2;i<pos;i++){
        if(temp->next != NULL){
            temp=temp->next;
        }
    }
    newnode->data=val;
    newnode->next=temp->next;
    temp->next=newnode;
}
void search(int num){
    int count=0;
    struct Node *p;
    p=start;
    while (p->data!=num) {
        p=p->next;
        count++;
    }
    if(p==NULL){
        cout<<"number not found"<<endl;
    }
    else{
        cout<<"element found at "<<count+1<<"th place"<<endl;
    }
}
int main() {
    int n;
    cout<<"Enter the no.of elements =";
    cin>>n;
    int A[n];
    cout<<"enter the array elements = ";
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    create(A,n);
    int k=0;
    while (k!=5) {
        cout<<"--------pick one to execuite---------"<<endl;
        cout<<"1.display"<<endl
            <<"2.insert in middle"<<endl
            <<"3.search an element in list"<<endl
            <<"4.Reverse display the linked list "<<endl
            <<"5.exit"<<endl
            <<"-------------------------------------"<<endl;
        cin>>k;
        switch(k){
            case 1:
                cout<<"The linked list is = ";
                display(start);
                break;
            case 2:
                int pos,val;
                cout<<"enter at which we need to add data and the value of data =";
                cin>>pos>>val;
                ins_in_middle(pos, val);
                cout<<"The new list is = ";
                display(start);
                break;
            case 3:
                int num;
                cout<<"Enter the element need to be searhed in linked list = ";
                cin>>num;
                search(num);
                break;
            case 4:
                cout<<"The reversed linked list is =";
                Rdisplay(start);
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}
