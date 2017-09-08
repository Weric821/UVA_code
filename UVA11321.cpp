//(尚未分析負數)
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool compare(int m,int n)
{
    return m>n;
}

void SORT(int *arr,int SIZE)
{
    switch(arr[0]%2)
    {
    case 0:
        {
            sort(arr,arr+SIZE);
            for(int i=0;i<SIZE;i++)
            {
                cout<<arr[i]<<endl;
            }
            break;
        }
    case 1:
        {
            sort(arr,arr+SIZE,compare);
            for(int i=0;i<SIZE;i++)
            {
                cout<<arr[i]<<endl;
            }
            break;
        }
    }
}
int main()
{
    int N=0;
    int M=0;
    int input=0;
    multimap <int,int> mp;
    multimap <int,int>::iterator iter;

    while(cin>>N>>M&&(N!=0||M!=0))
    {
        mp.clear();             //清除map，以防上一輪資料影響到下一輪資料
        for(int i=0;i<N;i++)
        {
            cin>>input;

            mp.insert(make_pair(input%M,input));    //用multimap先將餘數由小大大排好
        }
        cout<<N<<" "<<M<<endl;

        int Count=0;
        int oddbesort[N]={0};
        int *oddbesort2;
        int oddcount=0;
        int evenbesort[N]={0};
        int *evenbesort2;
        int evencount=0;

        for(iter=mp.begin();iter!=mp.end();)
        {
            if(iter->first==Count)              //將同餘數的數值分成奇數偶數
            {
                if(iter->second%2==0)
                {
                    evenbesort[evencount]=iter->second;
                    evencount++;
                }
                else
                {
                    oddbesort[oddcount]=iter->second;
                    oddcount++;
                }
                iter++;
            }

            if(iter->first!=Count)
            {
                oddbesort2=new int [oddcount];
                evenbesort2=new int [evencount];
                for(int i=0;i<oddcount;i++)
                {
                    oddbesort2[i]=oddbesort[i];
                }
                for(int i=0;i<evencount;i++)
                {
                    evenbesort2[i]=evenbesort[i];
                }

                SORT(oddbesort2,oddcount);          //針對奇數偶數實行不同的SORT
                SORT(evenbesort2,evencount);

                //reset
                delete[] oddbesort;
                delete[] evenbesort;
                delete[] oddbesort2;
                delete[] evenbesort2;
                oddcount=0;
                evencount=0;
                //reset
                Count++;
            }
        }
        Count=0;
    }
}
