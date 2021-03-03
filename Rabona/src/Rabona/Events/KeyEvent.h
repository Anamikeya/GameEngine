#pragma once
#include"Event.h"
#include"rbpch.h"

namespace Rabona {

	class RABONA_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}
		int m_KeyCode;
	
		
	};

	class RABONA_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_Repeat_Count(repeatCount) {}

		inline int GetRepeatCount() { return m_Repeat_Count; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " ( " << m_Repeat_Count << "repeats)";
			return ss.str();

		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		
		int m_Repeat_Count;

	};

	class RABONA_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}

