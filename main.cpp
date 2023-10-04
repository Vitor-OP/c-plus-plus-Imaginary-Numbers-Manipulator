#include "complex.hpp"
#include "fasor.hpp"

int main(){
    
    complex c1 = complex(2,3);

    complex c2  = complex(5,7);

    complex c3;

    c1 *= c2;

    c1.print();

    fasor f1 = fasor(c1);

    f1.print();
    std::cout << f1.get_phase()*180/M_PI << std::endl;
    std::cout << f1.get_phase() << std::endl;

    std::cout << c1 << std::endl;
    std::cout << c1.conj() << std::endl;

    std::cout << f1 << std::endl;

    return 0;
}