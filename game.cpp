//Copyright 2021 F. Alshammari fahed@bu.edu
//Copyright 2021 S. Deckers sebd@bu.edu
//Copyright 2021 C. McBride mcbridec@bu.edu
//Copyright 2021 J. Wang jaswang@bu.edu

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

// creating categories loaded with words and hints
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
std::vector <category> languages{
  {"C", "Low-level", "Stable:2018", "Lacking built-in function"},
  {"C++", ".at() not []", "Stable:2020", "Great class at BU"},
  {"Python", "Many Libraries", "High-level", "Slower speed"},
  {"Matlab", "Excellent Visualization", "Data Analysis", "Used by most engineers"},
  {"Java", "Easy", "Widely-used", "Server-side language"},
  {"Javascript", "Build websites", "Makes User-interfaces", "Recently turned 25"},
  {"R", "Data-analysis", "Open-source", "Machine-learning equations"},
  {"Reactnative", "Mobile apps", "Made by Facebook", "Younger Language"},
  {"Assembly", "Lowest-level", "Hard to debug", "direct hardware manipulation"}
};

int main() {
  int round_counter = 0; //counter for max rounds.
  bool endgame = false;
  std::string rc_str = std::to_string(round_counter);
  std::string points_str;
  // These lines establish and name the window for the GUI
  int windowheight = 800;
  int windowwidth = 1000;
  sf::RenderWindow window(sf::VideoMode(windowwidth, windowheight),
                          "Guess What?!");

  // This block of items creates the elements used for the main page

  // Background Box
  sf::RectangleShape box(sf::Vector2f(windowwidth - 2, windowheight - 2));
  box.setFillColor(sf::Color(210, 210, 210));
  box.setOutlineColor(sf::Color(125, 125, 125));
  box.setOutlineThickness(1);
  box.setPosition(1, 1);

  // Rectangles for the 5 categories
  // Custom colors created by combining (R,G,B) values
  int cat_box_width = 600;
  int cat_box_height = 100;
  sf::RectangleShape cat_1_box(sf::Vector2f(cat_box_width, cat_box_height));
  cat_1_box.setFillColor(sf::Color::White);
  cat_1_box.setOutlineThickness(3);
  cat_1_box.setOutlineColor(sf::Color(185, 185, 185));
  cat_1_box.setPosition(200, 150);
  sf::RectangleShape cat_2_box(sf::Vector2f(cat_box_width, cat_box_height));
  cat_2_box.setFillColor(sf::Color::White);
  cat_2_box.setOutlineThickness(3);
  cat_2_box.setOutlineColor(sf::Color(185, 185, 185));
  cat_2_box.setPosition(200, 300);
  sf::RectangleShape cat_3_box(sf::Vector2f(cat_box_width, cat_box_height));
  cat_3_box.setFillColor(sf::Color::White);
  cat_3_box.setOutlineThickness(3);
  cat_3_box.setOutlineColor(sf::Color(185, 185, 185));
  cat_3_box.setPosition(200, 450);
  sf::RectangleShape cat_4_box(sf::Vector2f(cat_box_width, cat_box_height));
  cat_4_box.setFillColor(sf::Color::White);
  cat_4_box.setOutlineThickness(3);
  cat_4_box.setOutlineColor(sf::Color(185, 185, 185));
  cat_4_box.setPosition(200, 600);

  // Rectangles for the 9 guesses in each category
  int guessbox_width = 300;
  int guessbox_height = 50;
  sf::RectangleShape hint_box(sf::Vector2f(cat_box_width, 75));
  hint_box.setFillColor(sf::Color(0, 0, 128));
  hint_box.setOutlineThickness(1);
  hint_box.setOutlineColor(sf::Color::White);
  hint_box.setPosition(200, 50);
  sf::RectangleShape guess_box_1(sf::Vector2f(guessbox_width, guessbox_height));
  guess_box_1.setFillColor(sf::Color::White);
  guess_box_1.setOutlineThickness(3);
  guess_box_1.setOutlineColor(sf::Color(185, 185, 185));
  guess_box_1.setPosition(150, 175);
  sf::RectangleShape guess_box_2(sf::Vector2f(guessbox_width, guessbox_height));
  guess_box_2.setFillColor(sf::Color::White);
  guess_box_2.setOutlineThickness(3);
  guess_box_2.setOutlineColor(sf::Color(185, 185, 185));
  guess_box_2.setPosition(550, 175);
  sf::RectangleShape guess_box_3(sf::Vector2f(guessbox_width, guessbox_height));
  guess_box_3.setFillColor(sf::Color::White);
  guess_box_3.setOutlineThickness(3);
  guess_box_3.setOutlineColor(sf::Color(185, 185, 185));
  guess_box_3.setPosition(150, 300);
  sf::RectangleShape guess_box_4(sf::Vector2f(guessbox_width, guessbox_height));
  guess_box_4.setFillColor(sf::Color::White);
  guess_box_4.setOutlineThickness(3);
  guess_box_4.setOutlineColor(sf::Color(185, 185, 185));
  guess_box_4.setPosition(550, 300);
  sf::RectangleShape guess_box_5(sf::Vector2f(guessbox_width, guessbox_height));
  guess_box_5.setFillColor(sf::Color::White);
  guess_box_5.setOutlineThickness(3);
  guess_box_5.setOutlineColor(sf::Color(185, 185, 185));
  guess_box_5.setPosition(150, 425);
  sf::RectangleShape guess_box_6(sf::Vector2f(guessbox_width, guessbox_height));
  guess_box_6.setFillColor(sf::Color::White);
  guess_box_6.setOutlineThickness(3);
  guess_box_6.setOutlineColor(sf::Color(185, 185, 185));
  guess_box_6.setPosition(550, 425);
  sf::RectangleShape guess_box_7(sf::Vector2f(guessbox_width, guessbox_height));
  guess_box_7.setFillColor(sf::Color::White);
  guess_box_7.setOutlineThickness(3);
  guess_box_7.setOutlineColor(sf::Color(185, 185, 185));
  guess_box_7.setPosition(150, 550);
  sf::RectangleShape guess_box_8(sf::Vector2f(guessbox_width, guessbox_height));
  guess_box_8.setFillColor(sf::Color::White);
  guess_box_8.setOutlineThickness(3);
  guess_box_8.setOutlineColor(sf::Color(185, 185, 185));
  guess_box_8.setPosition(550, 550);
  sf::RectangleShape guess_box_9(sf::Vector2f(guessbox_width, guessbox_height));
  guess_box_9.setFillColor(sf::Color::White);
  guess_box_9.setOutlineThickness(3);
  guess_box_9.setOutlineColor(sf::Color(185, 185, 185));
  guess_box_9.setPosition(350, 675);

  //Creates the different text elements for the main screen
  //Creates the fonts used for each of the text blocks (can be anything in the VM,
  //just browse and choose what you like)
  sf::Font topfont;
  sf::Font categoryfont;
  topfont.loadFromFile("/usr/share/fonts/truetype/ubuntu/UbuntuMono-B.ttf");
  categoryfont.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-Th.ttf");
  // Custom colors created by combining (R,G,B) values

  // Text for the top banner on the main screen
  sf::Text toptext;
  toptext.setFont(topfont);
  toptext.setPosition(100, 15);
  toptext.setString("Let's Play! Select A Category...");
  toptext.setCharacterSize(50);
  toptext.setFillColor(sf::Color(0, 0, 128));
  // Text for setting a high score page
  sf::Text congrats_text;
  congrats_text.setFont(topfont);
  congrats_text.setPosition(225, 100);
  congrats_text.setString("Congratulations!");
  congrats_text.setCharacterSize(70);
  congrats_text.setFillColor(sf::Color(5, 102, 8));
  sf::Text highscore_set_text;
  highscore_set_text.setFont(topfont);
  highscore_set_text.setPosition(150, 200);
  highscore_set_text.setString("You have set a new highscore!");
  highscore_set_text.setCharacterSize(50);
  highscore_set_text.setFillColor(sf::Color(5, 102, 8));
  sf::Text display_score;
  display_score.setFont(topfont);
  display_score.setPosition(350, 275);
  display_score.setCharacterSize(50);
  display_score.setFillColor(sf::Color(150, 0, 0));
  // Text for game over
  sf::Text endgame_text1;
  endgame_text1.setFont(topfont);
  endgame_text1.setPosition(200, 100);
  endgame_text1.setString("Thanks for playing");
  endgame_text1.setCharacterSize(70);
  endgame_text1.setFillColor(sf::Color(5, 102, 8));

  // Text to play a new game
  sf::Text newgame_text;
  newgame_text.setFont(topfont);
  newgame_text.setPosition(325, 500);
  newgame_text.setString("Play again? y/n");
  newgame_text.setCharacterSize(50);
  newgame_text.setFillColor(sf::Color(0, 0, 128));

  // Text for the welcome page
  sf::Text guesswhat_text;
  guesswhat_text.setFont(topfont);
  guesswhat_text.setPosition(270, 50);
  guesswhat_text.setString("Guess What?!");
  guesswhat_text.setCharacterSize(70);
  guesswhat_text.setFillColor(sf::Color(0, 0, 128));
  sf::Text enter_text;
  enter_text.setFont(topfont);
  enter_text.setPosition(275, 600);
  enter_text.setString("Press 'Enter' to play!");
  enter_text.setCharacterSize(40);
  enter_text.setFillColor(sf::Color(0, 0, 128));
  sf::Text instructions_text;
  instructions_text.setFont(topfont);
  instructions_text.setPosition(120, 150);
  instructions_text.setString("No more flashcards - a study tool game!");
  instructions_text.setCharacterSize(40);
  instructions_text.setFillColor(sf::Color(0, 0, 128));

  //::Text for the round counter
  sf::Text round_text;
  round_text.setFont(topfont);
  round_text.setPosition(435, 80);
  round_text.setString("Round " + rc_str);
  round_text.setCharacterSize(45);
  round_text.setFillColor(sf::Color::White);
  round_text.setOutlineThickness(0);
  round_text.setOutlineThickness(1);
  round_text.setOutlineColor(sf::Color(0, 0, 128));
  // Text for an incorrect answer
  sf::Text incorrect_text;
  incorrect_text.setFont(topfont);
  incorrect_text.setPosition(400, 350);
  incorrect_text.setString("Incorrect");
  incorrect_text.setCharacterSize(50);
  incorrect_text.setFillColor(sf::Color(150, 0, 0));
  // Text for a correct answer
  sf::Text correct_text;
  correct_text.setFont(topfont);
  correct_text.setPosition(420, 300);
  correct_text.setString("Correct!");
  correct_text.setCharacterSize(50);
  correct_text.setFillColor(sf::Color(5, 102, 8));
  // Text for points earned
  sf::Text points_text;
  points_text.setFont(topfont);
  points_text.setPosition(310, 350);
  points_text.setString("Points Earned: " + points_str);
  points_text.setCharacterSize(50);
  points_text.setFillColor(sf::Color(5, 102, 8));

  // Text for each of the four categories
  sf::Text cat_one_text;
  cat_one_text.setFont(topfont);
  cat_one_text.setPosition(225, 170);
  cat_one_text.setString("A)      Animals");
  cat_one_text.setCharacterSize(50);
  cat_one_text.setFillColor(sf::Color(0, 0, 128));
  cat_one_text.setOutlineThickness(0);
  sf::Text cat_two_text;
  cat_two_text.setFont(topfont);
  cat_two_text.setPosition(225, 320);
  cat_two_text.setString("B)     Countries");
  cat_two_text.setCharacterSize(50);
  cat_two_text.setFillColor(sf::Color(0, 0, 128));
  cat_two_text.setOutlineThickness(0);
  sf::Text cat_three_text;
  cat_three_text.setFont(topfont);
  cat_three_text.setPosition(225, 470);
  cat_three_text.setString("C)       Food");
  cat_three_text.setCharacterSize(50);
  cat_three_text.setFillColor(sf::Color(0, 0, 128));
  cat_three_text.setOutlineThickness(0);
  sf::Text cat_four_text;
  cat_four_text.setFont(topfont);
  cat_four_text.setPosition(225, 620);
  cat_four_text.setString("D)      Sports");
  cat_four_text.setCharacterSize(50);
  cat_four_text.setFillColor(sf::Color(0, 0, 128));
  cat_four_text.setOutlineThickness(0);

  // creating the text for the score
  sf::Text score_text;
  score_text.setFont(topfont);
  score_text.setPosition(800, 735);
  score_text.setString("Score:");
  score_text.setCharacterSize(35);
  score_text.setFillColor(sf::Color(5, 102, 8));
  score_text.setOutlineThickness(0);
  sf::Text score_num;
  score_num.setFont(topfont);
  score_num.setPosition(907, 735);
  score_num.setString("0"); //Replace "num" with points (int to string) in if else
  score_num.setCharacterSize(35);
  score_num.setFillColor(sf::Color(5, 102, 8));
  score_num.setOutlineThickness(0);

  //creating the text for the running high score
  sf::Text highscore_text;
  highscore_text.setFont(topfont);
  highscore_text.setPosition(50, 735);
  highscore_text.setString("Highscore:");
  highscore_text.setCharacterSize(35);
  highscore_text.setFillColor(sf::Color(150, 0, 0));
  highscore_text.setOutlineThickness(0);
  sf::Text highscore_num;
  highscore_num.setFont(topfont);
  highscore_num.setPosition(237, 735);
  highscore_num.setString("0"); //Replace "num" with points (int to string) in if else
  highscore_num.setCharacterSize(35);
  highscore_num.setFillColor(sf::Color(150, 0, 0));
  highscore_num.setOutlineThickness(0);

  //creating the text for each of the guesses for each category
  //note - the strings will be assigned later
  sf::Text guess_text_1;
  guess_text_1.setFont(topfont);
  guess_text_1.setPosition(155, 177);
  guess_text_1.setFillColor(sf::Color(0, 0, 128));
  sf::Text guess_text_2;
  guess_text_2.setFont(topfont);
  guess_text_2.setPosition(555, 177);
  guess_text_2.setFillColor(sf::Color(0, 0, 128));
  sf::Text guess_text_3;
  guess_text_3.setFont(topfont);
  guess_text_3.setPosition(155, 302);
  guess_text_3.setFillColor(sf::Color(0, 0, 128));
  sf::Text guess_text_4;
  guess_text_4.setFont(topfont);
  guess_text_4.setPosition(555, 302);
  guess_text_4.setFillColor(sf::Color(0, 0, 128));
  sf::Text guess_text_5;
  guess_text_5.setFont(topfont);
  guess_text_5.setPosition(155, 427);
  guess_text_5.setFillColor(sf::Color(0, 0, 128));
  sf::Text guess_text_6;
  guess_text_6.setFont(topfont);
  guess_text_6.setPosition(555, 427);
  guess_text_6.setFillColor(sf::Color(0, 0, 128));
  sf::Text guess_text_7;
  guess_text_7.setFont(topfont);
  guess_text_7.setPosition(155, 552);
  guess_text_7.setFillColor(sf::Color(0, 0, 128));
  sf::Text guess_text_8;
  guess_text_8.setFont(topfont);
  guess_text_8.setPosition(555, 552);
  guess_text_8.setFillColor(sf::Color(0, 0, 128));
  sf::Text guess_text_9;
  guess_text_9.setFont(topfont);
  guess_text_9.setPosition(355, 677);
  guess_text_9.setFillColor(sf::Color(0, 0, 128));
  sf::Text hint_text;
  hint_text.setFont(categoryfont);
  hint_text.setPosition(205, 75);
  hint_text.setFillColor(sf::Color::White);

  //Not sure if this is needed or not...
  window.setFramerateLimit(10);

  std::string str;
  int points = 0;
  bool first_time = true;



  // Opens the GUI and keeps it open until it is closed
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    if (first_time == true) {
      window.clear();
      window.draw(box);
      window.draw(enter_text);
      window.draw(instructions_text);
      instructions_text.setCharacterSize(30);
      instructions_text.setString("You have 4 rounds to score as many points as possible");
      instructions_text.setPosition(100, 250);
      window.draw(instructions_text);
      instructions_text.setString("Use your keyboard to enter your selections.");
      instructions_text.setPosition(175, 300);
      window.draw(instructions_text);
      instructions_text.setString("Press '0' for up to 2 additonal hints - but be careful,");
      instructions_text.setPosition(90, 350);
      window.draw(instructions_text);
      instructions_text.setString("each hint reduces your possible score and");
      instructions_text.setPosition(185, 400);
      window.draw(instructions_text);
      instructions_text.setString("incorrect guesses result in no points for that round.");
      instructions_text.setPosition(110, 450);
      window.draw(instructions_text);
      instructions_text.setCharacterSize(40);
      instructions_text.setString("Ready?");
      instructions_text.setPosition(420, 500);
      window.draw(instructions_text);
      window.draw(guesswhat_text);
      window.display();

      while (first_time == true) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
          first_time = false;
          break;
        }
      }
    }
    std::vector<std::string> sol;
    std::ifstream file;
    file.open("highscore.txt");
    std::string line;
    while(std::getline(file, line)) {
      sol.push_back(line);
    }
    file.close();
    if (round_counter == 4) {

      std::string::size_type sz;
      int rec = std::stoi(sol.at(0), &sz);
      if (points > rec) {
        window.clear();
        window.draw(box);
        std::string str = std::to_string(points);
        window.draw(congrats_text);
        window.draw(highscore_set_text);
        display_score.setString("Highscore: " + str);
        window.draw(display_score);
        window.draw(newgame_text);
        window.display();

        std::ofstream ofile;
        ofile.open("highscore.txt", std::ofstream::out | std::ofstream::trunc);
        ofile << points;
        ofile.close();
        while (round_counter == 4) {
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
            endgame = true;
            break;
          } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
            endgame = false;
            break;
          }
        }

      } else if(points <= rec) {
        window.clear();
        window.draw(box);
        std::string str = std::to_string(points);
        window.draw(endgame_text1);
        display_score.setString("Yourscore: " + str);
        window.draw(display_score);
        window.draw(newgame_text);
        window.display();

        while (round_counter == 4) {
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
            endgame = true;
            break;
          } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
            endgame = false;
            break;
          }
        }
      }
      if (endgame == true) {
        break;
        window.close();
      }
      if (endgame == false) {
        round_counter = 0;
        points = 0;
        str = std::to_string(points);
      }
    }
    //Print all the elements that have been created for the main page.
    //Note, these are printed in order. If you want something to be in the
    //background it needs to be printed first/early. If you want something
    //to be in the foregroud, it needs to be printed last/later.
    window.clear();
    window.draw(box);
    window.draw(toptext);
    rc_str = std::to_string(round_counter + 1);
    round_text.setString("Round " + rc_str);
    window.draw(round_text);
    window.draw(cat_1_box);
    window.draw(cat_2_box);
    window.draw(cat_3_box);
    window.draw(cat_4_box);
    window.draw(cat_one_text);
    window.draw(cat_two_text);
    window.draw(cat_three_text);
    window.draw(cat_four_text);
    window.draw(score_text);
    str = std::to_string(points);
    score_num.setString(str);
    window.draw(score_num);
    highscore_num.setString(sol.at(0));
    window.draw(highscore_text);
    window.draw(highscore_num);

    //Displays the window created from the actions above
    window.display();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

      while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)
            window.close();
        }

        window.clear();
        window.draw(box);
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
          str = std::to_string(points);
          score_num.setString(str);
          window.draw(score_num);
          hint_text.setString("Hint: " + animals.at(v).at(i));
          window.draw(hint_text);
          window.draw(highscore_text);
          window.draw(highscore_num);
          window.display();
          while (ans1 == true) {
            std::this_thread::sleep_for(std::chrono::nanoseconds(50000000));
            if (i < 3) {
              if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
                  or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))) {

                window.draw(hint_box);

                hint_text.setString("Hint: " + animals.at(v).at(i));
                window.draw(hint_text);
                window.display();
                ans1 = false;
              }
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))) {
              ans = 1;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))) {
              ans = 2;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))) {
              ans = 3;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))) {
              ans = 4;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))) {
              ans = 5;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))) {
              ans = 6;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))) {
              ans = 7;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))) {
              ans = 8;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))) {
              ans = 9;
              break;
            }

          }

          temp = temp - 5;
          if (ans == v + 1) {
            std::string str = std::to_string(points);
            score_num.setString(str);

            window.clear();
            window.draw(box);
            window.draw(correct_text);
            points_str = std::to_string(temp);
            points_text.setString("Points Earned: " + points_str);
            window.draw(points_text);
            window.display();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
          } else if ((ans != v + 1 & ans != 10 & ans != 0) | i == 3)  {

            temp = 0;
            window.clear();
            window.draw(box);
            window.draw(incorrect_text);
            window.display();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
          }
        }

        points = points + temp;
        std::string str = std::to_string(points);
        score_num.setString(str);
        round_counter++;
        window.draw(score_num);
        window.display();
        break;
      }

    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {

      while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)
            window.close();
        }

        window.clear();
        window.draw(box);
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
            if (i < 3) {
              if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
                  or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))) {

                window.draw(hint_box);

                hint_text.setString("Hint: " + countries.at(v).at(i));
                window.draw(hint_text);
                window.display();
                ans1 = false;
              }
            }

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))) {
              ans = 1;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))) {
              ans = 2;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))) {
              ans = 3;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))) {
              ans = 4;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))) {
              ans = 5;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))) {
              ans = 6;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))) {
              ans = 7;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))) {
              ans = 8;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))) {
              ans = 9;
              break;
            }

          }
          temp = temp - 5;
          if (ans == v + 1) {
            std::string str = std::to_string(points);
            score_num.setString(str);

            window.clear();
            window.draw(box);
            window.draw(correct_text);
            points_str = std::to_string(temp);
            points_text.setString("Points Earned: " + points_str);
            window.draw(points_text);
            window.display();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
          } else if ((ans != v + 1 & ans != 10 & ans != 0) | i == 3)  {

            temp = 0;
            window.clear();
            window.draw(box);
            window.draw(incorrect_text);
            window.display();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
          }
        }

        points = points + temp;
        std::string str = std::to_string(points);
        score_num.setString(str);
        round_counter++;
        window.draw(score_num);
        window.display();
        break;
      }

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {


      while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)
            window.close();
        }

        window.clear();
        window.draw(box);
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
            if (i < 3) {
              if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
                  or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))) {

                window.draw(hint_box);

                hint_text.setString("Hint: " + foods.at(v).at(i));
                window.draw(hint_text);
                window.display();
                ans1 = false;
              }
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))) {
              ans = 1;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))) {
              ans = 2;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))) {
              ans = 3;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))) {
              ans = 4;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))) {
              ans = 5;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))) {
              ans = 6;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))) {
              ans = 7;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))) {
              ans = 8;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))) {
              ans = 9;
              break;
            }

          }

          temp = temp - 5;
          if (ans == v + 1) {
            std::string str = std::to_string(points);
            score_num.setString(str);

            window.clear();
            window.draw(box);
            window.draw(correct_text);
            points_str = std::to_string(temp);
            points_text.setString("Points Earned: " + points_str);
            window.draw(points_text);
            window.display();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
          } else if ((ans != v + 1 & ans != 10 & ans != 0) | i == 3)  {

            temp = 0;
            window.clear();
            window.draw(box);
            window.draw(incorrect_text);
            window.display();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
          }
        }

        points = points + temp;
        std::string str = std::to_string(points);
        score_num.setString(str);
        round_counter++;
        window.draw(score_num);
        window.display();
        break;
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
        window.draw(box);
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
            if (i < 3) {
              if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
                  or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))) {

                window.draw(hint_box);

                hint_text.setString("Hint: " + sports.at(v).at(i));
                window.draw(hint_text);
                window.display();
                ans1 = false;
              }
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))) {
              ans = 1;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))) {
              ans = 2;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))) {
              ans = 3;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))) {
              ans = 4;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))) {
              ans = 5;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))) {
              ans = 6;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))) {
              ans = 7;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))) {
              ans = 8;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))) {
              ans = 9;
              break;
            }

          }

          temp = temp - 5;
          if (ans == v + 1) {
            std::string str = std::to_string(points);
            score_num.setString(str);

            window.clear();
            window.draw(box);
            window.draw(correct_text);
            points_str = std::to_string(temp);
            points_text.setString("Points Earned: " + points_str);
            window.draw(points_text);
            window.display();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
          } else if ((ans != v + 1 & ans != 10 & ans != 0) | i == 3)  {

            temp = 0;
            window.clear();
            window.draw(box);
            window.draw(incorrect_text);
            window.display();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
          }
        }

        points = points + temp;
        std::string str = std::to_string(points);
        score_num.setString(str);
        round_counter++;
        window.draw(score_num);
        window.display();
        break;
      }

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {

      while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)
            window.close();
        }

        window.clear();
        window.draw(box);
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
        guess_text_1.setString("1) C");
        window.draw(guess_text_1);
        guess_text_2.setString("2) C++");
        window.draw(guess_text_2);
        guess_text_3.setString("3) Python");
        window.draw(guess_text_3);
        guess_text_4.setString("4) Matlab");
        window.draw(guess_text_4);
        guess_text_5.setString("5) Java");
        window.draw(guess_text_5);
        guess_text_6.setString("6) Javascript");
        window.draw(guess_text_6);
        guess_text_7.setString("7) R");
        window.draw(guess_text_7);
        guess_text_8.setString("8) Reactnative");
        window.draw(guess_text_8);
        guess_text_9.setString("9) Assembly");
        window.draw(guess_text_9);
        hint_text.setString("Hint:");

        window.display();
        srand(time(0));
        int v = rand() % 9;
        int ans = 0;
        int temp = 40;

        for(int i = 1; i < 4; i++) {
          bool ans1 = true;
          window.draw(hint_box);

          window.draw(score_text);
          std::string str = std::to_string(points);
          score_num.setString(str);
          window.draw(score_num);
          hint_text.setString("Hint: " + languages.at(v).at(i));
          window.draw(hint_text);
          window.display();
          while (ans1 == true) {
            std::this_thread::sleep_for(std::chrono::nanoseconds(50000000));
            if (i < 3) {
              if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
                  or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))) {

                window.draw(hint_box);

                hint_text.setString("Hint: " + languages.at(v).at(i));
                window.draw(hint_text);
                window.display();
                ans1 = false;
              }
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))) {
              ans = 1;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))) {
              ans = 2;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))) {
              ans = 3;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))) {
              ans = 4;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))) {
              ans = 5;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))) {
              ans = 6;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))) {
              ans = 7;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))) {
              ans = 8;
              break;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
                or (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))) {
              ans = 9;
              break;
            }

          }

          temp = temp - 15;
          if (ans == v + 1) {
            std::string str = std::to_string(points);
            score_num.setString(str);

            window.clear();
            window.draw(box);
            window.draw(correct_text);
            points_str = std::to_string(temp);
            points_text.setString("Points Earned: " + points_str);
            window.draw(points_text);
            window.display();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
          } else if ((ans != v + 1 & ans != 10 & ans != 0) | i == 3)  {

            temp = 0;
            window.clear();
            window.draw(box);
            window.draw(incorrect_text);
            window.display();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
          }
        }

        points = points + temp;
        std::string str = std::to_string(points);
        score_num.setString(str);
        round_counter++;
        window.draw(score_num);
        window.display();
        break;
      }

    }
  }
}
