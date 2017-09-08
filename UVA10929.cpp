#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    string input;
    long long int sumodd=0;
    long long int sumeven=0;
    while(cin>>input&&input!="0")
    {
        for(int i=0;i<input.size();i++)
        {
            if(i%2==0)
            {
                sumeven+=(input[i]-'0');
            }
            else
            {
                sumodd+=(input[i]-'0');
            }
        }
        if(abs(sumeven-sumodd)%11==0)
        {
            cout<<input<<" is a multiple of 11."<<endl;
        }
        else
        {
            cout<<input<<" is not a multiple of 11."<<endl;
        }
        sumeven=0;
        sumodd=0;
    }
}
