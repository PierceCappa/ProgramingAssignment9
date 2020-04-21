//this is going to hold our main
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
	window.setVerticalSyncEnabled(true);

	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(100, 250, 50));


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}


		  ////////////
		 /// Draw ///
		////////////

		// clear first
		window.clear(sf::Color::Black);

		// draw calls
		window.draw(shape);
		
		// finally, show the frame
		window.display();
	}
	return 0;
}