#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
    int input_case=0;
    cin>>input_case;
    getchar();
    while(input_case--)
    {
        getchar();
        int bits=0;
        cin>>bits;
        stack<int> number1;
        stack<int> number2;
        int num1=0;
        int num2=0;
        while(bits--)
        {
            cin>>num1>>num2;        //將兩邊每個位元的數字分別存到兩個stack
            number1.push(num1);     //存入stack是因為加法要從個位數開始加
            number2.push(num2);
        }
        stack<int> sum;             //因為輸出要從最高位元輸出，故再用stack存加法之後的結果
        int carry=0;
        while(1)
        {
            int ssum=0;
            if(number1.empty())     //最後如果兩個數字位元都加完了，跳出
            {
                if(carry==1)        //如果加完之後carry=1，則要加一位最高位元1
                {
                   sum.push(1);
                }
                break;
            }
            else
            {
                ssum=number1.top()+number2.top()+carry;
                number1.pop();
                number2.pop();
                if(ssum>9)
                {
                    carry=1;
                    sum.push(ssum%10);
                }
                else
                {
                    carry=0;
                    sum.push(ssum);
                }
            }
        }
        while(1)
        {
            if(sum.empty())
            {
                cout<<endl;
                if(input_case!=0)   //最後一組資料不用空一列
                {
                    cout<<endl;
                }
                break;
            }
            else
            {
                cout<<sum.top();
                sum.pop();
            }
        }
    }
}
