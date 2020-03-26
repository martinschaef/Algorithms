#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Group {
public:    
    virtual string to_string() const = 0;
    virtual double norm() const = 0;
    virtual ~Group(){ cout << "Group element destroyed." << endl;}
}
class Real : public Group {
protected:    
    // data memeber
    double a;
public:    
    // constructor
    Real(double x): a{x} {}
    // overloaded members
    double norm() const {
        return a;
    }
    string to_string() const {
        ostringstream output;
        output << a;
        return output.str();
    }
};
class Complex : public Real {
protected:
    double b;
public:
    Complex(double x, double y): Real(x), b{y} {}
    // overloaded members
    double norm() const {
        return sqrt(a*a+b*b);
    }
    string to_string() const {
        ostringstream output;
        output << a << (b > 0 ? "+" : "") << b << "i";
        return output.str();
    }
};
class Polynomial : public Complex {
    friend ostream& operator<<(ostream&, const Polynomial&);
protected:
    double c;
public:
    // derived class constructor that uses base class constructor
    Polynomial(double x, double y, double z): Complex(x, y), c{z} {}
    // overloaded members
    double norm() const {
        return sqrt(a*a+b*b+c*c);
    }
    string to_string() const {
        ostringstream output;
        if (a != 0)
            output << a << "x^2";
        if (b != 0)
            output << (b > 0 ? "+" : "") << b << "x";
        if (c != 0)
            output << (c > 0 ? "+" : "") << c;
        return output.str();
    }
};
class Vector : public Group {
    vector<double> v;
public:
    Vector(double a, double b, double c){
        v.push_back(a);
        v.push_back(b); 
        v.push_back(c); 
    }
    ~Vector() {
        cout << "Vector destroyed." << endl;
        v.clear();
    }
    // overloaded members
    double norm() const {
        double sum = 0.0;
        for(auto e : v)
            sum += e*e;
        return sqrt(sum);
    }
    string to_string() const {
        ostringstream output;
        output << "[";
        for(auto e : v)
            output << e << " ";  
        long pos = output.tellp();
        output.seekp(pos-1);
        output << "]";
        return output.str();
    }
}
Test Driver
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    vector<Group*> elements;
    
    elements.push_back(new Real{3});
    elements.push_back(new Complex{3,4});
    elements.push_back(new Polynomial{1,2,3});
    elements.push_back(new Vector{1,2,3});
    
    for(auto e : elements){
        cout << "|"<< e->to_string() << "| = "<< e->norm() << endl;
    }
    
    for(auto e : elements)
        delete e;
    
    return 0;
}