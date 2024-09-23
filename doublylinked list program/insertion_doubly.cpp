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
        void insertAtfirst(int data){
            Node* newnode = new Node(data);
            newnode->prev = NULL;
            newnode->data = data;
            if(this->head == NULL){
                newnode->next=this->head;
                this->head->prev=newnode;
            }
            else{
                newnode->next=this->head;
                this->head->prev=newnode;
            }
            this->head = newnode;
        }
        void insertAtpos(int data,int index){
            Node* newnode = new Node(data);
            Node* current = this->head;
            int pos = 0;
            while(current->next!=NULL && pos<index-1){
                current = current->next;
                pos++;
            }
            newnode->data=data;
            if(current->next!=NULL){
                Node* successor=current->next;
                newnode->next=successor;
                current->next=newnode;
                newnode->prev=current;
                successor->prev=newnode;
            }else{
                newnode->next=NULL;
                newnode->prev=current;
                current->next=newnode;
                this->tail=newnode;
            }
        }
        void insertAtend(int data){
            Node* newnode = new Node(data);
            if(this->head == NULL){
                this->head=newnode;
                this->tail=newnode;
            }
            else{
                newnode->prev=this->tail;
                this->tail->next=newnode;
                this->tail=newnode;
            }
        }
};

int main(){
    DoublyLinkedList l;
    l.createdLinkedList();
    l.insertAtfirst(10);
    l.insertAtpos(20,3);
    l.insertAtend(20);
    l.fordisplayLinkedList();
    l.bacdisplayLinkedList();
}