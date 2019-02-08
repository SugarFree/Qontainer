#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QSize>
#include <QTableWidget>
#include <QHeaderView>
#include <QScreen>
#include <QLineEdit>
#include <QListWidget>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QIODevice>
#include <QFileDialog>
#include "cvector.h"
#include "pc_parts.h"
#include "moba.h"
#include "cpu.h"
#include "gpu.h"
#include "psu.h"
#include "ram.h"
#include "psu.h"
#include "storage.h"
#include <string>


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent=nullptr);

private slots:
    void mobaToBuild();
    void cpuToBuild();
    void gpuToBuild();
    void psuToBuild();
    void ramToBuild();
    void storageToBuild();
    void removeMOBAFromBuild();
    void removeCPUFromBuild();
    void removeGPUFromBuild();
    void removePSUFromBuild();
    void removeRAMFromBuild();
    void removeStorageFromBuild();
    void deleteBuild();
    void saveBuildToFile();
    void showMOBASpecs();
    void showCPUSpecs();
    void showGPUSpecs();
    void showPSUSpecs();
    void showRAMSpecs();
    void showStorageSpecs();
    void resetSpecs();
    //void loadFileToBuild();

private:
    QTabWidget *tab;
    QWidget *window;
    QWidget *window2;
    QRect screenGeometry;
    QGridLayout *layout;
    QFormLayout *layout2;
    QHBoxLayout *layoutMOBA;
    QHBoxLayout *layoutCPU;
    QHBoxLayout *layoutGPU;
    QHBoxLayout *layoutPSU;
    QHBoxLayout *layoutRAM;
    QHBoxLayout *layoutStorage;
    QLabel *mobaLabel;
    QLabel *cpuLabel;
    QLabel *gpuLabel;
    QLabel *psuLabel;
    QLabel *ramLabel;
    QLabel *storageLabel;
    QComboBox *mobaComboBox;
    QComboBox *cpuComboBox;
    QComboBox *gpuComboBox;
    QComboBox *psuComboBox;
    QComboBox *ramComboBox;
    QComboBox *storageComboBox;
    QPushButton *insertMOBA;
    QPushButton *insertCPU;
    QPushButton *insertGPU;
    QPushButton *insertPSU;
    QPushButton *insertRAM;
    QPushButton *insertStorage;
    QSizePolicy comboboxPolicy;
    QFormLayout *layout3;
    QHBoxLayout *buttonsLayout;
    QTableWidget *build;
    QPushButton *mobaSpecs;
    QPushButton *cpuSpecs;
    QPushButton *gpuSpecs;
    QPushButton *psuSpecs;
    QPushButton *ramSpecs;
    QPushButton *storageSpecs;
    QPushButton *removeMOBA;
    QPushButton *removeCPU;
    QPushButton *removeGPU;
    QPushButton *removePSU;
    QPushButton *removeRAM;
    QPushButton *removeStorage;
    QStringList *horizontalHeaders;
    QStringList *verticalHeaders;
    QSizePolicy headersPolicy;
    QPushButton *calculate;
    QPushButton *saveBuild;
    QPushButton *loadBuild;
    QPushButton *discardBuild;
    QFormLayout *specLayout;
    QLabel *lengthLabel;
    QLabel *heightLabel;
    QLabel *nameLabel;
    QLabel *manufacturerLabel;
    QLabel *priceLabel;
    QLabel *powerconsumptionLabel;
    QFormLayout *componentsSpecsLayout;
    QLabel *componentNameLabel;
    QLabel *componentLengthLabel;
    QLabel *componentHeightLabel;
    QLabel *componentPriceLabel;
    QLabel *componentPowerConsumptionLabel;
    QLabel *componentManufacturerLabel;
    QGridLayout *layout4;
    QFormLayout *layout5;
    QHBoxLayout *managementButtonsLayout;
    QVBoxLayout *specLayout2;
    QLineEdit *searchBox;
    QListWidget *componentsList;
    QPushButton *addComponent;
    QPushButton *removeComponent;
    QPushButton *editComponent;
    QLabel *lengthLabel2;
    QLabel *heightLabel2;
    QLabel *nameLabel2;
    QLabel *manufacturerLabel2;
    QLabel *priceLabel2;
    QLabel *powerconsumptionLabel2;
    cvector<PC_Parts*> componenti;
    bool load(QString path);
    std::string removeZero(std::string);
    void calculateTotal();
};

#endif // MAINWINDOW_H
