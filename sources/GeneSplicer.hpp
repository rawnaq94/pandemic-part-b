#pragma once
#include <iostream>
#include "Player.hpp"

namespace pandemic
{
    class GeneSplicer : public Player
    {
    
        public:
         GeneSplicer(pandemic::Board& board , pandemic::City city);
        Player& discover_cure(Color color)
        {
            int a =0;
            if(color == Color::Black) 
            {a=0;}
            else if(color == Color::Blue)
            {i=1;}
            else if(color == Color::Red) 
            {i=2;}
            else if(color == Color::Yellow)
            {i=3;}
            std::cout<<cards.size()<<std::endl;
            if(board.node(city).getResearch_station() == false)
            {
                throw std::out_of_range{"ERROR!! cant discover cure if you dont in city with reaserch station.\n"};
            }
            
            if(board.gerColorArr(i)==false)
            {    
                if(cards.size()<5)
                {
                    throw std::out_of_range{"ERROR!! you dont hava enogh cards.\n"};
                }
                
                std::list<pandemic::City>::iterator temp = cards.begin(); 
                int sum =0 ;
                while (sum < 5 )  // move on
                {
                    it = cards.begin();
                    while(temp!=cards.end())
                    {
                            cards.remove(*temp);
                            sum++;
                            break;
                        
                        temp++;
                    }

                }
                std::cout<<board.gerColorArr(a)<<std::endl;
                board.gerColorArr(a) = true;
                std::cout<<board.gerColorArr(a)<<std::endl;                
            }
            return *this; 
        }
        std::string role()
        {
            return "GeneSplicer";
        }
};
}
