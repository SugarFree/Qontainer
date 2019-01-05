#ifndef COMPONENTI_PC_H
#define COMPONENTI_PC_H
#include <string>

class Componenti_PC
{
private:
    unsigned int larghezza;
    unsigned int altezza;
public:
    Componenti_PC(unsigned int =1, unsigned int =1);
    virtual Componenti_PC* clone() const =0;
    virtual std::string Modello_Componente() =0;
    virtual float Prezzo() =0;
    virtual short int Rating() =0;
    unsigned int getLarghezza() const;
    unsigned int getAltezza() const;
    void setLarghezza(unsigned int);
    void setAltezza(unsigned int);
    virtual ~Componenti_PC() =default;
};

class Dimensioni_Negative {};

#endif // COMPONENTI_PC_H
