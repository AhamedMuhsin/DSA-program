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
        void deleteAtfirst(){
            Node* temp = this->head;
            if(this->head==NULL){
                cout<<"List is empty\n";
            }
            else{
                Node* temp = this->head;
                this->head = temp->next;
                this->head->prev=NULL;
                delete temp;
            }
        }
        void deleteAtpos(int index){
            Node* temp = this->head;
            int pos = 0;
            if(index==0){
                Node* temp = this->head;
                this->head = temp->next;
                this->head->prev=NULL;
                delete temp;
            }
            else{
                while(temp->next!=NULL && pos<index-1){
                    temp = temp->next;
                    pos++;
                }
                if(temp->next==NULL){
                    this->tail=temp->prev;
                    this->tail->next=NULL;
                }
                else{
                    Node* successor =temp->next;
                    temp->next=successor->next;
                    if(successor->next!=NULL){
                        successor->next->prev=temp;
                    }
                    else{
                        this->tail=temp;
                    }
                    delete successor;
                }
            }
        }
        void deleteAtend(){
            Node* temp = this->head;
            if(this->head==NULL){
                cout<<"List is empty\n";
            }
            else if(this->head->next==NULL){
                delete this->head;
                this->head=NULL;
                this->tail=NULL;
            }
            else{
                while(temp->next->next!=NULL){
                    temp = temp->next;
                }
                delete temp->next;
                temp->next=NULL;
                this->tail=temp;
            }
        }
};

int main(){
    DoublyLinkedList l;
    l.createdLinkedList();
    l.deleteAtend();
    l.fordisplayLinkedList();
    l.bacdisplayLinkedList();
}