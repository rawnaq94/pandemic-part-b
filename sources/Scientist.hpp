#pragma once
#include <iostream>
#include "Player.hpp"


namespace pandemic
{
    class Scientist : public Player
    {
     private:
        int _ad;
        
        
    public:
        Scientist(pandemic::Board& board , pandemic::City city, int);
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
                if(board.node(city).getResearch_station() == false)
                {
                throw std::out_of_range{"ERROR!! cant discover cure if you dont in city with reaserch station.\n"};
                }
                if(board.gerColorArr(a)==false)
                {
                        int sum = 0;
                        City cityColorArr[_ad];
                        std::list<pandemic::City>::iterator temp = cards.begin(); 
                        while (temp!=cards.end() && sum < _ad) // move on
                        {
                                if(board.node(*temp).getColor() ==  color) 
                                {
                                cityColorArr[sum] = *temp;
                                sum++;
                                }
                                temp++;
                        }
                        
                        if(sum < _ad)
                        {
                                throw std::out_of_range{"ERROR!! you dont hava enoght cards in this color of desieas\n"};

                        }
                        
                        if(sum == _ad)
                        {
                                temp = cards.begin();
                                sum =0 ;
                                while (sum < _ad )  // move on
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
                return "Scientist";
        }


};
}
