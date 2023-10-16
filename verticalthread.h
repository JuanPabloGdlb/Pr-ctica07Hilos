#ifndef VERTICALTHREAD_H
#define VERTICALTHREAD_H

#include <QThread> // Incluye la cabecera de QThread

class VerticalThread : public QThread {
    Q_OBJECT // Habilita las características de señales y ranuras de Qt
public:
    VerticalThread(QObject *parent = nullptr);
signals:
    void updateVerticalPosition(int position);

protected:
    void run() override;
};

#endif // VERTICALTHREAD_H
