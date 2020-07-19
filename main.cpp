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
        t = new Node(); // we created new node 
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

int countIteratively(struct Node *p){
    int count = 0;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    return count;
}

int countRecursively(struct Node *p){
    if(p!=NULL){
       return countRecursively(p->next) + 1;
    } else {
        return 0;
    }
}

int sumIteratively(struct Node *p){
    int sum = 0;
    while(p != NULL){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int sumRecursively(struct Node *p){
    if(p==NULL){
        return 0;
    } else {
        return sumRecursively(p->next) + p->data;
    }
}

int maxElement(struct Node *p){
    int max = p->data;
    while(p!=NULL){
        if(p->data > max){
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int maxElementRecursively(struct Node *p){
    int max = p->data;
    if(p!=NULL){
        return 0;
    }
    max = maxElementRecursively(p->next);
    return max;
}

int main() {
    int arr[] = {0,3,217,5,46,12,29};
    create(arr, 7);
    recursionValues(first);
    std::cout << "\n";
    recursionRevValues(first);
    std::cout << "\n";
    std::cout << "This function counts the nodes in the LL iteratively and has " << countIteratively(first) << " nodes.\n";
    std::cout << "This function counts the nodes in the LL recursively and has " << countRecursively(first) << " nodes.\n\n";
    std::cout << "This function adds all the nodes' data iteratively.\nTotal values are " << sumIteratively(first) << "\n";
    std::cout << "This function adds all the nodes' data recursively.\nTotal values are " << sumRecursively(first) << "\n";
    std::cout << "The maximum value in the LL is " << maxElement(first) << "\n";
    std::cout << maxElementRecursively(first);
}