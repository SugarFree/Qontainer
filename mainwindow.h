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
#include <QRegExp>
#include <QAction>
#include <QDialog>
#include <QSpinBox>
#include <QCheckBox>
#include <QMenuBar>
#include <QMainWindow>
#include <QDebug>
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


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

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
    void showMOBASpecs();
    void showCPUSpecs();
    void showGPUSpecs();
    void showPSUSpecs();
    void showRAMSpecs();
    void showStorageSpecs();
    void resetSpecs();
    void searchComponents(QString);
    void removeComponents();
    void editComponentsSpecs();
    void resetEditSpecs();
    void saveComponentsChanges();
    void discardComponentsChanges();
    void addComponents();
    void newComponentEdit(QString);
    void saveNewComponent(QString);
    void load();
    void save();
    void loadFileToBuild();
    void saveBuildToFile();

private:
    QTabWidget *tab;
    QWidget *window;
    QWidget *window2;
    QMenuBar *menuBar;
    QMenuBar *menuBar2;
    QMenu *saveMenu;
    QMenu *loadMenu;
    QMenu *saveMenu2;
    QMenu *loadMenu2;
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
    QFormLayout *specLayout2;
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
    QFormLayout *componentsSpecsLayout2;
    QLineEdit *componentNameLine;
    QSpinBox *componentLengthSpin;
    QSpinBox *componentHeightSpin;
    QDoubleSpinBox *componentPriceSpin;
    QSpinBox *componentPowerConsumptionSpin;
    QLineEdit *componentManufacturerLine;
    QLabel *mobaSocketLabel;
    QLabel *mobaFormFactorLabel;
    QLabel *mobaRAMSlotsLabel;
    QLabel *mobaMaxRAMLabel;
    QLabel *mobaConnectorsLabel;
    QLabel *cpuSpeedLabel;
    QLabel *cpuCoresLabel;
    QLabel *cpux64bitLabel;
    QLabel *cpuSocketLabel;
    QLabel *cpuIntegratedGraphicsLabel;
    QLabel *gpuTypeLabel;
    QLabel *gpuMemorySizeLabel;
    QLabel *gpuPerformanceLabel;
    QLabel *gpuClockLabel;
    QLabel *gpuInterfaceLabel;
    QLabel *gpuConnectorsLabel;
    QLabel *gpuSupplementaryPowerLabel;
    QLabel *psuFormFactorLabel;
    QLabel *psuWattageLabel;
    QLabel *psuEfficiencyCertificationLabel;
    QLabel *psuModularityLabel;
    QLabel *psuSupplementaryPowerLabel;
    QLabel *ramSpeedLabel;
    QLabel *ramTypeLabel;
    QLabel *ramSizeLabel;
    QLabel *storageTypeLabel;
    QLabel *storageRPMLabel;
    QLabel *storageSizeLabel;
    QLabel *storageInterfaceLabel;
    QLabel *storageFormFactorLabel;
    QLabel *storageSpeedLabel;
    QLineEdit *mobaMOBASocketLine;
    QLineEdit *mobaMOBAFormFactorLine;
    QSpinBox *mobaMOBARAMSlotsSpin;
    QSpinBox *mobaMOBAmaxRAMSpin;
    QLineEdit *mobaMOBAConnectorsLine;
    QDoubleSpinBox *cpuCPUSpeedSpin;
    QSpinBox *cpuCPUCoresSpin;
    QCheckBox *cpuCPUx64bitCheck;
    QCheckBox *cpuCPUIntegratedGraphicCheck;
    QLineEdit *cpuCPUSocketLine;
    QLineEdit *gpuGPUTypeLine;
    QSpinBox *gpuGPUMemorySizeSpin;
    QDoubleSpinBox *gpuGPUPerformanceSpin;
    QSpinBox *gpuGPUClockSpin;
    QLineEdit *gpuGPUInterfaceLine;
    QLineEdit *gpuGPUConnectorsLine;
    QCheckBox *gpuGPUSupplementaryPowerCheck;
    QLineEdit *psuPSUFormFactorLine;
    QSpinBox *psuPSUWattageSpin;
    QLineEdit *psuPSUEfficiencyCertificationLine;
    QLineEdit *psuPSUModularityLine;
    QCheckBox *psuPSUSupplementaryPowerCheck;
    QSpinBox *ramRAMSpeedSpin;
    QLineEdit *ramRAMTypeLine;
    QSpinBox *ramRAMSizeSpin;
    QLineEdit *storageStorageTypeLine;
    QSpinBox *storageStorageRPMSpin;
    QSpinBox *storageStorageSizeSpin;
    QLineEdit *storageStorageInterfaceLine;
    QDoubleSpinBox *storageStorageFormFactorSpin;
    QSpinBox *storageStorageSpeedSpin;
    QPushButton *saveChanges;
    QPushButton *discardChanges;
    QDialog *componentType;
    QPushButton *saveComponent;
    QPushButton *discardComponent;
    cvector<PC_Parts*> componenti;
    cvector<QString*> componentsNames;
    std::string removeZero(std::string);
    void calculateTotal();
    void hideAll();
    void specLabels(QString);
    void basicSpecs(unsigned int);
};

#endif // MAINWINDOW_H
