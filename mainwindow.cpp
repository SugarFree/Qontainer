#include "mainwindow.h"
#include <iostream>

//funzione per rimuovere gli zeri in eccesso nella conversione da double a QString
std::string MainWindow::removeZero(std::string str) {
    str.erase(str.find(',')+3, str.size());
    return str;
}

//metodo per inserire la MOBA selezionata sulla combobox nella build
void MainWindow::mobaToBuild() {
    if(mobaComboBox->currentText()!="") {
        QString mobaName=mobaComboBox->currentText();
        if(build->item(0, 0)!=nullptr && mobaName!=(build->item(0, 0))->text())
            resetSpecs();
        build->setItem(0, 0, new QTableWidgetItem(mobaName));
        for(unsigned int i=0; i!=componenti.getSize(); ++i) {
            if(dynamic_cast<MOBA*>(componenti[i])!=nullptr && componenti[i]->getName()==mobaName) {
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString price2=QString::fromStdString(price);
                build->setItem(0, 1, new QTableWidgetItem(QString::number(componenti[i]->Rating())));
                build->setItem(0, 2, new QTableWidgetItem(price2));
                (build->item(0, 1))->setTextAlignment(Qt::AlignCenter);
                (build->item(0, 2))->setTextAlignment(Qt::AlignCenter);
                (build->item(0, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                (build->item(0, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                (build->item(0, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                calculateTotal();
            }
        }
    }
}

//metodo per inserire la CPU selezionata sulla combobox nella build
void MainWindow::cpuToBuild() {
    if(cpuComboBox->currentText()!="") {
        QString cpuName=cpuComboBox->currentText();
        if(build->item(1, 0)!=nullptr && cpuName!=(build->item(1, 0))->text())
            resetSpecs();
        build->setItem(1, 0, new QTableWidgetItem(cpuName));
        for(unsigned int i=0; i!=componenti.getSize(); ++i) {
            if(dynamic_cast<CPU*>(componenti[i])!=nullptr && componenti[i]->getName()==cpuName) {
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString price2=QString::fromStdString(price);
                build->setItem(1, 1, new QTableWidgetItem(QString::number(componenti[i]->Rating())));
                build->setItem(1, 2, new QTableWidgetItem(price2));
                (build->item(1, 1))->setTextAlignment(Qt::AlignCenter);
                (build->item(1, 2))->setTextAlignment(Qt::AlignCenter);
                (build->item(1, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                (build->item(1, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                (build->item(1, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                calculateTotal();
            }
        }
    }
}

//metodo per inserire la GPU selezionata sulla combobox nella build
void MainWindow::gpuToBuild() {
    if(gpuComboBox->currentText()!="") {
        QString gpuName=gpuComboBox->currentText();
        if(build->item(2, 0)!=nullptr && gpuName!=(build->item(2, 0))->text())
            resetSpecs();
        build->setItem(2, 0, new QTableWidgetItem(gpuName));
        for(unsigned int i=0; i!=componenti.getSize(); ++i) {
            if(dynamic_cast<GPU*>(componenti[i])!=nullptr && componenti[i]->getName()==gpuName) {
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString price2=QString::fromStdString(price);
                build->setItem(2, 1, new QTableWidgetItem(QString::number(componenti[i]->Rating())));
                build->setItem(2, 2, new QTableWidgetItem(price2));
                (build->item(2, 1))->setTextAlignment(Qt::AlignCenter);
                (build->item(2, 2))->setTextAlignment(Qt::AlignCenter);
                (build->item(2, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                (build->item(2, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                (build->item(2, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                calculateTotal();
            }
        }
    }
}

//metodo per inserire la PSU selezionata sulla combobox nella build
void MainWindow::psuToBuild() {
    if(psuComboBox->currentText()!="") {
        QString psuName=psuComboBox->currentText();
        if(build->item(3, 0)!=nullptr && psuName!=(build->item(3, 0))->text())
            resetSpecs();
        build->setItem(3, 0, new QTableWidgetItem(psuName));
        for(unsigned int i=0; i!=componenti.getSize(); ++i) {
            if(dynamic_cast<PSU*>(componenti[i])!=nullptr && componenti[i]->getName()==psuName) {
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString price2=QString::fromStdString(price);
                build->setItem(3, 1, new QTableWidgetItem(QString::number(componenti[i]->Rating())));
                build->setItem(3, 2, new QTableWidgetItem(price2));
                (build->item(3, 1))->setTextAlignment(Qt::AlignCenter);
                (build->item(3, 2))->setTextAlignment(Qt::AlignCenter);
                (build->item(3, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                (build->item(3, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                (build->item(3, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                calculateTotal();
            }
        }
    }
}

//metodo per inserire la RAM selezionata sulla combobox nella build
void MainWindow::ramToBuild() {
    if(ramComboBox->currentText()!="") {
        QString ramName=ramComboBox->currentText();
        if(build->item(4, 0)!=nullptr && ramName!=(build->item(4, 0))->text())
            resetSpecs();
        build->setItem(4, 0, new QTableWidgetItem(ramName));
        for(unsigned int i=0; i!=componenti.getSize(); ++i) {
            if(dynamic_cast<RAM*>(componenti[i])!=nullptr && componenti[i]->getName()==ramName) {
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString price2=QString::fromStdString(price);
                build->setItem(4, 1, new QTableWidgetItem(QString::number(componenti[i]->Rating())));
                build->setItem(4, 2, new QTableWidgetItem(price2));
                (build->item(4, 1))->setTextAlignment(Qt::AlignCenter);
                (build->item(4, 2))->setTextAlignment(Qt::AlignCenter);
                (build->item(4, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                (build->item(4, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                (build->item(4, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                calculateTotal();
            }
        }
    }
}

//metodo per inserire lo Storage selezionato sulla combobox nella build
void MainWindow::storageToBuild() {
    if(storageComboBox->currentText()!="") {
        QString storageName=storageComboBox->currentText();
        if(build->item(5, 0)!=nullptr && storageName!=(build->item(5, 0))->text())
            resetSpecs();
        build->setItem(5, 0, new QTableWidgetItem(storageName));
        for(unsigned int i=0; i!=componenti.getSize(); ++i) {
            if(dynamic_cast<Storage*>(componenti[i])!=nullptr && componenti[i]->getName()==storageName) {
                std::string price=std::to_string(componenti[i]->getPrice());
                price=removeZero(price);
                QString price2=QString::fromStdString(price);
                build->setItem(5, 1, new QTableWidgetItem(QString::number(componenti[i]->Rating())));
                build->setItem(5, 2, new QTableWidgetItem(price2));
                (build->item(5, 1))->setTextAlignment(Qt::AlignCenter);
                (build->item(5, 2))->setTextAlignment(Qt::AlignCenter);
                (build->item(5, 0))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                (build->item(5, 1))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                (build->item(5, 2))->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                calculateTotal();
            }
        }
    }
}

//funzione che calcola il rating e il prezzo totale della build
void MainWindow::calculateTotal() {
    if(build->item(0, 0)!=nullptr || build->item(1, 0)!=nullptr || build->item(2, 0)!=nullptr ||
       build->item(3, 0)!=nullptr || build->item(4, 0)!=nullptr || build->item(5, 0)!=nullptr) {
        int totalRating=0, j=0;
        double totalPrice=0;
        for(unsigned int i=0; i!=componenti.getSize(); i++) {
            if((build->item(0, 0)!=nullptr && componenti[i]->getName()==build->item(0, 0)->text()) || (build->item(1, 0)!=nullptr && componenti[i]->getName()==build->item(1, 0)->text()) ||
               (build->item(2, 0)!=nullptr && componenti[i]->getName()==build->item(2, 0)->text()) || (build->item(3, 0)!=nullptr && componenti[i]->getName()==build->item(3, 0)->text()) ||
               (build->item(4, 0)!=nullptr && componenti[i]->getName()==build->item(4, 0)->text()) || (build->item(5, 0)!=nullptr && componenti[i]->getName()==build->item(5, 0)->text())) {
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

//funzione che nasconde tutti gli elementi nella lista dei componenti
void MainWindow::hideAll() {
  for(int i=0; i!=componentsList->count(); i++)
    componentsList->item(i)->setHidden(true);
}

//funzione che mostra solo gli elementi della lista componenti che matchano la stringa cercata
void MainWindow::searchComponents(QString search_str) {
      hideAll();
      QList<QListWidgetItem*> matches (componentsList->findItems(search_str, Qt::MatchFlag::MatchContains));
      for(QListWidgetItem* item:matches)
          item->setHidden(false);
}

//metodo che rimuove il componente selezionato dalla lista componenti e dal contenitore
void MainWindow::removeComponents() {
    if(componentsList->currentItem()!=nullptr) {
        bool trovato=false;
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(componenti[i]->getName()==(componentsList->currentItem())->text()) {
                trovato=true;
                int pos;
                QString *componentName=new QString(componenti[i]->getName());
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
                pos=componentsNames.search(componentName);
                if(pos!=-1)
                    componentsNames.erase(pos);
            }
        }
    }
}

//reset del layout di modifica dei componenti
void MainWindow::resetEditSpecs() {
    componentNameLine->setText("");
    componentLengthSpin->setValue(0);
    componentHeightSpin->setValue(0);
    componentPriceSpin->setValue(0);
    componentPowerConsumptionSpin->setValue(0);
    componentManufacturerLine->setText("");
    while(componentsSpecsLayout2->count()!=0) {
        QLayoutItem *item=componentsSpecsLayout2->takeAt(0);
        delete item->widget();
        delete item;
    }
    specLayout2->takeRow(componentsSpecsLayout2);
}

//metodo che annulla il processo di modifica del componente e riattiva la lista dei componenti
void MainWindow::discardComponentsChanges() {
    resetEditSpecs();
    for(int i=0; i!=componentsList->count(); ++i) {
        QListWidgetItem *item=componentsList->item(i);
        auto flags=item->flags();
        flags.setFlag(Qt::ItemIsEnabled, true);
        item->setFlags(flags);
    }
}

//metodo che salva le caratteristiche del nuovo componente sul contenitore inserendolo nella combobox e nella lista dei componenti
void MainWindow::saveNewComponent(QString type) {
    if(type=="MOBA") {
        if(componentNameLine->text()=="")
            componentNameLine->setText("Componente generico");
        componenti.push_back(new MOBA(componentLengthSpin->value(), componentHeightSpin->value(), componentNameLine->text(),
                                      componentManufacturerLine->text(), componentPriceSpin->value(), componentPowerConsumptionSpin->value(),
                                      mobaMOBASocketLine->text(), mobaMOBAFormFactorLine->text(), mobaMOBARAMSlotsSpin->value(), mobaMOBAmaxRAMSpin->value(),
                                      mobaMOBAConnectorsLine->text()));
        mobaComboBox->addItem(componenti[componenti.getSize()-1]->getName());
        componentsList->addItem(componenti[componenti.getSize()-1]->getName());
        discardComponentsChanges();
    }
    if(type=="CPU") {
        if(componentNameLine->text()=="")
            componentNameLine->setText("Componente generico");
        componenti.push_back(new CPU(componentLengthSpin->value(), componentHeightSpin->value(), componentNameLine->text(),
                                     componentManufacturerLine->text(), componentPriceSpin->value(), componentPowerConsumptionSpin->value(),
                                     cpuCPUSpeedSpin->value(), cpuCPUCoresSpin->value(), cpuCPUx64bitCheck->isChecked(), cpuCPUSocketLine->text(),
                                     cpuCPUIntegratedGraphicCheck->isChecked()));
        cpuComboBox->addItem(componenti[componenti.getSize()-1]->getName());
        componentsList->addItem(componenti[componenti.getSize()-1]->getName());
        discardComponentsChanges();
    }
    if(type=="GPU") {
        if(componentNameLine->text()=="")
            componentNameLine->setText("Componente generico");
        componenti.push_back(new GPU(componentLengthSpin->value(), componentHeightSpin->value(), componentNameLine->text(),
                                     componentManufacturerLine->text(), componentPriceSpin->value(), componentPowerConsumptionSpin->value(),
                                     gpuGPUTypeLine->text(), gpuGPUMemorySizeSpin->value(), gpuGPUPerformanceSpin->value(),
                                     gpuGPUClockSpin->value(), gpuGPUInterfaceLine->text(), gpuGPUConnectorsLine->text(),
                                     gpuGPUSupplementaryPowerCheck->isChecked()));
        gpuComboBox->addItem(componenti[componenti.getSize()-1]->getName());
        componentsList->addItem(componenti[componenti.getSize()-1]->getName());
        discardComponentsChanges();
    }
    if(type=="PSU") {
        if(componentNameLine->text()=="")
            componentNameLine->setText("Componente generico");
        componenti.push_back(new PSU(componentLengthSpin->value(), componentHeightSpin->value(), componentNameLine->text(),
                                     componentManufacturerLine->text(), componentPriceSpin->value(), componentPowerConsumptionSpin->value(),
                                     psuPSUFormFactorLine->text(), psuPSUWattageSpin->value(), psuPSUEfficiencyCertificationLine->text(),
                                     psuPSUModularityLine->text(), psuPSUSupplementaryPowerCheck->isChecked()));
        psuComboBox->addItem(componenti[componenti.getSize()-1]->getName());
        componentsList->addItem(componenti[componenti.getSize()-1]->getName());
        discardComponentsChanges();
    }
    if(type=="RAM") {
        if(componentNameLine->text()=="")
            componentNameLine->setText("Componente generico");
        componenti.push_back(new RAM(componentLengthSpin->value(), componentHeightSpin->value(), componentNameLine->text(),
                                     componentManufacturerLine->text(), componentPriceSpin->value(), componentPowerConsumptionSpin->value(),
                                     ramRAMSpeedSpin->value(), ramRAMTypeLine->text(), ramRAMSizeSpin->value()));
        ramComboBox->addItem(componenti[componenti.getSize()-1]->getName());
        componentsList->addItem(componenti[componenti.getSize()-1]->getName());
        discardComponentsChanges();
    }
    if(type=="Storage") {
        if(componentNameLine->text()=="")
            componentNameLine->setText("Componente generico");
        componenti.push_back(new Storage(componentLengthSpin->value(), componentHeightSpin->value(), componentNameLine->text(),
                                         componentManufacturerLine->text(), componentPriceSpin->value(), componentPowerConsumptionSpin->value(),
                                         storageStorageTypeLine->text(), storageStorageRPMSpin->value(), storageStorageSizeSpin->value(),
                                         storageStorageInterfaceLine->text(), storageStorageFormFactorSpin->value(), storageStorageSpeedSpin->value()));
        storageComboBox->addItem(componenti[componenti.getSize()-1]->getName());
        componentsList->addItem(componenti[componenti.getSize()-1]->getName());
        discardComponentsChanges();
    }
}

//metodo che imposta il layout per l'aggiunta del nuovo componente
void MainWindow::newComponentEdit(QString type) {
    componentType->close();
    if(componentNameLine->text()!="")
        resetEditSpecs();
    componentsSpecsLayout2=new QFormLayout();
    for(int i=0; i!=componentsList->count(); ++i) {
        QListWidgetItem *item=componentsList->item(i);
        auto flags=item->flags();
        flags.setFlag(Qt::ItemIsEnabled, false);
        item->setFlags(flags);
    }
    if(type=="MOBA") {
        specLabels(type);
        mobaMOBASocketLine=new QLineEdit();
        mobaMOBAFormFactorLine=new QLineEdit();
        mobaMOBARAMSlotsSpin=new QSpinBox();
        mobaMOBAmaxRAMSpin=new QSpinBox();
        mobaMOBAConnectorsLine=new QLineEdit();
        componentsSpecsLayout2->addRow(mobaSocketLabel, mobaMOBASocketLine);
        componentsSpecsLayout2->addRow(mobaFormFactorLabel, mobaMOBAFormFactorLine);
        componentsSpecsLayout2->addRow(mobaRAMSlotsLabel, mobaMOBARAMSlotsSpin);
        componentsSpecsLayout2->addRow(mobaMaxRAMLabel, mobaMOBAmaxRAMSpin);
        componentsSpecsLayout2->addRow(mobaConnectorsLabel, mobaMOBAConnectorsLine);
    }
    if(type=="CPU") {
        specLabels(type);
        cpuCPUSpeedSpin=new QDoubleSpinBox();
        cpuCPUCoresSpin=new QSpinBox();
        cpuCPUx64bitCheck=new QCheckBox();
        cpuCPUSocketLine=new QLineEdit();
        cpuCPUIntegratedGraphicCheck=new QCheckBox();
        componentsSpecsLayout2->addRow(cpuSpeedLabel, cpuCPUSpeedSpin);
        componentsSpecsLayout2->addRow(cpuCoresLabel, cpuCPUCoresSpin);
        componentsSpecsLayout2->addRow(cpux64bitLabel, cpuCPUx64bitCheck);
        componentsSpecsLayout2->addRow(cpuSocketLabel, cpuCPUSocketLine);
        componentsSpecsLayout2->addRow(cpuIntegratedGraphicsLabel, cpuCPUIntegratedGraphicCheck);
    }
    if(type=="GPU") {
        specLabels(type);
        gpuGPUTypeLine=new QLineEdit();
        gpuGPUMemorySizeSpin=new QSpinBox();
        gpuGPUPerformanceSpin=new QDoubleSpinBox();
        gpuGPUClockSpin=new QSpinBox();
        gpuGPUInterfaceLine=new QLineEdit();
        gpuGPUConnectorsLine=new QLineEdit();
        gpuGPUSupplementaryPowerCheck=new QCheckBox();
        componentsSpecsLayout2->addRow(gpuTypeLabel, gpuGPUTypeLine);
        componentsSpecsLayout2->addRow(gpuMemorySizeLabel, gpuGPUMemorySizeSpin);
        componentsSpecsLayout2->addRow(gpuPerformanceLabel, gpuGPUPerformanceSpin);
        componentsSpecsLayout2->addRow(gpuClockLabel, gpuGPUClockSpin);
        componentsSpecsLayout2->addRow(gpuInterfaceLabel, gpuGPUInterfaceLine);
        componentsSpecsLayout2->addRow(gpuConnectorsLabel, gpuGPUConnectorsLine);
        componentsSpecsLayout2->addRow(gpuSupplementaryPowerLabel, gpuGPUSupplementaryPowerCheck);
    }
    if(type=="PSU") {
        specLabels(type);
        psuPSUFormFactorLine=new QLineEdit();
        psuPSUWattageSpin=new QSpinBox();
        psuPSUEfficiencyCertificationLine=new QLineEdit();
        psuPSUModularityLine=new QLineEdit();
        psuPSUSupplementaryPowerCheck=new QCheckBox();
        componentsSpecsLayout2->addRow(psuFormFactorLabel, psuPSUFormFactorLine);
        componentsSpecsLayout2->addRow(psuEfficiencyCertificationLabel, psuPSUEfficiencyCertificationLine);
        componentsSpecsLayout2->addRow(psuWattageLabel, psuPSUWattageSpin);
        componentsSpecsLayout2->addRow(psuModularityLabel, psuPSUModularityLine);
        componentsSpecsLayout2->addRow(psuSupplementaryPowerLabel, psuPSUSupplementaryPowerCheck);
    }
    if(type=="RAM") {
        specLabels(type);
        ramRAMSpeedSpin=new QSpinBox();
        ramRAMTypeLine=new QLineEdit();
        ramRAMSizeSpin=new QSpinBox();
        componentsSpecsLayout2->addRow(ramSpeedLabel, ramRAMSpeedSpin);
        componentsSpecsLayout2->addRow(ramTypeLabel, ramRAMTypeLine);
        componentsSpecsLayout2->addRow(ramSizeLabel, ramRAMSizeSpin);
    }
    if(type=="Storage") {
        specLabels(type);
        storageStorageTypeLine=new QLineEdit();
        storageStorageRPMSpin=new QSpinBox();
        storageStorageSizeSpin=new QSpinBox();
        storageStorageInterfaceLine=new QLineEdit();
        storageStorageFormFactorSpin=new QDoubleSpinBox();
        storageStorageSpeedSpin=new QSpinBox();
        componentsSpecsLayout2->addRow(storageTypeLabel, storageStorageTypeLine);
        componentsSpecsLayout2->addRow(storageRPMLabel, storageStorageRPMSpin);
        componentsSpecsLayout2->addRow(storageSizeLabel, storageStorageSizeSpin);
        componentsSpecsLayout2->addRow(storageInterfaceLabel, storageStorageInterfaceLine);
        componentsSpecsLayout2->addRow(storageFormFactorLabel, storageStorageFormFactorSpin);
        componentsSpecsLayout2->addRow(storageSpeedLabel, storageStorageSpeedSpin);
    }
    saveComponent=new QPushButton("Salva nuovo componente");
    discardComponent=new QPushButton("Scarta nuovo componente");
    componentsSpecsLayout2->addRow(saveComponent);
    componentsSpecsLayout2->addRow(discardComponent);
    componentsSpecsLayout2->setVerticalSpacing(25);
    specLayout2->addRow(componentsSpecsLayout2);
    connect(saveComponent, &QPushButton::clicked, this, [this, type]{saveNewComponent(type);});
    connect(discardComponent, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
}

//finestra di dialogo che permette di scegliere che tipo di componente si vuole aggiungere
void MainWindow::addComponents() {
    componentType=new QDialog(this);
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

//metodo che permette di salvare le modifiche del componente sul contenitore
void MainWindow::saveComponentsChanges() {
    QString componentName=(componentsList->currentItem())->text();
    bool trovato=false;
    for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
        if(!trovato && componenti[i]->getName()==componentName) {
            trovato=true;
            if(componentNameLine->text()!=componenti[i]->getName()) {
                mobaComboBox->setItemText(mobaComboBox->findText(componentName), componentNameLine->text());
                componenti[i]->setName(componentNameLine->text());
            }
            if(componentLengthSpin->value()!=componenti[i]->getLength())
                componenti[i]->setLength(componentLengthSpin->value());
            if(componentHeightSpin->value()!=componenti[i]->getHeight())
                componenti[i]->setHeight(componentHeightSpin->value());
            if(componentPriceSpin->value()!=componenti[i]->getPrice())
                componenti[i]->setPrice(componentPriceSpin->value());
            if(componentPowerConsumptionSpin->value()!=componenti[i]->getPowerConsumption())
                componenti[i]->setPowerConsumption(componentPowerConsumptionSpin->value());
            if(componentManufacturerLine->text()!=componenti[i]->getManufacturer())
                componenti[i]->setManufacturer(componentManufacturerLine->text());
            if(dynamic_cast<MOBA*>(componenti[i])!=nullptr) {
                MOBA* moba=static_cast<MOBA*>(componenti[i]);
                if((build->item(0, 0))!=nullptr && (build->item(0, 0))->text()==componentName)
                    removeMOBAFromBuild();
                if(mobaMOBASocketLine->text()!=moba->getMOBASocket())
                    moba->setMOBASocket(mobaMOBASocketLine->text());
                if(mobaMOBAFormFactorLine->text()!=moba->getFormFactor())
                    moba->setFormFactor(mobaMOBAFormFactorLine->text());
                if(mobaMOBARAMSlotsSpin->value()!=moba->getRAMSlots())
                    moba->setRAMSlots(mobaMOBARAMSlotsSpin->value());
                if(mobaMOBAmaxRAMSpin->value()!=moba->getMaxRAM())
                    moba->setMaxRAM(mobaMOBAmaxRAMSpin->value());
                if(mobaMOBAConnectorsLine->text()!=moba->getConnectors())
                    moba->setConnectors(mobaMOBAConnectorsLine->text());
                (componentsList->currentItem())->setText(componentNameLine->text());
            }
            if(dynamic_cast<CPU*>(componenti[i])!=nullptr) {
                CPU* cpu=static_cast<CPU*>(componenti[i]);
                if((build->item(1, 0))!=nullptr && (build->item(1, 0))->text()==componentName)
                    removeCPUFromBuild();
                if(cpuCPUSpeedSpin->value()!=cpu->getCpuSpeed())
                    cpu->setCpuSpeed(cpuCPUSpeedSpin->value());
                if(cpuCPUCoresSpin->value()!=cpu->getCores())
                    cpu->setCores(cpuCPUCoresSpin->value());
                if(cpuCPUx64bitCheck->isChecked()!=cpu->getx64bit())
                    cpu->setx64bit(cpuCPUx64bitCheck->isChecked());
                if(cpuCPUSocketLine->text()!=cpu->getCpuSocket())
                    cpu->setCpuSocket(cpuCPUSocketLine->text());
                if(cpuCPUIntegratedGraphicCheck->isChecked()!=cpu->getIntegratedGraphic())
                    cpu->setIntegratedGraphic(cpuCPUIntegratedGraphicCheck->isChecked());
                (componentsList->currentItem())->setText(componentNameLine->text());
            }
            if(dynamic_cast<GPU*>(componenti[i])!=nullptr) {
                GPU* gpu=static_cast<GPU*>(componenti[i]);
                if((build->item(2, 0))!=nullptr && (build->item(2, 0))->text()==componentName)
                    removeGPUFromBuild();
                if(gpuGPUTypeLine->text()!=gpu->getType())
                    gpu->setType(gpuGPUTypeLine->text());
                if(gpuGPUMemorySizeSpin->value()!=gpu->getMemorySize())
                    gpu->setMemorySize(gpuGPUMemorySizeSpin->value());
                if(gpuGPUPerformanceSpin->value()!=gpu->getPerformance())
                    gpu->setPerformance(gpuGPUPerformanceSpin->value());
                if(gpuGPUClockSpin->value()!=gpu->getClock())
                    gpu->setClock(gpuGPUClockSpin->value());
                if(gpuGPUInterfaceLine->text()!=gpu->getInterface())
                    gpu->setInterface(gpuGPUInterfaceLine->text());
                if(gpuGPUConnectorsLine->text()!=gpu->getConnectors())
                    gpu->setConnectors(gpuGPUConnectorsLine->text());
                if(gpuGPUSupplementaryPowerCheck->isChecked()!=gpu->getSupplementaryPower())
                    gpu->setSupplementaryPower(gpuGPUSupplementaryPowerCheck->isChecked());
                (componentsList->currentItem())->setText(componentNameLine->text());
            }
            if(dynamic_cast<PSU*>(componenti[i])!=nullptr) {
                PSU* psu=static_cast<PSU*>(componenti[i]);
                if((build->item(3, 0))!=nullptr && (build->item(3, 0))->text()==componentName)
                    removePSUFromBuild();
                if(psuPSUFormFactorLine->text()!=psu->getFormFactor())
                    psu->setFormFactor(psuPSUFormFactorLine->text());
                if(psuPSUWattageSpin->value()!=psu->getWattage())
                    psu->setWattage(psuPSUWattageSpin->value());
                if(psuPSUEfficiencyCertificationLine->text()!=psu->getEfficiencyCertification())
                    psu->setEfficiencyCertification(psuPSUEfficiencyCertificationLine->text());
                if(psuPSUModularityLine->text()!=psu->getModularity())
                    psu->setModularity(psuPSUModularityLine->text());
                if(psuPSUSupplementaryPowerCheck->isChecked()!=psu->getSupplementaryPower())
                    psu->setSupplementaryPower(psuPSUSupplementaryPowerCheck->isChecked());
                (componentsList->currentItem())->setText(componentNameLine->text());
            }
            if(dynamic_cast<RAM*>(componenti[i])!=nullptr) {
                RAM* ram=static_cast<RAM*>(componenti[i]);
                if((build->item(4, 0))!=nullptr && (build->item(4, 0))->text()==componentName)
                    removeRAMFromBuild();
                if(ramRAMSpeedSpin->value()!=ram->getRamSpeed())
                    ram->setRamSpeed(ramRAMSpeedSpin->value());
                if(ramRAMTypeLine->text()!=ram->getType())
                    ram->setType(ramRAMTypeLine->text());
                if(ramRAMSizeSpin->value()!=ram->getSize())
                    ram->setSize(ramRAMSizeSpin->value());
                (componentsList->currentItem())->setText(componentNameLine->text());
            }
            if(dynamic_cast<Storage*>(componenti[i])!=nullptr) {
                Storage* storage=static_cast<Storage*>(componenti[i]);
                if((build->item(5, 0))!=nullptr && (build->item(5, 0))->text()==componentName)
                    removeStorageFromBuild();
                if(storageStorageTypeLine->text()!=storage->getType())
                    storage->setType(storageStorageTypeLine->text());
                if(storageStorageRPMSpin->value()!=storage->getRPM())
                    storage->setRPM(storageStorageRPMSpin->value());
                if(storageStorageSizeSpin->value()!=storage->getSize())
                    storage->setSize(storageStorageSizeSpin->value());
                if(storageStorageInterfaceLine->text()!=storage->getInterface())
                    storage->setInterface(storageStorageInterfaceLine->text());
                if(storageStorageFormFactorSpin->value()!=storage->getFormFactor())
                    storage->setFormFactor(storageStorageFormFactorSpin->value());
                if(storageStorageSpeedSpin->value()!=storage->getSpeed())
                    storage->setSpeed(storageStorageSpeedSpin->value());
                (componentsList->currentItem())->setText(componentNameLine->text());
            }
            discardComponentsChanges();
        }
    }
}

//metodo che imposta il layout per la modifica di un componente
void MainWindow::editComponentsSpecs() {
    if(componentNameLine->text()!="")
        resetEditSpecs();
    componentsSpecsLayout2=new QFormLayout;
    if(componentsList->currentItem()!=nullptr && (componentsList->currentItem())->text()!=componentNameLine->text()) {
        bool trovato=false;
        for(int i=0; i!=componentsList->count(); ++i) {
            QListWidgetItem *item=componentsList->item(i);
            auto flags=item->flags();
            flags.setFlag(Qt::ItemIsEnabled, false);
            item->setFlags(flags);
        }
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            componentNameLine->setText(componenti[i]->getName());
            componentManufacturerLine->setText(componenti[i]->getManufacturer());
            componentLengthSpin->setValue(componenti[i]->getLength());
            componentHeightSpin->setValue(componenti[i]->getHeight());
            componentPriceSpin->setValue(componenti[i]->getPrice());
            componentPowerConsumptionSpin->setValue(componenti[i]->getPowerConsumption());
            if(dynamic_cast<MOBA*>(componenti[i])!=nullptr) {
                QString mobaName=(componentsList->currentItem())->text();
                if(!trovato && componenti[i]->getName()==mobaName) {
                    trovato=true;
                    QString type="MOBA";
                    MOBA* moba=static_cast<MOBA*>(componenti[i]);
                    specLabels(type);
                    mobaMOBASocketLine=new QLineEdit(moba->getMOBASocket());
                    mobaMOBAFormFactorLine=new QLineEdit(moba->getFormFactor());
                    mobaMOBARAMSlotsSpin=new QSpinBox();
                    mobaMOBARAMSlotsSpin->setValue(moba->getRAMSlots());
                    mobaMOBAmaxRAMSpin=new QSpinBox();
                    mobaMOBAmaxRAMSpin->setValue(moba->getMaxRAM());
                    mobaMOBAConnectorsLine=new QLineEdit(moba->getConnectors());
                    componentsSpecsLayout2->addRow(mobaSocketLabel, mobaMOBASocketLine);
                    componentsSpecsLayout2->addRow(mobaFormFactorLabel, mobaMOBAFormFactorLine);
                    componentsSpecsLayout2->addRow(mobaRAMSlotsLabel, mobaMOBARAMSlotsSpin);
                    componentsSpecsLayout2->addRow(mobaMaxRAMLabel, mobaMOBAmaxRAMSpin);
                    componentsSpecsLayout2->addRow(mobaConnectorsLabel, mobaMOBAConnectorsLine);
                }
            }
            if(dynamic_cast<CPU*>(componenti[i])!=nullptr) {
                QString cpuName=(componentsList->currentItem())->text();
                if(!trovato && componenti[i]->getName()==cpuName) {
                    trovato=true;
                    QString type="CPU";
                    CPU* cpu=static_cast<CPU*>(componenti[i]);
                    specLabels(type);
                    cpuCPUSpeedSpin=new QDoubleSpinBox();
                    cpuCPUSpeedSpin->setValue(cpu->getCpuSpeed());
                    cpuCPUCoresSpin=new QSpinBox();
                    cpuCPUCoresSpin->setValue(cpu->getCores());
                    cpuCPUx64bitCheck=new QCheckBox();
                    cpuCPUx64bitCheck->setChecked(cpu->getx64bit());
                    cpuCPUSocketLine=new QLineEdit(cpu->getCpuSocket());
                    cpuCPUIntegratedGraphicCheck=new QCheckBox();
                    cpuCPUIntegratedGraphicCheck->setChecked(cpu->getIntegratedGraphic());
                    componentsSpecsLayout2->addRow(cpuSpeedLabel, cpuCPUSpeedSpin);
                    componentsSpecsLayout2->addRow(cpuCoresLabel, cpuCPUCoresSpin);
                    componentsSpecsLayout2->addRow(cpux64bitLabel, cpuCPUx64bitCheck);
                    componentsSpecsLayout2->addRow(cpuSocketLabel, cpuCPUSocketLine);
                    componentsSpecsLayout2->addRow(cpuIntegratedGraphicsLabel, cpuCPUIntegratedGraphicCheck);
                }
            }
            if(dynamic_cast<GPU*>(componenti[i])!=nullptr) {
                QString gpuName=(componentsList->currentItem())->text();
                if(!trovato && componenti[i]->getName()==gpuName) {
                    trovato=true;
                    QString type="GPU";
                    GPU *gpu=static_cast<GPU*>(componenti[i]);
                    specLabels(type);
                    gpuGPUTypeLine=new QLineEdit(gpu->getType());
                    gpuGPUMemorySizeSpin=new QSpinBox();
                    gpuGPUMemorySizeSpin->setValue(gpu->getMemorySize());
                    gpuGPUPerformanceSpin=new QDoubleSpinBox();
                    gpuGPUPerformanceSpin->setValue(gpu->getPerformance());
                    gpuGPUClockSpin=new QSpinBox();
                    gpuGPUClockSpin->setMaximum(3000);
                    gpuGPUClockSpin->setValue(gpu->getClock());
                    gpuGPUInterfaceLine=new QLineEdit(gpu->getInterface());
                    gpuGPUConnectorsLine=new QLineEdit(gpu->getConnectors());
                    gpuGPUSupplementaryPowerCheck=new QCheckBox();
                    gpuGPUSupplementaryPowerCheck->setChecked(gpu->getSupplementaryPower());
                    componentsSpecsLayout2->addRow(gpuTypeLabel, gpuGPUTypeLine);
                    componentsSpecsLayout2->addRow(gpuMemorySizeLabel, gpuGPUMemorySizeSpin);
                    componentsSpecsLayout2->addRow(gpuPerformanceLabel, gpuGPUPerformanceSpin);
                    componentsSpecsLayout2->addRow(gpuClockLabel, gpuGPUClockSpin);
                    componentsSpecsLayout2->addRow(gpuInterfaceLabel, gpuGPUInterfaceLine);
                    componentsSpecsLayout2->addRow(gpuConnectorsLabel, gpuGPUConnectorsLine);
                    componentsSpecsLayout2->addRow(gpuSupplementaryPowerLabel, gpuGPUSupplementaryPowerCheck);
                }
            }
            if(dynamic_cast<PSU*>(componenti[i])!=nullptr) {
                QString psuName=(componentsList->currentItem())->text();
                if(!trovato && componenti[i]->getName()==psuName) {
                    trovato=true;
                    QString type="PSU";
                    PSU *psu=static_cast<PSU*>(componenti[i]);
                    specLabels(type);
                    psuPSUFormFactorLine=new QLineEdit(psu->getFormFactor());
                    psuPSUWattageSpin=new QSpinBox();
                    psuPSUWattageSpin->setMaximum(2000);
                    psuPSUWattageSpin->setValue(psu->getWattage());
                    psuPSUEfficiencyCertificationLine=new QLineEdit(psu->getEfficiencyCertification());
                    psuPSUModularityLine=new QLineEdit(psu->getModularity());
                    psuPSUSupplementaryPowerCheck=new QCheckBox();
                    psuPSUSupplementaryPowerCheck->setChecked(psu->getSupplementaryPower());
                    componentsSpecsLayout2->addRow(psuFormFactorLabel, psuPSUFormFactorLine);
                    componentsSpecsLayout2->addRow(psuEfficiencyCertificationLabel, psuPSUEfficiencyCertificationLine);
                    componentsSpecsLayout2->addRow(psuWattageLabel, psuPSUWattageSpin);
                    componentsSpecsLayout2->addRow(psuModularityLabel, psuPSUModularityLine);
                    componentsSpecsLayout2->addRow(psuSupplementaryPowerLabel, psuPSUSupplementaryPowerCheck);
                }
            }
            if(dynamic_cast<RAM*>(componenti[i])!=nullptr) {
                QString ramName=(componentsList->currentItem())->text();
                if(!trovato && componenti[i]->getName()==ramName) {
                    trovato=true;
                    QString type="RAM";
                    RAM *ram=static_cast<RAM*>(componenti[i]);
                    specLabels(type);
                    ramRAMSpeedSpin=new QSpinBox();
                    ramRAMSpeedSpin->setMaximum(10000);
                    ramRAMSpeedSpin->setValue(ram->getRamSpeed());
                    ramRAMTypeLine=new QLineEdit(ram->getType());
                    ramRAMSizeSpin=new QSpinBox();
                    ramRAMSizeSpin->setValue(ram->getSize());
                    componentsSpecsLayout2->addRow(ramSpeedLabel, ramRAMSpeedSpin);
                    componentsSpecsLayout2->addRow(ramTypeLabel, ramRAMTypeLine);
                    componentsSpecsLayout2->addRow(ramSizeLabel, ramRAMSizeSpin);
                }
            }
            if(dynamic_cast<Storage*>(componenti[i])!=nullptr) {
                QString storageName=(componentsList->currentItem())->text();
                if(!trovato && componenti[i]->getName()==storageName) {
                    trovato=true;
                    QString type="Storage";
                    Storage* storage=static_cast<Storage*>(componenti[i]);
                    specLabels(type);
                    storageStorageTypeLine=new QLineEdit(storage->getType());
                    storageStorageRPMSpin=new QSpinBox();
                    storageStorageRPMSpin->setMaximum(10000);
                    storageStorageRPMSpin->setValue(storage->getRPM());
                    storageStorageSizeSpin=new QSpinBox();
                    storageStorageSizeSpin->setMaximum(10000);
                    storageStorageSizeSpin->setValue(storage->getSize());
                    storageStorageInterfaceLine=new QLineEdit(storage->getInterface());
                    storageStorageFormFactorSpin=new QDoubleSpinBox();
                    storageStorageFormFactorSpin->setValue(storage->getFormFactor());
                    storageStorageSpeedSpin=new QSpinBox();
                    storageStorageSpeedSpin->setMaximum(10000);
                    storageStorageSpeedSpin->setValue(storage->getSpeed());
                    componentsSpecsLayout2->addRow(storageTypeLabel, storageStorageTypeLine);
                    componentsSpecsLayout2->addRow(storageRPMLabel, storageStorageRPMSpin);
                    componentsSpecsLayout2->addRow(storageSizeLabel, storageStorageSizeSpin);
                    componentsSpecsLayout2->addRow(storageInterfaceLabel, storageStorageInterfaceLine);
                    componentsSpecsLayout2->addRow(storageFormFactorLabel, storageStorageFormFactorSpin);
                    componentsSpecsLayout2->addRow(storageSpeedLabel, storageStorageSpeedSpin);
                }
            }
        }
        saveChanges=new QPushButton("Salva modifiche");
        discardChanges=new QPushButton("Annulla modifiche");
        componentsSpecsLayout2->addRow(saveChanges);
        componentsSpecsLayout2->addRow(discardChanges);
        componentsSpecsLayout2->setVerticalSpacing(25);
        specLayout2->addRow(componentsSpecsLayout2);
        connect(discardChanges, SIGNAL(clicked(bool)), this, SLOT(discardComponentsChanges()));
        connect(saveChanges, SIGNAL(clicked(bool)), this, SLOT(saveComponentsChanges()));
    }
}

//metodo che rimuove la MOBA dalla build
void MainWindow::removeMOBAFromBuild() {
    if((build->item(0, 0))!=nullptr) {
        if(componentNameLabel->text()!="")
            resetSpecs();
        build->setItem(0, 0, nullptr);
        build->setItem(0, 1, nullptr);
        build->setItem(0, 2, nullptr);
    }
    calculateTotal();
}

//metodo che rimuove la CPU dalla build
void MainWindow::removeCPUFromBuild() {
    if((build->item(1, 0))!=nullptr) {
        if(componentNameLabel->text()!="")
            resetSpecs();
        build->setItem(1, 0, nullptr);
        build->setItem(1, 1, nullptr);
        build->setItem(1, 2, nullptr);
    }
    calculateTotal();
}

//metodo che rimuove la GPU dalla build
void MainWindow::removeGPUFromBuild() {
    if((build->item(2, 0))!=nullptr) {
        if(componentNameLabel->text()!="")
            resetSpecs();
        build->setItem(2, 0, nullptr);
        build->setItem(2, 1, nullptr);
        build->setItem(2, 2, nullptr);
    }
    calculateTotal();
}

//metodo che rimuove la PSU dalla build
void MainWindow::removePSUFromBuild() {
    if((build->item(3, 0))!=nullptr) {
        if(componentNameLabel->text()!="")
            resetSpecs();
        build->setItem(3, 0, nullptr);
        build->setItem(3, 1, nullptr);
        build->setItem(3, 2, nullptr);
    }
    calculateTotal();
}

//metodo che rimuove la RAM dalla build
void MainWindow::removeRAMFromBuild() {
    if((build->item(4, 0))!=nullptr) {
        if(componentNameLabel->text()!="")
            resetSpecs();
        build->setItem(4, 0, nullptr);
        build->setItem(4, 1, nullptr);
        build->setItem(4, 2, nullptr);
    }
    calculateTotal();
}

//metodo che rimuove lo Storage dalla build
void MainWindow::removeStorageFromBuild() {
    if((build->item(5, 0))!=nullptr) {
        if(componentNameLabel->text()!="")
            resetSpecs();
        build->setItem(5, 0, nullptr);
        build->setItem(5, 1, nullptr);
        build->setItem(5, 2, nullptr);
    }
    calculateTotal();
}

//metodo che scarta l'intera build
void MainWindow::deleteBuild() {
    removeMOBAFromBuild();
    removeCPUFromBuild();
    removeGPUFromBuild();
    removePSUFromBuild();
    removeRAMFromBuild();
    removeStorageFromBuild();
}

//metodo di salvataggio della build su file JSON
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
            singleComponent.insert("form_factor", QJsonValue::fromVariant(moba->getFormFactor()));
            singleComponent.insert("RAM_slots", QJsonValue::fromVariant(moba->getRAMSlots()));
            singleComponent.insert("max_RAM", QJsonValue::fromVariant(moba->getMaxRAM()));
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
            singleComponent.insert("cpu_speed", QJsonValue::fromVariant(cpu->getCpuSpeed()));
            singleComponent.insert("cores", QJsonValue::fromVariant(cpu->getCores()));
            singleComponent.insert("x64bit", QJsonValue::fromVariant(cpu->getx64bit()));
            singleComponent.insert("cpu_socket", QJsonValue::fromVariant(cpu->getCpuSocket()));
            singleComponent.insert("integrated_graphics", QJsonValue::fromVariant(cpu->getIntegratedGraphic()));
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
            singleComponent.insert("memory_size", QJsonValue::fromVariant(gpu->getMemorySize()));
            singleComponent.insert("performance", QJsonValue::fromVariant(gpu->getPerformance()));
            singleComponent.insert("clock", QJsonValue::fromVariant(gpu->getClock()));
            singleComponent.insert("interface", QJsonValue::fromVariant(gpu->getInterface()));
            singleComponent.insert("connectors", QJsonValue::fromVariant(gpu->getConnectors()));
            singleComponent.insert("supplementary_power", QJsonValue::fromVariant(gpu->getSupplementaryPower()));
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
            singleComponent.insert("form_factor", QJsonValue::fromVariant(psu->getFormFactor()));
            singleComponent.insert("wattage", QJsonValue::fromVariant(psu->getWattage()));
            singleComponent.insert("efficiency_certification", QJsonValue::fromVariant(psu->getEfficiencyCertification()));
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
            singleComponent.insert("ram_speed", QJsonValue::fromVariant(ram->getRamSpeed()));
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
            singleComponent.insert("rpm", QJsonValue::fromVariant(storage->getRPM()));
            singleComponent.insert("size", QJsonValue::fromVariant(storage->getSize()));
            singleComponent.insert("interface", QJsonValue::fromVariant(storage->getInterface()));
            singleComponent.insert("form_factor", QJsonValue::fromVariant(storage->getFormFactor()));
            singleComponent.insert("speed", QJsonValue::fromVariant(storage->getSpeed()));
            newBuild.append(singleComponent);
        }
    }
    QJsonObject toAdd;
    toAdd.insert("pc_parts", newBuild);
    QJsonDocument json(toAdd);
    if(savePath.open(QIODevice::WriteOnly)) {
        savePath.write(json.toJson());
        QDialog *success=new QDialog(this);
        QVBoxLayout *successLayout=new QVBoxLayout(success);
        success->setLayout(successLayout);
        QLabel *successLabel=new QLabel("File salvato correttamente!");
        QPushButton *successButton=new QPushButton("Ok");
        successLayout->addWidget(successLabel);
        successLayout->addWidget(successButton);
        successLabel->setAlignment(Qt::AlignCenter);
        successButton->resize(60, 30);
        successLayout->setAlignment(successButton, Qt::AlignCenter);
        success->setFixedHeight(100);
        success->setFixedWidth(350);
        success->move(700, 400);
        success->show();
        connect(successButton, SIGNAL(clicked(bool)), success, SLOT(close()));
    }
}

//metodo di salvataggio del database su file JSON
void MainWindow::save() {
    QString file = QFileDialog::getSaveFileName(this, tr("Save Database"), "", tr("JSON (*.json);"));
    QJsonArray newDatabase;
    QFile savePath(file);
    for(unsigned int i=0; i!=componenti.getSize(); ++i) {
        QJsonObject singleComponent;
        if(dynamic_cast<MOBA*>(componenti[i])) {
            MOBA* moba=static_cast<MOBA*>(componenti[i]);
            singleComponent.insert("component_type", "MOBA");
            singleComponent.insert("length", QJsonValue::fromVariant(moba->getLength()));
            singleComponent.insert("height", QJsonValue::fromVariant(moba->getHeight()));
            singleComponent.insert("name", QJsonValue::fromVariant(moba->getName()));
            singleComponent.insert("manufacturer", QJsonValue::fromVariant(moba->getManufacturer()));
            singleComponent.insert("price", QJsonValue::fromVariant(moba->getPrice()));
            singleComponent.insert("power_consumption", QJsonValue::fromVariant(moba->getPowerConsumption()));
            singleComponent.insert("moba_socket", QJsonValue::fromVariant(moba->getMOBASocket()));
            singleComponent.insert("form_factor", QJsonValue::fromVariant(moba->getFormFactor()));
            singleComponent.insert("RAM_slots", QJsonValue::fromVariant(moba->getRAMSlots()));
            singleComponent.insert("max_RAM", QJsonValue::fromVariant(moba->getMaxRAM()));
            singleComponent.insert("connectors", QJsonValue::fromVariant(moba->getConnectors()));
            newDatabase.append(singleComponent);
        }
        else if(dynamic_cast<CPU*>(componenti[i])) {
            CPU* cpu=static_cast<CPU*>(componenti[i]);
            singleComponent.insert("component_type", "CPU");
            singleComponent.insert("length", QJsonValue::fromVariant(cpu->getLength()));
            singleComponent.insert("height", QJsonValue::fromVariant(cpu->getHeight()));
            singleComponent.insert("name", QJsonValue::fromVariant(cpu->getName()));
            singleComponent.insert("manufacturer", QJsonValue::fromVariant(cpu->getManufacturer()));
            singleComponent.insert("price", QJsonValue::fromVariant(cpu->getPrice()));
            singleComponent.insert("power_consumption", QJsonValue::fromVariant(cpu->getPowerConsumption()));
            singleComponent.insert("cpu_speed", QJsonValue::fromVariant(cpu->getCpuSpeed()));
            singleComponent.insert("cores", QJsonValue::fromVariant(cpu->getCores()));
            singleComponent.insert("x64bit", QJsonValue::fromVariant(cpu->getx64bit()));
            singleComponent.insert("cpu_socket", QJsonValue::fromVariant(cpu->getCpuSocket()));
            singleComponent.insert("integrated_graphics", QJsonValue::fromVariant(cpu->getIntegratedGraphic()));
            newDatabase.append(singleComponent);
        }
        else if(dynamic_cast<GPU*>(componenti[i])) {
            GPU* gpu=static_cast<GPU*>(componenti[i]);
            singleComponent.insert("component_type", "GPU");
            singleComponent.insert("length", QJsonValue::fromVariant(gpu->getLength()));
            singleComponent.insert("height", QJsonValue::fromVariant(gpu->getHeight()));
            singleComponent.insert("name", QJsonValue::fromVariant(gpu->getName()));
            singleComponent.insert("manufacturer", QJsonValue::fromVariant(gpu->getManufacturer()));
            singleComponent.insert("price", QJsonValue::fromVariant(gpu->getPrice()));
            singleComponent.insert("power_consumption", QJsonValue::fromVariant(gpu->getPowerConsumption()));
            singleComponent.insert("type", QJsonValue::fromVariant(gpu->getType()));
            singleComponent.insert("memory_size", QJsonValue::fromVariant(gpu->getMemorySize()));
            singleComponent.insert("performance", QJsonValue::fromVariant(gpu->getPerformance()));
            singleComponent.insert("clock", QJsonValue::fromVariant(gpu->getClock()));
            singleComponent.insert("interface", QJsonValue::fromVariant(gpu->getInterface()));
            singleComponent.insert("connectors", QJsonValue::fromVariant(gpu->getConnectors()));
            singleComponent.insert("supplementary_power", QJsonValue::fromVariant(gpu->getSupplementaryPower()));
            newDatabase.append(singleComponent);
        }
        else if(dynamic_cast<PSU*>(componenti[i])) {
            PSU* psu=static_cast<PSU*>(componenti[i]);
            singleComponent.insert("component_type", "PSU");
            singleComponent.insert("length", QJsonValue::fromVariant(psu->getLength()));
            singleComponent.insert("height", QJsonValue::fromVariant(psu->getHeight()));
            singleComponent.insert("name", QJsonValue::fromVariant(psu->getName()));
            singleComponent.insert("manufacturer", QJsonValue::fromVariant(psu->getManufacturer()));
            singleComponent.insert("price", QJsonValue::fromVariant(psu->getPrice()));
            singleComponent.insert("power_consumption", QJsonValue::fromVariant(psu->getPowerConsumption()));
            singleComponent.insert("form_factor", QJsonValue::fromVariant(psu->getFormFactor()));
            singleComponent.insert("wattage", QJsonValue::fromVariant(psu->getWattage()));
            singleComponent.insert("efficiency_certification", QJsonValue::fromVariant(psu->getEfficiencyCertification()));
            singleComponent.insert("modularity", QJsonValue::fromVariant(psu->getModularity()));
            singleComponent.insert("supplementary_power", QJsonValue::fromVariant(psu->getSupplementaryPower()));
            newDatabase.append(singleComponent);
        }
        else if(dynamic_cast<RAM*>(componenti[i])) {
            RAM* ram=static_cast<RAM*>(componenti[i]);
            singleComponent.insert("component_type", "RAM");
            singleComponent.insert("length", QJsonValue::fromVariant(ram->getLength()));
            singleComponent.insert("height", QJsonValue::fromVariant(ram->getHeight()));
            singleComponent.insert("name", QJsonValue::fromVariant(ram->getName()));
            singleComponent.insert("manufacturer", QJsonValue::fromVariant(ram->getManufacturer()));
            singleComponent.insert("price", QJsonValue::fromVariant(ram->getPrice()));
            singleComponent.insert("power_consumption", QJsonValue::fromVariant(ram->getPowerConsumption()));
            singleComponent.insert("ram_speed", QJsonValue::fromVariant(ram->getRamSpeed()));
            singleComponent.insert("type", QJsonValue::fromVariant(ram->getType()));
            singleComponent.insert("size", QJsonValue::fromVariant(ram->getSize()));
            newDatabase.append(singleComponent);
        }
        else if(dynamic_cast<Storage*>(componenti[i])) {
            Storage* storage=static_cast<Storage*>(componenti[i]);
            singleComponent.insert("component_type", "Storage");
            singleComponent.insert("length", QJsonValue::fromVariant(storage->getLength()));
            singleComponent.insert("height", QJsonValue::fromVariant(storage->getHeight()));
            singleComponent.insert("name", QJsonValue::fromVariant(storage->getName()));
            singleComponent.insert("manufacturer", QJsonValue::fromVariant(storage->getManufacturer()));
            singleComponent.insert("price", QJsonValue::fromVariant(storage->getPrice()));
            singleComponent.insert("power_consumption", QJsonValue::fromVariant(storage->getPowerConsumption()));
            singleComponent.insert("type", QJsonValue::fromVariant(storage->getType()));
            singleComponent.insert("rpm", QJsonValue::fromVariant(storage->getRPM()));
            singleComponent.insert("size", QJsonValue::fromVariant(storage->getSize()));
            singleComponent.insert("interface", QJsonValue::fromVariant(storage->getInterface()));
            singleComponent.insert("form_factor", QJsonValue::fromVariant(storage->getFormFactor()));
            singleComponent.insert("speed", QJsonValue::fromVariant(storage->getSpeed()));
            newDatabase.append(singleComponent);
        }
    }
    QJsonObject toAdd;
    toAdd.insert("pc_parts", newDatabase);
    QJsonDocument json(toAdd);
    if(savePath.open(QIODevice::WriteOnly)) {
        savePath.write(json.toJson());
        QDialog *success=new QDialog(this);
        QVBoxLayout *successLayout=new QVBoxLayout(success);
        success->setLayout(successLayout);
        QLabel *successLabel=new QLabel("File salvato correttamente!");
        QPushButton *successButton=new QPushButton("Ok");
        successLayout->addWidget(successLabel);
        successLayout->addWidget(successButton);
        successLabel->setAlignment(Qt::AlignCenter);
        successButton->resize(60, 30);
        successLayout->setAlignment(successButton, Qt::AlignCenter);
        success->setFixedHeight(100);
        success->setFixedWidth(350);
        success->move(700, 400);
        success->show();
        connect(successButton, SIGNAL(clicked(bool)), success, SLOT(close()));
    }
}

//reset del layout che mostra le specifiche dei componenti
void MainWindow::resetSpecs() {
    if(componentNameLabel->text()!="") {
        componentNameLabel->setText("");
        componentLengthLabel->setText("");
        componentHeightLabel->setText("");
        componentPriceLabel->setText("");
        componentPowerConsumptionLabel->setText("");
        componentManufacturerLabel->setText("");
        while(componentsSpecsLayout->count()!=0) {
            QLayoutItem *item=componentsSpecsLayout->takeAt(0);
            delete item->widget();
            delete item;
        }
        specLayout->takeRow(componentsSpecsLayout);
    }
}

//funzione che genera le label specifice per ogni componente
void MainWindow::specLabels(QString type) {
    if(type=="MOBA") {
        mobaSocketLabel=new QLabel("Socket: ");
        mobaFormFactorLabel=new QLabel("Form Factor: ");
        mobaRAMSlotsLabel=new QLabel("Slot RAM: ");
        mobaMaxRAMLabel=new QLabel("RAM massima supportata (GB): ");
        mobaConnectorsLabel=new QLabel("Interfacce: ");
    }
    if(type=="CPU") {
        cpuSpeedLabel=new QLabel("Frequenza (GHz): ");
        cpuCoresLabel=new QLabel("Cores: ");
        cpux64bitLabel=new QLabel("Supporto 64 bit: ");
        cpuSocketLabel=new QLabel("Socket CPU: ");
        cpuIntegratedGraphicsLabel=new QLabel("Chip grafico integrato: ");
    }
    if(type=="GPU") {
        gpuTypeLabel=new QLabel("Tipo: ");
        gpuMemorySizeLabel=new QLabel("Memoria dedicata (GB): ");
        gpuPerformanceLabel=new QLabel("TFLOPs: ");
        gpuClockLabel=new QLabel("Clock (MHz): ");
        gpuInterfaceLabel=new QLabel("Interfacce: ");
        gpuConnectorsLabel=new QLabel("Porte: ");
        gpuSupplementaryPowerLabel=new QLabel("Alimentazione supplementare richiesta: ");
    }
    if(type=="PSU") {
        psuFormFactorLabel=new QLabel("Form Factor: ");
        psuWattageLabel=new QLabel("Wattaggio: ");
        psuEfficiencyCertificationLabel=new QLabel("Certificazione di efficienza: ");
        psuModularityLabel=new QLabel("Modularità: ");
        psuSupplementaryPowerLabel=new QLabel("Predisposizione alimentazione supplementare: ");
    }
    if(type=="RAM") {
        ramSpeedLabel=new QLabel("Frequenza (MHz): ");
        ramTypeLabel=new QLabel("Tipo: ");
        ramSizeLabel=new QLabel("Capacità (GB): ");
    }
    if(type=="Storage") {
        storageTypeLabel=new QLabel("Tipo: ");
        storageRPMLabel=new QLabel("RPM: ");
        storageSizeLabel=new QLabel("Capacità (GB): ");
        storageInterfaceLabel=new QLabel("Interfaccia: ");
        storageFormFactorLabel=new QLabel("Form Factor (pollici) : ");
        storageSpeedLabel=new QLabel("Velocità trasferimento (MB/s): ");
    }
}

//funzione che genera le label base per ogni componente
void MainWindow::basicSpecs(unsigned int pos) {
    if((build->item(0, 0)!=nullptr && (build->item(0, 0))->text()!=componentNameLabel->text()) || (build->item(1, 0)!=nullptr && (build->item(1, 0))->text()!=componentNameLabel->text()) || (build->item(2, 0)!=nullptr && (build->item(2, 0))->text()!=componentNameLabel->text()) ||
       (build->item(3, 0)!=nullptr && (build->item(3, 0))->text()!=componentNameLabel->text()) || (build->item(4, 0)!=nullptr && (build->item(4, 0))->text()!=componentNameLabel->text()) || (build->item(5, 0)!=nullptr && (build->item(5, 0))->text()!=componentNameLabel->text())) {
        if(dynamic_cast<MOBA*>(componenti[pos])!=nullptr)
            componentNameLabel->setText((build->item(0, 0))->text());
        else if(dynamic_cast<CPU*>(componenti[pos])!=nullptr)
            componentNameLabel->setText((build->item(1, 0))->text());
        else if(dynamic_cast<GPU*>(componenti[pos])!=nullptr)
            componentNameLabel->setText((build->item(2, 0))->text());
        else if(dynamic_cast<PSU*>(componenti[pos])!=nullptr)
            componentNameLabel->setText((build->item(3, 0))->text());
        else if(dynamic_cast<RAM*>(componenti[pos])!=nullptr)
            componentNameLabel->setText((build->item(4, 0))->text());
        else if(dynamic_cast<Storage*>(componenti[pos])!=nullptr)
            componentNameLabel->setText((build->item(5, 0))->text());
        componentManufacturerLabel->setText(componenti[pos]->getManufacturer());
        componentLengthLabel->setText(QString::number(componenti[pos]->getLength()));
        componentHeightLabel->setText(QString::number(componenti[pos]->getHeight()));
        std::string price=std::to_string(componenti[pos]->getPrice());
        price=removeZero(price);
        componentPriceLabel->setText(QString::fromStdString(price));
        componentPowerConsumptionLabel->setText(QString::number(componenti[pos]->getPowerConsumption()));
    }
}

//metodo che mostra le specifiche della MOBA inserita nella build
void MainWindow::showMOBASpecs() {
    if(componentNameLabel->text()!="")
        resetSpecs();
    if(build->item(0, 0)!=nullptr && (build->item(0, 0))->text()!=componentNameLabel->text()) {
        bool trovato=false;
        QString type="MOBA";
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(!trovato && componenti[i]->getName()==(build->item(0, 0))->text()) {
                trovato=true;
                MOBA* moba=static_cast<MOBA*>(componenti[i]);
                QString mobaMOBASocket=moba->getMOBASocket();
                QString mobaFormFactor=moba->getFormFactor();
                QString mobaRAMSlots=(QString::number(moba->getRAMSlots()));
                QString mobaMaxRAM=(QString::number(moba->getMaxRAM()));
                QString mobaConnectors=moba->getConnectors();
                specLabels(type);
                QLabel *mobaMOBASocketLabel=new QLabel(mobaMOBASocket);
                QLabel *mobaMOBAFormFactorLabel=new QLabel(mobaFormFactor);
                QLabel *mobaMOBARAMSlotsLabel=new QLabel(mobaRAMSlots);
                QLabel *mobaMOBAMaxRAMLabel=new QLabel(mobaMaxRAM);
                QLabel *mobaMOBAConnectorsLabel=new QLabel(mobaConnectors);
                basicSpecs(i);
                componentsSpecsLayout=new QFormLayout();
                componentsSpecsLayout->addRow(mobaSocketLabel, mobaMOBASocketLabel);
                componentsSpecsLayout->addRow(mobaRAMSlotsLabel, mobaMOBARAMSlotsLabel);
                componentsSpecsLayout->addRow(mobaConnectorsLabel, mobaMOBAConnectorsLabel);
                componentsSpecsLayout->addRow(mobaMaxRAMLabel, mobaMOBAMaxRAMLabel);
                componentsSpecsLayout->addRow(mobaFormFactorLabel, mobaMOBAFormFactorLabel);
                componentsSpecsLayout->setVerticalSpacing(25);
                specLayout->addRow(componentsSpecsLayout);
            }
        }
    }    
}

//metodo che mostra le specifiche della CPU inserita nella build
void MainWindow::showCPUSpecs() {
    if(componentNameLabel->text()!="")
        resetSpecs();
    if(build->item(1, 0)!=nullptr && (build->item(1, 0))->text()!=componentNameLabel->text()) {
        bool trovato=false;
        QString type="CPU";
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(!trovato && componenti[i]->getName()==(build->item(1, 0))->text()) {
                trovato=true;
                QString cpux64bit;
                QString cpuIntegratedGraphics;
                CPU* cpu=static_cast<CPU*>(componenti[i]);
                std::string speed=std::to_string(cpu->getCpuSpeed());
                speed=removeZero(speed);
                QString cpuSpeed=QString::fromStdString(speed);
                QString cpuCores=(QString::number(cpu->getCores()));
                if(cpu->getx64bit())
                    cpux64bit="Sì";
                else
                    cpux64bit="No";
                QString cpuSocket=cpu->getCpuSocket();
                if(cpu->getIntegratedGraphic())
                    cpuIntegratedGraphics="Sì";
                else
                    cpuIntegratedGraphics="No";
                specLabels(type);
                QLabel *cpuCPUSpeedLabel=new QLabel(cpuSpeed);
                QLabel *cpuCPUCoresLabel=new QLabel(cpuCores);
                QLabel *cpuCPUx64bitLabel=new QLabel(cpux64bit);
                QLabel *cpuCPUSocketLabel=new QLabel(cpuSocket);
                QLabel *cpuCPUIntegratedGraphicsLabel=new QLabel(cpuIntegratedGraphics);
                basicSpecs(i);
                componentsSpecsLayout=new QFormLayout();
                componentsSpecsLayout->addRow(cpuSpeedLabel, cpuCPUSpeedLabel);
                componentsSpecsLayout->addRow(cpuCoresLabel, cpuCPUCoresLabel);
                componentsSpecsLayout->addRow(cpux64bitLabel, cpuCPUx64bitLabel);
                componentsSpecsLayout->addRow(cpuSocketLabel, cpuCPUSocketLabel);
                componentsSpecsLayout->addRow(cpuIntegratedGraphicsLabel, cpuCPUIntegratedGraphicsLabel);
                componentsSpecsLayout->setVerticalSpacing(25);
                specLayout->addRow(componentsSpecsLayout);
            }
        }
    }
}

//metodo che mostra le specifiche della GPU inserita nella build
void MainWindow::showGPUSpecs() {
    if(componentNameLabel->text()!="")
        resetSpecs();
    if(build->item(2, 0)!=nullptr && (build->item(2, 0))->text()!=componentNameLabel->text()) {
        bool trovato=false;
        QString type="GPU";
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(!trovato && componenti[i]->getName()==(build->item(2, 0))->text()) {
                trovato=true;
                QString gpuSupplementaryPower;
                GPU *gpu=static_cast<GPU*>(componenti[i]);
                QString gpuType=gpu->getType();
                QString gpuMemorySize=(QString::number(gpu->getMemorySize()));
                std::string performance=std::to_string(gpu->getPerformance());
                performance=removeZero(performance);
                QString gpuPerformance=QString::fromStdString(performance);
                QString gpuClock=(QString::number(gpu->getClock()));
                QString gpuInterface=gpu->getInterface();
                QString gpuConnectors=gpu->getConnectors();
                if(gpu->getSupplementaryPower())
                    gpuSupplementaryPower="Sì";
                else
                    gpuSupplementaryPower="No";
                specLabels(type);
                QLabel *gpuGPUTypeLabel=new QLabel(gpuType);
                QLabel *gpuGPUMemorySizeLabel=new QLabel(gpuMemorySize);
                QLabel *gpuGPUPerformanceLabel=new QLabel(gpuPerformance);
                QLabel *gpuGPUClockLabel=new QLabel(gpuClock);
                QLabel *gpuGPUInterfaceLabel=new QLabel(gpuInterface);
                QLabel *gpuGPUConnectorsLabel=new QLabel(gpuConnectors);
                QLabel *gpuGPUSupplementaryPowerLabel=new QLabel(gpuSupplementaryPower);
                basicSpecs(i);
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

//metodo che mostra le specifiche della PSU inserita nella build
void MainWindow::showPSUSpecs() {
    if(componentNameLabel->text()!="")
        resetSpecs();
    if(build->item(3, 0)!=nullptr && (build->item(3, 0))->text()!=componentNameLabel->text()) {
        bool trovato=false;
        QString type="PSU";
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(!trovato && componenti[i]->getName()==(build->item(3, 0))->text()) {
                trovato=true;
                QString psuSupplementaryPower;
                PSU *psu=static_cast<PSU*>(componenti[i]);
                QString psuFormFactor=psu->getFormFactor();
                QString psuWattage=(QString::number(psu->getWattage()));
                QString psuEfficiencyCertification=psu->getEfficiencyCertification();
                QString psuModularity=psu->getModularity();
                if(psu->getSupplementaryPower()==true)
                    psuSupplementaryPower="Sì";
                else
                    psuSupplementaryPower="No";
                specLabels(type);
                QLabel *psuPSUFormFactorLabel=new QLabel(psuFormFactor);
                QLabel *psuPSUWattageLabel=new QLabel(psuWattage);
                QLabel *psuPSUEfficiencyCertificationLabel=new QLabel(psuEfficiencyCertification);
                QLabel *psuPSUModularityLabel=new QLabel(psuModularity);
                QLabel *psuPSUSupplementaryPowerLabel=new QLabel(psuSupplementaryPower);
                basicSpecs(i);
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

//metodo che mostra le specifiche della RAM inserita nella build
void MainWindow::showRAMSpecs() {
    if(componentNameLabel->text()!="")
        resetSpecs();
    if(build->item(4, 0)!=nullptr && (build->item(4, 0))->text()!=componentNameLabel->text()) {
        bool trovato=false;
        QString type="RAM";
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(!trovato && componenti[i]->getName()==(build->item(4, 0))->text()) {
                trovato=true;
                RAM *ram=static_cast<RAM*>(componenti[i]);
                QString ramSpeed=(QString::number(ram->getRamSpeed()));
                QString ramType=ram->getType();
                QString ramSize=(QString::number(ram->getSize()));
                specLabels(type);
                QLabel *ramRAMSpeedLabel=new QLabel(ramSpeed);
                QLabel *ramRAMTypeLabel=new QLabel(ramType);
                QLabel *ramRAMSizeLabel=new QLabel(ramSize);
                basicSpecs(i);
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

//metodo che mostra le specifiche dello Storage inserita nella build
void MainWindow::showStorageSpecs() {
    if(componentNameLabel->text()!="")
        resetSpecs();
    if(build->item(5, 0)!=nullptr && (build->item(5, 0))->text()!=componentNameLabel->text()) {
        bool trovato=false;
        QString type="Storage";
        for(unsigned int i=0; !trovato && i!=componenti.getSize(); ++i) {
            if(!trovato && componenti[i]->getName()==(build->item(5, 0))->text()) {
                trovato=true;
                Storage* storage=static_cast<Storage*>(componenti[i]);
                QString storageType=storage->getType();
                QString storageRPM=(QString::number(storage->getRPM()));
                QString storageSize=(QString::number(storage->getSize()));
                QString storageInterface=storage->getInterface();
                std::string form_factor=std::to_string(storage->getFormFactor());
                form_factor=removeZero(form_factor);
                QString storageFormFactor=QString::fromStdString(form_factor);
                QString storageSpeed=(QString::number(storage->getSpeed()));
                specLabels(type);
                QLabel *storageStorageTypeLabel=new QLabel(storageType);
                QLabel *storageStorageRPMLabel=new QLabel(storageRPM);
                QLabel *storageStorageSizeLabel=new QLabel(storageSize);
                QLabel *storageStorageInterfaceLabel=new QLabel(storageInterface);
                QLabel *storageStorageFormFactorLabel=new QLabel(storageFormFactor);
                QLabel *storageStorageSpeedLabel=new QLabel(storageSpeed);
                basicSpecs(i);
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

//metodo per il caricamento di un file JSON nella build e nel database
void MainWindow::loadFileToBuild() {
    QString path=QFileDialog::getOpenFileName(this, tr("Load Build"), QDir::currentPath(), tr("JSON (*.json)"));;
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray json=file.readAll();
    file.close();
    QJsonDocument document=QJsonDocument::fromJson(json);
    QJsonArray array=document.object().value("pc_parts").toArray();
    if(!array.isEmpty()) {
        resetSpecs();
        bool componentPresence;
        for(unsigned int i=0; i!=componenti.getSize(); i++)
            componentsNames.push_back(new QString(componenti[i]->getName()));
        foreach(const QJsonValue& j, array) {
            QString component_type=QString(j.toObject().value("component_type").toString());
            QString* component_name=new QString((j.toObject().value("name").toString()));
            if(componentsNames.search(component_name)!=-1)
                componentPresence=true;
            else
                componentPresence=false;
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
                    mobaComboBox->addItem(componenti[componenti.getSize()-1]->getName());
                    componentsList->addItem(componenti[componenti.getSize()-1]->getName());
                    mobaComboBox->setCurrentIndex(mobaComboBox->findText(*component_name));
                    mobaToBuild();
                }
                else {
                    mobaComboBox->setCurrentIndex(mobaComboBox->findText(*component_name));
                    mobaToBuild();
                }
            }
            if(component_type=="CPU") {
                if(componentPresence==false) {
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
                                                  j.toObject().value("integrated_grapchic").toBool()
                                                  ));
                    cpuComboBox->addItem(componenti[componenti.getSize()-1]->getName());
                    componentsList->addItem(componenti[componenti.getSize()-1]->getName());
                    cpuComboBox->setCurrentIndex(cpuComboBox->findText(*component_name));
                    cpuToBuild();
                }
                else {
                    cpuComboBox->setCurrentIndex(cpuComboBox->findText(*component_name));
                    cpuToBuild();
                }
            }
            if(component_type=="GPU") {
                if(componentPresence==false) {
                    componenti.push_back(new GPU(j.toObject().value("length").toInt(),
                                                  j.toObject().value("height").toInt(),
                                                  j.toObject().value("name").toString(),
                                                  j.toObject().value("manufacturer").toString(),
                                                  j.toObject().value("price").toDouble(),
                                                  j.toObject().value("power_consumption").toInt(),
                                                  j.toObject().value("type").toString(),
                                                  j.toObject().value("memory_size").toInt(),
                                                  j.toObject().value("performance").toDouble(),
                                                  j.toObject().value("clock").toInt(),
                                                  j.toObject().value("interface").toString(),
                                                  j.toObject().value("connectors").toString(),
                                                  j.toObject().value("supplementary_power").toBool()
                                                  ));
                    gpuComboBox->addItem(componenti[componenti.getSize()-1]->getName());
                    componentsList->addItem(componenti[componenti.getSize()-1]->getName());
                    gpuComboBox->setCurrentIndex(gpuComboBox->findText(*component_name));
                    gpuToBuild();
                }
                else {
                    gpuComboBox->setCurrentIndex(gpuComboBox->findText(*component_name));
                    gpuToBuild();
                }
            }
            if(component_type=="PSU") {
                if(componentPresence==false) {
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
                    psuComboBox->addItem(componenti[componenti.getSize()-1]->getName());
                    componentsList->addItem(componenti[componenti.getSize()-1]->getName());
                    psuComboBox->setCurrentIndex(psuComboBox->findText(*component_name));
                    psuToBuild();
                }
                else {
                    psuComboBox->setCurrentIndex(psuComboBox->findText(*component_name));
                    psuToBuild();
                }
            }
            if(component_type=="RAM") {
                if(componentPresence==false) {
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
                    ramComboBox->addItem(componenti[componenti.getSize()-1]->getName());
                    componentsList->addItem(componenti[componenti.getSize()-1]->getName());
                    ramComboBox->setCurrentIndex(ramComboBox->findText(*component_name));
                    ramToBuild();
                }
                else {
                    ramComboBox->setCurrentIndex(ramComboBox->findText(*component_name));
                    ramToBuild();
                }
            }
            if(component_type=="Storage") {
                if(componentPresence==false) {
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
                    storageComboBox->addItem(componenti[componenti.getSize()-1]->getName());
                    componentsList->addItem(componenti[componenti.getSize()-1]->getName());
                    storageComboBox->setCurrentIndex(storageComboBox->findText(*component_name));
                    storageToBuild();
                }
                else {
                    storageComboBox->setCurrentIndex(storageComboBox->findText(*component_name));
                    storageToBuild();
                }
            }
        }
        for(unsigned int i=0; i!=componenti.getSize(); ++i)
            componentsNames.push_back(new QString(componenti[i]->getName()));
    }
}

//metodo per il caricamento di un file JSON nel database
void MainWindow::load() {
    QString path=QFileDialog::getOpenFileName(this, tr("Load Database"), QDir::currentPath(), tr("JSON (*.json)"));
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray json=file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(json);
    QJsonArray array = document.object().value("pc_parts").toArray();
    if(!array.isEmpty()) {
        bool componentPresence;
        for(unsigned int i=0; i!=componenti.getSize(); i++)
            componentsNames.push_back(new QString(componenti[i]->getName()));
        foreach(const QJsonValue& j, array) {
            QString component_type=QString(j.toObject().value("component_type").toString());
            QString *component_name=new QString((j.toObject().value("name").toString()));
            if(componentsNames.search(component_name)!=-1)
                componentPresence=true;
            else
                componentPresence=false;
            if(component_type=="MOBA" && componentPresence==false)
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
            else if(component_type=="CPU" && componentPresence==false)
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
            else if(component_type=="GPU" && componentPresence==false)
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
            else if(component_type=="PSU" && componentPresence==false)
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
            else if(component_type=="RAM" && componentPresence==false)
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
            else if(component_type=="Storage" && componentPresence==false)
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
            if(dynamic_cast<MOBA*>(componenti[i])!=nullptr && mobaComboBox->findText(componenti[i]->getName())==-1)
                mobaComboBox->addItem(componenti[i]->getName());
            else if(dynamic_cast<CPU*>(componenti[i])!=nullptr && cpuComboBox->findText(componenti[i]->getName())==-1)
                cpuComboBox->addItem(componenti[i]->getName());
            else if(dynamic_cast<GPU*>(componenti[i])!=nullptr && gpuComboBox->findText(componenti[i]->getName())==-1)
                gpuComboBox->addItem(componenti[i]->getName());
            else if(dynamic_cast<PSU*>(componenti[i])!=nullptr && psuComboBox->findText(componenti[i]->getName())==-1)
                psuComboBox->addItem(componenti[i]->getName());
            else if(dynamic_cast<RAM*>(componenti[i])!=nullptr && ramComboBox->findText(componenti[i]->getName())==-1)
                ramComboBox->addItem(componenti[i]->getName());
            else if(dynamic_cast<Storage*>(componenti[i])!=nullptr && storageComboBox->findText(componenti[i]->getName())==-1)
                storageComboBox->addItem(componenti[i]->getName());
            if(componentsList->findItems(componenti[i]->getName(), Qt::MatchExactly).empty())
                componentsList->addItem(componenti[i]->getName());
        }
    }
}

MainWindow::MainWindow(): QMainWindow() {
    tab=new QTabWidget();
    window=new QWidget(tab);
    window2=new QWidget(tab);
    tab->addTab(window, "Build");
    tab->addTab(window2, "Gestione componenti");
    menuBar=new QMenuBar();
    saveMenu=new QMenu();
    loadMenu=new QMenu();
    saveMenu=menuBar->addMenu("&Salva");
    loadMenu=menuBar->addMenu("&Carica");
    saveMenu->addAction("&Salva database componenti");
    loadMenu->addAction("&Carica database componenti");

    layout=new QGridLayout();
    window->setLayout(layout);
    layout->setMenuBar(menuBar);
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
    build->setEditTriggers(QTableWidget::NoEditTriggers);
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
    horizontalHeaders.append("Componente");
    horizontalHeaders.append("Rating");
    horizontalHeaders.append("Prezzo");
    horizontalHeaders.append("Mostra specifiche");
    horizontalHeaders.append("Rimuovi componente");
    build->setHorizontalHeaderLabels(horizontalHeaders);
    verticalHeaders.append("MOBA");
    verticalHeaders.append("CPU");
    verticalHeaders.append("GPU");
    verticalHeaders.append("PSU");
    verticalHeaders.append("RAM");
    verticalHeaders.append("Storage");
    verticalHeaders.append("Totale");
    build->setVerticalHeaderLabels(verticalHeaders);

    saveBuild=new QPushButton("Salva Build");
    loadBuild=new QPushButton("Carica Build");
    discardBuild=new QPushButton("Scarta Build");
    saveBuild->setFixedWidth(150);
    loadBuild->setFixedWidth(150);
    discardBuild->setFixedWidth(150);
    buttonsLayout->addWidget(saveBuild);
    buttonsLayout->addWidget(loadBuild);
    buttonsLayout->addWidget(discardBuild);
    layout3->addRow(build);
    layout3->addRow(buttonsLayout);
    buttonsLayout->setSpacing(15);
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
    specLayout->setContentsMargins(0, 0, 60, 0);

    layout4=new QGridLayout();
    window2->setLayout(layout4);
    menuBar2=new QMenuBar();
    saveMenu2=new QMenu();
    loadMenu2=new QMenu();
    saveMenu2=menuBar2->addMenu("&Salva");
    loadMenu2=menuBar2->addMenu("&Carica");
    saveMenu2->addAction("&Salva database componenti");
    loadMenu2->addAction("&Carica database componenti");
    layout5=new QFormLayout();
    layout4->setMenuBar(menuBar2);
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
    componentLengthSpin=new QSpinBox();
    componentLengthSpin->setMaximum(1000);
    componentHeightSpin=new QSpinBox();
    componentHeightSpin->setMaximum(1000);
    componentPriceSpin=new QDoubleSpinBox();
    componentPriceSpin->setMaximum(2000);
    componentPriceSpin->setSingleStep(0.01);
    componentPowerConsumptionSpin=new QSpinBox();
    componentPowerConsumptionSpin->setMaximum(1000);
    componentManufacturerLine=new QLineEdit();
    specLayout2->addRow(nameLabel2, componentNameLine);
    specLayout2->addRow(manufacturerLabel2, componentManufacturerLine);
    specLayout2->addRow(lengthLabel2, componentLengthSpin);
    specLayout2->addRow(heightLabel2, componentHeightSpin);
    specLayout2->addRow(priceLabel2, componentPriceSpin);
    specLayout2->addRow(powerconsumptionLabel2, componentPowerConsumptionSpin);
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
    connect(saveMenu, SIGNAL(triggered(QAction*)), this, SLOT(save()));
    connect(saveMenu2, SIGNAL(triggered(QAction*)), this, SLOT(save()));
    connect(loadMenu, SIGNAL(triggered(QAction*)), this, SLOT(load()));
    connect(loadMenu2, SIGNAL(triggered(QAction*)), this, SLOT(load()));
    connect(saveBuild, SIGNAL(clicked(bool)), this, SLOT(saveBuildToFile()));
    connect(loadBuild, SIGNAL(clicked(bool)), this, SLOT(loadFileToBuild()));
    //load("../Qontainer/database.json");
    QCoreApplication::setApplicationName("PC Part Picker");
    tab->setMinimumSize(1800, 800);
    tab->setMaximumSize(1800, 800);
    tab->move(100, 100);
    tab->show();
}
