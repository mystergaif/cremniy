#ifndef CODEEDITORTAB_H
#define CODEEDITORTAB_H

#include "QCodeEditor.hpp"
#include "tooltab.h"
#include <QWidget>
#include <qfileinfo.h>

class CodeEditorTab : public QWidget, public ToolTab
{
    Q_OBJECT

private:
    QCodeEditor* m_codeEditorWidget;

public:
    explicit CodeEditorTab(QWidget *parent, QString path);

    void saveToFile(QString path) override {
        QFile f(path);
        if (!f.open(QFile::WriteOnly)) return;
        f.write(m_codeEditorWidget->getBData());
        f.close();
        m_codeEditorWidget->document()->setModified(false);
    };

    void setTabData(QByteArray &data) override {
        m_codeEditorWidget->setBData(data);
    };

signals:
    void modifyData(bool modified);
};

#endif // CODEEDITORTAB_H
