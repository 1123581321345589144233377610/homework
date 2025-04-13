#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject{parent}
{
    timer.setInterval(100);
    connect(&timer, &QTimer::timeout, this, &Stopwatch::updateTime);
}

Stopwatch::~Stopwatch() {}

void Stopwatch::startStop()
{
    if(!running){
        elapsedTimer.start();
        running = true;
        timer.start();
    }else{
        totalPausedTime += elapsedTimer.elapsed();
        running = false;
        timer.stop();
    }
}

void Stopwatch::reset()
{
    timer.stop();
    totalPausedTime = 0;
    lastLapTime = 0;
    laps.clear();
    running = false;
    emit timeUpdated();
}

void Stopwatch::lap()
{
    if (running) {
        qint64 currentTime = elapsedTimer.elapsed() + totalPausedTime;
        qint64 lapTime = currentTime - lastLapTime;
        lastLapTime = currentTime;
        laps.append(QString("LAP %1     TIME: %2 SEC.")
                        .arg(laps.size() + 1)
                        .arg(lapTime / 1000.0));
        emit timeUpdated();
    }
}

QString Stopwatch::getTime() const
{
    qint64 currentTime = running ? (elapsedTimer.elapsed() + totalPausedTime) : totalPausedTime;
    return QString::number(currentTime / 1000.0) + " SEC.";
}

QStringList Stopwatch::getLaps() const
{
    return laps;
}

bool Stopwatch::isRunning() const
{
    return running;
}

void Stopwatch::updateTime()
{
    emit timeUpdated();
}
