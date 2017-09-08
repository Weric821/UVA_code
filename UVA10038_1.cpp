#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int case_number=0;
    int *case_arr=0;
    int *case_length=0;
    while(cin>>case_number)
    {
        case_arr=new int[case_number];
        case_length=new int[case_number-1];
        for(int i=0;i<case_number;i++)
        {
            cin>>case_arr[i];
        }
        for(int i=0;i<case_number-1;i++)
        {
            case_length[i]=abs(case_arr[i]-case_arr[i+1]);
        }
        sort(case_length,case_length+case_number-1);
        for(int i=0;i<case_number-1;i++)
        {
            if(case_length[i]!=i+1)
            {
                cout<<"Not jolly"<<endl;
                break;
            }
            if(case_length[i]==case_number-1)
            {
                cout<<"Jolly"<<endl;
                break;
            }
        }
    }
}
