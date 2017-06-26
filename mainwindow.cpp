#include "mainwindow.h"
#include "pieceslist.h"
#include "editorwidget.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_EditorSize(6),
      m_PieceSize(100),
      m_offset(10)
{
    setupMenus();
    setupWidgets();
    setWindowTitle(tr("CircuitEditor"));
}

void MainWindow::openImage(const QString &path)
{
    QPixmap newImage;
    newImage.load(path);
    piecesList->addPiece(newImage);
}

void MainWindow::setupEditor()
{
    editorWidget->clear();
}

void MainWindow::setupMenus()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QMenu *gameMenu = menuBar()->addMenu(tr("&Editor"));

    QAction *exitAction = fileMenu->addAction(tr("E&xit"));
    exitAction->setShortcuts(QKeySequence::Quit);

    QAction *restartAction = gameMenu->addAction(tr("&Restart"));

    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(restartAction, SIGNAL(triggered()), this, SLOT(setupEditor()));
}

void MainWindow::setupWidgets()
{
    QFrame *frame = new QFrame;
    QHBoxLayout *frameLayout = new QHBoxLayout(frame);
    editorWidget = new EditorWidget(m_EditorSize, m_PieceSize+m_offset);

    piecesList = new PiecesList(this);

    frameLayout->addWidget(piecesList);
    frameLayout->addWidget(editorWidget);
    setCentralWidget(frame);
}
