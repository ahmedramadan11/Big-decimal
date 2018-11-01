#include "BigDecimal.h"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
BigDecimal s3;
BigDecimal::BigDecimal()
{

}
void string_absolute(string &absolute)//to remove negative
{
    string temp="";//to put full number with out negative
    for(int i=1; i<absolute.length(); i++)
    {
        if(absolute[0]=='-')//to ignore negative
            temp+=absolute[i];
    }
    if(absolute[0]=='-')//if the number donot have negative donot make any thing
        absolute=temp;
}
bool check_negative_for_plus(BigDecimal &num1,BigDecimal &num2)//to check negative number in plus
{
    //if the function return true so we will plus else we will minus
    s3.num="";//numbers sum
    if(num1.num[0]=='-'&&num2.num[0]=='-')//if the two numbers was negative add - to the sum
    {
        s3.num='-';
        return true;
    }
    if(num1.num[0]=='-'&&num2.num[0]!='-')//if the first number was negative and secong num was + swap
    {
        swap(num1,num2);
        return false;
    }
    if(num1.num[0]!='-'&&num2.num[0]=='-')//if the fist num was + and the second num was -
    {
        return false;
    }
    else//two num is + we will plus
        return true;
}
bool check_negative_for_minus(BigDecimal &num1,BigDecimal &num2)//to check negative number in minus
//if function return false we will minus if it return true we will plus
{
    s3.num="";//sum of two numbers
    if(num1.num[0]=='-'&&num2.num[0]=='-')//if the two numbers was negative swap and minus
    {
        swap(num1,num2);
        return false;
    }
    if(num1.num[0]=='-'&&num2.num[0]!='-')//first num - and second num + swape and minus
    {
        swap(num1,num2);
        s3.num='-';
        return true;
    }
    if(num1.num[0]!='-'&&num2.num[0]=='-')//first num + and second num  + we will plus
    {
        return true;
    }
    else//two num is + we will minus
        return false;
}
BigDecimal BigDecimal:: operator+ (BigDecimal s2)
{
    string_absolute(num);//remove negative if have for first num
    string_absolute(s2.num);//remove negative if have in secong num
    string num_for_append;//to make size same
    if (s2.num.length()>num.length())
    {
        for(int tryy=0; tryy<(s2.num.length()-num.length()); tryy++)
        {
            num_for_append.append("0");//to ad 0 in left of num
        }
        num=num_for_append.append(num);
    }
    if (num.length()>s2.num.length())
    {
        for(int tryy=0; tryy<(num.length()-s2.num.length()); tryy++)
        {
            num_for_append.append("0");//to ad 0 in left of num
        }
        s2.num=num_for_append.append(s2.num);
    }
    reverse(num.begin(),num.end());//to make unite at first ..for num 1
    reverse(s2.num.begin(),s2.num.end());//to make unite at first ..for num 2


    int num1_,num2_,sum_=0;//to take ascci for each degit
    for(int i=0; i<num.length(); i++)
    {
        num1_=num[i]-'0';//asci for num - asci of 0
        num2_=s2.num[i]-'0';
        sum_=sum_+num1_+num2_;//to add number + carrys
        if (sum_>=10&&(i+1)==num.length())//if we end the numbers size and tjier would be a carry we add 1 for sum
        {
            sum_-=10;
            s3.num+=char(sum_+48);
            s3.num=s3.num+'1';

        }
        else if (sum_<10)//if there is no carry we add numbers and put it into the sum
        {

            s3.num=s3.num+char(sum_+48);
            sum_=0;//return sum 0 again
        }

        else if(sum_>=10)//if thier is a carry we put 1 for the sum with will b eadd to next degit of the num
        {
            sum_-=10;
            s3.num=s3.num+char(sum_+48);
            sum_=1;
        }
    }
    reverse(s3.num.begin(),s3.num.end());//the put unites at last
    if(s3.num[s3.num.length()-1]=='-')//too put negative at first
    {
        s3.num[s3.num.length()-1]=' ';
        s3.num="-"+s3.num;
    }
    return s3;
}


BigDecimal BigDecimal:: operator- (BigDecimal s2)
{

    string_absolute(num);//to abs the first num
    string_absolute(s2.num);//to abs for seconf num
    if (num.length()<s2.num.length())//to make the bigger num always at first and add negative if it was smaller
    {
        swap(num,s2.num);
        s3.num+='-';
    }
   if(num.length()==s2.num.length()){//condition to know if length of number1 = number2
    for(int i=0;i<num.length();i++){
        if (num[i]<s2.num[i]){//condition to know who is bigger number1 or number2
            swap(num,s2.num);//swap num2 to num1
            s3.num+='-';
            break;
        }
    }}
    string num_for_append;
    if (s2.num.length()>num.length())
    {
        for(int tryy=0; tryy<(s2.num.length()-num.length()); tryy++)//to ad 0 in left of num
        {
            num_for_append.append("0");
        }
        num=num_for_append.append(num);
    }

    if (num.length()>s2.num.length())//to ad 0 in left of num
    {
        for(int tryy=0; tryy<(num.length()-s2.num.length()); tryy++)
        {
            num_for_append.append("0");
        }
        s2.num=num_for_append.append(s2.num);
    }

    reverse(num.begin(),num.end());//to make unite at first ..for num 1
    reverse(s2.num.begin(),s2.num.end());
    int num_,num2_,sum_=0;//to take ascci for each degit
    for(int i=0; i<num.length(); i++)
    {
        num_=num[i]-'0';//to take ascci for num mininus ascci of 0
        num2_=s2.num[i]-'0';
        sum_=num_-num2_;
        if (sum_<0&&(i+1)!=num.length())//if we need borrow we add for the seum 10 and -1 from the next degit
        {
            sum_+=10;
            num[i+1]--;
        }
        s3.num+=char(sum_+int('0'));
    }
    reverse(s3.num.begin(),s3.num.end());

    if(s3.num[s3.num.length()-1]=='-')//to put negative at first
    {
        s3.num[s3.num.length()-1]=' ';
        s3.num="-"+s3.num;
    }

    return s3;
}

istream& operator >> (istream& in, BigDecimal & big)//operator cin the number
{
    in>>big.num;
    return in;
}

ostream& operator<<(ostream &out, BigDecimal& val)//operator cout the number after plus or minus
{
    out << val.num;
    return out;
}

