#include <iostream>
using namespace std;

class Queue{
	private:
		int *arr;
		int front;
        int rear;
		int capacity;
	public:
		Queue(int capacity){
			this->capacity=capacity;
			this->front=-1;
            this->rear=-1;
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
            if(rear==capacity-1){
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
				arr[rear++]=value;
			}
		}
        int dequeue(){
            int a = -1;
            if(isEmpty()){
				cout<<"stack overflow!Cannot push"<<endl;
				return 1;
			}else{
				a = arr[front++];
			}
            return a;
		}
		~Queue(){
			delete[] arr;
		}
};
int main(){
    Queue q(5);
    cout<<q.isEmpty()<<endl;
    q.enqueue(10);
    q.enqueue(20);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.isEmpty()<<endl;
	return 0;
}