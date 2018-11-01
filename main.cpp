#include <iostream>
#include "BigDecimal.h"
using namespace std;

int main()
{
    BigDecimal num1,num2,num3;
    cout<<"enter num1:   ";
    cin>>num1;//to take the number
    cout<<"enter num2:   ";
    cin>>num2;
    cout<<"num1 + num2:  ";
    if(check_negative_for_plus(num1,num2))//check if number is negative

        num3=num1+num2;
    else
        num3=num1-num2;
    cout<<num3;//print sum
    cout<<endl;


    cout<<"enter num1:   ";
    cin>>num1;
    cout<<"enter num2:   ";
    cin>>num2;
    cout<<"num1 - num2:  ";
    if(check_negative_for_minus(num1,num2))//check if number is negative
        num3=num1+num2;
    else
        num3=num1-num2;
    cout<<num3;
    return 0;
}
