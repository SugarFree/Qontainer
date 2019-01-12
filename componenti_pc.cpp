#include "componenti_pc.h"

Componenti_PC::Componenti_PC(unsigned int l, unsigned int a, std::string n, std::string pr, float p, unsigned int ce): larghezza(l), altezza(a), nome(n), produttore(pr), prezzo(p), consumo_energetico(ce) {}

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

std::string Componenti_PC::getProduttore() const {
    return produttore;
}

void Componenti_PC::setProduttore(std::string pr) {
    if(this->produttore!=pr)
        this->produttore=pr;
}

double Componenti_PC::getPrezzo() const {
    return prezzo;
}

void Componenti_PC::setPrezzo(double p) {
    if(this->prezzo!=p)
        this->prezzo=p;
}

unsigned int Componenti_PC::getConsumoEnergetico() const {
    return consumo_energetico;
}

void Componenti_PC::setConsumoEnergetico(unsigned int c) {
    if(this->consumo_energetico!=c)
        this->consumo_energetico=c;
}