#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

void Probability(int n,float p,int i)
{
    float reg=0;
    float reg2=0;
    reg=pow((1-p),(i-1));
    reg2=1-pow((1-p),n);
    printf("%.4f\n",(reg*p)/reg2);
}
int main()
{
    int case_input=0;
    cin>>case_input;
    while(case_input--)
    {
        int player,winer=0;
        float p=0;
        cin>>player>>p>>winer;
        Probability(player,p,winer);
    }
}
