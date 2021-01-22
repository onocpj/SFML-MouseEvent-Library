#include "MouseEvent.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

MouseEvent::MouseEvent(sf::RenderWindow& window)
	: m_WindowReference(UNDEF_PTR)
{
	Init(window);
}
MouseEvent::~MouseEvent() {}

void MouseEvent::Init(sf::RenderWindow& window) {

	m_WindowReference = &window;
	m_Cursor.Reference = new sf::Mouse();

	// Double click init
	m_DoubleClick.LapsedTime = 0.0f;
	m_DoubleClick.Active = false;
	// Click init
	m_Click.Active = false;

}
bool MouseEvent::IsButtonPressed(sf::Mouse::Button button) {

	return m_Cursor.Reference->isButtonPressed(button);

}
bool MouseEvent::IsButtonPressed(sf::Mouse::Button button, const sf::RectangleShape& obj) {

	// if cursor is hovering over button
	if (MouseEvent::Hover(obj)) {
		// if mouse button is pressed
		if (m_Cursor.Reference->isButtonPressed(button)) {
			return true; // click state return true
		}
	}

	return false; // click state return false

}
bool MouseEvent::IsButtonPressed(sf::Mouse::Button button, const sf::Sprite& obj) {

	// if cursor is hovering over button
	if (MouseEvent::Hover(obj)) {
		// if mouse button is pressed
		if (m_Cursor.Reference->isButtonPressed(button)) {
			return true; // click state return true
		}
	}

	return false; // click state return false

}
bool MouseEvent::Click(sf::Mouse::Button button) {

	return IsButtonPressed(button);

}
bool MouseEvent::Click(sf::Mouse::Button button, const sf::RectangleShape& obj) {

	// if cursor is hovering over object
	if (MouseEvent::Hover(obj)) {
		// if mouse button is pressed
		if (m_Cursor.Reference->isButtonPressed(static_cast<sf::Mouse::Button>(button))) {
			return true; // click state return true
		}
	}

	return false; // click state return false

}
bool MouseEvent::Click(sf::Mouse::Button button, const sf::Sprite& obj) {

	// if cursor is hovering over object
	if (MouseEvent::Hover(obj)) {
		// if mouse button is pressed
		if (m_Cursor.Reference->isButtonPressed(button)) {
			return true; // click state return true
		}
	}

	return false; // click state return false

}
bool MouseEvent::DoubleClick(sf::Mouse::Button button) {

	if (MouseEvent::Released(button)) {
		m_DoubleClick.Active = true;
	}

	if (m_DoubleClick.Active == true) {
		m_DoubleClick.LapsedTime += DELTA_TIME;

		if (m_DoubleClick.LapsedTime <= MOUSE_DOUBLE_CLICK_DELAY) {
			if (MouseEvent::IsButtonPressed(button)) {
				m_DoubleClick.LapsedTime = 0.0f;
				m_DoubleClick.Active = false;

				return true;
			}

		}
		else {
			m_DoubleClick.LapsedTime = 0.0f;
			m_DoubleClick.Active = false;
		}
	}

	return false;

}
bool MouseEvent::DoubleClick(sf::Mouse::Button button, const sf::RectangleShape& obj) {

	if (!MouseEvent::Hover(obj)) {
		m_DoubleClick.Active = false;
		m_DoubleClick.LapsedTime = 0.0f;
	}

	if (MouseEvent::Released(button, obj)) {
		m_DoubleClick.Active = true;
	}

	if (m_DoubleClick.Active == true) {
		m_DoubleClick.LapsedTime += DELTA_TIME;

		if (m_DoubleClick.LapsedTime <= MOUSE_DOUBLE_CLICK_DELAY) {
			if (MouseEvent::IsButtonPressed(button, obj)) {
				m_DoubleClick.LapsedTime = 0.0f;
				m_DoubleClick.Active = false;

				return true;
			}

		}
		else {
			m_DoubleClick.LapsedTime = 0.0f;
			m_DoubleClick.Active = false;
		}
	}

	return false;

}
bool MouseEvent::DoubleClick(sf::Mouse::Button button, const sf::Sprite& obj) {

	if (!Hover(obj)) {
		m_DoubleClick.Active = false;
		m_DoubleClick.LapsedTime = 0.0f;
	}

	if (MouseEvent::Released(button, obj)) {
		m_DoubleClick.Active = true;
	}

	if (m_DoubleClick.Active == true) {
		m_DoubleClick.LapsedTime += DELTA_TIME;

		if (m_DoubleClick.LapsedTime <= MOUSE_DOUBLE_CLICK_DELAY) {
			if (MouseEvent::IsButtonPressed(button, obj)) {
				m_DoubleClick.LapsedTime = 0.0f;
				m_DoubleClick.Active = false;

				return true;
			}

		}
		else {
			m_DoubleClick.LapsedTime = 0.0f;
			m_DoubleClick.Active = false;
		}
	}

	return false;

}
bool MouseEvent::DoubleClick(sf::Mouse::Button button, float clickDelay) {

	if (MouseEvent::Released(button)) {
		m_DoubleClick.Active = true;
	}

	if (m_DoubleClick.Active == true) {
		m_DoubleClick.LapsedTime += DELTA_TIME;

		if (m_DoubleClick.LapsedTime <= clickDelay) {
			if (MouseEvent::IsButtonPressed(button)) {
				m_DoubleClick.LapsedTime = 0.0f;
				m_DoubleClick.Active = false;

				return true;
			}

		}
		else {
			m_DoubleClick.LapsedTime = 0.0f;
			m_DoubleClick.Active = false;
		}
	}

	return false;

}
bool MouseEvent::DoubleClick(sf::Mouse::Button button, float clickDelay, const sf::RectangleShape& obj) {

	if (!MouseEvent::Hover(obj)) {
		m_DoubleClick.Active = false;
		m_DoubleClick.LapsedTime = 0.0f;
	}

	if (MouseEvent::Released(button, obj)) {
		m_DoubleClick.Active = true;
	}

	if (m_DoubleClick.Active == true) {
		m_DoubleClick.LapsedTime += DELTA_TIME;

		if (m_DoubleClick.LapsedTime <= clickDelay) {
			if (MouseEvent::IsButtonPressed(button, obj)) {
				m_DoubleClick.LapsedTime = 0.0f;
				m_DoubleClick.Active = false;

				return true;
			}

		}
		else {
			m_DoubleClick.LapsedTime = 0.0f;
			m_DoubleClick.Active = false;
		}
	}

	return false;

}
bool MouseEvent::DoubleClick(sf::Mouse::Button button, float clickDelay, const sf::Sprite& obj) {

	if (!MouseEvent::Hover(obj)) {
		m_DoubleClick.Active = false;
		m_DoubleClick.LapsedTime = 0.0f;
	}

	if (MouseEvent::Released(button, obj)) {
		m_DoubleClick.Active = true;
	}

	if (m_DoubleClick.Active == true) {
		m_DoubleClick.LapsedTime += DELTA_TIME;

		if (m_DoubleClick.LapsedTime <= clickDelay) {
			if (MouseEvent::IsButtonPressed(button, obj)) {
				m_DoubleClick.LapsedTime = 0.0f;
				m_DoubleClick.Active = false;

				return true;
			}

		}
		else {
			m_DoubleClick.LapsedTime = 0.0f;
			m_DoubleClick.Active = false;
		}
	}

	return false;

}
bool MouseEvent::Released(sf::Mouse::Button button) {

	if (MouseEvent::IsButtonPressed(button)) {
		if (m_Click.Active == false) {
			m_Click.Active = true;
		}
	}

	if (m_Click.Active == true) {
		if (!MouseEvent::IsButtonPressed(button)) {
			m_Click.Active = false;

			return true;
		}
	}

	return false;

}
bool MouseEvent::Released(sf::Mouse::Button button, const sf::RectangleShape& obj) {

	if (MouseEvent::IsButtonPressed(button, obj)) {
		if (m_Click.Active == false) {
			m_Click.Active = true;
		}
	}

	if (m_Click.Active == true) {
		if (!MouseEvent::IsButtonPressed(button, obj)) {
			m_Click.Active = false;

			return true;
		}
	}

	return false;

}
bool MouseEvent::Released(sf::Mouse::Button button, const sf::Sprite& obj) {

	if (MouseEvent::IsButtonPressed(button, obj)) {
		if (m_Click.Active == false) {
			m_Click.Active = true;
		}
	}

	if (m_Click.Active == true) {
		if (!MouseEvent::IsButtonPressed(button, obj)) {
			m_Click.Active = false;

			return true;
		}
	}

	return false;

}
bool MouseEvent::Hold(sf::Mouse::Button button) {

	if (MouseEvent::IsButtonPressed(button)) {
		return true;
	}

	return false;

}
bool MouseEvent::Hold(sf::Mouse::Button button, const sf::RectangleShape& obj) {

	if (MouseEvent::IsButtonPressed(button, obj)) {
		return true;
	}

	return false;

}
bool MouseEvent::Hold(sf::Mouse::Button button, const sf::Sprite& obj) {

	if (MouseEvent::IsButtonPressed(button, obj)) {
		return true;
	}

	return false;

}
bool MouseEvent::Hover(const sf::RectangleShape& obj) {

	sf::Vector2i t_MousePosition = m_Cursor.Reference->getPosition(*m_WindowReference);

	if (t_MousePosition.x >= obj.getPosition().x &&
		t_MousePosition.y >= obj.getPosition().y) {

		if (t_MousePosition.x <= obj.getPosition().x + obj.getSize().x &&
			t_MousePosition.y <= obj.getPosition().y + obj.getSize().y) {

			return true; // if mouse cursor is hovering interface instance return true
		}
	}

	return false; // if mouse cursor is not hovering interface instance return false

}
bool MouseEvent::Hover(const sf::Sprite& obj) {

	sf::Vector2i t_MousePosition = UNDEF_VECTOR2I;
	sf::Vector2f t_TranslatedPosition = UNDEF_VECTOR2F;
	sf::Vector2f t_SpriteSize = UNDEF_VECTOR2F;

	t_MousePosition = m_Cursor.Reference->getPosition(*m_WindowReference);	// Mouse position relative to the window
	t_TranslatedPosition = m_WindowReference->mapPixelToCoords(sf::Vector2i(
		t_MousePosition.x, t_MousePosition.y
	));																		// Mouse position translated into world coordinates
	t_SpriteSize = {
		obj.getTexture()->getSize().x * obj.getScale().x,
		obj.getTexture()->getSize().y * obj.getScale().y
	};

	if (t_TranslatedPosition.x >= obj.getPosition().x &&
		t_TranslatedPosition.y >= obj.getPosition().y) {

		if (t_TranslatedPosition.x <= obj.getPosition().x + t_SpriteSize.x &&
			t_TranslatedPosition.y <= obj.getPosition().y + t_SpriteSize.y) {

			return true;
		}
	}

	return false;

}
bool MouseEvent::Drag(sf::RectangleShape& obj) {
	// Optimize this function !!!

	m_Cursor.Position = m_Cursor.Reference->getPosition(*m_WindowReference);
	obj.setPosition(sf::Vector2f(
		m_Cursor.Position.x - obj.getSize().x / 2,
		m_Cursor.Position.y - obj.getSize().y / 2
	));

	return true;

}
bool MouseEvent::Drag(sf::Sprite& obj) {

	sf::Vector2f t_OldObjectPosition = UNDEF_VECTOR2F;
	sf::Vector2f t_NewObjectPosition = UNDEF_VECTOR2F;
	sf::Vector2i t_TranslatedPosition = UNDEF_VECTOR2I;
	sf::Vector2f t_SpriteSize = UNDEF_VECTOR2F;

	t_OldObjectPosition = obj.getPosition();
	t_TranslatedPosition = m_WindowReference->mapCoordsToPixel(
		sf::Vector2f(t_OldObjectPosition.x, t_OldObjectPosition.y)
	);
	t_SpriteSize = {
		obj.getTexture()->getSize().x * obj.getScale().x,
		obj.getTexture()->getSize().y * obj.getScale().y
	};

	m_Cursor.Position = m_Cursor.Reference->getPosition(*m_WindowReference);

	t_NewObjectPosition = m_WindowReference->mapPixelToCoords(sf::Vector2i(
		(int)((float)m_Cursor.Position.x - t_SpriteSize.x / 2),
		(int)((float)m_Cursor.Position.y - t_SpriteSize.y / 2)
	));

	obj.setPosition(t_NewObjectPosition);

	return true;

}
