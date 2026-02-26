#include "codeeditortab.h"
#include "QCodeEditor.hpp"
#include <qboxlayout.h>
#include <qfileinfo.h>

CodeEditorTab::CodeEditorTab(QWidget *parent, QString path)
    : QWidget{parent}
{

    QFileInfo fileInfo(path);
    QString ext = fileInfo.suffix();

    m_codeEditorWidget = new QCodeEditor(ext, this);

    auto layout = new QVBoxLayout(this);
    layout->addWidget(m_codeEditorWidget);
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    connect(m_codeEditorWidget->document(),
            &QTextDocument::modificationChanged,
            this,
            [this](bool modified){
                qDebug() << "modified";
                if (!m_codeEditorWidget->m_ignoreModification)
                    emit modifyData(true);
            });

}
