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

    std::unique_ptr<ClickGame> m_game; //!< указатель на объект игры

    std::array<QColor,2> m_color_of_number = {QColor(150,1,1), QColor(1,1,255)}; //!< возможные цвета для количества нажатий

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

    /*!
     * \brief InitManageGroup - инициализация области с кнпками управления
     * \details В методе задается центрирование положения кнопок и объединение кнопок в группу
     */
    void InitManageGroup();

    /*!
     * \brief InitGame - инициализация игры
     * \details В методе создается объект класса ClickGame,
     */
    void InitGame();

    /*!
     * \brief getLabelStyleSheet - создание стиля для лейбла с количеством нажатий
     * \param num_color - номер цвета
     * \return стиль для класса QLabel с нужным цветом
     */
    QString getLabelStyleSheet(int num_color);

    /// Методы обработки событий нажатий
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMoveEvent *event);

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

private slots:
    /*!
     * \brief on_start_toggled - метод для обработки нажатия на кнопку старт
     * \param checked - признак нажатия
     */
    void on_start_toggled(bool checked);

    /*!
     * \brief on_stop_toggled - метод для обработки нажатия на кнопку стоп
     * \param checked - признак нажатия
     */
    void on_stop_toggled(bool checked);
};
#endif // MAINWINDOW_H
