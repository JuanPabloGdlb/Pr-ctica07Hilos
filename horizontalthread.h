#ifndef HORIZONTALTHREAD_H
#define HORIZONTALTHREAD_H

#include <QThread>

class HorizontalThread : public QThread {
    Q_OBJECT

public:
    HorizontalThread(QObject *parent = nullptr);

signals:
    void updateHorizontalPosition(int position1);

protected:
    void run() override;
};

#endif // HORIZONTALTHREAD_H
