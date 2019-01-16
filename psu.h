#ifndef PSU_H
#define PSU_H
#include "pc_parts.h"

class PSU {
private:
    unsigned int width;
    unsigned int height;
    std::string form_factor;
    unsigned int wattage;
    std::string efficiency_certification;
    std::string modularity;
    bool supplementary_power;
    std::string name;
    std::string manufacturer;
    double price;
public:
    PSU(unsigned int =0, unsigned int =0, std::string ="Non specificato", unsigned int =0, std::string ="Non specificato", std::string ="Non specificato", bool =false, std::string ="Non specificato", std::string ="Non specificato", double =0);
    unsigned int checkPowerConsumption(const PC_Parts*);
    bool getSupplementaryPower() const;
};

#endif // PSU_H