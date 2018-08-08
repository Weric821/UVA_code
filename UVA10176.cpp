#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    string input;
    stringstream ss;
    while(cin>>input)
    {
        if(input[input.size()-1]!='#')
        {
            ss<<input;
        }
        else
        {
            ss<<input;
            ss>>input;          //用stringstream存input，因為可能一列完還沒結束，末端沒有#
            ss.clear();
            long long int remainder=0;
            long long int sum=0;
            int flag=0;         //用來測試input是否大於131071，除了0以外，小於131071皆不能整除
            for(int i=0;i<input.size()-1;i++)
            {
                sum+=(input[i]-'0');
                if(sum>=131071)
                {
                    flag=1;
                    remainder=sum%131071;   //餘數
                    sum=remainder*2;        //餘數左移，乘二繼續計算
                }
                else
                {
                    sum*=2;             //左移，即乘二
                }
            }
            if((remainder==0&&flag==1)||input=="0#")    //0為特殊情形
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }
}
