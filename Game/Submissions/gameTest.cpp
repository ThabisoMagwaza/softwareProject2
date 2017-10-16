
#include "Player.h"
#include "Enemy.h"
#include "playerBullet.h"
#include "Position.h"
#include "cannotLoadImage.h"
#include "boundRect.h"
#include "gameSettings.h"
#include "Playing.h"
#include <cmath>
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

//Default boundRect is a square with sides of length 10

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
    auto testRect1 = std::shared_ptr<boundRect> (new boundRect(testPos1,1,2));
    
    auto testPos2 = std::shared_ptr<Position> (new Position(2,2));
    auto testRect2 = std::shared_ptr<boundRect> (new boundRect(testPos2,1,2));
    
    CHECK(testRect1->intersects(testRect2));
}

TEST_CASE("Un-intersecting rectangles don't intersect"){
    auto testPos1 = std::shared_ptr<Position> (new Position(3,3));
    auto testRect1 = std::shared_ptr<boundRect> (new boundRect(testPos1,1,2));
    
    auto testPos2 = std::shared_ptr<Position> (new Position(100,100));
    auto testRect2 = std::shared_ptr<boundRect> (new boundRect(testPos2,1,2));
    
    CHECK_FALSE(testRect1->intersects(testRect2));
}

TEST_CASE("BoundRect Dimensions changed correctly"){
    auto testPos = std::shared_ptr<Position> (new Position(5,5));
    auto testRect = boundRect(testPos);
    testRect.changeVertices(2,2);
    
    auto vertices = testRect.getVertices();
    
    auto topLeft = (*vertices[0]); 
    Position topLeft_exp(3,3); // expected position
    
    auto topRight = (*vertices[1]); 
    Position topRight_exp(7,3);
    
    auto bottomLeft = (*vertices[2]);
    Position bottomLeft_exp(3,7);
    
    auto bottomRight = (*vertices[3]);
    Position bottomRight_exp(7,7);
    
    CHECK(((topLeft == topLeft_exp) && (topRight == topRight_exp) && (bottomLeft == bottomLeft_exp) && (bottomRight == bottomRight_exp)));
}

//=================================== Player bullet Tests =====================================================

TEST_CASE("Player bullet starting position, displacement and angle set correctly"){
    auto testPos = std::shared_ptr<Position> (new Position(1,2));
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
    
    auto testPos = std::shared_ptr<Position> (new Position(100,1000));
    playerBullet testBullet(testPos,displacement,angle);
    
    Position origin(100,500);
    testBullet.shoot(origin,speed);
    
    auto bullet_pos = *(testBullet.getLocation());
    bullet_pos.x = round(bullet_pos.x);
    bullet_pos.y = round(bullet_pos.y);

    auto startPosition = Position(100,1000);
    auto position_exp = expectedPlayerbulletPosition(startPosition,speed,angle);
    
    
    CHECK((bullet_pos == position_exp));
    
}

