#include<iostream>
#include<stack>
#include<map>
#include<sstream>
using namespace std;
string pplus(string a,string b)         //大數相加
{
    stringstream ss;
    if(a.size()>b.size())               //判斷a.b哪個位數比較多，少的前面補零
    {
        for(int i=0;i<(a.size()-b.size());i++)
        {
            ss<<'0';
        }
        ss<<b;
        ss>>b;
    }
    else
    {
        for(int i=0;i<(b.size()-a.size());i++)
        {
            ss<<'0';
        }
        ss<<a;
        ss>>a;
    }
    int carry=0;
    int sum=0;
    stack<int> sk;
    for(int i=a.size()-1;i>=0;i--)
    {
        sum=(a[i]-'0')+(b[i]-'0')+carry;
        if(sum>9)
        {
            carry=sum/10;
            sk.push(sum%10);
        }
        else
        {
            carry=0;
            sk.push(sum);
        }
    }
    if(carry!=0)
    {
        sk.push(carry);
    }
    stringstream output;
    while(!sk.empty())
    {
        output<<sk.top();
        sk.pop();
    }
    string output_string;
    output>>output_string;
    return output_string;
}
int main()
{
    map<int,string> mp;         //建表，以map紀錄，這樣之後只需查表
    mp[0]="0";
    mp[1]="1";
    for(int i=2;i<=5000;i++)
    {
        mp[i]=pplus(mp[i-2],mp[i-1]);
    }
    int input;
    while(cin>>input)           //查表，output
    {
        cout<<"The Fibonacci number for "<<input<<" is "<<mp[input]<<endl;
    }
}
