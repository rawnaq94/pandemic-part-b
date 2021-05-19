#pragma once
#include <iostream>
#include "Player.hpp"


namespace pandemic
{
    class Medic : public Player
    {
    
        public:
       Medic(pandemic::Board &board , pandemic::City city);
       Player& treat(City _city)
        {
        if(_city != city)
        {
            throw std::out_of_range{"ERROR!! this city need to be === to other city\n"};
        }
        
        if( board.node(_city).get_disease_cubes() == 0)
        {
            throw std::out_of_range{"ERROR!! desiese level is alredy 0\n"};
        }
 
        board.node(_city).get_disease_cubes() = 0;
        return *this;
    }
    
       Player& drive(City _city)
       { 
        Color cityColor = board.node(_city).getColor();
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

        Player::drive(_city);
        if(discoverCure)
        {
            board.node(_city).get_disease_cubes() = 0;
        }
        return *this;
    }
    
    Player& fly_direct(City _city)
    {
        Color cityColor = board.node(_city).getColor();
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
        Player::fly_direct(_city);
        if(discoverCure)
        {
            board.node(_city).get_disease_cubes() = 0;
            
        }
        return *this;
    }
    
       Player& fly_charter(City _city)
       {
        bool discoverCure = false;
        Color cityColor = board.node(c).getColor();
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
        Player::fly_charter(_city);
        if(discoverCure)
        {
            board.node(_city).get_disease_cubes() = 0; 
        }
        return *this;
    }
    
       Player& fly_shuttle(City _city)
       {
        bool discoverCure = false;
        Color cityColor = board.node(_city).getColor();
        if(cityColor == Color::Black && board.gerColorArr(0) == true) 
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
        Player::fly_shuttle(_city);
        if(discoverCure)
        {
            board.node(_city).get_disease_cubes() = 0;
            
        }
        return *this;
    }
    std::string role()
    {
        return "Medic";
     }

};
}
