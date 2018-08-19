#include<iostream>
#include<set>
#include<sstream>
#include<cmath>
using namespace std;

int gcd(int a,int b)    //用輾轉相除法做最大公因數
{
    if(b>a)
    {
        return gcd(b,a);
    }
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}
int main()
{
    string input;
    while(getline(cin,input)&&input!="0")
    {
        stringstream ss;    //將input由字串轉為一個個int
        ss<<input;
        set<int> st;        //用set去存取input之int，可以直接去除重複並達到排序功能
        set<int>::iterator iter;
        int reg=1;          //暫存int
        while(reg!=0)       //輸入最後一位必為0
        {
            ss>>reg;
            st.insert(reg);
        }
        int min_number=0;
        for(iter=st.begin();iter!=st.end();iter++)
        {
            if(*iter!=0)
            {
                min_number=*iter;//排好序之後，找出其中最小值(不包括0)
                break;
            }
        }
        int gcd_reg[((st.size()+1)*st.size())/2]={0};   //存放所有數字互相做gcd的結果
        int COUNT=0;
        for(iter=st.begin();iter!=st.end();iter++)
        {
            if(*iter!=0)
            {
                gcd_reg[COUNT]=*iter-min_number;        //將每個數字減到最小的值
                COUNT++;
            }
        }
        for(int i=0;i<(st.size()*(st.size()-1))/2;i++)
        //將相鄰數字互相做gcd，並將結果再做gcd，一直做到剩下一個數字，即為所有數字的最大公因數
        {
            gcd_reg[COUNT]=gcd(abs(gcd_reg[i]),abs(gcd_reg[i+1]));  //要考慮負數，負數加絕對值
            COUNT++;
        }
        cout<<gcd_reg[COUNT-1]<<endl;   //最後一個數字即為最大公因數
    }
}
