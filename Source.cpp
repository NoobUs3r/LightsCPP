#include<SFML/Graphics.hpp>
#include<stdint.h>
#include "Rectangle.h"
#include <time.h>  

using namespace std;

int main()
{
    int screenWidth = 800;
    int screenHeight = 600;
    const int numberOfRectangles = 100;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Lights");
    Rectangle* rectangles[numberOfRectangles]{};
    int arrayLngth = 0;

    srand(time(NULL));
    for (size_t i = 0; i < numberOfRectangles; i++)
    {
        Rectangle* r = new Rectangle();
        r->SetRandomCoordinates(screenWidth, screenHeight);
        r->SetRandomSize();
        rectangles[arrayLngth++] = r;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            // "resize" event: change screen width and height, set new coordinates per rectangle
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                screenWidth = window.getSize().x;
                screenHeight = window.getSize().y;

                for (size_t i = 0; i < numberOfRectangles; i++)
                {
                    Rectangle* r = rectangles[i];
                    r->SetRandomCoordinates(screenWidth, screenHeight);
                    r->SetRandomSize();
                }
            }
        }

        window.clear(sf::Color::Black);

        for (size_t i = 0; i < arrayLngth; i++)
        {
            Rectangle* rectangleObject = rectangles[i];
            float x = rectangleObject->GetX();
            float y = rectangleObject->GetY();
            int size = rectangleObject->GetSize();

            if (y >= screenHeight || y <= 0 || x >= screenWidth || x <= 0) {
                rectangleObject->SetRandomCoordinatesInCenter(screenWidth, screenHeight);
                rectangleObject->SetRandomSize();
            }

            sf::RectangleShape rectangle(sf::Vector2f(size, size));
            rectangle.setPosition(x, y);
            window.draw(rectangle);

            rectangleObject->MoveFromCenter(screenWidth, screenHeight);
        }

        window.display();
        sf::sleep(sf::seconds(0.005));
    }

    return 0;
}