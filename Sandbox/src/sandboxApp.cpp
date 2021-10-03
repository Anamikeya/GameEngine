#include "Rabona.h"

class ExampleLayer : public Rabona::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}
	void OnUpdate() override
	{
		RB_CLIENT_INFO("ExampleLayer::Update");
	}
	void OnEvent(Rabona::Event& event) override
	{
		RB_CLIENT_TRACE("{0}", event);
	}
};
class Sandbox : public Rabona::Application
{
public:
	
	Sandbox() 
	{
		PushLayer(new ExampleLayer());

	}

	~Sandbox() {

	}
};

Rabona::Application* Rabona::CreateApplication() {

	return new Sandbox();
}