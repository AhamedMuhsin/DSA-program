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
        void searching(int data){
            bool found=false;
            Node * current = head;
            int count;
            while (current!=NULL){
                if(current->data == data){
                    cout<<"Element is found at "<<count<<" index."<<endl;
                    found=true;
                    break;
                }
                current=current->next;
                count++;
            }
            if(!found){
                cout<<"Element not found"<<endl;
            }
        }
};

int main(){
    LinkedList l;
    int search;
    l.createdLinkedList();
    l.displayLinkedList();
    cout<<"Enter the value you want to Search : ";
    cin>>search;
    l.searching(search);
}