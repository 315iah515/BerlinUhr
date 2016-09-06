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
    QBrush brush = painter->brush();
    painter->setBrush(mFillColor);
    painter->drawEllipse(rect());
    painter->setBrush(brush);
}
