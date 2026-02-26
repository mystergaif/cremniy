#include "hexviewtab.h"
#include <qboxlayout.h>

HexViewTab::HexViewTab(QWidget *parent, QString path)
    : QWidget{parent}
{

    m_hexViewWidget = new QHexView();

    auto layout = new QVBoxLayout(this);
    layout->addWidget(m_hexViewWidget);
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    connect(m_hexViewWidget->hexDocument(),
            &QHexDocument::dataChanged,
            this,
            [this](const QByteArray&, quint64, QHexChangeReason){
                emit modifyData(true);
            });
}
