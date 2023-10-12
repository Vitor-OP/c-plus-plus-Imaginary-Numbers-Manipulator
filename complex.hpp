#ifndef complex_HPP
#define complex_HPP

#include <iostream>
#include <cmath>

class fasor;

class complex {
private:
    double real;
    double imag;

public:
    complex(double r, double i): real(r), imag(i) {}
    complex(double r): real(r), imag(0) {}
    complex(): real(0), imag(0) {}
    
    //complex(fasor f): real(f.get_amplitude()*std::cos(f.get_phase())), imag(f.get_amplitude()*std::sin(f.get_phase())) {}
    complex(fasor c);

    void set_real(double r);
    void set_imag(double i);
    double get_real() const;
    double get_imag() const; //so the compilator knows it doesnt change the object
    void print();
    complex conj();

    // Overload the operator<<() operator
    friend std::ostream& operator<<(std::ostream& stream, const complex& c);
    
    complex operator +(complex c);
    complex operator -(complex c);
    complex operator *(complex c);
    complex operator /(complex c);
    complex operator +=(complex c);
    complex operator -=(complex c);
    complex operator *=(complex c);
    complex operator /=(complex c);
};

#endif