#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int casenumber=0;
    int housenum=0;
    int mid1=0;
    int sum=0;
    int *arr;
    cin>>casenumber;
    while(casenumber--)
    {
        cin>>housenum;
        arr=new int [housenum];             //動態陣列，根據我輸入的房子總數去開陣列
        for(int i=0;i<housenum;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+housenum);             //排序陣列，引用<algorithm>，sort(array start,array end)
        if(housenum%2==0)
        {
            mid1=housenum/2-1;
            for(int j=0;j<housenum;j++)
            {
                sum=sum+abs(arr[j]-arr[mid1]);      //引用<algorithm>或<cmath>，取絕對值，abs(a)
            }
        }
        else
        {
             mid1=housenum/2;
             for(int j=0;j<housenum;j++)
             {
                 sum=sum+abs(arr[j]-arr[mid1]);
             }
        }
        cout<<sum<<endl;
        sum=0;
        mid1=0;
    }
}
