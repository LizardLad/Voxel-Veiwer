#ifndef PROJECT_H
#define PROJECT_H

// Includes for Project
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

// Constant and Macro Definitions
#define WINDOW_TITLE_PREFIX "Point Cloud Voxel Veiwer"

// Type and Struct Definitions
typedef struct Vertex
{
	float Position[4];
	float Color[4];
} Vertex;

typedef struct Matrix
{
	float m[16];
} Matrix;

typedef struct
{
	float x;
	float y;
	float z;
} Position3D_t;

typedef struct
{
	float x;
	float y;
	float z;
} Camera_t;

typedef struct
{
	bool isActive;
} Block_t;

// Global Variable Declarations
static const double PI = 3.14159265358979323846;
extern const Matrix IDENTITY_MATRIX;
Matrix ProjectionMatrix, ViewMatrix, ModelMatrix;
unsigned FrameCount;
GLuint ProjectionMatrixUniformLocation, ViewMatrixUniformLocation, ModelMatrixUniformLocation, BufferIds[3], ShaderIds[3];
int CurrentWidth, CurrentHeight, WindowHandle;
float CubeRotation;
clock_t LastTime;
Camera_t *Cameras;
Block_t *mv;
int x_max, y_max, z_max;

// ------------------------------
// Function Prototypes Start
// ------------------------------

// Trig Functions
float Cotangent(float angle);
float DegreesToRadians(float degrees);
float RadiansToDegrees(float radians);

// Matrix Functions
Matrix MultiplyMatrices(const Matrix* m1, const Matrix* m2);
void RotateAboutX(Matrix* m, float angle);
void RotateAboutY(Matrix* m, float angle);
void RotateAboutZ(Matrix* m, float angle);
void ScaleMatrix(Matrix* m, float x, float y, float z);
void TranslateMatrix(Matrix* m, float x, float y, float z);
Matrix CreateProjectionMatrix(float fovy, float aspect_ratio, float near_plane, float far_plane);

// GLUtils Functions
void ExitOnGLError(const char* error_message);
GLuint LoadShader(const char* filename, GLenum shader_type);

// Camera Functions
void CreateCameraArray(int NumberOfCameras);
Camera_t SetCamera(Position3D_t *StartingPositionOfCamera);
void SetCameraPosition(Camera_t *MainCamera, Position3D_t *NewPositionOfCamera);
Position3D_t GetCameraPosition(Camera_t *MainCamera);

// Init and Window Functions
void Initialize(int argc, char* argv[]);
void InitWindow(int argc, char* argv[]);
void ResizeFunction(int Width, int Height);

// Render Function
void RenderFunction(void);

// Cube Functions
void CreateCube();
void DestroyCube();
void DrawCube(float x, float y, float z);

// GLUT Functions
void TimerFunction(int Value);
void IdleFunction(void);
void OnWindowClose();

// Multi-Dimensional Voxel Array Functions
Block_t get_matrix_entry(Block_t *matrix, int x, int y, int z, int max_x, int max_y, int max_z);
void set_matrix_entry(Block_t *matrix, int x, int y, int z, Block_t val, int max_x, int max_y, int max_z);
void alloc_matrix_mem(Block_t **matrix, int max_x, int max_y, int max_z);
void cleanup();

// ------------------------------
// Function Prototypes End
// ------------------------------

#endif // PROJECT_H
