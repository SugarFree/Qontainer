#ifndef STORAGE_H
#define STORAGE_H
#include "componenti_pc.h"

class Storage: public Componenti_PC {
private:
    std::string type;
    int rpm;
    int size;
    std::string interface;
    std::string form_factor;
    int speed;
public:
    Storage(unsigned int l, unsigned int a, std::string n, std::string pr, float p, unsigned int ce, std::string ="Non specificato", int =0, int =0, std::string ="Non specificato", std::string ="Non specificato", int =0);
    Componenti_PC *clone() const;
    int Rating();
    double PricePerGB() const;
    void typeCheck();
};

#endif // STORAGE_H