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
        Node* getHead(){
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
            fourth->next=NULL;
        }
        Node* copyingLinkedlist(){
            Node* temp = this->head;
            Node* newHead = new Node(temp->data);
            Node* newTemp = newHead;
            temp = temp->next;
            while(temp != NULL){
                Node* newNode = new Node(temp->data);
                newTemp->next = newNode;
                newTemp = newNode;
                temp = temp->next;
            }
            newTemp->next = NULL;
            return newHead;
        }
        void displayLinkedList(Node* head){
            Node* current = head;
            while(current != NULL){
                cout<<"Element "<<current->data<<"\n";
                current = current->next;
            }
        }
};

int main(){
    LinkedList l;
    l.createdLinkedList();
    l.displayLinkedList(l.getHead());
    cout<<"linked list after copying"<<"\n"; // You need to add a getHead() function to LinkedList class
    Node* newHead = l.copyingLinkedlist();
    LinkedList l2;
    l2.displayLinkedList(newHead);
}