#include "horizontalthread.h"

HorizontalThread::HorizontalThread(QObject *parent) : QThread(parent) {
    // Constructor de la clase, puedes realizar inicializaciones aquí si es necesario.
}

void HorizontalThread::run() {
    int position1 = 0;
    while (!isInterruptionRequested()) {
        // Implementa la lógica específica del hilo aquí.
        // Por ejemplo, puedes emitir la señal para actualizar la posición horizontal.
        emit updateHorizontalPosition(position1);

        // Incrementa la posición y controla los límites si es necesario.
        position1 += 1;

        // Establece un tiempo de espera para controlar la velocidad del hilo.
        msleep(10); // Controla la velocidad de movimiento (50 milisegundos en este caso).
    }
}
