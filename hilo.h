#ifndef HILO_H
#define HILO_H

#include <QThread>

class Hilo : public QThread {
    Q_OBJECT

public:
    Hilo(QObject *parent = nullptr);

signals:
    void updatePosition(int position);

protected:
    void run() override;
};

#endif // HILO_H
