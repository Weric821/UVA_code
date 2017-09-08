//(用set實作)
#include<iostream>
#include<set>
#include<algorithm>

using namespace std;
int main()
{
   int arr_length=0;
   while(cin>>arr_length)
   {
       set<int> st;
       int *arr=new int [arr_length];
       for(int i=0;i<arr_length;i++)
       {
           cin>>arr[i];
       }
       for(int i=0;i<arr_length-1;i++)
       {
           if(abs(arr[i]-arr[i+1])>=arr_length)
           {
               break;
           }
           st.insert(abs(arr[i]-arr[i+1]));
       }
       if(st.size()==arr_length-1)
       {
           cout<<"Jolly"<<endl;
       }
       else
       {
           cout<<"Not jolly"<<endl;
       }
       delete[] arr;
   }
}
