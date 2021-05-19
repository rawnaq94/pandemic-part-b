#include "Player.hpp"
#include <iostream>
#include <array>
using namespace std;



const int need5cards = 5; 
namespace pandemic
{

    Player::Player(Board& _board , City _city) : board(_board),city(_city)
    {
     
     }              

    Player& Player::drive(City _city1) 
    {
        if(!board.node(city).is_nib(_city1))
        {
            throw std::out_of_range{"ERROR!! cant drive to this place.\n"};
            
        }
        city = _city1;
        return *this;
    }
            
    Player& Player::fly_direct(City _city1) 
    {
        if(!has_card(_city1))
        {
            throw std::out_of_range{"ERROR!! cant fly_direct to this place - need to take fit card.\n"};
        }
        std::list<pandemic::City>::iterator temp = cards.begin();
        while (temp!=cards.end())
        {
            if(*temp ==  _city1)
            {
                city = _city1;
                cards.remove(_city1);
                break;
            }
            temp++;
        }

        return *this;
    }
    Player& Player::fly_charter(City _city1)
    {
        if(!has_card(city))
        {
            
            throw std::out_of_range{"ERROR!! cant fly_charter to this place - need to take fit card.\n"};
        }
        std::list<pandemic::City>::iterator temp = cards.begin();
        while (temp!=cards.end())
        {
            if(*temp ==  city) 
            {
                cards.remove(city);
                city = _city1;
                break;
            }
            temp++;
        }

        return *this;
    }
    Player& Player::fly_shuttle(City _city1)
    {
        if(city == _city1)
        {
            throw std::out_of_range{"ERROR!! cant fly_shuttle to this place -cannot fly from city to it self!!.\n"};

        }
        if(!board.node(city).getResearch_station())
        {
            throw std::out_of_range{"ERROR!! cant fly_shuttle to this place - need reaearch station in current city!!.\n"};
        }
        if(!board.node(_city1).getResearch_station())
        {
            throw std::out_of_range{"ERROR!! cant fly_shuttle to this place - need reaearch station in fly city!!.\n"};
        }
        city = _city1;
        return *this;
    }
    Player& Player::build()
    {
        if(board.node(city).getResearch_station())
        {
            return *this;

        }
        if(!has_card(city))
        {
            throw std::out_of_range{"ERROR!! cant build on this place - you dont hava fit card!!.\n"};

        }
        std::list<pandemic::City>::iterator temp = cards.begin(); 
        while (temp!=cards.end()) // move on 
        {
            if(*temp ==  city) {
                cards.remove(city); // remove
                board.node(city).getResearch_station() = true;
                break;
            }
            temp++;
        } 
        return *this;
    }
    Player& Player::discover_cure(Color color)
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
       
        if(!board.node(city).getResearch_station())
        {
            throw std::out_of_range{"ERROR!! cant discover cure if you dont in city with reaserch station.\n"};
        }
        if(!board.gerColorArr(i))
        {
            uint sum = 0;
            // City cityColorArr[5];
            array<City,need5cards> cityColorArr{};
            std::list<pandemic::City>::iterator temp = cards.begin();
            while (temp!=cards.end() && sum < need5cards) // move on 
            {
                if(board.node(*temp).getColor() ==  color)
                { 
                    cityColorArr.at(sum) = *temp;
                    sum++;
                }
                temp++;

            }
            if(sum < need5cards)
            {
                throw std::out_of_range{"ERROR!! you dont hava enoght cards in this color of desieas\n"};

            }
            if(sum == need5cards)
            {
                temp = cards.begin();
                sum =0 ;
                while (sum < need5cards)  // move on 
                {
                    it = cards.begin();
                    while(temp!=cards.end())
                    {
                        if(*temp  ==  cityColorArr.at(sum))
                        { 
                            cards.remove(cityColorArr.at(sum));
                            sum++;
                            break;

                        }
                        
                        temp++;
                    }

                }
                board.gerColorArr(i) = true;

                
            }
        }
        return *this;
    }
    Player& Player::treat(City _city1)
    {
        if(_city1 != city)
        {
            throw std::out_of_range{"ERROR!! this city need to be == to other city\n"};

        }
        if( board.node(_city1).get_disease_cubes() == 0)
        {
            throw std::out_of_range{"ERROR!! desiese level is alredy 0\n"};

        }
        Color cityColor = board.node(city).getColor();
        bool discoverCure = false;
        if(cityColor == Color::Black &&board.gerColorArr(0))
        {
         discoverCure = true;
        }
        if(cityColor == Color::Blue && board.gerColorArr(1))
        {
          discoverCure = true;
        }
        if(cityColor == Color::Red &&board.gerColorArr(2)) 
        {
          discoverCure = true;
        }
        if(cityColor == Color::Yellow &&board.gerColorArr(3))
        {
           discoverCure = true;
        }

        if(discoverCure)
        {
            board.node(_city1).get_disease_cubes() = 0;
            return *this;

        }
        board.node(_city1).get_disease_cubes() = board.node(_city1).get_disease_cubes()-1;
        return *this;
    }

    std::string Player::role()
    {
        return "Player";
    }
    Player& Player::take_card(City _city1)
    {
        cards.push_back(_city1);
        return *this;
    }


    bool Player::has_card(City _city1)
    {
        std::list<pandemic::City>::iterator temp = cards.begin();
        while (temp!=cards.end())
        {
            if(*temp ==  _city)
            {
              return true;
            }
            temp++;
        }
        return false;
    }


   
}
