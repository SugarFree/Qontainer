#include "storage.h"
#include <iostream>

QString Storage::getType() const
{
    return type;
}

unsigned int Storage::getRPM() const
{
    return rpm;
}

unsigned int Storage::getSize() const
{
    return size;
}

QString Storage::getInterface() const
{
    return interface;
}

double Storage::getFormFactor() const
{
    return form_factor;
}

unsigned int Storage::getSpeed() const
{
    return speed;
}

void Storage::setType(const QString &value)
{
    type = value;
}

void Storage::setRPM(unsigned int value)
{
    rpm = value;
}

void Storage::setSize(unsigned int value)
{
    size = value;
}

void Storage::setInterface(const QString &value)
{
    interface = value;
}

void Storage::setFormFactor(double value)
{
    form_factor = value;
}

void Storage::setSpeed(unsigned int value)
{
    speed = value;
}

Storage::Storage(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc, QString t, unsigned int r, unsigned int s, QString i, double ff, unsigned int sp):
    PC_Parts (l, h, n, m, p, pc), type(t), rpm(r), size(s), interface(i), form_factor(ff), speed(sp) {}

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
