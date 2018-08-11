#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double input_vtotla,input_v0=0;
    while(cin>>input_vtotla>>input_v0&&(input_vtotla!=0||input_v0!=0))
    {
        int n=input_vtotla/(2*input_v0);
        double sum[2]={0.0};
        for(int i=0;i<2;i++)
        {
            sum[i]=((-1.0)*(input_v0)*n*n)+(input_vtotla*n);
            n++;
        }
        if(sum[0]>sum[1])
        {
            cout<<n-2<<endl;
        }
        else if(sum[0]<sum[1])
        {
            cout<<n-1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
}
