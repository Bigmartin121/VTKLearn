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
    //�����㼯���ݣ��������������
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    points->InsertNextPoint(0.0, 0.0, 0.0);
    points->InsertNextPoint(1.0, 0.0, 0.0);

    //�������������
    vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
    polydata->SetPoints(points);

    //׼����������ݵı���ֵ����������ֵ�ֱ�Ϊ1��2
    vtkSmartPointer<vtkDoubleArray> weights = vtkSmartPointer<vtkDoubleArray>::New();
    weights->SetNumberOfValues(2);
    weights->SetValue(0, 5.0);
    weights->SetValue(1, 2.0);

    //�Ȼ�ȡ����������еĵ�����ָ�룬Ȼ�����øõ����ݵı�������ֵ
    vtkSmartPointer<vtkPointData>  PointData= polydata->GetPointData();
    PointData->SetScalars(weights);

    //�������������еĵ����ݱ�������ֵ
    double weight = vtkDoubleArray::SafeDownCast(PointData->GetScalars())->GetValue(0);
    std::cout << "weight = " << weight << std::endl;

    return 0;
}
