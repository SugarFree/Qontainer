#ifndef CPU_H
#define CPU_H
#include "pc_parts.h"
//#include "cache.h"
#include "moba.h"
#include "ram.h"

class CPU: public PC_Parts {
private:
    double cpu_speed;
    unsigned int cores;
    bool x64bit; //true se 64bit, false se 32bit
    QString cpu_socket;
    //cache
    bool integrated_graphic;
public:
    CPU(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc, double =0, unsigned int =0, bool =false, QString ="Non specificato", bool =false);
    PC_Parts* clone() const;
    unsigned int Rating();
    void SocketCheck(const MOBA*) const;
    void SupportedRAM(const RAM*) const;
    double getCpu_speed() const;
    unsigned int getCores() const;
    bool getX64bit() const;
    QString getCpu_socket() const;
    bool getIntegrated_graphic() const;
};

#endif // CPU_H
