#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    tab=new QTabWidget();
    window=new QWidget(tab);
    window2=new QWidget(tab);
    tab->addTab(window, "Build");
    tab->addTab(window2, "Gestione componenti");
    layout=new QGridLayout(window);
    window->setLayout(layout);
    layout2=new QFormLayout(window);
    layout->addLayout(layout2, 0, 0);
    layoutMOBA=new QHBoxLayout(window);
    layoutCPU=new QHBoxLayout(window);
    layoutGPU=new QHBoxLayout(window);
    layoutPSU=new QHBoxLayout(window);
    layoutRAM=new QHBoxLayout(window);
    layoutStorage=new QHBoxLayout(window);
    comboboxPolicy.setHorizontalPolicy(QSizePolicy::Expanding);
    comboboxPolicy.setVerticalPolicy(QSizePolicy::Expanding);

    insertMOBA=new QPushButton("--->");
    insertCPU=new QPushButton("--->");
    insertGPU=new QPushButton("--->");
    insertPSU=new QPushButton("--->");
    insertRAM=new QPushButton("--->");
    insertStorage=new QPushButton("--->");

    mobaLabel=new QLabel("MOBA:");
    mobaComboBox=new QComboBox();
    cpuLabel=new QLabel("CPU:");
    cpuComboBox=new QComboBox();
    gpuLabel=new QLabel("GPU:");
    gpuComboBox=new QComboBox();
    psuLabel=new QLabel("PSU:");
    psuComboBox=new QComboBox();
    ramLabel=new QLabel("RAM:");
    ramComboBox=new QComboBox();
    storageLabel=new QLabel("Storage:");
    storageComboBox=new QComboBox();

    layoutMOBA->addWidget(mobaComboBox);
    layoutMOBA->addWidget(insertMOBA);
    layout2->addRow(mobaLabel);
    layout2->addRow(layoutMOBA);
    mobaComboBox->setSizePolicy(comboboxPolicy);

    layoutCPU->addWidget(cpuComboBox);
    layoutCPU->addWidget(insertCPU);
    layout2->addRow(cpuLabel);
    layout2->addRow(layoutCPU);
    cpuComboBox->setSizePolicy(comboboxPolicy);

    layoutGPU->addWidget(gpuComboBox);
    layoutGPU->addWidget(insertGPU);
    layout2->addRow(gpuLabel);
    layout2->addRow(layoutGPU);
    gpuComboBox->setSizePolicy(comboboxPolicy);

    layoutPSU->addWidget(psuComboBox);
    layoutPSU->addWidget(insertPSU);
    layout2->addRow(psuLabel);
    layout2->addRow(layoutPSU);
    psuComboBox->setSizePolicy(comboboxPolicy);

    layoutRAM->addWidget(ramComboBox);
    layoutRAM->addWidget(insertRAM);
    layout2->addRow(ramLabel);
    layout2->addRow(layoutRAM);
    ramComboBox->setSizePolicy(comboboxPolicy);

    layoutStorage->addWidget(storageComboBox);
    layoutStorage->addWidget(insertStorage);
    layout2->addRow(storageLabel);
    layout2->addRow(layoutStorage);
    storageComboBox->setSizePolicy(comboboxPolicy);

    layout3=new QFormLayout(window);
    layout->addLayout(layout3, 0, 1);
    buttonsLayout=new QHBoxLayout(window);
    build=new QTableWidget(6, 5);
    build->setMinimumSize(window->sizeHint());
    build->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    build->setShowGrid(false);
    build->setIndexWidget(build->model()->index(0,3), new QPushButton("≡"));
    build->setIndexWidget(build->model()->index(0,4), new QPushButton("-"));
    build->setIndexWidget(build->model()->index(1,3), new QPushButton("≡"));
    build->setIndexWidget(build->model()->index(1,4), new QPushButton("-"));
    build->setIndexWidget(build->model()->index(2,3), new QPushButton("≡"));
    build->setIndexWidget(build->model()->index(2,4), new QPushButton("-"));
    build->setIndexWidget(build->model()->index(3,3), new QPushButton("≡"));
    build->setIndexWidget(build->model()->index(3,4), new QPushButton("-"));
    build->setIndexWidget(build->model()->index(4,3), new QPushButton("≡"));
    build->setIndexWidget(build->model()->index(4,4), new QPushButton("-"));
    build->setIndexWidget(build->model()->index(5,3), new QPushButton("≡"));
    build->setIndexWidget(build->model()->index(5,4), new QPushButton("-"));
    build->setIndexWidget(build->model()->index(6,3), new QPushButton("≡"));
    build->setIndexWidget(build->model()->index(6,4), new QPushButton("-"));
    horizontalHeaders=new QStringList();
    horizontalHeaders->append("Componente");
    horizontalHeaders->append("Rating");
    horizontalHeaders->append("Prezzo");
    horizontalHeaders->append("Mostra specifiche");
    horizontalHeaders->append("Rimuovi componente");
    build->setHorizontalHeaderLabels(*horizontalHeaders);
    verticalHeaders=new QStringList();
    verticalHeaders->append("MOBA");
    verticalHeaders->append("CPU");
    verticalHeaders->append("GPU");
    verticalHeaders->append("PSU");
    verticalHeaders->append("RAM");
    verticalHeaders->append("Storage");
    build->setVerticalHeaderLabels(*verticalHeaders);
    saveBuild=new QPushButton("Save Build");
    discardBuild=new QPushButton("Discard Build");
    buttonsLayout->addWidget(saveBuild);
    buttonsLayout->addWidget(discardBuild);
    layout3->addRow(build);
    layout3->addRow(buttonsLayout);
    layout3->setVerticalSpacing(30);

    specLayout=new QVBoxLayout(window);
    layout->addLayout(specLayout, 0, 2);
    widthLabel=new QLabel("Larghezza: ");
    heightLabel=new QLabel("Altezza: ");
    nameLabel=new QLabel("Nome componente: ");
    manufacturerLabel=new QLabel("Produttore: ");
    priceLabel=new QLabel("Prezzo: ");
    powerconsumptionLabel=new QLabel("Consumo energetico: ");
    specLayout->addWidget(nameLabel);
    specLayout->addWidget(manufacturerLabel);
    specLayout->addWidget(widthLabel);
    specLayout->addWidget(heightLabel);
    specLayout->addWidget(priceLabel);
    specLayout->addWidget(powerconsumptionLabel);

    layout4=new QGridLayout(window2);
    window2->setLayout(layout4);
    layout5=new QFormLayout(window2);
    layout4->addLayout(layout5, 0, 0);
    managementButtonsLayout=new QHBoxLayout(window2);
    searchBox=new QLineEdit(window2);
    componentsList=new QListView(window2);
    componentsList->setMaximumWidth(750);
    componentsList->setMinimumHeight(450);
    searchBox->setMaximumWidth(750);
    addComponent=new QPushButton("Aggiungi componente");
    removeComponent=new QPushButton("Rimuovi componente");
    editComponent=new QPushButton("Modifica componente");
    managementButtonsLayout->addWidget(addComponent);
    managementButtonsLayout->addWidget(removeComponent);
    managementButtonsLayout->addWidget(editComponent);
    managementButtonsLayout->setContentsMargins(0, 0, 38, 0);
    layout5->addRow(searchBox);
    layout5->addRow(componentsList);
    layout5->addRow(managementButtonsLayout);

    specLayout2=new QVBoxLayout(window2);
    layout4->addLayout(specLayout2, 0, 1);
    specLayout2->setContentsMargins(0, 0, 850, 0);
    widthLabel2=new QLabel("Larghezza: ");
    heightLabel2=new QLabel("Altezza: ");
    nameLabel2=new QLabel("Nome componente: ");
    manufacturerLabel2=new QLabel("Produttore: ");
    priceLabel2=new QLabel("Prezzo: ");
    powerconsumptionLabel2=new QLabel("Consumo energetico: ");
    specLayout2->addWidget(nameLabel2);
    specLayout2->addWidget(manufacturerLabel2);
    specLayout2->addWidget(widthLabel2);
    specLayout2->addWidget(heightLabel2);
    specLayout2->addWidget(priceLabel2);
    specLayout2->addWidget(powerconsumptionLabel2);

    window->setMinimumSize(1800, 500);
    window2->setMinimumSize(1000, 500);
    tab->setMinimumSize(1800, 500);
    screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-tab->width()) / 2;
    int y = (screenGeometry.height()-tab->height()) / 2;
    tab->move(x, y);
    tab->show();
}
