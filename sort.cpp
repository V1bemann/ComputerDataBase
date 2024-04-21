#include "sort.h"


void Sort::InsertionSortByPrice(QSqlTableModel* database_model) const {
    int rowCount = database_model->rowCount();

    for (int i = 1; i < rowCount; ++i) {
        QVariantList currentRowValues;
        int currentPrice = database_model->data(database_model->index(i, database_model->fieldIndex("Ціна_грн"))).toInt();
        int j = i - 1;

        while (j >= 0 && database_model->data(database_model->index(j, database_model->fieldIndex("Ціна_грн"))).toInt() > currentPrice) {
            for (int column = 0; column < database_model->columnCount(); ++column) {
                currentRowValues.push_back(database_model->data(database_model->index(j, column)));
                database_model->setData(database_model->index(j, column), database_model->data(database_model->index(j + 1, column)));
            }
            for (int column = 0; column < database_model->columnCount(); ++column) {
                database_model->setData(database_model->index(j + 1, column), currentRowValues[column]);
            }
            currentRowValues.clear();
            --j;
        }
    }
}


void Sort::AveragePrice(Window &window) const {

    QSqlDatabase database = window.getDatabase();

    QSqlQuery query(database);
    query.exec("SELECT AVG(Ціна_грн) FROM ComputerShop");

    if (query.next()) {
        double averagePrice = query.value(0).toDouble();
        QString averagePriceString = QString::number(averagePrice, 'f', 2) + " грн";
        QMessageBox::information(nullptr, "Середня вартість", "Середня вартість комп`ютера: " + averagePriceString);
    } else {
        QMessageBox::warning(nullptr, "Помилка", "Не вдалося отримати середню вартість комп`ютерів");
    }
}

