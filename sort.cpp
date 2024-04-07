#include "sort.h"


void Sort::InsertionSortByPrice(QSqlTableModel* database_model) const {

    int rowCount = database_model->rowCount();

    for (int i = 0; i < rowCount - 1; ++i) {
        int minIndex = i;
        int minPrice = database_model->data(database_model->index(i, database_model->fieldIndex("Ціна"))).toInt();

        for (int j = i + 1; j < rowCount; ++j) {
            int currentPrice = database_model->data(database_model->index(j, database_model->fieldIndex("Ціна"))).toInt();

            if (currentPrice < minPrice) {
                minIndex = j;
                minPrice = currentPrice;
            }
        }

        if (minIndex != i) {
            for (int column = 0; column < database_model->columnCount(); ++column) {
                QVariant temp = database_model->data(database_model->index(i, column));
                database_model->setData(database_model->index(i, column), database_model->data(database_model->index(minIndex, column)));
                database_model->setData(database_model->index(minIndex, column), temp);
            }
        }
    }
}


void Sort::AveragePrice(Window &window) const {

    QSqlDatabase database = window.getDatabase();

    QSqlQuery query(database);
    query.exec("SELECT AVG(Ціна) FROM ComputerShop");

    if (query.next()) {
        double averagePrice = query.value(0).toDouble();
        QString averagePriceString = QString::number(averagePrice, 'f', 2) + " грн";
        QMessageBox::information(nullptr, "Середня вартість", "Середня вартість комп`ютера: " + averagePriceString);
    } else {
        QMessageBox::warning(nullptr, "Помилка", "Не вдалося отримати середню вартість комп`ютерів");
    }
}

