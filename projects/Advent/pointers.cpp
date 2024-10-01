#include <iostream>
#include <string>

int main(){
    int c = 1;
    int *ptr = &c;
    //std::cout << "Adresse til c via c:" << &c << "verdien til c: "<<*ptr<< std::endl << "Adresse til c via d:"<< ptr<<" C:"<<c<< std::endl;
    std::cout << "c:" << c << std::endl;
    int *c_copy = &c;
    *c_copy = 2;
    std::cout << "Verdien til c_copy:" << *c_copy << std::endl << "Verdien til c:" << c;
    
    

    return 0;
    
}