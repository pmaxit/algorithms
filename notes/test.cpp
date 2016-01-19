#include <iostream>

using namespace std;

class complex{

  public:
    explicit complex(int real=0, int imaginary=0):real(real), imaginary(imaginary){}
    
    complex(const complex &c):real(c.real), imaginary(c.imaginary){
      cout<<" invoking copy constructor"<<endl;   
    }

    complex(complex &&c):real(c.real), imaginary(c.imaginary){
      cout<<" move constructor"<<endl;
    }

  private:
    int real;
    int imaginary;
};

complex fun(){

  return complex(0, 1);
}

int main(){
  complex c;
  //complex c1 = fun();
  complex c2(move(c));
  //complex c1(c);
}
