#include <iostream>
using namespace std;

class Circlurqueue{
	private:
		int *arr;
		int front;
        int rear;
		int capacity;
	public:
		Circlurqueue(int capacity){
			this->capacity=capacity;
			this->front=0;
            this->rear=0;
			this->arr=new int[capacity];
		}
		int isEmpty(){
            if(rear==front){
                return 1;
            }else{
                return 0;
            }
        }
		int isFull(){
            if((rear+1)%capacity==front){
                return 1;
            }else{
                return 0;
            }
        }
		void enqueue(int value){
			if(isFull()){
				cout<<"stack overflow!Cannot push"<<value<<endl;
				return;
			}else{
                rear=(rear+1)%capacity;
				arr[rear]=value;
			}
		}
        int dequeue(){
            int a = -1;
            if(isEmpty()){
				cout<<"stack overflow!Cannot push"<<endl;
				return 1;
			}else{
                front=(front+1)%capacity;
				a = arr[front];
			}
            return a;
		}
		~Circlurqueue(){
			delete[] arr;
		}
};
int main(){
    Circlurqueue q(5);
    cout<<q.isEmpty()<<endl;
    q.enqueue(10);
    q.enqueue(20);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.isEmpty()<<endl;
	return 0;
}