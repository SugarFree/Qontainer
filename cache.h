#ifndef CACHE_H
#define CACHE_H
#include <string>

class cache {
private:
    float dimensioni;
    bool istruzioni; //true se cache istruzione, false se cache dati
    std::string livello_cache;
    cache(float =0, bool =false, std::string ="Non specificato");
};

#endif // CACHE_H