#include <iostream>
using namespace std;

int insertioninArray(int arr[],int n,int capacity){
	int element,index;
	cout<<"Enter the index were you want to insert : ";
	cin>>index;
	cout<<"Enter the element you want to insert : ";
	cin>>element;
	if(n>=capacity){
		return -1;
		cout<<"No space to insert another element";
	}
	for(int i=n-1;i>=index;i--){
		arr[i+1]=arr[i];
	}
	arr[index]=element;
	cout<<"Insertion done Successfully\n";
	return 1;
}

int main(){
    int arr[100],n=0;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertioninArray(arr,n,100);
    n +=1;
    cout<<"The Stored values in array is : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}