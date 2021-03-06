#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>
#include<vector>
#include<stdlib.h>
#include<unistd.h>
#include<chrono>
#include<thread>
#include<ctime>
#include<SFML/Graphics.hpp>
#include<string>
#include<SFML/Window/Keyboard.hpp>
using std::cin;
using std::cout;
using std::string;
using std::to_string;

typedef std::vector<std::string> category;
std::vector <category> animals{
  {"Gorilla", "Has Fur", "Large", "Bipedal"},
  {"Elephant", "Large", "Roams in Herds", "Trunks"},
  {"Tiger", "Predator", "Patterned", "Big Cat"},
  {"Zebra", "Has Fur", "Patterned", "Cannot be domesticated"},
  {"Leopard", "Predator", "Patterned", "Small cat"},
  {"Camel", "Domesticated", "3 sets of eyelids", "Hump"},
  {"Dog", "Has Fur", "Domesticated", "Trainable"},
  {"Chicken", "Domesticated", "Bipedal", "Feathered"},
  {"Owl", "Predator", "Feathered", "Who?"}
};
std::vector <category> countries{
  {"Brazil", "European Influence", "South", "Rainforest"},
  {"Australia", "Unique Wildlife", "Coasts", "Prison"},
  {"China", "East", "Dynasty", "Wall"},
  {"Egypt", "North", "Ancient Civilization", "Wonder"},
  {"Peru", "Exploration", "Ancient Civilization", "Incas"},
  {"Mexico", "North", "European Conquest", "Aztec"},
  {"Canada", "European Influence", "Longest Coastline", "Bilingual"},
  {"Russia", "North", "Diverse Climate", "Vodka"},
  {"USA", "Diverse Climate", "Industrious", "West"}
};
std::vector <category> foods{
  {"Apple", "Fruit", "Tree", "Sweet"},
  {"Tomato", "Red", "Juicy", "Sweet"},
  {"Steak", "Cooked", "Red", "Animal"},
  {"Chicken", "Farm", "Raised", "White"},
  {"Chickpea", "Grown", "Round", "Hummus"},
  {"Avocado", "Fatty", "Plant", "Green"},
  {"Carrot", "Ground", "Vegetable", "Crunchy"},
  {"IceCream", "Summer", "Sweet", "Spoon"},
  {"Hamburger", "Ground", "Fatty", "Juicy"}
};
std::vector <category> sports{
  {"Football", "American", "Yards", "Touchdown"},
  {"Basketball", "Net", "Tall", "Court"},
  {"Baseball", "American", "Small", "Fenway"},
  {"Swimming", "No Ball", "Fast", "Wet"},
  {"Track", "No Ball", "Fast", "Run"},
  {"Gymnastics", "No Ball", "Balance", "Flexible"},
  {"Soccer", "Ball", "Real Madrid", "Greatest Sport On Earth"},
  {"Cricket", "Bat", "Wicket", "England"},
  {"Volleyball", "Net", "Beach", "Jump"}
};

