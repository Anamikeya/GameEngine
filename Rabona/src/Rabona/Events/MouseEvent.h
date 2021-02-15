#pragma once

#include "Event.h"
#include "rbpch.h"

namespace Rabona {
	
	class RABONA_API MouseMovedEvent : public Event
	{
		MouseMovedEvent(float x, float y)
			:m_MouseX(x), m_MouseY(y) 
		{

		}

		inline float GetX() { return m_MouseX;  }
		inline float GetY() { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ",  " << m_MouseY;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_TYPE(EventCategoryMouse | EventsCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class RABONA_API MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}
		
		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent  :" << GetXOffset() << ", " << GetYOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCatgoryInput)

	private:
		float m_XOffset, m_YOffset;
	};

	class RABONA_API MouseButtonEvent : public Event
	{
	public:

		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse |  EVentCategoryInput)
	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}
		int m_Button;

	};

	class RABONA_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)

		
	private:

	};

	class RABONA_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};


}