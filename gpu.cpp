#include "gpu.h"
#include <iostream>

GPU::GPU(unsigned int w, unsigned int h, std::string n, std::string m, double p, unsigned int pc, std::string t, int ms, double pf, float c, std::string i, std::string co, bool sp):
    PC_Parts (w, h, n, m, p, pc), type(t), memory_size(ms), performance(pf), clock(c), interface(i), connectors(co), supplementary_power(sp) {}

PC_Parts *GPU::clone() const {
    return new GPU(*this);
}

unsigned int GPU::Rating() {
    unsigned int rating=0;
    if(type=="GDDR6" || type=="GDDR5X" || type=="GDDR5")
        rating+=2;
    else if(type=="GDDR4")
        rating++;
    if(memory_size>=8)
        rating+=2;
    else if (memory_size<8 && memory_size>=4)
        rating++;
    if(performance>=8.5)
        rating+=2;
    else if(performance<8.5 && performance>=3)
        rating++;
    if(clock>=1400)
        rating+=2;
    else if(clock<1400 && clock>=1100)
        rating++;
    return rating;
}

void GPU::checkSupplementaryPower(const PSU* p) const {
    if(supplementary_power) {
        if(p->getSupplementaryPower()==false && supplementary_power)
            std::cerr<<"Pin di alimentazione supplementare non disponibili.";
    }
}