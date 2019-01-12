#ifndef GPU_H
#define GPU_H
#include "componenti_pc.h"

class GPU: public Componenti_PC
{
private:
    std::string type;
public:
    GPU();
};

#endif // GPU_H