#include<iostream>
#include<cmath>					//或是<algorithm>
using namespace std;
int main()
{
    long long int mysolider=0;
    long long int enemy=0;
    while(cin>>mysolider)
    {
        cin>>enemy;
        cout<<abs(mysolider-enemy)<<endl;
    }
}
