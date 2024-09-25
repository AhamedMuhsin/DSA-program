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

class Stack{
    public:
        Node* top;
        Stack() {
            this->top = NULL;
        }
        int isEmpty(){
            if(this->top == NULL){
                return 1;
            }
            else{
                return 0;
            }
        }
        void push(int data){
            Node* newNode = new Node(data);
            if(!newNode){
                cout<< "Stack overflow! Cannot push "<<data<<" in the stack"<<endl;
                return;
            }else{
                newNode->next = this->top;
                this->top = newNode;
            }
        }
        int pop(){
            if(this->isEmpty()){
                cout<< "Stack is empty! Cannot pop from the stack"<<endl;
                return -1;
            }
            else{
                int poppedData = this->top->data;
                Node* temp = this->top;
                this->top = this->top->next;
                return poppedData;
                delete temp;
            }
        }
        int isFull(){
            Node* newNode = new Node(1);
            if(!newNode){
                return 1;
            }
        }
        int peek(){
            if(this->isEmpty()){
                cout<< "Stack is empty! Cannot peek at the stack"<<endl;
                return -1;
            }else{
                return this->top->data;
            }
        }
};

int main(){
    Stack s;
    cout<<"linked is empty "<<s.isEmpty()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"popped item is "<<s.pop()<<endl;
    cout<<"linked is empty "<<s.isEmpty()<<endl;
    cout<<"top element is "<<s.peek()<<endl;
    return 0;
}

