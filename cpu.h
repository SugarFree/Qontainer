#ifndef CPU_H
#define CPU_H
#include "pc_parts.h"

class CPU: public PC_Parts {
private:
    double cpu_speed;
    unsigned int cores;
    bool x64bit;
    QString cpu_socket;
    bool integrated_graphic;
public:
    CPU(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc, double =0, unsigned int =0, bool =false, QString ="Non specificato", bool =false);
    PC_Parts* clone() const;
    unsigned int Rating();
    double getCpuSpeed() const;
    unsigned int getCores() const;
    bool getx64bit() const;
    QString getCpuSocket() const;
    bool getIntegratedGraphic() const;
    void setCpuSpeed(double value);
    void setCores(unsigned int value);
    void setx64bit(bool value);
    void setCpuSocket(const QString &value);
    void setIntegratedGraphic(bool value);
};

#endif // CPU_H
