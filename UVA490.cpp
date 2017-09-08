//(輸出末尾可能有多出空格)
#include<iostream>
using namespace std;

int main()
{
    char arr[101][101]={NULL};
    int input_row=0;
    int max_cul=0;
    while(cin.getline(arr[input_row],101))
    {
        for(int i=0;arr[input_row][i]!=NULL;i++)
        {
            max_cul=max(max_cul,i+1);       //紀錄最大長度字串
        }
        input_row++;
    }
    for(int i=0;i<max_cul;i++)              //轉置
    {
        for(int j=input_row-1;j>=0;j--)
        {
            cout<<arr[j][i];
        }
        cout<<endl;
    }
}
