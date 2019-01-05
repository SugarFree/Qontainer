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
public:
    MOBA(std::string ="Not Specified", std::string ="Not Specified", unsigned int =1, unsigned int =2);
};

#endif // MOBA_H
