/********************************************************************************
** Form generated from reading UI file 'SetVideoUrlDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETVIDEOURLDIALOG_H
#define UI_SETVIDEOURLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SetVideoUrlDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *lineEdit_fileUrl;
    QPushButton *pushButton_selectFile;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *SetVideoUrlDialog)
    {
        if (SetVideoUrlDialog->objectName().isEmpty())
            SetVideoUrlDialog->setObjectName(QStringLiteral("SetVideoUrlDialog"));
        SetVideoUrlDialog->resize(831, 133);
        verticalLayout = new QVBoxLayout(SetVideoUrlDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(SetVideoUrlDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_7 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, -1, -1, 0);
        label_8 = new QLabel(SetVideoUrlDialog);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_9->addWidget(label_8);

        lineEdit_fileUrl = new QLineEdit(SetVideoUrlDialog);
        lineEdit_fileUrl->setObjectName(QStringLiteral("lineEdit_fileUrl"));
        lineEdit_fileUrl->setMinimumSize(QSize(0, 32));

        horizontalLayout_9->addWidget(lineEdit_fileUrl);

        pushButton_selectFile = new QPushButton(SetVideoUrlDialog);
        pushButton_selectFile->setObjectName(QStringLiteral("pushButton_selectFile"));
        pushButton_selectFile->setMinimumSize(QSize(0, 28));
        pushButton_selectFile->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_9->addWidget(pushButton_selectFile);


        verticalLayout->addLayout(horizontalLayout_9);

        verticalSpacer_4 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(SetVideoUrlDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 28));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(32, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(SetVideoUrlDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 28));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(SetVideoUrlDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), SetVideoUrlDialog, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), SetVideoUrlDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetVideoUrlDialog);
    } // setupUi

    void retranslateUi(QDialog *SetVideoUrlDialog)
    {
        SetVideoUrlDialog->setWindowTitle(QApplication::translate("SetVideoUrlDialog", "Set http address", 0));
        label_2->setText(QApplication::translate("SetVideoUrlDialog", "Select video file (support direct input of network address)", 0));
        label_8->setText(QApplication::translate("SetVideoUrlDialog", "Video address\357\274\232", 0));
        lineEdit_fileUrl->setText(QApplication::translate("SetVideoUrlDialog", "rtmp://202.69.69.180:443/webcast/bshdlive-pc", 0));
        pushButton_selectFile->setText(QApplication::translate("SetVideoUrlDialog", "Select Local File", 0));
        pushButton->setText(QApplication::translate("SetVideoUrlDialog", "Accept", 0));
        pushButton_2->setText(QApplication::translate("SetVideoUrlDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class SetVideoUrlDialog: public Ui_SetVideoUrlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETVIDEOURLDIALOG_H
