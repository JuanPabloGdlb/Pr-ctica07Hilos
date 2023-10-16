#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "verticalthread.h"
#include "horizontalthread.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Crear una instancia del hilo VerticalThread
    hiloVertical = new VerticalThread(this);
    hiloHorizontal = new HorizontalThread(this);

    // Conectar las señales de los hilos a las ranuras de MainWindow
    connect(hiloVertical, &VerticalThread::updateVerticalPosition, this, &MainWindow::updateVerticalImagePosition);
    connect(hiloHorizontal, &HorizontalThread::updateHorizontalPosition, this, &MainWindow::updateHorizontalImagePosition);

    /* // Iniciar los hilos
    hiloVertical->start();
    hiloHorizontal->start();*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateVerticalImagePosition(int position) {
    // Obtener la QLabel que muestra la imagen vertical
    QLabel *verticalImageLabel = ui->label; // Asegúrate de que el nombre de la QLabel sea correcto

    // Calcular la nueva posición vertical de la imagen
    int newVerticalY = 255 - position; // La posición vertical inicial más el valor de 'position'

    // Actualizar la posición de la QLabel
    verticalImageLabel->move(110, newVerticalY);
}

void MainWindow::updateHorizontalImagePosition(int position1) {
    // Obtener la QLabel que muestra la imagen vertical
    QLabel *horizontalImageLabel = ui->label_2; // Asegúrate de que el nombre de la QLabel sea correcto

    // Calcular la nueva posición vertical de la imagen
    int newHorizontalX = 20 + position1; // La posición vertical inicial más el valor de 'position'

    // Actualizar la posición de la QLabel
    horizontalImageLabel->move(newHorizontalX, 590);
}

void MainWindow::on_pushButton_clicked()
{
    // Iniciar los hilos cuando se hace clic en el botón
    if (!hiloVertical->isRunning()) {
        hiloVertical->start();
    }
    if (!hiloHorizontal->isRunning()) {
        hiloHorizontal->start();
    }
}
