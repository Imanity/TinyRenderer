/********************************************************************************
** Form generated from reading UI file 'TinyRenderer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TINYRENDERER_H
#define UI_TINYRENDERER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TinyRendererClass
{
public:
    QAction *actionImportObj;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *rendererLayout;
    QVBoxLayout *toolbarLayout;
    QGroupBox *rendererSettingGroup;
    QGridLayout *resolutionSettingGridLayout;
    QHBoxLayout *resolutionSliderLayout;
    QSlider *resolutionValueSlider;
    QLabel *resolutionValueLabel;
    QLabel *resolutionLabel;
    QLabel *cameraLabel;
    QHBoxLayout *cameraRadioLayout;
    QRadioButton *perspectiveRadioButton;
    QRadioButton *orthogonalRadioButton;
    QGroupBox *layerGroup;
    QGridLayout *gridLayout;
    QCheckBox *LeftBallLayerCheckBox;
    QCheckBox *RightBallLayerCheckBox;
    QCheckBox *Obj1LayerCheckBox;
    QCheckBox *Obj2LayerCheckBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *TinyRendererClass)
    {
        if (TinyRendererClass->objectName().isEmpty())
            TinyRendererClass->setObjectName(QStringLiteral("TinyRendererClass"));
        TinyRendererClass->resize(600, 400);
        actionImportObj = new QAction(TinyRendererClass);
        actionImportObj->setObjectName(QStringLiteral("actionImportObj"));
        centralWidget = new QWidget(TinyRendererClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rendererLayout = new QVBoxLayout();
        rendererLayout->setSpacing(6);
        rendererLayout->setObjectName(QStringLiteral("rendererLayout"));

        horizontalLayout->addLayout(rendererLayout);

        toolbarLayout = new QVBoxLayout();
        toolbarLayout->setSpacing(6);
        toolbarLayout->setObjectName(QStringLiteral("toolbarLayout"));
        toolbarLayout->setContentsMargins(5, 5, 5, 5);
        rendererSettingGroup = new QGroupBox(centralWidget);
        rendererSettingGroup->setObjectName(QStringLiteral("rendererSettingGroup"));
        resolutionSettingGridLayout = new QGridLayout(rendererSettingGroup);
        resolutionSettingGridLayout->setSpacing(6);
        resolutionSettingGridLayout->setContentsMargins(11, 11, 11, 11);
        resolutionSettingGridLayout->setObjectName(QStringLiteral("resolutionSettingGridLayout"));
        resolutionSliderLayout = new QHBoxLayout();
        resolutionSliderLayout->setSpacing(6);
        resolutionSliderLayout->setObjectName(QStringLiteral("resolutionSliderLayout"));
        resolutionValueSlider = new QSlider(rendererSettingGroup);
        resolutionValueSlider->setObjectName(QStringLiteral("resolutionValueSlider"));
        resolutionValueSlider->setFocusPolicy(Qt::NoFocus);
        resolutionValueSlider->setMinimum(10);
        resolutionValueSlider->setMaximum(100);
        resolutionValueSlider->setValue(50);
        resolutionValueSlider->setOrientation(Qt::Horizontal);

        resolutionSliderLayout->addWidget(resolutionValueSlider);

        resolutionValueLabel = new QLabel(rendererSettingGroup);
        resolutionValueLabel->setObjectName(QStringLiteral("resolutionValueLabel"));
        resolutionValueLabel->setAlignment(Qt::AlignCenter);

        resolutionSliderLayout->addWidget(resolutionValueLabel);

        resolutionSliderLayout->setStretch(0, 2);
        resolutionSliderLayout->setStretch(1, 1);

        resolutionSettingGridLayout->addLayout(resolutionSliderLayout, 0, 1, 1, 1);

        resolutionLabel = new QLabel(rendererSettingGroup);
        resolutionLabel->setObjectName(QStringLiteral("resolutionLabel"));

        resolutionSettingGridLayout->addWidget(resolutionLabel, 0, 0, 1, 1);

        cameraLabel = new QLabel(rendererSettingGroup);
        cameraLabel->setObjectName(QStringLiteral("cameraLabel"));

        resolutionSettingGridLayout->addWidget(cameraLabel, 1, 0, 1, 1);

        cameraRadioLayout = new QHBoxLayout();
        cameraRadioLayout->setSpacing(6);
        cameraRadioLayout->setObjectName(QStringLiteral("cameraRadioLayout"));
        perspectiveRadioButton = new QRadioButton(rendererSettingGroup);
        perspectiveRadioButton->setObjectName(QStringLiteral("perspectiveRadioButton"));
        perspectiveRadioButton->setFocusPolicy(Qt::NoFocus);
        perspectiveRadioButton->setChecked(true);

        cameraRadioLayout->addWidget(perspectiveRadioButton);

        orthogonalRadioButton = new QRadioButton(rendererSettingGroup);
        orthogonalRadioButton->setObjectName(QStringLiteral("orthogonalRadioButton"));
        orthogonalRadioButton->setFocusPolicy(Qt::NoFocus);

        cameraRadioLayout->addWidget(orthogonalRadioButton);


        resolutionSettingGridLayout->addLayout(cameraRadioLayout, 1, 1, 1, 1);

        resolutionSettingGridLayout->setColumnStretch(0, 1);
        resolutionSettingGridLayout->setColumnStretch(1, 3);

        toolbarLayout->addWidget(rendererSettingGroup);

        layerGroup = new QGroupBox(centralWidget);
        layerGroup->setObjectName(QStringLiteral("layerGroup"));
        gridLayout = new QGridLayout(layerGroup);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LeftBallLayerCheckBox = new QCheckBox(layerGroup);
        LeftBallLayerCheckBox->setObjectName(QStringLiteral("LeftBallLayerCheckBox"));
        LeftBallLayerCheckBox->setFocusPolicy(Qt::NoFocus);
        LeftBallLayerCheckBox->setChecked(true);

        gridLayout->addWidget(LeftBallLayerCheckBox, 0, 0, 1, 1);

        RightBallLayerCheckBox = new QCheckBox(layerGroup);
        RightBallLayerCheckBox->setObjectName(QStringLiteral("RightBallLayerCheckBox"));
        RightBallLayerCheckBox->setFocusPolicy(Qt::NoFocus);
        RightBallLayerCheckBox->setChecked(true);

        gridLayout->addWidget(RightBallLayerCheckBox, 1, 0, 1, 1);

        Obj1LayerCheckBox = new QCheckBox(layerGroup);
        Obj1LayerCheckBox->setObjectName(QStringLiteral("Obj1LayerCheckBox"));
        Obj1LayerCheckBox->setFocusPolicy(Qt::NoFocus);
        Obj1LayerCheckBox->setChecked(true);

        gridLayout->addWidget(Obj1LayerCheckBox, 2, 0, 1, 1);

        Obj2LayerCheckBox = new QCheckBox(layerGroup);
        Obj2LayerCheckBox->setObjectName(QStringLiteral("Obj2LayerCheckBox"));
        Obj2LayerCheckBox->setFocusPolicy(Qt::NoFocus);
        Obj2LayerCheckBox->setChecked(true);

        gridLayout->addWidget(Obj2LayerCheckBox, 3, 0, 1, 1);


        toolbarLayout->addWidget(layerGroup);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        toolbarLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(toolbarLayout);

        TinyRendererClass->setCentralWidget(centralWidget);

        retranslateUi(TinyRendererClass);

        QMetaObject::connectSlotsByName(TinyRendererClass);
    } // setupUi

    void retranslateUi(QMainWindow *TinyRendererClass)
    {
        TinyRendererClass->setWindowTitle(QApplication::translate("TinyRendererClass", "TinyRenderer", nullptr));
        actionImportObj->setText(QApplication::translate("TinyRendererClass", "Obj\346\226\207\344\273\266", nullptr));
        rendererSettingGroup->setTitle(QApplication::translate("TinyRendererClass", "\346\270\262\346\237\223\345\231\250\350\256\276\347\275\256", nullptr));
        resolutionValueLabel->setText(QApplication::translate("TinyRendererClass", "200 * 150", nullptr));
        resolutionLabel->setText(QApplication::translate("TinyRendererClass", "\345\210\206\350\276\250\347\216\207\357\274\232", nullptr));
        cameraLabel->setText(QApplication::translate("TinyRendererClass", "\346\212\225\345\275\261\346\226\271\345\274\217\357\274\232", nullptr));
        perspectiveRadioButton->setText(QApplication::translate("TinyRendererClass", "\351\200\217\350\247\206\346\212\225\345\275\261", nullptr));
        orthogonalRadioButton->setText(QApplication::translate("TinyRendererClass", "\346\255\243\344\272\244\346\212\225\345\275\261", nullptr));
        layerGroup->setTitle(QApplication::translate("TinyRendererClass", "\346\230\276\347\244\272\345\233\276\345\261\202", nullptr));
        LeftBallLayerCheckBox->setText(QApplication::translate("TinyRendererClass", "\345\267\246\347\220\203\357\274\210\347\273\277\350\211\262\357\274\211", nullptr));
        RightBallLayerCheckBox->setText(QApplication::translate("TinyRendererClass", "\345\217\263\347\220\203\357\274\210\347\272\242\350\211\262\357\274\211", nullptr));
        Obj1LayerCheckBox->setText(QApplication::translate("TinyRendererClass", "obj\346\250\241\345\236\213\357\274\210\345\226\267\347\201\253\351\276\231\357\274\211", nullptr));
        Obj2LayerCheckBox->setText(QApplication::translate("TinyRendererClass", "obj\346\250\241\345\236\213\357\274\210\345\211\221\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TinyRendererClass: public Ui_TinyRendererClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TINYRENDERER_H
