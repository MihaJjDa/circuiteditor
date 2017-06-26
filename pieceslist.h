#ifndef PIECESLIST_H
#define PIECESLIST_H

#include <QListWidget>

class PiecesList : public QListWidget
{
    Q_OBJECT

public:
    explicit PiecesList(QWidget *parent = 0);
    void addPiece(QPixmap pixmap);
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void startDrag(Qt::DropActions supportedActions);

    int m_IconSize;
    int m_WidgetWidthSize;
    int m_WidgetHeightSize;
};


#endif // PIECESLIST_H
