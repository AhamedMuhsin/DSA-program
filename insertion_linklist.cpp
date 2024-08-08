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
        void createdLinkedList(){
            Node* first = new Node(10);
            this->head=first;
            Node* second = new Node(20);
            first->next=second;
            Node* third = new Node(30);
            second->next=third;
            Node* fourth = new Node(40);
            third->next=fourth;
            fourth->next=NULL;
        }
        void displayLinkedList(){
            Node* current = this->head;
            while(current != NULL){
                cout<<"Element "<<current->data<<"\n";
                current = current->next;
            }
        }
        void insetAtFirst(){
            Node* ptr = new Node(0);
            ptr->next = this->head;
            this->head = ptr;
        }
        void insertAtEnd(){
            Node* ptr = new Node(50);
            Node* current = this->head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = ptr;
            ptr->next=NULL;
        }
        void insertAtIndex(int index){
            Node* ptr = new Node(25);
            Node* current = this->head;
            int i = 0;
            while(current != NULL){
                if(i == index-1){
                    ptr->next = current->next;
                    current->next=ptr;
                }
                current = current->next;
                i++;
            }
        }
};

int main(){
    LinkedList l;
    cout<<"Linked list before insertion \n";
    l.createdLinkedList();
    l.displayLinkedList();
    cout<<"linked list after insertion \n";
    l.insertAtIndex(1);
    l.displayLinkedList();

    return 0;
}