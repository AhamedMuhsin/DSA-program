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
    int choice;
    l.createdLinkedList();
    l.displayLinkedList();
    do{
        cout<<"1. Delete at first\n";        
        cout<<"2. Delete at any position\n";        
        cout<<"3. Delete at end\n";        
        cout<<"4. Exit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                l.deleteAtFirst();
                l.displayLinkedList();
                break;
            case 2:
                int index;
                cout<<"Enter the position where you want to insert : ";
                cin>>index;
                l.deleteAtIndex(index);
                l.displayLinkedList();
                break;
            case 3:
                l.deleteAtEnd();
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