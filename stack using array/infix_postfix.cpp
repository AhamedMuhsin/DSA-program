#include <iostream>
using namespace std;

class Stack{
	private:
		char *arr;
		int top;
		int capacity;
	public:
		Stack(int capacity){
			this->capacity=capacity;
			this->top=-1;
			this->arr=new char[capacity];
		}
		char isEmpty(){
            if(top==-1){
                return 1;
            }else{
                return 0;
            }
        }
		char isFull(){
            if(top==capacity-1){
                return 1;
            }else{
                return 0;
            }
        }
		void push(char value){
			if(isFull()){
				// cout<<"stack overflow!Cannot push"<<value<<endl;
				return;
			}else{
				arr[++top]=value;
			}
		}
		char pop(){
            if(isEmpty()){
                // cout<< "Stack underflow! Cannot pop element from the stack"<< endl;
                return -1;
            }else{
                return arr[top--];
            }
        }
        void peek(){
        	if(isEmpty()){
        		// cout<<"Stack is empty"<<endl;
        		return;
			}
			for(int i=0;i<=top;i++){
				cout<<arr[i]<<" ";			
			}
			cout<<endl;
		}
		~Stack(){
			delete[] arr;
		}
        char stackTop(){
            if(isEmpty()){
                // cout<< "Stack overflow!"<< endl;
                return -1;
            }else{
                return arr[top];
            }
        }
        int precedence(char ch){
            if(ch=='+' || ch=='-'){
                return 2;
            }else if(ch=='*' || ch=='/'){
                return 3;
            }else{
                return 0;
            }
        }
        int isOperator(char ch){
            if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                return 1;
            }else{
                return 0;
            }
        }
        char *infixtopostfix(char *infix){
            int i = 0, j = 0;
            char *postfix = new char[100];
            while(infix[i]!='\0'){
                if(!isOperator(infix[i])){
                    postfix[j]=infix[i];
                    j++;
                    i++;    
                }
                else{
                    if(precedence(infix[i])>precedence(stackTop())){
                        push(infix[i]);
                        i++;
                    }else{
                        postfix[j]=pop();
                        j++;
                    }
                }
            }
            while(!isEmpty()){
                postfix[j]=pop();
                j++;
            }
            postfix[j] = '\0';
            return postfix;
        }	
};
int main(){
    Stack s(100);
    char infix[100];
    cout<<"enter the expression : ";
    cin>>infix;
    cout<<"postfix is "<<s.infixtopostfix(infix)<<endl;
	return 0;
}