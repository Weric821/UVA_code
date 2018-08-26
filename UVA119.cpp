#include<iostream>
#include<sstream>
#include<map>
using namespace std;

int main()
{
    int number_of_people=0;
    int flag=0;
    while(cin>>number_of_people)
    {
        if(flag!=0)
            cout<<endl;

        string name_input;
        getline(cin,name_input);    //吃換行
        getline(cin,name_input);

        stringstream ss;
        ss<<name_input;

        map<string,int> mp;         //記錄姓名，以及該人賺賠多少
        map<string,int>::iterator iter;
        string *name_arr=new string[number_of_people];  //用來記錄輸入名字的順序，以便輸出按照順序
        for(int i=0;i<number_of_people;i++)
        {
            string tmp;
            ss>>tmp;

            mp[tmp]=0;              //初始值為0
            name_arr[i]=tmp;
        }

        string name;                //發送方姓名
        int gift_money=0;           //發送禮物總金額
        int number=0;               //發給的人數
        for(int i=0;i<number_of_people;i++)
        {
            cin>>name>>gift_money>>number;

            int given=0;    //接收方獲得多少價值的禮物

            if(number!=0)
                given=gift_money/number;    //總價格除以人數

            mp[name]-=(given*number);   //發送方花掉經費

            string tmp2;
            for(int j=0;j<number;j++)
            {
                cin>>tmp2;
                mp[tmp2]+=given;    //接收方獲得禮物價值
            }
        }

        for(int i=0;i<number_of_people;i++)
            cout<<name_arr[i]<<" "<<mp[name_arr[i]]<<endl;

        flag=1;
    }
}
