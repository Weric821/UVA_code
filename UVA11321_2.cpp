#include <iostream>
#include <algorithm>
using namespace std;

int N,M=0;                          //compare需要，所以訂成全域變數
bool compare(int m,int n)
{
    int m_M=m%M;
    int n_M=n%M;
    int m_2=abs(m%2);
    int n_2=abs(n%2);

    if(m_M!=n_M)
    {
            return m_M<n_M;
    }
    else
    {
        if(m_2!=n_2)
        {
                return m_2>n_2;         //這邊return都是指誰擺前面
        }
        else if(m_2=n_2&&m_2==1)
        {
                return m>n;
        }
        else
        {
                return m<n;
        }
    }
}

int main()
{
    int *numberarr;

    while(cin>>N>>M&&(N!=0||M!=0))
    {
        numberarr=new int [N];
        for(int i=0;i<N;i++)
        {
            cin>>numberarr[i];
        }
        cout<<N<<" "<<M<<endl;
        sort(numberarr,numberarr+N,compare);
        for(int i=0;i<N;i++)
        {
            cout<<numberarr[i]<<endl;
        }
        delete[] numberarr;
    }
}
