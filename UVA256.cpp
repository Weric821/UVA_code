#include<iostream>
#include<set>
#include<math.h>
#include<sstream>
using namespace std;
int main()
{                                       //s2.s4.s6.s8作法雷同，註解看s2
    set<string> st_2;                   //用set存output之string
    set<string>::iterator st_2_iter;
    for(int i=0;i<10;i++)
    {
        int s1_2=i*i;                   //s1=i平方
        double s2_2=pow((s1_2/10+s1_2%10),2);   //s2=(i/10+i%10)的平方，即十位數加個位數的平方
        if(s1_2==s2_2)
        {
            stringstream ss_2;
            ss_2<<s1_2/10<<s1_2%10;
            string output_2;
            ss_2>>output_2;
            st_2.insert(output_2);
        }
    }
    set<string> st_4;
    set<string>::iterator st_4_iter;
    for(int i=0;i<100;i++)
    {
        int s1_4=i*i;
        double s2_4=pow((s1_4/100+s1_4%100),2);
        if(s1_4==s2_4)
        {
            string output_4;
            stringstream ss_4;
            if(s1_4<1000)           //不滿四位補零
            {
                ss_4<<s1_4;
                ss_4>>output_4;
                ss_4.clear();
                for(int i=0;i<4-output_4.size();i++)
                {
                    ss_4<<'0';
                }
            }
            ss_4<<s1_4;
            ss_4>>output_4;
            st_4.insert(output_4);
        }
    }
    set<string> st_6;
    set<string>::iterator st_6_iter;
    for(int i=0;i<1000;i++)
    {
        int s1_6=i*i;
        double s2_6=pow((s1_6/1000+s1_6%1000),2);
        if(s1_6==s2_6)
        {
            string output_6;
            stringstream ss_6;
            if(s1_6<100000)        //不滿六位補零
            {
                ss_6<<s1_6;
                ss_6>>output_6;
                ss_6.clear();
                for(int i=0;i<6-output_6.size();i++)
                {
                    ss_6<<'0';
                }
            }
            ss_6<<s1_6;
            ss_6>>output_6;
            st_6.insert(output_6);
        }
    }
    set<string> st_8;
    set<string>::iterator st_8_iter;
    for(int i=0;i<10000;i++)
    {
        int s1_8=i*i;
        double s2_8=pow((s1_8/10000+s1_8%10000),2);
        if(s1_8==s2_8)
        {
            string output_8;
            stringstream ss_8;
            if(s1_8<10000000)       //不滿八位補零
            {
                ss_8<<s1_8;
                ss_8>>output_8;
                ss_8.clear();
                for(int i=0;i<8-output_8.size();i++)
                {
                    ss_8<<'0';
                }
            }
            ss_8<<s1_8;
            ss_8>>output_8;
            st_8.insert(output_8);
        }
    }

    int input=0;
    while(cin>>input)   //依據輸入去找不同的set走訪結果
    {
        switch (input)
        {
            case 2:
                for(st_2_iter=st_2.begin();st_2_iter!=st_2.end();st_2_iter++)
                {
                    cout<<*st_2_iter<<endl;
                }
            break;
            case 4:
                for(st_4_iter=st_4.begin();st_4_iter!=st_4.end();st_4_iter++)
                {
                    cout<<*st_4_iter<<endl;
                }
            break;
            case 6:
                for(st_6_iter=st_6.begin();st_6_iter!=st_6.end();st_6_iter++)
                {
                    cout<<*st_6_iter<<endl;
                }
            break;
            case 8:
                for(st_8_iter=st_8.begin();st_8_iter!=st_8.end();st_8_iter++)
                {
                    cout<<*st_8_iter<<endl;
                }
            break;
        }
    }
}
