#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vtkSmartPointer.h"

class vtkImageViewer2;
class vtkRenderer;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    vtkImageViewer2* imageView ;
    vtkSmartPointer<vtkRenderer> renderer;
};

#endif // MAINWINDOW_H
