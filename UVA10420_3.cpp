//(資料內有同筆資料版本，要除去同資料干擾結果)	版本二
#include<iostream>
#include<map>
#include<set>
#include<sstream>

using namespace std;
int main()
{
    int number_cases;
    char ws=NULL;			//用於接收enter，以防等等getline吃到第一個cin的enter

    cin>>number_cases>>ws;		//ws吃enter

    set<string> st;			//用set除去重複資料
    set<string>::iterator s_iter;

    char total_string[75];
    while(number_cases--)
    {
        cin.getline(total_string,75);
        st.insert(total_string);
    }


    map<string,int> mp;			//用map統計票數
    string reg;
    stringstream ss;
    for(s_iter=st.begin();s_iter!=st.end();s_iter++)
    {

        ss.str("");	//清空stringstream
        ss.clear();	//清空stringstream

	      ss<<*s_iter;
        ss>>reg;
        mp[reg]++;
    }

    map<string,int>::iterator m_iter;

    for(m_iter=mp.begin();m_iter!=mp.end();m_iter++)
    {
        cout<<m_iter->first<<" "<<m_iter->second<<endl;
    }
}
