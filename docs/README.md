# Documentation for Solitary Battleship

This is the documentation for my final project

## Solitary Battleship
The project I would like to create is a solo battleship, 
a twist on the popular 2-player game.

###Description
In this game the user will not have their own ships, and will 
instead have try to call the coordinates of the computer's 
ships, which will be placed randomly. 

If the user is able to sink all the ships in a certain number of turns, they will 
win, if not they will lose and all the ships will be revealed.

###Getting Started
####Dependencies
- Cinder
    - Only for Windows Users
        - Download this version of Visual Studio Code: 
        [Visual Studio](https://my.visualstudio.com/Downloads?q=visual%20studio%202015&wt.mc_id=o%7Emsft%7Evscom%7Eolder-downloads)
    - Downloading Cinder:
        - [Cinder](https://libcinder.org/download)
        - Put this version in a folder and name it ~/Cinder
        - Open the ~/Cinder folder in CLion and click the green build button. 
        This will build libcinder. You only need to do this once per machine.
        - Create a directory, say my-projects in ~/Cinder.
        - Here you will create your project.
        
- Cinder-Block Notification Library
  - Clone your forked version of the Cinder Block into 
  ${CINDER_PATH}/blocks/<name-of-cinder-block-repo> using the 
  exact same name as the repo on GitHub. Type [Cinder-Block Notification](https://github.com/redpaperheart/Cinder-Notifications.git) 
  as the URL, and ${CINDER_PATH}/blocks/Cinder-Notifications as the directory. 
  Then click the Clone button and open the repo in a new window.
  - Place the Notification.cpp and the NotificationManager.cpp at the
  same level as your battleship directory
 
 ####Controls
 
- Here is how to select a tile

 Keys | Action
 ------------ | -------------
 "a1" | Tile Changes to a **Hit** or a **Miss**

- Here is how to reveal and hide where the ships are

 Keys | Action
 ------------ | -------------
 Up Arrow | Ships Revealed
 Down Arrow | Ships Hidden