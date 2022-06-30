#include "Winner.h"
#include <cassert>
#include <chrono>
#include <vector>

constexpr int MaxPlayers = 100;

std::tuple<int, int, int> Winner(std::stringstream& data){
    using duration_t = std::chrono::milliseconds;
    constexpr duration_t Initial = {};
    duration_t playerLoopTime[MaxPlayers] = {};

    using loop_duration_t = decltype(Initial-Initial);
    loop_duration_t playerBestLoop[MaxPlayers] = {};
    constexpr loop_duration_t InitialLoop = {};

    std::vector<int> bestPlayers;
    std::vector<loop_duration_t> bestLoops;
    while (!data.eof()) {
        int player;
        data >> player;
        char delimeter;
        data >> delimeter;
        assert(delimeter == ',');
        int m,s,ms;
        data >> m >> delimeter >> s >> delimeter >> ms;

        auto min = std::chrono::minutes(m);
        auto sec = std::chrono::seconds(s);
        auto msec = std::chrono::milliseconds(ms);
        auto time = min + sec + msec;
        if (time < playerLoopTime[player]) {
            time += std::chrono::hours(1);
        }

        if(playerLoopTime[player] != Initial){
            auto loop = time - playerLoopTime[player];
            if(loop < playerBestLoop[player] || playerBestLoop[player] == InitialLoop) {
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


