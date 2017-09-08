#include<iostream>
#include<ctype.h>

using namespace std;

int main()
{
    string s="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    string s_incode="234567890-=`1ertyuiop[]\\qwdfghjkl;'ascvbnm,./zx"; // \q為一個特殊指令所以前面多加個\

    char arr[1001]={NULL};
    cin.getline(arr,1001);
    for(int i=0;arr[i]!=NULL;i++)
    {
            arr[i]=tolower(arr[i]);				//#include<ctype.h>	tolower()，大寫轉小寫；toupper()，小寫轉大寫；非字母則不動

            for(int j=0;j<s_incode.size();j++)
            {
                if(arr[i]==s_incode[j])
                {
                    arr[i]=s[j];
                    break;
                }
            }
    }
    for(int i=0;arr[i]!=NULL;i++)
    {
            cout<<arr[i];
    }
        arr[1001]={NULL};
}
