#include "datedialog.h"
#include "qboxlayout.h"
#include "qpushbutton.h"

DateDialog::DateDialog(QWidget *parent)
    : QDialog(parent) {
    calendar = new QCalendarWidget(this);
    calendar->setSelectedDate(QDate::currentDate());

    QPushButton *okButton = new QPushButton("OK", this);
    QPushButton *cancelButton = new QPushButton("Отмена", this);

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(calendar);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    connect(okButton, &QPushButton::clicked, this, &DateDialog::acceptDate);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

QDate DateDialog::date() const {
    return selectedDate; // Возвращаем выбранную дату
}

void DateDialog::acceptDate() {
    selectedDate = calendar->selectedDate();
    accept(); // Подтверждаем диалог
}
