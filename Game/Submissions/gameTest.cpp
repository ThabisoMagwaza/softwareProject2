
#include "Player.h"
#include "Enemy.h"
#include "playerBullet.h"
#include "Position.h"
#include "cannotLoadImage.h"
#include "boundRect.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <memory>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

//calculates expected next position of a bullet fired towards the center for a point
//returns rounded values
Position expectedPlayerbulletPosition(const Position& startPosition, const double& angle, const double& speed);

//advenace enemy in straight line from center
Position expectedEnemyPosition(const Position& startPosition, const double& speed, const double& angle);

Position expectedPlayerPosition(const Position& startPosition, const Position& origin, const double& speed);

//=================================== Position tests =====================================================

TEST_CASE("Position co-ordinates set correctly"){
    Position testPos(1.0,2.0);
    CHECK(((testPos.x == 1.0) && (testPos.y == 2.0)));  
}

TEST_CASE("Position equality operator returns true for equivalent positions"){
    Position testPos1(1.0,2.0);
    Position testPos2(1.0,2.0);
    
    CHECK((testPos1 == testPos2));
}

TEST_CASE("Position equality operator returns false for inequivalent positions"){
    Position testPos1(1.0,2.0);
    Position testPos2(3.0,2.0);
    
    CHECK_FALSE((testPos1 == testPos2));    
}


//=================================== Bounding rectangle Tests =====================================================

TEST_CASE("Bounding rectangle correctly set"){
    auto testPos = std::shared_ptr<Position> (new Position(3,3));
    boundRect testRect(testPos,1,2);
    
    auto vertices = testRect.getVertices();
    
    auto topLeft = (*vertices[0]); 
    Position topLeft_exp(2,1); // expected position
    
    auto topRight = (*vertices[1]); 
    Position topRight_exp(4,1);
    
    auto bottomLeft = (*vertices[2]);
    Position bottomLeft_exp(2,5);
    
    auto bottomRight = (*vertices[3]);
    Position bottomRight_exp(4,5);
    
    
    CHECK(((topLeft == topLeft_exp) && (topRight == topRight_exp) && (bottomLeft == bottomLeft_exp) && (bottomRight == bottomRight_exp)));
    
}

TEST_CASE("Bounding rectangle correctly scalable"){
    auto testPos = std::shared_ptr<Position> (new Position(3,3));
    boundRect testRect(testPos,1,2);
    
    auto factor = 0.5;
    testRect.scale(factor);
    
    auto vertices = testRect.getVertices();
    
    auto topLeft = (*vertices[0]); 
    Position topLeft_exp(2.5,2); // expected position
    
    auto topRight = (*vertices[1]); 
    Position topRight_exp(3.5,2);
    
    auto bottomLeft = (*vertices[2]);
    Position bottomLeft_exp(2.5,4);
    
    auto bottomRight = (*vertices[3]);
    Position bottomRight_exp(3.5,4);
    
    
    CHECK(((topLeft == topLeft_exp) && (topRight == topRight_exp) && (bottomLeft == bottomLeft_exp) && (bottomRight == bottomRight_exp)));
}

TEST_CASE("Bouding rectangle correctly updates after position is moved"){
    auto testPos = std::shared_ptr<Position> (new Position(3,3));
    boundRect testRect(testPos,1,2);
    
    auto xshift = 2;
    auto yshift = 3;
    auto updatedPos = std::shared_ptr<Position> (new Position(testPos->x + xshift, testPos->y + yshift));
    testRect.update(updatedPos);
    
    auto vertices = testRect.getVertices();
    
    auto topLeft = (*vertices[0]); 
    Position topLeft_exp(2 + xshift,1 + yshift); // expected position
    
    auto topRight = (*vertices[1]); 
    Position topRight_exp(4 + xshift,1 + yshift);
    
    auto bottomLeft = (*vertices[2]);
    Position bottomLeft_exp(2 + xshift,5 + yshift);
    
    auto bottomRight = (*vertices[3]);
    Position bottomRight_exp(4 + xshift,5 + yshift);
    
    
    CHECK(((topLeft == topLeft_exp) && (topRight == topRight_exp) && (bottomLeft == bottomLeft_exp) && (bottomRight == bottomRight_exp)));
}


