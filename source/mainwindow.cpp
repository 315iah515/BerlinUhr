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
#include "qgraphics_roundwidget.hpp"
#include "berlin_clock.hpp"

namespace {

    unsigned int sMargin = 30;
    unsigned int sViewHeight = 400;

}
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
    mpSecondsLamp(nullptr),
    mpContainerLayout(nullptr),
    mpSecondsLayout(nullptr),
    mpFiveHourLayout(nullptr),
    mpOneHourLayout(nullptr),
    mpFiveMinuteLayout(nullptr),
    mpOneMinuteLayout(nullptr),
    mpTopLevelLayout(nullptr),
    mpTimer(new QTimer(this))

{
    ui->setupUi(this);
    CreateActions();
    CreateMenus();
    CreateLamps();
    CreateSceneLayout();

    ui->GraphicsView->setScene(mpScene);
    ui->GraphicsView->setFrameStyle(0);
    ui->GraphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->GraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->GraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->GraphicsView->show();


    connect(mpTimer, &QTimer::timeout, this, &MainWindow::UpdateClock);
    mpTimer->start(500);
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
    delete mpTimer;
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
//      Instantiates all the lamps for the clock and places them into containers for later
//      manipulation.
//
//
//  Remarks:
//      deallocation of lamps takes place in deconstrcutor and may need to be removed if scene
//      takes ownership of pointers
//
//  See Also:
//      {Optional...}
//--------------------------------------------------------------------------------------------------
//
void
MainWindow::CreateLamps()
{
    //- Seconds Lamp
    mpSecondsLamp = new QGraphicsRoundWidget;
    mpSecondsLamp->setFillColor(Qt::yellow);

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

    mpSecondsLayout = new QGraphicsLinearLayout(Qt::Vertical);
    mpSecondsLayout->addItem(mpSecondsLamp);

    mpFiveHourLayout = new QGraphicsLinearLayout;
    for (auto const& lamp : mFiveHourLamps)
    {
        mpFiveHourLayout->addItem(lamp);
    }

    mpOneHourLayout = new QGraphicsLinearLayout;
    for (auto const& lamp : mOneHourLamps)
    {
        mpOneHourLayout->addItem(lamp);
    }

    mpFiveMinuteLayout = new QGraphicsLinearLayout;
    for (auto const& lamp : mFiveMinuteLamps)
    {
        mpFiveMinuteLayout->addItem(lamp);
    }

    mpOneMinuteLayout = new QGraphicsLinearLayout;
    for (auto const& lamp : mOneMinuteLamps)
    {
        mpOneMinuteLayout->addItem(lamp);
    }

    mpContainerLayout = new QGraphicsGridLayout;
    mpContainerLayout->addItem(mpFiveHourLayout, 0, 0);
    mpContainerLayout->addItem(mpOneHourLayout, 1, 0);
    mpContainerLayout->addItem(mpFiveMinuteLayout, 2, 0);
    mpContainerLayout->addItem(mpOneMinuteLayout, 3, 0);

    mpTopLevelLayout = new QGraphicsLinearLayout(Qt::Vertical);
    mpTopLevelLayout->addItem(mpSecondsLayout);
    mpTopLevelLayout->addItem(mpContainerLayout);
    mpTopLevelLayout->setSpacing(sMargin);
    mpTopLevelLayout->setContentsMargins(2, 40, 2, 2);


    QGraphicsWidget *vpWidget = new QGraphicsWidget;
    vpWidget->setLayout(mpTopLevelLayout);

    int width = qRound(vpWidget->preferredWidth());
    int height = sViewHeight + (2 * sMargin);
    setMinimumSize(width, height);

    mpScene = new QGraphicsScene(0, 0, 700, 700);
    mpScene->setSceneRect(0, 0, width, height);
    mpScene->setBackgroundBrush(QColor(192, 192, 192));
    mpScene->addItem(vpWidget);

}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      UpdateClock()
//
//  Summary:
//      Slot - Does...
//
//
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
MainWindow::UpdateClock()
{
    BerlinClock engine;
    BerlinClock::LampColors Colors = engine.RetrieveLampRow(LampRow::FIVE_HOUR_BLOCKS);

    for (int i = 0; i < mFiveHourLamps.size(); ++i)
    {
        mFiveHourLamps[i]->setFillColor(Colors[i].Color());
    }


    Colors = engine.RetrieveLampRow(LampRow::ONE_HOUR_BLOCKS);

    for (int i = 0; i < mOneHourLamps.size(); ++i)
    {
        mOneHourLamps[i]->setFillColor(Colors[i].Color());
    }

    Colors = engine.RetrieveLampRow(LampRow::FIVE_MINUTE_BLOCKS);

    for (int i = 0; i < mFiveMinuteLamps.size(); ++i)
    {
        mFiveMinuteLamps[i]->setFillColor(Colors[i].Color());
    }

    Colors = engine.RetrieveLampRow(LampRow::SINGLE_MINUTES);

    for (int i = 0; i < mOneMinuteLamps.size(); ++i)
    {
        mOneMinuteLamps[i]->setFillColor(Colors[i].Color());
    }

    Colors = engine.RetrieveLampRow(LampRow::SECONDS_BLOCK);
    mpSecondsLamp->setFillColor(Colors[0].Color());
}
