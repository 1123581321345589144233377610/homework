#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QObject>
#include <QTimer>
#include <QElapsedTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    Stopwatch(QObject* parent = nullptr);
    ~Stopwatch();
    void startStop();
    void reset();
    void lap();
    QString getTime() const;
    QStringList getLaps() const;
    bool isRunning() const;
signals:
    void timeUpdated();
private:
    QTimer timer;
    QElapsedTimer elapsedTimer;
    qint64 totalPausedTime = 0;
    qint64 lastLapTime = 0;
    QStringList laps;
    bool running = false;
    void updateTime();
};

#endif // STOPWATCH_H
