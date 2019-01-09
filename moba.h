#ifndef MOBA_H
#define MOBA_H
#include "componenti_pc.h"
#include <string>

class MOBA: public Componenti_PC {
private:
    std::string Socket;
    std::string Form_Factor;
    unsigned int RAM_Slots;
    unsigned int Max_RAM;
    std::string Connectors;
public:
    MOBA(unsigned int l, unsigned int a, std::string n, float p, std::string ="Non specificato", std::string ="Non specificato", unsigned int =0, unsigned int =0, std::string ="Non specificati");
    Componenti_PC* clone() const;
    int Rating(); //aggiungere prezzo?
    void setRightSize();
    ~MOBA() =default;
};

#endif // MOBA_H
