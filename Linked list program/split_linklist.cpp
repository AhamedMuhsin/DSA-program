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
        void createLinkedList(){
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
        void displayLinkedList(Node* head){
            Node* current = head;
            while(current != NULL){
                cout<<"Element "<<current->data<<"\n";
                current = current->next;
            }
        }
        Node* splitLinkedList(LinkedList& l){
            Node* firstHalf = NULL;
            Node* secondHalf = NULL;
            Node* ptr = l.head;
            int count = 0;
            while(ptr != NULL){
                count++;
                ptr=ptr->next;
            }
            int mid = count/2;
            ptr = l.head;
            Node* prev = NULL;
            for(int i=1; i<=mid; i++){
                if(i==1){
                    firstHalf = ptr;
                    prev=ptr;
                }
                else{
                    prev->next=ptr;
                    prev=ptr;
                }
                ptr=ptr->next;
            }
            secondHalf=ptr;
            prev->next=NULL; // Update the last node of the first half to NULL
            l.head=secondHalf; // Update the head of the original list to the second half
            return firstHalf;
        }
        void setHead(Node* head){
            this->head=head;
        }
};

int main(){
    cout<<"linked list"<<"\n";
    LinkedList l;
    l.createLinkedList();
    l.displayLinkedList(l.getHead());
    Node* firstHalf=l.splitLinkedList(l);
    cout<<"spliting a single linked list in two parts"<<"\n";
    cout<<"first half of orginal linked list"<<"\n";
    LinkedList l2;
    l2.setHead(firstHalf);
    l2.displayLinkedList(l2.getHead()); 
    cout<<"Second half of orginal linked list"<<"\n";
    LinkedList l3;
    l3.setHead(l.getHead()); // Use the updated head of the original list for the second half
    l3.displayLinkedList(l3.getHead());
    return 0;
}