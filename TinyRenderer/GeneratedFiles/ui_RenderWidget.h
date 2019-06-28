/********************************************************************************
** Form generated from reading UI file 'RenderWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDERWIDGET_H
#define UI_RENDERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenderWidget
{
public:

    void setupUi(QWidget *RenderWidget)
    {
        if (RenderWidget->objectName().isEmpty())
            RenderWidget->setObjectName(QStringLiteral("RenderWidget"));
        RenderWidget->resize(400, 300);

        retranslateUi(RenderWidget);

        QMetaObject::connectSlotsByName(RenderWidget);
    } // setupUi

    void retranslateUi(QWidget *RenderWidget)
    {
        RenderWidget->setWindowTitle(QApplication::translate("RenderWidget", "RenderWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenderWidget: public Ui_RenderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERWIDGET_H
