#include "Winner.h"
#include <chrono>
#include <vector>

constexpr int MaxPlayers = 100;

std::tuple<int, int, int> Winner(std::stringstream& data){
    std::vector<int> bestPlayers;
    std::vector<double> bestLoops;
    time_t playerLoopTime[MaxPlayers];
    double playerBestLoop[MaxPlayers];

    while (!data.eof()) {
        int player;
        data >> player;
        char delimeter;
        data >> delimeter;
        assert(delimeter == ',');
        time_t time;
        data >> time;
        
        if(playerLoopTime[player]){
            auto loop = difftime(time, playerLoopTime[player]);
            if(loop < playerBestLoop[player]){
                playerBestLoop[player] = loop;
                if(bestLoops.size() == 0 || loop < bestLoops[0]){
                    bestLoops.insert(bestLoops.begin(), loop);
                    bestPlayers.insert(bestPlayers.begin(), player);
                } else if(bestLoops.size() == 1 || (loop < bestLoops[1])){
                    bestLoops.insert(bestLoops.begin()+1, loop);
                    bestPlayers.insert(bestPlayers.begin()+1, player);
                } else if(bestLoops.size() == 2 || (loop < bestLoops[2])){
                    bestLoops.insert(bestLoops.begin()+2, loop);
                    bestPlayers.insert(bestPlayers.begin()+2, player);
                }
                if(bestLoops.size() > 3){
                    bestLoops.resize(3);
                    bestPlayers.resize(3);
                }
            }
        }
        playerLoopTime[player] = time;
    }
    assert(bestPlayers.size()==3);
    return {bestPlayers[0], bestPlayers[1], bestPlayers[2]};
}


