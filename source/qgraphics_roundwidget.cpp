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
//==================================================================================================
//
#include <QPainter>
#include "qgraphics_roundwidget.hpp"

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      paint
//
//  Summary:
//      Draws the ellipse that displays seconds. The ellipse is drawn at the upper
//      right corner from the center of the bounding box.
//
//
//  Parameters:
//      painter -
//          [in, out] Pointer to painter instance
//      QStyleOptionGraphicsItem -
//          [in, out] Unused parameters Dictated by Q widget hierarchy
//      QWidget -
//          [in, out] Unused parameters Dictated by Q widget hierarchy
//
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


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      minimumSizeHint
//
//  Summary:
//      Returns the minimum size of the seconds lamp. Don’t want the lamp to be too small in
//      comparison to the other lamps which are rectangles.
//
//
//  Returns:
//      QSize instance
//
//
//--------------------------------------------------------------------------------------------------
//
QSize
QGraphicsRoundWidget::minimumSizeHint() const
{
    return QSize(40, 40);
}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      sizeHint
//
//  Summary:
//      Returns the recommended size for the seconds lamp.
//      This is the bounding box dimensions of the ellipse that is drawn.
//
//
//  Returns:
//      QSize instance
//
//
//--------------------------------------------------------------------------------------------------
//
QSize
QGraphicsRoundWidget::sizeHint() const
{
    return QSize(80, 80);
}