TEST_CASE("intersecting rectangles intersect"){
    auto testPos1 = std::shared_ptr<Position> (new Position(3,3));
    boundRect testRect1(testPos1,1,2);
    
    auto testPos2 = std::shared_ptr<Position> (new Position(2,2));
    boundRect testRect2(testPos2,1,2);
    
    CHECK(testRect1.intersects(testRect2));
}

TEST_CASE("Un-intersecting rectangles don't intersect"){
    auto testPos1 = std::shared_ptr<Position> (new Position(3,3));
    boundRect testRect1(testPos1,1,2);
    
    auto testPos2 = std::shared_ptr<Position> (new Position(10,10));
    boundRect testRect2(testPos2,1,2);
    
    CHECK_FALSE(testRect1.intersects(testRect2));
}


//=================================== Player Tests =====================================================

TEST_CASE("Player starting position, angle and radius set correctly"){
    Position testPos(1,2);
    Player testPlayer(testPos,90,500);
    
    auto radius_exp = 500;
    auto angle_exp = 90;
    auto location_exp =  Position(1,2);
    
    auto playerLocation = *(testPlayer.getLocation());
    auto playerRadius = testPlayer.getRadius();
    auto playerAngle = testPlayer.getAngle();

    CHECK(((location_exp == playerLocation) && (radius_exp == playerRadius) && (angle_exp == playerAngle)));
}

TEST_CASE("Player anticlockwise rotation once correct"){
    auto radius = 500;
    auto startAngle = 90;
    
    Position testPos(100,1000);
    Player testPlayer(testPos,startAngle,radius);
    Position origin(100,100);

    testPlayer.move('r',origin,1);
    
    auto playerLocation = *(testPlayer.getLocation());
    
    double newAngle = 89; //staring angle is 90 degrees which is decremented by 1 as the angle increases clockwise
    //polar coordinates used 
    auto newPosition = Position(origin.x + (radius * cos(newAngle*(3.14/180))), origin.y + (radius * sin(newAngle *(3.14/180))));

    CHECK((playerLocation == newPosition));
}

TEST_CASE("Player clockwise rotation once correct"){
    auto radius = 500;
    auto startAngle = 90;
    
    Position testPos(100,1000);
    Player testPlayer(testPos,startAngle,radius);
    Position origin(100,100);

    testPlayer.move('l',origin,1);
    
    auto playerLocation = *(testPlayer.getLocation());
    
    double newAngle = 91; //staring angle is 90 degrees which is incremented by 1 as the angle increases clockwise
    //polar coordinates used 
    auto newPosition = Position(origin.x + (radius * cos(newAngle*(3.14/180))), origin.y + (radius * sin(newAngle *(3.14/180))));

    CHECK((playerLocation == newPosition));
}

TEST_CASE("Player anticlockwise rotation repeatedly correct"){
    auto radius = 500;
    auto startAngle = 90;
    
    Position testPos(100,1000);
    Player testPlayer(testPos,startAngle,radius);
    Position origin(100,100);
    
    
    for(auto i = 0;i<90;i++){
        testPlayer.move('r',origin,1); //rotate 90 times
    }
    
    
    auto playerLocation = *(testPlayer.getLocation());
    
    double newAngle = 0; //staring angle is 90 degrees which is incremented by 1 as the angle increases clockwise
    //polar coordinates used 
    auto newPosition = Position(origin.x + (radius * cos(newAngle*(3.14/180))), origin.y + (radius * sin(newAngle *(3.14/180))));

    CHECK((playerLocation == newPosition));
}

TEST_CASE("Player clockwise rotation repeatedly correct"){
    auto radius = 500;
    auto startAngle = 90;
    
    Position testPos(100,1000);
    Player testPlayer(testPos,startAngle,radius);
    Position origin(100,100);
    
    
    for(auto i = 0;i<90;i++){
        testPlayer.move('l',origin,1); //rotate 90 times
    }
    
    
    auto playerLocation = *(testPlayer.getLocation());
    
    double newAngle = 180; //staring angle is 90 degrees  
    auto newPosition = Position(origin.x + (radius * cos(newAngle*(3.14/180))), origin.y + (radius * sin(newAngle *(3.14/180))));

    CHECK((playerLocation == newPosition));

}


//=================================== Player bullet Tests =====================================================

