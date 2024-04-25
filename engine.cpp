#include "engine.h"

// Constructor and Destructor
Engine::Engine() {}
Engine::~Engine() {}
// member functions
int Engine::create() { return 0; }
int Engine::update()
{
	while (1) {}
	return 0;
}
int Engine::destroy() { return 0; }
int Engine::run()
{
	Engine::create();
	Engine::update();
	Engine::destroy();
	return 0;
}