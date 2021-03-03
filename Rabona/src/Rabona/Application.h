#pragma once

#include"core.h"

#include "Events/Event.h"
#include "Rabona/Events/ApplicationEvent.h"

#include "Rabona/Log.h"
#include "Window.h"
namespace Rabona {
	class RABONA_API Application
	{
	public:
		//constructors
		Application();
		virtual ~Application();

		//public functions
	public:
		void Run();
		void OnEvent(Event& e);
	
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}

