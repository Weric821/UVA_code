#include<iostream>
#include<sstream>
using namespace std;
int check_prime(long long int number)   //判斷是否為質數，是回傳1，非回傳-1(Eratosthenes篩選求質數)
{
    if(number==2||number==3||number==5||number==7)
    {
        return 1;
    }
    else if(number%6==1||number%6==5)   //判斷是否為6n+-1，直接排除2與3的倍數
    {
        for(int i=1;i*i<number;i++)     //判斷是否為質數*質數，檢查到N的根號倍即可
        {                               //因為若是質數*質數，在比較小的那個質數就會檢查出來
            if(number==(6*i+1)||number==(6*i-1))    //當i小的時候，有可能就檢查到自己，為質數(當i小的時候：線性>指數)
            {
                break;
            }
            if(number%(6*i-1)==0||number%(6*i+1)==0)    //當我被一個比我小的質數整除，即非質數
            {
                return -1;
            }
        }
        return 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    long long int input=0;
    while(cin>>input)
    {
        string str_input;
        stringstream ss;            //運用stringstream將數字轉字串，方便倒置
        ss<<input;
        ss>>str_input;
        for(int i=0;i<str_input.size()/2;i++)
        {
            swap(str_input[i],str_input[str_input.size()-1-i]);
        }
        long long int input_Reversal=0;
        ss.clear();                 //清空stringstream以防影響結果
        ss<<str_input;
        ss>>input_Reversal;
        if(check_prime(input)==1)
        {
            if(check_prime(input_Reversal)==1&&input!=input_Reversal)
            {
                cout<<input<<" is emirp."<<endl;
            }
            else
            {
                cout<<input<<" is prime."<<endl;
            }
        }
        else
        {
            cout<<input<<" is not prime."<<endl;
        }
    }
}
