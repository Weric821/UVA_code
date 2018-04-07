//(運用輾轉相除，快速找出最大公因數，判斷其是否為1即為此題解)
#include<iostream>
#include<math.h>
using namespace std;
int binary_to_decimal(string input) //將二進位轉成十進位
{
    long long int input_decimal=0;
    for(int i=input.size()-1;i>=0;i--)
    {
        input_decimal+=(input[i]-'0')*pow(2,input.size()-1-i);
    }
    return input_decimal;
}
int gcd(int a1,int a2)      //輾轉相除法，快速求出最大公因數
{
    if(a2>a1)
    {
        return gcd(a2,a1);
    }
    else
    {
        if(a2==0)
        {
            return a1;
        }
        else
        {
            return gcd(a2,a1%a2);
        }
    }
}
void show_result(string input1,string input2)   //利用輾轉相處法找出最大公因數，快速求出是否有1以外的公因數
{
    long long int input1_decimal=0;
    long long int input2_decimal=0;
    input1_decimal=binary_to_decimal(input1);
    input2_decimal=binary_to_decimal(input2);
        if(gcd(input1_decimal,input2_decimal)!=1)
        {
            cout<<"All you need is love!"<<endl;
        }
        else
        {
            cout<<"Love is not all you need!"<<endl;
        }
}
int main()
{
    int input_case=0;
    cin>>input_case;
    for(int i=0;i<input_case;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        cout<<"Pair #"<<i+1<<": ";
        show_result(s1,s2);
    }
}
