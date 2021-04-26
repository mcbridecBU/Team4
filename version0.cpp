#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include <stdlib.h>
#include<string>
typedef std::vector<std::string> category;
std::vector <category> animals{
  {"Gorilla","Has Fur","Large","Bipedal"},
  {"Elephant","Large","Roams in Herds","Trunks"},
  {"Tiger","Predator","Patterned","Big Cat"},
  {"Zebra","Has Fur","Patterned","Cannot be domesticated"},
  {"Leopard","Predator","Patterned","Small cat"},
  {"Camel","Domesticated","3 sets of eyelids","Hump"},
  {"Dog","Has Fur","Domesticated","Trainable"},
  {"Chicken","Domesticated","Bipedal","Feathered"},
  {"Owl","Predator","Feathered","Who?"}
};
std::vector <category> countries{
  {"Brazil","European Influence","South","Rainforest"},
  {"Australia","Unique Wildlife","Coasts","Prison"},
  {"China","East","Dynasty","Wall"},
  {"Egypt","North","Ancient Civilization","Wonder"},
  {"Peru","Exploration","Ancient Civilization","Incas"},
  {"Mexico","North","European Conquest","Aztec"},
  {"Canada","European Influence","Longest Coastline","Bilingual"},
  {"Russia","North","Diverse Climate","Vodka"},
  {"USA","Diverse Climate","Industrious","West"}
};
std::vector <category> foods{
  {"Apple","Fruit","Tree","Sweet"},
  {"Tomato","Red","Juicy","Sweet"},
  {"Steak","Cooked","Red","Animal"},
  {"Chicken","Farm","Raised","White"},
  {"Chickpea","Grown","Round","Hummus"},
  {"Avocado","Fatty","Plant","Green"},
  {"Carrot","Ground","Vegetable","Crunchy"},
  {"IceCream","Summer","Sweet","Spoon"},
  {"Hamburger","Ground","Fatty","Juicy"}
};
std::vector <category> sports{
  {"Football","American","Yards","Touchdown"},
  {"Basketball","Net","Tall","Court"},
  {"Baseball","American","Small","Fenway"},
  {"Swimming","No Ball","Fast","Wet"},
  {"Track","No Ball","Fast","Run"},
  {"Gymnastics","No Ball","Balance","Flexible"},
  {"Soccer","Ball","Real Madrid","Greatest Sport On Earth"},
  {"Cricket","Bat","Wicket","England"},
  {"Volleyball","Net","Beach","Jump"}
};
int animal(){
  srand(time(0));
  int v=rand()%9;
  int ans=10;
std::cout<<"These numbers correspond to these guesses\n1:Gorilla\n2:Elephant\n3:Tiger\n4:Zebra\n5:Leapord\n6:Camel\n7:Dog\n8:Chicken\n9:Owl\n";
  for(int i=1; i<4; i++){
if (ans==10){
std::cout<<" \nHint:"<< animals.at(v).at(i)<<"  enter answer(enter 10 for another hint)";
std::cin>>ans;
std::cout<<"\n";}
  if (ans==v+1){std::cout<< "correct\n"; break;}
if (ans!=v-1&ans!=10){std::cout<<"incorrect\n";
break;}
  }
  return 1;
}
int country(){
  srand(time(0));
  int v=rand()%9;
  int ans=10;
std::cout<<"These numbers correspond to these guesses\n1:Brazil\n2:Australia\n3:China\n4:Egypt\n5:Peru\n6:Mexico\n7:Canada\n8:Russia\n9:USA\n";
  for(int i=1; i<4; i++){
if (ans==10){
std::cout<<" \nHint:"<< countries.at(v).at(i)<<"  enter answer(enter 10 for another hint)";
std::cin>>ans;
std::cout<<"\n";}
  if (ans==v+1){std::cout<< "correct\n"; break;}
if (ans!=v-1&ans!=10){std::cout<<"incorrect\n";
break;}
  }
  return 1;
}
int food(){
  srand(time(0));
  int v=rand()%9;
  int ans=10;
std::cout<<"These numbers correspond to these guesses\n1:Apple\n2:Tomato\n3:Steak\n4:Chicken\n5:Chickpea\n6:Avocado\n7:Carrot\n8:Ice Cream\n9:Hamburger\n";
  for(int i=1; i<4; i++){
if (ans==10){
std::cout<<" \nHint:"<< foods.at(v).at(i)<<"  enter answer(enter 10 for another hint)";
std::cin>>ans;
std::cout<<"\n";}
  if (ans==v+1){std::cout<< "correct\n"; break;}
if (ans!=v-1&ans!=10){std::cout<<"incorrect\n";
break;}
  }
  return 1;
}
int sport(){
  srand(time(0));
  int v=rand()%9;
  int ans=10;
std::cout<<"These numbers correspond to these guesses\n1:Football\n2:Basketball\n3:Baseball\n4:Swimming\n5:Track\n6:Gymnastics\n7:Soccer\n8:Cricket\n9:Volleyball\n";
  for(int i=1; i<4; i++){
if (ans==10){
std::cout<<" \nHint:"<< sports.at(v).at(i)<<"  enter answer(enter 10 for another hint)";
std::cin>>ans;
std::cout<<"\n";}
  if (ans==v+1){std::cout<< "correct\n"; break;}
if (ans!=v-1&ans!=10){std::cout<<"incorrect\n";
break;}
  }
  return 1;
}
int main(){

  int k;
  std::cout << "Type in category: \nfor animals type '1'. \nfor countries type '2' \nfor food type '3' \nfor sports type '4' ";
  std::cin >> k;
  if (k==1){animal();}
  if (k==2){country();}
  if (k==3){food();}
  if (k==4){sport();}
  return 0;
  
  
}