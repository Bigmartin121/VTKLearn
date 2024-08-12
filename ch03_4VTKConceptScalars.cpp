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
#include <vtkDoubleArray.h> 
#include <vtkPolyData.h>
#include <vtkPointData.h>

int main(int argc, char* argv[])
{
    //创建点集数据，包含两个坐标点
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    points->InsertNextPoint(0.0, 0.0, 0.0);
    points->InsertNextPoint(1.0, 0.0, 0.0);

    //创建多边形数据
    vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
    polydata->SetPoints(points);

    //准备加入点数据的标量值，两个标量值分别为1、2
    vtkSmartPointer<vtkDoubleArray> weights = vtkSmartPointer<vtkDoubleArray>::New();
    weights->SetNumberOfValues(2);
    weights->SetValue(0, 5.0);
    weights->SetValue(1, 2.0);

    //先获取多边形数据中的点数据指针，然后设置该点数据的标量属性值
    vtkSmartPointer<vtkPointData>  PointData= polydata->GetPointData();
    PointData->SetScalars(weights);

    //输出多边形数据中的点数据标量属性值
    double weight = vtkDoubleArray::SafeDownCast(PointData->GetScalars())->GetValue(0);
    std::cout << "weight = " << weight << std::endl;

    return 0;
}
