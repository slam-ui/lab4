/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QMenuBar *menubar;
    QMenu *menuФайл;
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    QTabWidget *tabWidget;
    QWidget *tabCategory;
    QVBoxLayout *vboxLayout1;
    QTableView *tableCategory;
    QHBoxLayout *hboxLayout;
    QPushButton *btnAddCategory;
    QPushButton *btnDeleteCategory;
    QWidget *tabMaterial;
    QVBoxLayout *vboxLayout2;
    QTableView *tableMaterial;
    QHBoxLayout *hboxLayout1;
    QPushButton *btnAddMaterial;
    QPushButton *btnDeleteMaterial;
    QWidget *tabWaybill;
    QVBoxLayout *vboxLayout3;
    QTableView *tableWaybill;
    QHBoxLayout *hboxLayout2;
    QPushButton *btnAddWaybill;
    QPushButton *btnDeleteWaybill;
    QWidget *tabReceipt;
    QVBoxLayout *vboxLayout4;
    QTableView *tableReceipt;
    QHBoxLayout *hboxLayout3;
    QPushButton *btnAddReceipt;
    QPushButton *btnDeleteReceipt;
    QWidget *tabExpense;
    QVBoxLayout *vboxLayout5;
    QTableView *tableExpense;
    QHBoxLayout *hboxLayout4;
    QPushButton *btnAddExpense;
    QPushButton *btnDeleteExpense;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 600);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        menuФайл = new QMenu(menubar);
        menuФайл->setObjectName(QString::fromUtf8("menu\320\244\320\260\320\271\320\273"));
        MainWindow->setMenuBar(menubar);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        vboxLayout = new QVBoxLayout(centralwidget);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabCategory = new QWidget();
        tabCategory->setObjectName(QString::fromUtf8("tabCategory"));
        vboxLayout1 = new QVBoxLayout(tabCategory);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        tableCategory = new QTableView(tabCategory);
        tableCategory->setObjectName(QString::fromUtf8("tableCategory"));

        vboxLayout1->addWidget(tableCategory);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        btnAddCategory = new QPushButton(tabCategory);
        btnAddCategory->setObjectName(QString::fromUtf8("btnAddCategory"));

        hboxLayout->addWidget(btnAddCategory);

        btnDeleteCategory = new QPushButton(tabCategory);
        btnDeleteCategory->setObjectName(QString::fromUtf8("btnDeleteCategory"));

        hboxLayout->addWidget(btnDeleteCategory);


        vboxLayout1->addLayout(hboxLayout);

        tabWidget->addTab(tabCategory, QString());
        tabMaterial = new QWidget();
        tabMaterial->setObjectName(QString::fromUtf8("tabMaterial"));
        vboxLayout2 = new QVBoxLayout(tabMaterial);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        tableMaterial = new QTableView(tabMaterial);
        tableMaterial->setObjectName(QString::fromUtf8("tableMaterial"));

        vboxLayout2->addWidget(tableMaterial);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        btnAddMaterial = new QPushButton(tabMaterial);
        btnAddMaterial->setObjectName(QString::fromUtf8("btnAddMaterial"));

        hboxLayout1->addWidget(btnAddMaterial);

        btnDeleteMaterial = new QPushButton(tabMaterial);
        btnDeleteMaterial->setObjectName(QString::fromUtf8("btnDeleteMaterial"));

        hboxLayout1->addWidget(btnDeleteMaterial);


        vboxLayout2->addLayout(hboxLayout1);

        tabWidget->addTab(tabMaterial, QString());
        tabWaybill = new QWidget();
        tabWaybill->setObjectName(QString::fromUtf8("tabWaybill"));
        vboxLayout3 = new QVBoxLayout(tabWaybill);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        tableWaybill = new QTableView(tabWaybill);
        tableWaybill->setObjectName(QString::fromUtf8("tableWaybill"));

        vboxLayout3->addWidget(tableWaybill);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        btnAddWaybill = new QPushButton(tabWaybill);
        btnAddWaybill->setObjectName(QString::fromUtf8("btnAddWaybill"));

        hboxLayout2->addWidget(btnAddWaybill);

        btnDeleteWaybill = new QPushButton(tabWaybill);
        btnDeleteWaybill->setObjectName(QString::fromUtf8("btnDeleteWaybill"));

        hboxLayout2->addWidget(btnDeleteWaybill);


        vboxLayout3->addLayout(hboxLayout2);

        tabWidget->addTab(tabWaybill, QString());
        tabReceipt = new QWidget();
        tabReceipt->setObjectName(QString::fromUtf8("tabReceipt"));
        vboxLayout4 = new QVBoxLayout(tabReceipt);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        tableReceipt = new QTableView(tabReceipt);
        tableReceipt->setObjectName(QString::fromUtf8("tableReceipt"));

        vboxLayout4->addWidget(tableReceipt);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        btnAddReceipt = new QPushButton(tabReceipt);
        btnAddReceipt->setObjectName(QString::fromUtf8("btnAddReceipt"));

        hboxLayout3->addWidget(btnAddReceipt);

        btnDeleteReceipt = new QPushButton(tabReceipt);
        btnDeleteReceipt->setObjectName(QString::fromUtf8("btnDeleteReceipt"));

        hboxLayout3->addWidget(btnDeleteReceipt);


        vboxLayout4->addLayout(hboxLayout3);

        tabWidget->addTab(tabReceipt, QString());
        tabExpense = new QWidget();
        tabExpense->setObjectName(QString::fromUtf8("tabExpense"));
        vboxLayout5 = new QVBoxLayout(tabExpense);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        tableExpense = new QTableView(tabExpense);
        tableExpense->setObjectName(QString::fromUtf8("tableExpense"));

        vboxLayout5->addWidget(tableExpense);

        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        btnAddExpense = new QPushButton(tabExpense);
        btnAddExpense->setObjectName(QString::fromUtf8("btnAddExpense"));

        hboxLayout4->addWidget(btnAddExpense);

        btnDeleteExpense = new QPushButton(tabExpense);
        btnDeleteExpense->setObjectName(QString::fromUtf8("btnDeleteExpense"));

        hboxLayout4->addWidget(btnDeleteExpense);


        vboxLayout5->addLayout(hboxLayout4);

        tabWidget->addTab(tabExpense, QString());

        vboxLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);

        menubar->addAction(menuФайл->menuAction());
        menuФайл->addAction(actionSave);
        menuФайл->addAction(actionLoad);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\243\321\207\320\265\321\202 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\276\320\262 \320\275\320\260 \321\201\320\272\320\273\320\260\320\264\320\265", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        menuФайл->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        btnAddCategory->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnDeleteCategory->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCategory), QCoreApplication::translate("MainWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        btnAddMaterial->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnDeleteMaterial->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMaterial), QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\320\265\321\200\320\270\320\260\320\273\321\213", nullptr));
        btnAddWaybill->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnDeleteWaybill->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWaybill), QCoreApplication::translate("MainWindow", "\320\235\320\260\320\272\320\273\320\260\320\264\320\275\321\213\320\265", nullptr));
        btnAddReceipt->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnDeleteReceipt->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabReceipt), QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\203\320\277\320\273\320\265\320\275\320\270\321\217", nullptr));
        btnAddExpense->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnDeleteExpense->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabExpense), QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\205\320\276\320\264\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
