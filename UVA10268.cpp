#include<iostream>
#include<sstream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int Function(int sum,int x,int n,int coefficient)   //微分計算
{
    sum=sum+coefficient*n*pow(x,n-1);
    return sum;
}
int main()
{
    int x=0;
    while(cin>>x)
    {
        getchar();              //吃enter
        string input;
        char arr_input[100000]={NULL};
        int arr_after_transfer[100000]={NULL};
        int COUNT=0;

        cin.getline(arr_input,100000);

        stringstream ss;
        ss<<arr_input;
        for(int i=0;arr_input[i]!=NULL;i++)
        {
            ss>>arr_after_transfer[i];          //將資料處理，除去空白並存到int陣列
        }
        for(int i=0;arr_after_transfer[i]!=NULL;i++)
        {
            COUNT++;                            //計算int陣列長度
        }
        long long int sum=0;
        for(int i=0;i<COUNT;i++)
        {
            sum=Function(sum,x,COUNT-i-1,arr_after_transfer[i]);
        }
        cout<<sum<<endl;
        delete[] arr_input;
        delete[] arr_after_transfer;
    }
}
