#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QCalendarWidget>
#include "datedialog.h" // Подключение кастомного диалога

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dateDialog(new DateDialog(this)) // Инициализация указателя
{
    ui->setupUi(this);
    loadStyles();

    // Подключение сигналов
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::onSaveFile);
    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::onLoadFile);

    // Кнопки для категорий
    connect(ui->btnAddCategory, &QPushButton::clicked, this, &MainWindow::onAddCategory);
    connect(ui->btnDeleteCategory, &QPushButton::clicked, this, &MainWindow::onDeleteCategory);

    // Кнопки для материалов
    connect(ui->btnAddMaterial, &QPushButton::clicked, this, &MainWindow::onAddMaterial);
    connect(ui->btnDeleteMaterial, &QPushButton::clicked, this, &MainWindow::onDeleteMaterial);

    // Кнопки для накладных
    connect(ui->btnAddWaybill, &QPushButton::clicked, this, &MainWindow::onAddWaybill);
    connect(ui->btnDeleteWaybill, &QPushButton::clicked, this, &MainWindow::onDeleteWaybill);

    // Кнопки для поступлений
    connect(ui->btnAddReceipt, &QPushButton::clicked, this, &MainWindow::onAddReceipt);
    connect(ui->btnDeleteReceipt, &QPushButton::clicked, this, &MainWindow::onDeleteReceipt);

    // Кнопки для расходов
    connect(ui->btnAddExpense, &QPushButton::clicked, this, &MainWindow::onAddExpense);
    connect(ui->btnDeleteExpense, &QPushButton::clicked, this, &MainWindow::onDeleteExpense);

    // Инициализация моделей
    categoryModel = new QStandardItemModel();
    categoryModel->setHorizontalHeaderLabels({"ID", "Название", "Ед.изм"});
    ui->tableCategory->setModel(categoryModel);
    ui->tableCategory->setAlternatingRowColors(true);

    materialModel = new QStandardItemModel();
    materialModel->setHorizontalHeaderLabels({"ID", "Название", "Код категории"});
    ui->tableMaterial->setModel(materialModel);
    ui->tableMaterial->setAlternatingRowColors(true);

    waybillModel = new QStandardItemModel();
    waybillModel->setHorizontalHeaderLabels({"ID", "Дата"});
    ui->tableWaybill->setModel(waybillModel);
    ui->tableWaybill->setAlternatingRowColors(true);

    receiptModel = new QStandardItemModel();
    receiptModel->setHorizontalHeaderLabels({"ID", "Материал", "Количество", "Накладная"});
    ui->tableReceipt->setModel(receiptModel);
    ui->tableReceipt->setAlternatingRowColors(true);

    expenseModel = new QStandardItemModel();
    expenseModel->setHorizontalHeaderLabels({"ID", "Материал", "Количество", "Накладная"});
    ui->tableExpense->setModel(expenseModel);
    ui->tableExpense->setAlternatingRowColors(true);
}

MainWindow::~MainWindow() {
    delete ui;
    delete dateDialog; // Теперь dateDialog является указателем и может быть удален
}

void MainWindow::loadStyles() {
    QFile file(":/style/style.qss");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Failed to load stylesheet";
        return;
    }
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);
}

void MainWindow::clearModels() {
    categoryModel->clear();
    materialModel->clear();
    waybillModel->clear();
    receiptModel->clear();
    expenseModel->clear();

    // Восстановление заголовков таблиц
    categoryModel->setHorizontalHeaderLabels({"ID", "Название", "Ед.изм"});
    materialModel->setHorizontalHeaderLabels({"ID", "Название", "Код категории"});
    waybillModel->setHorizontalHeaderLabels({"ID", "Дата"});
    receiptModel->setHorizontalHeaderLabels({"ID", "Материал", "Количество", "Накладная"});
    expenseModel->setHorizontalHeaderLabels({"ID", "Материал", "Количество", "Накладная"});
}

// Метод для выбора даты через кастомный диалог
QDate MainWindow::showDateDialog() {
    if (dateDialog->exec() == QDialog::Accepted) {
        return dateDialog->date();
    } else {
        return QDate(); // Если пользователь отменил выбор
    }
}

