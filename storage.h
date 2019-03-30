#ifndef STORAGE_H
#define STORAGE_H
#include "pc_parts.h"

class Storage: public PC_Parts {
private:
    QString type;
    unsigned int rpm;
    unsigned int size;
    QString interface;
    double form_factor;
    unsigned int speed;
public:
    Storage(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc, QString ="Non specificato", unsigned int =0, unsigned int =0, QString ="Non specificato", double =0, unsigned int =0);
    PC_Parts *clone() const;
    unsigned int Rating();
    QString getType() const;
    unsigned int getRPM() const;
    unsigned int getSize() const;
    QString getInterface() const;
    double getFormFactor() const;
    unsigned int getSpeed() const;
    void setType(const QString &value);
    void setRPM(unsigned int value);
    void setSize(unsigned int value);
    void setInterface(const QString &value);
    void setFormFactor(double value);
    void setSpeed(unsigned int value);
};

#endif // STORAGE_H
