#include "moba.h"

MOBA::MOBA(unsigned int l, unsigned int a, std::string n, float p, std::string s, std::string f, unsigned int r, unsigned int m, std::string c): Componenti_PC (l, a, n, p), Socket(s), Form_Factor(f), RAM_Slots(r), Max_RAM(m), Connectors(c) {}

Componenti_PC *MOBA::clone() const {
    return new MOBA(*this);
}

int MOBA::Rating() {
    int rating=0;
    if(Socket=="LGA1151" || Socket=="AM4")
        rating++;
    if(RAM_Slots>=4)
        rating+=2;
    else if(RAM_Slots>=2 && RAM_Slots<4)
        rating++;
    if(Max_RAM>=32)
        rating+=2;
    else if(Max_RAM>=16 && Max_RAM<32)
        rating++;
    return rating;
}

void MOBA::setRightSize() {
    if(Socket=="ATX") {
        setAltezza(305);
        setLarghezza(244);
    }
    if(Socket=="Micro ATX"){
        setAltezza(244);
        setLarghezza(244);
    }
    if(Socket=="Mini ITX") {
        setAltezza(170);
        setLarghezza(170);
    }
}
