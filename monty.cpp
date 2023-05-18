#include "monty.h"  
#include <cmath> 
#include <cstdlib>
#include <ctime>
using namespace std; 

bool monty(char strategy) {    //bool function that input of game strategy
    int doors[3]= {0,0,0};     //creats an array to represent the doors, where 0 is no car, or "zonked" 
    int win_door= rand()%3;    //randomly assigns the car to a door, using index number. 
    doors[win_door]= 1;        //the winning door become "true."
    int door_selection= rand()%3; //the door the contestant selects at random 

    if (strategy== 'r'){         //selection for strategy if main function call monty with 'r'. 
        int coin_flip= rand()%2; //0 means orginal door,1 is switch. 
        if (coin_flip == 0){     
          strategy= 'k';
        }else strategy= 's';    // uses a coin flip to pick either switch or stay strategy. 
    }
 
    switch (strategy){                     //picks the strategy corresponding to the character input 
      case 'k':
        if (door_selection == win_door){    //if the contestant keep the orginal door and it has the car behind it, 
          return true;                      //they win the game! and monty(strategy) returns a true and exits to main.  
        } else return false;                //if they keep orginal door and its wrong, they lose, false is returned. 
        break;  
      case 's':                             //switch strategy
        if (door_selection == win_door){    
          return false;                     //if they switch when their orginal choice was true they have lost.
        }else return true;                  // if they switch and their orginal choice wasn't true, now they have won! 
        break;                              
      default: return false;                // if either r,k,s aren't picked then monty(strategy) returns a false. 
    }

  return true;
}

int monty ( char strategy, int n_games){   //int function that takes the strategy input and runs its a number of times
  int n_wins=0;                            //creates counter for number of wins. 
  for( int i=0; i< n_games; i++){         
    if (monty(strategy) == true){
      n_wins++; 
    }  // for loop that calls the bool monty function to run the game an n number of times, and keeps a counter for wins.
  }
  return n_wins;     // int monty function will return the number of wins to the calling function. 
}
