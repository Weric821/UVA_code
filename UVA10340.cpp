#include<iostream>
using namespace std;
int main()
{
    string subsequence;
    string sequence;
    while(cin>>subsequence>>sequence)
    {
        int sum=0;
        int count_subsequence=0;
        for(int i=0;i<sequence.size();i++)  //從sequence從比對每個subsequence的元素
        {
            if(subsequence[count_subsequence]==sequence[i]) //有這個元素count_subsequence就加一
            {
                count_subsequence++;
            }
        }
        if(count_subsequence==subsequence.size())
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}
