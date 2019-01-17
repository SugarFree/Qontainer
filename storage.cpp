#include "storage.h"
#include <iostream>

Storage::Storage(unsigned int w, unsigned int h, std::string n, std::string m, double p, unsigned int pc, std::string t, unsigned int r, unsigned int s, std::string i, std::string ff, unsigned int sp):
    PC_Parts (w, h, n, m, p, pc), type(t), rpm(r), size(s), interface(i), form_factor(ff), speed(sp) {}

PC_Parts *Storage::clone() const {
    return new Storage(*this);
}

unsigned int Storage::Rating() {
    unsigned int rating=0;
    if(type=="SSD")
        rating+=2;
    else
        rating++;
    if((type=="HDD" || type=="Hybrid HDD") && rpm>=7200)
        rating++;
    if(speed>=200)
        rating+=2;
    if(speed>=50 && speed<200)
        rating++;
    return rating;
}

double Storage::PricePerGB() const {
    return (getPrice()/size);
}

void Storage::typeCheck() {
    if(type=="SSD" && rpm!=0)
        std::cerr<<"Attenzione! RPM non è un parametro valido per storage di tipo SSD.";
}