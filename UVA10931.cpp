#include<iostream>
#include<stack>
using namespace std;

void number_of_one_in_binary(long long int number)
{
    stack<int> st;      //將每次算的餘數丟入stack，並反向輸出
    int number_of_one=0;
    while(number>=1)
    {
        number_of_one+=number%2;
        st.push(number%2);
        number/=2;
    }
    cout<<"The parity of ";
    while(!st.empty())  //將stack中所有的元素丟出
    {
        cout<<st.top();
        st.pop();
    }
    cout<<" is "<<number_of_one<<" (mod 2)."<<endl;
}
int main()
{
    long long int input=0;
    while(cin>>input&&input!=0)
    {
        number_of_one_in_binary(input);
    }
}
