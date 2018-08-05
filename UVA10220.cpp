#include<iostream>
#include<sstream>
#include<stack>
using namespace std;
int main()
{
    int ans[1001]={0};				//將1000!的每位數總和存在此array
    string dp="1";				//1!=1
    for(int j=1;j<=1000;j++)			//從1乘到1000，每次紀錄所乘的數字，即能得知1!到1000!
    {
            int carry=0;
            stack<int> sk;			//存目前階層所乘出來的大數
            for(int k=dp.size()-1;k>=0;k--)
            {
                int reg=0;
                reg=(dp[k]-'0')*j+carry;	//將j乘上主要大數，超過10則進位
                if(reg>9)
                {
                   carry=reg/10;
                   ans[j]+=reg%10;		//記錄每一位數字到array
                   sk.push(reg%10);
                }
                else
                {
                   carry=0;
                   ans[j]+=reg;
                   sk.push(reg%10);
                }
            }
            if(carry!=0)
            {
                while(carry>0)
                {
                     sk.push(carry%10);
                     ans[j]+=carry%10;
                     carry/=10;
                }
            }
            stringstream ss;
            while(!sk.empty())
            {
                ss<<sk.top();
                sk.pop();
            }
            ss>>dp;
    }
    int input=0;
    while(cin>>input)
    {
        cout<<ans[input]<<endl;
    }
}
