#include "psu.h"
#include <iostream>

QString PSU::getForm_factor() const
{
    return form_factor;
}

unsigned int PSU::getWattage() const
{
    return wattage;
}

QString PSU::getEfficiency_certification() const
{
    return efficiency_certification;
}

QString PSU::getModularity() const
{
    return modularity;
}

PSU::PSU(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc, QString ff, unsigned int wa, QString ec, QString mo, bool sp):
    PC_Parts(l, h, n, m, p, pc), form_factor(ff), wattage(wa), efficiency_certification(ec), modularity(mo), supplementary_power(sp) {}

PC_Parts *PSU::clone() const {
    return new PSU(*this);
}

unsigned int PSU::Rating() {
    unsigned int rating=0;
    if(efficiency_certification=="80+ Gold" || efficiency_certification=="80+ Titanium" || efficiency_certification=="80+ Titanium")
        rating+=2;
    else if(efficiency_certification=="80+ Silver" || efficiency_certification=="80+ Bronze" || efficiency_certification=="80+")
        rating++;
    if(modularity=="Semi" || modularity=="Full")
        rating++;
    if(supplementary_power)
        rating++;
    return rating;
}

void PSU::checkPowerConsumption(const PC_Parts *c) const {
    if(c->getPowerConsumption()>wattage)
        std::cerr<<"Attenzione! Consumo energetico eccessivo per l'attuale alimentazione.";
    else if ((((c->getPowerConsumption())+(30/100)*c->getPowerConsumption()))<wattage)
        std::cerr<<"Attenzione! Consumo energetico vicino al wattaggio dell'alimentatore.";
}

bool PSU::getSupplementaryPower() const {
    return supplementary_power;
}