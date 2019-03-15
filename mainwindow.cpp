#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include <iostream>

std::string MainWindow::removeZero(std::string str) {
    str.erase(str.find(',')+3, str.size());
    return str;
}

void MainWindow::mobaToBuild() {
    if(mobaComboBox->currentText()!="") {
        QString mobaName=mobaComboBox->currentText();
        if(build->item(0, 0)!=nullptr && mobaName!=(build->item(0, 0))->text())
            resetSpecs();
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
        calculateTotal();
    }
}

void MainWindow::cpuToBuild() {
    if(cpuComboBox->currentText()!="") {
        QString cpuName=cpuComboBox->currentText();
        if(build->item(1, 0)!=nullptr && cpuName!=(build->item(1, 0))->text())
            resetSpecs();
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
        calculateTotal();
    }
}

void MainWindow::gpuToBuild() {
    if(gpuComboBox->currentText()!="") {
        QString gpuName=gpuComboBox->currentText();
        if(build->item(2, 0)!=nullptr && gpuName!=(build->item(2, 0))->text())
            resetSpecs();
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
        calculateTotal();
    }
}

void MainWindow::psuToBuild() {
    if(psuComboBox->currentText()!="") {
        QString psuName=psuComboBox->currentText();
        if(build->item(3, 0)!=nullptr && psuName!=(build->item(3, 0))->text())
            resetSpecs();
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
        calculateTotal();
    }
}

void MainWindow::ramToBuild() {
    if(ramComboBox->currentText()!="") {
        QString ramName=ramComboBox->currentText();
        if(build->item(4, 0)!=nullptr && ramName!=(build->item(4, 0))->text())
            resetSpecs();
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
        calculateTotal();
    }
}

void MainWindow::storageToBuild() {
    if(storageComboBox->currentText()!="") {
        QString storageName=storageComboBox->currentText();
        if(build->item(5, 0)!=nullptr && storageName!=(build->item(5, 0))->text())
            resetSpecs();
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
        calculateTotal();
    }
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
    else {
        build->setItem(6, 1, nullptr);
        build->setItem(6, 2, nullptr);
    }

}

void MainWindow::hideAll() {
  for(unsigned int i=0; i!=componentsList->count(); i++)
    componentsList->item(i)->setHidden(true);
}

void MainWindow::searchComponents(QString search_str) {
      hideAll();
      QList<QListWidgetItem*> matches (componentsList->findItems(search_str, Qt::MatchFlag::MatchContains));
      for(QListWidgetItem* item:matches)
          item->setHidden(false);
}

void MainWindow::removeComponents() {
    if(componentsList->currentItem()!=nullptr) {
        bool trovato=false;
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(componenti[i]->getName()==(componentsList->currentItem())->text()) {
                trovato=true;
                componentsList->takeItem(componentsList->currentRow());
                if(dynamic_cast<MOBA*>(componenti[i])!=nullptr)
                    mobaComboBox->removeItem(mobaComboBox->findText(componenti[i]->getName()));
                if(dynamic_cast<CPU*>(componenti[i])!=nullptr)
                    cpuComboBox->removeItem(cpuComboBox->findText(componenti[i]->getName()));
                if(dynamic_cast<GPU*>(componenti[i])!=nullptr)
                    gpuComboBox->removeItem(gpuComboBox->findText(componenti[i]->getName()));
                if(dynamic_cast<PSU*>(componenti[i])!=nullptr)
                    psuComboBox->removeItem(psuComboBox->findText(componenti[i]->getName()));
                if(dynamic_cast<RAM*>(componenti[i])!=nullptr)
                    ramComboBox->removeItem(ramComboBox->findText(componenti[i]->getName()));
                if(dynamic_cast<Storage*>(componenti[i])!=nullptr)
                    storageComboBox->removeItem(storageComboBox->findText(componenti[i]->getName()));
                if(build->item(0, 0)!=nullptr && componenti[i]->getName()==(build->item(0, 0)->text()))
                    removeMOBAFromBuild();
                if(build->item(1, 0)!=nullptr && componenti[i]->getName()==(build->item(1, 0)->text()))
                    removeCPUFromBuild();
                if(build->item(2, 0)!=nullptr && componenti[i]->getName()==(build->item(2, 0)->text()))
                    removeGPUFromBuild();
                if(build->item(3, 0)!=nullptr && componenti[i]->getName()==(build->item(3, 0)->text()))
                    removePSUFromBuild();
                if(build->item(4, 0)!=nullptr && componenti[i]->getName()==(build->item(4, 0)->text()))
                    removeRAMFromBuild();
                if(build->item(5, 0)!=nullptr && componenti[i]->getName()==(build->item(5, 0)->text()))
                    removeStorageFromBuild();
                componenti.erase(i);
            }
        }
    }
}

void MainWindow::resetEditSpecs() {
    componentNameLine->setText("");
    componentLengthLine->setText("");
    componentHeightLine->setText("");
    componentPriceLine->setText("");
    componentPowerConsumptionLine->setText("");
    componentManufacturerLine->setText("");
    specLayout2->removeRow(componentsSpecsLayout2);
}

void MainWindow::discardComponentsChanges() {
    resetEditSpecs();
    for(unsigned int i=0; i!=componentsList->count(); ++i) {
        QListWidgetItem *item=componentsList->item(i);
        auto flags=item->flags();
        flags.setFlag(Qt::ItemIsEnabled, true);
        item->setFlags(flags);
    }
}

void MainWindow::saveNewComponent() {

}

