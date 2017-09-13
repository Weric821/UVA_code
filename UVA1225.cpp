#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    int input_case=0;
    cin>>input_case;
    while(input_case--)
    {
        int input=0;
        int record[10]={0};
        cin>>input;
        for(int i=1;i<=input;i++)
        {
            stringstream ss;    //將1~input數字丟入ss轉換成string
            ss<<i;
            string reg;
            ss>>reg;
            for(int i=0;i<reg.size();i++)   //將每個位元記錄在record
            {
                record[reg[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++)
        {
            cout<<record[i];
            if(i!=9)
            {
                cout<<" ";
            }
            else
            {
                cout<<endl;
            }
        }
    }
}
