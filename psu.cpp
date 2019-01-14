#include "psu.h"
#include <iostream>

PSU::PSU(unsigned int l, unsigned int a, std::string f, int w, std::string e, std::string m, bool as):
    larghezza(l), altezza(a), form_factor(f), wattage(w), efficiency_certification(e), modularity(m), alimentazione_supplementare(as) {}

int PSU::checkPowerConsumption(const Componenti_PC *c) {
    if(c->getConsumoEnergetico()>wattage) {
        std::cerr<<"Consumo energetico eccessivo per l'attuale alimentazione.";
        return 0;
    }
    else if ((((c->getConsumoEnergetico())+(30/100)*c->getConsumoEnergetico()))<wattage) {
        std::cerr<<"Consumo energetico troppo vicino al wattaggio dell'alimentatore.";
        return 0;
    }
    else
        return wattage-(c->getConsumoEnergetico());
}

bool PSU::getAlimentazioneSupplementare() const {
    return alimentazione_supplementare;
}