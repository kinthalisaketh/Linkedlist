#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*first = NULL;
void create(int A[], int n){
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1; i<n; i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    }    
void display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
        }
        cout<<endl;
    }
void Rdisplay(struct Node *p){
    if(p!=NULL){
        Rdisplay(p->next);
        cout<<p->data<<" ";
    }
}
void insert(int pos, int x){
    if(pos<0) return;
     struct Node *t= new Node;
     t->data=x;
     t->next=NULL;
     if(pos==0){
         t->next=first;
         first=t;
    }else{
        struct Node *p=first;
        for(int i=1; i<pos-1 && p!=NULL ;i++){
            p=p->next;
        }
        if(p!=NULL){
            t->next = p->next;
            p->next =t;
        }else{
            delete t;
        }
            
        }
        cout<<endl;
}
void deletePos(int pos) {
    if (pos < 0) return;
    struct Node *temp = first;
    if (pos == 0) {
        if (first != NULL) {
            first = first->next;
            delete temp;
        }
        return;
    }
    struct Node *prev = NULL;
    for (int i = 0; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    delete temp; 
}

int main(){
    int A[]={1,2,3,4,5,6};
    create(A,6);
    display(first);
    Rdisplay(first);
    insert(5, 7);
    display(first);
    deletePos(1);
    display(first);
    return 0;
}
