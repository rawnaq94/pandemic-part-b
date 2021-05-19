#pragma once
#include <iostream>
#include "Player.hpp"


namespace pandemic
{
    class Dispatcher : public Player
    {
        public:
        Dispatcher(pandemic::Board& board , pandemic::City city);
        Player& fly_direct(City _city) 
        {
                if(city == _city)
                {
                         throw std::out_of_range{"Error!! cannot fly from city to it self\n"};
                }
                
                if(board.node(city).getResearch_station()==false)
                {
                        Player::fly_direct(_city);
                }
                city = _city;
                return *this;
        }
        
        std::string role()
        {
                return "Dispatcher";
        }
};
}
