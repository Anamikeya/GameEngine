#pragma once
#include "rbpch.h"
#include "Log.h"
#include "Rabona/core.h"
#include "Rabona/Events/Event.h"

namespace  Rabona {
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Rabona Engine",
			unsigned int width = 1200,
			unsigned int height = 720)
			:Title(title),Width(width), Height(height)
		{
		}
	};

	class RABONA_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window Attribute;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};
}