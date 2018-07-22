#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int row,col=0;
    int case_number=1;
    while(cin>>row>>col&&(row!=0||col!=0))
    {
        char Map[row][col]={NULL};  //計炸彈位置
        int Map_number[row][col];   //計數字
        for(int i=0;i<row;i++)      //初始化
        {
            for(int j=0;j<col;j++)
            {
                Map_number[i][j]=0;
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>Map[i][j];
                if(Map[i][j]=='*')
                {
                    for(int p=i-1;(p<=i+1)&&(p!=row);p++)
                    {
                        if(p<0)
                        {
                            p++;
                        }
                        for(int q=j-1;(q<=j+1)&&(q!=col);q++)
                        {
                            if(q<0)
                            {
                                q++;
                            }
                            Map_number[p][q]++;
                        }
                    }
                }
            }
        }

        cout<<"Field #"<<case_number<<":"<<endl;
        case_number++;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(Map[i][j]=='*')
                {
                    cout<<Map[i][j];
                }
                else
                {
                    cout<<Map_number[i][j];
                }
            }
            cout<<endl;
        }
        cout<<endl;
        delete[] Map;
        delete[]Map_number;
    }
}
