#ifndef COMPONENTI_PC_H
#define COMPONENTI_PC_H
#include <string>

class Componenti_PC {
private:
    unsigned int larghezza;
    unsigned int altezza;
    std::string nome;
    float prezzo;
public:
    Componenti_PC(unsigned int =0, unsigned int =0, std::string ="Non specificato", float =0);
    virtual Componenti_PC* clone() const =0;
    virtual int Rating() =0;
    unsigned int getLarghezza() const;
    unsigned int getAltezza() const;
    void setLarghezza(unsigned int);
    void setAltezza(unsigned int);
    std::string getNome() const;
    void setNome(std::string);
    float getPrezzo() const;
    void setPrezzo(float);
    virtual ~Componenti_PC() =default;
};

#endif // COMPONENTI_PC_H
