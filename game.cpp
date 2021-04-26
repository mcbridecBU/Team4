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
  int buttonheight = 100;
  int guessbox_width = 300;
  int guessbox_height = 50;
  sf::RectangleShape cat_1_box(sf::Vector2f(buttonwidth, buttonheight));
  sf::RectangleShape cat_2_box(sf::Vector2f(buttonwidth, buttonheight));
  sf::RectangleShape cat_3_box(sf::Vector2f(buttonwidth, buttonheight));
  sf::RectangleShape cat_4_box(sf::Vector2f(buttonwidth, buttonheight));
  sf::RectangleShape guess_box_1(sf::Vector2f(guessbox_width, guessbox_height));
  sf::RectangleShape guess_box_2(sf::Vector2f(guessbox_width, guessbox_height));
  sf::RectangleShape guess_box_3(sf::Vector2f(guessbox_width, guessbox_height));
  sf::RectangleShape guess_box_4(sf::Vector2f(guessbox_width, guessbox_height));
  sf::RectangleShape guess_box_5(sf::Vector2f(guessbox_width, guessbox_height));
  sf::RectangleShape guess_box_6(sf::Vector2f(guessbox_width, guessbox_height));
  sf::RectangleShape guess_box_7(sf::Vector2f(guessbox_width, guessbox_height));
  sf::RectangleShape guess_box_8(sf::Vector2f(guessbox_width, guessbox_height));
  sf::RectangleShape guess_box_9(sf::Vector2f(guessbox_width, guessbox_height));
  sf::RectangleShape hint_box(sf::Vector2f(buttonwidth, 75));


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
  sf::Text score_text;
  sf::Text score_num;
  sf::Text guess_text_1;
  sf::Text guess_text_2;
  sf::Text guess_text_3;
  sf::Text guess_text_4;
  sf::Text guess_text_5;
  sf::Text guess_text_6;
  sf::Text guess_text_7;
  sf::Text guess_text_8;
  sf::Text guess_text_9;
  cat_1_box.setFillColor(sf::Color(200, 30, 100));
  cat_1_box.setOutlineThickness(1);
  cat_1_box.setOutlineColor(sf::Color::White);
  cat_2_box.setFillColor(sf::Color(200, 30, 100));
  cat_2_box.setOutlineThickness(1);
  cat_2_box.setOutlineColor(sf::Color::White);
  cat_3_box.setFillColor(sf::Color(200, 30, 100));
  cat_3_box.setOutlineThickness(1);
  cat_3_box.setOutlineColor(sf::Color::White);
  cat_4_box.setFillColor(sf::Color(200, 30, 100));
  cat_4_box.setOutlineThickness(1);
  cat_4_box.setOutlineColor(sf::Color::White);
  hint_box.setFillColor(sf::Color(128,128,128));
  hint_box.setOutlineThickness(1);
  hint_box.setOutlineColor(sf::Color::White);
  guess_box_1.setFillColor(sf::Color::Blue);
  guess_box_1.setOutlineThickness(1);
  guess_box_1.setOutlineColor(sf::Color::White);
  guess_box_2.setFillColor(sf::Color::Blue);
  guess_box_2.setOutlineThickness(1);
  guess_box_2.setOutlineColor(sf::Color::White);
  guess_box_3.setFillColor(sf::Color::Blue);
  guess_box_3.setOutlineThickness(1);
  guess_box_3.setOutlineColor(sf::Color::White);
  guess_box_4.setFillColor(sf::Color::Blue);
  guess_box_4.setOutlineThickness(1);
  guess_box_4.setOutlineColor(sf::Color::White);
  guess_box_5.setFillColor(sf::Color::Blue);
  guess_box_5.setOutlineThickness(1);
  guess_box_5.setOutlineColor(sf::Color::White);  
  guess_box_6.setFillColor(sf::Color::Blue);
  guess_box_6.setOutlineThickness(1);
  guess_box_6.setOutlineColor(sf::Color::White);
  guess_box_7.setFillColor(sf::Color::Blue);
  guess_box_7.setOutlineThickness(1);
  guess_box_7.setOutlineColor(sf::Color::White);
  guess_box_8.setFillColor(sf::Color::Blue);
  guess_box_8.setOutlineThickness(1);
  guess_box_8.setOutlineColor(sf::Color::White);
  guess_box_9.setFillColor(sf::Color::Blue);
  guess_box_9.setOutlineThickness(1);
  guess_box_9.setOutlineColor(sf::Color::White);    

  // Creates the fonts used for each of the text blocks (can be anything in the VM,
  // just browse and choose what you like)
  sf::Font topfont;
  sf::Font categoryfont;
  topfont.loadFromFile("/usr/share/fonts/truetype/ubuntu/UbuntuMono-B.ttf");
  categoryfont.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-Th.ttf");
  toptext.setFont(topfont);
  cat_one_text.setFont(topfont);
  cat_two_text.setFont(topfont);
  cat_three_text.setFont(topfont);
  cat_four_text.setFont(topfont);
  //cat_five_text.setFont(categoryfont);

  // Not sure if this is needed or not...
  window.setFramerateLimit(10);

  // Set position of elements (x position, y position).
  // (indexed off the top left conrer)
  box.setPosition(50, 50);
  cat_1_box.setPosition(200, 150);
  cat_2_box.setPosition(200, 300);
  cat_3_box.setPosition(200, 450);
  cat_4_box.setPosition(200, 600);
  hint_box.setPosition(200, 50);
  guess_box_1.setPosition(150, 175);
  guess_box_2.setPosition(550, 175);
  guess_box_3.setPosition(150, 300);
  guess_box_4.setPosition(550, 300);
  guess_box_5.setPosition(150, 425);
  guess_box_6.setPosition(550, 425);
  guess_box_7.setPosition(150, 550);
  guess_box_8.setPosition(550, 550);
  guess_box_9.setPosition(350, 675);

  toptext.setPosition(100, 50);
  cat_one_text.setPosition(225, 170);
  cat_two_text.setPosition(225, 320);
  cat_three_text.setPosition(225, 470);
  cat_four_text.setPosition(225, 620);
  //cat_five_text.setPosition(420, 500);

  // Assign the text that will be displayed for each element.
  toptext.setString("Let's Play! Select A Category...");
  toptext.setCharacterSize(50);
  toptext.setFillColor(sf::Color::White);
  cat_one_text.setString("A)      Animals");
  cat_one_text.setCharacterSize(50);
  cat_one_text.setFillColor(sf::Color::Black);
  cat_one_text.setOutlineThickness(0);
  cat_two_text.setString("B)     Countries");
  cat_two_text.setCharacterSize(50);
  cat_two_text.setFillColor(sf::Color::Black);
  cat_two_text.setOutlineThickness(0);
  cat_three_text.setString("C)       Food");
  cat_three_text.setCharacterSize(50);
  cat_three_text.setFillColor(sf::Color::Black);
  cat_three_text.setOutlineThickness(0);
  cat_four_text.setString("D)      Sports");
  cat_four_text.setCharacterSize(50);
  cat_four_text.setFillColor(sf::Color::Black);
  cat_four_text.setOutlineThickness(0);
  // cat_five_text.setString("Category 5");
  // cat_five_text.setFillColor(sf::Color::Black);
  // cat_five_text.setOutlineThickness(0);

  // Opens the GUI and keeps it open until it is closed
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
  //Score Box
  score_text.setFont(topfont);
  score_text.setPosition(850,700);
  score_text.setString("Score");
  score_text.setCharacterSize(35);
  score_text.setFillColor(sf::Color::White);
  score_text.setOutlineThickness(0);
  score_num.setFont(topfont);
  score_num.setPosition(885,735);
  score_num.setString("0"); //Replace "num" with points
  score_num.setCharacterSize(35);
  score_num.setFillColor(sf::Color::White);
  score_num.setOutlineThickness(0);
    
    
    // Print all the elements that have been created for the main page.
    // Note, these are printed in order. If you want something to be in the
    //   background it needs to be printed first/early. If you want something
    //     to be in the foregroud, it needs to be printed last/later.
    window.clear();
    //window.draw(box);
    window.draw(toptext);
    window.draw(cat_1_box);
    window.draw(cat_2_box);
    window.draw(cat_3_box);
    window.draw(cat_4_box);
    window.draw(cat_one_text);
    window.draw(cat_two_text);
    window.draw(cat_three_text);
    window.draw(cat_four_text);
    window.draw(score_text);
    window.draw(score_num);

    // Displays the window created from the actions above
    window.display();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {


      while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)
            window.close();
        }
        window.clear();
        //window.draw(box);
        window.draw(hint_box);
        window.draw(guess_box_1);
        window.draw(guess_box_2);
        window.draw(guess_box_3);
        window.draw(guess_box_4);
        window.draw(guess_box_5);
        window.draw(guess_box_6);
        window.draw(guess_box_7);
        window.draw(guess_box_8);
        window.draw(guess_box_9);
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
