#pragma once

namespace Advent {

	class Platform;

	class Engine {
	public:
		Engine(const char* applicationName);
		~Engine();

		void Run();

		void OnLoop(const float deltaTime);
	private:
		Platform* _platform;
	};
}