//==================================================================================================
//  File Name:
//      mainwindow.cpp
//
//  Product:
//      BerlinUhr
//
//  Authors:
//      Ian Heaton
//
//  Copyright Notice:
//
//==================================================================================================
//
#include <QtWidgets>

#include "mainwindow.hpp"
#include "ui_main_window.h"
#include "qgraphics_rectwidget.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mpScene(nullptr),
    mpExitAct(nullptr)
{
    ui->setupUi(this);
    CreateActions();
    CreateMenus();
    DrawLights();

    ui->GraphicsView->setScene(mpScene);
    ui->GraphicsView->setFrameStyle(0);
    ui->GraphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->GraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->GraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //mpGView->setGeometry(QRect(0, 0, 761, 761));
    ui->GraphicsView->show();
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

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      DrawLights()
//
//  Summary:
//      Does...
//
//
//
//  Returns:
//      {Optional...}
//
//  Exceptions:
//      {Optional...}
//
//  Remarks:
//      {Optional...}
//
//  See Also:
//      {Optional...}
//--------------------------------------------------------------------------------------------------
//
void
MainWindow::DrawLights()
{
    QGraphicsRectWidget *vpLight1 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight2 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight3 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight4 = new QGraphicsRectWidget;
    vpLight1->setZValue(1);
    vpLight2->setZValue(2);
    vpLight3->setZValue(3);
    vpLight4->setZValue(4);

    vpLight1->setFillColor(Qt::red);
    vpLight2->setFillColor(Qt::yellow);
    vpLight3->setFillColor(Qt::black);
    vpLight4->setFillColor(Qt::red);

    mpScene = new QGraphicsScene(0, 0, 700, 700);
    mpScene->setBackgroundBrush(Qt::black);
    mpScene->addItem(vpLight1);
    mpScene->addItem(vpLight2);
    mpScene->addItem(vpLight3);
    mpScene->addItem(vpLight4);
}
