//==================================================================================================
//  File Name:
//      qgraphics_rectwidget.cpp
//
//  Product:
//      BerlinUhr
//
//  Authors:
//      Ian Heaton
//
//
//==================================================================================================
//
#include <QPainter>
#include "qgraphics_rectwidget.hpp"


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      paint()
//
//  Summary:
//      Draws a rectangle with a fill color
//
//
//  Parameters:
//      painter -
//          [in, out] mutable painter instance that draws the shape to the widget
//      QStyleOptionGraphicsItem -
//          [in, out] Not used
//      QWidget -
//          [in, out] Not used
//
//
//--------------------------------------------------------------------------------------------------
//
void
QGraphicsRectWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QBrush brush = painter->brush();
    painter->setBrush(mFillColor);
    painter->drawRect(rect());
    painter->setBrush(brush);
}
