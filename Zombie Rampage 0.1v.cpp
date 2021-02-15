#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
using namespace std;

 
int
createZombie ()
{
  
if (rand () % 67 < 10)
    
return 11;
  
 
  else
    
return rand () % 10 + 1;

}


 
int
main ()
{
  
srand (time (NULL));
  
char enter;
  
 
    // game stats
  int playerAlive = true;
  
int playerSkill = 9;
  
int playerScore = 1;
  
string playerName = "";
  
int zombieCount = 0;
  
int zombiesKilled = 0;
  
 
    // title
    cout << "Welcome to Zombies Rampage v0.1." << endl <<
    "Press the ENTER key to start playing.";
  
cin.get ();
  
 
    // player name
    cout << "Input character name your name: ";
  
cin >> playerName;
  
 
    // ask how many zombies
    cout << "How many zombies do you wanna fight? ";
  
cin >> zombieCount;
  
 
cout << "Get ready for the fight of your life, " << playerName << "!" <<
    endl;
  
 
    // main game loop
    while (playerAlive && zombiesKilled < zombieCount)
    {
      
	// create a random zombie
      int zombieSkill = createZombie ();
      
 
	// battle sequence
	if (zombieSkill > 10)
	{
	  
cout << endl <<
	    "Here comes a huge horde of zombies!! You should run away" <<
	    endl;
	
}
      
      else
	{
	  
cout << endl << "Here come the zombies! Good luck. " <<
	    zombiesKilled + 1 << endl;
	
}
      
 
cout << "Fighting and generating results..." << endl;
      
sleep (2);
      
 
	// zombie killed the player
	if (playerSkill < zombieSkill)
	{
	  
playerAlive = false;
	  
cout << "You died. Sorry better luck next time" << endl;
	
}
      
 
	// player killed the zombie
	else
	{
	  
if (playerSkill - zombieSkill > 7)
	    {
	      
cout << "You wasted the *living* hell out of the zombies!" <<
		endl;
	      
playerScore = playerScore * 2;
	    
}
	  
 
	  else if (playerSkill - zombieSkill > 5)
	    {
	      
cout <<
		"You decapitated the zombies and stepped on their heads! Wow gruesome."
		<< endl;
	      
playerScore = playerScore * 2;
	    
}
	  
 
	  else if (playerSkill - zombieSkill > 0)
	    {
	      
cout <<
		"You killed the zombie by cutting their throat and leaving them to bleed and die."
		<< endl;
	      
playerScore = playerScore * 2;
	    
}
	  
 
	  else
	    {
	      
cout <<
		"You killed the zombies, but suffered heavy and almost fatal injuries."
		<< endl;
	    
}
	  
 
zombiesKilled++;
	
}
      
 
cout << endl;
      
sleep (1);
    
}
  
 
    // end game
    if (zombiesKilled == zombieCount)
    {
      
	// victory
	cout << "You survived the gruesome ambush and retreated. GG!" << endl;
    
}
  
  else
    {
      
	// lost
	cout <<
	"You were eaten by the zombies and your brain was taken out of your skull. You instatly die."
	<< endl;
    
}
  
 
cout << "Zombies killed: " << zombiesKilled << endl;
  
cout << "Final score: " << playerScore << endl << endl;

}
