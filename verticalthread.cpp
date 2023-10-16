#include "verticalthread.h"

VerticalThread::VerticalThread(QObject *parent) : QThread(parent) {
    // Constructor de la clase, puedes realizar inicializaciones aquí si es necesario.
}

void VerticalThread::run() {
    int position = 0;
    while (!isInterruptionRequested()) {
        // Realiza la lógica específica del hilo aquí.
        // Por ejemplo, puedes emitir la señal para actualizar la posición vertical.
        emit updateVerticalPosition(position);

        // Incrementa la posición y controla los límites si es necesario.
        position += 1;

        // Establece un tiempo de espera para controlar la velocidad del hilo.
        msleep(10); // Controla la velocidad de movimiento (50 milisegundos en este caso).
    }
}
