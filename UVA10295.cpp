#include<iostream>
#include<map>
using namespace std;
int main()
{
    int m,n=0;
    cin>>m>>n;    //m為字典裡幾個單字，n為幾篇文章
    map <string,int> mp;    //用map來記錄字典單字及價錢
    for(int i=0;i<m;i++)    //字典登錄單字及價錢入map
    {
        string input;
        int input2;
        cin>>input>>input2;
        mp[input]+=input2;
    }
    while(n--)
    {
        string article;
        long long int output_price=0;       //整篇文章賺多少錢
        while(cin>>article&&(article!=".")) //當輸入不等於"."
        {
            if(mp.count(article)==1)        //當mp找的到單字
            {
                output_price+=mp.find(article)->second;
            }
        }
        cout<<output_price<<endl;
    }
}
