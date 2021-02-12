#pragma once

#include <SFML/Window/Mouse.hpp>

#define UNDEF_PTR	nullptr
#define UNDEF_VECTOR2I	{ 0, 0 }				
#define UNDEF_VECTOR2F	{ 0.0f, 0.0f }				

#define DELTA_TIME 	1.0f

#define MOUSE_DOUBLE_CLICK 		2
#define MOUSE_DOUBLE_CLICK_DELAY 	0.2 // seconds


namespace sf {
	class RenderWindow;
	class RectangleShape;
	class Sprite;
}
class MouseEvent {
private:
	typedef struct {

		sf::Mouse*	Reference;
		sf::Vector2i	Position;

	} Cursor_t;
	typedef struct {

		float	LapsedTime;
		bool	Active;

	} MouseDoubleClick_t;
	typedef struct {

		bool	Active;

	} MouseClick_t;

public:
	MouseEvent(sf::RenderWindow& window);
	~MouseEvent();

	/// \brief Check if a mouse button is pressed
	///
	/// \param button - button to check
	///
	/// \return True if the button is pressed, false otherwise
	/// 
	bool IsButtonPressed(sf::Mouse::Button button);
	/// \brief Check if a mouse button press is applied for RectangleShape
	///
	/// \param button - button to check
	/// \param obj - relative to this RectangleShape
	///
	/// \return True if the button press is applied for RectangleShape, false otherwise
	/// 
	bool IsButtonPressed(sf::Mouse::Button button, const sf::RectangleShape& obj);
	/// \brief Check if a mouse button press is applied for Sprite
	///
	/// \param button - button to check
	/// \param obj - relative to this Sprite
	///
	/// \return True if the button press is applied for Sprite, false otherwise
	/// 
	bool IsButtonPressed(sf::Mouse::Button button, const sf::Sprite& obj);
	/// \brief Check if a mouse button is clicked
	///
	/// \param button - button to check
	///
	/// \return True if the button is pressed, false otherwise
	/// 
	bool Click(sf::Mouse::Button button);
	/// \brief Check if a mouse button click is applied for RectangleShape
	///
	/// \param button - button to check
	/// \param obj - relative to this RectangleSprite
	///
	/// \return True if the button click is applied for RectangleShape, false otherwise
	/// 
	bool Click(sf::Mouse::Button button, const sf::RectangleShape& obj);
	/// \brief Check if a mouse button click is applied for Sprite
	///
	/// \param button - button to check
	/// \param obj - relative to this Sprite
	///
	/// \return True if the button click is applied for Sprite, false otherwise
	/// 
	bool Click(sf::Mouse::Button button, const sf::Sprite& obj);
	/// \brief Check if a mouse button is doubble clicked
	///
	/// \param button - button to check
	///
	/// \return True if the button is doubble clicked, false otherwise
	/// 
	bool DoubleClick(sf::Mouse::Button button);
	/// \brief Check if a mouse button doubble click is applied for RectangleShape
	///
	/// \param button - button to check
	/// \param obj - relative to this RectangleShape
	///
	/// \return True if the button doubble click is applied for RectangleShape, false otherwise
	/// 
	bool DoubleClick(sf::Mouse::Button button, const sf::RectangleShape& obj);
	/// \brief Check if a mouse button doubble click is applied for Sprite
	///
	/// \param button - button to check
	/// \param obj - relative to this Sprite
	///
	/// \return True if the button doubble click is applied for Sprite, false otherwise
	/// 
	bool DoubleClick(sf::Mouse::Button button, const sf::Sprite& obj);
	/// \brief Check if a mouse button doubble click is performed in specific delay
	///
	/// \param button - button to check
	/// \param clickDelay - click delay
	///
	/// \return True if the button is doubble clicked in specific delay, false otherwise
	/// 
	bool DoubleClick(sf::Mouse::Button button, float clickDelay);
	/// \brief Check if a mouse button doubble click is performed in specific delay and is applied for RectangleShape
	///
	/// \param button - button to check
	/// \param clickDelay - click delay
	/// \param obj - relative to this RectangleShape
	///
	/// \return True if the button doubble click in specific delay is applied for RectangleShape, false otherwise
	/// 
	bool DoubleClick(sf::Mouse::Button button, float clickDelay, const sf::RectangleShape& obj);
	/// \brief Check if a mouse button doubble click is performed in specific delay and is applied for Sprite
	///
	/// \param button - button to check
	/// \param clickDelay - click delay
	/// \param obj - relative to this Sprite
	///
	/// \return True if the button doubble click in specific delay is applied for Sprite, false otherwise
	/// 
	bool DoubleClick(sf::Mouse::Button button, float clickDelay, const sf::Sprite& obj);
	/// \brief Check if a mouse button was released
	///
	/// \param button - button to check
	///
	/// \return True if the button was released, false otherwise
	/// 
	bool Released(sf::Mouse::Button button);
	/// \brief Check if a mouse button release is applied for RectangleShape
	///
	/// \param button - button to check
	/// \param obj - relative to this RectangleShape
	///
	/// \return True if the button release is applied fo RectangleShape, false otherwise
	/// 
	bool Released(sf::Mouse::Button button, const sf::RectangleShape& obj);
	/// \brief Check if a mouse button release is applied for Sprite
	///
	/// \param button - button to check
	/// \param obj - relative to this Sprite
	///
	/// \return True if the button release is applied fo Sprite, false otherwise
	/// 
	bool Released(sf::Mouse::Button button, const sf::Sprite& obj);
	/// \brief Check if a mouse button is holded
	///
	/// \param button - button to check
	///
	/// \return True if the button is holded, false otherwise
	/// 
	bool Hold(sf::Mouse::Button button);
	/// \brief Check if a mouse button hold is applied for RectangleShape
	///
	/// \param button - button to check
	/// \param obj - relative to this RectangleShape
	///
	/// \return True if the button hold is applied for RectangleShape, false otherwise
	/// 
	bool Hold(sf::Mouse::Button button, const sf::RectangleShape& obj);
	/// \brief Check if a mouse button hold is applied for Sprite
	///
	/// \param button - button to check
	/// \param obj - relative to this Sprite
	///
	/// \return True if the button hold is applied for Sprite, false otherwise
	/// 
	bool Hold(sf::Mouse::Button button, const sf::Sprite& obj);
	/// \brief Check if a mouse cursor is hovering over RectangleShape
	///
	/// \param obj - relative to this RectangleShape
	///
	/// \return True if the cursor is hovering RectangleShape, false otherwise
	/// 
	bool Hover(const sf::RectangleShape& obj);
	/// \brief Check if a mouse cursor is hovering over Sprite
	///
	/// \param obj - relative to this Sprite
	///
	/// \return True if the cursor is hovering Sprite, false otherwise
	/// 
	bool Hover(const sf::Sprite& obj);
	/// \brief Enables to drag RectangleShape with cursor. Also checks if RectangleShape is draged by cursor
	///
	/// \param obj - relative to this RectangleShape
	///
	/// \return True if cursor is draging RectangleShape, false otherwise
	/// 
	bool Drag(sf::RectangleShape& obj);
	/// \brief Enables to drag Sprite with cursor. Also checks if Sprite is draged by cursor
	///
	/// \param obj - relative to this Sprite
	///
	/// \return True if cursor is draging Sprite, false otherwise
	/// 
	bool Drag(sf::Sprite& obj);

private:
	void Init(sf::RenderWindow& window);

	sf::RenderWindow*	m_WindowReference;
	Cursor_t		m_Cursor;
	MouseDoubleClick_t	m_DoubleClick;
	MouseClick_t		m_Click;

};

