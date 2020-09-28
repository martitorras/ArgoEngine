#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	Sphere(0.5f).Render();

	/*Cube c(3, 1, 1);
	c.SetPos(5, 0, 0);
	c.wire = true;
	c.Render();

	Cylinder y(1, 3);
	y.SetPos(-5, 0, 0);
	y.wire = true;
	y.Render();*/

	return UPDATE_CONTINUE;
}

