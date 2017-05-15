//
//  main.cpp
//  класс для работы с комплексными числами
//
//  Created by Артем on 03.04.17.
//  Copyright © 2017 Артем. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

class Complex
{ public :
    Complex(){
        real = 0;
        imaginary = 1;
    }//конструктор
    Complex(double re, double im){
       setComplex(re,im);
    }
    void setComplex(double re, double im)
    {real = re; imaginary = im; }
    Complex add(Complex auther)// metod
    {
        Complex result;
        result.real=real+auther.real;
        result.imaginary=imaginary+auther.imaginary;
        return result;
    }
    Complex substract( )
    {
        Complex z(-real,-imaginary);
        return z;
    }
    Complex subscract (Complex z1)
    {   Complex result1;// z2=this->add(z1.substract)
        result1.real=real+z1.real;
        result1.imaginary=imaginary+z1.imaginary;
        return result1;
    }
    double radius ()
    { return sqrt(real*real + imaginary+imaginary);
    }
    void display ()
    {
        cout << real << "+" << imaginary << "i" <<endl;
        
    }
    private :
    double real, imaginary;
};
int main() {
    Complex z1,z2,z3;
    z1.setComplex(2,-1);
    z1.display();
    z2.setComplex(3,1);
    z2.display();
    z3= z1.add(z2);
    z3.display();
    Complex zArray[5];
    for (int i(0); i<5; i++)
    {
        zArray[i].setComplex(i,i+1);
        cout<<zArray[i].radius()<<endl;
    }
    Complex* zPointer =& z1;
    zPointer->setComplex(3,5);
    cout<< "Values of Array of pointers"<<endl;
    Complex* zA = new Complex[10];
    for (int i(0); i<10; i++)
    {
        zA->setComplex(i,i+1);
        cout << zA->radius()<<endl;
    }
    return 0;
}
// набор публичных классов - интерфейс класса ( api )
