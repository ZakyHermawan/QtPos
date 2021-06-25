#include "include/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QStackedWidget(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::admin_logged() {
    qDebug() << "Berhasil masuk ke halaman administrator";
    this->setCurrentIndex(Window::ADMINISTRATOR);
}
