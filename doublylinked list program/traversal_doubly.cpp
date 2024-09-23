#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int data) {
        this->data = data;
        this->next=NULL;
        this->prev=NULL;
    }
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList(){
            this->head = NULL;
            this->tail = NULL;
        }
        void createdLinkedList(){
            Node* first = new Node(10);
            first->prev=NULL;
            this->head=first;
            Node* second = new Node(20);
            second->prev=first;
            first->next=second;
            Node* third = new Node(30);
            third->prev=second;
            second->next=third;
            Node* fourth = new Node(40);
            fourth->prev=third;
            third->next=fourth;
            tail=fourth;
        }
        void fordisplayLinkedList(){
            Node* current = this->head;
            while(current != NULL){
                cout<<"Element "<<current->data<<"\n";
                current = current->next;
            }
        }
        void bacdisplayLinkedList(){
            Node* current = this->tail;
            while(current != NULL){
                cout<<"Element "<<current->data<<"\n";
                current = current->prev;
            }
        }
};

int main(){
    DoublyLinkedList l;
    l.createdLinkedList();
    l.fordisplayLinkedList();
    l.bacdisplayLinkedList();
}