#ifndef DATEDIALOG_H
#define DATEDIALOG_H

#include <QDialog>
#include <QCalendarWidget>

class DateDialog : public QDialog {
    Q_OBJECT

public:
    explicit DateDialog(QWidget *parent = nullptr);
    QDate date() const; // Объявление метода date()

private slots:
    void acceptDate();

private:
    QCalendarWidget *calendar;
    QDate selectedDate;
};

#endif // DATEDIALOG_H
