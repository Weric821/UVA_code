#include<iostream>
using namespace std;
int main()
{
    string input;
    while(cin>>input&&input!=".")
    {
        int flag[input.size()];
        for(int i=0;i<input.size();i++)
        {
            flag[i]=1;              //初始化將紀錄之flag都設為1
        }
        for(int n=1;n<=input.size()/2;n++)  //n只需到一半，因為大於1/2小於1不可能為其子字串
        {
            for(int i=0;i<input.size()-n;i++)
            {
                if(input.size()%n!=0||input[i]!=input[i+n])
                {
                    flag[n-1]=0;    //當有不符合前面字串的，flag計為0跳出
                    break;
                }
            }
        }
        for(int i=0;i<input.size();i++)
        {
            if(flag[i]==1&&i<input.size()/2)
            {
                cout<<input.size()/(i+1)<<endl;
                break;
            }
            if(i>=input.size()/2)   //若檢查到字串長度1/2都沒有子字串，則只剩下整列字串
            {
                cout<<1<<endl;
                break;
            }
        }
    }
}
