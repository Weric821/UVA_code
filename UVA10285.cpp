//UVa 10285
#include<iostream>
using namespace std;

int **arr;      //存放輸入數字
int **ans;      //存放輸出結果，即在特定座標中能延伸的最長長度
int **used;     //記錄此座標是否已經遞迴計算過最長長度，若有則直接查表利用，不再多做一次遞迴運算
int Row=0,Col=0;

int trace(int x,int y)
{
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            if(i+j==-1||i+j==1)   //上下左右四個方向
            {
                if(arr[x][y]!=0 && arr[x+i][y+j]!=0 && arr[x][y]>arr[x+i][y+j])
                {
                    if(used[x+i][y+j]==1)   //若之前已經計算過座標(x+i,y+j)的最長長度，則不需再重算，直接查表
                        ans[x][y]=max(ans[x][y],ans[x+i][y+j]+1);   //四個方向中最長的長度+1即為(x,y)的長度
                    else                    //若尚未計算過則用遞迴求出其最大長度
                        ans[x][y]=max(ans[x][y],trace(x+i,y+j)+1);
                }
            }

    used[x][y]=1;           //更新完長度，將used array改為1，成為已知資訊，若再次遇到不需重新計算
    return ans[x][y];       //回傳以(x,y)座標為頭(串列中最大數字)，最長長度
}
int main()
{
    int case_number=0;
    cin>>case_number;

    while(case_number--)
    {
        string name;
        cin>>name>>Row>>Col;

        arr=new int *[Row+2];
        ans=new int *[Row+2];
        used=new int *[Row+2];
        int MIN[3]={99999};     //記錄初始值，即最小值為最一開始的點，最長長度為1
        for(int i=0;i<Row+2;i++)
        {
            arr[i]=new int [Col+2];
            ans[i]=new int [Col+2];
            used[i]=new int [Col+2];
            for(int j=0;j<Col+2;j++)
            {
                if(i==0||j==0||i==Row+1||j==Col+1)  //周圍為牆壁，避免四周存取到不應該存取的位置
                    arr[i][j]=0;
                else
                {
                    cin>>arr[i][j];
                    if(MIN[0]>arr[i][j])
                    {
                        MIN[0]=arr[i][j];
                        MIN[1]=i;
                        MIN[2]=j;
                    }
                }
                ans[i][j]=1;
                used[i][j]=0;
            }
        }

        used[MIN[1]][MIN[2]]=1; //將最小值的最長長度為1，故直接將used改為1成為可使用資訊，為遞迴的初始值

        int MAX=0;
        for(int i=0 ; i<Row+2 ; i++)
            for(int j=0 ; j<Col+2 ;j++)
                MAX=max(trace(i,j),MAX);

        cout<<name<<": "<<MAX<<endl;
    }
}
