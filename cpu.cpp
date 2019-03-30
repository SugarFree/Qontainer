#include <iostream>
#include "cpu.h"

double CPU::getCpuSpeed() const
{
    return cpu_speed;
}

unsigned int CPU::getCores() const
{
    return cores;
}

bool CPU::getx64bit() const
{
    return x64bit;
}

QString CPU::getCpuSocket() const
{
    return cpu_socket;
}

bool CPU::getIntegratedGraphic() const
{
    return integrated_graphic;
}

void CPU::setCpuSpeed(double value)
{
    cpu_speed = value;
}

void CPU::setCores(unsigned int value)
{
    cores = value;
}

void CPU::setx64bit(bool value)
{
    x64bit = value;
}

void CPU::setCpuSocket(const QString &value)
{
    cpu_socket = value;
}

void CPU::setIntegratedGraphic(bool value)
{
    integrated_graphic = value;
}

CPU::CPU(unsigned int l, unsigned int h, QString n, QString m, double p, unsigned int pc, double s, unsigned int c, bool x64, QString cs, bool ig):
    PC_Parts (l, h, n, m, p, pc), cpu_speed(s), cores(c), x64bit(x64), cpu_socket(cs), integrated_graphic(ig) {}

PC_Parts* CPU::clone() const {
    return new CPU(*this);
}

unsigned int CPU::Rating() {
    unsigned int rating=0;
    if(cpu_speed>=2.4 && cpu_speed<3.6)
        rating++;
    else if(cpu_speed>=3.6)
        rating+=2;
    if(cores>=4 && cores<8)
        rating++;
    else if(cores>=8)
        rating+=2;
    if(x64bit)
        rating++;
    if(cpu_socket=="LGA1151" || cpu_socket=="AM4")
        rating++;
    return rating;
}
