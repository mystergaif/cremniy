#include "iconprovider.h"

#include <QFileIconProvider>
#include <QIcon>

QIcon IconProvider::icon(const QFileInfo &info) const {
    if (info.isDir()) {
        return QIcon(":/dasm.png");
    } else if (info.suffix() == "txt") {
        return QIcon(":/code.png");
    }
    return QIcon(":/code.png"); // дефолтная иконка
}
