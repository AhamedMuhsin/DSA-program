#include<iostream>
using namespace std;

void towerOfHanio(int n,int a,int b,int c){
    if(n>0){
        towerOfHanio(n-1,a,c,b);
        cout<<"Move disk "<<n<<" from rod "<<a<<" to rod "<<c<<endl;
        towerOfHanio(n-1,b,a,c);
    }
}

int main(){
    towerOfHanio(2,1,2,3);
    return 0;
}