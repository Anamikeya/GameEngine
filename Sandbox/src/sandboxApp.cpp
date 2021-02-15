#include "Rabona.h"

class Sandbox : public Rabona::Application
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Rabona::Application* Rabona::CreateApplication() {

	return new Sandbox();
}