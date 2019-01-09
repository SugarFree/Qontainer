#include "componenti_pc.h"

Componenti_PC::Componenti_PC(unsigned int l, unsigned int a, std::string n, float p): larghezza(l), altezza(a), nome(n), prezzo(p) {}

unsigned int Componenti_PC::getLarghezza() const {
    return larghezza;
}

unsigned int Componenti_PC::getAltezza() const {
    return altezza;
}

void Componenti_PC::setLarghezza(unsigned int l) {
    if(this->larghezza!=l)
        this->larghezza=l;
}

void Componenti_PC::setAltezza(unsigned int a) {
    if(this->altezza!=a)
        this->altezza=a;
}

std::string Componenti_PC::getNome() const {
    return nome;
}

void Componenti_PC::setNome(std::string n) {
    if(this->nome!=n)
        this->nome=n;
}

float Componenti_PC::getPrezzo() const {
    return prezzo;
}

void Componenti_PC::setPrezzo(float p) {
    if(this->prezzo!=p)
        this->prezzo=p;
}
