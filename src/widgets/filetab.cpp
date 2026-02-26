#include "filetab.h"
#include "tooltabwidget.h"
#include <qboxlayout.h>
#include <qdir.h>
#include <qevent.h>

FileTab::FileTab(FilesTabWidget *ftparent, QString path, QWidget* parent)
    : QWidget(parent),
    m_filesTabWidget(ftparent),
    filePath(path)
{
    QVBoxLayout *vlayout = new QVBoxLayout(this);
    m_tooltabWidget = new ToolTabWidget(this, path);
    m_tooltabWidget->setObjectName("toolTabWidget");
    vlayout->addWidget(m_tooltabWidget);
    vlayout->setContentsMargins(0,0,0,0);
    this->setLayout(vlayout);
}

void FileTab::openFile(){
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) return;
    QByteArray data = file.readAll();
    file.close();
    m_tooltabWidget->setDataInTabs(data);
}

void FileTab::saveFile(){
    m_tooltabWidget->saveToFileCurrentTab(filePath);
}