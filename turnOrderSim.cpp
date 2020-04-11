#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct actor {
  string name;
  int speed;
  int ct;
};

int main ()
{
  vector<actor> actors;
  cout << "Enter your characters and their speeds" << endl;
  cout << "Enter DONE when complete" << endl;
  
  while(1) {
    actor temp;
    cout << "Actor Name: ";
    cin >> temp.name;
    if(temp.name == "DONE") break;
    cout << "Actor Speed: ";
    cin >> temp.speed;

    temp.ct = temp.speed;

    actors.push_back(temp);
  }

  cout << "Hit enter to advance the turn count" << endl;
    
  int tick = 0;
  while(1) {
    cout << "Tick #" << ++tick << " passes." << endl;

    for(int i = 0; i < actors.size(); i++) {
      if(--actors[i].ct == 0) {
        actors[i].ct = actors[i].speed;
        cout << actors[i].name << " takes a turn!" << endl;
        cin.get();
      }
    }
    
    random_shuffle(actors.begin(), actors.end());
  }

  return 0;
}