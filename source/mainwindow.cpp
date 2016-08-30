#include <QtWidgets>

#include "mainwindow.hpp"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mpExitAct(nullptr)
{
    ui->setupUi(this);
    CreateActions();
    CreateMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void
MainWindow::CreateActions()
{
    mpExitAct = new QAction(tr("E&xit"), this);
    mpExitAct->setShortcuts(QKeySequence::Quit);
    mpExitAct->setStatusTip(tr("Exit the application"));
    connect(mpExitAct, &QAction::triggered, this, &QWidget::close);

}

void
MainWindow::CreateMenus()
{
    ui->menu_File->addAction(mpExitAct);
}
