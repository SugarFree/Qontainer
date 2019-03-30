#include "psu.h"
#include <iostream>

QString PSU::getFormFactor() const
{
    return form_factor;
}

unsigned int PSU::getWattage() const
{
    return wattage;
}

QString PSU::getEfficiencyCertification() const
{
    return efficiency_certification;
}

QString PSU::getModularity() const
{
    return modularity;
}

void PSU::setFormFactor(const QString &value)
{
    form_factor = value;
}

void PSU::setWattage(unsigned int value)
{
    wattage = value;
}

void PSU::setEfficiencyCertification(const QString &value)
{
    efficiency_certification = value;
}

void PSU::setModularity(const QString &value)
{
    modularity = value;
}

void PSU::setSupplementaryPower(bool value)
{
    supplementary_power = value;
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

bool PSU::getSupplementaryPower() const {
    return supplementary_power;
}
