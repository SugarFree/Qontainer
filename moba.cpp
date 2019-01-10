#include "moba.h"

MOBA::MOBA(unsigned int l, unsigned int a, std::string n, std::string pr, float p, unsigned int ce, std::string s, std::string f, unsigned int r, unsigned int m, std::string c): Componenti_PC (l, a, n, pr, p, ce), moba_socket(s), form_factor(f), RAM_slots(r), max_RAM(m), connectors(c) {}

Componenti_PC *MOBA::clone() const {
    return new MOBA(*this);
}

int MOBA::Rating() {
    int rating=0;
    if(moba_socket=="LGA1151" || moba_socket=="AM4")
        rating++;
    if(RAM_slots>=4)
        rating+=2;
    else if(RAM_slots>=2 && RAM_slots<4)
        rating++;
    if(max_RAM>=32)
        rating+=2;
    else if(max_RAM>=16 && max_RAM<32)
        rating++;
    return rating;
}

void MOBA::setRightSize() {
    if(form_factor=="ATX") {
        setAltezza(305);
        setLarghezza(244);
    }
    if(form_factor=="Micro ATX"){
        setAltezza(244);
        setLarghezza(244);
    }
    if(form_factor=="Mini ITX") {
        setAltezza(170);
        setLarghezza(170);
    }
}
