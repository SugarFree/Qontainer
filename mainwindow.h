#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QSize>
#include <QTableWidget>
#include <QHeaderView>
#include <QDesktopWidget>
#include <QLineEdit>
#include <QListView>
#include "vector.h"
#include "pc_parts.h"
#include "cpu.h"
#include "gpu.h"
#include "moba.h"
#include "psu.h"
#include "ram.h"
#include "storage.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent=nullptr);

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
    QStringList *horizontalHeaders;
    QStringList *verticalHeaders;
    QSizePolicy headersPolicy;
    QPushButton *saveBuild;
    QPushButton *discardBuild;
    QVBoxLayout *specLayout;
    QLabel *widthLabel;
    QLabel *heightLabel;
    QLabel *nameLabel;
    QLabel *manufacturerLabel;
    QLabel *priceLabel;
    QLabel *powerconsumptionLabel;
    QGridLayout *layout4;
    QFormLayout *layout5;
    QHBoxLayout *managementButtonsLayout;
    QVBoxLayout *specLayout2;
    QLineEdit *searchBox;
    QListView *componentsList;
    QPushButton *addComponent;
    QPushButton *removeComponent;
    QPushButton *editComponent;
    QLabel *widthLabel2;
    QLabel *heightLabel2;
    QLabel *nameLabel2;
    QLabel *manufacturerLabel2;
    QLabel *priceLabel2;
    QLabel *powerconsumptionLabel2;
    vector<PC_Parts> pc_parts;
};

#endif // MAINWINDOW_H
