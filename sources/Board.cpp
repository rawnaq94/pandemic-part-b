#include "Board.hpp"
#include <iterator>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;



const int numOfCity=48; // num of countries - does not change
namespace pandemic
{
    
    bool NodeCity::is_nib(pandemic::City city)
    {
        std::list<pandemic::City>::iterator temp=city1.begin();
        while (temp!=city1.end())
        {
            if(*temp ==  city)
            {
              return true;
            }
            temp++;
        }
        return false;
    }
  
    void Board::initBoard()
    {
      // Loading yellow/red/black/blue cities to the board.
    board.insert ( std::pair<pandemic::City,NodeCity>(City::Bogota,NodeCity(City::Bogota, Color::Yellow, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires})) );
    board.insert (std::pair<pandemic::City,NodeCity>(City::BuenosAires,NodeCity(City::BuenosAires, Color::Yellow,{City::Bogota, City::SaoPaulo})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Johannesburg, NodeCity(City::Johannesburg, Color::Yellow, {City::Kinshasa, City::Khartoum})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Khartoum, NodeCity(City::Khartoum, Color::Yellow, {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Kinshasa, NodeCity(City::Kinshasa, Color::Yellow, {City::Lagos, City::Khartoum, City::Johannesburg})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Lagos, NodeCity(City::Lagos, Color::Yellow,{City::SaoPaulo, City::Khartoum, City::Kinshasa})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Lima,  NodeCity(City::Lima, Color::Yellow,{City::MexicoCity, City::Bogota, City::Santiago})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::LosAngeles,  NodeCity(City::LosAngeles, Color::Yellow, {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::MexicoCity,  NodeCity(City::MexicoCity, Color::Yellow,{City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Miami,  NodeCity(City::Miami, Color::Yellow, {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Santiago,  NodeCity(City::Santiago, Color::Yellow,{City::Lima})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::SaoPaulo,  NodeCity(City::SaoPaulo, Color::Yellow, {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Algiers,  NodeCity(City::Algiers, Color::Black,{City::Paris, City::Istanbul, City::Cairo, City::Madrid})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Baghdad,  NodeCity(City::Baghdad, Color::Black, {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Cairo,  NodeCity(City::Cairo, Color::Black,{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Chennai,  NodeCity(City::Chennai, Color::Black, {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Delhi,  NodeCity(City::Delhi, Color::Black, {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Istanbul, NodeCity(City::Istanbul, Color::Black, {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Karachi, NodeCity(City::Karachi, Color::Black,{City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Kolkata, NodeCity(City::Kolkata, Color::Black,{City::Delhi, City::Chennai, City::Bangkok, City::HongKong})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Moscow, NodeCity(City::Moscow, Color::Black, {City::StPetersburg, City::Istanbul, City::Tehran})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Mumbai, NodeCity(City::Mumbai, Color::Black, {City::Karachi, City::Delhi, City::Chennai})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Riyadh, NodeCity(City::Riyadh, Color::Black, {City::Baghdad, City::Cairo, City::Karachi})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Tehran, NodeCity(City::Tehran, Color::Black, {City::Baghdad, City::Moscow, City::Karachi, City::Delhi})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Beijing, NodeCity(City::Beijing, Color::Red, {City::Shanghai, City::Seoul})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::HongKong, NodeCity(City::HongKong, Color::Red, {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Tokyo, NodeCity(City::Tokyo, Color::Red, {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Seoul, NodeCity(City::Seoul, Color::Red,  {City::Beijing, City::Shanghai, City::Tokyo})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Shanghai, NodeCity(City::Shanghai, Color::Red,   {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Taipei, NodeCity(City::Taipei, Color::Red, {City::Shanghai, City::HongKong, City::Osaka, City::Manila})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Sydney, NodeCity(City::Sydney, Color::Red, {City::Jakarta, City::Manila, City::LosAngeles})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Jakarta, NodeCity(City::Jakarta, Color::Red,{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Manila, NodeCity(City::Manila, Color::Red,  {City::HongKong,City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Osaka, NodeCity(City::Osaka, Color::Red, {City::Taipei, City::Tokyo})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::HoChiMinhCity, NodeCity(City::HoChiMinhCity, Color::Red, {City::Jakarta, City::Bangkok, City::HongKong, City::Manila})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Bangkok, NodeCity(City::Bangkok, Color::Red, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Atlanta, NodeCity(City::Atlanta, Color::Blue, {City::Chicago, City::Miami, City::Washington})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Chicago, NodeCity(City::Chicago, Color::Blue, {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Essen, NodeCity(City::Essen, Color::Blue,  {City::London, City::Paris, City::Milan, City::StPetersburg})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::London, NodeCity(City::London, Color::Blue, {City::NewYork, City::Madrid, City::Essen, City::Paris})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Madrid, NodeCity(City::Madrid, Color::Blue, {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Milan, NodeCity(City::Milan, Color::Blue,  {City::Essen, City::Paris, City::Istanbul})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Montreal, NodeCity(City::Montreal, Color::Blue, {City::Chicago, City::Washington, City::NewYork})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::NewYork, NodeCity(City::NewYork, Color::Blue,  {City::Montreal, City::Washington, City::London, City::Madrid})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Paris, NodeCity(City::Paris, Color::Blue, {City::Algiers, City::Essen, City::Madrid, City::Milan, City::London})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::SanFrancisco, NodeCity(City::SanFrancisco, Color::Blue, {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::StPetersburg, NodeCity(City::StPetersburg, Color::Blue, {City::Essen, City::Istanbul, City::Moscow})));
    board.insert (std::pair<pandemic::City,NodeCity>(City::Washington, NodeCity(City::Washington, Color::Blue, {City::Atlanta, City::NewYork, City::Montreal, City::Miami})));
    }

    int& Board::operator[](pandemic::City city)
    {
        return this->board.at(city).get_disease_cubes();
    }


    std::ostream& operator<< (std::ostream& os, const Board& c)
    {
        return os;
    }
  
  
    bool Board::is_clean()
    {
        map<pandemic::City,pandemic::NodeCity>::iterator temp=this->board.begin();
        int a =0;
      
        while (temp!=board.end() && a < numOfCity)
        {
            if(temp->second.get_disease_cubes() != 0)
            {
              return false;
            }
            temp++;
            a++;
        }
        return true;
    }
  
    void Board::remove_cures()
    {
        for(int i =0 ; i < 4 ; i++)
        {
            gerColorArr(i) = false;
        }

    }

}
