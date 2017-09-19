#include<iostream>
#include<set>
#include<math.h>
using namespace std;

string arr="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int main()
{
    string input;
    while(cin>>input)
    {
        set <char> st;
        set <char>::iterator iter;
        for(int i=0;i<input.size();i++)
        {
            st.insert((-1)*input[i]);       //要找出最大，所以乘負號讓set排序
        }
        iter=st.begin();
        char result=*iter*(-1);

        int start=0;
        while(arr[start]!=result)
        {
            start++;
        }
        start++;

        long long int sum=0;
        for(int i=start;i<63;i++)
        {
           for(int j=input.size()-1;j>=0;j--)
            {
                int case_number=0;
                while(arr[case_number]!=input[j])
                {
                    case_number++;
                }

                double PLUS=pow(i,((input.size()-1)-j));    //電腦小數計算會有誤差，用double存再去做運算將誤差值縮到最小，避免用int在PLUS就出現誤差
                sum+=case_number*PLUS;                      //使得case_number*PLUS讓誤差放大後，sum出現整數誤差
            }
            if(sum%(i-1)==0)
            {
                cout<<i<<endl;
                i=63;
                break;
            }
            else
            {
                sum=0;
                if(i==62)
                {
                    cout<<"such number is impossible!"<<endl;
                }
            }
        }
    }
}
