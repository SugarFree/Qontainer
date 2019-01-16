#ifndef STORAGE_H
#define STORAGE_H
#include "pc_parts.h"

class Storage: public PC_Parts {
private:
    std::string type;
    unsigned int rpm;
    unsigned int size;
    std::string interface;
    std::string form_factor;
    unsigned int speed;
public:
    Storage(unsigned int w, unsigned int h, std::string n, std::string m, double p, unsigned int pc, std::string ="Non specificato", unsigned int =0, unsigned int =0, std::string ="Non specificato", std::string ="Non specificato", unsigned int =0);
    PC_Parts *clone() const;
    unsigned int Rating();
    double PricePerGB() const;
    void typeCheck();
};

#endif // STORAGE_H