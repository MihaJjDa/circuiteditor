#ifndef EDITORWIDGET_H
#define EDITORWIDGET_H

#include <QList>
#include <QPoint>
#include <QPixmap>
#include <QWidget>

#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMouseEvent>

class EditorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EditorWidget(int pieceSize, QWidget *parent = 0);
    void clear();

    int pieceSize() const;

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    int findPiece(const QRect &pieceRect) const;
    const QRect targetSquare(const QPoint &position) const;

    QList<QPixmap> piecePixmaps;
    QList<QRect> pieceRects;
    QList<QPoint> pieceLocations;
    QList<int> pieceType;
    QRect highlightedRect;

    int m_PieceSize;
};

#endif // EDITORWIDGET_H
