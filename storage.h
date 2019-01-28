#ifndef STORAGE_H
#define STORAGE_H
#include "pc_parts.h"

class Storage: public PC_Parts {
private:
    QString type;
    unsigned int rpm;
    unsigned int size;
    QString interface;
    QString form_factor;
    unsigned int speed;
public:
    Storage(unsigned int w, unsigned int h, QString n, QString m, double p, unsigned int pc, QString ="Non specificato", unsigned int =0, unsigned int =0, QString ="Non specificato", QString ="Non specificato", unsigned int =0);
    PC_Parts *clone() const;
    unsigned int Rating();
    double PricePerGB() const;
    void typeCheck();
};

#endif // STORAGE_H