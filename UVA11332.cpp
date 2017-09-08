#include<iostream>
#include<sstream>
using namespace std;

void F(string n,int SIZE)
{
    if(SIZE>1)
    {
        int sum=0;
        for(int i=0;i<SIZE;i++)
        {
            sum=sum+n[i]-'0';
        }
        string nn;
        stringstream ss;
        ss<<sum;
        ss>>nn;
        F(nn,nn.size());
    }
    else
    {
        cout<<n[0]<<endl;
    }
}
int main()
{
    string n;
    while(cin>>n&&n!="0")
    {
        F(n,n.size());
    }
}
