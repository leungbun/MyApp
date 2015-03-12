#include "mainwindow.h"
#include <QtWidgets>
#include <QPixmap>
#include <QtGui/QKeySequence>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    openAction = new QAction(tr("&Open"), this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a file."));
    openAction->setIcon(QIcon(":/Open.jpg"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    msgLabel = new QLabel;
    msgLabel->setMinimumSize(msgLabel->sizeHint());
    msgLabel->setAlignment(Qt::AlignCenter);

    statusBar()->addWidget(msgLabel);
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));

    /*颜色测试模块
    QColor color = QColorDialog::getColor(Qt::white, this);
    QString msg = QString("r: %1, g: %2, b: %3").arg(QString::number(color.red()), QString::number(color.green()), QString::number(color.blue()));
    QMessageBox::information(NULL, "Selected color", msg);
    */

    QMenu *file = menuBar()->addMenu(tr("&file"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&file"));
    toolBar->addAction(openAction);
}

MainWindow::~MainWindow()
{

}


void MainWindow::open()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg *.png)"));
    if(path.length() == 0){
        //QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        QMessageBox message(QMessageBox::NoIcon, "Title", "Content with icon.");
        message.setIconPixmap(QPixmap("icon.png"));
        message.exec();
    }else{
        QMessageBox::information(NULL, tr("Path"), tr("You selected:")+path);
    }
}



















