#ifndef SORT_H
#define SORT_H

#pragma once

#include "window.h"

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <QCoreApplication>
#include <QDesktopServices>
#include <QUrl>


class Sort {
public:
    void selectionSort_increase(QSqlTableModel* database_model) const;
    void selectionSort_descending(QSqlTableModel* database_model) const;

    void AveragePrice(Window &window) const;

    void convert_txt(const QString& dbFile, const QString& txtFile);
    void open_txt(const QString &txtFile);
};


#endif // SORT_H
