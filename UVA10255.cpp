//(UVA_10255)Knight's_Tour
#include<iostream>
#include<stack>
using namespace std;

int **arr;
int direction[16]={2,1,1,2,-2,1,-1,2,-2,-1,-1,-2,2,-1,1,-2};
int length;
int trace(int x,int y,int counter)
{
    int value=0;
    counter++;
    arr[x][y]=counter;

    //最後一格，則return代表有Knight’s Path Tour
    if(counter==length*length)
    {
        return 1;
    }


    for(int i=0;i<16;i+=2)
    {
        //檢測八個方向，分別recursive，若有解則回傳1
        if(arr[x+direction[i]][y+direction[i+1]]==0)
            value=trace(x+direction[i],y+direction[i+1],counter);

        if(value==1)
            return 1;
    }
    //若最終八個方向都沒有解且並不是最後一格則清空此格並且回傳
    arr[x][y]=0;
    return -1;
}
int main()
{
    int start_x,start_y=0;
    while(cin>>length>>start_x>>start_y)
    {
        //多建立2列邊框
        arr=new int* [length+4];
        int CONTROL=0;
        int Circuit=0;

        for(int i=0;i<length+4;i++)
        {
            arr[i]=new int [length+4];
            for(int j=0;j<length+4;j++)
            {
                if(i==0||i==1||j==0||j==1||i==length+2||i==length+3||j==length+2||j==length+3)
                    arr[i][j]=-1;
                else
                    arr[i][j]=0;
            }
        }

        CONTROL=trace(start_x+1,start_y+1,0);

        //判斷是否為Knight’s Circuit Tour
        for(int i=0;i<16;i+=2)
        {
            if(arr[start_x+1+direction[i]][start_y+1+direction[i+1]]==length*length)
            {
                Circuit=1;
                break;
            }
        }
        //output
        if(CONTROL==1&&Circuit==1)
        {
            for(int i=2;i<length+2;i++)
            {
                for(int j=2;j<length+2;j++)
                {
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else
            cout<<"No Circuit Tour."<<endl;


        delete[] arr;
    }
}
