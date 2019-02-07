#ifndef PSU_H
#define PSU_H
#include "pc_parts.h"

class PSU: public PC_Parts {
private:
    QString form_factor;
    unsigned int wattage;
    QString efficiency_certification;
    QString modularity;
    bool supplementary_power;
public:
    PSU(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc, QString ="Non specificato", unsigned int =0, QString ="Non specificato", QString ="Non specificato", bool =false);
    PC_Parts* clone() const;
    unsigned int Rating();
    void checkPowerConsumption(const PC_Parts*) const;
    bool getSupplementaryPower() const;
    QString getForm_factor() const;
    unsigned int getWattage() const;
    QString getEfficiency_certification() const;
    QString getModularity() const;
};

#endif // PSU_H
