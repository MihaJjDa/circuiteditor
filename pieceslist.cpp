#include "pieceslist.h"

#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>

PiecesList::PiecesList(QWidget *parent)
    : QListWidget(parent), m_IconSize(70)
{
    setDragEnabled(true);
    setViewMode(QListView::IconMode);
    setIconSize(QSize(int(m_IconSize), int(m_IconSize)));
    setSpacing(5);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
    m_WidgetWidthSize = (m_IconSize+23)*2;
    m_WidgetHeightSize = (m_IconSize+19)*8;
    setMinimumWidth(m_WidgetWidthSize);
    setMaximumWidth(m_WidgetWidthSize);
    setMinimumHeight(m_WidgetHeightSize);
    setMaximumHeight(m_WidgetHeightSize);
}

void PiecesList::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void PiecesList::dragMoveEvent(QDragMoveEvent *event)
{
    event->setDropAction(Qt::MoveAction);
    event->accept();
}

void PiecesList::dropEvent(QDropEvent *event)
{
    QByteArray pieceData = event->mimeData()->data("image");
    QDataStream dataStream(&pieceData, QIODevice::ReadOnly);
    QPixmap pixmap;
    QPoint location;
    dataStream >> pixmap >> location;
    event->setDropAction(Qt::MoveAction);
    event->accept();
}

void PiecesList::addPiece(QPixmap pixmap)
{
    QListWidgetItem *pieceItem = new QListWidgetItem(this);
    pieceItem->setIcon(QIcon(pixmap));
    pieceItem->setData(Qt::UserRole, QVariant(pixmap));
    pieceItem->setFlags(Qt::ItemIsEnabled |
                        Qt::ItemIsSelectable |
                        Qt::ItemIsDragEnabled);
}

void PiecesList::startDrag(Qt::DropActions)
{
    QListWidgetItem *item = currentItem();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    QPixmap pixmap = qvariant_cast<QPixmap>(item->data(Qt::UserRole));
    QPoint location = item->data(Qt::UserRole+1).toPoint();
    dataStream << pixmap << location;

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("image", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setHotSpot(QPoint(pixmap.width()/2, pixmap.height()/2));
    drag->setPixmap(pixmap);
    drag->exec(Qt::MoveAction);
}
