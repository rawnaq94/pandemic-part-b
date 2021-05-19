#pragma once
#include "Color.hpp"
#include "City.hpp"
#include <iostream>
#include <algorithm>
#include <map>
#include <list>


namespace pandemic
{

    class NodeCity
    {
        private:
            pandemic::City city; 
            pandemic::Color color; 
            int levelD; 
            std::list<pandemic::City> city1;
            bool Research_station; 
      
        public:
            NodeCity(pandemic::City x , pandemic::Color y ,std::list<pandemic::City> z):city(x),color(y),city1(z),levelD(0)
            {
                Research_station = false;
                levelD = 0;
            }
      
            ~NodeCity(){}
            int &get_disease_cubes()
            { 
                return levelD;
              
            }

           void set_disease_cubes( int tp) { levelD = tp;}       
            bool is_nib(pandemic::City city);
            bool &getResearch_station()
            {
                return Research_station;
            }
            void setResearch_station(bool ans)
            {
              Research_station = !Research_station;
            }
            Color getColor()
            {
                return color;
            }

    };
  
    class Board
    {
        private:
            bool clean = true;
            std::map<pandemic::City,NodeCity> board; 
            bool colorArr[4];
            void initBoard();
        public:
            Board()
            {
                initBoard();
                 for(int i =0 ; i < 4 ; i++)
                 {
                    colorArr[i] = false;
                }
            }
            
            int& operator[](pandemic::City city);
            friend std::ostream& operator<< (std::ostream& os, const Board& c);
            bool is_clean();
            void remove_cures();
            NodeCity& node(pandemic::City city)
            { 
                return board.at(city);
            }
            bool& gerColorArr(int ne)
            {
                return colorArr[ne];
            }

    };
}
