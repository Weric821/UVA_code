#include<iostream>
using namespace std;
int main()
{
    int case_number=0;
    cin>>case_number;
    for(int i=0;i<case_number;i++)
    {
        int x1,y1,x2,y2=0;
        long long int sum=0;
        cin>>x1>>y1>>x2>>y2;
        int number_of_first_level=(x1+y1)-x1;   //起始點沿著斜線到x軸有多長
        int number_of_final_level=x2;           //y軸沿斜線到終點有多長
        int number_of_first_to_final_level=((x1+y1+1)+((x2+y2-1))*((x2+y2)-(x1+y1)-1))/2;//中間斜線長度，等差級數總和計算
        int number_of_dotted_line=(x2+y2)-(x1+y1);  //介於兩平行實線的虛線總數
        sum=number_of_first_level+number_of_final_level+number_of_first_to_final_level+number_of_dotted_line;
        cout<<"Case "<<i+1<<": "<<sum<<endl;;
    }
}
