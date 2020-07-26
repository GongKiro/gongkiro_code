#ifndef GEMINI_H
#define GEMINI_H

#include <QObject>
#include "QDebug"
#include "QTimer"

class Gemini : public QObject
{
    Q_OBJECT
    Q_ENUMS(BALL_COLOR)
    Q_PROPERTY(unsigned int ballNumber READ ballNumber WRITE setBallNumber NOTIFY ballNumberChanged)
public:
    explicit Gemini(QObject *parent = nullptr);

    Q_INVOKABLE void stop() {
        qDebug() << "Gemini::stop() called";
    }
    unsigned int ballNumber() const {
        qDebug() << __FUNCTION__;
        return m_ballNumber;
    }
    void setBallNumber(const unsigned int &ballNumber) {
        qDebug() << __FUNCTION__;
        if(ballNumber != m_ballNumber) {
            m_ballNumber = ballNumber;
            emit ballNumberChanged();
        }
    }

    enum BALL_COLOR {
        BALL_COLOR_YELLOW,
        BALL_COLOR_RED,
        BALL_COLOR_BLUE,
        BALL_COLOR_ALL
    };
signals:
    void begin();
    void ballNumberChanged();
public slots:
    void doSomething(BALL_COLOR ballColor){
        qDebug()<< "gemini::doSomething";
        if(ballColor != m_ballColor) {
            m_ballColor = ballColor;
            qDebug() << "ball color changed";
        }
    }
    void onTimerout();

private:
    BALL_COLOR m_ballColor;
    unsigned int m_ballNumber;
    QTimer* m_timer;
};

#endif // GEMINI_H
