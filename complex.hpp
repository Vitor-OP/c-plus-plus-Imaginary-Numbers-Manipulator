#ifndef complex_HPP
#define complex_HPP

#include <iostream>
#include <cmath>

class complex {
private:
    double real;
    double imag;

public:
    complex(double r, double i): real(r), imag(i) {}
    complex(double r): real(r), imag(0) {}
    complex(): real(0), imag(0) {}
    
    // I need to figure it out how to do this whithout destoying everything
    //complex(fasor f): real(f.get_amplitude()*std::cos(f.get_phase())), imag(f.get_amplitude()*std::sin(f.get_phase())) {}

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


/* ----moving fasor to another file----
class fasor {
private:
    double amplitude;
    double phase;

public:
    fasor(double a, double p): amplitude(a), phase(p) {}
    fasor(double a): amplitude(a), phase(0) {}
    fasor(): amplitude(0), phase(0) {}
    fasor(complex c): amplitude(std::sqrt(c.get_real()*c.get_real() + c.get_imag()*c.get_imag())), phase(std::atan2(c.get_imag(),c.get_real())) {}

    void set_amplitude(double a);
    void set_phase(double p);
    double get_amplitude() const;
    double get_phase() const; //so the compilator knows it doesnt change the object
    void print();
    fasor conj();

    // Overload the operator<<() operator
    friend std::ostream& operator<<(std::ostream& stream, const fasor& f);

    fasor operator +(fasor f);
    fasor operator -(fasor f);
    fasor operator *(fasor f);
    fasor operator /(fasor f);
    fasor operator +=(fasor f);
    fasor operator -=(fasor f);
    fasor operator *=(fasor f);
    fasor operator /=(fasor f);

};

*/

#endif