#include<iostream>
using namespace std;
int main()
{
    int input=0;
    while(cin>>input&&(input!=0))
    {
        string st_input;
        int arr[6]={1,2,3,4,5,6};   //代表骰子目前點數情形
        while(input--)
        {
            cin>>st_input;
            int reg=0;
            switch(st_input[0])     //根據不同的case去改變骰子點數情形
            {
                case 'n':
                    reg=arr[0];
                    arr[0]=arr[4];
                    arr[4]=arr[5];
                    arr[5]=arr[1];
                    arr[1]=reg;
                    break;
                case 'e':
                    reg=arr[0];
                    arr[0]=arr[2];
                    arr[2]=arr[5];
                    arr[5]=arr[3];
                    arr[3]=reg;
                    break;
                case 'w':
                    reg=arr[0];
                    arr[0]=arr[3];
                    arr[3]=arr[5];
                    arr[5]=arr[2];
                    arr[2]=reg;
                    break;
                case 's':
                    reg=arr[0];
                    arr[0]=arr[1];
                    arr[1]=arr[5];
                    arr[5]=arr[4];
                    arr[4]=reg;
                    break;
            }
        }
        cout<<arr[0]<<endl;
    }
}