// Исправленный слот для добавления накладной
void MainWindow::onAddWaybill() {
    QDate date = showDateDialog();
    if (date.isNull()) return;
    int id = waybills.size() + 1;
    Waybill newWaybill{id, date};
    waybills.append(newWaybill);
    waybillModel->appendRow({
        new QStandardItem(QString::number(id)),
        new QStandardItem(date.toString("yyyy-MM-dd"))
    });
}

// Сохранение данных
void MainWindow::onSaveFile() {
    QString filename = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "JSON Files (*.json)");
    if (filename.isEmpty()) return;

    QJsonObject root;

    // Сериализация категорий
    QJsonArray categoriesArray;
    for (const auto& cat : categories) {
        QJsonObject catObj;
        catObj["id"] = cat.id;
        catObj["name"] = cat.name;
        catObj["unit"] = cat.unit;
        categoriesArray.append(catObj);
    }
    root["categories"] = categoriesArray;

    // Сериализация материалов
    QJsonArray materialsArray;
    for (const auto& mat : materials) {
        QJsonObject matObj;
        matObj["id"] = mat.id;
        matObj["name"] = mat.name;
        matObj["category_id"] = mat.categoryId;
        materialsArray.append(matObj);
    }
    root["materials"] = materialsArray;

    // Сериализация накладных
    QJsonArray waybillsArray;
    for (const auto& wb : waybills) {
        QJsonObject wbObj;
        wbObj["id"] = wb.id;
        wbObj["date"] = wb.date.toString("yyyy-MM-dd");
        waybillsArray.append(wbObj);
    }
    root["waybills"] = waybillsArray;

    // Сериализация поступлений
    QJsonArray receiptsArray;
    for (const auto& rec : receipts) {
        QJsonObject recObj;
        recObj["id"] = rec.id;
        recObj["material_id"] = rec.materialId;
        recObj["quantity"] = rec.quantity;
        recObj["waybill_id"] = rec.waybillId;
        receiptsArray.append(recObj);
    }
    root["receipts"] = receiptsArray;

    // Сериализация расходов
    QJsonArray expensesArray;
    for (const auto& exp : expenses) {
        QJsonObject expObj;
        expObj["id"] = exp.id;
        expObj["material_id"] = exp.materialId;
        expObj["quantity"] = exp.quantity;
        expObj["waybill_id"] = exp.waybillId;
        expensesArray.append(expObj);
    }
    root["expenses"] = expensesArray;

    QJsonDocument doc(root);
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
        file.write(doc.toJson());
}

