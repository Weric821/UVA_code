#include<iostream>
#include<sstream>
#include<stdio.h>
using namespace std;

int main()
{
    int input_case=0;
    cin>>input_case;            //幾筆矩陣
    for(int input_count=0;input_count<input_case;input_count++)
    {
        char N[10]={NULL};
        getchar();              //吃cin接getline中間的enter
        cin.getline(N,10);

        stringstream ss(N);
        int n=0;
        ss>>N[0]>>N[1]>>n;      //將"N ="除去，留下重要資訊n

        long long int **matrix=new long long int*[n];
        for(int i=0;i<n;i++)
        {
            matrix[i]=new long long int [n];
            for(int j=0;j<n;j++)
            {
                cin>>matrix[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]<0)          //如果有元素<0，則非此定義中的Symmetric
                {
                    i=n;
                    break;
                }
                else if(matrix[i][j]!=matrix[n-i-1][n-j-1])   //非對稱
                {
                    i=n;
                    break;
                }
                if(i==n-1&&j==n-1)          //成功走到[n-1,n-1]，即是矩陣最後一個數字，對稱
                {
                    cout<<"Test #"<<(input_count+1)<<": Symmetric."<<endl;
                    break;
                }
            }
            if(i==n)        //i==n代表上面for內的判斷式已經判斷出非對稱，則跳出
            {
                cout<<"Test #"<<(input_count+1)<<": Non-Symmetric."<<endl;
                break;
            }
        }
        delete[] matrix;
    }
}
