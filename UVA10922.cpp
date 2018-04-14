#include<iostream>
#include<sstream>
using namespace std;
int total_bits(string str_number)  //計算每個bits相加後的數值，回傳long long int
{
    long long int sum=0;
    for(int i=0;i<str_number.size();i++)
    {
        sum+=str_number[i]-'0';
    }
    return sum;
}
int calculate_degree(string str_number) //計算此字串是否為9的倍數，是回傳1，否回傳0
{
    long long int sum=0;
    sum=total_bits(str_number);
    if(sum%9==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    string input;
    while(cin>>input&&input!="0")
    {
        string output=input;            //顯示原有的input
        int total_degree=0;
        while(calculate_degree(input))  //當此數不為9的倍數時跳出，停止計算degree
        {
            total_degree++;
            stringstream ss;            //將long long int 轉回 string
            ss<<total_bits(input);
            input.clear();              //清空字串以防前面結果影響後面字串
            ss>>input;
            if(input.size()<2)          //當算到小於10時跳出
            {
                break;
            }
        }
        if(total_degree!=0)
        {
            cout<<output<<" is a multiple of 9 and has 9-degree "<<total_degree<<"."<<endl;
        }
        else
        {
            cout<<output<<" is not a multiple of 9."<<endl;
        }
    }
}
