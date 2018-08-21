//move a onto b : 把a和b上方的東西都放回原位，且將a放到b上面
//move a over b : 把a上面的東西放回原位，把a放到b所在的位置上
//pile a onto b : 把b上的東西放回原位，把a和a上方的東西都放到b上面
//pile a over b : 把a和a上方的東西放到b所在的位置上
//quit : 指令輸入結束
#include<iostream>
#include<sstream>
using namespace std;
int **arr;
int n=0;

//node：記錄該block在矩陣中的位置，x表列，y表行
struct node
{
    int x=0;
    int y=0;
};

//Find_X：找出目標block所在的位置，並回傳座標(node)
node *Find_X(int target)
{
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=arr[i][0];j++)
        {
            if(arr[i][j]==target)
            {
                node *Position=new node;
                Position->x=i;
                Position->y=j;
                return Position;
            }
        }
    }
}

//清除某個座標上的數字，並且將第一行的使用數字減一
void Clean(node *target_position)
{
    arr[target_position->x][target_position->y]=-1;
    arr[target_position->x][0]--;
}

//將a座標上的block挪移置b列
void Put_a_to_b(node *a_position,int b)
{
    if(a_position->x!=b)    //若a本來就在b列上，則不動
    {
        arr[b][arr[b][0]+1]=arr[a_position->x][a_position->y];
        arr[b][0]++;
        Clean(a_position);
    }
}

void move_a_onto_b(int a,int b)
{
    node *a_Position=new node;
    node *b_Position=new node;
    a_Position=Find_X(a);   //記錄a座標
    b_Position=Find_X(b);   //記錄b座標

    //將a block上面的block回復原位
    for(int j=a_Position->y+1;arr[a_Position->x][j]!=-1;j++)
    {
        node *tmp=new node;
        tmp->x=a_Position->x;
        tmp->y=j;
        Put_a_to_b(tmp,arr[a_Position->x][j]);
    }

    //將b block上面的block回復原位
    for(int j=b_Position->y+1;arr[b_Position->x][j]!=-1;j++)
    {
        node *tmp=new node;
        tmp->x=b_Position->x;
        tmp->y=j;
        Put_a_to_b(tmp,arr[b_Position->x][j]);
    }

    //將a block 移到 b block 所在列上面
    Put_a_to_b(a_Position,b_Position->x);
}
void move_a_over_b(int a,int b)
{
    node *a_Position=new node;
    node *b_Position=new node;
    a_Position=Find_X(a);   //記錄a座標
    b_Position=Find_X(b);   //記錄b座標

    //將a block上面的block回復原位
    for(int j=a_Position->y+1;arr[a_Position->x][j]!=-1;j++)
    {
        node *tmp=new node;
        tmp->x=a_Position->x;
        tmp->y=j;
        Put_a_to_b(tmp,arr[a_Position->x][j]);
    }

    //將a block 移到 b block 所在列上面
    Put_a_to_b(a_Position,b_Position->x);
}
void pile_a_onto_b(int a,int b)
{
    node *a_Position=new node;
    node *b_Position=new node;
    a_Position=Find_X(a);   //記錄a座標
    b_Position=Find_X(b);   //記錄b座標


    //將b block上面的block回復原位
    for(int j=b_Position->y+1;arr[b_Position->x][j]!=-1;j++)
    {
        node *tmp=new node;
        tmp->x=b_Position->x;
        tmp->y=j;
        Put_a_to_b(tmp,arr[b_Position->x][j]);
    }

    //將a block 與a block 上面的東西移到b block所在列上面
    for(int j=a_Position->y;arr[a_Position->x][j]!=-1;j++)
    {
        node *tmp=new node;
        tmp->x=a_Position->x;
        tmp->y=j;
        Put_a_to_b(tmp,b_Position->x);
    }

}
void pile_a_over_b(int a,int b)
{
    node *a_Position=new node;
    node *b_Position=new node;
    a_Position=Find_X(a);   //記錄a座標
    b_Position=Find_X(b);   //記錄b座標

    //將a block 與a block 上面的東西移到b block所在列上面
    for(int j=a_Position->y;arr[a_Position->x][j]!=-1;j++)
    {
        node *tmp=new node;
        tmp->x=a_Position->x;
        tmp->y=j;
        Put_a_to_b(tmp,b_Position->x);
    }
}
int main()
{

    cin>>n;
    //開二維陣列儲存block存放情形
    //第一行表示該位置存放東西個數，以加快找到最尾端
    arr=new int *[n];
    for(int i=0;i<n;i++)
    {
        //多開兩行，第一行存放目前此列存放block個數
        //最後一行為array邊界
        arr[i]=new int [n+2];
        for(int j=0;j<n+2;j++)
        {
            if(j==0)
                arr[i][j]=1;
            else if(j==1)
                arr[i][j]=i;
            else
                arr[i][j]=-1;
        }
    }

    string ins_input;
    getline(cin,ins_input); //吃換行字符

    while(getline(cin,ins_input) && ins_input!="quit")
    {
        stringstream ss;
        ss<<ins_input;

        string ins1,ins2;
        int num1,num2;
        ss>>ins1>>num1>>ins2>>num2;

        if(ins1=="move")
        {
            if(ins2=="onto")
                move_a_onto_b(num1,num2);
            else
                move_a_over_b(num1,num2);
        }
        else
        {
            if(ins2=="onto")
                pile_a_onto_b(num1,num2);
            else
                pile_a_over_b(num1,num2);
        }
    }

    //輸出
    for(int i=0;i<n;i++)
    {
        cout<<i<<":";
        for(int j=1;j<n+2;j++)
        {
            if(arr[i][j]==-1)
                break;
            cout<<" "<<arr[i][j];
        }
        cout<<endl;
    }
}
