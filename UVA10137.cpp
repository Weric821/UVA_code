#include<iostream>
#include<iomanip>
#include<cmath>				//abs()需引入cmath
using namespace std;
int main()
{
    int input_number=0;
    while(cin>>input_number&&input_number!=0)
    {
        float  arr[input_number]={0.0};
        float avg=0;
        for(int i=0;i<input_number;i++)    //算出平均數，並將input存到arr
        {
            cin>>arr[i];
            avg+=arr[i];
        }
        avg/=input_number;

        float S_avg=0.0;                   //存比avg小的數字與avg的總差距
        float L_avg=0.0;                   //存比avg大的數字與avg的總差距
        for(int i=0;i<input_number;i++)
        {
            float reg=abs(avg-arr[i]);
            if(reg>=0.01)
            {
                int delete_2_reg=reg*100;   //此須無條件捨去小數點以下3位，因貨幣最小到0.01
                reg=delete_2_reg/100.00;    //用float*100存成int達成除去小數以下三位數字功能
                if(arr[i]<avg)
                {
                    S_avg+=reg;
                }
                else if(arr[i]>avg)
                {
                    L_avg+=reg;
                }
            }
        }
        float output=max(S_avg,L_avg);
        cout<<"$"<<fixed<<setprecision(2)<<output<<endl;    //輸出補齊小數以下兩位
    }
}
