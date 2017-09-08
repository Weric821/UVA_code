#include<iostream>
using namespace std;
int main()
{
    long long int people_number=0;
    long long int day=0;
    while(cin>>people_number>>day)
    {
        for(int i=1;;i++)
        {
            if(((people_number+i)*(i+1-people_number))/2>=day)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
}
