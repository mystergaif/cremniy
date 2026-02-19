#include "filetab.h"
#include "codeeditor.h"

FileTab::FileTab(QWidget *parent) {

    CodeEditor *codeEditorWidget = new CodeEditor();
    QWidget *emptyWidget1 = new QWidget();
    QWidget *emptyWidget2 = new QWidget();

    QIcon codeIcon(":/code.png");
    QIcon hexIcon(":/hex.png");
    QIcon disasmIcon(":/dasm.png");

    this->addTab(codeEditorWidget, codeIcon, "Code");
    this->addTab(emptyWidget1, hexIcon, "Hex");
    this->addTab(emptyWidget2, disasmIcon, "Disassembler");

}
