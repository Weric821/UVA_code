#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
int main()
{
    int input_case=0;
    cin>>input_case;
    getchar();                      //吃cin與getline之間的enter
    while(input_case--)
    {
        getchar();                  //吃每組測資之間的enter
        map<string,double> mp;
        map<string,double>::iterator iter;
        int total_input=0;
        string input_arr;
        while(getline(cin,input_arr)&&input_arr!="")
        {
        //用getline(cin,string)去接整列資料
        //因為getline(cin,string)不吃enter，所以當沒資料時即為直接按enter
            mp[input_arr]++;
            total_input++;
        }
        for(iter=mp.begin();iter!=mp.end();iter++)
        {
            cout<<iter->first<<" ";
            printf("%.4f\n",iter->second/total_input*100);
        }
    }
}
