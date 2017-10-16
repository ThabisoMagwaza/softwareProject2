#include "gameSettings.h"

gameSettings::gameSettings(const double& w , const double& h)
:screenWidth(w),screenHeight(h)
{
     playingRadius = (screenHeight/2) -40 ;
     playerStartingAngle = 90;
     playerBulletSpeed = 5;
     numberOfEnemies = 3;
     playerStartingPosition = Position((screenWidth/2),screenHeight-40);
     origin = Position((screenWidth/2),(screenHeight/2));
     enemySpeed = 1;
     enemyBulletSpeed = 1;
     playerImageDirectory = "resources/ship.png";
     enemyImageDirectory = "resources/villain2.png";
     playerImageCenter = Position(86,145);
     enemyImageCenter = Position(55,157);
     playerSpeed = 1;
     playerBoundRectSize = Position(40,70);
     enemyBoundRectSize = Position(41,75);
	 maxPlayerBullets = 2;
	 playerBulletImageDir = "resources/playerBullet.png";
	 enemyBulletImageDir = "resources/enemyBullet.png";
	 playerBulletImageCenter = Position(205,135);
	 enemyBulletImageCenter = Position(205,250);
	 enemyBulletShootingDistance = 100;
}