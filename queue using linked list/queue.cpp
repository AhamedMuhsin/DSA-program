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

class Queue{
    public:
        Node* front;
        Node* rear;
        Queue(){
            this->front=NULL;
            this->rear=NULL;
        }
        int isEmpty(){
            if(this->front==NULL){
                cout<<"Queue is empty"<<endl;
                return 1;
            }
            return 0;
        }
        void enqueue(int data){
            Node* newNode = new Node(data);
            if(this->isEmpty()){
                this->front=newNode;
                this->rear=newNode;
                return;
            }
            this->rear->next=newNode;
            this->rear=newNode;
        }
        int dequeue(){
            int del = -1;
            del = this->front->data; 
            Node *temp = this->front;
            if(this->isEmpty()){
                cout<<"Queue is empty"<<endl;
                return 1;
            }
            else{
                this->front = this->front->next;
            }
            delete temp;
            return del;
        }
        void display(){
            Node* current = this->front;
            while(current != NULL){
                cout<<"Element "<<current->data<<"\n";
                current = current->next;
            }
        }
};

int main(){
    Queue q;
    cout<<q.isEmpty()<<endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.isEmpty()<<endl;
    return 0;
}