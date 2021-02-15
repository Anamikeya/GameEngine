#pragma once
#include "Rabona/core.h"
#include "rbpch.h"

namespace Rabona
{
	//Events in Hazel are Currently blocking ie. whenever teh evente take place it stops all other events and starts thet event poll
	//Like if the Mouse Button is clicked it stops all teh processes and starts that perticular operation of mouseClicked function
	// meaning When an Event Occours it
	//immediately gets dispatched and must be dealt with right then and there
	//For the future, we will have a buffer eventsd in an event
	//bus and process them during te event part of the update stage


	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, Keyreleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled

	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4),

		//we have it as a bit field because we are just doing thins that might need 2 
		//categories or traits like categoryKeyboard and categoryInput is same
	};

#define EVENT_CLASS_TYPE(type)  EventType GetStaticType() const {return EventType::##type;}\
								virtual EventType GetEventType() const override { return GetStaticType();  }\
								virtual const char* GetName() const override{ return #type;  }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class RABONA_API Event
	{
		//its base class for boolean
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags()  const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category; 

		}

	protected:
		bool m_Handeled = false;   //this is to handel the event like when you clicked but removed the miouse from that place wir=thout releasing that 
									//event shouldnt take palce


	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)

		{

		}
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;

	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}


}