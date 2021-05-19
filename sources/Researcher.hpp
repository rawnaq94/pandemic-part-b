#pragma once
#include <iostream>
#include "Player.hpp"


namespace pandemic
{
    class Researcher : public Player
    {
    
         public:
        Researcher(pandemic::Board& board , pandemic::City city);
    Player& discover_cure(Color color)
    {
        int a =0;
        if(color == Color::Black)
        {a=0;}
        else if(color == Color::Blue) 
        {a=1;}
        else if(color == Color::Red)
        {a=2;}
        else if(color == Color::Yellow)
        {a=3;}
        
        if(board.gerColorArr(a)==false)
        {
            int sum = 0;
            City cityColorArr[5];
            std::list<pandemic::City>::iterator temp = cards.begin();
            while (temp!=cards.end() && sum < 5) // move on 
            {
                if(board.node(*temp).getColor() ==  color) 
                {
                    cityColorArr[sum] = *temp;
                    sum++;
                }
                temp++;

            }
            if(sum < 5)
            {
                throw std::out_of_range{"ERROR!! you dont hava enoght cards in this color of desieas\n"};

            }
            if(sum == 5)
            {
                temp = cards.begin();
                sum =0 ;
                while (sum < 5 )  // move on 
                {
                    temp = cards.begin();
                    while(temp!=cards.end())
                    {
                        if(*temp  ==  cityColorArr[sum]) { 
                            cards.remove(cityColorArr[sum]);
                            sum++;
                            break;
                        }   
                        temp++;
                    }

                }
                board.gerColorArr(a) = true;
                
            }
        }
        return *this;
    }
    std::string role(){
        return "Researcher";
    }


};
}
