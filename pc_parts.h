#ifndef PC_PARTS_H
#define PC_PARTS_H
#include <QString>

class PC_Parts {
private:
    unsigned int width;
    unsigned int height;
    QString name;
    QString manufacturer;
    double price;
    unsigned int power_consumption;
public:
    PC_Parts(unsigned int =0, unsigned int =0, QString ="Non specificato", QString ="Non specificato", double =0, unsigned int =0);
    virtual PC_Parts* clone() const =0;
    virtual unsigned int Rating() =0;
    unsigned int getWidth() const;
    void setWidth(unsigned int);
    unsigned int getHeight() const;
    void setHeight(unsigned int);
    QString getName() const;
    void setName(QString);
    QString getManufacturer() const;
    void setManufacturer(QString);
    double getPrice() const;
    void setPrice(double);
    unsigned int getPowerConsumption() const;
    void setPowerConsumption(unsigned int);
    virtual ~PC_Parts() =default;
};

#endif // PC_PARTS_H