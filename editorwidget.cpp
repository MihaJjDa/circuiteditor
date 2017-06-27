#include "editorwidget.h"

#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>

#include <QtDebug>

#include <iostream>
#include <cstdio>

EditorWidget::EditorWidget(int pieceSize, QWidget *parent)
    : QWidget(parent), m_PieceSize(pieceSize)
{
    setAcceptDrops(true);
    setMinimumSize(5*m_PieceSize, 5*m_PieceSize);
    setMaximumSize(10*m_PieceSize, 10*m_PieceSize);
}

void EditorWidget::clear()
{
    pieceLocations.clear();
    piecePixmaps.clear();
    pieceRects.clear();
    highlightedRect = QRect();
    update();
}

void EditorWidget::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void EditorWidget::dragLeaveEvent(QDragLeaveEvent *event)
{
    QRect updateRect = highlightedRect;
    highlightedRect = QRect();
    update(updateRect);
    event->accept();
}

void EditorWidget::dragMoveEvent(QDragMoveEvent *event)
{
    QRect updateRect = highlightedRect.united(targetSquare(event->pos()));

    highlightedRect = targetSquare(event->pos());
    event->setDropAction(Qt::MoveAction);
    event->accept();

    update(updateRect);
}

void EditorWidget::dropEvent(QDropEvent *event)
{
    QRect square = targetSquare(event->pos());
    int found = findPiece(square);

    if (found != -1)
    {
        pieceLocations.removeAt(found);
        piecePixmaps.removeAt(found);
        pieceRects.removeAt(found);
        pieceType.removeAt(found);
        update(square);
    }

    QByteArray pieceData = event->mimeData()->data("image");
    QDataStream dataStream(&pieceData, QIODevice::ReadOnly);
    QPixmap pixmap;
    QPoint location;
    int type;
    dataStream >> pixmap >> location >> type;

    pieceLocations.append(location);   
    piecePixmaps.append(pixmap);
    pieceRects.append(square);
    pieceType.append(type);

    qDebug() << "Insert" << type << "at" << square.x()/100 << square.y()/100;

    highlightedRect = QRect();
    update(square);

    event->setDropAction(Qt::MoveAction);
    event->accept();
}

int EditorWidget::findPiece(const QRect &pieceRect) const
{
    for (int i = 0; i < pieceRects.size(); ++i) {
        if (pieceRect == pieceRects[i])
            return i;
    }
    return -1;
}

void EditorWidget::mousePressEvent(QMouseEvent *event)
{
    QRect square = targetSquare(event->pos());
    int found = findPiece(square);

    if (found == -1)
        return;

    QPoint location = pieceLocations[found];
    QPixmap pixmap = piecePixmaps[found];
    int type = pieceType[found];
    pieceLocations.removeAt(found);
    piecePixmaps.removeAt(found);
    pieceRects.removeAt(found);
    pieceType.removeAt(found);

    qDebug() << "Delete" << type << "at" << square.x()/100 << square.y()/100;

    update(square);

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

    dataStream << pixmap << location << type;

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("image", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setHotSpot(event->pos() - square.topLeft());
    drag->setPixmap(pixmap);

    drag->exec(Qt::MoveAction);
    update(targetSquare(event->pos()));
}

void EditorWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.fillRect(event->rect(), Qt::white);

    painter.setBrush(QColor("#ffcccc"));
    painter.setPen(Qt::NoPen);
    painter.drawRect(highlightedRect.adjusted(0, 0, -1, -1));

    for (int i = 0; i < pieceRects.size(); ++i)
        painter.drawPixmap(pieceRects[i], piecePixmaps[i]);
    painter.end();
}

const QRect EditorWidget::targetSquare(const QPoint &position) const
{
    return QRect(position.x()/pieceSize() * pieceSize(),
                 position.y()/pieceSize() * pieceSize(),
                 pieceSize(),
                 pieceSize());
}

int EditorWidget::pieceSize() const
{
    return m_PieceSize;
}
