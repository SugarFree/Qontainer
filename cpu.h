#ifndef CPU_H
#define CPU_H
#include "componenti_pc.h"
//#include "cache.h"
#include "moba.h"

class cpu: public Componenti_PC {
private:
    double cpu_speed;
    unsigned int cores;
    bool x64bit; //true se 64bit, false se 32bit
    std::string cpu_socket;
    //cache
    bool grafica_integrata;
    bool dissipatore_integrato;
public:
    cpu(unsigned int l, unsigned int a, std::string n, std::string pr, float p, unsigned int ce, double =0, unsigned int =0, bool =false, std::string ="Non specificato", bool =false, bool =false);
    Componenti_PC* clone() const;
    int Rating();
    void SocketCheck(MOBA);
    //void SupportedRAM(); devo fare classe RAM dopo
    ~cpu() =default;
};

#endif // CPU_H