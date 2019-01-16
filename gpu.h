#ifndef GPU_H
#define GPU_H
#include "pc_parts.h"
#include "moba.h"
#include "psu.h"

class GPU: public PC_Parts
{
private:
    std::string type;
    int memory_size;
    double performance;
    float clock;
    std::string interface;
    std::string connectors;
    bool supplementary_power;
public:
    GPU(unsigned int w, unsigned int h, std::string n, std::string m, double p, unsigned int pc, std::string ="Non specificato", int =0, double =0, float =0, std::string ="Non specificato", std::string ="Non specificato", bool =false);
    PC_Parts* clone() const;
    unsigned int Rating();
    void checkRightInterface(const MOBA*) const; //da perferzionare
    void checkSupplementaryPower(const PSU*) const;
    ~GPU() =default;
};

#endif // GPU_H