// Загрузка данных
void MainWindow::onLoadFile() {
    QString filename = QFileDialog::getOpenFileName(this, "Открыть файл", "", "JSON Files (*.json)");
    if (filename.isEmpty()) return;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) return;

    categories.clear();
    materials.clear();
    waybills.clear();
    receipts.clear();
    expenses.clear();

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();

    // Десериализация категорий
    const QJsonArray& cats = obj["categories"].toArray();
    for (const auto& v : cats) {
        QJsonObject catObj = v.toObject();
        Category cat;
        cat.id = catObj["id"].toInt();
        cat.name = catObj["name"].toString();
        cat.unit = catObj["unit"].toString();
        categories.append(cat);
    }

    // Десериализация материалов
    const QJsonArray& mats = obj["materials"].toArray();
    for (const auto& v : mats) {
        QJsonObject matObj = v.toObject();
        Material mat;
        mat.id = matObj["id"].toInt();
        mat.name = matObj["name"].toString();
        mat.categoryId = matObj["category_id"].toInt();
        materials.append(mat);
    }

    // Десериализация накладных
    const QJsonArray& wbs = obj["waybills"].toArray();
    for (const auto& v : wbs) {
        QJsonObject wbObj = v.toObject();
        Waybill wb;
        wb.id = wbObj["id"].toInt();
        wb.date = QDate::fromString(wbObj["date"].toString(), "yyyy-MM-dd");
        waybills.append(wb);
    }

    // Десериализация поступлений
    const QJsonArray& recs = obj["receipts"].toArray();
    for (const auto& v : recs) {
        QJsonObject recObj = v.toObject();
        MaterialReceipt rec;
        rec.id = recObj["id"].toInt();
        rec.materialId = recObj["material_id"].toInt();
        rec.quantity = recObj["quantity"].toInt();
        rec.waybillId = recObj["waybill_id"].toInt();
        receipts.append(rec);
    }

    // Десериализация расходов
    const QJsonArray& exps = obj["expenses"].toArray();
    for (const auto& v : exps) {
        QJsonObject expObj = v.toObject();
        MaterialExpense exp;
        exp.id = expObj["id"].toInt();
        exp.materialId = expObj["material_id"].toInt();
        exp.quantity = expObj["quantity"].toInt();
        exp.waybillId = expObj["waybill_id"].toInt();
        expenses.append(exp);
    }

    clearModels();

    // Заполнение моделей данными
    for (const auto& cat : categories)
        categoryModel->appendRow({
            new QStandardItem(QString::number(cat.id)),
            new QStandardItem(cat.name),
            new QStandardItem(cat.unit)
        });

    for (const auto& mat : materials)
        materialModel->appendRow({
            new QStandardItem(QString::number(mat.id)),
            new QStandardItem(mat.name),
            new QStandardItem(QString::number(mat.categoryId))
        });

    for (const auto& wb : waybills)
        waybillModel->appendRow({
            new QStandardItem(QString::number(wb.id)),
            new QStandardItem(wb.date.toString("yyyy-MM-dd"))
        });

    for (const auto& rec : receipts)
        receiptModel->appendRow({
            new QStandardItem(QString::number(rec.id)),
            new QStandardItem(QString::number(rec.materialId)),
            new QStandardItem(QString::number(rec.quantity)),
            new QStandardItem(QString::number(rec.waybillId))
        });

    for (const auto& exp : expenses)
        expenseModel->appendRow({
            new QStandardItem(QString::number(exp.id)),
            new QStandardItem(QString::number(exp.materialId)),
            new QStandardItem(QString::number(exp.quantity)),
            new QStandardItem(QString::number(exp.waybillId))
        });
}

// Добавление категории
void MainWindow::onAddCategory() {
    bool ok;
    QString name = QInputDialog::getText(
        this,
        "Категория",
        "Название:",
        QLineEdit::Normal,
        "",
        &ok
        );
    if (!ok) return;

    QString unit = QInputDialog::getText(
        this,
        "Ед.изм.",
        "Единицы измерения:",
        QLineEdit::Normal,
        "",
        &ok
        );
    if (!ok) return;

    int id = categories.size() + 1;
    categories.append({id, name, unit});
    categoryModel->appendRow({
        new QStandardItem(QString::number(id)),
        new QStandardItem(name),
        new QStandardItem(unit)
    });
}

// Удаление категории
void MainWindow::onDeleteCategory() {
    QModelIndexList indexes = ui->tableCategory->selectionModel()->selectedRows();
    if (indexes.isEmpty()) return;

    int row = indexes[0].row();
    int catId = categories[row].id;
    categories.remove(row);

    // Удаление связанных материалов
    materials.erase(
        std::remove_if(materials.begin(), materials.end(),
                       [catId](const Material& mat) { return mat.categoryId == catId; }),
        materials.end()
        );

    categoryModel->removeRow(row);
}

// Добавление материала
void MainWindow::onAddMaterial() {
    if (categories.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Сначала добавьте категорию!");
        return;
    }

    bool ok;
    QString name = QInputDialog::getText(
        this,
        "Материал",
        "Название:",
        QLineEdit::Normal,
        "",
        &ok
        );
    if (!ok) return;

    QStringList catNames;
    for (const auto& cat : categories)
        catNames << cat.name;

    int idx = QInputDialog::getItem(
                  this,
                  "Категория",
                  "Выберите категорию:",
                  catNames,
                  0,
                  false,
                  &ok
                  ).toInt();

    if (!ok) return;
    int catId = categories[idx].id;

    int id = materials.size() + 1;
    materials.append({id, name, catId});
    materialModel->appendRow({
        new QStandardItem(QString::number(id)),
        new QStandardItem(name),
        new QStandardItem(QString::number(catId))
    });
}

