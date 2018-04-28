#include<iostream>
using namespace std;
int gcd(int input1,int input2)  //輾轉相除法
{
    if(input2>input1)
    {
        return gcd(input2,input1);
    }
    if(input2==0)
    {
        return input1;
    }
    else
    {
        return gcd(input2,input1%input2);
    }
}
int main()
{
    int input=0;
    while(cin>>input&&input!=0)
    {
        long long int G=0;
        for(int i=1;i<input;i++)    //根據題目完成巢狀迴圈
        {
            for(int j=i+1;j<=input;j++)
            {
                G+=gcd(i,j);
            }
        }
        cout<<G<<endl;
    }
}
