#ifndef MOBA_H
#define MOBA_H
#include "pc_parts.h"

class MOBA: public PC_Parts {
private:
    QString moba_socket;
    QString form_factor;
    unsigned int RAM_slots;
    unsigned int max_RAM;
    QString connectors; //specializzare ulteriormente (ex. PCI slot) per fare più metodi (ex. su RAM compatibilità)??? Oppure lasciare così e usare find di string per trovare le parole chiave???
public:
    MOBA(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc, QString ="Non specificato", QString ="Non specificato", unsigned int =0, unsigned int =0, QString ="Non specificati");
    PC_Parts* clone() const;
    unsigned int Rating();
    QString getMOBASocket() const;
    void setFormFactor(QString);
    void setRightSize();
    void setRightFormFactor();
    //controllo slot di RAM e GB di RAM (da fare nella "classe finale"???)
};

#endif // MOBA_H