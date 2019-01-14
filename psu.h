#ifndef PSU_H
#define PSU_H
#include "componenti_pc.h"

class PSU {
private:
    unsigned int larghezza;
    unsigned int altezza;
    std::string form_factor;
    int wattage;
    std::string efficiency_certification;
    std::string modularity;
    bool alimentazione_supplementare;
public:
    PSU(unsigned int =0, unsigned int =0, std::string ="Non specificato", int =0, std::string ="Non specificato", std::string ="Non specificato", bool =false);
    int checkPowerConsumption(const Componenti_PC*);
    bool getAlimentazioneSupplementare() const;
};

#endif // PSU_H