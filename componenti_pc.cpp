#include "componenti_pc.h"

Componenti_PC::Componenti_PC(unsigned int l, unsigned int a): larghezza(l), altezza(a) {
    if(l<=0 || a<=0)
        throw Dimensioni_Negative();
}

unsigned int Componenti_PC::getAltezza() const {
    return altezza;
}

unsigned int Componenti_PC::getLarghezza() const {
    return larghezza;
}

void Componenti_PC::setAltezza(unsigned int a) {
    altezza=a;
}

void Componenti_PC::setLarghezza(unsigned int l) {
    larghezza=l;
}
