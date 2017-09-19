#include<iostream>
#include<sstream>
using namespace std;

//轉乘二進位並且計算1的個數
int number_of_one_in_binary(int number)
{
    int number_of_one=0;
    while(number>=1)
    {
        number_of_one+=number%2;
        number/=2;
    }
    return number_of_one;
}
int main()
{
    int input_case=0;
    cin>>input_case;
    while(input_case--)
    {
        int input=0;
        cin>>input;

        int b1=number_of_one_in_binary(input);
        int b2=0;
        string reg;
        stringstream ss;    //用stringstream把每個字元分開丟入binary
        ss<<input;
        ss>>reg;
        for(int i=0;i<reg.size();i++)
        {
            b2+=number_of_one_in_binary(reg[i]-'0');
        }
        cout<<b1<<" "<<b2<<endl;
    }
}
