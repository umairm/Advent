#include "Logger.h"
#include "Engine.h"
#include "Platform.h"

namespace Advent {
	Engine::Engine(const char* applicationName) {
		Logger::Trace("Initializing Advent Engine...");
		_platform = new Platform(this, applicationName);
	}

	Engine::~Engine() {

	}

	void Engine::Run() {
		_platform->StartGameLoop();
	}

	void Engine::OnLoop(const float deltaTime) {

	}
}