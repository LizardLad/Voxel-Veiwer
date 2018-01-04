#include "include/Project.h"

void IdleFunction(void)
{
	glutPostRedisplay();
}

void TimerFunction(int Value)
{
	if (0 != Value) {
		char* TempString = (char*)malloc(512 + strlen(WINDOW_TITLE_PREFIX));
		sprintf(TempString, "%s: %d Frames Per Second @ %d x %d", WINDOW_TITLE_PREFIX, FrameCount * 4, CurrentWidth, CurrentHeight);
		glutSetWindowTitle(TempString);
		free(TempString);
	}

	FrameCount = 0;
	glutTimerFunc(250, TimerFunction, 1);
}

void OnWindowClose()
{
	DestroyCube();
	free(mv);
}
