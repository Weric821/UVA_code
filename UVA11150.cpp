#include<iostream>
using namespace std;
int total_cola(int input,int sum)
{
    if(input==1)        //剩1個瓶子不能跟朋友借了
    {
        return sum;
    }
    else if(input<=3)   //剩2個瓶子可以跟朋友借一個，多喝一瓶
    {
        return sum+1;
    }
    else
    {
        return total_cola((input%3+input/3),(sum+input/3));
    }
}
int main()
{
    int input=0;
    while(cin>>input)
    {
        int sum=input;
        cout<<total_cola(input,sum)<<endl;
    }
}
