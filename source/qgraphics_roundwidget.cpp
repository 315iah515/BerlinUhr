//==================================================================================================
//  File Name:
//      qgraphics_roundwidget.cpp
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
#include <QPainter>
#include "qgraphics_roundwidget.hpp"

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      paint
//
//  Summary:
//      Does...
//
//
//  Parameters:
//      FP1 -
//          [in, out] Abc...
//      FP2 -
//          [in, out] Xyz...
//
//  Returns:
//      {Optional...}
//
//
//  Remarks:
//      {Optional...}
//
//--------------------------------------------------------------------------------------------------
//
void
QGraphicsRoundWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    int diameter = 80;
    QBrush brush = painter->brush();
    painter->setBrush(mFillColor);
    int x = rect().center().x() - diameter/2;
    int y = rect().center().y() - diameter/2;
    painter->drawEllipse(QRect(x, y, diameter, diameter));
    painter->setBrush(brush);
}


QSize
QGraphicsRoundWidget::minimumSizeHint() const
{
    return QSize(40, 40);
}

QSize
QGraphicsRoundWidget::sizeHint() const
{
    return QSize(80, 80);
}
