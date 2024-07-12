//2-5
#include <vtkSmartPointer.h>
#include <vtkStructuredPointsReader.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkMarchingCubes.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>

int main(int argc, char* argv[])
{
    // 读取 Structured_Points 类型的 VTK 文件
    if (argc < 2)
	{
		std::cout<<argv[0]<<" "<<"VTK-File(*.vtk)"<<std::endl;
		return EXIT_FAILURE;
	}
    vtkSmartPointer<vtkStructuredPointsReader> reader = vtkSmartPointer<vtkStructuredPointsReader>::New();
    reader->SetFileName(argv[1]);
    reader->Update();  // 确保读取文件

    if (!reader->GetOutput())
    {
        std::cerr << "Failed to read the VTK file." << std::endl;
        return EXIT_FAILURE;
    }

    // 用移动立方体提取等值面
	vtkSmartPointer<vtkMarchingCubes> marchingCubes = 
		vtkSmartPointer<vtkMarchingCubes>::New();
	marchingCubes->SetInputConnection(reader->GetOutputPort());
	marchingCubes->SetValue(0,500);
    marchingCubes->Update();  // 确保生成等值面


    // 将生成的等值面进行 Mapper
	vtkSmartPointer<vtkPolyDataMapper> mapper = 
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(marchingCubes->GetOutputPort());


    // 将 Mapper 的输出当作渲染引擎的输入
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);
	renderer->SetBackground(1.0, 1.0, 1.0);

    // 创建渲染引擎
    vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();
    renWin->AddRenderer(renderer);
	renWin->SetSize( 640, 480 );
    renWin->Render();

    vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();

    // 设置渲染引擎
    interactor->SetRenderWindow(renWin);

    interactor->Initialize();
    interactor->Start();

    return 0;
}
