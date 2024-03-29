#ifndef RAM_H
#define RAM_H
#include "pc_parts.h"

class RAM: public PC_Parts {
private:
    unsigned int ram_speed;
    QString type;
    unsigned int size;
public:
    RAM(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc, unsigned int =0, QString ="Non specificato", unsigned int =0);
    PC_Parts *clone() const;
    unsigned int Rating();
    unsigned int getSize() const;
    QString getType() const;
    unsigned int getRamSpeed() const;
    void setRamSpeed(unsigned int value);
    void setType(const QString &value);
    void setSize(unsigned int value);
};

#endif // RAM_H
