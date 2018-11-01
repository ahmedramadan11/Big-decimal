#ifndef BIGDECIMAL_H
#define BIGDECIMAL_H
#include<cstring>
#include<iostream>
using namespace std;

class BigDecimal
{
    public:
        BigDecimal();//default constructor
        BigDecimal operator+ (BigDecimal s2 );//prototype for operator +
        BigDecimal operator- (BigDecimal s2 );//prototype for operator -
        friend ostream& operator<<(ostream &out, BigDecimal& val);//operator cout
        friend istream& operator >> (istream& in, BigDecimal & big);//operator cin
        friend bool check_negative_for_plus(BigDecimal &num1,BigDecimal &num2);//function to check if number is negative for plus
        friend bool check_negative_for_minus(BigDecimal &num1,BigDecimal &num2);//function to check if number is negative for minus
        friend void  string_absolute(string &absolute);//to make the number positive
    private:
    string num;
};

#endif // BIGDECIMAL_H
