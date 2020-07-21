// https://www.hackerrank.com/challenges/overload-operators/problem

//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

Complex operator+(const Complex &first, const Complex &second){
    Complex res;
    int real = first.a + second.a;
    int imaginery = first.b + second.b;
    std::string str = std::to_string(real) + "+i" + std::to_string(imaginery);
    res.input(str);
    return res;
}

std::ostream &operator<<(std::ostream &oss, const Complex &rhs){
    oss << rhs.a << "+i" << rhs.b << std::endl;
    return oss;
}

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}