#ifndef COMPONENTI_PC_H
#define COMPONENTI_PC_H
#include <string>

class PC_Parts {
private:
    unsigned int width;
    unsigned int height;
    std::string name;
    std::string manufacturer;
    double price;
    unsigned int power_consumption;
public:
    PC_Parts(unsigned int =0, unsigned int =0, std::string ="Non specificato", std::string ="Non specificato", double =0, unsigned int =0);
    virtual PC_Parts* clone() const =0;
    virtual unsigned int Rating() =0;
    unsigned int getWidth() const;
    void setWidth(unsigned int);
    unsigned int getHeight() const;
    void setHeight(unsigned int);
    std::string getName() const;
    void setName(std::string);
    std::string getManufacturer() const;
    void setManufacturer(std::string);
    double getPrice() const;
    void setPrice(double);
    unsigned int getPowerConsumption() const;
    void setPowerConsumption(unsigned int);
    virtual ~PC_Parts() =default;
};

#endif // COMPONENTI_PC_H