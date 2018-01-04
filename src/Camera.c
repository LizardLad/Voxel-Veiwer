#include "include/Project.h"

void CreateCameraArray(int NumberOfCameras)
{
	Cameras = malloc(NumberOfCameras * sizeof(Camera_t));
}

Camera_t SetCamera(Position3D_t *StartingPositionOfCamera)
{
	Camera_t MainCamera = {StartingPositionOfCamera->x, StartingPositionOfCamera->z, StartingPositionOfCamera->y};
	return MainCamera;
}

void SetCameraPosition(Camera_t *MainCamera, Position3D_t *NewPositionOfCamera)
{
	// Set Global Camera Offset
	MainCamera->x = NewPositionOfCamera->x;
	MainCamera->z = NewPositionOfCamera->y;
	MainCamera->y = NewPositionOfCamera->z;
}

Position3D_t GetCameraPosition(Camera_t *MainCamera)
{
	//  Get Camera Position
	Position3D_t CurrentPosition = {MainCamera->x, MainCamera->z, -MainCamera->y};
	return CurrentPosition;
}
