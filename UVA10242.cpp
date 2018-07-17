#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    double x[4],y[4]={0};
    while(cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3])
    {
        int repeat=0;
        for(int i=0;i<4;i++)        //找出重複的點在陣列中的位址記在repeat
        {
            for(int j=i+1;j<4;j++)
            {
                if(x[i]==x[j]&&y[i]==y[j])
                {
                    repeat=i;
                    i=4;
                    break;
                }
            }
        }
        double x_nr[3],y_nr[3]={0};
        int nr_count=0;
        for(int i=0;i<4;i++)
        {
            if(i==repeat)          //遇到重複的點跳過
            {
                i++;
            }
            x_nr[nr_count]=x[i];
            y_nr[nr_count]=y[i];
            nr_count++;
        }
        printf("%.3f %.3f\n",(x_nr[0]+x_nr[2]-x_nr[1]),(y_nr[0]+y_nr[2]-y_nr[1]));
    }
}
