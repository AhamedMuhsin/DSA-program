#include <iostream>
#include <cstring>
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
				return;
			}else{
				arr[++top]=value;
			}
		}
		char pop(){
            if(isEmpty()){
                return -1;
            }else{
                return arr[top--];
            }
        }
        void peek(){
        	if(isEmpty()){
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
        char *infixtoprefix(char *infix){
            int length = strlen(infix);
            char *reversed = new char[length + 1];
            for (int i = 0; i < length; i++) {
                reversed[i] = infix[length - i - 1];
            }
            reversed[length] = '\0';

            int i = 0, j = 0;
            char *prefix = new char[100];
            while(reversed[i]!='\0'){
                if(reversed[i]=='('||reversed[i]==')'){
                    i++;
                }
                else if(!isOperator(reversed[i])){
                    prefix[j]=reversed[i];
                    j++;
                    i++;    
                }
                else{
                    if(precedence(reversed[i])>precedence(stackTop())){
                        push(reversed[i]);
                        i++;
                    }else{
                        prefix[j]=pop();
                        j++;
                    }
                }
            }
            while(!isEmpty()){
                prefix[j]=pop();
                j++;
            }
            prefix[j] = '\0'; // Null-terminate the prefix array
            // Reverse the prefix expression
            int prefixLength = strlen(prefix);
            char *result = new char[prefixLength + 1];
            for (int i = 0; i < prefixLength; i++) {
                result[i] = prefix[prefixLength - i - 1];
            }
            result[prefixLength] = '\0';
            // delete[] prefix; // Don't forget to free the memory
            // delete[] reversed; // Don't forget to free the memory
            return result;
        }	
};

int main(){
    Stack s(100);
    char infix[100];
    cout<<"enter the expression : ";
    cin>>infix;
    cout<<"prefix is "<<s.infixtoprefix(infix)<<endl;
	return 0;
}