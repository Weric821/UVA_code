#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int input=0;
    while(cin>>input)
    {
        int input_arr[input]={0};
        for(int i=0;i<input;i++)
        {
            cin>>input_arr[i];
        }
        sort(input_arr,input_arr+input);    //將輸入由小到大排好
        if(input%2==0)
        {
            cout<<input_arr[input/2-1]<<" "<<2<<" "<<input_arr[input/2]-input_arr[input/2-1]+1<<endl;;
        }
        else
        {
            cout<<input_arr[input/2]<<" "<<1<<" "<<1<<endl;;
        }
    }
}
