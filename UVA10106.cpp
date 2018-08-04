#include<iostream>
#include<sstream>
#include<stack>
using namespace std;
string mul(string a,char b)     //單一位元與另一數相乘
{
    int CARRY=0;
    int SUM=0;
    stack<int> sk;
    for(int i=a.size()-1;i>=0;i--)
    {
        SUM=((a[i]-'0')*(b-'0'))+CARRY;
        if(SUM>9)
        {
            CARRY=SUM/10;
            sk.push(SUM%10);
        }
        else
        {
            CARRY=0;
            sk.push(SUM);
        }
    }
    if(CARRY>0)
    {
        sk.push(CARRY);
    }
    stringstream ss;
    while(!sk.empty())
    {
        ss<<sk.top();
        sk.pop();
    }
    string output;
    ss>>output;
    return output;
}
string pplus(string a,string b)     //兩數相加
{
    stringstream ss;
    stack<int> sk;
    if(a.size()<b.size())           //位元數不同較短的補零在前面
    {
        for(int i=0;i<b.size()-a.size();i++)
        {
            ss<<'0';
        }
        ss<<a;
        ss>>a;
    }
    else
    {
        for(int i=0;i<a.size()-b.size();i++)
        {
            ss<<'0';
        }
        ss<<b;
        ss>>b;
    }
    int SUM=0;
    int CARRY=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        SUM=(a[i]-'0')+(b[i]-'0')+CARRY;
        if(SUM>9)
        {
            CARRY=1;
            sk.push(SUM%10);
        }
        else
        {
            CARRY=0;
            sk.push(SUM);
        }
    }
    if(CARRY>0)
    {
        sk.push(CARRY);
    }
    stringstream sout;
    while(!sk.empty())
    {
        sout<<sk.top();
        sk.pop();
    }
    string output;
    sout>>output;
    return output;
}
int main()
{
    string input_X,input_Y;     //多位元乘法可看成x單一位元與y相乘並將所有結果一特定情況補零後相加
    while(cin>>input_X>>input_Y)
    {
        stack<string> sk;
        for(int i=0;i<input_Y.size();i++)   //將y的每個位元與x相乘，並用stack記下
        {
            sk.push(mul(input_X,input_Y[i]));
        }
        int COUNT=0;
        string SUM="0";
        while(!sk.empty())
        {
            stringstream ss;
            ss<<sk.top();
            for(int i=0;i<COUNT;i++)        //因多位數相乘需要補零
            {
                ss<<'0';
            }
            COUNT++;
            sk.pop();
            string reg;
            ss>>reg;
            SUM=pplus(SUM,reg);
        }
        cout<<SUM<<endl;
    }
}
