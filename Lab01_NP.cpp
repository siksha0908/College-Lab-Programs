//Write a program to check number palindrome and using string palindrome.
#include <iostream>
using namespace std;
int main(){
    int n, r, sum=0, temp;
    cout<<"Enter a number: ";
    cin>>n;
    temp=n;
    while(n>0){
        r=n%10;
        sum=sum*10+r;
        n=n/10;
    }
    if(temp==sum){
        cout<<"The number is a palindrome."<<endl;
    }
    else{
        cout<<"The number is not a palindrome."<<endl;
    }
    return 0;
}