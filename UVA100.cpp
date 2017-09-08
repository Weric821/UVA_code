#include<iostream>
using namespace std;

int evenodd(long long int input,long long int Count)        //計算考拉茲長度
{
    if(input==1)
    {
        return  Count;
    }
    if(input%2==0)
    {
        Count++;
        evenodd(input/2,Count);
    }
    else
    {
        Count++;
        evenodd(input*3+1,Count);
    }
}

int main()                          //尚未剪枝
{
    long long int input1=0;
    long long int input2=0;
    long long int output=0;
    long long int output2=0;
    long long int current=0;
    long long int Count=1;
    long long int MAX=0;

    while(cin>>input1>>input2)
    {
           output=input1;               //因等等input1會遞增，以output保存原值
           output2=input2;
           if(input1>input2)
           {
               swap(input1,input2);
           }
           while(input1<=input2)
           {
                current=evenodd(input1,Count);      //計算目前這個數字的考拉茲長度
                if(current>MAX)                     //跟MAX比較，目前比較大則取代
                {
                    MAX=current;
                }
                Count=1;
                input1++;
           }
           cout<<output<<" "<<output2<<" "<<MAX<<endl;

           input1=0;
           input2=0;
           output=0;
           MAX=0;
           current=0;
           Count=1;
    }
}
