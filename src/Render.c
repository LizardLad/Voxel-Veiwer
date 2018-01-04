#include "include/Project.h"

void RenderFunction(void)
{
	++FrameCount;
	
	glEnable(GL_MULTISAMPLE_ARB);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	Block_t tempBlock;
	
	glUseProgram(ShaderIds[0]);
	ExitOnGLError("ERROR: Could not use the shader program");

	glBindVertexArray(BufferIds[0]);
	ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");
	
	for(int z = -(z_max / 2); z < z_max - (z_max / 2); z++)
	{
		for(int y = -(y_max / 2); y < y_max - (y_max / 2); y++)
		{
			for(int x = -(x_max / 2); x < x_max - (x_max / 2); x++)
			{
				//tempBlock = get_matrix_entry(mv, x, y, z, x_max, y_max, z_max);
				//if(tempBlock.isActive == 1)
				//{
					DrawCube(x, y, z);
				//}
			}
		}
	}
	
	glBindVertexArray(0);
	glUseProgram(0);
	
	glutSwapBuffers();
}

void BindArraysAndShaders(void)
{
	//
	
}
