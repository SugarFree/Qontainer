#include "moba.h"

QString MOBA::getForm_factor() const
{
    return form_factor;
}

unsigned int MOBA::getRAM_slots() const
{
    return RAM_slots;
}

unsigned int MOBA::getMax_RAM() const
{
    return max_RAM;
}

QString MOBA::getConnectors() const
{
    return connectors;
}

MOBA::MOBA(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc, QString ms, QString ff, unsigned int rs, unsigned int mr, QString c):
    PC_Parts (l, h, n, m, p, pc), moba_socket(ms), form_factor(ff), RAM_slots(rs), max_RAM(mr), connectors(c) {}

PC_Parts *MOBA::clone() const {
    return new MOBA(*this);
}

unsigned int MOBA::Rating() {
    unsigned int rating=0;
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

QString MOBA::getMOBASocket() const {
    return moba_socket;
}

void MOBA::setFormFactor(QString f) {
    if(this->form_factor!=f)
        this->form_factor=f;
}

void MOBA::setRightSize() {
    if(getHeight()==0 || getLength()==0) {
        if(form_factor=="ATX") {
            setHeight(305);
            setLength(244);
        }
        if(form_factor=="Micro ATX"){
            setHeight(244);
            setLength(244);
        }
        if(form_factor=="Mini ITX") {
            setHeight(170);
            setLength(170);
        }
    }
}

void MOBA::setRightFormFactor() {
    if(form_factor!="ATX" || form_factor!="Micro ATX" || form_factor!="Mini ITX") {
        if(getHeight()==305 && getLength()==244)
            setFormFactor("ATX");
        if(getHeight()==244 && getLength()==244)
            setFormFactor("Micro ATX");
        if(getHeight()==170 && getLength()==170)
            setFormFactor("Mini ITX");
    }
}