TEST_CASE("Player bullet starting position, displacement and angle set correctly"){
    Position testPos(1,2);
    playerBullet testBullet(testPos,500,90);
    
    auto location_exp = Position(1,2);
    auto displacement_exp = 500;
    auto angle_exp = 90;
    
    auto bullet_location = *(testBullet.getLocation());
    auto bullet_disp = testBullet.getDisplacement();
    auto bullet_angle = testBullet.getAngle();
    
    CHECK(((bullet_location == location_exp) &&(bullet_disp == displacement_exp) && (bullet_angle = angle_exp)));
    
}

TEST_CASE("Player Bullet moves straight towards center when fired once from player's original position"){
    auto angle = 90;
    auto displacement = 500;
    auto speed = 1;
    
    Position testPos(100,1000);
    playerBullet testBullet(testPos,displacement,angle);
    
    Position origin(100,500);
    testBullet.shoot(origin,speed);
    
    auto bullet_pos = *(testBullet.getLocation());
    bullet_pos.x = round(bullet_pos.x);
    bullet_pos.y = round(bullet_pos.y);

    
    auto position_exp = expectedPlayerbulletPosition(testPos,speed,angle);
    
    
    CHECK((bullet_pos == position_exp));
    
}

TEST_CASE("Player Bullet moves straight towards center when fired many times"){
    auto angle = 180;
    auto displacement = 10;
    auto speed = 2;
    auto numberFired = 5;
    
    Position testPos(90,500);
    playerBullet testBullet(testPos,displacement,angle);
    
    Position origin(100,500);
    for(auto i = 0;i<numberFired;i++){
        testBullet.shoot(origin,speed);
    }
    
    
    auto bullet_pos = *(testBullet.getLocation());
    bullet_pos.x = round(bullet_pos.x);
    bullet_pos.y = round(bullet_pos.y);

    
    CHECK((bullet_pos == origin));
}

//=================================== Enemy Test =====================================================

TEST_CASE("Enemy starting position, health and displacement correct"){
    Position testOrigin(5,5);
    Enemy testEnemy(testOrigin); //enemy to start at origin
    
    auto enemyPos = *(testEnemy.getLocation());
    
    auto enemyHealth = testEnemy.getHealth();
    auto health_exp = 20; //default health
    
    auto enemyDisp = testEnemy.getDisplacement();
    auto disp_exp = 0; //default displacement
    
    CHECK(((enemyPos == testOrigin) && (enemyHealth == health_exp) && (enemyDisp == disp_exp)));

}

//TEST_CASE("Enemy moves in straight line from center"){
//    srand(time(0));
//    auto screenWidth = 1024;
//    auto screenHeight = 640;
//    auto rightImagePath = "resources/villain2.png"; 
//    auto numberOfMoves = rand()%20; 
//    auto angleOfMovement = rand()%361;
//    auto movingSpeed = 1;
//    
//    enemySFML testEnemy(rightImagePath, sf::Vector2f((screenWidth/2),(screenHeight/2)), sf::Vector2f((screenWidth/2),(screenHeight/2)));
//    
//    sf::Vector2f expPos;
//    
//    Position enemyPos;
//
//    for(auto i = 0;i<numberOfMoves;i++){
//        enemyPos = testEnemy.getLocation();
//        expPos = expectedEnemyPosition(enemyPos,movingSpeed,angleOfMovement);
//        testEnemy.moveStraightFromCentre(angleOfMovement,movingSpeed);
//    }
//    
//    enemyPos = testEnemy.getLocation();
//    
//    CHECK(expPos == sf::Vector2f(round(enemyPos.x),round(enemyPos.y)));
//    
//}





Position expectedPlayerbulletPosition(const Position& startPosition, const double& speed, const double& angle){
    auto x_exp = round(startPosition.x - (speed*cos(angle*(3.14/180))));
    auto y_exp = round(startPosition.y - (speed*sin(angle*(3.14/180))));
    
    return Position(x_exp,y_exp);
}

Position expectedEnemyPosition(const Position& startPosition, const double& speed, const double& angle){
    auto x_exp = round(startPosition.x + (speed*cos(angle*(3.14/180))));
    auto y_exp = round(startPosition.y + (speed*sin(angle*(3.14/180))));
    
    return Position(x_exp,y_exp);
}







