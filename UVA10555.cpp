#include<iostream>
#include<map>
#include<sstream>
using namespace std;
int gb(int a,int b)     //用輾轉相除法求最大公因數，用來讓(分子/分母)最簡化
{
    if(a<b)
    {
        gb(b,a);
    }
    if(a%b==0)
    {
        return b;
    }
    else
    {
        gb(b,a%b);
    }
}
int main()
{
    string input;
    while(cin>>input&&(input!="0"))
    {
        map<int,int> mp;    //用map存取，並將分母當索引值，讓之自動以分母由小到大排列
        map<int,int>::iterator iter;
        stringstream ss;    //以stringstream將小數點以下到...之前的資料取出存回input
        for(int i=2;i<input.size()-3;i++)
        {
            ss<<input[i];
        }
        ss>>input;
        int SIZE=input.size();
        stringstream ss_input_interger; //將input轉成int，在分子分母取最大公因數時會用到
        ss_input_interger<<input;
        int input_interger=0;   //input <int>
        ss_input_interger>>input_interger;
        while(SIZE>0)
        {
            stringstream s_reg; //存取分母值
            stringstream s_Numerator;   //存取分子要減去之值
            int N_Numerator=0;
            for(int i=0;i<input.size()-SIZE;i++)
            {
                s_Numerator<<input[i];
            }
            s_Numerator>>N_Numerator;
            for(int i=0;i<SIZE;i++)
            {
                s_reg<<9;
            }
            for(int i=SIZE;i<input.size();i++)
            {
                s_reg<<0;
            }
            int de_Denominator=0;
            s_reg>>de_Denominator;  //將分母存成int
            int greatest_common_divisor=gb(input_interger-N_Numerator,de_Denominator);  //最大公因數
            mp[(input_interger-N_Numerator)/greatest_common_divisor]=de_Denominator/greatest_common_divisor;
            //最簡化，並以分母當索引值存入map
            SIZE--;
        }
        iter=mp.begin();            //map第一位即為分母最小值的資料
        cout<<iter->first<<"/"<<iter->second<<endl;
    }
}
