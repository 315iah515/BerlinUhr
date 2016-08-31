//==================================================================================================
//  File Name:
//      qgraphics_rectwidget.hpp
//
//  Product:
//      BerlinUhr
//
//  Interface Header:
//
//
//  Authors:
//      Ian Heaton
//
//  Copyright Notice:
//
//==================================================================================================
//
#ifndef QGRAPGICS_RECTWIDGET_HPP_DEFINED
#define QGRAPGICS_RECTWIDGET_HPP_DEFINED

#include <QGraphicsWidget>
//--------------------------------------------------------------------------------------------------
//  Class:
//      CLASS_NAME
//
//  Summary:
//      Does ...
//
//  C++ Syntax:
//      <code><![CDATA[
//      {Optional...}
//      ]]></code>
//
//  Remarks:
//      {Optional...}
//
//  See Also:
//      {Optional...}
//--------------------------------------------------------------------------------------------------
//
class QGraphicsRectWidget : public QGraphicsWidget
{

  public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) Q_DECL_OVERRIDE;

};

#endif //- QGRAPGICS_RECTWIDGET_HPP_DEFINED
