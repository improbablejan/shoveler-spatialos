#include <stdlib.h> // EXIT_FAILURE, EXIT_SUCCESS
#include <stdbool.h> // bool
#include <stdio.h> // stdout

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <shoveler/game.h>
#include <shoveler/global.h>
#include <shoveler/log.h>

#include "sample.h"

int main(int argc, char *argv[])
{
	const char *windowTitle = "shoveler";
	bool fullscreen = false;
	bool vsync = true;
	int samples = 4;
	int width = 640;
	int height = 480;

	shovelerLogInit("shoveler/", SHOVELER_LOG_LEVEL_INFO_UP, stdout);
	shovelerGlobalInit();

	ShovelerGame *game = shovelerGameCreate(windowTitle, width, height, samples, fullscreen, vsync);
	if(game == NULL) {
		return EXIT_FAILURE;
	}

	shovelerSampleInit(game, width, height, samples);

	while(shovelerGameIsRunning(game)) {
		shovelerGameRenderFrame(game);
	}
	shovelerLogInfo("Exiting main loop, goodbye.");

	shovelerSampleTerminate();
	shovelerGameFree(game);
	shovelerGlobalUninit();
	shovelerLogTerminate();

	return EXIT_SUCCESS;
}
