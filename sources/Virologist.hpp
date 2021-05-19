#pragma once
#include <iostream>
#include "Player.hpp"


namespace pandemic
{
    class Virologist : public Player
    {
    
        public:
       Virologist(pandemic::Board& board , pandemic::City city);
        Player& treat(City _city1)
        {
        if(city !=_city1 &&!has_card(_city1))
        {
            throw std::out_of_range{"ERROR!! Virologist cant treat on this place - you dont hava fit card!!.\n"};
        }
        
        if( board.node(_city1).get_disease_cubes() == 0)
        {
            throw std::out_of_range{"ERROR!! desiese level is alredy 0\n"};

        }
        
        if(city == _city1)
        {
            Player::treat(_city1);
            return *this;
        }
        
        Color cityColor = board.node(city).getColor();
        bool discoverCure = false;
        if(cityColor == Color::Black && board.gerColorArr(0) == true) 
        {discoverCure = true;}
        else if(cityColor == Color::Blue && board.gerColorArr(1) == true) 
        {discoverCure = true;}
        else if(cityColor == Color::Red &&board.gerColorArr(2) == true)
        {discoverCure = true;}
        else if(cityColor == Color::Yellow && board.gerColorArr(3) == true)
        {discoverCure = true;}

        if(discoverCure)
        {
            board.node(_city1).get_disease_cubes() = 0;
            return *this;

        }
        board.node(_city1).get_disease_cubes() = board.node(_city1).get_disease_cubes()-1;
        cards.remove(_city1);
        return *this;
    }

    std::string role()
    {
        return "Virologist";
    }

};
}
