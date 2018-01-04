#include "include/Project.h"

void Initialize(int argc, char* argv[])
{
	alloc_matrix_mem(&mv, x_max, y_max, z_max);
	Block_t defaultBlock = {1};
	
	for(int z = 0; z < z_max; z++)
	{
		for(int y = 0; y < y_max; y++)
		{
			for(int x = 0; x < x_max; x++)
			{
				set_matrix_entry(mv, x, y, z, defaultBlock, x_max, y_max, z_max);
			}
		}
	}
	
	CreateCameraArray(1);
	Position3D_t temp = {0, -60, 0};
	Cameras[0] = SetCamera(&temp);

	GLenum GlewInitResult;
	
	InitWindow(argc, argv);
	
	glewExperimental = GL_TRUE;
	GlewInitResult = glewInit();

	if (GLEW_OK != GlewInitResult)
	{
		printf("ERROR: %s\n", glewGetErrorString(GlewInitResult));
		exit(EXIT_FAILURE);
	}
	
	printf("INFO: OpenGL Version: %s\n", glGetString(GL_VERSION));

	glGetError();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	ExitOnGLError("ERROR: Could not set OpenGL depth testing options");

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	ExitOnGLError("ERROR: Could not set OpenGL culling options");

	ModelMatrix = IDENTITY_MATRIX;
	ProjectionMatrix = IDENTITY_MATRIX;
	ViewMatrix = IDENTITY_MATRIX;
	TranslateMatrix(&ViewMatrix, 0, 0, -2);

	CreateCube();
}
