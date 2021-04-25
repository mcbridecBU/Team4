#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>
#include<vector>
#include<stdlib.h>
#include<string>
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
int animal() {
  srand(time(0));
  int v = rand() % 9;
  int ans = 10;
  int temp = 20;
  std::cout << "These numbers correspond to these guesses\n1:Gorilla\n2:Elephant\n3:Tiger\n4:Zebra\n5:Leapord\n6:Camel\n7:Dog\n8:Chicken\n9:Owl\n";
  for(int i = 1; i < 4; i++) {
    if (ans == 10) {
      std::cout << " \nHint:" << animals.at(v).at(i) << "  enter answer(enter 10 for another hint)";
      std::cin >> ans;
      std::cout << "\n";
    }
    temp = temp - 5;
    if (ans == v + 1) {
      std::cout << "correct\n";
      break;
    }
    if (ans != v - 1 & ans != 10) {
      std::cout << "incorrect\n";
      temp = 0;
      break;
    }
  }
  return temp;
}
int country() {
  srand(time(0));
  int v = rand() % 9;
  int ans = 10;
  int temp = 20;
  std::cout << "These numbers correspond to these guesses\n1:Brazil\n2:Australia\n3:China\n4:Egypt\n5:Peru\n6:Mexico\n7:Canada\n8:Russia\n9:USA\n";
  for(int i = 1; i < 4; i++) {
    if (ans == 10) {
      std::cout << " \nHint:" << countries.at(v).at(i) << "  enter answer(enter 10 for another hint)";
      std::cin >> ans;
      std::cout << "\n";
    }
    temp = temp - 5;
    if (ans == v + 1) {
      std::cout << "correct\n";
      break;
    }
    if (ans != v - 1 & ans != 10) {
      std::cout << "incorrect\n";
      temp = 0;
      break;
    }
  }
  return temp;
}
int food() {
  srand(time(0));
  int v = rand() % 9;
  int ans = 10;
  int temp = 20;
  std::cout << "These numbers correspond to these guesses\n1:Apple\n2:Tomato\n3:Steak\n4:Chicken\n5:Chickpea\n6:Avocado\n7:Carrot\n8:Ice Cream\n9:Hamburger\n";
  for(int i = 1; i < 4; i++) {
    if (ans == 10) {
      std::cout << " \nHint:" << foods.at(v).at(i) << "  enter answer(enter 10 for another hint)";
      std::cin >> ans;
      std::cout << "\n";
    }
    temp = temp - 5;
    if (ans == v + 1) {
      std::cout << "correct\n";
      break;
    }
    if (ans != v - 1 & ans != 10) {
      std::cout << "incorrect\n";
      temp = 0;
      break;
    }
  }
  return temp;
}
int sport() {
  srand(time(0));
  int v = rand() % 9;
  int ans = 10;
  int temp = 20;
  std::cout << "These numbers correspond to these guesses\n1:Football\n2:Basketball\n3:Baseball\n4:Swimming\n5:Track\n6:Gymnastics\n7:Soccer\n8:Cricket\n9:Volleyball\n";
  for(int i = 1; i < 4; i++) {
    if (ans == 10) {
      std::cout << " \nHint:" << sports.at(v).at(i) << "  enter answer(enter 10 for another hint)";
      std::cin >> ans;
      std::cout << "\n";
    }
    temp = temp - 5;
    if (ans == v + 1) {
      std::cout << "correct\n";
      break;
    }
    if (ans != v - 1 & ans != 10) {
      std::cout << "incorrect\n";
      temp = 0;
      break;
    }
  }
  return temp;
}
void SplitString(std::string s, std::vector<std::string> &v){
  
  std::string temp = "";
  for(int i=0;i<s.length();++i){
    
    if(s[i]==' '){
      v.push_back(temp);
      temp = "";
    }
    else{
      temp.push_back(s[i]);
    }
    
  }
  v.push_back(temp);
  
}


int main() {
  std::vector<std::string> sol;
  std::vector<std::string> sol2;
  std::ifstream file;
  //copy(istream_iterator<std::string>)
   file.open("highscore.txt");
 std::string line;
   while(std::getline(file, line)) {
     sol.push_back(line);
   }
  file.close();
  SplitString(sol.at(0),sol2);
  std::cout << "Welcome to 'Guess What?' You will have 4 opportunities to guess a word and win points. Current High score is " << sol2.at(1) << " points held by " << sol2.at(0)<<"\n";
  int k;
  int points = 0;

  for (int i = 0; i < 4; i++) {

    std::cout << "Type in category: \nfor animals type '1'. \nfor countries type '2' \nfor food type '3' \nfor sports type '4' ";
    std::cin >> k;
    if (k == 1) {
      int temp{animal()};
      points = points + temp;
      std::cout << "You got " << temp << " points this round. You are currently on " << points << " points\n";
    }
    if (k == 2) {
      int temp{country()};
      points = points + temp;
      std::cout << "You got " << temp << " points this round. You are currently on " << points << " points\n";
    }
    if (k == 3) {
      int temp{food()};
      points = points + temp;
      std::cout << "You got " << temp << " points this round. You are currently on " << points << " points\n";
    }
    if (k == 4) {
      int temp{sport()};
      points = points + temp;
      std::cout << "You got " << temp << " points this round. You are currently on " << points << " points\n";
    }

  }
std::string::size_type sz;
  int rec =std::stoi(sol2.at(1),&sz);
  if (points>rec){
    std::string name;
    std::cout<<"Congrats! You have beat the high score! Please enter your name:";
    std::cin>>name;
      std::ofstream ofile;
      ofile.open("highscore.txt",std::ofstream::out|std::ofstream::trunc);
      ofile<<name<<" "<<points;
      ofile.close();}
      else{
        std::cout << "Congrats! You have " << points << " points!";
      }


  return 0;


}