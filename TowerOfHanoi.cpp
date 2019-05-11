
#include<iostream>
using namespace std;
void hanoi(int n,char fromPeg,char toPeg,char auxPeg)
{
    if(n==1)
    {
        cout<<"move disk "<<n<<" from "<<fromPeg<<" to "<<toPeg<<endl;
        return;
    }
    hanoi(n-1,fromPeg,auxPeg,toPeg);
    cout<<"move disk "<<n<<" from "<<fromPeg<<" to "<<toPeg<<endl;
    hanoi(n-1,auxPeg,toPeg,fromPeg);
}
int main(){
    int n=3;
    hanoi(n,'S','D','A');
    return 0;
}
