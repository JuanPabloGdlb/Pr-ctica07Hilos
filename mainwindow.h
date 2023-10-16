#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "verticalthread.h"
#include "horizontalthread.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void updateVerticalImagePosition(int position);
    void updateHorizontalImagePosition(int position1);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    VerticalThread *hiloVertical;
    HorizontalThread *hiloHorizontal;
};
#endif // MAINWINDOW_H
