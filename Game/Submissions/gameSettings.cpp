#include "gameSettings.h"

gameSettings::gameSettings(const double& w , const double& h)
:screenWidth(w),screenHeight(h)
{
     playingRadius = screenHeight/2;
     playerStartingAngle = 90;
     playerBulletSpeed = 1;
     numberOfEnemies = 3;
     playerStartingPosition = Position((screenWidth/2),screenHeight);
     origin = Position((screenWidth/2),(screenHeight/2));
     enemySpeed = 1;
     enemyBulletSpeed = 1;
     playerImageDirectory = "resources/ship.png";
     enemyImageDirectory = "resources/villain2.png";
}