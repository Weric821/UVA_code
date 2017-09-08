#include<iostream>
using namespace std;

char week[7][10]={"Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"};
int monthday[12]={31,28,31,30,31,30,31,31,30,31,30};
int main()
{
    int input_case=0;
    int date[2]={0};
    int day_sum=0;
    cin>>input_case;
    while(input_case--)
    {
        cin>>date[0]>>date[1];
        for(int i=0;i<date[0]-1;i++)
        {
            day_sum+=monthday[i];
        }
        day_sum+=date[1];
        cout<<week[day_sum%7]<<endl;
        day_sum=0;
    }
}
