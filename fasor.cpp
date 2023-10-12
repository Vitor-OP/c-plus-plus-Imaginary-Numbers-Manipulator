#include "fasor.hpp"
#include "complex.hpp"

    //constructor from complex
    fasor::fasor(complex c): amplitude(std::sqrt(c.get_real()*c.get_real() + c.get_imag()*c.get_imag())), phase(std::atan2(c.get_imag(),c.get_real())) {}

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