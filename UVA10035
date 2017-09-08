#include<iostream>
using namespace std;
int main()
{
    long long int inputnumber1=1;
    long long int inputnumber2=1;
    int carryflag=0;
    int cf=0;
    while(1)
    {
        cin>>inputnumber1>>inputnumber2;

        if(inputnumber1==0&&inputnumber2==0)
        {
            break;
        }
        while(1)
        {
            if((inputnumber1%10)+(inputnumber2%10)+cf>9)        //cf即為進位
            {
                carryflag++;
                inputnumber1/=10;
                inputnumber2/=10;
                cf=1;          //進位

            }
            else
            {
                inputnumber1/=10;
                inputnumber2/=10;
                cf=0;          //沒進位
            }
            if(inputnumber1==0&&inputnumber2==0)
            {
                break;
            }
        }

        //output
        if(carryflag==0)
        {
            cout<<"No carry operation."<<endl;
        }
        else if(carryflag==1)
        {
            cout<<carryflag<<" "<<"carry operation."<<endl;
        }
        else
        {
            cout<<carryflag<<" "<<"carry operations."<<endl;
        }

        //reset
        carryflag=0;
        inputnumber1=1;
        inputnumber2=1;
        cf=0;
    }
}
