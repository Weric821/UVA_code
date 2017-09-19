#include<iostream>
#include<map>
#include<set>
using namespace std;

long long int test_case_input=0;    //輸入之十進位數字，因void會用到設全域
int arr_ink[36]={NULL};             //為每個字需要的墨水，void會用到設全域
void calculate_min_Base(long long int number)   //計算墨水數並找出最少花費
{
    set <int> chose_min_number;     //用set找出最低花費，用於iter走訪用
    map <int,int> mp;               //用map存每個進位所耗費的墨水數
    map <int,int>::iterator iter;
    for(int i=2;i<37;i++)
    {
        int sum=0;
        while(number>=1)            //轉n進位，並隨時將墨水數加總到sum
        {
            sum+=arr_ink[number%i];
            number/=i;
        }
        mp[i]=sum;
        chose_min_number.insert(sum);
        number=test_case_input;     //回復原本輸入的數字
    }

    cout<<"Cheapest base(s) for number "<<test_case_input<<":";
    for(iter=mp.begin();iter!=mp.end();iter++)
    {
        if(iter->second==*chose_min_number.begin()) //當耗費等於set的頭筆資料，即為最小墨水耗費，指標指向set.begin()的位址，顯示出他所存的值
        {
            cout<<" "<<iter->first;
        }
    }
    cout<<endl;
}
int main()
{
    int total_case=0;
    cin>>total_case;
    for(int i=0;i<total_case;i++)
    {
        for(int i=0;i<36;i++)
        {
            cin>>arr_ink[i];
        }

        int amount_of_test_case=0;
        cin>>amount_of_test_case;
        cout<<"Case "<<i+1<<":"<<endl;
        while(amount_of_test_case--)
        {
            cin>>test_case_input;
            calculate_min_Base(test_case_input);
        }
        cout<<endl;
    }
}
