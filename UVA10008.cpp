#include<iostream>
#include<stdio.h>
#include<map>

using namespace std;

int main()
{
    int inputcase=0;

    cin>>inputcase;
    getchar();                              //以防之後getline被enter影響

    map <char,int> mp;                      //先以map讓字母由小到大排(A~Z)
    map <char,int>::iterator iter;
    while(inputcase--)
    {
        char arr[1001]={NULL};
        cin.getline(arr,1001);

        for(int i=0;arr[i]!=NULL;i++)
        {
            if('a'<=arr[i]&&arr[i]<='z')    //小寫換成大寫
            {
                arr[i]-=32;
            }
            mp[arr[i]]++;

        }
    }
    multimap <int,char> mp2;                //再以map2排字母總數大小
    multimap <int,char>::iterator iter2;    //因map會自動由小到大排，而題目要求總數由大到小，故將總數取負號存入map，最後顯示的時候再取負號回來
    for(iter=mp.begin();iter!=mp.end();iter++)
    {
        mp2.insert(make_pair(-(iter->second),iter->first));
    }
    for(iter2=mp2.begin();iter2!=mp2.end();iter2++)
    {
        if('A'<=iter2->second&&iter2->second<='Z')
        {
            cout<<iter2->second<<" "<<-(iter2->first)<<endl;
        }
    }
}
