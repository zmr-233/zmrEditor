#include <SFML/Graphics.hpp>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<iostream>
#include"config.h"
int main()
{
    using std::cout,std::cin,std::endl,std::setw;
    std::vector<sf::VideoMode> vmode(sf::VideoMode::getFullscreenModes());
    int i=0;
    std::cout << vmode.size() << std::endl;
    std::for_each(vmode.begin(),vmode.end(),[&i](sf::VideoMode& vm){
        std::cout << std::setw(4)<< i++ << ":" << std::setw(4) << vm.width 
        << " " <<std::setw(4)<< vm.height << " " << std::setw(2) << vm.bitsPerPixel;
        i % 2 == 0 ? std::cout << std::endl : std::cout << "    ";
    });
    #ifdef DEB
    i = 180;
    #else
    cin >> i;
    #endif
    sf::RenderWindow baseWin(vmode[i],"basWin",sf::Style::Default);
    baseWin.setVerticalSyncEnabled(false);
    sf::Texture sp1_t;
    sf::CircleShape sp1;
    sp1.setTexture(&sp1_t);
    if(!sp1_t.loadFromFile("./assets/texture1.png"))
        abort();
    while(baseWin.isOpen())
    {
        sf::Event event;
        while(baseWin.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                baseWin.close();
        }
        baseWin.clear(sf::Color::Cyan);
        baseWin.draw(sp1);
        baseWin.display();
    }
    getchar();
    getchar();

}
