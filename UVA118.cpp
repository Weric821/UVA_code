#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
string NS="NESW";
int main()
{
    int edge[2]={0};
    cin>>edge[0]>>edge[1];  //輸入邊界
    int start[2]={0};
    char direction=NULL;
    multimap <int,int> mp;  //用map記下超出邊界時形成的牆
    multimap <int,int>::iterator iter;
    while(cin>>start[0]>>start[1]>>direction)
    {
        getchar();
        string input_arr;
        getline(cin,input_arr);
        int current_direction=NS.find(direction);   //目前方向
        int out_flag=0;
        for(int i=0;i<input_arr.size();i++)
        {
            if(input_arr[i]=='F')
            {
                switch (direction)
                {
                case 'N':
                    start[1]++;
                    break;
                case 'S':
                    start[1]--;
                    break;
                case 'E':
                    start[0]++;
                    break;
                case 'W':
                    start[0]--;
                    break;
                }
                for(iter=mp.begin();iter!=mp.end();iter++)   //如果過往前面有形成牆壁，則退回原位
                {
                    if(iter->first==start[0]&&iter->second==start[1])
                    {
                        switch (direction)
                        {
                        case 'N':
                            start[1]--;
                            break;
                        case 'S':
                            start[1]++;
                            break;
                        case 'E':
                            start[0]--;
                            break;
                        case 'W':
                            start[0]++;
                            break;
                        }
                        break;
                    }
                }
            }
            else if(input_arr[i]=='R')
            {
                current_direction++;
                direction=NS[current_direction%4];
            }
            else if(input_arr[i]=='L')
            {
                current_direction--;
                if(current_direction<0)     //如果為負數則+4，在string NS為同一位子
                {
                    current_direction+=4;
                }
                direction=NS[current_direction%4];
            }
            if(start[0]>edge[0]||start[1]>edge[1]||start[0]<0||start[1]<0)  //出界out_flag改1，並將形成的牆丟入map
            {
                out_flag=1;
                mp.insert(make_pair(start[0],start[1]));
                switch (direction)          //回到出界前的點然後輸出
                        {
                        case 'N':
                            start[1]--;
                            break;
                        case 'S':
                            start[1]++;
                            break;
                        case 'E':
                            start[0]--;
                            break;
                        case 'W':
                            start[0]++;
                            break;
                        }
                break;
            }
        }
        cout<<start[0]<<" "<<start[1]<<" "<<direction;
        if(out_flag==1)
        {
            cout<<" LOST";
        }
        cout<<endl;
    }
}
