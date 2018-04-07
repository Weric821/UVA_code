//(直觀的一個一個找，數字大的時候太慢了)
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
void show_result(string input1,string input2)   //將兩字串丟入求出公因數
{
    long long int input1_decimal=0;
    long long int input2_decimal=0;
    input1_decimal=binary_to_decimal(input1);
    input2_decimal=binary_to_decimal(input2);
    for(int i=2;i<max(input1_decimal,input2_decimal);i++)
    {
        if(input1_decimal%i==0&&input2_decimal%i==0)
        {
            cout<<"All you need is love!"<<endl;
            break;
        }
        if(i==max(input1_decimal,input2_decimal)-1)
        {
            cout<<"Love is not all you need!"<<endl;
        }
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
