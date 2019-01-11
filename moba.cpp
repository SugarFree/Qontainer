#include "moba.h"

MOBA::MOBA(unsigned int l, unsigned int a, std::string n, std::string pr, float p, unsigned int ce, std::string s, std::string f, unsigned int r, unsigned int m, std::string c):
    Componenti_PC (l, a, n, pr, p, ce), moba_socket(s), form_factor(f), RAM_slots(r), max_RAM(m), connectors(c) {}

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

std::string MOBA::getMOBASocket() const {
    return moba_socket;
}

void MOBA::setFormFactor(std::string f) {
    if(this->form_factor!=f)
        this->form_factor=f;
}

void MOBA::setRightSize() {
    if(getAltezza()==0 || getLarghezza()==0) {
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
}

void MOBA::setRightFormFactor() {
    if(form_factor!="ATX" || form_factor!="Micro ATX" || form_factor!="Mini ITX") {
        if(getAltezza()==305 && getLarghezza()==244)
            setFormFactor("ATX");
        if(getAltezza()==244 && getLarghezza()==244)
            setFormFactor("Micro ATX");
        if(getAltezza()==170 && getLarghezza()==170)
            setFormFactor("Mini ITX");
    }
}

