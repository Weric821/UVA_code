#include<iostream>
#include<sstream>
#include<map>
using namespace std;

const char color[3]={'B','G','C'};  //三種顏色的瓶子
int arr[9]={0};                     //存輸入，三堆各個BGC瓶子個數

int Identify_color(char color,int start)
{
    //若此推決定放某特定顏色，另外兩種顏色的瓶子必定得挪動至其他堆
    //回傳當該堆決定為某顏色時，該堆必須挪動的瓶子個數
    switch(color)
    {
        case 'B':
            return arr[start+1]+arr[start+2];
        case 'G':
            return arr[start]+arr[start+2];
        case 'C':
            return arr[start]+arr[start+1];
    }
}
int main()
{
    //以map存各種狀況下需要移動的瓶子個數
    //mp以字母順序排序
    map<string,int> mp;
    map<string,int>::iterator iter;

    //'B','G','C' 排列組合
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i!=j)
            {
                stringstream ss;
                ss<<color[i]<<color[j]<<color[3-i-j];
                mp[ss.str()]=0;
            }
        }
    }

    while(cin>>arr[0])
    {
        for(int i=1;i<9;i++)
        {
            cin>>arr[i];
        }

        //將6種排列組合所需移動次數計算一遍，並記錄在mp
        for(iter=mp.begin();iter!=mp.end();iter++)
        {
            for(int i=0;i<iter->first.size();i++)
            {
                mp[iter->first]+=Identify_color(iter->first[i],i*3);
            }
        }

        //mp2改以挪動次數排序，則mp2.begin()即為所求
        multimap<int,string> mp2;
        multimap<int,string>::iterator iter2;

        for(iter=mp.begin();iter!=mp.end();iter++)
        {
            mp2.insert(make_pair(iter->second,iter->first));
            iter->second=0; //初始化mp
        }

        cout<<mp2.begin()->second<<" "<<mp2.begin()->first<<endl;
    }
}
