#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QButtonGroup>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitManageGroup();
}

MainWindow::~MainWindow()
{
    delete ui;
    killTimer(m_id_timer_update);
}

void MainWindow::InitManageGroup()
{
    ui->manage_lay->setAlignment(Qt::AlignHCenter);
    QButtonGroup* group = new QButtonGroup(this);
    group->addButton(ui->start);
    group->addButton(ui->stop);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

}

void MainWindow::resiveRoundResult(ClickGame::RoundResultStatus st)
{

}

void MainWindow::displayRequiredNumofClick(int numof_click)
{

}


void MainWindow::on_start_toggled(bool checked)
{

}

void MainWindow::on_stop_toggled(bool checked)
{

}
