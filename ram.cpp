#include "ram.h"

RAM::RAM(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc, unsigned int rs, QString t, unsigned int s):
    PC_Parts (l, h, n, m, p, pc), ram_speed(rs), type(t), size(s) {}

PC_Parts *RAM::clone() const {
    return new RAM(*this);
}

unsigned int RAM::Rating() {
    unsigned int rating=0;
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
    return (getPrice()/size);
}

unsigned int RAM::getSize() const {
    return size;
}