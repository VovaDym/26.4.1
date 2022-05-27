#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <map>


class Player
{
    bool isPlay = false;
    std::string playingTrack = "";
    std::map <std::string, int> commands{ {"play", 0}, {"pause", 1}, {"stop", 2},
                                        {"next", 3}, {"exit", 4} };

public:
    void getTrackInfo()
    {
        for (auto it = tracks.cbegin(); it != tracks.cend(); ++it)
        {
            std::cout << it->first << std::endl;
        }
    }
    void play()
    {
        if (!isPlay)
        {
            std::string name;
            std::cout << "Enter track's name: " << std::endl;
            std::cin >> name;
            std::map <std::string, Track>::iterator itf = tracks.find(name);
            if (itf != tracks.end())
            {
                std::string trackName = itf->first;
                std::tm dateTrackPrint = itf->second.getDate();
                int durationPrint = itf->second.getDuration();
                playingTrack = trackName;
                isPlay = true;
            }
            else
            {
                std::cout << "Track: " << name << " not found!" << std::endl << std::endl;
            }
        }
    }
    void pause()
    {
        if (isPlay)
        {

            std::cout << " <<" << playingTrack << ">> paused " << std::endl << std::endl;
            isPlay = false;
        }
    }

    void next()
    {
        std::map <std::string, Track>::iterator itf = tracks.find(randTrack());
        std::string trackName = itf->first;
        std::tm dateTrackPrint = itf->second.getDate();
        int durationPrint = itf->second.getDuration();
        playingTrack = trackName;
        isPlay = true;
    }

    void playingTrackInfo()
    {
        std::map <std::string, Track>::iterator itf = tracks.find(playingTrack);
        if (itf != tracks.end())
        {
            std::string trackName = itf->first;
            std::tm dateTrackPrint = itf->second.getDate();
            int durationPrint = itf->second.getDuration();

            std::cout << " Track:     " << trackName << std::endl;
            std::cout << "  date:     " << dateTrackPrint.tm_mday << "."
                << dateTrackPrint.tm_mon << "." << dateTrackPrint.tm_year << std::endl;
            std::cout << "  duration: " << durationPrint << std::endl << std::endl;
        }
    }

    std::string randTrack()
    {
        std::srand(std::time(nullptr));
        std::string randTrack;
        do
        {
            uint16_t randNo = std::rand() % (tracks.size());
            std::map <std::string, Track>::iterator itn = std::next(tracks.begin(), randNo);
            randTrack = itn->first;
        } while (playingTrack == randTrack);
        return randTrack;
    }

    void stop()
    {
        if (isPlay)
        {
            std::cout << " <<" << playingTrack << " stopped>> " << std::endl << std::endl;
            isPlay = false;
        }
    }
    int chosenCommand()
    {
        std::cout << "Available commands:" << std::endl;
        for (const auto& c : commands)
        {
            std::cout << "  " << c.first << ";" << std::endl;
        }

        std::string action;
        std::map <std::string, int>::iterator itf;
        do
        {
            std::cout << std::endl << "Enter command for action: ";
            std::cin >> action;
            itf = commands.find(action);
            if (itf == commands.end())
            {
                std::cout << "Incorrect command. Try again" << std::endl;
            }
        } while (itf == commands.end());

        system("cls");
        return itf->second;
    }

private:
    class Track
    {
        std::string nameTrack;
        std::tm date;
        int durationTrack;
    public:
        Track(int d, int m, int y, int durationTrack)
        {
            this->date.tm_mday = d;
            this->date.tm_mon = m;
            this->date.tm_year = y;
            this->durationTrack = durationTrack;
        }

        int getDuration()
        {
            return durationTrack;
        }
        std::string getName()
        {
            return nameTrack;
        }
        std::tm getDate()
        {
            return date;
        }
    };
    Track track1 = { 22,11,1999,192 };
    Track track2 = { 23,10,1998,194 };
    Track track3 = { 1,11,2021,170 };
    Track track4 = { 3,7,1995,160 };
    std::map <std::string, Track> tracks =
    {
        {"Artist1",track1},
        {"Artist2",track2},
        {"Artist3",track3},
        {"Artist4",track4}
    };
};
