#include "./ui_interface.h"
#include "window.h"
#include "sort.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QSqlError>
#include <QtSql>
#include <QVBoxLayout>


Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("./ComputerShop.db");

    if (database.open()) {
        qDebug("open database!");
    } else {
        qDebug("Not open database!");
    }


    /* creating a database table */
    database_query = new QSqlQuery(database);
    database_query->exec("CREATE TABLE ComputerShop(ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "Код_компьютера TEXT, "
                         "Тип_процессора TEXT, "
                         "Прізвище TEXT, "
                         "Телефон TEXT, "
                         "Ціна INT);");

    database_model = new QSqlTableModel(this, database);
    database_model->setTable("ComputerShop");
    database_model->select();

    ui->tableView->setModel(database_model);

    /* hide the 'ID' column from the database */
    ui->tableView->hideColumn(database_model->fieldIndex("ID"));

    /* changing the standard output sizes of table columns */
    ui->tableView->setColumnWidth(database_model->fieldIndex("Код_компьютера"), 210);
    ui->tableView->setColumnWidth(database_model->fieldIndex("Тип_процессора"), 210);
    ui->tableView->setColumnWidth(database_model->fieldIndex("Прізвище"), 200);
    ui->tableView->setColumnWidth(database_model->fieldIndex("Телефон"), 200);
    ui->tableView->setColumnWidth(database_model->fieldIndex("Ціна"), 200);

    connect(ui->buttonUPDATE, &QPushButton::clicked, this, &Window::on_buttonUPDATE_clicked);
}


Window::~Window() {
    delete ui;
}


void Window::updateDatabase() {
    database_model->select();
}


void Window::on_buttonADD_clicked() {
    database_model->insertRow(database_model->rowCount());
}


void Window::on_buttonDELETE_clicked() {

    QMessageBox message(QMessageBox::Warning, "Попередження"
                        , "Ви дійсно хочете видалити рядок? Дія не оборотна!"
                        , QMessageBox::Yes | QMessageBox::No
                        , this);

    message.setDefaultButton(QMessageBox::No);

    int answer = message.exec();
    if (answer == QMessageBox::Yes) {
        database_model->removeRow(row_database);
    }
}


void Window::on_tableView_clicked(const QModelIndex &index) {
    row_database = index.row();
}


void Window::on_buttonUPDATE_clicked() {
    database_model->select();
    database_model->setSort(database_model->fieldIndex("ID"), Qt::AscendingOrder);
    database_model->select();

    ui->statusbar->showMessage("Оновлення екрану...", 1000);
}


void Window::on_Sortted_triggered() {

    Sort sort;

    ui->tableView->setColumnWidth(database_model->fieldIndex("Код_компьютера"), 210);
    ui->tableView->setColumnWidth(database_model->fieldIndex("Тип_процессора"), 210);
    ui->tableView->setColumnWidth(database_model->fieldIndex("Прізвище"), 200);
    ui->tableView->setColumnWidth(database_model->fieldIndex("Телефон"), 200);
    ui->tableView->setColumnWidth(database_model->fieldIndex("Ціна"), 200);

    sort.InsertionSortByPrice(database_model);
    ui->tableView->sortByColumn(database_model->fieldIndex("Ціна"), Qt::AscendingOrder);

    ui->statusbar->showMessage("Сортування...", 2000);
}


void Window::on_Average_triggered() {

    ui->statusbar->showMessage("Відображення середньої ціни комп`ютерів в магазині", 2000);

    Sort sort;
    sort.AveragePrice(*this);
}


void Window::on_Display_triggered() {

    ui->statusbar->showMessage("Пошук...", 2000);

    bool ok;
    QString model = QInputDialog::getText(this, tr("Введіть прізвище клієнта")
                                              , tr("Прізвище:"), QLineEdit::Normal, ""
                                              , &ok);
    if (!ok || model.isEmpty()) {
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM ComputerShop WHERE Прізвище = ?");
    query.addBindValue(model);
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        QString result = QString("Дані за прізвищем:\n\n"
                                "Код комп'ютера: %1\n"
                                "Тип процесора: %2\n"
                                "Прізвище: %3\n"
                                "Телефон: %4\n"
                                "Ціна: %5 грн\n")
                                .arg(query.value("Код_компьютера").toString())
                                .arg(query.value("Тип_процессора").toString())
                                .arg(query.value("Прізвище").toString())
                                .arg(query.value("Телефон").toString())
                                .arg(query.value("Ціна").toString());

        QMessageBox::information(this, tr("Інформація про комп'ютер"), result);
    } else {
        QMessageBox::information(this, tr("Інформація про комп'ютер"), tr("Клієнта з таким прізвищем не знайдено."));
    }
}


void Window::on_About_triggered() {
    ui->statusbar->showMessage("Інформація...", 2000);

    QMessageBox::information(this, "Про розробників:",
                             "Розробник цього ПЗ - Санжура Артем,"
                             "\nСтудент ВСП Павлоградський фаховий коледж НТУ ''ДП''\nГрупи KI-2-21");
}


void Window::on_Exit_triggered() {
    QApplication::quit();
}

