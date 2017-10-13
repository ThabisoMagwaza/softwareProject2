#include "gameSettings.h"

gameSettings::gameSettings(const double& w , const double& h)
:screenWidth(w),screenHeight(h)
{
     playingRadius = (screenHeight/2) - 40 ;
     playerStartingAngle = 90;
     playerBulletSpeed = 1;
     numberOfEnemies = 3;
     playerStartingPosition = Position((screenWidth/2),screenHeight - 40);
     origin = Position((screenWidth/2),(screenHeight/2));
     enemySpeed = 1;
     enemyBulletSpeed = 1;
     playerImageDirectory = "resources/ship.png";
     enemyImageDirectory = "resources/villain2.png";
     playerImageCenter = Position(86,145);
     playerSpeed = 1;
}