# CATapult
## 1. Description
CATapult is a game for two players, which were created as my OOP course work.The main idea is a contest of two cats, that have capability to procure weapons with different power. This power you can buy by the coins for your character. There is free and weak weapon as well, you haven't to buy these. If you start the game, you'll notice that health score is coming down. You should take of the plane to stop this. In air cats are more safety than on the ground(but try do not leave the map, it's also dangerous). To choose plane or to buy weapon you should come with your character to their own home door and you'll get a desirable cat's menu. Also try do not die after your partner death, cause you can get a draw. Sounds and music in the game were chosen bona fides to make some mood. I hope you'll like it. By the way, the code for this were typed by using SFML library, so there are some subtleties for getting started. Check it in the following paragraph.
## 2. Manual
To start tha game you need have Linux operating system and SFML library, and, of course, g++ compiler, since the game created by the C++ programing language. If the version of SFML that you want to install is available in the official repository, then install it using your package manager. For example, on Debian you would do:

` sudo apt-get install libsfml-dev `

If you have problems with downloading, check this link: [SFML and Linux](https://www.sfml-dev.org/tutorials/2.5/start-linux.php). If everything is okay and you have an SFML and a g++ compiler on your Linux core system, just launch build.sh file and enjoy the game, but in case you installed SFML to a non-standard path, you'll need to tell the compiler where to find the SFML headers. Also go to preceding link for help.
## 3. How to play
You have such options for every Cat charachter:

Ground:
  * leftward & rihtward movement
  * jump
  * shooting with free and weak bullets
  * if you stand near house door:
    * scrooling options
    * choose an option
    
Air:
  * clockwise movement
  * counterclockwise movement
  * scrolling to choose desirble weapon
  * shooting
  * catapult

To remind you of all those options and keyword buttons for them, you get list before each game(you can skip it by space).
## 4. What awaits you
Here are some screenshots from the game.

![alt](/Introduce_pctrs/img3.png)
------
![alt](/Introduce_pctrs/img1.png)
------
![alt](/Introduce_pctrs/img2.png)
