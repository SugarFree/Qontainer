#ifndef PSU_H
#define PSU_H
#include "pc_parts.h"

class PSU {
private:
    unsigned int width;
    unsigned int height;
    QString form_factor;
    unsigned int wattage;
    QString efficiency_certification;
    QString modularity;
    bool supplementary_power;
    QString name;
    QString manufacturer;
    double price;
public:
    PSU(unsigned int =0, unsigned int =0, QString ="Non specificato", unsigned int =0, QString ="Non specificato", QString ="Non specificato", bool =false, QString ="Non specificato", QString ="Non specificato", double =0);
    void checkPowerConsumption(const PC_Parts*) const;
    bool getSupplementaryPower() const;
};

#endif // PSU_H