#include<iostream>
using namespace std;

int main()
{
    int input_case=0;
    cin>>input_case;
    while(input_case--)
    {
        int day=0;  //總測驗天數
        int number_of_political_party=0;    //政黨總數
        cin>>day;
        cin>>number_of_political_party;

        int arr_day[day]={0};
        int political_party[number_of_political_party]={0};

        for(int i=0;i<number_of_political_party;i++)
        {
            cin>>political_party[i];
        }

        for(int i=0;i<number_of_political_party;i++)
        {
            for(int j=0;j<day;j++)
            {
                if(j%7!=5&&j%7!=6)  //判斷非星期五及星期六
                {
                    if(j%political_party[i]==political_party[i]-1)
                    {
                        arr_day[j]=1;
                    }
                }
            }
        }
        int output=0;
        for(int i=0;i<day;i++)
        {
            output+=arr_day[i];
        }
        cout<<output<<endl;
    }
}
