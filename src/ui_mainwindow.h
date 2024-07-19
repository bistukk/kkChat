/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *sendPushButton;
    QLabel *label;
    QLabel *label_2;
    QTableWidget *userListTableWidget;
    QLabel *label_3;
    QLabel *userLabel;
    QTextBrowser *chatTextBrowser;
    QLabel *label_5;
    QTextEdit *chatTextEdit;
    QPushButton *searchPushButton;
    QPushButton *transPushButton;
    QPushButton *recordButton;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *labelUser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(744, 502);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sendPushButton = new QPushButton(centralWidget);
        sendPushButton->setObjectName(QString::fromUtf8("sendPushButton"));
        sendPushButton->setGeometry(QRect(665, 476, 75, 25));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(10);
        sendPushButton->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 60, 500));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);
        label->setPixmap(QPixmap(QString::fromUtf8("images/bar.jpg")));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 0, 250, 65));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setPixmap(QPixmap(QString::fromUtf8("images/search.jpg")));
        userListTableWidget = new QTableWidget(centralWidget);
        if (userListTableWidget->columnCount() < 1)
            userListTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        userListTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        userListTableWidget->setObjectName(QString::fromUtf8("userListTableWidget"));
        userListTableWidget->setGeometry(QRect(60, 65, 250, 435));
        QFont font1;
        font1.setPointSize(14);
        userListTableWidget->setFont(font1);
        userListTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        userListTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        userListTableWidget->setShowGrid(false);
        userListTableWidget->horizontalHeader()->setVisible(false);
        userListTableWidget->horizontalHeader()->setDefaultSectionSize(250);
        userListTableWidget->verticalHeader()->setVisible(false);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 0, 432, 65));
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Sunken);
        label_3->setPixmap(QPixmap(QString::fromUtf8("images/title.jpg")));
        userLabel = new QLabel(centralWidget);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setGeometry(QRect(311, 1, 121, 62));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("04b_21")});
        font2.setPointSize(16);
        userLabel->setFont(font2);
        userLabel->setAutoFillBackground(true);
        userLabel->setFrameShape(QFrame::NoFrame);
        userLabel->setFrameShadow(QFrame::Plain);
        userLabel->setAlignment(Qt::AlignCenter);
        chatTextBrowser = new QTextBrowser(centralWidget);
        chatTextBrowser->setObjectName(QString::fromUtf8("chatTextBrowser"));
        chatTextBrowser->setGeometry(QRect(310, 65, 431, 300));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(310, 365, 432, 40));
        label_5->setFrameShape(QFrame::Box);
        label_5->setFrameShadow(QFrame::Sunken);
        label_5->setPixmap(QPixmap(QString::fromUtf8("images/tool.jpg")));
        chatTextEdit = new QTextEdit(centralWidget);
        chatTextEdit->setObjectName(QString::fromUtf8("chatTextEdit"));
        chatTextEdit->setGeometry(QRect(310, 403, 431, 97));
        searchPushButton = new QPushButton(centralWidget);
        searchPushButton->setObjectName(QString::fromUtf8("searchPushButton"));
        searchPushButton->setGeometry(QRect(74, 25, 191, 26));
        searchPushButton->setFlat(true);
        transPushButton = new QPushButton(centralWidget);
        transPushButton->setObjectName(QString::fromUtf8("transPushButton"));
        transPushButton->setGeometry(QRect(350, 375, 31, 23));
        transPushButton->setFlat(true);
        recordButton = new QPushButton(centralWidget);
        recordButton->setObjectName(QString::fromUtf8("recordButton"));
        recordButton->setGeometry(QRect(590, 372, 80, 24));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(95, 25, 171, 25));
        label_4->setAutoFillBackground(true);
        label_4->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(515, 374, 71, 20));
        label_6->setAlignment(Qt::AlignCenter);
        labelUser = new QLabel(centralWidget);
        labelUser->setObjectName(QString::fromUtf8("labelUser"));
        labelUser->setGeometry(QRect(10, 10, 41, 41));
        labelUser->setPixmap(QPixmap(QString::fromUtf8("images/KK.jpg")));
        MainWindow->setCentralWidget(centralWidget);
        chatTextEdit->raise();
        sendPushButton->raise();
        label->raise();
        label_2->raise();
        userListTableWidget->raise();
        label_3->raise();
        userLabel->raise();
        chatTextBrowser->raise();
        label_5->raise();
        searchPushButton->raise();
        transPushButton->raise();
        recordButton->raise();
        label_4->raise();
        label_6->raise();
        labelUser->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        sendPushButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221 \351\200\201(S)", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = userListTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\345\234\250 \347\272\277 \345\245\275 \345\217\213", nullptr));
        label_3->setText(QString());
        userLabel->setText(QString());
        label_5->setText(QString());
        searchPushButton->setText(QString());
        transPushButton->setText(QString());
        recordButton->setText(QCoreApplication::translate("MainWindow", "\346\214\211\344\275\217\350\257\264\350\257\235", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\345\267\246\344\276\247\346\220\234\347\264\242\344\270\212\347\272\277", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\350\257\255\351\237\263\350\276\223\345\205\245\357\274\232", nullptr));
        labelUser->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
