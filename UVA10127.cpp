#include<iostream>
using namespace std;
int main()
{
    int input=0;
    while(cin>>input)
    {
        long long int one=1;
        int output=1;       //輸出
        while(one%input!=0)
        {
            one%=input;
            one*=10;
            one+=1;
            output++;
        }
        cout<<output<<endl;
    }
}