void MainWindow::newComponentEdit(QString type) {
    componentType->close();
    resetEditSpecs();
    for(unsigned int i=0; i!=componentsList->count(); ++i) {
        QListWidgetItem *item=componentsList->item(i);
        auto flags=item->flags();
        flags.setFlag(Qt::ItemIsEnabled, false);
        item->setFlags(flags);
    }
    if(type=="MOBA") {
        QLabel *mobaSocketLabel=new QLabel("Socket: ");
        QLabel *mobaFormFactorLabel=new QLabel("Form Factor: ");
        QLabel *mobaRAMSlotsLabel=new QLabel("Slot RAM: ");
        QLabel *mobaMaxRAMLabel=new QLabel("RAM massima supportata (GB): ");
        QLabel *mobaConnectorsLabel=new QLabel("Interfacce: ");
        mobaMOBASocketLine=new QLineEdit();
        mobaMOBAFormFactorLine=new QLineEdit();
        mobaMOBARAMSlotsLine=new QLineEdit();
        mobaMOBAmaxRAMLine=new QLineEdit();
        mobaMOBAConnectorsLine=new QLineEdit();
        componentsSpecsLayout2=new QFormLayout();
        saveComponent=new QPushButton("Salva nuovo componente");
        discardComponent=new QPushButton("Scarta nuovo componente");
        componentsSpecsLayout2->addRow(mobaSocketLabel, mobaMOBASocketLine);
        componentsSpecsLayout2->addRow(mobaFormFactorLabel, mobaMOBAFormFactorLine);
        componentsSpecsLayout2->addRow(mobaRAMSlotsLabel, mobaMOBARAMSlotsLine);
        componentsSpecsLayout2->addRow(mobaMaxRAMLabel, mobaMOBAmaxRAMLine);
        componentsSpecsLayout2->addRow(mobaConnectorsLabel, mobaMOBAConnectorsLine);
        componentsSpecsLayout2->addRow(saveComponent);
        componentsSpecsLayout2->addRow(discardComponent);
        componentsSpecsLayout2->setVerticalSpacing(25);
        specLayout2->addRow(componentsSpecsLayout2);
        connect(discardComponent, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
    }
    if(type=="CPU") {
        QLabel *SpeedLabel=new QLabel("Frequenza (GHz): ");
        QLabel *CoresLabel=new QLabel("Cores: ");
        QLabel *x64bitLabel=new QLabel("Supporto 64 bit: ");
        QLabel *cpuSocketLabel=new QLabel("Socket CPU: ");
        QLabel *IntegratedGraphicsLabel=new QLabel("Chip grafico integrato: ");
        cpuCPUSpeedLine=new QLineEdit();
        cpuCPUCoresLine=new QLineEdit();
        cpuCPUx64bitLine=new QLineEdit();
        cpuCPUSocketLine=new QLineEdit();
        cpuCPUIntegratedGraphicLine=new QLineEdit();
        componentsSpecsLayout2=new QFormLayout();
        saveComponent=new QPushButton("Salva nuovo componente");
        discardComponent=new QPushButton("Scarta nuovo componente");
        componentsSpecsLayout2->addRow(SpeedLabel, cpuCPUSpeedLine);
        componentsSpecsLayout2->addRow(CoresLabel, cpuCPUCoresLine);
        componentsSpecsLayout2->addRow(x64bitLabel, cpuCPUx64bitLine);
        componentsSpecsLayout2->addRow(cpuSocketLabel, cpuCPUSocketLine);
        componentsSpecsLayout2->addRow(IntegratedGraphicsLabel, cpuCPUIntegratedGraphicLine);
        componentsSpecsLayout2->addRow(saveComponent);
        componentsSpecsLayout2->addRow(discardComponent);
        componentsSpecsLayout2->setVerticalSpacing(25);
        specLayout2->addRow(componentsSpecsLayout2);
        connect(discardComponent, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
    }
    if(type=="GPU") {
        QLabel *gpuTypeLabel=new QLabel("Tipo: ");
        QLabel *gpuMemorySizeLabel=new QLabel("Memoria dedicata (GB): ");
        QLabel *gpuPerformanceLabel=new QLabel("TFLOPs: ");
        QLabel *gpuClockLabel=new QLabel("Clock (MHz): ");
        QLabel *gpuInterfaceLabel=new QLabel("Interfacce: ");
        QLabel *gpuConnectorsLabel=new QLabel("Porte: ");
        QLabel *gpuSupplementaryPowerLabel=new QLabel("Alimentazione supplementare richiesta: ");
        gpuGPUTypeLine=new QLineEdit();
        gpuGPUMemorySizeLine=new QLineEdit();
        gpuGPUPerformanceLine=new QLineEdit();
        gpuGPUClockLine=new QLineEdit();
        gpuGPUInterfaceLine=new QLineEdit();
        gpuGPUConnectorsLine=new QLineEdit();
        gpuGPUSupplementaryPowerLine=new QLineEdit();
        componentsSpecsLayout2=new QFormLayout();
        saveComponent=new QPushButton("Salva nuovo componente");
        discardComponent=new QPushButton("Scarta nuovo componente");
        componentsSpecsLayout2->addRow(gpuTypeLabel, gpuGPUTypeLine);
        componentsSpecsLayout2->addRow(gpuMemorySizeLabel, gpuGPUMemorySizeLine);
        componentsSpecsLayout2->addRow(gpuPerformanceLabel, gpuGPUPerformanceLine);
        componentsSpecsLayout2->addRow(gpuClockLabel, gpuGPUClockLine);
        componentsSpecsLayout2->addRow(gpuInterfaceLabel, gpuGPUInterfaceLine);
        componentsSpecsLayout2->addRow(gpuConnectorsLabel, gpuGPUConnectorsLine);
        componentsSpecsLayout2->addRow(gpuSupplementaryPowerLabel, gpuGPUSupplementaryPowerLine);
        componentsSpecsLayout2->addRow(saveComponent);
        componentsSpecsLayout2->addRow(discardComponent);
        componentsSpecsLayout2->setVerticalSpacing(25);
        specLayout2->addRow(componentsSpecsLayout2);
        connect(discardComponent, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
    }
    if(type=="PSU") {
        QLabel *psuFormFactorLabel=new QLabel("Form Factor: ");
        QLabel *psuWattageLabel=new QLabel("Wattaggio: ");
        QLabel *psuEfficiencyCertificationLabel=new QLabel("Certificazione di efficienza: ");
        QLabel *psuModularityLabel=new QLabel("Modularità: ");
        QLabel *psuSupplementaryPowerLabel=new QLabel("Predisposizione alimentazione supplementare: ");
        psuPSUFormFactorLine=new QLineEdit();
        psuPSUWattageLine=new QLineEdit();
        psuPSUEfficiencyCertificationLine=new QLineEdit();
        psuPSUModularityLine=new QLineEdit();
        psuPSUSupplementaryPowerLine=new QLineEdit();
        componentsSpecsLayout2=new QFormLayout();
        saveComponent=new QPushButton("Salva nuovo componente");
        discardComponent=new QPushButton("Scarta nuovo componente");
        componentsSpecsLayout2->addRow(psuFormFactorLabel, psuPSUFormFactorLine);
        componentsSpecsLayout2->addRow(psuEfficiencyCertificationLabel, psuPSUEfficiencyCertificationLine);
        componentsSpecsLayout2->addRow(psuWattageLabel, psuPSUWattageLine);
        componentsSpecsLayout2->addRow(psuModularityLabel, psuPSUModularityLine);
        componentsSpecsLayout2->addRow(psuSupplementaryPowerLabel, psuPSUSupplementaryPowerLine);
        componentsSpecsLayout2->addRow(saveComponent);
        componentsSpecsLayout2->addRow(discardComponent);
        componentsSpecsLayout2->setVerticalSpacing(25);
        specLayout2->addRow(componentsSpecsLayout2);
        connect(discardComponent, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
    }
    if(type=="RAM") {
        QLabel *ramSpeedLabel=new QLabel("Frequenza (MHz): ");
        QLabel *ramTypeLabel=new QLabel("Tipo: ");
        QLabel *ramSizeLabel=new QLabel("Capacità (GB): ");
        ramRAMSpeedLine=new QLineEdit();
        ramRAMTypeLine=new QLineEdit();
        ramRAMSizeLine=new QLineEdit();
        componentsSpecsLayout2=new QFormLayout();
        saveComponent=new QPushButton("Salva nuovo componente");
        discardComponent=new QPushButton("Scarta nuovo componente");
        componentsSpecsLayout2->addRow(ramSpeedLabel, ramRAMSpeedLine);
        componentsSpecsLayout2->addRow(ramTypeLabel, ramRAMTypeLine);
        componentsSpecsLayout2->addRow(ramSizeLabel, ramRAMSizeLine);
        componentsSpecsLayout2->addRow(saveComponent);
        componentsSpecsLayout2->addRow(discardComponent);
        componentsSpecsLayout2->setVerticalSpacing(25);
        specLayout2->addRow(componentsSpecsLayout2);
        connect(discardComponent, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
    }
    if(type=="Storage") {
        QLabel *storageTypeLabel=new QLabel("Tipo: ");
        QLabel *storageRPMLabel=new QLabel("RPM: ");
        QLabel *storageSizeLabel=new QLabel("Capacità (GB): ");
        QLabel *storageInterfaceLabel=new QLabel("Interfaccia: ");
        QLabel *storageFormFactorLabel=new QLabel("Form Factor: ");
        QLabel *storageSpeedLabel=new QLabel("Velocità trasferimento (MB/s): ");
        storageStorageTypeLine=new QLineEdit();
        storageStorageRPMLine=new QLineEdit();
        storageStorageSizeLine=new QLineEdit();
        storageStorageInterfaceLine=new QLineEdit();
        storageStorageFormFactorLine=new QLineEdit();
        storageStorageSpeedLine=new QLineEdit();
        componentsSpecsLayout2=new QFormLayout();
        saveComponent=new QPushButton("Salva nuovo componente");
        discardComponent=new QPushButton("Scarta nuovo componente");
        componentsSpecsLayout2->addRow(storageTypeLabel, storageStorageTypeLine);
        componentsSpecsLayout2->addRow(storageRPMLabel, storageStorageRPMLine);
        componentsSpecsLayout2->addRow(storageSizeLabel, storageStorageSizeLine);
        componentsSpecsLayout2->addRow(storageInterfaceLabel, storageStorageInterfaceLine);
        componentsSpecsLayout2->addRow(storageFormFactorLabel, storageStorageFormFactorLine);
        componentsSpecsLayout2->addRow(storageSpeedLabel, storageStorageSpeedLine);
        componentsSpecsLayout2->addRow(saveComponent);
        componentsSpecsLayout2->addRow(discardComponent);
        componentsSpecsLayout2->setVerticalSpacing(25);
        specLayout2->addRow(componentsSpecsLayout2);
        connect(discardComponent, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
    }
}

void MainWindow::addComponents() {
    componentType=new QDialog();
    QVBoxLayout *componentSelection=new QVBoxLayout(componentType);
    componentType->setLayout(componentSelection);
    QLabel *componentTypeLine=new QLabel(componentType);
    QComboBox *componentSelector=new QComboBox(componentType);
    QPushButton *okButton=new QPushButton(componentType);
    componentTypeLine->setText("Che tipo di componente vuoi aggiungere?");
    componentSelector->addItem("MOBA");
    componentSelector->addItem("CPU");
    componentSelector->addItem("GPU");
    componentSelector->addItem("PSU");
    componentSelector->addItem("RAM");
    componentSelector->addItem("Storage");
    okButton->setText("Ok");
    componentSelection->addWidget(componentTypeLine);
    componentSelection->addWidget(componentSelector);
    componentSelection->addWidget(okButton);
    componentSelection->setAlignment(componentSelection, Qt::AlignCenter);
    componentType->setFixedHeight(100);
    componentType->setFixedWidth(350);
    componentType->move(700, 400);
    componentType->show();
    connect(okButton, &QPushButton::clicked, this, [this, componentSelector]{newComponentEdit(componentSelector->currentText());});
}

void MainWindow::saveComponentsChanges() {
    QString componentName=(componentsList->currentItem())->text();
    bool trovato=false;
    for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
        if(!trovato && componenti[i]->getName()==componentName) {
            trovato=true;
            if(dynamic_cast<MOBA*>(componenti[i])!=nullptr) {
                MOBA* moba=static_cast<MOBA*>(componenti[i]);
                if((build->item(0, 0))!=nullptr && (build->item(0, 0))->text()==componentName)
                    removeMOBAFromBuild();
                if(componentNameLine->text()!=componenti[i]->getName()) {
                    mobaComboBox->setItemText(mobaComboBox->findText(componentName), componentNameLine->text());
                    componenti[i]->setName(componentNameLine->text());
                }
                if(componentLengthLine->text()!=QString::number(componenti[i]->getLength()))
                    componenti[i]->setLength((componentLengthLine->text()).toInt());
                if(componentHeightLine->text()!=QString::number(componenti[i]->getHeight()))
                    componenti[i]->setHeight((componentHeightLine->text()).toInt());
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                if(componentPriceLine->text()!=QString::fromStdString(price))
                    componenti[i]->setPrice((componentPriceLine->text()).toDouble());
                if(componentPowerConsumptionLine->text()!=QString::number(componenti[i]->getPowerConsumption()))
                    componenti[i]->setPowerConsumption((componentPowerConsumptionLine->text()).toInt());
                if(componentManufacturerLine->text()!=componenti[i]->getManufacturer())
                    componenti[i]->setManufacturer(componentManufacturerLine->text());
                if(mobaMOBASocketLine->text()!=moba->getMOBASocket())
                    moba->setMoba_socket(mobaMOBASocketLine->text());
                if(mobaMOBAFormFactorLine->text()!=moba->getForm_factor())
                    moba->setFormFactor(mobaMOBAFormFactorLine->text());
                if(mobaMOBARAMSlotsLine->text()!=QString::number(moba->getRAM_slots()))
                    moba->setRAM_slots((mobaMOBARAMSlotsLine->text()).toInt());
                if(mobaMOBAmaxRAMLine->text()!=QString::number(moba->getMax_RAM()))
                    moba->setMax_RAM((mobaMOBAmaxRAMLine->text()).toInt());
                if(mobaMOBAConnectorsLine->text()!=moba->getConnectors())
                    moba->setConnectors(mobaMOBAConnectorsLine->text());
                (componentsList->currentItem())->setText(componentNameLine->text());
            }
        }
        if(dynamic_cast<CPU*>(componenti[i])!=nullptr) {
            CPU* cpu=static_cast<CPU*>(componenti[i]);
            QString cpuX64bit;
            bool cpuX64bit2;
            QString cpuIntegratedGraphic;
            bool cpuIntegratedGraphic2;
            if((build->item(1, 0))!=nullptr && (build->item(1, 0))->text()==componentName)
                removeCPUFromBuild();
            if(componentNameLine->text()!=componenti[i]->getName()) {
                cpuComboBox->setItemText(cpuComboBox->findText(componentName), componentNameLine->text());
                componenti[i]->setName(componentNameLine->text());
            }
            if(componentLengthLine->text()!=QString::number(componenti[i]->getLength()))
                componenti[i]->setLength((componentLengthLine->text()).toInt());
            if(componentHeightLine->text()!=QString::number(componenti[i]->getHeight()))
                componenti[i]->setHeight((componentHeightLine->text()).toInt());
            std::string price=std::to_string(componenti[i]->getPrice());
            price=removeZero(price);
            if(componentPriceLine->text()!=QString::fromStdString(price))
                componenti[i]->setPrice((componentPriceLine->text()).toDouble());
            if(componentPowerConsumptionLine->text()!=QString::number(componenti[i]->getPowerConsumption()))
                componenti[i]->setPowerConsumption((componentPowerConsumptionLine->text()).toInt());
            if(componentManufacturerLine->text()!=componenti[i]->getManufacturer())
                componenti[i]->setManufacturer(componentManufacturerLine->text());
            std::string cpu_speed=std::to_string(cpu->getCpu_speed());
            cpu_speed=removeZero(cpu_speed);
            if(componentPriceLine->text()!=QString::fromStdString(cpu_speed))
                cpu->setCpu_speed((cpuCPUSpeedLine->text()).toDouble());
            if(cpuCPUCoresLine->text()!=QString::number(cpu->getCores()))
                cpu->setCores((cpuCPUCoresLine->text()).toInt());
            if(cpu->getX64bit())
                cpuX64bit="Sì";
            else
                cpuX64bit="No";
            if(cpuCPUx64bitLine->text()!=cpuX64bit) {
                if((cpuCPUx64bitLine->text())=="Sì")
                    cpuX64bit2=true;
                else
                    cpuX64bit2=false;
                cpu->setX64bit(cpuX64bit2);
            }
            if(cpuCPUSocketLine->text()!=cpu->getCpu_socket())
                cpu->setCpu_socket(cpuCPUSocketLine->text());
            if(cpu->getIntegrated_graphic())
                cpuIntegratedGraphic="Sì";
            else
                cpuIntegratedGraphic="No";
            if(cpuCPUIntegratedGraphicLine->text()!=cpuIntegratedGraphic) {
                if((cpuCPUIntegratedGraphicLine->text())=="Sì")
                    cpuIntegratedGraphic2=true;
                else
                    cpuIntegratedGraphic2=false;
                cpu->setIntegrated_graphic(cpuIntegratedGraphic2);
            }
            (componentsList->currentItem())->setText(componentNameLine->text());
        }
        if(dynamic_cast<GPU*>(componenti[i])!=nullptr) {
            GPU* gpu=static_cast<GPU*>(componenti[i]);
            QString gpuSupplementaryPower;
            bool gpuSupplementaryPower2;
            if((build->item(2, 0))!=nullptr && (build->item(2, 0))->text()==componentName)
                removeGPUFromBuild();
            if(componentNameLine->text()!=componenti[i]->getName()) {
                gpuComboBox->setItemText(gpuComboBox->findText(componentName), componentNameLine->text());
                componenti[i]->setName(componentNameLine->text());
            }
            if(componentLengthLine->text()!=QString::number(componenti[i]->getLength()))
                componenti[i]->setLength((componentLengthLine->text()).toInt());
            if(componentHeightLine->text()!=QString::number(componenti[i]->getHeight()))
                componenti[i]->setHeight((componentHeightLine->text()).toInt());
            std::string price=std::to_string(componenti[i]->getPrice());
            price=removeZero(price);
            if(componentPriceLine->text()!=QString::fromStdString(price))
                componenti[i]->setPrice((componentPriceLine->text()).toDouble());
            if(componentPowerConsumptionLine->text()!=QString::number(componenti[i]->getPowerConsumption()))
                componenti[i]->setPowerConsumption((componentPowerConsumptionLine->text()).toInt());
            if(componentManufacturerLine->text()!=componenti[i]->getManufacturer())
                componenti[i]->setManufacturer(componentManufacturerLine->text());
            if(gpuGPUTypeLine->text()!=gpu->getType())
                gpu->setType(gpuGPUTypeLine->text());
            if(gpuGPUMemorySizeLine->text()!=QString::number(gpu->getMemory_size()))
                gpu->setMemory_size((gpuGPUMemorySizeLine->text()).toInt());
            std::string performance=std::to_string(gpu->getPerformance());
            performance=removeZero(performance);
            if(gpuGPUPerformanceLine->text()!=QString::fromStdString(performance))
                gpu->setPerformance((gpuGPUPerformanceLine->text()).toDouble());
            if(gpuGPUClockLine->text()!=QString::number(gpu->getClock()))
                gpu->setClock((gpuGPUClockLine->text()).toInt());
            if(gpuGPUInterfaceLine->text()!=gpu->getInterface())
                gpu->setInterface(gpuGPUInterfaceLine->text());
            if(gpuGPUConnectorsLine->text()!=gpu->getConnectors())
                gpu->setConnectors(gpuGPUConnectorsLine->text());
            if(gpu->getSupplementary_power())
                gpuSupplementaryPower="Sì";
            else
                gpuSupplementaryPower="No";
            if(gpuGPUSupplementaryPowerLine->text()!=gpuSupplementaryPower) {
                if(gpuGPUSupplementaryPowerLine->text()=="Sì")
                    gpuSupplementaryPower2=true;
                else
                    gpuSupplementaryPower2=false;
                gpu->setSupplementary_power(gpuSupplementaryPower2);
            }
            (componentsList->currentItem())->setText(componentNameLine->text());
        }
        if(dynamic_cast<PSU*>(componenti[i])!=nullptr) {
            PSU* psu=static_cast<PSU*>(componenti[i]);
            QString psuSupplementaryPower;
            bool psuSupplementaryPower2;
            if((build->item(3, 0))!=nullptr && (build->item(3, 0))->text()==componentName)
                removePSUFromBuild();
            if(componentNameLine->text()!=componenti[i]->getName()) {
                psuComboBox->setItemText(psuComboBox->findText(componentName), componentNameLine->text());
                componenti[i]->setName(componentNameLine->text());
            }
            if(componentLengthLine->text()!=QString::number(componenti[i]->getLength()))
                componenti[i]->setLength((componentLengthLine->text()).toInt());
            if(componentHeightLine->text()!=QString::number(componenti[i]->getHeight()))
                componenti[i]->setHeight((componentHeightLine->text()).toInt());
            std::string price=std::to_string(componenti[i]->getPrice());
            price=removeZero(price);
            if(componentPriceLine->text()!=QString::fromStdString(price))
                componenti[i]->setPrice((componentPriceLine->text()).toDouble());
            if(componentPowerConsumptionLine->text()!=QString::number(componenti[i]->getPowerConsumption()))
                componenti[i]->setPowerConsumption((componentPowerConsumptionLine->text()).toInt());
            if(componentManufacturerLine->text()!=componenti[i]->getManufacturer())
                componenti[i]->setManufacturer(componentManufacturerLine->text());
            if(psuPSUFormFactorLine->text()!=psu->getForm_factor())
                psu->setForm_factor(psuPSUFormFactorLine->text());
            if(psuPSUWattageLine->text()!=QString::number(psu->getWattage()))
                psu->setWattage((psuPSUWattageLine->text()).toInt());
            if(psuPSUEfficiencyCertificationLine->text()!=psu->getEfficiency_certification())
                psu->setEfficiency_certification(psuPSUEfficiencyCertificationLine->text());
            if(psuPSUModularityLine->text()!=psu->getModularity())
                psu->setModularity(psuPSUModularityLine->text());
            if(psu->getSupplementaryPower())
                psuSupplementaryPower="Sì";
            else
                psuSupplementaryPower="No";
            if(psuPSUSupplementaryPowerLine->text()!=psuSupplementaryPower) {
                if(psuPSUSupplementaryPowerLine->text()=="Sì")
                    psuSupplementaryPower2=true;
                else
                    psuSupplementaryPower2=false;
                psu->setSupplementary_power(psuSupplementaryPower2);
            }
            (componentsList->currentItem())->setText(componentNameLine->text());
        }
        if(dynamic_cast<RAM*>(componenti[i])!=nullptr) {
            RAM* ram=static_cast<RAM*>(componenti[i]);
            if((build->item(4, 0))!=nullptr && (build->item(4, 0))->text()==componentName)
                removeRAMFromBuild();
            if(componentNameLine->text()!=componenti[i]->getName()) {
                ramComboBox->setItemText(ramComboBox->findText(componentName), componentNameLine->text());
                componenti[i]->setName(componentNameLine->text());
            }
            if(componentLengthLine->text()!=QString::number(componenti[i]->getLength()))
                componenti[i]->setLength((componentLengthLine->text()).toInt());
            if(componentHeightLine->text()!=QString::number(componenti[i]->getHeight()))
                componenti[i]->setHeight((componentHeightLine->text()).toInt());
            std::string price=std::to_string(componenti[i]->getPrice());
            price=removeZero(price);
            if(componentPriceLine->text()!=QString::fromStdString(price))
                componenti[i]->setPrice((componentPriceLine->text()).toDouble());
            if(componentPowerConsumptionLine->text()!=QString::number(componenti[i]->getPowerConsumption()))
                componenti[i]->setPowerConsumption((componentPowerConsumptionLine->text()).toInt());
            if(componentManufacturerLine->text()!=componenti[i]->getManufacturer())
                componenti[i]->setManufacturer(componentManufacturerLine->text());
            if(ramRAMSpeedLine->text()!=QString::number(ram->getRam_speed()))
                ram->setRam_speed((ramRAMSpeedLine->text()).toInt());
            if(ramRAMTypeLine->text()!=ram->getType())
                ram->setType(ramRAMTypeLine->text());
            if(ramRAMSizeLine->text()!=QString::number(ram->getSize()))
                ram->setSize((ramRAMSizeLine->text()).toInt());
            (componentsList->currentItem())->setText(componentNameLine->text());
        }
        if(dynamic_cast<Storage*>(componenti[i])!=nullptr) {
            Storage* storage=static_cast<Storage*>(componenti[i]);
            if((build->item(5, 0))!=nullptr && (build->item(5, 0))->text()==componentName)
                removeStorageFromBuild();
            if(componentNameLine->text()!=componenti[i]->getName()) {
                storageComboBox->setItemText(storageComboBox->findText(componentName), componentNameLine->text());
                componenti[i]->setName(componentNameLine->text());
            }
            if(componentLengthLine->text()!=QString::number(componenti[i]->getLength()))
                componenti[i]->setLength((componentLengthLine->text()).toInt());
            if(componentHeightLine->text()!=QString::number(componenti[i]->getHeight()))
                componenti[i]->setHeight((componentHeightLine->text()).toInt());
            std::string price=std::to_string(componenti[i]->getPrice());
            price=removeZero(price);
            if(componentPriceLine->text()!=QString::fromStdString(price))
                componenti[i]->setPrice((componentPriceLine->text()).toDouble());
            if(componentPowerConsumptionLine->text()!=QString::number(componenti[i]->getPowerConsumption()))
                componenti[i]->setPowerConsumption((componentPowerConsumptionLine->text()).toInt());
            if(componentManufacturerLine->text()!=componenti[i]->getManufacturer())
                componenti[i]->setManufacturer(componentManufacturerLine->text());
            if(storageStorageTypeLine->text()!=storage->getType())
                storage->setType(storageStorageTypeLine->text());
            if(storageStorageRPMLine->text()!=QString::number(storage->getRpm()))
                storage->setRpm((storageStorageRPMLine->text()).toInt());
            if(storageStorageSizeLine->text()!=QString::number(storage->getSize()))
                storage->setSize((storageStorageSizeLine->text()).toInt());
            if(storageStorageInterfaceLine->text()!=storage->getInterface())
                storage->setInterface(storageStorageInterfaceLine->text());
            std::string form_factor=std::to_string(storage->getForm_factor());
            form_factor=removeZero(form_factor);
            if(storageStorageFormFactorLine->text()!=QString::fromStdString(form_factor))
                storage->setForm_factor((storageStorageFormFactorLine->text()).toDouble());
            if(storageStorageSpeedLine->text()!=QString::number(storage->getSpeed()))
                storage->setSpeed((storageStorageSpeedLine->text()).toInt());
            (componentsList->currentItem())->setText(componentNameLine->text());
        }
    }
    discardComponentsChanges();
}

void MainWindow::editComponentsSpecs() {
    resetEditSpecs();
    if(componentsList->currentItem()!=nullptr && (componentsList->currentItem())->text()!=componentNameLine->text()) {
        bool trovato=false;
        for(unsigned int i=0; i!=componentsList->count(); ++i) {
            QListWidgetItem *item=componentsList->item(i);
            auto flags=item->flags();
            flags.setFlag(Qt::ItemIsEnabled, false);
            item->setFlags(flags);
        }
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(dynamic_cast<MOBA*>(componenti[i])!=nullptr) {
                QString mobaName=(componentsList->currentItem())->text();
                if(!trovato && componenti[i]->getName()==mobaName) {
                    trovato=true;
                    QString mobaLength=(QString::number(componenti[i]->getLength()));
                    QString mobaHeight=(QString::number(componenti[i]->getHeight()));
                    QString mobaManufacturer=(componenti[i]->getManufacturer());
                    std::string price=std::to_string(componenti[i]->getPrice());
                    price=removeZero(price);
                    QString mobaPrice=QString::fromStdString(price);
                    QString mobaPowerConsumption=(QString::number(componenti[i]->getPowerConsumption()));
                    MOBA* moba=static_cast<MOBA*>(componenti[i]);
                    QString mobaMOBASocket=moba->getMOBASocket();
                    QString mobaFormFactor=moba->getForm_factor();
                    QString mobaRAMSlots=(QString::number(moba->getRAM_slots()));
                    QString mobaMaxRAM=(QString::number(moba->getMax_RAM()));
                    QString mobaConnectors=moba->getConnectors();
                    QLabel *mobaSocketLabel=new QLabel("Socket: ");
                    QLabel *mobaFormFactorLabel=new QLabel("Form Factor: ");
                    QLabel *mobaRAMSlotsLabel=new QLabel("Slot RAM: ");
                    QLabel *mobaMaxRAMLabel=new QLabel("RAM massima supportata (GB): ");
                    QLabel *mobaConnectorsLabel=new QLabel("Interfacce: ");
                    mobaMOBASocketLine=new QLineEdit(mobaMOBASocket);
                    mobaMOBAFormFactorLine=new QLineEdit(mobaFormFactor);
                    mobaMOBARAMSlotsLine=new QLineEdit(mobaRAMSlots);
                    mobaMOBAmaxRAMLine=new QLineEdit(mobaMaxRAM);
                    mobaMOBAConnectorsLine=new QLineEdit(mobaConnectors);
                    componentNameLine->setText(mobaName);
                    componentManufacturerLine->setText(mobaManufacturer);
                    componentLengthLine->setText(mobaLength);
                    componentHeightLine->setText(mobaHeight);
                    componentPriceLine->setText(mobaPrice);
                    componentPowerConsumptionLine->setText(mobaPowerConsumption);
                    componentsSpecsLayout2=new QFormLayout();
                    saveChanges=new QPushButton("Salva modifiche");
                    discardChanges=new QPushButton("Annulla modifiche");
                    componentsSpecsLayout2->addRow(mobaSocketLabel, mobaMOBASocketLine);
                    componentsSpecsLayout2->addRow(mobaFormFactorLabel, mobaMOBAFormFactorLine);
                    componentsSpecsLayout2->addRow(mobaRAMSlotsLabel, mobaMOBARAMSlotsLine);
                    componentsSpecsLayout2->addRow(mobaMaxRAMLabel, mobaMOBAmaxRAMLine);
                    componentsSpecsLayout2->addRow(mobaConnectorsLabel, mobaMOBAConnectorsLine);
                    componentsSpecsLayout2->addRow(saveChanges);
                    componentsSpecsLayout2->addRow(discardChanges);
                    componentsSpecsLayout2->setVerticalSpacing(25);
                    specLayout2->addRow(componentsSpecsLayout2);
                    connect(discardChanges, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
                    connect(saveChanges, SIGNAL(clicked(bool)), this, SLOT(saveComponentsChanges()));
                }
            }
            if(dynamic_cast<CPU*>(componenti[i])!=nullptr) {
                QString cpuName=(componentsList->currentItem())->text();
                if(!trovato && componenti[i]->getName()==cpuName) {
                    trovato=true;
                    QString cpux64bit;
                    QString cpuIntegratedGraphics;
                    QString cpuLength=(QString::number(componenti[i]->getLength()));
                    QString cpuHeight=(QString::number(componenti[i]->getHeight()));
                    QString cpuManufacturer=(componenti[i]->getManufacturer());
                    std::string price=std::to_string(componenti[i]->getPrice());
                    price=removeZero(price);
                    QString cpuPrice=QString::fromStdString(price);
                    QString cpuPowerConsumption=(QString::number(componenti[i]->getPowerConsumption()));
                    CPU* cpu=static_cast<CPU*>(componenti[i]);
                    std::string speed=std::to_string(cpu->getCpu_speed());
                    speed=removeZero(speed);
                    QString cpuSpeed=QString::fromStdString(speed);
                    QString cpuCores=(QString::number(cpu->getCores()));
                    if(cpu->getX64bit())
                        cpux64bit="Sì";
                    else
                        cpux64bit="No";
                    QString cpuSocket=cpu->getCpu_socket();
                    if(cpu->getIntegrated_graphic())
                        cpuIntegratedGraphics="Sì";
                    else
                        cpuIntegratedGraphics="No";
                    QLabel *SpeedLabel=new QLabel("Frequenza (GHz): ");
                    QLabel *CoresLabel=new QLabel("Cores: ");
                    QLabel *x64bitLabel=new QLabel("Supporto 64 bit: ");
                    QLabel *cpuSocketLabel=new QLabel("Socket CPU: ");
                    QLabel *IntegratedGraphicsLabel=new QLabel("Chip grafico integrato: ");
                    cpuCPUSpeedLine=new QLineEdit(cpuSpeed);
                    cpuCPUCoresLine=new QLineEdit(cpuCores);
                    cpuCPUx64bitLine=new QLineEdit(cpux64bit);
                    cpuCPUSocketLine=new QLineEdit(cpuSocket);
                    cpuCPUIntegratedGraphicLine=new QLineEdit(cpuIntegratedGraphics);
                    componentNameLine->setText(cpuName);
                    componentManufacturerLine->setText(cpuManufacturer);
                    componentLengthLine->setText(cpuLength);
                    componentHeightLine->setText(cpuHeight);
                    componentPriceLine->setText(cpuPrice);
                    componentPowerConsumptionLine->setText(cpuPowerConsumption);
                    componentsSpecsLayout2=new QFormLayout();
                    saveChanges=new QPushButton("Salva modifiche");
                    discardChanges=new QPushButton("Annulla modifiche");
                    componentsSpecsLayout2->addRow(SpeedLabel, cpuCPUSpeedLine);
                    componentsSpecsLayout2->addRow(CoresLabel, cpuCPUCoresLine);
                    componentsSpecsLayout2->addRow(x64bitLabel, cpuCPUx64bitLine);
                    componentsSpecsLayout2->addRow(cpuSocketLabel, cpuCPUSocketLine);
                    componentsSpecsLayout2->addRow(IntegratedGraphicsLabel, cpuCPUIntegratedGraphicLine);
                    componentsSpecsLayout2->addRow(saveChanges);
                    componentsSpecsLayout2->addRow(discardChanges);
                    componentsSpecsLayout2->setVerticalSpacing(25);
                    specLayout2->addRow(componentsSpecsLayout2);
                    connect(discardChanges, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
                    connect(saveChanges, SIGNAL(clicked(bool)), this, SLOT(saveComponentsChanges()));
                }
            }
            if(dynamic_cast<GPU*>(componenti[i])!=nullptr) {
                QString gpuName=(componentsList->currentItem())->text();
                if(!trovato && componenti[i]->getName()==gpuName) {
                    trovato=true;
                    QString gpuSupplementaryPower;
                    QString gpuLength=(QString::number(componenti[i]->getLength()));
                    QString gpuHeight=(QString::number(componenti[i]->getHeight()));
                    QString gpuManufacturer=(componenti[i]->getManufacturer());
                    std::string price=std::to_string(componenti[i]->getPrice());
                    price=removeZero(price);
                    QString gpuPrice=QString::fromStdString(price);
                    QString gpuPowerConsumption=(QString::number(componenti[i]->getPowerConsumption()));
                    GPU *gpu=static_cast<GPU*>(componenti[i]);
                    QString gpuType=gpu->getType();
                    QString gpuMemorySize=(QString::number(gpu->getMemory_size()));
                    std::string performance=std::to_string(gpu->getPerformance());
                    performance=removeZero(performance);
                    QString gpuPerformance=QString::fromStdString(performance);
                    QString gpuClock=(QString::number(gpu->getClock()));
                    QString gpuInterface=gpu->getInterface();
                    QString gpuConnectors=gpu->getConnectors();
                    if(gpu->getSupplementary_power())
                        gpuSupplementaryPower="Sì";
                    else
                        gpuSupplementaryPower="No";
                    QLabel *gpuTypeLabel=new QLabel("Tipo: ");
                    QLabel *gpuMemorySizeLabel=new QLabel("Memoria dedicata (GB): ");
                    QLabel *gpuPerformanceLabel=new QLabel("TFLOPs: ");
                    QLabel *gpuClockLabel=new QLabel("Clock (MHz): ");
                    QLabel *gpuInterfaceLabel=new QLabel("Interfacce: ");
                    QLabel *gpuConnectorsLabel=new QLabel("Porte: ");
                    QLabel *gpuSupplementaryPowerLabel=new QLabel("Alimentazione supplementare richiesta: ");
                    gpuGPUTypeLine=new QLineEdit(gpuType);
                    gpuGPUMemorySizeLine=new QLineEdit(gpuMemorySize);
                    gpuGPUPerformanceLine=new QLineEdit(gpuPerformance);
                    gpuGPUClockLine=new QLineEdit(gpuClock);
                    gpuGPUInterfaceLine=new QLineEdit(gpuInterface);
                    gpuGPUConnectorsLine=new QLineEdit(gpuConnectors);
                    gpuGPUSupplementaryPowerLine=new QLineEdit(gpuSupplementaryPower);
                    componentNameLine->setText(gpuName);
                    componentManufacturerLine->setText(gpuManufacturer);
                    componentLengthLine->setText(gpuLength);
                    componentHeightLine->setText(gpuHeight);
                    componentPriceLine->setText(gpuPrice);
                    componentPowerConsumptionLine->setText(gpuPowerConsumption);
                    componentsSpecsLayout2=new QFormLayout();
                    saveChanges=new QPushButton("Salva modifiche");
                    discardChanges=new QPushButton("Annulla modifiche");
                    componentsSpecsLayout2->addRow(gpuTypeLabel, gpuGPUTypeLine);
                    componentsSpecsLayout2->addRow(gpuMemorySizeLabel, gpuGPUMemorySizeLine);
                    componentsSpecsLayout2->addRow(gpuPerformanceLabel, gpuGPUPerformanceLine);
                    componentsSpecsLayout2->addRow(gpuClockLabel, gpuGPUClockLine);
                    componentsSpecsLayout2->addRow(gpuInterfaceLabel, gpuGPUInterfaceLine);
                    componentsSpecsLayout2->addRow(gpuConnectorsLabel, gpuGPUConnectorsLine);
                    componentsSpecsLayout2->addRow(gpuSupplementaryPowerLabel, gpuGPUSupplementaryPowerLine);
                    componentsSpecsLayout2->addRow(saveChanges);
                    componentsSpecsLayout2->addRow(discardChanges);
                    componentsSpecsLayout2->setVerticalSpacing(25);
                    specLayout2->addRow(componentsSpecsLayout2);
                    connect(discardChanges, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
                    connect(saveChanges, SIGNAL(clicked(bool)), this, SLOT(saveComponentsChanges()));
                }
            }
            if(dynamic_cast<PSU*>(componenti[i])!=nullptr) {
                QString psuName=(componentsList->currentItem())->text();
                if(!trovato && componenti[i]->getName()==psuName) {
                    trovato=true;
                    QString psuSupplementaryPower;
                    QString psuLength=(QString::number(componenti[i]->getLength()));
                    QString psuHeight=(QString::number(componenti[i]->getHeight()));
                    QString psuManufacturer=(componenti[i]->getManufacturer());
                    std::string price=std::to_string(componenti[i]->getPrice());
                    price=removeZero(price);
                    QString psuPrice=QString::fromStdString(price);
                    QString psuPowerConsumption=(QString::number(componenti[i]->getPowerConsumption()));
                    PSU *psu=static_cast<PSU*>(componenti[i]);
                    QString psuFormFactor=psu->getForm_factor();
                    QString psuWattage=(QString::number(psu->getWattage()));
                    QString psuEfficiencyCertification=psu->getEfficiency_certification();
                    QString psuModularity=psu->getModularity();
                    if(psu->getSupplementaryPower()==true)
                        psuSupplementaryPower="Sì";
                    else
                        psuSupplementaryPower="No";
                    QLabel *psuFormFactorLabel=new QLabel("Form Factor: ");
                    QLabel *psuWattageLabel=new QLabel("Wattaggio: ");
                    QLabel *psuEfficiencyCertificationLabel=new QLabel("Certificazione di efficienza: ");
                    QLabel *psuModularityLabel=new QLabel("Modularità: ");
                    QLabel *psuSupplementaryPowerLabel=new QLabel("Predisposizione alimentazione supplementare: ");
                    psuPSUFormFactorLine=new QLineEdit(psuFormFactor);
                    psuPSUWattageLine=new QLineEdit(psuWattage);
                    psuPSUEfficiencyCertificationLine=new QLineEdit(psuEfficiencyCertification);
                    psuPSUModularityLine=new QLineEdit(psuModularity);
                    psuPSUSupplementaryPowerLine=new QLineEdit(psuSupplementaryPower);
                    componentNameLine->setText(psuName);
                    componentManufacturerLine->setText(psuManufacturer);
                    componentLengthLine->setText(psuLength);
                    componentHeightLine->setText(psuHeight);
                    componentPriceLine->setText(psuPrice);
                    componentPowerConsumptionLine->setText(psuPowerConsumption);
                    componentsSpecsLayout2=new QFormLayout();
                    saveChanges=new QPushButton("Salva modifiche");
                    discardChanges=new QPushButton("Annulla modifiche");
                    componentsSpecsLayout2->addRow(psuFormFactorLabel, psuPSUFormFactorLine);
                    componentsSpecsLayout2->addRow(psuEfficiencyCertificationLabel, psuPSUEfficiencyCertificationLine);
                    componentsSpecsLayout2->addRow(psuWattageLabel, psuPSUWattageLine);
                    componentsSpecsLayout2->addRow(psuModularityLabel, psuPSUModularityLine);
                    componentsSpecsLayout2->addRow(psuSupplementaryPowerLabel, psuPSUSupplementaryPowerLine);
                    componentsSpecsLayout2->addRow(saveChanges);
                    componentsSpecsLayout2->addRow(discardChanges);
                    componentsSpecsLayout2->setVerticalSpacing(25);
                    specLayout2->addRow(componentsSpecsLayout2);
                    connect(discardChanges, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
                    connect(saveChanges, SIGNAL(clicked(bool)), this, SLOT(saveComponentsChanges()));
                }
            }
            if(dynamic_cast<RAM*>(componenti[i])!=nullptr) {
                QString ramName=(componentsList->currentItem())->text();
                if(!trovato && componenti[i]->getName()==ramName) {
                    trovato=true;
                    QString ramLength=(QString::number(componenti[i]->getLength()));
                    QString ramHeight=(QString::number(componenti[i]->getHeight()));
                    QString ramManufacturer=(componenti[i]->getManufacturer());
                    std::string price=std::to_string(componenti[i]->getPrice());
                    price=removeZero(price);
                    QString ramPrice=QString::fromStdString(price);
                    QString ramPowerConsumption=(QString::number(componenti[i]->getPowerConsumption()));
                    RAM *ram=static_cast<RAM*>(componenti[i]);
                    QString ramSpeed=(QString::number(ram->getRam_speed()));
                    QString ramType=ram->getType();
                    QString ramSize=(QString::number(ram->getSize()));
                    QLabel *ramSpeedLabel=new QLabel("Frequenza (MHz): ");
                    QLabel *ramTypeLabel=new QLabel("Tipo: ");
                    QLabel *ramSizeLabel=new QLabel("Capacità (GB): ");
                    ramRAMSpeedLine=new QLineEdit(ramSpeed);
                    ramRAMTypeLine=new QLineEdit(ramType);
                    ramRAMSizeLine=new QLineEdit(ramSize);
                    componentNameLine->setText(ramName);
                    componentManufacturerLine->setText(ramManufacturer);
                    componentLengthLine->setText(ramLength);
                    componentHeightLine->setText(ramHeight);
                    componentPriceLine->setText(ramPrice);
                    componentPowerConsumptionLine->setText(ramPowerConsumption);
                    componentsSpecsLayout2=new QFormLayout();
                    saveChanges=new QPushButton("Salva modifiche");
                    discardChanges=new QPushButton("Annulla modifiche");
                    componentsSpecsLayout2->addRow(ramSpeedLabel, ramRAMSpeedLine);
                    componentsSpecsLayout2->addRow(ramTypeLabel, ramRAMTypeLine);
                    componentsSpecsLayout2->addRow(ramSizeLabel, ramRAMSizeLine);
                    componentsSpecsLayout2->addRow(saveChanges);
                    componentsSpecsLayout2->addRow(discardChanges);
                    componentsSpecsLayout2->setVerticalSpacing(25);
                    specLayout2->addRow(componentsSpecsLayout2);
                    connect(discardChanges, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
                    connect(saveChanges, SIGNAL(clicked(bool)), this, SLOT(saveComponentsChanges()));
                }
            }
            if(dynamic_cast<Storage*>(componenti[i])!=nullptr) {
                QString storageName=(componentsList->currentItem())->text();
                if(!trovato && componenti[i]->getName()==storageName) {
                    trovato=true;
                    QString storageLength=(QString::number(componenti[i]->getLength()));
                    QString storageHeight=(QString::number(componenti[i]->getHeight()));
                    QString storageManufacturer=(componenti[i]->getManufacturer());
                    std::string price=std::to_string(componenti[i]->getPrice());
                    price=removeZero(price);
                    QString storagePrice=QString::fromStdString(price);
                    QString storagePowerConsumption=(QString::number(componenti[i]->getPowerConsumption()));
                    Storage* storage=static_cast<Storage*>(componenti[i]);
                    QString storageType=storage->getType();
                    QString storageRPM=(QString::number(storage->getRpm()));
                    QString storageSize=(QString::number(storage->getSize()));
                    QString storageInterface=storage->getInterface();
                    std::string form_factor=std::to_string(storage->getForm_factor());
                    form_factor=removeZero(form_factor);
                    QString storageFormFactor=QString::fromStdString(form_factor);
                    QString storageSpeed=(QString::number(storage->getSpeed()));
                    QLabel *storageTypeLabel=new QLabel("Tipo: ");
                    QLabel *storageRPMLabel=new QLabel("RPM: ");
                    QLabel *storageSizeLabel=new QLabel("Capacità (GB): ");
                    QLabel *storageInterfaceLabel=new QLabel("Interfaccia: ");
                    QLabel *storageFormFactorLabel=new QLabel("Form Factor: ");
                    QLabel *storageSpeedLabel=new QLabel("Velocità trasferimento (MB/s): ");
                    storageStorageTypeLine=new QLineEdit(storageType);
                    storageStorageRPMLine=new QLineEdit(storageRPM);
                    storageStorageSizeLine=new QLineEdit(storageSize);
                    storageStorageInterfaceLine=new QLineEdit(storageInterface);
                    storageStorageFormFactorLine=new QLineEdit(storageFormFactor);
                    storageStorageSpeedLine=new QLineEdit(storageSpeed);
                    componentNameLine->setText(storageName);
                    componentManufacturerLine->setText(storageManufacturer);
                    componentLengthLine->setText(storageLength);
                    componentHeightLine->setText(storageHeight);
                    componentPriceLine->setText(storagePrice);
                    componentPowerConsumptionLine->setText(storagePowerConsumption);
                    componentsSpecsLayout2=new QFormLayout();
                    saveChanges=new QPushButton("Salva modifiche");
                    discardChanges=new QPushButton("Annulla modifiche");
                    componentsSpecsLayout2->addRow(storageTypeLabel, storageStorageTypeLine);
                    componentsSpecsLayout2->addRow(storageRPMLabel, storageStorageRPMLine);
                    componentsSpecsLayout2->addRow(storageSizeLabel, storageStorageSizeLine);
                    componentsSpecsLayout2->addRow(storageInterfaceLabel, storageStorageInterfaceLine);
                    componentsSpecsLayout2->addRow(storageFormFactorLabel, storageStorageFormFactorLine);
                    componentsSpecsLayout2->addRow(storageSpeedLabel, storageStorageSpeedLine);
                    componentsSpecsLayout2->addRow(saveChanges);
                    componentsSpecsLayout2->addRow(discardChanges);
                    componentsSpecsLayout2->setVerticalSpacing(25);
                    specLayout2->addRow(componentsSpecsLayout2);
                    connect(discardChanges, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
                    connect(saveChanges, SIGNAL(clicked(bool)), this, SLOT(saveComponentsChanges()));
                }
            }
        }
    }
}

void MainWindow::removeMOBAFromBuild() {
    if((build->item(0, 0))!=nullptr) {
        resetSpecs();
        build->setItem(0, 0, nullptr);
        build->setItem(0, 1, nullptr);
        build->setItem(0, 2, nullptr);
    }
    calculateTotal();
}

void MainWindow::removeCPUFromBuild() {
    if((build->item(1, 0))!=nullptr) {
        resetSpecs();
        build->setItem(1, 0, nullptr);
        build->setItem(1, 1, nullptr);
        build->setItem(1, 2, nullptr);
    }
    calculateTotal();
}

void MainWindow::removeGPUFromBuild() {
    if((build->item(2, 0))!=nullptr) {
        resetSpecs();
        build->setItem(2, 0, nullptr);
        build->setItem(2, 1, nullptr);
        build->setItem(2, 2, nullptr);
    }
    calculateTotal();
}

void MainWindow::removePSUFromBuild() {
    if((build->item(3, 0))!=nullptr) {
        resetSpecs();
        build->setItem(3, 0, nullptr);
        build->setItem(3, 1, nullptr);
        build->setItem(3, 2, nullptr);
    }
    calculateTotal();
}

void MainWindow::removeRAMFromBuild() {
    if((build->item(4, 0))!=nullptr) {
        resetSpecs();
        build->setItem(4, 0, nullptr);
        build->setItem(4, 1, nullptr);
        build->setItem(4, 2, nullptr);
    }
    calculateTotal();
}

void MainWindow::removeStorageFromBuild() {
    if((build->item(5, 0))!=nullptr) {
        resetSpecs();
        build->setItem(5, 0, nullptr);
        build->setItem(5, 1, nullptr);
        build->setItem(5, 2, nullptr);
    }
    calculateTotal();
}

void MainWindow::deleteBuild() {
    removeMOBAFromBuild();
    removeCPUFromBuild();
    removeGPUFromBuild();
    removePSUFromBuild();
    removeRAMFromBuild();
    removeStorageFromBuild();
}

void MainWindow::saveBuildToFile() {
    QString file = QFileDialog::getSaveFileName(this, tr("Save Build"), "", tr("JSON (*.json);"));
    QJsonArray newBuild;
    QFile savePath(file);
    bool mobaCheck=(build->item(0, 0)!=nullptr);
    bool cpuCheck=(build->item(1, 0)!=nullptr);
    bool gpuCheck=(build->item(2, 0)!=nullptr);
    bool psuCheck=(build->item(3, 0)!=nullptr);
    bool ramCheck=(build->item(4, 0)!=nullptr);
    bool storageCheck=(build->item(5, 0)!=nullptr);
    for(unsigned int i=0; i!=componenti.getSize(); ++i) {
        QJsonObject singleComponent;
        if(mobaCheck && (build->item(0, 0))->text()==componenti[i]->getName()) {
            MOBA* moba=static_cast<MOBA*>(componenti[i]);
            singleComponent.insert("component_type", "MOBA");
            singleComponent.insert("length", QJsonValue::fromVariant(moba->getLength()));
            singleComponent.insert("height", QJsonValue::fromVariant(moba->getHeight()));
            singleComponent.insert("name", QJsonValue::fromVariant(moba->getName()));
            singleComponent.insert("manufacturer", QJsonValue::fromVariant(moba->getManufacturer()));
            singleComponent.insert("price", QJsonValue::fromVariant(moba->getPrice()));
            singleComponent.insert("power_consumption", QJsonValue::fromVariant(moba->getPowerConsumption()));
            singleComponent.insert("moba_socket", QJsonValue::fromVariant(moba->getMOBASocket()));
            singleComponent.insert("form_factor", QJsonValue::fromVariant(moba->getForm_factor()));
            singleComponent.insert("RAM_slots", QJsonValue::fromVariant(moba->getRAM_slots()));
            singleComponent.insert("max_RAM", QJsonValue::fromVariant(moba->getMax_RAM()));
            singleComponent.insert("connectors", QJsonValue::fromVariant(moba->getConnectors()));
            newBuild.append(singleComponent);
        }
        else if(cpuCheck && (build->item(1, 0))->text()==componenti[i]->getName()) {
            CPU* cpu=static_cast<CPU*>(componenti[i]);
            singleComponent.insert("component_type", "CPU");
            singleComponent.insert("length", QJsonValue::fromVariant(cpu->getLength()));
            singleComponent.insert("height", QJsonValue::fromVariant(cpu->getHeight()));
            singleComponent.insert("name", QJsonValue::fromVariant(cpu->getName()));
            singleComponent.insert("manufacturer", QJsonValue::fromVariant(cpu->getManufacturer()));
            singleComponent.insert("price", QJsonValue::fromVariant(cpu->getPrice()));
            singleComponent.insert("power_consumption", QJsonValue::fromVariant(cpu->getPowerConsumption()));
            singleComponent.insert("cpu_speed", QJsonValue::fromVariant(cpu->getCpu_speed()));
            singleComponent.insert("cores", QJsonValue::fromVariant(cpu->getCores()));
            singleComponent.insert("x64bit", QJsonValue::fromVariant(cpu->getX64bit()));
            singleComponent.insert("cpu_socket", QJsonValue::fromVariant(cpu->getCpu_socket()));
            singleComponent.insert("integrated_graphics", QJsonValue::fromVariant(cpu->getIntegrated_graphic()));
            newBuild.append(singleComponent);
        }
        else if(gpuCheck && (build->item(2, 0))->text()==componenti[i]->getName()) {
            GPU* gpu=static_cast<GPU*>(componenti[i]);
            singleComponent.insert("component_type", "GPU");
            singleComponent.insert("length", QJsonValue::fromVariant(gpu->getLength()));
            singleComponent.insert("height", QJsonValue::fromVariant(gpu->getHeight()));
            singleComponent.insert("name", QJsonValue::fromVariant(gpu->getName()));
            singleComponent.insert("manufacturer", QJsonValue::fromVariant(gpu->getManufacturer()));
            singleComponent.insert("price", QJsonValue::fromVariant(gpu->getPrice()));
            singleComponent.insert("power_consumption", QJsonValue::fromVariant(gpu->getPowerConsumption()));
            singleComponent.insert("type", QJsonValue::fromVariant(gpu->getType()));
            singleComponent.insert("memory_size", QJsonValue::fromVariant(gpu->getMemory_size()));
            singleComponent.insert("performance", QJsonValue::fromVariant(gpu->getPerformance()));
            singleComponent.insert("clock", QJsonValue::fromVariant(gpu->getClock()));
            singleComponent.insert("interface", QJsonValue::fromVariant(gpu->getInterface()));
            singleComponent.insert("connectors", QJsonValue::fromVariant(gpu->getConnectors()));
            singleComponent.insert("supplementary_power", QJsonValue::fromVariant(gpu->getSupplementary_power()));
            newBuild.append(singleComponent);
        }
        else if(psuCheck && (build->item(3, 0))->text()==componenti[i]->getName()) {
            PSU* psu=static_cast<PSU*>(componenti[i]);
            singleComponent.insert("component_type", "PSU");
            singleComponent.insert("length", QJsonValue::fromVariant(psu->getLength()));
            singleComponent.insert("height", QJsonValue::fromVariant(psu->getHeight()));
            singleComponent.insert("name", QJsonValue::fromVariant(psu->getName()));
            singleComponent.insert("manufacturer", QJsonValue::fromVariant(psu->getManufacturer()));
            singleComponent.insert("price", QJsonValue::fromVariant(psu->getPrice()));
            singleComponent.insert("power_consumption", QJsonValue::fromVariant(psu->getPowerConsumption()));
            singleComponent.insert("form_factor", QJsonValue::fromVariant(psu->getForm_factor()));
            singleComponent.insert("wattage", QJsonValue::fromVariant(psu->getWattage()));
            singleComponent.insert("efficiency_certification", QJsonValue::fromVariant(psu->getEfficiency_certification()));
            singleComponent.insert("modularity", QJsonValue::fromVariant(psu->getModularity()));
            singleComponent.insert("supplementary_power", QJsonValue::fromVariant(psu->getSupplementaryPower()));
            newBuild.append(singleComponent);
        }
        else if(ramCheck && (build->item(4, 0))->text()==componenti[i]->getName()) {
            RAM* ram=static_cast<RAM*>(componenti[i]);
            singleComponent.insert("component_type", "RAM");
            singleComponent.insert("length", QJsonValue::fromVariant(ram->getLength()));
            singleComponent.insert("height", QJsonValue::fromVariant(ram->getHeight()));
            singleComponent.insert("name", QJsonValue::fromVariant(ram->getName()));
            singleComponent.insert("manufacturer", QJsonValue::fromVariant(ram->getManufacturer()));
            singleComponent.insert("price", QJsonValue::fromVariant(ram->getPrice()));
            singleComponent.insert("power_consumption", QJsonValue::fromVariant(ram->getPowerConsumption()));
            singleComponent.insert("ram_speed", QJsonValue::fromVariant(ram->getRam_speed()));
            singleComponent.insert("type", QJsonValue::fromVariant(ram->getType()));
            singleComponent.insert("size", QJsonValue::fromVariant(ram->getSize()));
            newBuild.append(singleComponent);
        }
        else if(storageCheck && (build->item(5, 0))->text()==componenti[i]->getName()) {
            Storage* storage=static_cast<Storage*>(componenti[i]);
            singleComponent.insert("component_type", "Storage");
            singleComponent.insert("length", QJsonValue::fromVariant(storage->getLength()));
            singleComponent.insert("height", QJsonValue::fromVariant(storage->getHeight()));
            singleComponent.insert("name", QJsonValue::fromVariant(storage->getName()));
            singleComponent.insert("manufacturer", QJsonValue::fromVariant(storage->getManufacturer()));
            singleComponent.insert("price", QJsonValue::fromVariant(storage->getPrice()));
            singleComponent.insert("power_consumption", QJsonValue::fromVariant(storage->getPowerConsumption()));
            singleComponent.insert("type", QJsonValue::fromVariant(storage->getType()));
            singleComponent.insert("rpm", QJsonValue::fromVariant(storage->getRpm()));
            singleComponent.insert("size", QJsonValue::fromVariant(storage->getSize()));
            singleComponent.insert("interface", QJsonValue::fromVariant(storage->getInterface()));
            singleComponent.insert("form_factor", QJsonValue::fromVariant(storage->getForm_factor()));
            singleComponent.insert("speed", QJsonValue::fromVariant(storage->getSpeed()));
            newBuild.append(singleComponent);
        }
    }
    QJsonObject toAdd;
    toAdd.insert("pc_parts", newBuild);
    QJsonDocument json(toAdd);
    if(savePath.open(QIODevice::WriteOnly)) {
        savePath.write(json.toJson());
        std::cout<<"File salvato correttamente!"<<std::endl;
    }
}

void MainWindow::resetSpecs() {
    componentNameLabel->setText("");
    componentLengthLabel->setText("");
    componentHeightLabel->setText("");
    componentPriceLabel->setText("");
    componentPowerConsumptionLabel->setText("");
    componentManufacturerLabel->setText("");
    specLayout->removeRow(componentsSpecsLayout);
}

void MainWindow::showMOBASpecs() {
    resetSpecs();
    if(build->item(0, 0)!=nullptr && (build->item(0, 0))->text()!=componentNameLabel->text()) {
        bool trovato=false;
        QString mobaName=(build->item(0, 0))->text();
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(!trovato && componenti[i]->getName()==mobaName) {
                trovato=true;
                QString mobaLength=(QString::number(componenti[i]->getLength()));
                QString mobaHeight=(QString::number(componenti[i]->getHeight()));
                QString mobaManufacturer=(componenti[i]->getManufacturer());
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString mobaPrice=QString::fromStdString(price);
                QString mobaPowerConsumption=(QString::number(componenti[i]->getPowerConsumption()));
                MOBA* moba=static_cast<MOBA*>(componenti[i]);
                QString mobaMOBASocket=moba->getMOBASocket();
                QString mobaFormFactor=moba->getForm_factor();
                QString mobaRAMSlots=(QString::number(moba->getRAM_slots()));
                QString mobaMaxRAM=(QString::number(moba->getMax_RAM()));
                QString mobaConnectors=moba->getConnectors();
                QLabel *MOBASocketLabel=new QLabel("Socket: ");
                QLabel *FormFactorLabel=new QLabel("Form Factor: ");
                QLabel *RAMSlotsLabel=new QLabel("Slot RAM: ");
                QLabel *MaxRAMLabel=new QLabel("RAM massima supportata (GB): ");
                QLabel *MOBAConnectorsLabel=new QLabel("Interfacce: ");
                QLabel *mobaMOBASocketLabel=new QLabel();
                QLabel *mobaFormFactorLabel=new QLabel();
                QLabel *mobaRAMSlotsLabel=new QLabel();
                QLabel *mobaMaxRAMLabel=new QLabel();
                QLabel *mobaMOBAConnectorsLabel=new QLabel();
                componentNameLabel->setText(mobaName);
                componentManufacturerLabel->setText(mobaManufacturer);
                componentLengthLabel->setText(mobaLength);
                componentHeightLabel->setText(mobaHeight);
                componentPriceLabel->setText(mobaPrice);
                componentPowerConsumptionLabel->setText(mobaPowerConsumption);
                mobaMOBASocketLabel->setText(mobaMOBASocket);
                mobaFormFactorLabel->setText(mobaFormFactor);
                mobaRAMSlotsLabel->setText(mobaRAMSlots);
                mobaMaxRAMLabel->setText(mobaMaxRAM);
                mobaMOBAConnectorsLabel->setText(mobaConnectors);
                componentsSpecsLayout=new QFormLayout();
                componentsSpecsLayout->addRow(MOBASocketLabel, mobaMOBASocketLabel);
                componentsSpecsLayout->addRow(RAMSlotsLabel, mobaRAMSlotsLabel);
                componentsSpecsLayout->addRow(MOBAConnectorsLabel, mobaMOBAConnectorsLabel);
                componentsSpecsLayout->addRow(MaxRAMLabel, mobaMaxRAMLabel);
                componentsSpecsLayout->addRow(FormFactorLabel, mobaFormFactorLabel);
                componentsSpecsLayout->setVerticalSpacing(25);
                specLayout->addRow(componentsSpecsLayout);
            }
        }
    }    
}

void MainWindow::showCPUSpecs() {
    resetSpecs();
    if(build->item(1, 0)!=nullptr && (build->item(1, 0))->text()!=componentNameLabel->text()) {
        bool trovato=false;
        QString cpuName=(build->item(1, 0))->text();
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(!trovato && componenti[i]->getName()==cpuName) {
                trovato=true;
                QString cpux64bit;
                QString cpuIntegratedGraphics;
                QString cpuLength=(QString::number(componenti[i]->getLength()));
                QString cpuHeight=(QString::number(componenti[i]->getHeight()));
                QString cpuManufacturer=(componenti[i]->getManufacturer());
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString cpuPrice=QString::fromStdString(price);
                QString cpuPowerConsumption=(QString::number(componenti[i]->getPowerConsumption()));
                CPU* cpu=static_cast<CPU*>(componenti[i]);
                std::string speed=std::to_string(cpu->getCpu_speed());
                speed=removeZero(speed);
                QString cpuSpeed=QString::fromStdString(speed);
                QString cpuCores=(QString::number(cpu->getCores()));
                if(cpu->getX64bit())
                    cpux64bit="Sì";
                else
                    cpux64bit="No";
                QString cpuSocket=cpu->getCpu_socket();
                if(cpu->getIntegrated_graphic())
                    cpuIntegratedGraphics="Sì";
                else
                    cpuIntegratedGraphics="No";
                QLabel *SpeedLabel=new QLabel("Frequenza (GHz): ");
                QLabel *CoresLabel=new QLabel("Cores: ");
                QLabel *x64bitLabel=new QLabel("Supporto 64 bit: ");
                QLabel *cpuSocketLabel=new QLabel("Socket CPU: ");
                QLabel *IntegratedGraphicsLabel=new QLabel("Chip grafico integrato: ");
                QLabel *cpuSpeedLabel=new QLabel();
                QLabel *cpuCoresLabel=new QLabel();
                QLabel *cpux64bitLabel=new QLabel();
                QLabel *cpuCPUSocketLabel=new QLabel();
                QLabel *cpuIntegratedGraphicsLabel=new QLabel();
                componentNameLabel->setText(cpuName);
                componentManufacturerLabel->setText(cpuManufacturer);
                componentLengthLabel->setText(cpuLength);
                componentHeightLabel->setText(cpuHeight);
                componentPriceLabel->setText(cpuPrice);
                componentPowerConsumptionLabel->setText(cpuPowerConsumption);
                cpuSpeedLabel->setText(cpuSpeed);
                cpuCoresLabel->setText(cpuCores);
                cpux64bitLabel->setText(cpux64bit);
                cpuCPUSocketLabel->setText(cpuSocket);
                cpuIntegratedGraphicsLabel->setText(cpuIntegratedGraphics);
                componentsSpecsLayout=new QFormLayout();
                componentsSpecsLayout->addRow(SpeedLabel, cpuSpeedLabel);
                componentsSpecsLayout->addRow(CoresLabel, cpuCoresLabel);
                componentsSpecsLayout->addRow(x64bitLabel, cpux64bitLabel);
                componentsSpecsLayout->addRow(cpuSocketLabel, cpuCPUSocketLabel);
                componentsSpecsLayout->addRow(IntegratedGraphicsLabel, cpuIntegratedGraphicsLabel);
                componentsSpecsLayout->setVerticalSpacing(25);
                specLayout->addRow(componentsSpecsLayout);
            }
        }
    }
}

void MainWindow::showGPUSpecs() {
    resetSpecs();
    if(build->item(2, 0)!=nullptr && (build->item(2, 0))->text()!=componentNameLabel->text()) {
        bool trovato=false;
        QString gpuName=(build->item(2, 0))->text();
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(!trovato && componenti[i]->getName()==gpuName) {
                trovato=true;
                QString gpuSupplementaryPower;
                QString gpuLength=(QString::number(componenti[i]->getLength()));
                QString gpuHeight=(QString::number(componenti[i]->getHeight()));
                QString gpuManufacturer=(componenti[i]->getManufacturer());
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString gpuPrice=QString::fromStdString(price);
                QString gpuPowerConsumption=(QString::number(componenti[i]->getPowerConsumption()));
                GPU *gpu=static_cast<GPU*>(componenti[i]);
                QString gpuType=gpu->getType();
                QString gpuMemorySize=(QString::number(gpu->getMemory_size()));
                std::string performance=std::to_string(gpu->getPerformance());
                performance=removeZero(performance);
                QString gpuPerformance=QString::fromStdString(performance);
                QString gpuClock=(QString::number(gpu->getClock()));
                QString gpuInterface=gpu->getInterface();
                QString gpuConnectors=gpu->getConnectors();
                if(gpu->getSupplementary_power())
                    gpuSupplementaryPower="Sì";
                else
                    gpuSupplementaryPower="No";
                QLabel *gpuTypeLabel=new QLabel("Tipo: ");
                QLabel *gpuMemorySizeLabel=new QLabel("Memoria dedicata (GB): ");
                QLabel *gpuPerformanceLabel=new QLabel("TFLOPs: ");
                QLabel *gpuClockLabel=new QLabel("Clock (MHz): ");
                QLabel *gpuInterfaceLabel=new QLabel("Interfacce: ");
                QLabel *gpuConnectorsLabel=new QLabel("Porte: ");
                QLabel *gpuSupplementaryPowerLabel=new QLabel("Alimentazione supplementare richiesta: ");
                QLabel *gpuGPUTypeLabel=new QLabel();
                QLabel *gpuGPUMemorySizeLabel=new QLabel();
                QLabel *gpuGPUPerformanceLabel=new QLabel();
                QLabel *gpuGPUClockLabel=new QLabel();
                QLabel *gpuGPUInterfaceLabel=new QLabel();
                QLabel *gpuGPUConnectorsLabel=new QLabel();
                QLabel *gpuGPUSupplementaryPowerLabel=new QLabel();
                componentNameLabel->setText(gpuName);
                componentManufacturerLabel->setText(gpuManufacturer);
                componentLengthLabel->setText(gpuLength);
                componentHeightLabel->setText(gpuHeight);
                componentPriceLabel->setText(gpuPrice);
                componentPowerConsumptionLabel->setText(gpuPowerConsumption);
                gpuGPUTypeLabel->setText(gpuType);
                gpuGPUMemorySizeLabel->setText(gpuMemorySize);
                gpuGPUPerformanceLabel->setText(gpuPerformance);
                gpuGPUClockLabel->setText(gpuClock);
                gpuGPUInterfaceLabel->setText(gpuInterface);
                gpuGPUConnectorsLabel->setText(gpuConnectors);
                gpuGPUSupplementaryPowerLabel->setText(gpuSupplementaryPower);
                componentsSpecsLayout=new QFormLayout();
                componentsSpecsLayout->addRow(gpuTypeLabel, gpuGPUTypeLabel);
                componentsSpecsLayout->addRow(gpuMemorySizeLabel, gpuGPUMemorySizeLabel);
                componentsSpecsLayout->addRow(gpuPerformanceLabel, gpuGPUPerformanceLabel);
                componentsSpecsLayout->addRow(gpuClockLabel, gpuGPUClockLabel);
                componentsSpecsLayout->addRow(gpuInterfaceLabel, gpuGPUInterfaceLabel);
                componentsSpecsLayout->addRow(gpuConnectorsLabel, gpuGPUConnectorsLabel);
                componentsSpecsLayout->addRow(gpuSupplementaryPowerLabel, gpuGPUSupplementaryPowerLabel);
                componentsSpecsLayout->setVerticalSpacing(25);
                specLayout->addRow(componentsSpecsLayout);
            }
        }
    }
}

void MainWindow::showPSUSpecs() {
    resetSpecs();
    if(build->item(3, 0)!=nullptr && (build->item(3, 0))->text()!=componentNameLabel->text()) {
        bool trovato=false;
        QString psuName=(build->item(3, 0))->text();
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(!trovato && componenti[i]->getName()==psuName) {
                trovato=true;
                QString psuSupplementaryPower;
                QString psuLength=(QString::number(componenti[i]->getLength()));
                QString psuHeight=(QString::number(componenti[i]->getHeight()));
                QString psuManufacturer=(componenti[i]->getManufacturer());
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString psuPrice=QString::fromStdString(price);
                QString psuPowerConsumption=(QString::number(componenti[i]->getPowerConsumption()));
                PSU *psu=static_cast<PSU*>(componenti[i]);
                QString psuFormFactor=psu->getForm_factor();
                QString psuWattage=(QString::number(psu->getWattage()));
                QString psuEfficiencyCertification=psu->getEfficiency_certification();
                QString psuModularity=psu->getModularity();
                if(psu->getSupplementaryPower()==true)
                    psuSupplementaryPower="Sì";
                else
                    psuSupplementaryPower="No";
                QLabel *psuFormFactorLabel=new QLabel("Form Factor: ");
                QLabel *psuWattageLabel=new QLabel("Wattaggio: ");
                QLabel *psuEfficiencyCertificationLabel=new QLabel("Certificazione di efficienza: ");
                QLabel *psuModularityLabel=new QLabel("Modularità: ");
                QLabel *psuSupplementaryPowerLabel=new QLabel("Predisposizione alimentazione supplementare: ");
                QLabel *psuPSUFormFactorLabel=new QLabel();
                QLabel *psuPSUWattageLabel=new QLabel();
                QLabel *psuPSUEfficiencyCertificationLabel=new QLabel();
                QLabel *psuPSUModularityLabel=new QLabel();
                QLabel *psuPSUSupplementaryPowerLabel=new QLabel();
                componentNameLabel->setText(psuName);
                componentManufacturerLabel->setText(psuManufacturer);
                componentLengthLabel->setText(psuLength);
                componentHeightLabel->setText(psuHeight);
                componentPriceLabel->setText(psuPrice);
                componentPowerConsumptionLabel->setText(psuPowerConsumption);
                psuPSUFormFactorLabel->setText(psuFormFactor);
                psuPSUWattageLabel->setText(psuWattage);
                psuPSUEfficiencyCertificationLabel->setText(psuEfficiencyCertification);
                psuPSUModularityLabel->setText(psuModularity);
                psuPSUSupplementaryPowerLabel->setText(psuSupplementaryPower);
                componentsSpecsLayout=new QFormLayout();
                componentsSpecsLayout->addRow(psuFormFactorLabel, psuPSUFormFactorLabel);
                componentsSpecsLayout->addRow(psuEfficiencyCertificationLabel, psuPSUEfficiencyCertificationLabel);
                componentsSpecsLayout->addRow(psuWattageLabel, psuPSUWattageLabel);
                componentsSpecsLayout->addRow(psuModularityLabel, psuPSUModularityLabel);
                componentsSpecsLayout->addRow(psuSupplementaryPowerLabel, psuPSUSupplementaryPowerLabel);
                componentsSpecsLayout->setVerticalSpacing(25);
                specLayout->addRow(componentsSpecsLayout);
            }
        }
    }
}

void MainWindow::showRAMSpecs() {
    resetSpecs();
    if(build->item(4, 0)!=nullptr && (build->item(4, 0))->text()!=componentNameLabel->text()) {
        bool trovato=false;
        QString ramName=(build->item(4, 0))->text();
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(!trovato && componenti[i]->getName()==ramName) {
                trovato=true;
                QString ramLength=(QString::number(componenti[i]->getLength()));
                QString ramHeight=(QString::number(componenti[i]->getHeight()));
                QString ramManufacturer=(componenti[i]->getManufacturer());
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString ramPrice=QString::fromStdString(price);
                QString ramPowerConsumption=(QString::number(componenti[i]->getPowerConsumption()));
                RAM *ram=static_cast<RAM*>(componenti[i]);
                QString ramSpeed=(QString::number(ram->getRam_speed()));
                QString ramType=ram->getType();
                QString ramSize=(QString::number(ram->getSize()));
                QLabel *ramSpeedLabel=new QLabel("Frequenza (MHz): ");
                QLabel *ramTypeLabel=new QLabel("Tipo: ");
                QLabel *ramSizeLabel=new QLabel("Capacità (GB): ");
                QLabel *ramRAMSpeedLabel=new QLabel();
                QLabel *ramRAMTypeLabel=new QLabel();
                QLabel *ramRAMSizeLabel=new QLabel();
                componentNameLabel->setText(ramName);
                componentManufacturerLabel->setText(ramManufacturer);
                componentLengthLabel->setText(ramLength);
                componentHeightLabel->setText(ramHeight);
                componentPriceLabel->setText(ramPrice);
                componentPowerConsumptionLabel->setText(ramPowerConsumption);
                ramRAMSpeedLabel->setText(ramSpeed);
                ramRAMTypeLabel->setText(ramType);
                ramRAMSizeLabel->setText(ramSize);
                componentsSpecsLayout=new QFormLayout();
                componentsSpecsLayout->addRow(ramSpeedLabel, ramRAMSpeedLabel);
                componentsSpecsLayout->addRow(ramTypeLabel, ramRAMTypeLabel);
                componentsSpecsLayout->addRow(ramSizeLabel, ramRAMSizeLabel);
                componentsSpecsLayout->setVerticalSpacing(25);
                specLayout->addRow(componentsSpecsLayout);
            }
        }
    }
}

void MainWindow::showStorageSpecs() {
    resetSpecs();
    if(build->item(5, 0)!=nullptr && (build->item(5, 0))->text()!=componentNameLabel->text()) {
        bool trovato=false;
        QString storageName=(build->item(5, 0))->text();
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(!trovato && componenti[i]->getName()==storageName) {
                trovato=true;
                QString storageLength=(QString::number(componenti[i]->getLength()));
                QString storageHeight=(QString::number(componenti[i]->getHeight()));
                QString storageManufacturer=(componenti[i]->getManufacturer());
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString storagePrice=QString::fromStdString(price);
                QString storagePowerConsumption=(QString::number(componenti[i]->getPowerConsumption()));
                Storage* storage=static_cast<Storage*>(componenti[i]);
                QString storageType=storage->getType();
                QString storageRPM=(QString::number(storage->getRpm()));
                QString storageSize=(QString::number(storage->getSize()));
                QString storageInterface=storage->getInterface();
                std::string form_factor=std::to_string(storage->getForm_factor());
                form_factor=removeZero(form_factor);
                QString storageFormFactor=QString::fromStdString(form_factor);
                QString storageSpeed=(QString::number(storage->getSpeed()));
                QLabel *storageTypeLabel=new QLabel("Tipo: ");
                QLabel *storageRPMLabel=new QLabel("RPM: ");
                QLabel *storageSizeLabel=new QLabel("Capacità (GB): ");
                QLabel *storageInterfaceLabel=new QLabel("Interfaccia: ");
                QLabel *storageFormFactorLabel=new QLabel("Form Factor: ");
                QLabel *storageSpeedLabel=new QLabel("Velocità trasferimento (MB/s): ");
                QLabel *storageStorageTypeLabel=new QLabel();
                QLabel *storageStorageRPMLabel=new QLabel();
                QLabel *storageStorageSizeLabel=new QLabel();
                QLabel *storageStorageInterfaceLabel=new QLabel();
                QLabel *storageStorageFormFactorLabel=new QLabel();
                QLabel *storageStorageSpeedLabel=new QLabel();
                componentNameLabel->setText(storageName);
                componentManufacturerLabel->setText(storageManufacturer);
                componentLengthLabel->setText(storageLength);
                componentHeightLabel->setText(storageHeight);
                componentPriceLabel->setText(storagePrice);
                componentPowerConsumptionLabel->setText(storagePowerConsumption);
                storageStorageTypeLabel->setText(storageType);
                storageStorageRPMLabel->setText(storageRPM);
                storageStorageSizeLabel->setText(storageSize);
                storageStorageInterfaceLabel->setText(storageInterface);
                storageStorageFormFactorLabel->setText(storageFormFactor);
                storageStorageSpeedLabel->setText(storageSpeed);
                componentsSpecsLayout=new QFormLayout();
                componentsSpecsLayout->addRow(storageTypeLabel, storageStorageTypeLabel);
                componentsSpecsLayout->addRow(storageRPMLabel, storageStorageRPMLabel);
                componentsSpecsLayout->addRow(storageSizeLabel, storageStorageSizeLabel);
                componentsSpecsLayout->addRow(storageInterfaceLabel, storageStorageInterfaceLabel);
                componentsSpecsLayout->addRow(storageFormFactorLabel, storageStorageFormFactorLabel);
                componentsSpecsLayout->addRow(storageSpeedLabel, storageStorageSpeedLabel);
                componentsSpecsLayout->setVerticalSpacing(25);
                specLayout->addRow(componentsSpecsLayout);
            }
        }
    }
}

/*void MainWindow::loadFileToBuild() {
    QString path = QFileDialog::getOpenFileName(this, tr("Load Build"), "", tr("JSON (*.json);"));
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray json=file.readAll();
    file.close();
    QJsonDocument document=QJsonDocument::fromJson(json);
    QJsonArray array=document.object().value("pc_parts").toArray();
    if(!array.isEmpty()) {
        bool componentPresence=false;
        foreach(const QJsonValue& j, array) {
            QString component_type=QString(j.toObject().value("component_type").toString());
            QString component_name=QString(j.toObject().value("name").toString());
            for(unsigned int i=0; i!=componenti.getSize(); ++i) {
                if(component_name==componenti[i]->getName())
                    componentPresence=true;
            }
            if(component_type=="MOBA") {
                if(componentPresence==false) {
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
                    mobaComboBox->addItem(componenti[componenti.getSize()]->getName());
                    componentsList->addItem(componenti[componenti.getSize()]->getName());
                    mobaComboBox->setCurrentIndex(mobaComboBox->count());
                    mobaToBuild();
                }
                else {
                    mobaComboBox->setCurrentIndex(mobaComboBox->findText(componenti[componenti.getSize()]->getName()));
                    mobaToBuild();
                }
            }
        }
    }
}*/

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
    build->setMinimumHeight(233);
    build->setMaximumWidth(674);
    build->setMinimumWidth(674);
    build->setColumnWidth(0, 225);
    build->setColumnWidth(1, 50);
    build->setColumnWidth(2, 61);
    build->setColumnWidth(3, 125);
    build->setColumnWidth(4, 150);
    build->setShowGrid(false);
    removeMOBA=new QPushButton("-");
    removeCPU=new QPushButton("-");
    removeGPU=new QPushButton("-");
    removePSU=new QPushButton("-");
    removeRAM=new QPushButton("-");
    removeStorage=new QPushButton("-");
    mobaSpecs=new QPushButton("≡");
    cpuSpecs=new QPushButton("≡");
    gpuSpecs=new QPushButton("≡");
    psuSpecs=new QPushButton("≡");
    ramSpecs=new QPushButton("≡");
    storageSpecs=new QPushButton("≡");
    build->setIndexWidget(build->model()->index(0,3), mobaSpecs);
    build->setIndexWidget(build->model()->index(0,4), removeMOBA);
    build->setIndexWidget(build->model()->index(1,3), cpuSpecs);
    build->setIndexWidget(build->model()->index(1,4), removeCPU);
    build->setIndexWidget(build->model()->index(2,3), gpuSpecs);
    build->setIndexWidget(build->model()->index(2,4), removeGPU);
    build->setIndexWidget(build->model()->index(3,3), psuSpecs);
    build->setIndexWidget(build->model()->index(3,4), removePSU);
    build->setIndexWidget(build->model()->index(4,3), ramSpecs);
    build->setIndexWidget(build->model()->index(4,4), removeRAM);
    build->setIndexWidget(build->model()->index(5,3), storageSpecs);
    build->setIndexWidget(build->model()->index(5,4), removeStorage);
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
    /*(build->item(0, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(0, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(0, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(1, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(1, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(1, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(2, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(2, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(2, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(3, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(3, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(3, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(4, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(4, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(4, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(5, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(5, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(5, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(6, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(6, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(6, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(6, 3))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    (build->item(6, 4))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);*/

    saveBuild=new QPushButton("Salva Build");
    loadBuild=new QPushButton("Carica Build");
    discardBuild=new QPushButton("Scarta Build");
    saveBuild->setMinimumWidth(150);
    saveBuild->setMaximumWidth(150);
    loadBuild->setMinimumWidth(150);
    loadBuild->setMaximumWidth(150);
    discardBuild->setMinimumWidth(150);
    discardBuild->setMaximumWidth(150);
    buttonsLayout->addWidget(saveBuild);
    buttonsLayout->addWidget(loadBuild);
    buttonsLayout->addWidget(discardBuild);
    layout3->addRow(build);
    layout3->addRow(buttonsLayout);
    layout3->setAlignment(buttonsLayout, Qt::AlignLeft);
    buttonsLayout->setSpacing(10);
    layout3->setVerticalSpacing(30);
    layout3->setContentsMargins(0, 0, 20, 0);

    specLayout=new QFormLayout();
    layout->addLayout(specLayout, 0, 2);
    lengthLabel=new QLabel("Larghezza (mm): ");
    heightLabel=new QLabel("Altezza (mm): ");
    nameLabel=new QLabel("Nome componente: ");
    manufacturerLabel=new QLabel("Produttore: ");
    priceLabel=new QLabel("Prezzo (€): ");
    powerconsumptionLabel=new QLabel("Consumo energetico (W): ");
    componentNameLabel=new QLabel();
    componentLengthLabel=new QLabel();
    componentHeightLabel=new QLabel();
    componentPriceLabel=new QLabel();
    componentPowerConsumptionLabel=new QLabel();
    componentManufacturerLabel=new QLabel();
    specLayout->addRow(nameLabel, componentNameLabel);
    specLayout->addRow(manufacturerLabel, componentManufacturerLabel);
    specLayout->addRow(lengthLabel, componentLengthLabel);
    specLayout->addRow(heightLabel, componentHeightLabel);
    specLayout->addRow(priceLabel, componentPriceLabel);
    specLayout->addRow(powerconsumptionLabel, componentPowerConsumptionLabel);
    specLayout->setVerticalSpacing(25);
    specLayout->setContentsMargins(0, 0, 100, 0);

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
    managementButtonsLayout->setContentsMargins(0, 20, 136, 0);
    layout5->addRow(searchBox);
    layout5->addRow(componentsList);
    layout5->addRow(managementButtonsLayout);

    specLayout2=new QFormLayout();
    layout4->addLayout(specLayout2, 0, 1);
    lengthLabel2=new QLabel("Larghezza (mm): ");
    heightLabel2=new QLabel("Altezza (mm): ");
    nameLabel2=new QLabel("Nome componente: ");
    manufacturerLabel2=new QLabel("Produttore: ");
    priceLabel2=new QLabel("Prezzo (€): ");
    powerconsumptionLabel2=new QLabel("Consumo energetico (W): ");
    componentNameLine=new QLineEdit();
    componentLengthLine=new QLineEdit();
    componentHeightLine=new QLineEdit();
    componentPriceLine=new QLineEdit();
    componentPowerConsumptionLine=new QLineEdit();
    componentManufacturerLine=new QLineEdit();
    specLayout2->addRow(nameLabel2, componentNameLine);
    specLayout2->addRow(manufacturerLabel2, componentManufacturerLine);
    specLayout2->addRow(lengthLabel2, componentLengthLine);
    specLayout2->addRow(heightLabel2, componentHeightLine);
    specLayout2->addRow(priceLabel2, componentPriceLine);
    specLayout2->addRow(powerconsumptionLabel2, componentPowerConsumptionLine);
    specLayout2->setVerticalSpacing(25);
    specLayout2->setContentsMargins(0, 0, 400, 0);

    connect(insertMOBA, SIGNAL(clicked(bool)), this, SLOT(mobaToBuild()));
    connect(insertCPU, SIGNAL(clicked(bool)), this, SLOT(cpuToBuild()));
    connect(insertGPU, SIGNAL(clicked(bool)), this, SLOT(gpuToBuild()));
    connect(insertPSU, SIGNAL(clicked(bool)), this, SLOT(psuToBuild()));
    connect(insertRAM, SIGNAL(clicked(bool)), this, SLOT(ramToBuild()));
    connect(insertStorage, SIGNAL(clicked(bool)), this, SLOT(storageToBuild()));
    connect(removeMOBA, SIGNAL(clicked(bool)), this, SLOT(removeMOBAFromBuild()));
    connect(removeCPU, SIGNAL(clicked(bool)), this, SLOT(removeCPUFromBuild()));
    connect(removeGPU, SIGNAL(clicked(bool)), this, SLOT(removeGPUFromBuild()));
    connect(removePSU, SIGNAL(clicked(bool)), this, SLOT(removePSUFromBuild()));
    connect(removeRAM, SIGNAL(clicked(bool)), this, SLOT(removeRAMFromBuild()));
    connect(removeStorage, SIGNAL(clicked(bool)), this, SLOT(removeStorageFromBuild()));
    connect(discardBuild, SIGNAL(clicked(bool)), this, SLOT(deleteBuild()));
    connect(saveBuild, SIGNAL(clicked(bool)), this, SLOT(saveBuildToFile()));
    connect(mobaSpecs, SIGNAL(clicked(bool)), this, SLOT(showMOBASpecs()));
    connect(cpuSpecs, SIGNAL(clicked(bool)), this, SLOT(showCPUSpecs()));
    connect(gpuSpecs, SIGNAL(clicked(bool)), this, SLOT(showGPUSpecs()));
    connect(psuSpecs, SIGNAL(clicked(bool)), this, SLOT(showPSUSpecs()));
    connect(ramSpecs, SIGNAL(clicked(bool)), this, SLOT(showRAMSpecs()));
    connect(storageSpecs, SIGNAL(clicked(bool)), this, SLOT(showStorageSpecs()));
    connect(searchBox, SIGNAL(textEdited(QString)), this, SLOT(searchComponents(QString)));
    connect(removeComponent, SIGNAL(clicked(bool)), this, SLOT(removeComponents()));
    connect(editComponent, SIGNAL(clicked(bool)), this, SLOT(editComponentsSpecs()));
    connect(addComponent, SIGNAL(clicked(bool)), this, SLOT(addComponents()));
    //connect(loadBuild, SIGNAL(clicked(bool)), this, SLOT(loadFileToBuild()));
    load("../Qontainer/database.json");
    tab->setMinimumSize(1800, 750);
    tab->setMaximumSize(1800, 750);
    tab->move(100, 100);
    tab->show();
}
