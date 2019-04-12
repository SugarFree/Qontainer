#include "usermanual.h"

userManual::userManual(QWidget* parent): QMessageBox(parent) {
    setText("PC Part Picker - Manuale utente\n\n"
            "Tab Build:\n"
            "dopo aver caricato un database JSON attraverso il tasto carica nella menu bar "
            "è possibile inserire i componenti delle combo box nella tabella che identifica la build "
            "attraverso i pulsanti --->. Dopodichè si possono usare i bottoni ≡ e - per rispettivamente "
            "visualizzare le specifiche del componente associato o rimuoverlo dalla build. È inoltre possibile "
            "salvare, caricare o scartare la build con i pulsanti posizionati sotto la tabella.\n\n"
            "Tab Gestione componenti:\n"
            "dopo aver caricato un database JSON attraverso il tasto carica nella menu bar "
            "vengono visualizzati tutti i componenti inseriti nella tabella sottostante; in questa tabella "
            "è possibile filtrare gli elementi attraverso la search bar soprastante o aggiungere, rimuovere o "
            "modificare i pezzi. A destra verrano mostrate le caratteristiche del componente selzionato modificabili "
            "attraverso line edit, spin box o check box e due bottoni per il salvataggio o l'annullamento delle modifiche.");
    setTextFormat(Qt::PlainText);
    setWindowTitle("PC Part Picker - Manuale utente");
}
