#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
int main()
{
    string input;
    while(cin>>input)
    {
        map <char,int> mp;
        map <char,int>::iterator iter;
        for(int i=0;i<input.size();i++)
        {
            mp[(-1)*input[i]]++;      //先以字元為索引值，並統計數字，因map會將字母以小到大排，與題目所求相反，故乘-1
        }
        multimap <int,int> mp2;
        map <int,int>::iterator iter2;
        for(iter=mp.begin();iter!=mp.end();iter++)
        {
            mp2.insert(make_pair(iter->second,iter->first));    //換以統計出的數字排序，數字由小到大排
        }
        for(iter2=mp2.begin();iter2!=mp2.end();iter2++)
        {
            cout<<(-1)*iter2->second<<" "<<iter2->first<<endl;
        }
        cout<<endl;
    }
}
