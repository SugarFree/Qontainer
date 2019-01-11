#include <iostream>
#include "cpu.h"

cpu::cpu(unsigned int l, unsigned int a, std::string n, std::string pr, float p, unsigned int ce, double s, unsigned int c, bool x64, std::string cs, bool gi, bool di):
    Componenti_PC (l, a, n, pr, p, ce), cpu_speed(s), cores(c), x64bit(x64), cpu_socket(cs), grafica_integrata(gi), dissipatore_integrato(di)   {}

Componenti_PC* cpu::clone() const {
    return new cpu(*this);
}

int cpu::Rating() {
    int rating=0;
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

void cpu::SocketCheck(MOBA m) {
    if(m.getMOBASocket()!=cpu_socket)
        std::cerr<<"Socket MOBA e CPU non compatibili.";
}