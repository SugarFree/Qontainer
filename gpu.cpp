#include "gpu.h"
#include <iostream>

GPU::GPU(unsigned int l, unsigned int a, std::string n, std::string pr, float p, unsigned int ce, std::string t, int ms, double pf, float c, std::string i, std::string co):
    Componenti_PC (l, a, n, pr, p, ce), type(t), memory_size(ms), performance(pf), clock(c), interface(i), connectors(co) {}

Componenti_PC *GPU::clone() const {
    return new GPU(*this);
}

int GPU::Rating() {
    int rating=0;
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

void GPU::checkRightInterface(const MOBA* m) const {
    size_t pci_moba=m->getConnectors().find("PCI-E 3.0");
    size_t pci_gpu=connectors.find("PCI-E 3.0");
    if(!pci_moba || !pci_gpu)
        std::cerr<<"Interfaccia PCI Express non compatibile.";
}