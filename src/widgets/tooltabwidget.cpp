#include "tooltabwidget.h"
#include <QCodeEditor.hpp>
#include <QFile>
#include <QSyntaxStyle.hpp>

#include <QCodeEditor.hpp>
#include <QCECompleter.hpp>
#include <QSyntaxStyle.hpp>
#include <QCXXHighlighter.hpp>
#include <QJSONHighlighter.hpp>
#include <qboxlayout.h>
#include <qfileinfo.h>

ToolTabWidget::ToolTabWidget(QWidget *parent, QString path)
    {

    // Tabs
    m_codeEditorTab = new CodeEditorTab(this, path);
    m_hexViewTab = new HexViewTab(this, path);
    m_disassemblerTab = new DisassemblerTab(this, path);

    // Tab Icons
    QIcon codeIcon(":/icons/code.png");
    QIcon hexIcon(":/icons/hex.png");
    QIcon disasmIcon(":/icons/dasm.png");

    // Add Tabs
    this->addTab(m_codeEditorTab, codeIcon, "Code");
    this->addTab(m_hexViewTab, hexIcon, "Hex");
    this->addTab(m_disassemblerTab, disasmIcon, "Disassembler");

    connect(m_codeEditorTab, &CodeEditorTab::modifyData,
            this, &ToolTabWidget::onTabModified);
    connect(m_hexViewTab, &HexViewTab::modifyData,
            this, &ToolTabWidget::onTabModified);
    connect(m_disassemblerTab, &DisassemblerTab::modifyData,
            this, &ToolTabWidget::onTabModified);

}

void ToolTabWidget::onTabModified(bool modified)
{
    QObject* obj = sender();
    QWidget* widget = qobject_cast<QWidget*>(obj);

    if (!widget) return;

    int index = indexOf(widget);
    if (index < 0) return;

    QString text = tabText(index);
    if (!text.endsWith("*")){
        qDebug() << "if";
        setTabText(index, text + "*");
    }

}

void ToolTabWidget::saveToFileCurrentTab(QString path){
    QWidget* w = currentWidget();
    int index = currentIndex();
    if (!w) return;

    ToolTab* tab = dynamic_cast<ToolTab*>(w);
    if (!tab) return;

    tab->saveToFile(path);
    QString text = tabText(index);
    text.replace("*", "");
    setTabText(index, text);
}

void ToolTabWidget::setDataInTabs(QByteArray &data){
    for (int i = 0; i < count(); ++i) {
        QWidget* w = widget(i);
        if (!w) return;

        ToolTab* tab = dynamic_cast<ToolTab*>(w);
        if (!tab) return;

        tab->setTabData(data);
    }
}
