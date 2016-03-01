
======================================================
C++ Term 2 Mini Project : Ecosystem (Work in Progress)
======================================================
Tues 29 Feb
by Uyen Le (tle004@gold.ac.uk)

Git repo: https://github.com/uyenle57/cppUyen2 


** Description -------------------------------------------
This is a visual simulation of the Ecosystem.
Organisms are: worms, leeches, mosquitoes.
Animals are: frogs, squids, flock of small fish, big fish.


** How It Works ------------------------------------------
All organisms and animals eat and swim.
Organisms don't mate and eat. Only die when eaten (Destructor call).

Animals don't eat each other, only eat Organisms. Die when run out of organisms to eat (call Destructor).
 
Organisms' Destructor is called when it is eaten (and free memory for new organisms to be added by User).
Animals' sign of hunger and death shown through change of colour:
 - Hungry = green
 - Dying = red
 - Dead = fade away
 

** Gameplay ----------------------------------------------
- Add new Organisms to feed the Animals (keypress)
- If not, all Animals will die and Organisms will takeover the ecosystem.


** TODO --------------------------------------------------
- Improve movement for Worms and Leeches
- Collision detection
- User adds new Organisms with keypress
- Create Animal derived classes

