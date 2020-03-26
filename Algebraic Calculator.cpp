class Real {
    friend ostream& operator<<(ostream&, const Real&);
protected:    
    // data memeber
    double a;
public:    
    // constructor
    Real(double x): a{x} {}
    // overloaded operation
    Real operator/(Real& x) const {
        double r = a / x.a;
        return Real(r);
    }
};

iostream& operator<<(ostream& output, const Real& obj) {
    output << obj.a;
    return output;
}
Solution: class Complex
class Complex : public Real {
    friend ostream& operator<<(ostream&, const Complex&);
protected:
    double b;
public:
    Complex(double x, double y): Real(x), b{y} {}
    Complex operator*(Complex& num) const {
        double re = a * num.a - b*num.b;
        double im = b * num.a + a*num.b;
        return Complex(re, im);
    }
};

ostream& operator<<(ostream& output, const Complex& obj) {
    output << obj.a << (obj.b > 0 ? "+" : "") << obj.b << "i";
    return output;
}
Solution: class Polynomial
class Polynomial : public Complex {
    friend ostream& operator<<(ostream&, const Polynomial&);
protected:
    double c;
public:
    // derived class constructor that uses base class constructor
    Polynomial(double x, double y, double z): Complex(x, y), c{z} {}
    // overloaded operation
    Polynomial operator+(Polynomial& num) const {
        double c1 = a + num.a;
        double c2 = b + num.b;
        double c3 = c + num.c;
        return Polynomial(c1, c2, c3);
    }
};

iostream& operator<<(ostream& output, const Polynomial& obj) {
    if (obj.a != 0)
        output << obj.a << "x^2";
    if (obj.b != 0)
        output << (obj.b > 0 ? "+" : "") << obj.b << "x";
    if (obj.c != 0)
        output << (obj.c > 0 ? "+" : "") << obj.c;
    return output;
}
Test Driver
#include <iostream>
using namespace std;

int main() 
{
    Real a{30.0};
    Real b{20.0};  
    // next line shows: 30/20 = 1.5
    cout << a << " / " << b << " = " << (a/b) << endl;
                
    Complex d{3.0, 1.0};  // 3 + i
    Complex e{2.0, -2.0}; // 2 - 2i
    // next line shows: (3+1i)*(2-2i) = (8-4i)
    cout << "(" << d << ") * (" << e << ") = " << (d*e) << endl;
        
    Polynomial h{2,1,1};    // 2x^2+1x+1
    Polynomial i{1,-1,0};   // 1x^2-1x
    // next line shows: (2x^2+1x+1) + (1x^2-1x) = (3x^2+1)
    cout << "(" << h << ") + (" << i << ") = " << (h+i) << endl;     
}