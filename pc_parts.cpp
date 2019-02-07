#include "pc_parts.h"

PC_Parts::PC_Parts(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc)
    : length(l), height(h), name(n), manufacturer(m), price(p), power_consumption(pc) {}

unsigned int PC_Parts::getLength() const {
    return length;
}

void PC_Parts::setLength(unsigned int l) {
    if(this->length!=l)
        this->length=l;
}

unsigned int PC_Parts::getHeight() const {
    return height;
}

void PC_Parts::setHeight(unsigned int h) {
    if(this->height!=h)
        this->height=h;
}

QString PC_Parts::getName() const {
    return name;
}

void PC_Parts::setName(QString n) {
    if(this->name!=n)
        this->name=n;
}

QString PC_Parts::getManufacturer() const {
    return this->manufacturer;
}

void PC_Parts::setManufacturer(QString m) {
    if(this->manufacturer!=m)
        this->manufacturer=m;
}

double PC_Parts::getPrice() const {
    return price;
}

void PC_Parts::setPrice(double p) {
    if(this->price!=p)
        this->price=p;
}

unsigned int PC_Parts::getPowerConsumption() const {
    return power_consumption;
}

void PC_Parts::setPowerConsumption(unsigned int pc) {
    if(this->power_consumption!=pc)
        this->power_consumption=pc;
}
