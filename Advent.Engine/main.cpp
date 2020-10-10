#include "Engine.h"

int main(int argc, const char** argv) {
	Advent::Engine* engine = new Advent::Engine("Advent");
	engine->Run();
	delete engine;
	return 0;
}