#ifndef fasor_HPP
#define fasor_HPP

#include <iostream>
#include <cmath>

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
    double get_phase() const;
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

#endif