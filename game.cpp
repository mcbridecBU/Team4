// To compile this program, type "make game" into the terminal.

#include<iostream>
#include<chrono>
#include<ctime>
#include<SFML/Graphics.hpp>
#include<string>
#include<SFML/Window/Keyboard.hpp>
using std::cin;
using std::cout;
using std::string;
using std::to_string;

int main() {

  // These lines establish and name the window for the GUI
  int windowheight = 800;
  int windowwidth = 1000;
  sf::RenderWindow window(sf::VideoMode(windowwidth, windowheight),
                          "Guess What?!");

  // This block of items creates the elements used for the main page

  // Background Box
  sf::RectangleShape box(sf::Vector2f(900, 700));
  box.setFillColor(sf::Color::Red);
  box.setOutlineColor(sf::Color::White);
  box.setOutlineThickness(1);

  // Rectangles for the 5 categories
  int buttonwidth = 600;
  int buttonheight = 50;
  sf::RectangleShape cat_1_box(sf::Vector2f(buttonwidth, buttonheight));
  sf::RectangleShape cat_2_box(sf::Vector2f(buttonwidth, buttonheight));
  sf::RectangleShape cat_3_box(sf::Vector2f(buttonwidth, buttonheight));
  sf::RectangleShape cat_4_box(sf::Vector2f(buttonwidth, buttonheight));
  sf::RectangleShape cat_5_box(sf::Vector2f(buttonwidth, buttonheight));

  // Creates the different text elements for the main screen
  // Default colors: Red, Green, Blue, Yellow, Cyan, Magenta, Black, White
  // Custom colors can be made by specifying the R,G,B value (see line 45)
  //   (cusstom values range from 0-255)
  sf::Text toptext;
  sf::Text cat_one_text;
  sf::Text cat_two_text;
  sf::Text cat_three_text;
  sf::Text cat_four_text;
  sf::Text cat_five_text;
  cat_1_box.setFillColor(sf::Color(150, 0, 255));
  cat_1_box.setOutlineThickness(1);
  cat_1_box.setOutlineColor(sf::Color::White);
  cat_2_box.setFillColor(sf::Color::Cyan);
  cat_2_box.setOutlineThickness(1);
  cat_2_box.setOutlineColor(sf::Color::White);
  cat_3_box.setFillColor(sf::Color::Green);
  cat_3_box.setOutlineThickness(1);
  cat_3_box.setOutlineColor(sf::Color::White);
  cat_4_box.setFillColor(sf::Color::Yellow);
  cat_4_box.setOutlineThickness(1);
  cat_4_box.setOutlineColor(sf::Color::White);
  cat_5_box.setFillColor(sf::Color::Blue);
  cat_5_box.setOutlineThickness(1);
  cat_5_box.setOutlineColor(sf::Color::White);

  // Creates the fonts used for each of the text blocks (can be anything in the VM,
  // just browse and choose what you like)
  sf::Font topfont;
  sf::Font categoryfont;
  topfont.loadFromFile("/usr/share/fonts/truetype/ubuntu/UbuntuMono-B.ttf");
  categoryfont.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-Th.ttf");
  toptext.setFont(topfont);
  cat_one_text.setFont(categoryfont);
  cat_two_text.setFont(categoryfont);
  cat_three_text.setFont(categoryfont);
  cat_four_text.setFont(categoryfont);
  cat_five_text.setFont(categoryfont);

  // Not sure if this is needed or not...
  window.setFramerateLimit(10);

  // Set position of elements (x position, y position).
  // (indexed off the top left conrer)
  box.setPosition(50, 50);
  cat_1_box.setPosition(200, 100);
  cat_2_box.setPosition(200, 200);
  cat_3_box.setPosition(200, 300);
  cat_4_box.setPosition(200, 400);
  cat_5_box.setPosition(200, 500);
  toptext.setPosition(275, 0);
  cat_one_text.setPosition(420, 100);
  cat_two_text.setPosition(420, 200);
  cat_three_text.setPosition(420, 300);
  cat_four_text.setPosition(420, 400);
  cat_five_text.setPosition(420, 500);

  // Assign the text that will be displayed for each element.
  toptext.setString("Let's Play! Select A Category...");
  toptext.setFillColor(sf::Color::White);
  cat_one_text.setString("Category 1");
  cat_one_text.setFillColor(sf::Color::Black);
  cat_one_text.setOutlineThickness(0);
  cat_two_text.setString("Category 1");
  cat_two_text.setFillColor(sf::Color::Black);
  cat_two_text.setOutlineThickness(0);
  cat_three_text.setString("Category 3");
  cat_three_text.setFillColor(sf::Color::Black);
  cat_three_text.setOutlineThickness(0);
  cat_four_text.setString("Category 4");
  cat_four_text.setFillColor(sf::Color::Black);
  cat_four_text.setOutlineThickness(0);
  cat_five_text.setString("Category 5");
  cat_five_text.setFillColor(sf::Color::Black);
  cat_five_text.setOutlineThickness(0);

  // Opens the GUI and keeps it open until it is closed
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // Print all the elements that have been created for the main page.
    // Note, these are printed in order. If you want something to be in the
    //   background it needs to be printed first/early. If you want something
    //     to be in the foregroud, it needs to be printed last/later.
    window.clear();
    window.draw(box);
    window.draw(toptext);
    window.draw(cat_1_box);
    window.draw(cat_2_box);
    window.draw(cat_3_box);
    window.draw(cat_4_box);
    window.draw(cat_one_text);
    window.draw(cat_two_text);
    window.draw(cat_three_text);
    window.draw(cat_four_text);

    // Displays the window created from the actions above
    window.display();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {


      while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)
            window.close();
        }
        window.clear();
        window.draw(box);
        window.draw(cat_5_box);
        window.draw(cat_five_text);
        window.display();
      }
    }
  }

  return 0;
}


// What's next?

// 1) There will need to be a page for each category.
// 1a) Each category will need a place for hints to appear and images of all
//     the items in that category
// 2) There will need to be a way of detecting the click of a mouse on each of
//  the boxes for each category. On the main page, it will take you to the
//   category you click on (no action if no category is clicked). Within a
//    category, it will register as the player's guess on an image (no action
//     if no image is clicked)