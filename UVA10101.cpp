#include<iostream>
#include<string>
using namespace std;

void cut(long long int data,int Case)
{
    char *word[4]={"kuti","lakh","hajar","shata"};
    int number[4]={10000000,100000,1000,100};
    if(data>=number[0])
    {
        cout<<" "<<data/number[0]<<" "<<word[0];
        cut(data-(data/number[0])*number[0],Case);

    }
    else if(data>=number[1])
    {
        cout<<" "<<data/number[1]<<" "<<word[1];
        cut(data-(data/number[1])*number[1],Case);
    }
    else if(data>=number[2])
    {
        cout<<" "<<data/number[2]<<" "<<word[2];
        cut(data-(data/number[2])*number[2],Case);
    }
    else if(data>=number[3])
    {
        cout<<" "<<data/number[3]<<" "<<word[3];
        cut(data-(data/number[3])*number[3],Case);
    }
    else
    {
        if(Case==0)
        {
           cout<<" "<<data<<endl;
        }
        else
        {
           cout<<" "<<data<<" kuti ";
        }
    }
}
int main()
{
    long long int input=0;
    int num=1;
    while(cin>>input)
    {
        cout<<num<<".";
        num++;
        if(input>999999999)
        {
            cut(input/10000000,1);
            cut(input%10000000,0);
        }
        else
        {
            cut(input,0);
        }
    }
}
