#ifndef TOOLTAB_H
#define TOOLTAB_H

#include <qstringview.h>
#include <qwidget.h>

class ToolTab
{
public:

    virtual void saveToFile(QString path) = 0;
    virtual void setTabData(QByteArray &data) = 0;

};

#endif // TOOLTAB_H
