#ifndef SORT_H
#define SORT_H

#pragma once

#include "window.h"


class Sort {
public:
    void InsertionSortByPrice(QSqlTableModel* database_model) const;
    void AveragePrice(Window &window) const;
};


#endif // SORT_H
