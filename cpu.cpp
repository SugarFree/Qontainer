#include <iostream>
#include "CPU.h"

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

void CPU::SocketCheck(const MOBA* m) const {
    if(m->getMOBASocket()!=cpu_socket)
        std::cerr<<"Socket MOBA e CPU non compatibili.";
}

void CPU::SupportedRAM(const RAM* r) const {
    if(r->getSize()>8 && !x64bit)
        std::cerr<<"CPU a 32 bit. Non verrano supportati quantitativi di RAM superiori ad 8 GB.";
}