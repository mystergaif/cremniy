#ifndef DISASSEMBLERTAB_H
#define DISASSEMBLERTAB_H

#include "tooltab.h"
#include <QWidget>

class DisassemblerTab : public QWidget, public ToolTab
{
    Q_OBJECT
public:
    explicit DisassemblerTab(QWidget *parent, QString path);

    void saveToFile(QString path) override {

    };

    void setTabData(QByteArray &data) override {

    };

signals:
    void modifyData(bool modified);
};

#endif // DISASSEMBLERTAB_H
