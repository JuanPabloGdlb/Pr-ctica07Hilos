#include "hilo.h"

Hilo::Hilo(QObject *parent) : QThread(parent) {
    // Constructor de la clase, puedes inicializar variables aquí si es necesario.
}

void Hilo::run() {
    int position = 0;
    int position1 = 0;
    while (!isInterruptionRequested()) {
        // Realiza la lógica específica del hilo aquí.
        // Por ejemplo, puedes emitir una señal para actualizar la posición.
        emit updatePosition(position);
        emit updatePosition(position1);
        // Incrementa la posición y controla los límites si es necesario.
        position += 1;
        position1 += 1;
        // Establece un tiempo de espera para controlar la velocidad del hilo.
        msleep(10); // Controla la velocidad de movimiento (50 milisegundos en este caso).
    }
}
