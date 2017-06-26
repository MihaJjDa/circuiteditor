#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPixmap>
#include <QMainWindow>
#include <QListWidgetItem>


class PiecesList;
class EditorWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void openImage(const QString &path = QString());

public slots:
    void setupEditor();

private:
    void setupMenus();
    void setupWidgets();

    PiecesList *piecesList;
    EditorWidget *editorWidget;
    int m_EditorSize;
    int m_PieceSize;
};

#endif // MAINWINDOW_H
