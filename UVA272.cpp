#include<iostream>
using namespace std;

int main()
{
    char input=NULL;
    int flag=0;
    while(cin.get(input))
    {
        if(input=='"'&&flag==0)
        {
            cout<<"``";
            flag=1;
        }
        else if(input=='"'&&flag==1)
        {
            cout<<"''";
            flag=0;
        }
        else
        {
            cout<<input;
        }
    }
}