int main() {
  int round_counter = 0; //counter for max rounds.
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
  sf::Text highscore_text;
  sf::Text highscore_num;
  sf::Text guess_text_1;
  sf::Text guess_text_2;
  sf::Text guess_text_3;
  sf::Text guess_text_4;
  sf::Text guess_text_5;
  sf::Text guess_text_6;
  sf::Text guess_text_7;
  sf::Text guess_text_8;
  sf::Text guess_text_9;
  sf::Text hint_text;
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
  hint_box.setFillColor(sf::Color(128, 128, 128));
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
  guess_text_1.setFont(categoryfont);
  guess_text_2.setFont(categoryfont);
  guess_text_3.setFont(categoryfont);
  guess_text_4.setFont(categoryfont);
  guess_text_5.setFont(categoryfont);
  guess_text_6.setFont(categoryfont);
  guess_text_7.setFont(categoryfont);
  guess_text_8.setFont(categoryfont);
  guess_text_9.setFont(categoryfont);
  hint_text.setFont(categoryfont);

  score_text.setFont(topfont);
  score_text.setPosition(800, 735);
  score_text.setString("Score:");
  score_text.setCharacterSize(35);
  score_text.setFillColor(sf::Color::White);
  score_text.setOutlineThickness(0);
  score_num.setFont(topfont);
  score_num.setPosition(907, 735);
  score_num.setString("0"); //Replace "num" with points (int to string)
  score_num.setCharacterSize(35);
  score_num.setFillColor(sf::Color::White);
  score_num.setOutlineThickness(0);
  //cat_five_text.setFont(categoryfont);

  highscore_text.setFont(topfont);
  highscore_text.setPosition(50, 735);
  highscore_text.setString("Highscore:");
  highscore_text.setCharacterSize(35);
  highscore_text.setFillColor(sf::Color::White);
  highscore_text.setOutlineThickness(0);
  highscore_num.setFont(topfont);
  highscore_num.setPosition(237, 735);
  highscore_num.setString("0"); //Replace "num" with points (int to string)
  highscore_num.setCharacterSize(35);
  highscore_num.setFillColor(sf::Color::White);
  highscore_num.setOutlineThickness(0);
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
  guess_text_1.setPosition(155, 177);
  guess_text_2.setPosition(555, 177);
  guess_text_3.setPosition(155, 302);
  guess_text_4.setPosition(555, 302);
  guess_text_5.setPosition(155, 427);
  guess_text_6.setPosition(555, 427);
  guess_text_7.setPosition(155, 552);
  guess_text_8.setPosition(555, 552);
  guess_text_9.setPosition(355, 677);
  hint_text.setPosition(205, 75);
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
  guess_text_1.setFillColor(sf::Color::White);
  guess_text_2.setFillColor(sf::Color::White);
  guess_text_3.setFillColor(sf::Color::White);
  guess_text_4.setFillColor(sf::Color::White);
  guess_text_5.setFillColor(sf::Color::White);
  guess_text_6.setFillColor(sf::Color::White);
  guess_text_7.setFillColor(sf::Color::White);
  guess_text_8.setFillColor(sf::Color::White);
  guess_text_9.setFillColor(sf::Color::White);
  hint_text.setFillColor(sf::Color::Black);

  std::string str;
  // cat_five_text.setString("Category 5");
  // cat_five_text.setFillColor(sf::Color::Black);
  // cat_five_text.setOutlineThickness(0);
  int points = 0;
  std::vector<std::string> sol;
  std::vector<std::string> sol2;
  std::ifstream file;

  file.open("highscore.txt");
  std::string line;
  while(std::getline(file, line)) {
    sol.push_back(line);
  }
  file.close();
  // Opens the GUI and keeps it open until it is closed
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    if (round_counter == 4) {

      std::string::size_type sz;
      int rec = std::stoi(sol.at(0), &sz);
      if (points > rec) {
        window.clear();
        std::string str = std::to_string(points);
        toptext.setString("Congrats you have beat\n the highscore \n and accumulated \na point total of: " + str);
        window.draw(toptext);
        window.display();
        std::this_thread::sleep_for(std::chrono::seconds(10));

        std::ofstream ofile;
        ofile.open("highscore.txt", std::ofstream::out | std::ofstream::trunc);
        ofile << points;
        ofile.close();
        break;
      } else if(points < rec) {
        window.clear();
        std::string str = std::to_string(points);
        toptext.setString("Congrats you have accumulated \na point total of: " + str);
        window.draw(toptext);
        window.display();
        std::this_thread::sleep_for(std::chrono::seconds(10));
        break;
      }

    }
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
    highscore_num.setString(sol.at(0));
    window.draw(highscore_text);
    window.draw(highscore_num);

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
        window.draw(highscore_text);
        window.draw(highscore_num);
        guess_text_1.setString("1) Gorilla");
        window.draw(guess_text_1);
        guess_text_2.setString("2) Elephant");
        window.draw(guess_text_2);
        guess_text_3.setString("3) Tiger");
        window.draw(guess_text_3);
        guess_text_4.setString("4) Zebra");
        window.draw(guess_text_4);
        guess_text_5.setString("5) Leopard");
        window.draw(guess_text_5);
        guess_text_6.setString("6) Camel");
        window.draw(guess_text_6);
        guess_text_7.setString("7) Dog");
        window.draw(guess_text_7);
        guess_text_8.setString("8) Chicken");
        window.draw(guess_text_8);
        guess_text_9.setString("9) Owl");
        window.draw(guess_text_9);
        hint_text.setString("Hint:");

        window.display();
        srand(time(0));
        int v = rand() % 9;
        int ans = 0;
        int temp = 20;

        for(int i = 1; i < 4; i++) {
          bool ans1 = true;
          window.draw(hint_box);

          window.draw(score_text);
          std::string str = std::to_string(points);
          score_num.setString(str);
          window.draw(score_num);
          hint_text.setString("Hint: " + animals.at(v).at(i));
          window.draw(hint_text);
          window.draw(highscore_text);
          window.draw(highscore_num);
          window.display();
          while (ans1 == true) {
            std::this_thread::sleep_for(std::chrono::nanoseconds(50000000));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {


              window.draw(hint_box);

              hint_text.setString("Hint: " + animals.at(v).at(i));
              window.draw(hint_text);
              window.display();
              ans1 = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
              ans = 1;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
              ans = 2;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
              ans = 3;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
              ans = 4;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
              ans = 5;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
              ans = 6;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
              ans = 7;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
              ans = 8;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
              ans = 9;
              break;
            }

          }
          while(i == 3) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
              ans = 1;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
              ans = 2;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
              ans = 3;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
              ans = 4;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
              ans = 5;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
              ans = 6;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
              ans = 7;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
              ans = 8;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
              ans = 9;
              break;
              break;
            }

          }
          temp = temp - 5;
          if (ans == v + 1) {
            std::string str = std::to_string(points);
            score_num.setString(str);

            window.draw(score_num);
            window.display();
            break;
          } else if ((ans != v + 1 & ans != 10 & ans != 0) | i == 3)  {

            temp = 0;
            break;
          }


        }

        points = points + temp;
        std::string str = std::to_string(points);
        score_num.setString(str);
        round_counter++;
        window.draw(score_num);
        window.display();
        std::cout << "You got " << temp << " points this round. You are currently on " << points << " points\n";
        break;//break;
      }

    }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
    //   while (window.isOpen()) {
    //     sf::Event event;
    //     while (window.pollEvent(event)) {
    //       if (event.type == sf::Event::Closed)
    //         window.close();
    //     }
    //     window.clear();
    //     window.draw(box);
    //     window.draw(cat_2_box);
    //     window.draw(cat_two_text);
    //     window.display();
    //     int temp{country()};
    //     points = points + temp;
    //     std::cout << "You got " << temp << " points this round. You are currently on " << points << " points\n";
    //     break;
    //   }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {


      while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)
            window.close();
        }

        window.clear();
        //window.draw(box);
        window.draw(hint_box);
        window.draw(highscore_text);
        window.draw(highscore_num);
        window.draw(guess_box_1);
        window.draw(guess_box_2);
        window.draw(guess_box_3);
        window.draw(guess_box_4);
        window.draw(guess_box_5);
        window.draw(guess_box_6);
        window.draw(guess_box_7);
        window.draw(guess_box_8);
        window.draw(guess_box_9);
        guess_text_1.setString("1) Brazil");
        window.draw(guess_text_1);
        guess_text_2.setString("2) Australia");
        window.draw(guess_text_2);
        guess_text_3.setString("3) China");
        window.draw(guess_text_3);
        guess_text_4.setString("4) Egypt");
        window.draw(guess_text_4);
        guess_text_5.setString("5) Peru");
        window.draw(guess_text_5);
        guess_text_6.setString("6) Mexico");
        window.draw(guess_text_6);
        guess_text_7.setString("7) Canada");
        window.draw(guess_text_7);
        guess_text_8.setString("8) Russia");
        window.draw(guess_text_8);
        guess_text_9.setString("9) USA");
        window.draw(guess_text_9);
        hint_text.setString("Hint:");

        window.display();
        srand(time(0));
        int v = rand() % 9;
        int ans = 0;
        int temp = 20;

        for(int i = 1; i < 4; i++) {
          bool ans1 = true;
          window.draw(hint_box);

          window.draw(score_text);
          std::string str = std::to_string(points);
          score_num.setString(str);
          window.draw(score_num);
          hint_text.setString("Hint: " + countries.at(v).at(i));
          window.draw(hint_text);
          window.display();
          while (ans1 == true) {
            std::this_thread::sleep_for(std::chrono::nanoseconds(50000000));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {


              window.draw(hint_box);

              hint_text.setString("Hint: " + countries.at(v).at(i));
              window.draw(hint_text);
              window.display();
              ans1 = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
              ans = 1;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
              ans = 2;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
              ans = 3;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
              ans = 4;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
              ans = 5;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
              ans = 6;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
              ans = 7;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
              ans = 8;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
              ans = 9;
              break;
            }

          }
          while(i == 3) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
              ans = 1;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
              ans = 2;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
              ans = 3;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
              ans = 4;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
              ans = 5;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
              ans = 6;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
              ans = 7;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
              ans = 8;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
              ans = 9;
              break;
              break;
            }

          }
          temp = temp - 5;
          if (ans == v + 1) {
            std::string str = std::to_string(points);
            score_num.setString(str);

            window.draw(score_num);
            window.display();
            break;
          } else if ((ans != v + 1 & ans != 10 & ans != 0) | i == 3)  {

            temp = 0;
            break;
          }


        }

        points = points + temp;
        std::string str = std::to_string(points);
        score_num.setString(str);
        round_counter++;
        window.draw(score_num);
        window.display();
        std::cout << "You got " << temp << " points this round. You are currently on " << points << " points\n";
        break;//break;
      }

    }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
    //   while (window.isOpen()) {
    //     sf::Event event;
    //     while (window.pollEvent(event)) {
    //       if (event.type == sf::Event::Closed)
    //         window.close();
    //     }
    //     window.clear();
    //     window.draw(box);
    //     window.draw(cat_2_box);
    //     window.draw(cat_two_text);
    //     window.display();
    //     int temp{country()};
    //     points = points + temp;
    //     std::cout << "You got " << temp << " points this round. You are currently on " << points << " points\n";
    //     break;
    //   }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {


      while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)
            window.close();
        }

        window.clear();
        //window.draw(box);
        window.draw(highscore_text);
        window.draw(highscore_num);
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
        guess_text_1.setString("1) Apple");
        window.draw(guess_text_1);
        guess_text_2.setString("2) Tomato");
        window.draw(guess_text_2);
        guess_text_3.setString("3) Steak");
        window.draw(guess_text_3);
        guess_text_4.setString("4) Chicken");
        window.draw(guess_text_4);
        guess_text_5.setString("5) Chickpea");
        window.draw(guess_text_5);
        guess_text_6.setString("6) Avocado");
        window.draw(guess_text_6);
        guess_text_7.setString("7) Carrot");
        window.draw(guess_text_7);
        guess_text_8.setString("8) Icecream");
        window.draw(guess_text_8);
        guess_text_9.setString("9) Hamburger");
        window.draw(guess_text_9);
        hint_text.setString("Hint:");

        window.display();
        srand(time(0));
        int v = rand() % 9;
        int ans = 0;
        int temp = 20;

        for(int i = 1; i < 4; i++) {
          bool ans1 = true;
          window.draw(hint_box);

          window.draw(score_text);
          std::string str = std::to_string(points);
          score_num.setString(str);
          window.draw(score_num);
          hint_text.setString("Hint: " + foods.at(v).at(i));
          window.draw(hint_text);
          window.display();
          while (ans1 == true) {
            std::this_thread::sleep_for(std::chrono::nanoseconds(50000000));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {


              window.draw(hint_box);

              hint_text.setString("Hint: " + foods.at(v).at(i));
              window.draw(hint_text);
              window.display();
              ans1 = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
              ans = 1;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
              ans = 2;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
              ans = 3;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
              ans = 4;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
              ans = 5;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
              ans = 6;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
              ans = 7;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
              ans = 8;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
              ans = 9;
              break;
            }

          }
          while(i == 3) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
              ans = 1;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
              ans = 2;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
              ans = 3;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
              ans = 4;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
              ans = 5;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
              ans = 6;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
              ans = 7;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
              ans = 8;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
              ans = 9;
              break;
              break;
            }

          }
          temp = temp - 5;
          if (ans == v + 1) {
            std::string str = std::to_string(points);
            score_num.setString(str);

            window.draw(score_num);
            window.display();
            break;
          } else if ((ans != v + 1 & ans != 10 & ans != 0) | i == 3)  {

            temp = 0;
            break;
          }


        }

        points = points + temp;
        std::string str = std::to_string(points);
        score_num.setString(str);
        round_counter++;
        window.draw(score_num);
        window.display();
        std::cout << "You got " << temp << " points this round. You are currently on " << points << " points\n";
        break;//break;
      }

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {


      while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)
            window.close();
        }

        window.clear();
        //window.draw(box);
        window.draw(highscore_text);
        window.draw(highscore_num);
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
        guess_text_1.setString("1) Football");
        window.draw(guess_text_1);
        guess_text_2.setString("2) Basketball");
        window.draw(guess_text_2);
        guess_text_3.setString("3) Baseball");
        window.draw(guess_text_3);
        guess_text_4.setString("4) Swimming");
        window.draw(guess_text_4);
        guess_text_5.setString("5) Track");
        window.draw(guess_text_5);
        guess_text_6.setString("6) Gymnastics");
        window.draw(guess_text_6);
        guess_text_7.setString("7) Soccer");
        window.draw(guess_text_7);
        guess_text_8.setString("8) Cricket");
        window.draw(guess_text_8);
        guess_text_9.setString("9) Volleyball");
        window.draw(guess_text_9);
        hint_text.setString("Hint:");

        window.display();
        srand(time(0));
        int v = rand() % 9;
        int ans = 0;
        int temp = 20;

        for(int i = 1; i < 4; i++) {
          bool ans1 = true;
          window.draw(hint_box);

          window.draw(score_text);
          std::string str = std::to_string(points);
          score_num.setString(str);
          window.draw(score_num);
          hint_text.setString("Hint: " + sports.at(v).at(i));
          window.draw(hint_text);
          window.display();
          while (ans1 == true) {
            std::this_thread::sleep_for(std::chrono::nanoseconds(50000000));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {


              window.draw(hint_box);

              hint_text.setString("Hint: " + sports.at(v).at(i));
              window.draw(hint_text);
              window.display();
              ans1 = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
              ans = 1;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
              ans = 2;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
              ans = 3;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
              ans = 4;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
              ans = 5;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
              ans = 6;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
              ans = 7;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
              ans = 8;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
              ans = 9;
              break;
            }

          }
          while(i == 3) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
              ans = 1;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
              ans = 2;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
              ans = 3;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
              ans = 4;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
              ans = 5;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
              ans = 6;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
              ans = 7;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
              ans = 8;
              break;
              break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
              ans = 9;
              break;
              break;
            }

          }
          temp = temp - 5;
          if (ans == v + 1) {
            std::string str = std::to_string(points);
            score_num.setString(str);

            window.draw(score_num);
            window.display();
            break;
          } else if ((ans != v + 1 & ans != 10 & ans != 0) | i == 3)  {

            temp = 0;
            break;
          }


        }

        points = points + temp;
        std::string str = std::to_string(points);
        score_num.setString(str);
        round_counter++;
        window.draw(score_num);
        window.display();
        std::cout << "You got " << temp << " points this round. You are currently on " << points << " points\n";
        break;//break;
      }

    }
  }

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