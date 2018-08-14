#include<iostream>
#include<math.h>
#include<set>
#include<sstream>
#include <iomanip>
using namespace std;
int main()
{
   double L,W=0;
   while(cin>>L>>W)
   {
        double X[4]={0.0};      //由一階微分=0解出來的x值加上邊界，總共只需測4個值
         X[0]=((L+W)+pow((L*L+W*W-L*W),0.5))/6;
         X[1]=((L+W)-pow((L*L+W*W-L*W),0.5))/6;
         X[2]=min(L,W)*0.5;
        set<float> MIN;         //用set紀錄x，因會自動排序
        set<float> MAX;
        float MAX_Volume=0,MIN_Volume=0;
        float Volume=0.0;
        for(int i=0;i<4;i++)
        {
            stringstream ss;
            Volume=(L-(2*X[i]))*(W-(2*X[i]))*X[i];
            ss<<fixed << setprecision(3)<<Volume;   //小數取三位，以下四捨五入
            ss>>Volume;
            if(Volume==MIN_Volume)
            {
                MIN.insert(X[i]);
            }
            if(Volume>MAX_Volume)
            {
                MAX_Volume=Volume;
                MAX.clear();
                MAX.insert(X[i]);
            }
            else if(Volume==MAX_Volume)
            {
                MAX.insert(X[i]);
            }
        }

        set<float>::iterator MIN_iter;
        set<float>::iterator MAX_iter;
        for(MAX_iter=MAX.begin();MAX_iter!=MAX.end();MAX_iter++)
        {
            if(MAX_iter!=MAX.begin())
            {
               cout<<" "<<fixed<<setprecision(3)<<*MAX_iter;
            }
            else
            {
               cout<<fixed<<setprecision(3)<<*MAX_iter;
            }
        }
        for(MIN_iter=MIN.begin();MIN_iter!=MIN.end();MIN_iter++)
        {
                cout<<" "<<fixed<<setprecision(3)<<*MIN_iter;
        }
        cout<<endl;
   }
}
