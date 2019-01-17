#ifndef CPU_H
#define CPU_H
#include "pc_parts.h"
//#include "cache.h"
#include "moba.h"
#include "ram.h"

class cpu: public PC_Parts {
private:
    double cpu_speed;
    unsigned int cores;
    bool x64bit; //true se 64bit, false se 32bit
    std::string cpu_socket;
    //cache
    bool integrated_graphic;
public:
    cpu(unsigned int w, unsigned int h, std::string n, std::string m, double p, unsigned int pc, double =0, unsigned int =0, bool =false, std::string ="Non specificato", bool =false);
    PC_Parts* clone() const;
    unsigned int Rating();
    void SocketCheck(const MOBA*) const;
    void SupportedRAM(const RAM*) const;
    ~cpu() =default;
};

#endif // CPU_H