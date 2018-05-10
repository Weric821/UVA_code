#include<iostream>
#include<stdio.h>
#include<math.h>
#define PI 2*acos(0.0)  //利用反餘弦求精準的pi
using namespace std;    //cos(pi/2)=0.0 所以acos(0.0)=pi/2 =>pi=2*acos(0.0)
void arc(int r,double degree)
{
    printf("%.6f ",2*r*PI*degree/360);
}
void line(int r,double rad) //運用餘弦定理求出第三邊
{
    printf("%.6f\n",pow(2*pow(r,2)*(1-cos(rad)),0.5));  //c++內是cos(弧度)
}
int main()
{
    int s,a=0;
    string type;
    while(cin>>s>>a>>type)
    {
        if(type!="deg")
        {
            a/=60;
        }
        arc(6440+s,a);
        line(6440+s,a*PI/180);  //因為cos()函式在c++內是要放弧度，故將(角度*pi/180)做轉換
    }
}
