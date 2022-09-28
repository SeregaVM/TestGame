#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QButtonGroup>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitManageGroup();
    InitGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitManageGroup()
{
    ui->manage_lay->setAlignment(Qt::AlignHCenter);
    QButtonGroup* group = new QButtonGroup(this);
    group->addButton(ui->start);
    group->addButton(ui->stop);
}

void MainWindow::InitGame()
{
    m_game.reset(new ClickGame(2000, 5));
    connect(m_game.get(), &ClickGame::newNumberOfClick, this, &MainWindow::displayRequiredNumofClick);
    connect(m_game.get(), &ClickGame::roundResult, this, &MainWindow::resiveRoundResult);
}

QString MainWindow::getLabelStyleSheet(int num_color)
{
    QColor& clr = m_color_of_number.at(num_color);
    return QString("QLabel {color : rgba(%1,%2,%3); }").arg(clr.red())
                                                       .arg(clr.green())
                                                       .arg(clr.blue());
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    m_game->addClick();
}

void MainWindow::mouseDoubleClickEvent(QMoveEvent *event)
{
    Q_UNUSED(event)
    m_game->addClick();
    m_game->addClick();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
     Q_UNUSED(event)
    m_game->stop();
    QMessageBox::information(this, "Пожелание", "Приходите еще!", "Обязательно приду!");
}

void MainWindow::resiveRoundResult(ClickGame::RoundResultStatus st)
{
    switch(st)
    {
    case ClickGame::Win:
        ui->win->setText(QString::number(m_game->getWinCount()));
        break;
    case ClickGame::Failure:
        ui->failure->setText(QString::number(m_game->getFailureCount()));
        break;
    default:
        break;
    }
}

void MainWindow::displayRequiredNumofClick(int numof_click)
{
    static int num_color = 0;
    ++num_color;
    num_color %= m_color_of_number.size();
    ui->numof_click->setStyleSheet(getLabelStyleSheet(num_color));
    ui->numof_click->setText(QString::number(numof_click));
}

void MainWindow::on_start_toggled(bool checked)
{
    if(checked)
    {
        m_game->start();
        ui->win->setText(QString::number(m_game->getWinCount()));
        ui->failure->setText(QString::number(m_game->getFailureCount()));
    }
}

void MainWindow::on_stop_toggled(bool checked)
{
    if(checked)
    {
        m_game->stop();
        ui->numof_click->setText("-");
    }
}
