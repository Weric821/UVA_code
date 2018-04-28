#include<iostream>
using namespace std;
int check_max_edge(int row,int col,char** MAP_arr)  //輸入中心點座標以及地圖
{
    int edge=1;             //edge為中心點向外擴散幾格，並不直接等於邊長
    int condition=1;        //用來判斷是否跳出while及for迴圈

    while(condition)
    {
        if(row-edge<0||col-edge<0)  //當擴散超出邊界，跳出while
        {
            condition=0;
        }
        for(int i=row-edge;(i<row+edge+1)&&(condition!=0);i++)
        {
            for(int j=col-edge;j<col+edge+1;j++)
            {
                if(MAP_arr[i][j]!=MAP_arr[row][col])
                {
                    condition=0;
                    break;
                }
            }
        }
        edge+=condition;
    }
    edge--;     //因為edge起始值為1，當while挑出時代表上個狀態的檢測不符合，故-1回上一狀態
    if(edge==0)
    {
        return 1;
    }
    else
    {
        return 2*edge+1;    //兩倍擴散值+中心點
    }
}
int main()
{
    int total_case=0;
    cin>>total_case;
    while(total_case--)
    {
        int M,N,Q=0;
        cin>>M>>N>>Q;
        char** MAP=new char *[M];
        for(int i=0;i<M;i++)
        {
            MAP[i]=new char [N];
        }
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>MAP[i][j];
            }
        }
        cout<<M<<" "<<N<<" "<<Q<<endl;
        for(int i=0;i<Q;i++)
        {
            int center[2]={0};
            cin>>center[0]>>center[1];
            int output=0;
            output=check_max_edge(center[0],center[1],MAP);
            cout<<output<<endl;
        }
        delete[] MAP;
    }
}
