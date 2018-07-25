#include<iostream>
#include<stdio.h>
using namespace std;
int switch_case(char input)     //挑音符之case
{
    switch (input)
    {
    case 'c':
        return 0;
        break;
    case 'd':
        return 1;
        break;
    case 'e':
        return 2;
        break;
    case 'f':
        return 3;
        break;
    case 'g':
        return 4;
        break;
    case 'a':
        return 5;
        break;
    case 'b':
        return 6;
        break;
    case 'C':
        return 7;
        break;
    case 'D':
        return 8;
        break;
    case 'E':
        return 9;
        break;
    case 'F':
        return 10;
        break;
    case 'G':
        return 11;
        break;
    case 'A':
        return 12;
        break;
    case 'B':
        return 13;
        break;
    }
}
int main()
{
    char finger[14][11]={
    "0111001111",
    "0111001110",
    "0111001100",
    "0111001000",
    "0111000000",
    "0110000000",
    "0100000000",
    "0010000000",
    "1111001110",
    "1111001100",
    "1111001000",
    "1111000000",
    "1110000000",
    "1100000000"};  //音符所需的finger
    int input_case=0;
    cin>>input_case;
    getchar();
    while(input_case--)
    {
        string input_arr;
        getline(cin,input_arr);
        int output[10]={0};     //output計算
        if(input_arr.size()!=0)
        {
            for(int i=0;i<10;i++)      //先將第一次按的按鍵計入
            {
                output[i]+=finger[switch_case(input_arr[0])][i]-'0';
            }
            for(int i=0;i<input_arr.size()-1;i++)
            {
                for(int j=0;j<10;j++)
                {
                    int a1=switch_case(input_arr[i]);
                    int a2=switch_case(input_arr[i+1]);
                    if(finger[a1][j]=='0'&&finger[a2][j]=='1')  //當這次沒按，但下次按了
                    {
                        output[j]++;
                    }
                }
            }
        }
        for(int i=0;i<10;i++)
        {
            cout<<output[i]<<" ";
        }
        cout<<endl;
    }
}
