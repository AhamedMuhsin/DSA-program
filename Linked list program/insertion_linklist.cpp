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
        void insetAtFirst(int data){
            Node* ptr = new Node(data);
            ptr->next = this->head;
            this->head = ptr;
        }
        void insertAtEnd(int data){
            Node* ptr = new Node(data);
            Node* current = this->head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = ptr;
            ptr->next=NULL;
        }
        void insertAtIndex(int index,int data){
            Node* ptr = new Node(data);
            if(index==0){
                ptr->next = this->head;
                this->head=ptr;
            }
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
    int choice,data,index;
    l.createdLinkedList();
    l.displayLinkedList();
    do{
        cout<<"1. Insert at first\n";        
        cout<<"2. Insert at any position\n";        
        cout<<"3. Insert at end\n";        
        cout<<"4. Exit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the data to be inserted at first position : ";
                cin>>data;
                l.insetAtFirst(data);
                l.displayLinkedList();
                break;
            case 2:
                cout<<"Enter the position where you want to insert : ";
                cin>>index;
                cout<<"Enter the data to to inserted at any position : ";
                cin>>data;
                l.insertAtIndex(index,data);
                l.displayLinkedList();
                break;
            case 3:
                cout<<"Enter the data to inserted at end : ";
                cin>>data;
                l.insertAtEnd(data);
                l.displayLinkedList();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice!=4);
    return 0;
}