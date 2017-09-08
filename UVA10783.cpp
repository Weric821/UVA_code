#include<iostream>
#include<cmath>

using namespace std;
int main()
{
    int total_case=0;
    cin>>total_case;
    for(int i=0;i<total_case;i++)
    {
        int a,b;
        cin>>a>>b;
        a+=abs(a%2-1);  //a是偶數讓他+1
        b-=abs(b%2-1);  //b是偶數讓他-1
        if(b<a)
        {
            if((a+b/2)%2==0)    //a==b且都為偶數
            {
                cout<<"Case "<<i+1<<":"<<0<<endl;
            }
            else                //a==b且都為奇數
            {
                cout<<"Case "<<i+1<<":"<<(a+b/2)<<endl;
            }
        }
        else    //等差級數總和
        {
            cout<<"Case "<<i+1<<":"<<((a+b)*((b-a)/2+1))/2<<endl;
        }
    }
}
