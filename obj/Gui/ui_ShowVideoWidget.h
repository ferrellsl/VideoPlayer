/********************************************************************************
** Form generated from reading UI file 'ShowVideoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWVIDEOWIDGET_H
#define UI_SHOWVIDEOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowVideoWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_back;
    QWidget *widget_name;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_name;
    QWidget *widget_erro;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_erro;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_close;

    void setupUi(QWidget *ShowVideoWidget)
    {
        if (ShowVideoWidget->objectName().isEmpty())
            ShowVideoWidget->setObjectName(QStringLiteral("ShowVideoWidget"));
        ShowVideoWidget->resize(412, 304);
        ShowVideoWidget->setMouseTracking(true);
        ShowVideoWidget->setFocusPolicy(Qt::ClickFocus);
        verticalLayout = new QVBoxLayout(ShowVideoWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_back = new QWidget(ShowVideoWidget);
        widget_back->setObjectName(QStringLiteral("widget_back"));
        widget_back->setStyleSheet(QLatin1String("QWidget#widget_back\n"
"{\n"
"border:1px solid rgba(74, 108, 155, 0);\n"
"border-radius:2px;\n"
"	background-color: rgba(74, 108, 155, 0);\n"
"}\n"
"\n"
""));
        widget_name = new QWidget(widget_back);
        widget_name->setObjectName(QStringLiteral("widget_name"));
        widget_name->setGeometry(QRect(20, 250, 371, 22));
        widget_name->setStyleSheet(QLatin1String("QWidget#widget_name\n"
"{\n"
"	background-color: rgba(220, 255, 193, 0);\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(widget_name);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, 6, 0);
        horizontalSpacer = new QSpacerItem(62, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_name = new QLabel(widget_name);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setMaximumSize(QSize(200, 16777215));
        label_name->setStyleSheet(QLatin1String("	font-family: \"Microsoft Windows\";\n"
"	color:rgb(33,33,33);\n"
"	font-size: 13px;\n"
"border:1px solid rgba(102, 102, 102, 92);\n"
"	border-radius:1px;\n"
"	\n"
"background-color: rgb(255, 255, 255);\n"
"	\n"
"	"));

        horizontalLayout->addWidget(label_name);

        widget_erro = new QWidget(widget_back);
        widget_erro->setObjectName(QStringLiteral("widget_erro"));
        widget_erro->setGeometry(QRect(20, 20, 331, 49));
        widget_erro->setStyleSheet(QLatin1String("QWidget#widget_erro\n"
"{\n"
"	background-color: rgba(220, 255, 193, 0);\n"
"}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(widget_erro);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(63, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_erro = new QLabel(widget_erro);
        label_erro->setObjectName(QStringLiteral("label_erro"));
        label_erro->setStyleSheet(QLatin1String("	font-family: \"Microsoft Windows\";\n"
"	color:rgb(233,233,233);\n"
"	font-size: 16px;\n"
"border:1px solid rgba(102, 102, 102, 92);\n"
"	border-radius:1px;\n"
"	padding-left:6px;\n"
"padding-right:6px;\n"
"background-color: rgb(255, 25, 25);\n"
"	\n"
"	"));

        horizontalLayout_2->addWidget(label_erro);

        horizontalSpacer_3 = new QSpacerItem(63, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_close = new QPushButton(widget_back);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setGeometry(QRect(240, 120, 36, 36));
        pushButton_close->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_close->setStyleSheet(QLatin1String("QPushButton{ \n"
"image: url(:/image/closebtn_3.png);\n"
"background-color:rgba(200,80,6,0);  \n"
"border-radius:18px; \n"
"color: rgb(255, 255, 255);\n"
"font-size:16px;\n"
"font-family:\"Microsoft Windows\"\n"
"} \n"
"QPushButton:hover{ \n"
"background-color:rgb(200,80,6); \n"
"} \n"
"QPushButton:pressed{ \n"
"background-color:rgb(200,80,6);  \n"
"}\n"
""));

        verticalLayout->addWidget(widget_back);


        retranslateUi(ShowVideoWidget);

        QMetaObject::connectSlotsByName(ShowVideoWidget);
    } // setupUi

    void retranslateUi(QWidget *ShowVideoWidget)
    {
        ShowVideoWidget->setWindowTitle(QApplication::translate("ShowVideoWidget", "Form", 0));
        label_name->setText(QApplication::translate("ShowVideoWidget", "TextLabel", 0));
        label_erro->setText(QApplication::translate("ShowVideoWidget", "Play failed, retrying...", 0));
        pushButton_close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ShowVideoWidget: public Ui_ShowVideoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWVIDEOWIDGET_H
