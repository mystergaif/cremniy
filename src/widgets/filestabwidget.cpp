#include "filestabwidget.h"
#include "filetab.h"
#include <qboxlayout.h>

FilesTabWidget::FilesTabWidget(QWidget *parent) {
    connect(this, &QTabWidget::currentChanged, this, &FilesTabWidget::tabSelect);
}

void FilesTabWidget::saveCurrentFile(){
    FileTab *currentFileTab = qobject_cast<FileTab*>(this->currentWidget());
    currentFileTab->saveFile();
}

void FilesTabWidget::tabSelect(int index){
    FileTab *tab = qobject_cast<FileTab*>(widget(index));
    if (!tab) return;
}

// Create new tab and open file if he is not open already
void FilesTabWidget::openFile(QString filePath, QString tabTitle){

    // check already open
    for (int i = 0; i < this->count(); ++i)
    {
        FileTab *t = qobject_cast<FileTab*>(this->widget(i));
        if (t && t->filePath == filePath)
        {
            this->setCurrentIndex(i);
            return;
        }
    }

    // else file is not opened
    FileTab *filetab = new FileTab(this, filePath);
    int new_tab_index = this->addTab(filetab, tabTitle);
    this->setCurrentIndex(new_tab_index);
    filetab->openFile();
}


