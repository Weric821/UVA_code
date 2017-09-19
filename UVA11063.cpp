#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;

void B2_Sequence(long long int *arr,int SIZE)
{
    set <int> st;
    for(int i=0;i<SIZE;i++)             //將陣列中所有的值互相相加，丟到set
    {
        for(int j=i;j<SIZE;j++)
        {
            if(arr[i]>arr[j])          //若發現並非遞增數列，故意跳出讓SIZE不合
            {
                break;
            }
            st.insert(arr[i]+arr[j]);
        }
    }
    if(st.size()!=SIZE*(SIZE-1)/2+SIZE) //若有重複，則set的size!=C(N,2) + N (+N是自己加自己的case)
    {
        cout<<"It is not a B2-Sequence."<<endl;
    }
    else
    {
        cout<<"It is a B2-Sequence."<<endl;
    }
}
int main()
{
    long long int N=0;
    long long int output_case=0;
    while(cin>>N)
    {
        output_case++;
        long long int inputnumber[N]={0};
        for(int i=0;i<N;i++)
        {
            cin>>inputnumber[i];
        }
        cout<<"Case #"<<output_case<<": ";
        B2_Sequence(inputnumber,N);
        getchar();                      //接受兩個case之間的enter

        delete [] inputnumber;
    }
}
