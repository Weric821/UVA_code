#include<iostream>
using namespace std;
int main()
{
    int a,b;
    int arr[100001]={0};
    for(int i=1;i*i<100001;i++) //記錄下那些數字是完全平方數
    {
        arr[i*i]=1;
    }
    for(int i=0;i<100001;i++)   //將結果轉換成累加紀錄
    {
        arr[i]+=arr[i-1];
    }
    while(cin>>a>>b&&(a!=0||b!=0))
    {
        cout<<arr[b]-arr[a-1]<<endl;
    }
}
