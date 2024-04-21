/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QAction *Sortted;
    QAction *Average;
    QAction *Display;
    QAction *About;
    QAction *Exit;
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *buttonDELETE;
    QPushButton *buttonADD;
    QPushButton *buttonUPDATE;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName("Window");
        Window->resize(1057, 595);
        Window->setCursor(QCursor(Qt::ArrowCursor));
        Sortted = new QAction(Window);
        Sortted->setObjectName("Sortted");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/resurces/menu/sort.png"), QSize(), QIcon::Normal, QIcon::Off);
        Sortted->setIcon(icon);
        QFont font;
        font.setPointSize(14);
        Sortted->setFont(font);
        Average = new QAction(Window);
        Average->setObjectName("Average");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/resurces/menu/average.png"), QSize(), QIcon::Normal, QIcon::Off);
        Average->setIcon(icon1);
        Average->setFont(font);
        Display = new QAction(Window);
        Display->setObjectName("Display");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/resurces/menu/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        Display->setIcon(icon2);
        Display->setFont(font);
        About = new QAction(Window);
        About->setObjectName("About");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/resurces/menu/programmer.png"), QSize(), QIcon::Normal, QIcon::Off);
        About->setIcon(icon3);
        About->setFont(font);
        Exit = new QAction(Window);
        Exit->setObjectName("Exit");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/resurces/menu/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        Exit->setIcon(icon4);
        Exit->setFont(font);
        centralwidget = new QWidget(Window);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(9, 0, 1041, 480));
        tableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        buttonDELETE = new QPushButton(centralwidget);
        buttonDELETE->setObjectName("buttonDELETE");
        buttonDELETE->setGeometry(QRect(100, 490, 87, 26));
        buttonDELETE->setCursor(QCursor(Qt::PointingHandCursor));
        buttonADD = new QPushButton(centralwidget);
        buttonADD->setObjectName("buttonADD");
        buttonADD->setGeometry(QRect(10, 490, 87, 26));
        buttonADD->setCursor(QCursor(Qt::PointingHandCursor));
        buttonUPDATE = new QPushButton(centralwidget);
        buttonUPDATE->setObjectName("buttonUPDATE");
        buttonUPDATE->setGeometry(QRect(960, 500, 87, 26));
        buttonUPDATE->setCursor(QCursor(Qt::PointingHandCursor));
        Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1057, 23));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        QFont font1;
        font1.setPointSize(11);
        menu->setFont(font1);
        menu->setCursor(QCursor(Qt::PointingHandCursor));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_2->setCursor(QCursor(Qt::PointingHandCursor));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_3->setCursor(QCursor(Qt::PointingHandCursor));
        Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Window);
        statusbar->setObjectName("statusbar");
        Window->setStatusBar(statusbar);

        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(Sortted);
        menu->addAction(Average);
        menu->addAction(Display);
        menu_2->addAction(Exit);
        menu_3->addAction(About);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "Window", nullptr));
        Sortted->setText(QCoreApplication::translate("Window", "\320\241\320\276\321\200\321\202\321\203\320\262\320\260\321\202\320\270 \320\267\320\260 \321\206\321\226\320\275\320\276\321\216", nullptr));
        Average->setText(QCoreApplication::translate("Window", "\320\241\320\265\321\200\320\265\320\264\320\275\321\217 \320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214", nullptr));
        Display->setText(QCoreApplication::translate("Window", "\320\206\320\275\321\204\320\276\321\200\320\274\320\260\321\206\321\226\321\217 \320\267\320\260 \320\277\321\200\321\226\320\267\320\262\320\270\321\211\320\265\320\274 \320\272\320\273\321\226\321\224\320\275\321\202\320\260", nullptr));
#if QT_CONFIG(tooltip)
        Display->setToolTip(QCoreApplication::translate("Window", "\320\206\320\275\321\204\320\276\321\200\320\274\320\260\321\206\321\226\321\217 \320\267\320\260 \320\277\321\200\321\226\320\267\320\262\320\270\321\211\320\265\320\274 \320\272\320\273\321\226\321\224\320\275\321\202\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        About->setText(QCoreApplication::translate("Window", "\320\237\321\200\320\276 \321\200\320\276\320\267\321\200\320\276\320\261\320\275\320\270\320\272\321\226\320\262", nullptr));
        Exit->setText(QCoreApplication::translate("Window", "\320\222\320\270\321\205\321\226\320\264", nullptr));
        buttonDELETE->setText(QCoreApplication::translate("Window", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270", nullptr));
        buttonADD->setText(QCoreApplication::translate("Window", "\320\224\320\276\320\264\320\260\321\202\320\270", nullptr));
        buttonUPDATE->setText(QCoreApplication::translate("Window", "\320\236\320\275\320\276\320\262\320\270\321\202\320\270", nullptr));
        menu->setTitle(QCoreApplication::translate("Window", "\320\244\321\203\320\275\320\272\321\206\321\226\321\227 \320\261\320\260\320\267\320\270 \320\264\320\260\320\275\320\275\320\270\321\205", nullptr));
        menu_2->setTitle(QCoreApplication::translate("Window", "\320\244\320\260\320\271\320\273", nullptr));
        menu_3->setTitle(QCoreApplication::translate("Window", "\320\224\320\276\320\277\320\276\320\274\320\276\320\263\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
