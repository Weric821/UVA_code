#include<iostream>
#include<sstream>
#include<stack>
using namespace std;
string pplus(string a,string b)         //大數加法，將每筆帳單加再一起
{
    stringstream ss;
    if(a.size()>b.size())
    {
            for(int i=0;i<(a.size()-b.size());i++)
            {
                ss<<"0";
            }
            ss<<b;
            ss>>b;
    }
    else
    {
            for(int i=0;i<(b.size()-a.size());i++)
            {
                ss<<"0";
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
            sk.push(sum%10);
        }
    }
    if(carry>0)
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
string divide(string a,int b)       //大數除法，題目b<=20
{
    int remainder=0;
    int sum=0;
    stringstream output;
    for(int i=0;i<a.size();i++)
    {
        sum+=(a[i]-'0');
        if(sum<b)
        {
            sum*=10;
            output<<'0';
        }
        else
        {
            output<<sum/b;
            remainder=sum%b;
            sum=remainder*10;
        }

    }
    string output_string;
    output>>output_string;
    stringstream delete_front_zero;
    for(int i=0;i<output_string.size();i++)     //去除前面無意義的零
    {
        if(output_string[i]!='0')
        {
            for(int j=i;j<output_string.size();j++)
            {
                delete_front_zero<<output_string[j];
            }
            break;
        }
    }
    delete_front_zero>>output_string;
    return output_string;
}
int main()
{
    int N,F=0;
    int Case=1;
    while(cin>>N>>F&&(N!=0||F!=0))
    {
        string input;
        string sum="0";
        while(N--)
        {
            cin>>input;
            sum=pplus(sum,input);
        }
        cout<<"Bill #"<<Case<<" costs "<<sum<<": each friend should pay "<<divide(sum,F)<<endl;
        cout<<endl;
        Case++;
    }
}
