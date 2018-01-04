#include "include/Project.h"

int main(int argc, char* argv[])
{
	WindowHandle = 0;
	FrameCount = 0;

	BufferIds[0] = 0;
	ShaderIds[0] = 0;
	BufferIds[1] = 0;
	ShaderIds[1] = 0;
	BufferIds[2] = 0;
	ShaderIds[2] = 0;
	
	CubeRotation = 0;
	LastTime = 0;
	CurrentWidth = 800;
	CurrentHeight = 600;
	x_max = 32;
	y_max = 32;
	z_max = 32;

	Initialize(argc, argv);

	glutMainLoop();
	
	return 0;
}




