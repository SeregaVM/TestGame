#ifndef CLICKGAME_H
#define CLICKGAME_H

#include <QObject>

/*!
 * \brief The ClickGame class
 * \details Класс реализует основную логику игры.
 * Здесь определено поведение игры при старте, остановке, подсчете нажатий
 *  и генерации нового требуемого числа нажатий.
 */
class ClickGame : public QObject
{
    Q_OBJECT

public:
    enum RoundResultStatus
    {
        Win,    // признак соответсвия количества требуемых и количества сделаных кликов
        Failure // признак не соответсвия количества требуемых и количества сделаных кликов
    };

    explicit ClickGame(int period_of_round, int max_number_of_click, QObject *parent = nullptr);

    /*!
     * \brief start - метод для старта игры
     */
    void start();

    /*!
     * \brief stop - метод для остановки игры
     */
    void stop();

    /*!
     * \brief addClick - метод добавления одного нажатия
     */
    void addClick();

signals:
    /*!
     * \brief roundResult - Сигнал для передачи результата раунда игры
     * \param st - состояние прошедшего раунда игры
     */
    void roundResult(RoundResultStatus st);

    /*!
     * \brief newNumberOfClick - Сигнал для передачи нового требуемого чила нажатий
     * \param number_of_lick - количество требуемый нажатий
     */
    void newNumberOfClick(int number_of_lick);

private:
    int m_timer_id = -1;
    int m_period_of_round = -1;
    int m_max_numof_click = -1;

    int m_current_numof_click = -1;
    int m_required_numof_click = -1;

    void timerEvent(QTimerEvent *event);
};

#endif // CLICKGAME_H
