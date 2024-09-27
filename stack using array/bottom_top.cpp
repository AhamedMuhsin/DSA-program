#include <iostream>
using namespace std;
#define MAX 100
class Stack{
    public:
    int top;
    int arr[MAX];
        Stack(){
            top=-1;
        }
        int isEmpty(){
            if(top==-1){
                return 1;
            }else{
                return 0;
            }
        }
        int isFull(){
            if(top==MAX-1){
                return 1;
            }else{
                return 0;
            }
        }
        void push(int item){
            if (isFull()) {
                cout<< "Stack overflow! Cannot push "<<item<<" in the stack"<<endl;
                return;
            }else{
                arr[++top] = item;
            }
        }
        int pop(){
            if(isEmpty()){
                cout<< "Stack underflow! Cannot pop element from the stack"<< endl;
                return -1;
            }else{
                return arr[top--];
            }
        }
        int peek(int index){
            int ind=top-index+1;
            if(isEmpty()){
                cout<< "Stack underflow!"<< endl;
                return -1;
            }else{
                return arr[ind];
            }
        }
        int stackBottom(){
            if(isFull()){
                cout<< "Stack underflow!"<< endl;
                return -1;
            }else{
                return arr[0];
            }
        }
        int stackTop(){
            if(isEmpty()){
                cout<< "Stack overflow!"<< endl;
                return -1;
            }else{
                return arr[top];
            }
        }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout<<s.stackTop()<<endl;
    cout<<s.stackBottom()<<endl;
    cout<<"popped out the first element from stack is "<<s.pop()<<endl;
    for(int j=1;j<=s.top+1;j++){
        cout<<"the element at the postion "<<j<<" is "<<s.peek(j)<<endl;
    }
    return 0;
}
