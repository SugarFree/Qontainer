#include "storage.h"
#include <iostream>

Storage::Storage(unsigned int l, unsigned int a, std::string n, std::string pr, float p, unsigned int ce, std::string t, int r, int si, std::string i, std::string f, int s):
    Componenti_PC (l, a, n, pr, p, ce), type(t), rpm(r), size(si), interface(i), form_factor(f), speed(s) {}

Componenti_PC *Storage::clone() const {
    return new Storage(*this);
}

int Storage::Rating() {
    int rating=0;
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
    return (getPrezzo()/size);
}

void Storage::typeCheck() {
    if(type=="SSD" && rpm!=0)
        std::cerr<<"RPM non è un parametro valido per storage di tipo SSD.";
}