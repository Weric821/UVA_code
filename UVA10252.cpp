#include<iostream>

using namespace std;

string a_z="abcdefghijklmnopqrstuvwxyz";        //設全域變數
int main()
{
    string a;
    string b;
    char a_num[256];        //將a~z設成索引值
    char b_num[256];

    while(cin>>a>>b)
    {
        for(int i=0;i<a_z.size();i++)   //初始化
        {
            a_num[a_z[i]]=0;
            b_num[a_z[i]]=0;
        }
        for(int i=0;i<a.size();i++)
        {
            a_num[a[i]]++;              //計算字母個數
        }
        for(int i=0;i<b.size();i++)
        {
            b_num[b[i]]++;
        }

        for(char i='a';;i++)            //走訪完整個陣列
        {
            if(a_num[i]>0&&b_num[i]>0)  //若兩者都有此字元，即數值>0
            {
                for(int j=0;j<min(a_num[i],b_num[i]);j++)   //取兩者中數目少的，即為共同子字串
                {
                    cout<<i;
                }
            }
            if(i=='z')
            {
                break;
            }
        }
        cout<<endl;
    }
}
