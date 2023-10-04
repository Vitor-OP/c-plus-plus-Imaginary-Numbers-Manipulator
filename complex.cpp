#include "complex.hpp"
#include "fasor.hpp"
    
    //complex::complex(fasor f): real(f.get_amplitude()*std::cos(f.get_phase())), imag(f.get_amplitude()*std::sin(f.get_phase())) {}
    //fasor::fasor(complex c): amplitude(std::sqrt(c.get_real()*c.get_real() + c.get_imag()*c.get_imag())), phase(std::atan2(c.get_imag(),c.get_real())) {}

    void complex::set_real(double r){
        real = r;
    }

    void complex::set_imag(double i){
        imag = i;
    }

    double complex::get_real() const{
        return real;
    }

    double complex::get_imag() const{
        return imag;
    }

    void complex::print(){
        std::cout << real << " + " << imag << "i" << std::endl;
    }

    complex complex::conj(){
        complex c;
        c.real = real;
        c.imag = -imag;
        return c;
    }

    std::ostream& operator<<(std::ostream& stream, const complex& c) {
        if (c.imag < 0) {
            stream << c.real << " - " << std::abs(c.imag) << "i";
        } else {
            stream << c.real << " + " << c.imag << "i";
        }
        return stream;
    }

    complex complex::operator +(complex c){
        return complex(real + c.real, imag + c.imag);
    }

    complex complex::operator -(complex c){
        return complex(real - c.real, imag - c.imag);
    }

    complex complex::operator *(complex c){
        return complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    complex complex::operator /(complex c){
        return complex((real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag), (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag));
    }

    complex complex::operator +=(complex c){
        real = real + c.real;
        imag = imag + c.imag;
        
        return *this;
    }

    complex complex::operator -=(complex c){
        real = real - c.real;
        imag = imag - c.imag;

        return *this;
    }

    complex complex::operator *=(complex c){
        double aux_real = real;
        real = real * c.real - imag * c.imag;
        imag = aux_real * c.imag + imag * c.real;

        return *this;

    }

    complex complex::operator /=(complex c){
        double aux_real = real;
        real = (real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag);
        imag = (imag * c.real - aux_real * c.imag) / (c.real * c.real + c.imag * c.imag);

        return *this;
    }
        
//********************************************************************************************************************
//*********************************************** FASOR CLASS ********************************************************
//********************************************************************************************************************

    void fasor::set_amplitude(double a){
        amplitude = a;
    }

    void fasor::set_phase(double p){
        phase = p;
    }

    double fasor::get_amplitude() const{
        return amplitude;
    }

    double fasor::get_phase() const{
        return phase;
    }

    void fasor::print(){
        std::cout << amplitude << " * e^(" << phase/M_PI << "*PI*i)" << std::endl;
    }

    fasor fasor::conj(){
        fasor f;
        f.amplitude = amplitude;
        f.phase = -phase;
        return f;
    }

    std::ostream& operator<<(std::ostream& stream, const fasor& f) {
        stream << f.amplitude << " /_ " << f.phase/M_PI << "PI";
        return stream;
    }

    fasor fasor::operator +(fasor f){
        return fasor(amplitude + f.amplitude, phase + f.phase);
    }

    fasor fasor::operator -(fasor f){
        return fasor(amplitude - f.amplitude, phase - f.phase);
    }

    fasor fasor::operator *(fasor f){
        return fasor(amplitude * f.amplitude, phase + f.phase);
    }

    fasor fasor::operator /(fasor f){
        return fasor(amplitude / f.amplitude, phase - f.phase);
    }

    fasor fasor::operator +=(fasor f){
        amplitude = amplitude + f.amplitude;
        phase = phase + f.phase;
        
        return *this;
    }

    fasor fasor::operator -=(fasor f){
        amplitude = amplitude - f.amplitude;
        phase = phase - f.phase;

        return *this;
    }

    fasor fasor::operator *=(fasor f){
        amplitude = amplitude * f.amplitude;
        phase = phase + f.phase;

        return *this;

    }

    fasor fasor::operator /=(fasor f){
        amplitude = amplitude / f.amplitude;
        phase = phase - f.phase;

        return *this;
    }

// #endif