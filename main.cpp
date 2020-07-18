#include <iostream>

struct Node {
    int data; // data member
    struct Node *next; // next pointer is of struct Node type
}*first=NULL; //global first pointer

void create(int A[], int n){
    struct Node *t, *last; //t helps to create a new node, last points on last node
    first = new Node(); // creates new node
    first->data = A[0]; // assigns data of first node to first element in array
    first->next = NULL; // gives next pointer of first node a value of NULL 
    last = first; // last pointer points to same element A[0], just as first is. 

    for(int i = 1; i < n; i++){ // this starts from 1 because zeroth element is already initiated
        t = new Node(); // created new node 
        t->data = A[i]; // loops through A[] and gives value to each new node's data
        t->next = NULL; // no next node yet, so assignment of NULL is given
        last->next = t; // takes our newly created node and assigns to next of last node. 
        last = t; // last becomes newly created node of t
    }
}

void recursionRevValues(struct Node* p){ // takes in first pointer of LL called first to point on first node
    if(p!=NULL){ // if p is not equal to NULL
        recursionRevValues(p->next); // calls upon the next node without printing data 
        std::cout << p->data << std::endl; // the data will be printed once all the recursive calls are made 
    }
}

void recursionValues(struct Node *p){
    if(p!=NULL){
        std::cout << p->data << std::endl; // the data will be printed before the next recursive call is made
        recursionValues(p->next); // calls upon the next recursion call on next pointer
    }
}

int count(struct Node *p){
    int count = 0;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    return count;
}

int main() {
    int arr[] = {3,4,5,6,12,9};
    create(arr, 6);
    recursionValues(first);
    std::cout << "\n";
    recursionRevValues(first);
    std::cout << "\n";
    std::cout << "This Linked List has " << count(first) << " nodes." << std::endl;
}