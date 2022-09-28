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
        Win,    // признак соответсвия количества требуемых и сделаных кликов
        Failure // признак не соответсвия количества требуемых и сделаных кликов
    };

    explicit ClickGame(int period_of_round, int max_number_of_click, QObject *parent = nullptr);
    ~ClickGame();

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

    /*!
     * \brief getWinCount - метод получения количества выигранных раундов
     * \return количество выигранных раундов
     */
    int getWinCount();

    /*!
     * \brief getFailureCount - метод получения количества проигранных раундов
     * \return количество проигранных раундов
     */
    int getFailureCount();

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
    int m_timer_id = -1;                //!< id таймера игры
    int m_period_of_round = -1;         //!< длительность одного раунда
    int m_max_numof_click = -1;         //!< максимальное количество требуемых нажатий в раунде

    int m_current_numof_click = -1;     //!< текущее число нажатий
    int m_required_numof_click = -1;    //!< требуемое число нажатий

    int m_win_count = -1;               //!< количество выигранных раундов
    int m_failure_count = -1;           //!< количество програнных раундов

    /*!
     * \brief timerEvent - метод обработки события таймера
     * \details Происходит проверка текущего количества нажатий и подготовка данных для следующего раунда
     * \param event
     */
    void timerEvent(QTimerEvent *event);

    /*!
     * \brief setNewRequiredNumber - метод подготовки нового требуемого числа нажатий
     */
    void setNewRequiredNumber();
};

#endif // CLICKGAME_H
