#include<iostream>
using namespace std;

void score(long long int s,long long int d)
{
    long long int score1=(s+d)/2;
    long long int score2=(s-d)/2;
    if(score1<0||score2<0)
    {
        cout<<"impossible"<<endl;
    }
    else
    {
        cout<<max(score1,score2)<<" "<<min(score1,score2)<<endl;
    }
}
int main()
{
    long long int n=0;
    cin>>n;
    while(n--)
    {
         long long int s=0;
         long long int d=0;
         cin>>s>>d;
         score(s,d);
    }
}
