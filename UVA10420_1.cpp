//(資料內沒有同筆資料版本)
#include<iostream>
#include<map>

using namespace std;
int main()
{
    int number_cases;
    cin>>number_cases;

    map<string,int> ma;
    map<string,int>::iterator iter;

    string country;
    char name[75];
    while(number_cases--)
    {


        cin>>country;
        ma[country]++;
        cin.getline(name,75);
    }


    for(iter=ma.begin();iter!=ma.end();iter++)
    {
        cout<<iter->first<<" "<<iter->second<<endl;
    }
}
