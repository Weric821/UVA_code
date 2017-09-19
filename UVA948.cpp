#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    //-------------------------------建立fib
    long long int Fib[40]={NULL};
    Fib[0]=0;
    Fib[1]=1;
    for(int i=2;i<40;i++)
    {
        Fib[i]=Fib[i-1]+Fib[i-2];
    }
    //-------------------------------
    int input_case=0;
    cin>>input_case;
    while(input_case--)
    {
        long long int m=0;
        cin>>m;
        cout<<m<<" = ";
        stringstream ss;            //將資料丟到sstring之後再丟到一個long long int去除在開頭的0
        for(int i=39;i>=2;i--)
        {
            if(m>=Fib[i])
            {
                m-=Fib[i];
                ss<<1;
            }
            else
            {
                ss<<0;
            }
        }
        ss>>m;
        cout<<m<<" (fib)"<<endl;
    }
}
