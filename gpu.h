#ifndef GPU_H
#define GPU_H
#include "componenti_pc.h"
#include "moba.h"

class GPU: public Componenti_PC
{
private:
    std::string type;
    int memory_size;
    double performance;
    float clock;
    std::string interface;
    std::string connectors;
public:
    GPU(unsigned int l, unsigned int a, std::string n, std::string pr, float p, unsigned int ce, std::string ="Non specificato", int =0, double =0, float =0, std::string ="Non specificato", std::string ="Non specificato");
    Componenti_PC* clone() const;
    int Rating();
    void checkRightInterface(const MOBA*) const;
    //check alimentazione con psu???
    ~GPU() =default;
};

#endif // GPU_H