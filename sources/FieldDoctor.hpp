#pragma once
#include <iostream>
#include "Player.hpp"


namespace pandemic
{
    class FieldDoctor : public Player
    {
    
            public:
                FieldDoctor(pandemic::Board& board , pandemic::City city);
        Player& treat(City _city)
        {
        if(city !=_city && !board.node(city).is_nib(_city))
        {
            throw std::out_of_range{"ERROR!! FieldDoctor can treat only in nib city\n"};
        }
        
        if( board.node(_city).get_disease_cubes() == 0)
        {
            throw std::out_of_range{"ERROR!! desiese level is alredy 0\n"};
        }
        
        Color cityColor = board.node(city).getColor();
        bool discoverCure = false;
        if(cityColor == Color::Black &&board.gerColorArr(0) == true)
        {
        discoverCure = true;
        }
        else if(cityColor == Color::Blue && board.gerColorArr(1) == true)
        {
        discoverCure = true;
        }
        else if(cityColor == Color::Red && board.gerColorArr(2) == true) 
        {
        discoverCure = true;
        }
        else if(cityColor == Color::Yellow && board.gerColorArr(3) == true)
        {
        discoverCure = true;
        }

        if(discoverCure)
        {
            board.node(_city).get_disease_cubes() = 0;
            return *this;
        }
        board.node(_city).get_disease_cubes() = board.node(_city).get_disease_cubes()-1;    
        return *this;
    }

    std::string role()
    {
        return "FieldDoctor";
    }
};
}
