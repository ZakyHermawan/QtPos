#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStackedWidget>
#include <QDebug>

enum Window {
    LOGIN,
    ADMINISTRATOR
};

class MainWindow : public QStackedWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void admin_logged();
};
#endif // MAINWINDOW_H
