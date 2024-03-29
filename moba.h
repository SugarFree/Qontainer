#ifndef MOBA_H
#define MOBA_H
#include "pc_parts.h"

class MOBA: public PC_Parts {
private:
    QString moba_socket;
    QString form_factor;
    unsigned int RAM_slots;
    unsigned int max_RAM;
    QString connectors;
public:
    MOBA(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc, QString ="Non specificato", QString ="Non specificato", unsigned int =0, unsigned int =0, QString ="Non specificati");
    PC_Parts* clone() const;
    unsigned int Rating();
    QString getMOBASocket() const;
    QString getFormFactor() const;
    unsigned int getRAMSlots() const;
    unsigned int getMaxRAM() const;
    QString getConnectors() const;
    void setMOBASocket(const QString &value);
    void setFormFactor(QString);
    void setRAMSlots(unsigned int value);
    void setMaxRAM(unsigned int value);
    void setConnectors(const QString &value);
};

#endif // MOBA_H
