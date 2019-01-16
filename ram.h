#ifndef RAM_H
#define RAM_H
#include "pc_parts.h"

class RAM: public PC_Parts {
private:
    unsigned int ram_speed;
    std::string type;
    unsigned int size;
public:
    RAM(unsigned int w, unsigned int h, std::string n, std::string m, double p, unsigned int pc, unsigned int =0, std::string ="Non specificato", unsigned int =0);
    PC_Parts *clone() const;
    unsigned int Rating();
    double PricePerGB() const;
    unsigned int getSize() const;
    ~RAM() =default;
};

#endif // RAM_H