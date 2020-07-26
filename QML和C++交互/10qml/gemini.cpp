#include "gemini.h"

Gemini::Gemini(QObject *parent) : QObject(parent)
{
    m_ballColor = BALL_COLOR_YELLOW;
    m_ballNumber = 0;

    m_timer = new QTimer();
    //m_timer->start(1000);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimerout()));
}

void Gemini::onTimerout()
{
    qDebug()<<"onTimerout "<<__FUNCTION__;
    setBallNumber(m_ballNumber + 1);
}
