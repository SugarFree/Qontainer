#ifndef GPU_H
#define GPU_H
#include "pc_parts.h"
#include "moba.h"
#include "psu.h"

class GPU: public PC_Parts
{
private:
    QString type;
    int memory_size;
    double performance;
    float clock;
    QString interface;
    QString connectors;
    bool supplementary_power;
public:
    GPU(unsigned int w, unsigned int h, QString n, QString m, double p, unsigned int pc, QString ="Non specificato", int =0, double =0, float =0, QString ="Non specificato", QString ="Non specificato", bool =false);
    PC_Parts* clone() const;
    unsigned int Rating();
    void checkSupplementaryPower(const PSU*) const;
    ~GPU() =default;
};

#endif // GPU_H