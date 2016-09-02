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

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      MainWindow()
//
//  Summary:
//      Canonical Constructor
//
//
//
//--------------------------------------------------------------------------------------------------
//
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mpScene(nullptr),
    mpExitAct(nullptr),
    mpSecondsLamp(nullptr)
{
    ui->setupUi(this);
    CreateActions();
    CreateMenus();
    CreateLamps();

    ui->GraphicsView->setScene(mpScene);
    ui->GraphicsView->setFrameStyle(0);
    ui->GraphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->GraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->GraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->GraphicsView->show();
}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      ~MainWindow()
//
//  Summary:
//      Destructor
//
//
//
//--------------------------------------------------------------------------------------------------
//
MainWindow::~MainWindow()
{
    //- This maybe temp as the scene may take ownership of these once their inserted
    //- delete lamp pointers

    for (auto& lamp : mFiveHourLamps)
    {
        delete lamp;
    }

    for (auto& lamp : mOneHourLamps)
    {
        delete lamp;
    }

    for (auto& lamp : mFiveMinuteLamps)
    {
        delete lamp;
    }

    for (auto& lamp : mOneMinuteLamps)
    {
        delete lamp;
    }

    delete mpSecondsLamp;

    //-
    delete ui;
}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      CreateActions()
//
//  Summary:
//      Creates the QActions that are invoked from the QMenu items within the min window.
//
//
//
//--------------------------------------------------------------------------------------------------
//
void
MainWindow::CreateActions()
{
    mpExitAct = new QAction(tr("E&xit"), this);
    mpExitAct->setShortcuts(QKeySequence::Quit);
    mpExitAct->setStatusTip(tr("Exit the application"));
    connect(mpExitAct, &QAction::triggered, this, &QWidget::close);

}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      CreateMenus()
//
//  Summary:
//      Does...
//
//
//--------------------------------------------------------------------------------------------------
//
void
MainWindow::CreateMenus()
{
    ui->menu_File->addAction(mpExitAct);
}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      CreateLamps()
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
//      Add layouts for QGraphicsRectWidgets
//
//  See Also:
//      {Optional...}
//--------------------------------------------------------------------------------------------------
//
void
MainWindow::CreateLamps()
{
    //- Seconds Lamp
    // Will need to create circle widget for this one
    mpSecondsLamp = new QGraphicsRectWidget;
    mpSecondsLamp->setFillColor(Qt::black);

    //- 5 hour lamps
    QGraphicsRectWidget *vpLight1 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight2 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight3 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight4 = new QGraphicsRectWidget;


    mFiveHourLamps = { vpLight1, vpLight2, vpLight3, vpLight4 };

    for (auto& lamp : mFiveHourLamps)
    {
        lamp->setFillColor(Qt::red);
    }

    //- 1 hour lamps
    QGraphicsRectWidget *vpLight5 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight6 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight7 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight8 = new QGraphicsRectWidget;

    mOneHourLamps = { vpLight5, vpLight6, vpLight7, vpLight8 };

    for (auto& lamp : mOneHourLamps)
    {
        lamp->setFillColor(Qt::red);
    }

    //- 5 minute lamps
    QGraphicsRectWidget *vpLight9 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight10 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight11= new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight12 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight13 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight14 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight15 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight16 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight17 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight18 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight19 = new QGraphicsRectWidget;

    mFiveMinuteLamps = { vpLight9, vpLight10, vpLight11, vpLight12, vpLight13, vpLight14, vpLight15,
                         vpLight16, vpLight17, vpLight18, vpLight19 };

    for (auto& lamp : mFiveMinuteLamps)
    {
        lamp->setFillColor(Qt::yellow);
    }

    //- 1 minute lamps
    QGraphicsRectWidget *vpLight20 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight21 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight22 = new QGraphicsRectWidget;
    QGraphicsRectWidget *vpLight23 = new QGraphicsRectWidget;

    mOneMinuteLamps = { vpLight20, vpLight21, vpLight22, vpLight23 };

    for (auto& lamp : mOneMinuteLamps)
    {
        lamp->setFillColor(Qt::red);
    }

}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      CreateSceneLayout()
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
//
//
//  See Also:
//      {Optional...}
//--------------------------------------------------------------------------------------------------
//
void
MainWindow::CreateSceneLayout()
{
    mpScene = new QGraphicsScene(0, 0, 700, 700);
    mpScene->setBackgroundBrush(Qt::black);
//    mpScene->addItem(vpLight1);
//    mpScene->addItem(vpLight2);
//    mpScene->addItem(vpLight3);
//    mpScene->addItem(vpLight4);
}
