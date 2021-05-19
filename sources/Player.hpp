#pragma once
#include <iostream>
#include "Board.hpp"




namespace pandemic
{
    class Player
    {
        
      protected :
            Board& board ;
            City city;
            std::list<pandemic::City> cards;
          
        public:
            Player(Board& board , City city);
            virtual Player& drive(City _city1);
            virtual Player& fly_direct(City _city1);
            virtual Player& fly_charter(City _city1);
            virtual Player& fly_shuttle(City _city1);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            virtual Player& treat( City _city1);
            bool has_card(City _city1);
            virtual std::string role();
            Player& take_card(City _city1);
           

    };
}
