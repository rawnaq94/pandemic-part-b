#pragma once
#include <iostream>
#include "Player.hpp"


namespace pandemic
{
    class OperationsExpert : public Player
    {
    
        public:
           OperationsExpert(pandemic::Board& board , pandemic::City city);
            Player& build()
            {
                if(board.node(city).getResearch_station())
                {
                        return *this;
                }
                
                board.node(city).getResearch_station() = true;
                return *this;
        }
        std::string role()
        {
                return "OperationsExpert";
        }


};
}
