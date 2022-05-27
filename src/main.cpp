#include <iostream>
#include <string>
#include "class.h"

int main()
{
    bool exit = false;
    Player myPlay;
    do
    {
        myPlay.playingTrackInfo();
        int command;
        command = myPlay.chosenCommand();
        myPlay.getTrackInfo();

        switch (command)
        {
        case 0:
            myPlay.play();
            break;
        case 1:
            myPlay.pause();
            break;
        case 2:
            myPlay.stop();
            break;
        case 3:
            myPlay.next();
            break;
        case 4:
            exit = true;
            break;
        default:
            std::cout << "Incorrect command. Try again!";
            break;
        }
    } while (!exit);
}