// Удаление материала
void MainWindow::onDeleteMaterial() {
    QModelIndexList indexes = ui->tableMaterial->selectionModel()->selectedRows();
    if (indexes.isEmpty()) return;

    int row = indexes[0].row();
    materials.remove(row);
    materialModel->removeRow(row);
}



// Удаление накладной
void MainWindow::onDeleteWaybill() {
    QModelIndexList indexes = ui->tableWaybill->selectionModel()->selectedRows();
    if (indexes.isEmpty()) return;

    int row = indexes[0].row();
    int wbId = waybills[row].id;

    // Удаление связанных поступлений и расходов
    receipts.erase(
        std::remove_if(receipts.begin(), receipts.end(),
                       [wbId](const MaterialReceipt& rec) { return rec.waybillId == wbId; }),
        receipts.end()
        );

    expenses.erase(
        std::remove_if(expenses.begin(), expenses.end(),
                       [wbId](const MaterialExpense& exp) { return exp.waybillId == wbId; }),
        expenses.end()
        );

    waybills.remove(row);
    waybillModel->removeRow(row);
}

// Добавление поступления
void MainWindow::onAddReceipt() {
    if (materials.isEmpty() || waybills.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Сначала добавьте материал и накладную!");
        return;
    }

    bool ok;
    int matId = QInputDialog::getInt(
        this,
        "Материал",
        "Код материала:",
        1,
        1,
        1000,
        1,
        &ok
        );
    if (!ok) return;

    int quantity = QInputDialog::getInt(
        this,
        "Количество",
        "Количество:",
        1,
        1,
        1000000,
        1,
        &ok
        );
    if (!ok) return;

    int wbId = QInputDialog::getInt(
        this,
        "Накладная",
        "Код накладной:",
        1,
        1,
        1000,
        1,
        &ok
        );
    if (!ok) return;

    int id = receipts.size() + 1;
    receipts.append({id, matId, quantity, wbId});
    receiptModel->appendRow({
        new QStandardItem(QString::number(id)),
        new QStandardItem(QString::number(matId)),
        new QStandardItem(QString::number(quantity)),
        new QStandardItem(QString::number(wbId))
    });
}

// Удаление поступления
void MainWindow::onDeleteReceipt() {
    QModelIndexList indexes = ui->tableReceipt->selectionModel()->selectedRows();
    if (indexes.isEmpty()) return;

    int row = indexes[0].row();
    receipts.remove(row);
    receiptModel->removeRow(row);
}

// Добавление расхода
void MainWindow::onAddExpense() {
    if (materials.isEmpty() || waybills.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Сначала добавьте материал и накладную!");
        return;
    }

    bool ok;
    int matId = QInputDialog::getInt(
        this,
        "Материал",
        "Код материала:",
        1,
        1,
        1000,
        1,
        &ok
        );
    if (!ok) return;

    int quantity = QInputDialog::getInt(
        this,
        "Количество",
        "Количество:",
        1,
        1,
        1000000,
        1,
        &ok
        );
    if (!ok) return;

    int wbId = QInputDialog::getInt(
        this,
        "Накладная",
        "Код накладной:",
        1,
        1,
        1000,
        1,
        &ok
        );
    if (!ok) return;

    int id = expenses.size() + 1;
    expenses.append({id, matId, quantity, wbId});
    expenseModel->appendRow({
        new QStandardItem(QString::number(id)),
        new QStandardItem(QString::number(matId)),
        new QStandardItem(QString::number(quantity)),
        new QStandardItem(QString::number(wbId))
    });
}

// Удаление расхода
void MainWindow::onDeleteExpense() {
    QModelIndexList indexes = ui->tableExpense->selectionModel()->selectedRows();
    if (indexes.isEmpty()) return;

    int row = indexes[0].row();
    expenses.remove(row);
    expenseModel->removeRow(row);
}
