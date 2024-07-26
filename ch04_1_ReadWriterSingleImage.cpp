#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyDataMapper.h>
#include <vtkPoints.h>
#include <vtkPolyDataWriter.h>
#include <vtkImageViewer2.h>
#include <vtkImageData.h>
#include <vtkPNGReader.h>
#include <vtkJPEGWriter.h>

int main(int, char *[])
{
    vtkSmartPointer<vtkPNGReader> pngReader = vtkSmartPointer<vtkPNGReader>::New();
    pngReader->SetFileName("/data/VTK-logo.png");

    //显示读取的单幅PNG图像
    vtkSmartPointer<vtkImageViewer2> imageViewer  = vtkSmartPointer<vtkImageViewer2>::New();
    imageViewer->SetInputConnection(pngReader->GetOutputPort());

    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();

    imageViewer->SetupInteractor(renderWindowInteractor);
    imageViewer->Render();
    imageViewer->GetRenderer()->ResetCamera();
    imageViewer->Render();

    //save as jpg
    vtkSmartPointer<vtkJPEGWriter> writer = vtkSmartPointer<vtkJPEGWriter>::New();
    writer->SetFileName("VTK-logo.jpg");
    writer->SetInputConnection(pngReader->GetOutputPort());
    writer->Write();

    return 0;
}
