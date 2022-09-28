#include "clickgame.h"

void ClickGame::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
    if(m_current_numof_click == m_required_numof_click)
    {
        ++m_win_count;
        emit roundResult(Win);
    }
    else
    {
        ++m_failure_count;
        emit roundResult(Failure);
    }
    m_current_numof_click = 0;
    setNewRequiredNumber();
}

void ClickGame::setNewRequiredNumber()
{
    m_required_numof_click = qrand()%(m_max_numof_click+1);
    emit newNumberOfClick(m_required_numof_click);
}

ClickGame::ClickGame(int period_of_round, int max_number_of_click, QObject *parent) :
    QObject(parent)
  , m_period_of_round(period_of_round)
  , m_max_numof_click(max_number_of_click)
{

}

ClickGame::~ClickGame()
{
    if(m_timer_id != -1)
        killTimer(m_timer_id);
}

void ClickGame::start()
{
    if(m_timer_id == -1)
        m_timer_id = startTimer(m_period_of_round);
    m_win_count = 0;
    m_failure_count = 0;
    m_current_numof_click = 0;
    setNewRequiredNumber();
}

void ClickGame::stop()
{
    if(m_timer_id != -1)
        killTimer(m_timer_id);
    m_timer_id = -1;
}

void ClickGame::addClick()
{
    ++m_current_numof_click;
}

int ClickGame::getWinCount()
{
    return m_win_count;
}

int ClickGame::getFailureCount()
{
    return m_failure_count;
}
