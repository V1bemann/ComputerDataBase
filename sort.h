#ifndef SORT_H
#define SORT_H

#pragma once

#include "window.h"
#include <QCoreApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QSqlError>
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>
#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>

class Sort
{
public:
    void AveragePrice(Window &window) const;
    void selectionSort_descending(QSqlTableModel* database_model) const;
    void selectionSort_increase(QSqlTableModel* database_model) const;
    void convert_txt(const QString& dbFile, const QString& txtFile);
    void open_txt(const QString &txtFile);
};


#endif // SORT_H
