#pragma once

#include"core.h"
#include "Window.h"
#include "Rabona/LayerStack.h"
#include "Events/Event.h"
#include "Rabona/Events/ApplicationEvent.h"

#include "Rabona/Log.h"
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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}

