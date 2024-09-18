#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data) {
        this->data = data;
        this->next=NULL;
    }
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            this->head = NULL;
        }
        Node* getHead() {
            return this->head;
        } 
        void createdLinkedList(){
            Node* first = new Node(10);
            this->head=first;
            Node* second = new Node(20);
            first->next=second;
            Node* third = new Node(30);
            second->next=third;
            Node* fourth = new Node(40);
            third->next=fourth;
            Node* fifth = new Node(50);
            fourth->next=fifth;
            fifth->next=NULL;
        }
        void displayLinkedList(Node* head){
            Node* current = this->head;
            while(current != NULL){
                cout<<"Element "<<current->data<<"\n";
                current = current->next;
            }
        }
        Node* ReverseLinkedlist(LinkedList& l){
            Node* ptr1=this->head;
            Node* ptr2=head->next;
            Node* ptr3=ptr2->next;
            if(ptr3==NULL){
                ptr2->next=ptr1;
                ptr1->next=NULL;
                this->head=ptr2;
            }
            ptr1->next=NULL;
            while(ptr3->next!=NULL){
                ptr2->next=ptr1;
                ptr1=ptr2;
                ptr2=ptr3;
                ptr3=ptr3->next;
            }
            ptr2->next=ptr1;
            ptr3->next=ptr2;
            this->head=ptr3;
            return this->head;
        }
};

int main(){
    cout<<"orginal linked list "<<"\n";
    LinkedList l;
    l.createdLinkedList();
    l.displayLinkedList(l.getHead());
    cout<<"linked list after perfoming reverse operation"<<"\n";
    Node* newHead=l.ReverseLinkedlist(l);
    l.displayLinkedList(newHead);
}