#include<iostream>
using namespace std;
void bubble_sort(int *arr,int arr_size) //Bubble sort
{
    int min_swap_times=0;
    for(int i=0;i<arr_size;i++)
    {
        for(int j=0;j<arr_size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);  //每做一次swap計數一次
                min_swap_times++;
            }
        }
    }
    cout<<"Optimal train swapping takes "<<min_swap_times<<" swaps."<<endl;
}
int main()
{
    int input_case=0;
    cin>>input_case;
    while(input_case--)
    {
        int train_length=0;
        cin>>train_length;
        int *train=new int[train_length];   //為了傳入自訂函式，故開動態陣列
        for(int i=0;i<train_length;i++)
        {
            cin>>train[i];
        }
        bubble_sort(train,train_length);
    }
}
