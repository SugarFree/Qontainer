#ifndef GPU_H
#define GPU_H
#include "pc_parts.h"
#include "moba.h"
#include "psu.h"

class GPU: public PC_Parts
{
private:
    QString type;
    unsigned int memory_size;
    double performance;
    unsigned int clock;
    QString interface;
    QString connectors;
    bool supplementary_power;
public:
    GPU(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc, QString ="Non specificato", unsigned int =0, double =0, unsigned int =0, QString ="Non specificato", QString ="Non specificato", bool =false);
    PC_Parts* clone() const;
    unsigned int Rating();
    QString getType() const;
    unsigned int getMemorySize() const;
    double getPerformance() const;
    unsigned int getClock() const;
    QString getInterface() const;
    QString getConnectors() const;
    bool getSupplementaryPower() const;
    void setType(const QString &value);
    void setMemorySize(unsigned int value);
    void setPerformance(double value);
    void setClock(unsigned int value);
    void setInterface(const QString &value);
    void setConnectors(const QString &value);
    void setSupplementaryPower(bool value);
};

#endif // GPU_H
