#include<iostream>
#include<sstream>
#include<stack>
#include<stdio.h>
#include<math.h>
using namespace std;
int binary_to_dec(string input)     //二進位轉十進位(string->int)
{
    int output=0;
    for(int i=0;i<input.size();i++)
    {
        output+=(input[i]-'0')*pow(2,input.size()-i-1);
    }
    return output;
}
string binary(int input)           //十進位轉二進位(int->string)
{
    stack<int> st;
    if(input<1)
    {
        st.push(input%2);
    }
    while(input>=1)
    {
        st.push(input%2);
        input/=2;
    }
    stringstream sso;
    while(!st.empty())
    {
        sso<<st.top();
        if(!st.empty())
        {
           st.pop();
        }
        else
        {
            break;
        }
    }
    string output;
    sso>>output;
    return output;
}
int main()
{
    string MAP="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";  //Base64編碼表
    string total_input;
    stringstream total_ss;
    while(1)
    {
        string input;
        getline(cin,input);     //每列input
        if(input!="##")
        {
            total_ss<<input;    //以stringstream將所有輸入串接成一字串，直到end
        }
        else
        {
            total_ss>>total_input;      //當結束input，把每列input串成一個string
            int COUNT=0;                //計算四個字元做一次轉換，不直接用for的i%4是因為可能參雜沒在編碼表裡的字元
            stringstream combine;
            for(int i=0;i<total_input.size();i++)
            {
                if(total_input[i]=='#') //遇到單一#，印出#
                {
                    cout<<'#';
                }
                else  if((MAP.find(total_input[i])>=MAP.size()||MAP.find(total_input[i])<0)&&total_input[i]!='=')
                {                       //遇到非編碼表內字元，不做任何事情，將之篩掉
                }
                else
                {
                    int total_input_number=0;
                    if(total_input[i]!='=')    //若非'='符號，去編碼表裡找編碼號碼，若為'='，則total_input_number=0(初始值)
                    {
                        total_input_number=MAP.find(total_input[i]);
                    }
                    if(binary(total_input_number).size()<6) //若Base64內編碼數字轉換成binary少於六個字元，前面補零
                    {
                        for(int i=0;i<6-binary(total_input_number).size();i++)
                        {
                            combine<<'0';
                        }
                    }
                    combine<<binary(total_input_number);    //將轉換好的binary丟入stringstream去跟前面的0做串接
                    COUNT++;
                    if(COUNT==4)
                    {
                        string base_4;
                        combine>>base_4;                    //將4個字元傳換成的binary串接成一個string
                        combine.clear();
                        stringstream combine_8bits;
                        for(int i=0;i<base_4.size();i++)    //每8個binary字元為一切割
                        {
                            if(i%8==7)
                            {
                                string base_8;
                                combine_8bits<<base_4[i];
                                combine_8bits>>base_8;      //轉成一8bits之字串
                                combine_8bits.clear();
                                int output=binary_to_dec(base_8);   //將字串轉成10進位
                                char output_char=output;            //將10進位int轉成char
                                if(output!=0)               //因'='為0，所以非0則輸出
                                {
                                    cout<<output_char;
                                }
                            }
                            else
                            {
                               combine_8bits<<base_4[i];    //用stringstream去串接字元成一字串
                            }
                        }
                        COUNT=0;
                    }
                }
            }
            cout<<'#'<<endl;
            break;
        }
    }
}
