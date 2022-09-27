#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include "clickgame.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief The MainWindow class - Главное окно отображения игры.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

    std::unique_ptr<ClickGame> m_game;

    int m_alpha_color = 0;
    QColor m_color_of_signal = QColor(255,150,100,m_alpha_color);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

public slots:
    /*!
     * \brief resiveRoundResult - слот приема результата прошедшего раунда
     * \param st - результат прошедшего раунда
     */
    void resiveRoundResult(ClickGame::RoundResultStatus st);

    /*!
     * \brief displayRequiredNumofClick - слот приема нового требуемого числа нажатий
     * \param numof_click - количество нажатий
     */
    void displayRequiredNumofClick(int numof_click);
};
#endif // MAINWINDOW_H
