
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

using namespace sf;

#define BLACK_KING 1
#define BLACK_QUEEN 2
#define BLACK_BISHOP 3
#define BLACK_KNIGHT 4
#define BLACK_ROOK 5
#define BLACK_PAWN 6
#define WHITE_KING -1
#define WHITE_QUEEN -2
#define WHITE_BISHOP -3
#define WHITE_KNIGHT -4
#define WHITE_ROOK -5
#define WHITE_PAWN -6



int board[8][8] =
{
    5,4,3,2,1,3,4,5,
    6,6,6,6,6,6,6,6,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    -6,-6,-6,-6,-6,-6,-6,-6,
    -5,-4,-3,-2,-1,-3,-4,-5
};




int main(int, char** argv)
{
    bool isMove = false;
    int dx = 0, dy = 0;
    
    RenderWindow window(sf::VideoMode(1500, 1500), "megy");
    Event event;
    
    Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, tboard;
    t1.loadFromFile("/Users/chambrezoltan/Desktop/testgrap/testgraph/testgraph/images/blackking.png");
    t2.loadFromFile("/Users/chambrezoltan/Desktop/testgrap/testgraph/testgraph/images/blackqueen.png");
    t3.loadFromFile("/Users/chambrezoltan/Desktop/testgrap/testgraph/testgraph/images/blackbishop.png");
    t4.loadFromFile("/Users/chambrezoltan/Desktop/testgrap/testgraph/testgraph/images/blackknight.png");
    t5.loadFromFile("/Users/chambrezoltan/Desktop/testgrap/testgraph/testgraph/images/blackrook.png");
    t6.loadFromFile("/Users/chambrezoltan/Desktop/testgrap/testgraph/testgraph/images/blackpawn.png");
    t7.loadFromFile("/Users/chambrezoltan/Desktop/testgrap/testgraph/testgraph/images/whiteking.png");
    t8.loadFromFile("/Users/chambrezoltan/Desktop/testgrap/testgraph/testgraph/images/whitequeen.png");
    t9.loadFromFile("/Users/chambrezoltan/Desktop/testgrap/testgraph/testgraph/images/whitebishop.png");
    t10.loadFromFile("/Users/chambrezoltan/Desktop/testgrap/testgraph/testgraph/images/whiteknight.png");
    t11.loadFromFile("/Users/chambrezoltan/Desktop/testgrap/testgraph/testgraph/images/whiterook.png");
    t12.loadFromFile("/Users/chambrezoltan/Desktop/testgrap/testgraph/testgraph/images/whitepawn.png");
    tboard.loadFromFile("/Users/chambrezoltan/Desktop/testgrap/testgraph/testgraph/images/board.png");
    
    Sprite BlackKing(t1);
    Sprite BlackQueen(t2);
    Sprite BlackBishop(t3);
    Sprite BlackKnight(t4);
    Sprite BlackRook(t5);
    Sprite BlackPawn(t6);
    Sprite WhiteKing(t7);
    Sprite WhiteQueen(t8);
    Sprite WhiteBishop(t9);
    Sprite WhiteKnight(t10);
    Sprite WhiteRook(t11);
    Sprite WhitePawn(t12);
    Sprite Board(tboard);
    
    BlackKing.setTexture(t1);
    BlackQueen.setTexture(t2);
    BlackBishop.setTexture(t3);
    BlackKnight.setTexture(t4);
    BlackRook.setTexture(t5);
    BlackPawn.setTexture(t6);
    WhiteKing.setTexture(t7);
    WhiteQueen.setTexture(t8);
    WhiteBishop.setTexture(t9);
    WhiteKnight.setTexture(t10);
    WhiteRook.setTexture(t11);
    WhitePawn.setTexture(t12);
    
    BlackKing.scale(0.5, 0.5);
    BlackQueen.scale(0.5, 0.5);
    BlackBishop.scale(0.5, 0.5);
    BlackKnight.scale(0.5, 0.5);
    BlackRook.scale(0.5, 0.5);
    BlackPawn.scale(0.5, 0.5);
    WhiteKing.scale(0.5, 0.5);
    WhiteQueen.scale(0.5, 0.5);
    WhiteBishop.scale(0.5, 0.5);
    WhiteKnight.scale(0.5, 0.5);
    WhiteRook.scale(0.5, 0.5);
    WhitePawn.scale(0.5, 0.5);

    
    
    while (window.isOpen()){
        Event e;
        Vector2i pos = Mouse::getPosition(window);
        while(window.pollEvent(e)){
            if(event.type == Event::EventType::Closed)
                window.close();
            if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left)
                    if (WhiteQueen.getGlobalBounds().contains(pos.x, pos.y))
                    {
                        isMove = true;
                        dx = pos.x - WhiteQueen.getPosition().x;
                        dy = pos.y - WhiteQueen.getPosition().y;
                    }
            if (e.type == Event::MouseButtonReleased)
                if (e.key.code == Mouse::Left)
                    isMove = false;
        }
        
        if (isMove) WhiteQueen.setPosition(pos.x-dx,pos.y-dy);
//        renderWindow.clear();
//        renderWindow.draw(BlackKing);
//        renderWindow.draw(BlackQueen);
//        renderWindow.draw(BlackBishop);
//        renderWindow.draw(BlackKnight);
//        renderWindow.draw(BlackRook);
//        renderWindow.draw(BlackPawn);
//        renderWindow.draw(WhiteKing);
//        renderWindow.draw(WhiteQueen);
//        renderWindow.draw(WhiteBishop);
//        renderWindow.draw(WhiteKnight);
//        renderWindow.draw(WhiteRook);
//        renderWindow.draw(WhitePawn);
        
        window.clear();
        window.draw(Board);
        window.draw(BlackKnight);
        window.display();
    }
}
