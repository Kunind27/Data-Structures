#include <iostream>
#include <cmath>

using namespace std;

class complex
{
    double real, im;
    
    public:
    
    //Default Constructor
    complex()
    {
        real = 0.0; im = 0.0;
    }
    
    //Constructor
    complex(double r, double i)
    {
        real = r; im = i;
    }
    
    // Copy Constructor
    complex(const complex &z)
    {
        real = z.real; im = z.im;
    }
    
    //Modulus
    double modulus()
    {
        return sqrt(real*real + im*im);
    }
    
    //Assignment Operator
    complex &operator=(const complex &z)
    {
        real = z.real; im = z.im;
        return *this;
    }
    
    //Addition
    complex operator+(const complex &z)
    {
        return complex(real+z.real, im+z.im);
    }
    
    //Subtraction
    complex operator-(const complex &z)
    {
        return complex(real-z.real, im-z.im);
    }
    
    //Constant Multiplication
    complex operator*(double a)
    {
        return complex(real*a, im*a);
    }
    
    //Multiplication
    complex operator*(const complex &z)
    {
        return complex(real*z.real - im*z.im, real*z.im + im*z.real);
    }
    
    //Constant Division
    complex operator/(double a)
    {
        return complex(real/a, im/a);
    }
    
    //Division
    complex operator/(const complex &z)
    {
        return complex(real*z.real + im*z.im, -real*z.im + im*z.real)/sqrt(z.real*z.real + z.im*z.im);
    }
    
    // Declaring Overloaded << as a friend to access private variables
    friend ostream& operator<<(ostream& out, const complex& z);
};

ostream& operator<<(ostream& out, const complex& z)
{
    out << z.real << " + " << z.im<< "i";
    return out;
}
    

int main()
{
  // Defining two complex numbers  
  complex z1(0,0);
  complex z2(8,1);
  
  // Doing some operations
  cout<<(z1+z2).modulus()<<endl;
  cout<<(z1/z2+z2*2.5)<<endl;
  return 0;
}
