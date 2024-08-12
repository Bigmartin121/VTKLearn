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
    double X[3] = { 1.0, 0.0, 0.0 };
    double Y[3] = { 0.0, 0.0, 1.0 };
    double Z[3] = { 0.0, 0.0, 0.0 };

    //创建点数据以及在每个点坐标上加入顶点类型的单元
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    vtkSmartPointer<vtkCellArray> vertices = vtkSmartPointer<vtkCellArray>::New();

    for(unsigned int i = 0; i < 3; i++)
    {
        //定义用于存储点索引的中间变量，vtkIDType就相当于int,long等类型
        vtkIdType pid[1];
        //把每个点坐标都加如vtkpoints中，InsertNetPoint()函数返回的是点的索引
        pid[0] = points->InsertNextPoint(X[i], Y[i], Z[i]);

        //在每个坐标点上分别创建一个顶点，顶点是单元里的一种类型
        vertices->InsertNextCell(1, pid);
    }

    //创建vtkPolyData对象，并添加点数据和顶点数据
    vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
    polydata->SetPoints(points);
    polydata->SetVerts(vertices);

    //将vtkPolyData对象写入文件
    vtkSmartPointer<vtkPolyDataWriter> writer = vtkSmartPointer<vtkPolyDataWriter>::New();
    writer->SetFileName("triangleVerts.vtk");
    writer->SetInputData(polydata);
    writer->Write();


    return 0;
}
