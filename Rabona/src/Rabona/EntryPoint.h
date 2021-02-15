#pragma once

#ifdef RB_PLATFORM_WINDOWS

extern Rabona::Application* Rabona::CreateApplication();
int main(int argc, char** argv)
{
	Rabona::Log::init();
	RB_CORE_WARN("Initialized CoreLogger");
	int a = 5;
	RB_CLIENT_INFO("Hello Var={0}", a);
	auto app = Rabona::CreateApplication();
	app->Run();
	delete app;
}
#endif