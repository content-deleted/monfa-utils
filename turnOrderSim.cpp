#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct actor {
  string name;
  int speed;
  int ct;
  actor(string Name, int Speed, int CT) {
      name = Name;
      ct = CT;
      speed = Speed;
  }
  actor(){
    name = "";
    ct = 0;
    speed = 0;
  }
};

bool compareSpeed(actor a, actor b) { 
    return (a.speed < b.speed); 
}

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

    temp.ct = 0;

    actors.push_back(temp);
  }

  cout << "Hit enter to advance the turn count" << endl;
  
  vector<actor> actingFolks;
  int tick = 0;
  while(1) {
    for(int i = 0; i < actors.size(); i++) {
      actors[i].ct += actors[i].speed;
      if(actors[i].ct >= 100) {
        actors[i].ct -= 100;
        actingFolks.push_back(actor(actors[i].name, actors[i].ct, actors[i].speed));
      }
    }
    if(actingFolks.size() > 0) {
        cout << "Tick #" << ++tick << " passes." << endl;
        sort(actingFolks.begin(), actingFolks.end(), compareSpeed); 
        for(int i = actingFolks.size(); i > 0; i--) {
            cout << actingFolks[i-1].name << " takes a turn!" << endl;
            cin.get();
        }
    }
    actingFolks.clear();
    random_shuffle(actors.begin(), actors.end());
  }

  return 0;
}
