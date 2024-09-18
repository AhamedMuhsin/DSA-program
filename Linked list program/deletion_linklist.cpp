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
        void deleteAtFirst(){
            Node* ptr = this->head;
            this->head = head->next;
            // free(ptr);
        }
        void deleteAtIndex(int index){
            Node* ptr = this->head;
            if(index==0){
                this->head = head->next;
                // free(ptr);
            }
            Node* current = head->next;
            int i = 0;
            while(current != NULL){
                if(i == index-1){
                    ptr->next = current->next;
                }
                ptr = ptr->next;
                current = current->next;
                i++;
            }
            // free(current);
        }
        void deleteAtEnd(){
            Node* ptr = this->head;
            Node* current = head->next;
            while(current->next != NULL){
                ptr=ptr->next;
                current=current->next;
            }
            ptr->next=NULL;
            // free(current);
        }
        void displayLinkedList(){
            Node* current = this->head;
            while(current != NULL){
                cout<<"Element "<<current->data<<"\n";
                current = current->next;
            }
        }
};

int main(){
    LinkedList l;
    cout<<"element before deletion : "<<"\n";
    l.createdLinkedList();
    l.displayLinkedList();
    l.deleteAtIndex(3
    cout<<"element after deletion : "<<"\n";
    l.displayLinkedList();
}