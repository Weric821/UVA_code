#include<iostream>
#include<stdio.h>
#include<sstream>
#include<queue>
using namespace std;
int main()
{
    int answer,student_answer=0;
    int Run_case=1;
    while(cin>>answer&&(answer!=0))
    {
        int flag=0;
        getchar();
        queue<string> sk_answer;        //存標準答案每列之string
        queue<string> sk2_answer;       //存標準答案每列之string*2
        string answer_st;
        for(int i=0;i<answer;i++)
        {
            getline(cin,answer_st);     //將每列存成string
            sk_answer.push(answer_st);  //將每列輸入存在queue
            sk2_answer.push(answer_st);
        }
        cin>>student_answer;
        queue<string> sk_student_answer;    //存學生答案每列之string
        queue<string> sk2_student_answer;   //存學生答案每列之string*2
        string student_answer_st;
        getchar();
        for(int i=0;i<student_answer;i++)
        {
            getline(cin,student_answer_st); //將每列存成string
            sk_student_answer.push(student_answer_st);  //將每列輸入存在queue
            sk2_student_answer.push(student_answer_st);
        }
        stringstream ss_answer_number;      //將數字存入stringstream，後面一起做比較
        stringstream ss_student_answer_number;
        while(1)        //將標準答案裡所有的數字存入stringstream
        {
            string answer_number;
            if(sk_answer.empty())
            {
                break;
            }
            else
            {
                answer_number=sk_answer.front();
                sk_answer.pop();
                for(int i=0;i<answer_number.size();i++)
                {
                    if(answer_number[i]<='9'&&answer_number[i]>='0')
                    {
                        ss_answer_number<<answer_number[i];
                    }
                }
            }
        }
        while(1)        //將學生答案裡所有的數字存入stringstream
        {
            string student_answer_number;
            if(sk_student_answer.empty())
            {
                break;
            }
            else
            {
                student_answer_number=sk_student_answer.front();
                sk_student_answer.pop();
                for(int i=0;i<student_answer_number.size();i++)
                {
                    if(student_answer_number[i]<='9'&&student_answer_number[i]>='0')
                    {
                        ss_student_answer_number<<student_answer_number[i];
                    }
                }
            }
        }
        //---------------比較數字順序是否一樣
        string number1;
        string number2;
        ss_answer_number>>number1;
        ss_student_answer_number>>number2;
        if(number1.size()!=number2.size())
        {
            flag=2;
        }
        else
        {
            for(int i=0;i<number1.size();i++)
            {
                if(number1[i]!=number2[i])
                {
                    flag=2;      //若數字比較就已經不同了，必定為"Wrong Answer"
                    break;
                }
            }
        }
        //---------------
        if(flag==2)
        {
            cout<<"Run #"<<Run_case<<": Wrong Answer"<<endl;
        }
        else
        {
            while(1)                                                //利用前面保存第二筆queue
            {
                if(sk2_answer.empty()||sk2_student_answer.empty())  //當有queue為空，則while需break
                {
                    if(!sk2_answer.empty()||!sk2_student_answer.empty())    //當有一個queue沒了另一個還有
                    {                                                       //表示兩個answer的size不同
                        cout<<"Run #"<<Run_case<<": Presentation Error"<<endl;
                        flag=1;
                    }
                    break;
                }
                else
                {
                    if(sk2_answer.front()!=sk2_student_answer.front())      //將queue內的元素做比較
                    {                                                       //不同則為"Presentation Error"
                        cout<<"Run #"<<Run_case<<": Presentation Error"<<endl;
                        flag=1;
                        break;
                    }
                    sk2_answer.pop();
                    sk2_student_answer.pop();
                }
            }
            if(flag==0)     //若非"Wrong Answer"與"Presentation Error"，則為"Accepted"
            {
                cout<<"Run #"<<Run_case<<": Accepted"<<endl;
            }
        }
        Run_case++;
    }
}
