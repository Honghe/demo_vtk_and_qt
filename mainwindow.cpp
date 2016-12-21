#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)

#include "vtkImageViewer.h"
#include "vtkImageViewer2.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkPNGReader.h"
#include "QVTKWidget.h"
#include "vtkSmartPointer.h"
#include "vtkImageData.h"
#include "vtkSphereSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderer.h"
#include "vtkProperty.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    imageView = vtkImageViewer2::New();
   renderer = vtkSmartPointer<vtkRenderer>::New();

    vtkSmartPointer<vtkSphereSource> sphereSource =
        vtkSmartPointer<vtkSphereSource>::New();

    vtkSmartPointer<vtkPolyDataMapper> sphereMapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection( sphereSource->GetOutputPort() );

    vtkSmartPointer<vtkActor> sphereActor =
        vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper( sphereMapper );

    vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor( sphereActor );

     renderer->ResetCamera();
     renderer->DrawOn();

     ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
     ui->qvtkWidget->GetRenderWindow()->Render();
}

MainWindow::~MainWindow()
{
    delete ui;
}
