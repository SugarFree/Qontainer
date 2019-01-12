#include "ram.h"

RAM::RAM(unsigned int l, unsigned int a, std::string n, std::string pr, float p, unsigned int ce, int rs, std::string t, int sz):
    Componenti_PC (l, a, n, pr, p, ce), ram_speed(rs), type(t), size(sz) {}

Componenti_PC *RAM::clone() const {
    return new RAM(*this);
}

int RAM::Rating() {
    int rating=0;
    if(ram_speed<=3000)
        rating+=2;
    else if(ram_speed<3000 && ram_speed>=2000)
        rating++;
    if(type=="DDR4")
        rating+=2;
    else if(type=="DDR3")
        rating++;
    if(size>=8)
        rating++;
    return rating;
}

double RAM::PricePerGB() const {
    return (getPrezzo()/size);
}

int RAM::getSize() const {
    return size;
}