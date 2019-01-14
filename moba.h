#ifndef MOBA_H
#define MOBA_H
#include "componenti_pc.h"

class MOBA: public Componenti_PC {
private:
    std::string moba_socket;
    std::string form_factor;
    unsigned int RAM_slots;
    unsigned int max_RAM;
    std::string connectors; //specializzare ulteriormente (ex. PCI slot) per fare più metodi (ex. su RAM compatibilità)??? Oppure lasciare così e usare find di string per trovare le parole chiave???
public:
    MOBA(unsigned int l, unsigned int a, std::string n, std::string pr, float p, unsigned int ce, std::string ="Non specificato", std::string ="Non specificato", unsigned int =0, unsigned int =0, std::string ="Non specificati");
    Componenti_PC* clone() const;
    int Rating();
    std::string getMOBASocket() const;
    void setFormFactor(std::string);
    void setRightSize();
    void setRightFormFactor();
    std::string getConnectors() const;
    //controllo slot di RAM e GB di RAM (da fare nella "classe finale"???)
    ~MOBA() =default;
};

#endif // MOBA_H