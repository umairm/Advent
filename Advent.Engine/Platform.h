#pragma once
struct GLFWwindow;

namespace Advent {
	class Engine;

	class Platform {
	public:
		Platform(Engine* engine, const char* applicationName);
		~Platform();

		const bool StartGameLoop();
		GLFWwindow* getWindow() { return _window; }
		
	private:
		Engine* _engine;
		GLFWwindow* _window;
	};
}