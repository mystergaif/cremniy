#ifndef TOOLTABWIDGET_H
#define TOOLTABWIDGET_H

#include "codeeditortab.h"
#include "disassemblertab.h"
#include "hexviewtab.h"
#include <QTabWidget>

class QVBoxLayout;
class QSyntaxStyle;
class QComboBox;
class QCheckBox;
class QSpinBox;
class QCompleter;
class QStyleSyntaxHighlighter;
class QCodeEditor;

class ToolTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    ToolTabWidget(QWidget *parent, QString path);
    void saveToFileCurrentTab(QString path);
    void setDataInTabs(QByteArray &data);

private:
    void loadStyle(QString path, QString name);

    CodeEditorTab* m_codeEditorTab;
    HexViewTab* m_hexViewTab;
    DisassemblerTab* m_disassemblerTab;

public slots:
    void onTabModified(bool modified);

};

#endif // TOOLTABWIDGET_H
