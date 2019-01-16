#include "psu.h"
#include <iostream>

PSU::PSU(unsigned int w, unsigned int h, std::string ff, unsigned int wa, std::string ec, std::string m, bool sp, std::string n, std::string ma, double p):
    width(w), height(h), form_factor(ff), wattage(wa), efficiency_certification(ec), modularity(m), supplementary_power(sp), name(n), manufacturer(ma), price(p) {}

unsigned int PSU::checkPowerConsumption(const PC_Parts *c) {
    if(c->getPowerConsumption()>wattage) {
        std::cerr<<"Consumo energetico eccessivo per l'attuale alimentazione.";
        return 0;
    }
    else if ((((c->getPowerConsumption())+(30/100)*c->getPowerConsumption()))<wattage) {
        std::cerr<<"Consumo energetico troppo vicino al wattaggio dell'alimentatore.";
        return 0;
    }
    else
        return wattage-(c->getPowerConsumption());
}

bool PSU::getSupplementaryPower() const {
    return supplementary_power;
}