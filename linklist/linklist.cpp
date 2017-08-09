#include <iostream>

struct Node{
    int data;
    Node *next;

};

// create a linklist with n node;
Node* create_list(int n)
{
    Node *head = new Node();
    Node *ptr = head;
    for(int i = 0; i < n; i++){
        ptr->data = rand() % 100;
        if(i < n - 1){
            ptr->next = new Node();
            ptr = ptr->next;
        }else{
            ptr->next = NULL;
        }
    }
    return head;
}

// print linklist
void print_list(Node *A)
{
    Node *ptr = A;
    while(ptr != NULL){
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

// delete linklist
void distroy_list(Node *A)
{
    Node *ptr = NULL;
    while(A != NULL){
        ptr = A;
        A = A->next;
        delete ptr;
    }
}

// reverst the linklist
// insert every node in the front of the new linklist
Node* reverst(Node *A)
{
    Node *newhead = NULL;
    Node *oldhead = NULL;
    Node *ptr = A;
    while( ptr!= NULL ){
        oldhead = newhead;
        newhead = ptr;
        ptr = ptr->next;
        newhead->next = oldhead;
    }
    A->next = NULL;
    return newhead;
}

Node* merge_list(Node *A, Node *B)
{
    if(A == NULL) return B;
    if(B == NULL) return A;
    Node *p1 = NULL;
    Node *p2 = NULL;
    Node *cur = NULL, *head = NULL;
    // find the head
    if(A->data <= B->data){
        head = A;
        cur = head;
        p1 = A->next;
        p2 = B;
    }else{
        head = B;
        cur = head;
        p2 = B->next;
        p1 = A;
    }
    while(p1 != NULL && p2 != NULL){
        if(p1->data <= p2->data){
            cur->next = p1;
            cur = cur->next;
            p1 = p1->next;
        }else{
            cur->next = p2;
            cur = cur->next;
            p2 = p2->next;
        }
    }
    if(p1 != NULL){
        cur->next = p1;
    }
    if(p2 != NULL){
        cur->next = p2;
    }
    return head;
}

int main(int argc, char** argv) {
    Node *A;
    A = create_list(10);
    print_list(A);

    Node *B;
    B = create_list(10);
    print_list(B);

    Node *C = merge_list(A, B);
    print_list(C);

    distroy_list(C);
    return 0;
}
