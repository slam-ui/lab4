#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonArray>
#include <QStandardItemModel>
#include <QDate>
#include "datedialog.h" // Добавьте это

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSaveFile();
    void onLoadFile();
    void onAddCategory();
    void onDeleteCategory();
    void onAddMaterial();
    void onDeleteMaterial();
    void onAddWaybill();
    void onDeleteWaybill();
    void onAddReceipt();
    void onDeleteReceipt();
    void onAddExpense();
    void onDeleteExpense();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* categoryModel;
    QStandardItemModel* materialModel;
    QStandardItemModel* waybillModel;
    QStandardItemModel* receiptModel;
    QStandardItemModel* expenseModel;

    struct Category {
        int id;
        QString name;
        QString unit;
    };

    struct Material {
        int id;
        QString name;
        int categoryId;
    };

    struct Waybill {
        int id;
        QDate date;
    };

    struct MaterialReceipt {
        int id;
        int materialId;
        int quantity;
        int waybillId;
    };

    struct MaterialExpense {
        int id;
        int materialId;
        int quantity;
        int waybillId;
    };

    QVector<Category> categories;
    QVector<Material> materials;
    QVector<Waybill> waybills;
    QVector<MaterialReceipt> receipts;
    QVector<MaterialExpense> expenses;

    DateDialog *dateDialog; // Изменено на указатель
    QDate showDateDialog();
    void loadStyles();
    void clearModels();
};

#endif // MAINWINDOW_H
