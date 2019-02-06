#include "mainwindow.h"
//#include "ui_mainwindow.h"

std::string MainWindow::removeZero(std::string str) {
    int j=0;
    while(str[j]!=',')
        j++;
    str.erase(j+3, str.size());
    return str;
}

void MainWindow::mobaToBuild() {
    QString mobaName=mobaComboBox->currentText();
    build->setItem(0, 0, new QTableWidgetItem(mobaName));
    for(unsigned int i=0; i!=componenti.getSize(); ++i) {
        if(dynamic_cast<MOBA*>(componenti[i])!=nullptr) {
            if(componenti[i]->getName()==mobaName) {
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString price2=QString::fromStdString(price);
                build->setItem(0, 1, new QTableWidgetItem(QString::number(componenti[i]->Rating())));
                build->setItem(0, 2, new QTableWidgetItem(price2));
            }
        }
    }
    (build->item(0, 1))->setTextAlignment(Qt::AlignCenter);
    (build->item(0, 2))->setTextAlignment(Qt::AlignCenter);
    (build->item(0, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(0, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(0, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
}

void MainWindow::cpuToBuild() {
    QString cpuName=cpuComboBox->currentText();
    build->setItem(1, 0, new QTableWidgetItem(cpuName));
    for(unsigned int i=0; i!=componenti.getSize(); ++i) {
        if(dynamic_cast<CPU*>(componenti[i])!=nullptr) {
            if(componenti[i]->getName()==cpuName) {
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString price2=QString::fromStdString(price);
                build->setItem(1, 1, new QTableWidgetItem(QString::number(componenti[i]->Rating())));
                build->setItem(1, 2, new QTableWidgetItem(price2));
            }
        }
    }
    (build->item(1, 1))->setTextAlignment(Qt::AlignCenter);
    (build->item(1, 2))->setTextAlignment(Qt::AlignCenter);
    (build->item(1, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(1, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(1, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
}

void MainWindow::gpuToBuild() {
    QString gpuName=gpuComboBox->currentText();
    build->setItem(2, 0, new QTableWidgetItem(gpuName));
    for(unsigned int i=0; i!=componenti.getSize(); ++i) {
        if(dynamic_cast<GPU*>(componenti[i])!=nullptr) {
            if(componenti[i]->getName()==gpuName) {
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString price2=QString::fromStdString(price);
                build->setItem(2, 1, new QTableWidgetItem(QString::number(componenti[i]->Rating())));
                build->setItem(2, 2, new QTableWidgetItem(price2));
            }
        }
    }
    (build->item(2, 1))->setTextAlignment(Qt::AlignCenter);
    (build->item(2, 2))->setTextAlignment(Qt::AlignCenter);
    (build->item(2, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(2, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(2, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
}

void MainWindow::psuToBuild() {
    QString psuName=psuComboBox->currentText();
    build->setItem(3, 0, new QTableWidgetItem(psuName));
    for(unsigned int i=0; i!=componenti.getSize(); ++i) {
        if(dynamic_cast<PSU*>(componenti[i])!=nullptr) {
            if(componenti[i]->getName()==psuName) {
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString price2=QString::fromStdString(price);
                build->setItem(3, 1, new QTableWidgetItem(QString::number(componenti[i]->Rating())));
                build->setItem(3, 2, new QTableWidgetItem(price2));
            }
        }
    }
    (build->item(3, 1))->setTextAlignment(Qt::AlignCenter);
    (build->item(3, 2))->setTextAlignment(Qt::AlignCenter);
    (build->item(3, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(3, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(3, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
}

void MainWindow::ramToBuild() {
    QString ramName=ramComboBox->currentText();
    build->setItem(4, 0, new QTableWidgetItem(ramName));
    for(unsigned int i=0; i!=componenti.getSize(); ++i) {
        if(dynamic_cast<RAM*>(componenti[i])!=nullptr) {
            if(componenti[i]->getName()==ramName) {
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString price2=QString::fromStdString(price);
                build->setItem(4, 1, new QTableWidgetItem(QString::number(componenti[i]->Rating())));
                build->setItem(4, 2, new QTableWidgetItem(price2));
            }
        }
    }
    (build->item(4, 1))->setTextAlignment(Qt::AlignCenter);
    (build->item(4, 2))->setTextAlignment(Qt::AlignCenter);
    (build->item(4, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(4, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(4, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
}

void MainWindow::storageToBuild() {
    QString storageName=storageComboBox->currentText();
    build->setItem(5, 0, new QTableWidgetItem(storageName));
    for(unsigned int i=0; i!=componenti.getSize(); ++i) {
        if(dynamic_cast<Storage*>(componenti[i])!=nullptr) {
            if(componenti[i]->getName()==storageName) {
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString price2=QString::fromStdString(price);
                build->setItem(5, 1, new QTableWidgetItem(QString::number(componenti[i]->Rating())));
                build->setItem(5, 2, new QTableWidgetItem(price2));
            }
        }
    }
    (build->item(5, 1))->setTextAlignment(Qt::AlignCenter);
    (build->item(5, 2))->setTextAlignment(Qt::AlignCenter);
    (build->item(5, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(5, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(5, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
}

void MainWindow::calculateTotal() {
    if(build->item(0, 0)!=nullptr || build->item(1, 0)!=nullptr || build->item(2, 0)!=nullptr ||
       build->item(3, 0)!=nullptr || build->item(4, 0)!=nullptr || build->item(5, 0)!=nullptr) {
        QTableWidgetItem *mobaTableWidget=new QTableWidgetItem();
        mobaTableWidget=(build->item(0, 0));
        QString mobaName;
        if(mobaTableWidget!=nullptr)
            mobaName=mobaTableWidget->text();
        else
            mobaName="Non definito";
        QTableWidgetItem *cpuTableWidget=new QTableWidgetItem();
        cpuTableWidget=(build->item(1, 0));
        QString cpuName;
        if(cpuTableWidget!=nullptr)
            cpuName=cpuTableWidget->text();
        else
            cpuName="Non definito";
        QTableWidgetItem *gpuTableWidget=new QTableWidgetItem();
        gpuTableWidget=(build->item(2, 0));
        QString gpuName;
        if(gpuTableWidget!=nullptr)
            gpuName=gpuTableWidget->text();
        else
            gpuName="Non definito";
        QTableWidgetItem *psuTableWidget=new QTableWidgetItem();
        psuTableWidget=(build->item(3, 0));
        QString psuName;
        if(psuTableWidget!=nullptr)
            psuName=psuTableWidget->text();
        else
            psuName="Non definito";
        QTableWidgetItem *ramTableWidget=new QTableWidgetItem();
        ramTableWidget=(build->item(4, 0));
        QString ramName;
        if(ramTableWidget!=nullptr)
            ramName=ramTableWidget->text();
        else
            ramName="Non definito";
        QTableWidgetItem *storageTableWidget=new QTableWidgetItem();
        storageTableWidget=(build->item(5, 0));
        QString storageName;
        if(storageTableWidget!=nullptr)
            storageName=storageTableWidget->text();
        else
            storageName="Non definito";
        int totalRating=0, j=0;
        double totalPrice=0;
        for(unsigned int i=0; i!=componenti.getSize(); i++) {
            if(componenti[i]->getName()==mobaName || componenti[i]->getName()==cpuName || componenti[i]->getName()==gpuName ||
            componenti[i]->getName()==psuName || componenti[i]->getName()==ramName || componenti[i]->getName()==storageName) {
                totalRating=totalRating+componenti[i]->Rating();
                totalPrice=totalPrice+componenti[i]->getPrice();
                j++;
            }
        }
        totalRating=totalRating/j;
        std::string totalPriceStr=std::to_string(totalPrice);
        totalPriceStr=removeZero(totalPriceStr);
        QString totalPriceQStr=QString::fromStdString(totalPriceStr);
        build->setItem(6, 1, new QTableWidgetItem(QString::number(totalRating)));
        build->setItem(6, 2, new QTableWidgetItem(totalPriceQStr));
        (build->item(6, 1))->setTextAlignment(Qt::AlignCenter);
        (build->item(6, 2))->setTextAlignment(Qt::AlignCenter);
    }
}

void MainWindow::removeMOBAFromBuild() {
    if((build->item(0, 0))!=nullptr) {
        build->setItem(0, 0, nullptr);
        build->setItem(0, 1, nullptr);
        build->setItem(0, 2, nullptr);
    }
    calculateTotal();
}

bool MainWindow::load(QString path) {
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray json=file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(json);
    QJsonArray array = document.object().value("pc_parts").toArray();
    if(!array.isEmpty()) {
        foreach(const QJsonValue& j, array) {
            QString component_type=QString(j.toObject().value("component_type").toString());
            if(component_type=="MOBA")
                componenti.push_back(new MOBA(j.toObject().value("length").toInt(),
                                              j.toObject().value("height").toInt(),
                                              j.toObject().value("name").toString(),
                                              j.toObject().value("manufacturer").toString(),
                                              j.toObject().value("price").toDouble(),
                                              j.toObject().value("power_consumption").toInt(),
                                              j.toObject().value("moba_socket").toString(),
                                              j.toObject().value("form_factor").toString(),
                                              j.toObject().value("RAM_slots").toInt(),
                                              j.toObject().value("max_RAM").toInt(),
                                              j.toObject().value("connectors").toString()
                                              ));
            else if(component_type=="CPU")
                componenti.push_back(new CPU(j.toObject().value("length").toInt(),
                                             j.toObject().value("height").toInt(),
                                             j.toObject().value("name").toString(),
                                             j.toObject().value("manufacturer").toString(),
                                             j.toObject().value("price").toDouble(),
                                             j.toObject().value("power_consumption").toInt(),
                                             j.toObject().value("cpu_speed").toDouble(),
                                             j.toObject().value("cores").toInt(),
                                             j.toObject().value("x64bit").toBool(),
                                             j.toObject().value("cpu_socket").toString(),
                                             j.toObject().value("integrated_graphics").toBool()
                                             ));
            else if(component_type=="GPU")
                componenti.push_back(new GPU(j.toObject().value("length").toInt(),
                                             j.toObject().value("height").toInt(),
                                             j.toObject().value("name").toString(),
                                             j.toObject().value("manufacturer").toString(),
                                             j.toObject().value("price").toDouble(),
                                             j.toObject().value("power_consumption").toInt(),
                                             j.toObject().value("type").toString(),
                                             j.toObject().value("memory_size").toInt(),
                                             j.toObject().value("performance").toDouble(),
                                             j.toObject().value("clock").toDouble(),
                                             j.toObject().value("interface").toString(),
                                             j.toObject().value("connectors").toString(),
                                             j.toObject().value("supplementary_power").toBool()
                                             ));
            else if(component_type=="PSU")
                componenti.push_back(new PSU(j.toObject().value("length").toInt(),
                                             j.toObject().value("height").toInt(),
                                             j.toObject().value("name").toString(),
                                             j.toObject().value("manufacturer").toString(),
                                             j.toObject().value("price").toDouble(),
                                             j.toObject().value("power_consumption").toInt(),
                                             j.toObject().value("form_factor").toString(),
                                             j.toObject().value("wattage").toInt(),
                                             j.toObject().value("efficiency_certification").toString(),
                                             j.toObject().value("modularity").toString(),
                                             j.toObject().value("supplementary_power").toBool()
                                             ));
            else if(component_type=="RAM")
                componenti.push_back(new RAM(j.toObject().value("length").toInt(),
                                             j.toObject().value("height").toInt(),
                                             j.toObject().value("name").toString(),
                                             j.toObject().value("manufacturer").toString(),
                                             j.toObject().value("price").toDouble(),
                                             j.toObject().value("power_consumption").toInt(),
                                             j.toObject().value("ram_speed").toInt(),
                                             j.toObject().value("type").toString(),
                                             j.toObject().value("size").toInt()
                                             ));
            else if(component_type=="Storage")
                componenti.push_back(new Storage(j.toObject().value("length").toInt(),
                                                 j.toObject().value("height").toInt(),
                                                 j.toObject().value("name").toString(),
                                                 j.toObject().value("manufacturer").toString(),
                                                 j.toObject().value("price").toDouble(),
                                                 j.toObject().value("power_consumption").toInt(),
                                                 j.toObject().value("type").toString(),
                                                 j.toObject().value("rpm").toInt(),
                                                 j.toObject().value("size").toInt(),
                                                 j.toObject().value("interface").toString(),
                                                 j.toObject().value("form_factor").toDouble(),
                                                 j.toObject().value("speed").toInt()
                                                 ));
        }
        for(unsigned int i=0; i!=componenti.getSize(); ++i) {
            if(dynamic_cast<MOBA*>(componenti[i])!=nullptr) {
                mobaComboBox->addItem(componenti[i]->getName());
                componentsList->addItem(componenti[i]->getName());
            }
            else if(dynamic_cast<CPU*>(componenti[i])!=nullptr) {
                cpuComboBox->addItem(componenti[i]->getName());
                componentsList->addItem(componenti[i]->getName());
            }
            else if(dynamic_cast<GPU*>(componenti[i])!=nullptr) {
                gpuComboBox->addItem(componenti[i]->getName());
                componentsList->addItem(componenti[i]->getName());
            }
            else if(dynamic_cast<PSU*>(componenti[i])!=nullptr) {
                psuComboBox->addItem(componenti[i]->getName());
                componentsList->addItem(componenti[i]->getName());
            }
            else if(dynamic_cast<RAM*>(componenti[i])!=nullptr) {
                ramComboBox->addItem(componenti[i]->getName());
                componentsList->addItem(componenti[i]->getName());
            }
            else if(dynamic_cast<Storage*>(componenti[i])!=nullptr) {
                storageComboBox->addItem(componenti[i]->getName());
                componentsList->addItem(componenti[i]->getName());
            }
        }
        return true;
    }
    return false;
}


MainWindow::MainWindow(QWidget *parent): QWidget(parent) {
    tab=new QTabWidget();
    window=new QWidget(tab);
    window2=new QWidget(tab);
    tab->addTab(window, "Build");
    tab->addTab(window2, "Gestione componenti");
    layout=new QGridLayout();
    window->setLayout(layout);
    layout2=new QFormLayout();
    layout->addLayout(layout2, 0, 0);
    layoutMOBA=new QHBoxLayout();
    layoutCPU=new QHBoxLayout();
    layoutGPU=new QHBoxLayout();
    layoutPSU=new QHBoxLayout();
    layoutRAM=new QHBoxLayout();
    layoutStorage=new QHBoxLayout();
    comboboxPolicy.setHorizontalPolicy(QSizePolicy::Expanding);

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
    layout2->setContentsMargins(0, 0, 20, 0);

    layout3=new QFormLayout();
    layout->addLayout(layout3, 0, 1);
    buttonsLayout=new QHBoxLayout();
    build=new QTableWidget(7, 5);
    build->setMinimumHeight(237);
    build->setMinimumWidth(787);
    build->setColumnWidth(0, 250);
    build->setColumnWidth(1, 70);
    build->setColumnWidth(2, 75);
    build->setColumnWidth(3, 150);
    build->setColumnWidth(4, 175);
    build->setShowGrid(false);
    removeMOBA=new QPushButton("-");
    build->setIndexWidget(build->model()->index(0,3), new QPushButton("≡"));
    build->setIndexWidget(build->model()->index(0,4), removeMOBA);
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
    verticalHeaders->append("Totale");
    build->setVerticalHeaderLabels(*verticalHeaders);

    calculate=new QPushButton("Calcola totale");
    saveBuild=new QPushButton("Salva Build");
    discardBuild=new QPushButton("Scarta Build");
    buttonsLayout->addWidget(calculate);
    buttonsLayout->addWidget(saveBuild);
    buttonsLayout->addWidget(discardBuild);
    layout3->addRow(build);
    layout3->addRow(buttonsLayout);
    layout3->setVerticalSpacing(30);
    layout3->setContentsMargins(0, 0, 20, 0);

    specLayout=new QVBoxLayout();
    layout->addLayout(specLayout, 0, 2);
    lengthLabel=new QLabel("Larghezza: ");
    heightLabel=new QLabel("Altezza: ");
    nameLabel=new QLabel("Nome componente: ");
    manufacturerLabel=new QLabel("Produttore: ");
    priceLabel=new QLabel("Prezzo: ");
    powerconsumptionLabel=new QLabel("Consumo energetico: ");
    specLayout->addWidget(nameLabel);
    specLayout->addWidget(manufacturerLabel);
    specLayout->addWidget(lengthLabel);
    specLayout->addWidget(heightLabel);
    specLayout->addWidget(priceLabel);
    specLayout->addWidget(powerconsumptionLabel);
    specLayout->setContentsMargins(0, 0, 300, 0);

    layout4=new QGridLayout();
    window2->setLayout(layout4);
    layout5=new QFormLayout();
    layout4->addLayout(layout5, 0, 0);
    managementButtonsLayout=new QHBoxLayout();
    searchBox=new QLineEdit(window2);
    componentsList=new QListWidget(window2);
    componentsList->setMaximumWidth(750);
    componentsList->setMinimumHeight(350);
    searchBox->setMaximumWidth(750);
    addComponent=new QPushButton("Aggiungi componente");
    removeComponent=new QPushButton("Rimuovi componente");
    editComponent=new QPushButton("Modifica componente");
    managementButtonsLayout->addWidget(addComponent);
    managementButtonsLayout->addWidget(removeComponent);
    managementButtonsLayout->addWidget(editComponent);
    managementButtonsLayout->setContentsMargins(0, 20, 188, 0);
    layout5->addRow(searchBox);
    layout5->addRow(componentsList);
    layout5->addRow(managementButtonsLayout);

    specLayout2=new QVBoxLayout();
    layout4->addLayout(specLayout2, 0, 1);
    lengthLabel2=new QLabel("Larghezza: ");
    heightLabel2=new QLabel("Altezza: ");
    nameLabel2=new QLabel("Nome componente: ");
    manufacturerLabel2=new QLabel("Produttore: ");
    priceLabel2=new QLabel("Prezzo: ");
    powerconsumptionLabel2=new QLabel("Consumo energetico: ");
    specLayout2->addWidget(nameLabel2);
    specLayout2->addWidget(manufacturerLabel2);
    specLayout2->addWidget(lengthLabel2);
    specLayout2->addWidget(heightLabel2);
    specLayout2->addWidget(priceLabel2);
    specLayout2->addWidget(powerconsumptionLabel2);
    specLayout2->setContentsMargins(0, 0, 700, 0);

    connect(insertMOBA, SIGNAL(clicked(bool)), this, SLOT(mobaToBuild()));
    connect(insertCPU, SIGNAL(clicked(bool)), this, SLOT(cpuToBuild()));
    connect(insertGPU, SIGNAL(clicked(bool)), this, SLOT(gpuToBuild()));
    connect(insertPSU, SIGNAL(clicked(bool)), this, SLOT(psuToBuild()));
    connect(insertRAM, SIGNAL(clicked(bool)), this, SLOT(ramToBuild()));
    connect(insertStorage, SIGNAL(clicked(bool)), this, SLOT(storageToBuild()));
    connect(calculate, SIGNAL(clicked(bool)), this, SLOT(calculateTotal()));
    connect(removeMOBA, SIGNAL(clicked(bool)), this, SLOT(removeMOBAFromBuild()));
    load("../Qontainer/database.json");
    tab->setMinimumSize(1800, 500);
    tab->setMaximumSize(1800, 500);
    tab->move(50, 200);
    tab->show();
}