TEST_CASE("Player Bullet moves straight towards center when fired many times"){
    auto angle = 180;
    auto displacement = 10;
    auto speed = 2;
    auto numberFired = 5;
    
    auto testPos = std::shared_ptr<Position> (new Position(90,500));
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

TEST_CASE("Number of player bullets initialized correctly"){
    auto testPos = std::shared_ptr<Position> (new Position(1,2));
    playerBullet testBullet1(testPos,1,2);
    
    auto numberOfBullets = 1;
    
    CHECK(playerBullet::getNumberOfBullets() == numberOfBullets);
}

TEST_CASE("Number of player bullets increments correctly"){
    auto testPos = std::shared_ptr<Position> (new Position(1,2));
    auto testbullet1 = std::shared_ptr<playerBullet> (new playerBullet(testPos,1,2));
    auto testbullet2 = std::shared_ptr<playerBullet> (new playerBullet(testPos,1,2));
    auto testbullet3 = std::shared_ptr<playerBullet> (new playerBullet(testPos,1,2));
    
    auto numberOfBullets = 3;
    
    CHECK(playerBullet::getNumberOfBullets() == numberOfBullets);
}

TEST_CASE("Number of player bullets decrements correctly"){
    auto testPos = std::shared_ptr<Position> (new Position(1,2));
    auto testbullet1 = std::unique_ptr<playerBullet> (new playerBullet(testPos,1,2));
    auto testbullet2 = std::unique_ptr<playerBullet> (new playerBullet(testPos,1,2));
    auto testbullet3 = std::unique_ptr<playerBullet> (new playerBullet(testPos,1,2));
    
    testbullet3 = NULL;
    
    auto numberOfBullets = 2;
    
    CHECK(playerBullet::getNumberOfBullets() == numberOfBullets);
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

TEST_CASE("Enemy moves in straight line from center"){
    srand(time(0)); 
    auto numberOfMoves = rand()%20; 
    //auto numberOfMoves = 6;
    auto angleOfMovement = rand()%361;
    auto movingSpeed = 1;
    
    //auto startPosition = std::shared_ptr<Position> (new Position(0,6));
    auto origin = Position(6,6);
    
    Enemy testEnemy(origin);
    Position enemyPos;
    Position expPos;

    for(auto i = 0;i<numberOfMoves;i++){
        enemyPos = *(testEnemy.getLocation());
        expPos = expectedEnemyPosition(enemyPos,movingSpeed,angleOfMovement);
        testEnemy.move('l',origin,movingSpeed,angleOfMovement);
    }
    
    enemyPos = *(testEnemy.getLocation());
    enemyPos.x = round(enemyPos.x);
    enemyPos.y = round(enemyPos.y);
    
    
    CHECK((enemyPos == expPos));
    
    
}


//=================================== Playing Test =====================================================


TEST_CASE(" can add bullets player bullets"){
    auto radius = 500;
    auto startAngle = 90;

    Position testPos(100,1000);
    Player testPlayer(testPos,startAngle,radius);
    
    testPlayer.addBullet();
    
    auto numberBullets = 1;
    CHECK(playerBullet::getNumberOfBullets() == numberBullets);
}

TEST_CASE(" can remove player bullet"){
    auto radius = 500;
    auto startAngle = 90;

    Position testPos(100,1000);
    Player testPlayer(testPos,startAngle,radius);
    
    testPlayer.addBullet();
    testPlayer.addBullet();
    testPlayer.addBullet();
    
    testPlayer.removeBullet(1);
    
    auto numberBullets = 2;
    CHECK(playerBullet::getNumberOfBullets() == numberBullets);
}

TEST_CASE("Player bullet and enemy collision detected when they collide"){
    gameSettings settings(60,60);
    settings.playerStartingPosition = Position(30,60);
    settings.playingRadius = 30;
    settings.enemyBoundRectSize = Position(10,10);
    settings.playerBoundRectSize = Position(10,10);
    
    Playing testPlay(settings);
    
    testPlay.addPlayerBullet();
	
    
    //defalt boundRect has w = 1, h = 1
    for(auto i = 0; i < 27;i++){
        testPlay.advancePlayerBullets(); //after 27 - 5 moves the bullet should have collided with the enemy
    }
    
    //CHECK((testPlay.playerBullet_Enemy_Collision(0)));
}


TEST_CASE("Player bullet and enemy collision is false when they don't collide"){
    gameSettings settings(60,60);
    settings.playerStartingPosition = Position(30,60);
    settings.playingRadius = 30;
    settings.enemyBoundRectSize = Position(10,10);
    settings.playerBoundRectSize = Position(10,10);
    
    Playing testPlay(settings);
    
    testPlay.addPlayerBullet();
    
    CHECK_FALSE((testPlay.playerBullet_Enemy_Collision(0))); //initial player bullet position is when they don't collide
}

TEST_CASE("Player and enemy collision detected when they collide"){
    gameSettings settings(60,60);
    settings.playerStartingPosition = Position(30,60);
    settings.playingRadius = 30;
    settings.enemyBoundRectSize = Position(10,10);
    settings.playerBoundRectSize = Position(10,10);
    
    
    Playing testPlay(settings);
    
    std::vector<int> enemyAngles;
    enemyAngles.push_back(90); //make 'enemy 0' move towards player
    enemyAngles.push_back(0);
    enemyAngles.push_back(0);
    
    testPlay.setEnemyMovingAngles(enemyAngles);
    
    auto numberOfEnemyMoves = 27;
    
    for(auto i = 0;i<numberOfEnemyMoves;i++){
        testPlay.advanceEnemies(); // after 27 moves the enemy should have collided with the player
    }
    
    
    
    CHECK(testPlay.player_Enemy_Collison());
}

TEST_CASE("Player and enemy collision retuns false when they don't collide"){
    gameSettings settings(60,60);
    settings.playerStartingPosition = Position(30,60);
    settings.enemyBoundRectSize = Position(10,10);
    settings.playerBoundRectSize = Position(10,10);
    Playing testPlay(settings);

    CHECK_FALSE(testPlay.player_Enemy_Collison()); //all enemies are initially not colliding with player
}

TEST_CASE("Enemy bullet and player collision detected when they collide"){
    gameSettings settings(60,60);
    settings.playerStartingPosition = Position(30,60);
    settings.playingRadius = 30;
    settings.enemyBoundRectSize = Position(10,10);
    settings.playerBoundRectSize = Position(10,10);
    
    Playing testPlay(settings);
	
    std::vector<int> enemyAngles;
    enemyAngles.push_back(90); //make 'enemy 0' move towards player
    enemyAngles.push_back(0);
    enemyAngles.push_back(0);
    
    testPlay.setEnemyMovingAngles(enemyAngles);
    
    auto numberOfEnemyMoves = 27;
    

    for(auto i = 0;i<numberOfEnemyMoves;i++){
		testPlay.makeEnemybullets();
        testPlay.advanceEnemyBullets(); // after 27 moves the enemy bullet should have collided with the player
    }
    
    //CHECK(testPlay.enemyBullet_player_collision(0));
    
}

TEST_CASE("Non-colliding enemy bullet and player are identified to now collide"){
    gameSettings settings(60,60);
    settings.playerStartingPosition = Position(30,60);
    settings.playingRadius = 30;
    settings.enemyBoundRectSize = Position(10,10);
    settings.playerBoundRectSize = Position(10,10);
    Playing testPlay(settings);
	testPlay.makeEnemybullets();
    
    testPlay.advanceEnemyBullets(); 
    
    CHECK_FALSE(testPlay.enemyBullet_player_collision(0));
}


//=================================== Enemy bullet Tests =====================================================

TEST_CASE("Player bullet starting position, displacement and angle set correctly"){
    auto testPos = std::shared_ptr<Position> (new Position(1,2));
    enemyBullet testBullet(testPos,0,90);
    
    auto location_exp = Position(1,2);
    auto displacement_exp = 0;
    auto angle_exp = 90;
    
    auto bullet_location = *(testBullet.getLocation());
    auto bullet_disp = testBullet.getDisplacement();
    auto bullet_angle = testBullet.getAngle();
    
    CHECK(((bullet_location == location_exp) &&(bullet_disp == displacement_exp) && (bullet_angle = angle_exp)));
 
}


TEST_CASE("enemy Bullet moves straight towards outer circle when fired once from enemy original position"){
    auto angle = 90;
    auto displacement = 0;
    auto speed = 1;
    
    auto enemyPos = std::shared_ptr<Position> (new Position(100,500));
    enemyBullet testBullet(enemyPos,displacement,angle);
    
    Position origin(100,500);
    testBullet.shoot(origin,speed);
    
    auto bullet_pos = *(testBullet.getLocation());
    bullet_pos.x = round(bullet_pos.x);
    bullet_pos.y = round(bullet_pos.y);

    auto startPosition = Position(100,500);
    auto position_exp = expectedEnemyPosition(startPosition,speed,angle); //enemy and enemy bullet move in the same was 
    
    CHECK((bullet_pos == position_exp));
    
}

TEST_CASE("enemy Bullet moves straight towards center when fired many times"){
    auto angle = 180;
    auto displacement = 0;
    auto speed = 2;
    auto numberFired = 5;
    
    auto enemyPos = std::shared_ptr<Position> (new Position(500,500));
    enemyBullet testBullet(enemyPos,displacement,angle);
    
    Position origin(500,500);
    for(auto i = 0;i<numberFired;i++){
        testBullet.shoot(origin,speed);
    }
    
    
    auto bullet_pos = *(testBullet.getLocation());
    bullet_pos.x = round(bullet_pos.x);
    bullet_pos.y = round(bullet_pos.y);
    
    auto exp_pos = Position(490,500);

    
    CHECK((bullet_pos == exp_pos));
}

TEST_CASE("Number of enemy bullets initialized correctly"){
    auto testPos = std::shared_ptr<Position> (new Position(1,2));
    enemyBullet testBullet1(testPos,1,2);
    
    auto numberOfBullets = 1;
    
    CHECK(enemyBullet::getNumberOfBullets() == numberOfBullets);
}

TEST_CASE("Number of enemy bullets increments correctly"){
    auto testPos = std::shared_ptr<Position> (new Position(1,2));
    auto testbullet1 = std::shared_ptr<enemyBullet> (new enemyBullet(testPos,1,2));
    auto testbullet2 = std::shared_ptr<enemyBullet> (new enemyBullet(testPos,1,2));
    auto testbullet3 = std::shared_ptr<enemyBullet> (new enemyBullet(testPos,1,2));
    
    auto numberOfBullets = 3;
    
    CHECK(enemyBullet::getNumberOfBullets() == numberOfBullets);
}

TEST_CASE("Number of enemy bullets decrements correctly"){
    auto testPos = std::shared_ptr<Position> (new Position(1,2));
    auto testbullet1 = std::unique_ptr<enemyBullet> (new enemyBullet(testPos,1,2));
    auto testbullet2 = std::unique_ptr<enemyBullet> (new enemyBullet(testPos,1,2));
    auto testbullet3 = std::unique_ptr<enemyBullet> (new enemyBullet(testPos,1,2));
    
    testbullet3 = NULL;
    
    auto numberOfBullets = 2;
    
    CHECK(enemyBullet::getNumberOfBullets() == numberOfBullets);
}




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







