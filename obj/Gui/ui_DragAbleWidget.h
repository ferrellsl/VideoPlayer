/********************************************************************************
** Form generated from reading UI file 'DragAbleWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGABLEWIDGET_H
#define UI_DRAGABLEWIDGET_H

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

class Ui_DragAbleWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_frame;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_back;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_titleWidget_Back;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_40;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_titleName;
    QSpacerItem *horizontalSpacer_26;
    QWidget *widget_titleBtn;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Max;
    QPushButton *btnMenu_Close;
    QWidget *widget_container;

    void setupUi(QWidget *DragAbleWidget)
    {
        if (DragAbleWidget->objectName().isEmpty())
            DragAbleWidget->setObjectName(QStringLiteral("DragAbleWidget"));
        DragAbleWidget->resize(718, 449);
        verticalLayout = new QVBoxLayout(DragAbleWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_frame = new QWidget(DragAbleWidget);
        widget_frame->setObjectName(QStringLiteral("widget_frame"));
        widget_frame->setStyleSheet(QLatin1String("QWidget#widget_frame\n"
"{\n"
"	border:3px solid  rgb(46, 165, 255);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"QWidget#widget_back\n"
"{\n"
"border-radius:3px;\n"
"}\n"
"\n"
"QWidget#widget_title\n"
"{\n"
"	border-top-right-radius:5px;\n"
"	border-top-left-radius:5px;\n"
"}\n"
"\n"
"QWidget#widget_container\n"
"{\n"
"	border-bottom-right-radius:5px;\n"
"	border-bottom-left-radius:5px;\n"
"}\n"
"\n"
"QStackedWidget\n"
"{\n"
"	border-bottom-right-radius:5px;\n"
"	border-bottom-left-radius:5px;\n"
"}\n"
"\n"
"QWidget#page_courseList\n"
"{\n"
"	border-bottom-right-radius:5px;\n"
"	border-bottom-left-radius:5px;\n"
"}\n"
"\n"
"	"));
        verticalLayout_6 = new QVBoxLayout(widget_frame);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_back = new QWidget(widget_frame);
        widget_back->setObjectName(QStringLiteral("widget_back"));
        widget_back->setStyleSheet(QStringLiteral(""));
        verticalLayout_8 = new QVBoxLayout(widget_back);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_titleWidget_Back = new QVBoxLayout();
        verticalLayout_titleWidget_Back->setSpacing(0);
        verticalLayout_titleWidget_Back->setObjectName(QStringLiteral("verticalLayout_titleWidget_Back"));
        verticalLayout_titleWidget_Back->setContentsMargins(-1, 0, -1, -1);
        widget_title = new QWidget(widget_back);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_title->sizePolicy().hasHeightForWidth());
        widget_title->setSizePolicy(sizePolicy);
        widget_title->setMinimumSize(QSize(0, 32));
        widget_title->setMaximumSize(QSize(16777215, 32));
        widget_title->setStyleSheet(QLatin1String("\n"
"QPushButton#btnMenu,QPushButton#btnMenu_Min,QPushButton#btnMenu_Max,QPushButton#btnMenu_Close{\n"
"	border-radius:0px;\n"
"	color: #F0F0F0;\n"
"	background-color:rgba(0,0,0,0);\n"
"	border-style:none;\n"
"}\n"
"\n"
"QPushButton#btnMenu:hover,QPushButton#btnMenu_Min:hover,QPushButton#btnMenu_Max:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(25, 134, 199, 0), stop:1 #636363);\n"
"}\n"
"\n"
"QPushButton#btnMenu_Close:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(238, 0, 0, 128), stop:1 rgba(238, 44, 44, 255));\n"
"}\n"
"\n"
"QWidget#widget_title{\n"
"        background-color:rgb(0, 153, 255); \n"
"}\n"
"\n"
"QLabel#lab_Ico,QLabel#lab_Title{\n"
"	border-radius:0px;\n"
"	color: #F0F0F0;\n"
"	background-color:rgba(0,0,0,0);\n"
"	border-style:none;\n"
"}\n"
""));
        horizontalLayout_40 = new QHBoxLayout(widget_title);
        horizontalLayout_40->setSpacing(0);
        horizontalLayout_40->setObjectName(QStringLiteral("horizontalLayout_40"));
        horizontalLayout_40->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(0);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(12, 0, 0, -1);
        label_titleName = new QLabel(widget_title);
        label_titleName->setObjectName(QStringLiteral("label_titleName"));
        label_titleName->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font-size:16px;\n"
"font-weight:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_19->addWidget(label_titleName);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_26);

        widget_titleBtn = new QWidget(widget_title);
        widget_titleBtn->setObjectName(QStringLiteral("widget_titleBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_titleBtn->sizePolicy().hasHeightForWidth());
        widget_titleBtn->setSizePolicy(sizePolicy1);
        widget_titleBtn->setMaximumSize(QSize(16777215, 46));
        horizontalLayout_5 = new QHBoxLayout(widget_titleBtn);
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        btnMenu_Min = new QPushButton(widget_titleBtn);
        btnMenu_Min->setObjectName(QStringLiteral("btnMenu_Min"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy2);
        btnMenu_Min->setMaximumSize(QSize(16777215, 60));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);
        btnMenu_Min->setLayoutDirection(Qt::LeftToRight);
        btnMenu_Min->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/showminisizebtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMenu_Min->setIcon(icon);
        btnMenu_Min->setIconSize(QSize(22, 22));
        btnMenu_Min->setFlat(true);

        horizontalLayout_5->addWidget(btnMenu_Min);

        btnMenu_Max = new QPushButton(widget_titleBtn);
        btnMenu_Max->setObjectName(QStringLiteral("btnMenu_Max"));
        sizePolicy2.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy2);
        btnMenu_Max->setMaximumSize(QSize(16777215, 60));
        btnMenu_Max->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);
        btnMenu_Max->setLayoutDirection(Qt::LeftToRight);
        btnMenu_Max->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/showmaxsizebtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMenu_Max->setIcon(icon1);
        btnMenu_Max->setIconSize(QSize(22, 22));
        btnMenu_Max->setFlat(true);

        horizontalLayout_5->addWidget(btnMenu_Max);


        horizontalLayout_19->addWidget(widget_titleBtn);

        btnMenu_Close = new QPushButton(widget_title);
        btnMenu_Close->setObjectName(QStringLiteral("btnMenu_Close"));
        sizePolicy2.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy2);
        btnMenu_Close->setCursor(QCursor(Qt::PointingHandCursor));
        btnMenu_Close->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/close_normal.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMenu_Close->setIcon(icon2);
        btnMenu_Close->setIconSize(QSize(28, 28));

        horizontalLayout_19->addWidget(btnMenu_Close);


        horizontalLayout_40->addLayout(horizontalLayout_19);


        verticalLayout_titleWidget_Back->addWidget(widget_title);


        verticalLayout_8->addLayout(verticalLayout_titleWidget_Back);

        widget_container = new QWidget(widget_back);
        widget_container->setObjectName(QStringLiteral("widget_container"));
        sizePolicy1.setHeightForWidth(widget_container->sizePolicy().hasHeightForWidth());
        widget_container->setSizePolicy(sizePolicy1);
        widget_container->setStyleSheet(QLatin1String("QWidget#widget_container\n"
"{\n"
"	background-color: rgb(22, 22, 22);\n"
"}\n"
""));

        verticalLayout_8->addWidget(widget_container);


        verticalLayout_6->addWidget(widget_back);


        verticalLayout->addWidget(widget_frame);


        retranslateUi(DragAbleWidget);

        QMetaObject::connectSlotsByName(DragAbleWidget);
    } // setupUi

    void retranslateUi(QWidget *DragAbleWidget)
    {
        DragAbleWidget->setWindowTitle(QApplication::translate("DragAbleWidget", "Form", 0));
        label_titleName->setText(QApplication::translate("DragAbleWidget", "\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250", 0));
        btnMenu_Min->setText(QString());
        btnMenu_Max->setText(QString());
        btnMenu_Close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DragAbleWidget: public Ui_DragAbleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGABLEWIDGET_H
