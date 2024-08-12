//2-5
#include <vtkSmartPointer.h>
#include <vtkStructuredPointsReader.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkMarchingCubes.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkPoints.h>
#include <vtkPolyDataWriter.h>

int main(int argc, char* argv[])
{
    //创建点数据
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    points->InsertNextPoint(1.0, 0.0, 0.0);
    points->InsertNextPoint(0.0, 0.0, 0.0);
    points->InsertNextPoint(0.0, 1.0, 0.0);

    //创建vtkPolyData类型数据,vtkPolyData派生自vtkPointSet
    //vtkPointSet派生自vtkDataSet，所以vtkPolyData是一种数据集
    vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
    //将创建的点加入到vtkpolyData中
    polydata->SetPoints(points);
    //将vtkPolyData类型数据写入到一个VTK文件中
    vtkSmartPointer<vtkPolyDataWriter> wirter = vtkSmartPointer<vtkPolyDataWriter>::New();
    wirter->SetFileName("triangle.vtk");
    wirter->SetInputData(polydata);
    wirter->Write();

    return 0;
}
