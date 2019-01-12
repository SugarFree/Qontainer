#ifndef RAM_H
#define RAM_H
#include "componenti_pc.h"

class RAM: public Componenti_PC {
private:
    int ram_speed;
    std::string type;
    int size;
public:
    RAM(unsigned int l, unsigned int a, std::string n, std::string pr, float p, unsigned int ce, int =0, std::string ="Non specificato", int =0);
    Componenti_PC *clone() const;
    int Rating();
    double PricePerGB() const;
    int getSize() const;
    ~RAM() =default;
};

#endif // RAM_H