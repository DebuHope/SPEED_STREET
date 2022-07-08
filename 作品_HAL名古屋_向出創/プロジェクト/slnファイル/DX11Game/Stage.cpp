//======================================================================================
// ÉXÉeÅ[ÉWä«óù
// êßçÏÅFå¸èoën
//======================================================================================
#include "Stage.h"
#include "DEnemy.h"
#include "UEnemy.h"
#include "Car.h"
#include "Hole.h"
#include "Hint.h"
#include "Item.h"
#include "CheckPoint.h"
#include "Goal.h"
#include "Player.h"
#include "Object.h"
#include "Endroll.h"

#define	CENTER	(0.0f)
#define	LEFT	(-50.0f)
#define	RIGHT	(50.0f)
#define	MAXLEFT		(-80.0f)
#define	MAXRIGHT	(80.0f)
#define ENEMYRANGE	(600.0f)

void SetStage()
{
	switch (GetSceneNo())
	{
	case SCENE_STAGE1_1:

		SetSign(XMFLOAT3(-140.0f, 0.0f, 1000.0f), XMFLOAT3(0.0f, -35.0f, 0.0f));
		SetHint(0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 1500.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 1700.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 1900.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 2100.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 2300.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 2500.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 2700.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 2900.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 3100.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 3300.0f), 0);

		SetItem(XMFLOAT3(LEFT, 0.0f, 4000.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 4200.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 4400.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 4600.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 4800.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 5000.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 5200.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 5400.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 5600.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 5800.0f), 0);

		SetItem(XMFLOAT3(RIGHT, 0.0f, 6500.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 6700.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 6900.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 7100.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 7300.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 7500.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 7700.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 7900.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 8100.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 8300.0f), 0);

		SetDEnemy(XMFLOAT3(25.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(75.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-25.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-75.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-75.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(25.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(75.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-25.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);

		SetItem(XMFLOAT3(RIGHT, 0.0f, 9400.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 9500.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 9600.0f), 0);	// 33
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1); // 43

		SetItem(XMFLOAT3(LEFT, 0.0f, 10650.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 10700.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 10750.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 10800.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 10850.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 10900.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 10950.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 11000.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 11050.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 11100.0f), 0);	// 53

		SetItem(XMFLOAT3(-20.0f, 0.0f, 11550.0f), 0);
		SetItem(XMFLOAT3(-20.0f, 0.0f, 11650.0f), 0);
		SetItem(XMFLOAT3(-20.0f, 0.0f, 11750.0f), 0);
		SetItem(XMFLOAT3(-20.0f, 0.0f, 11850.0f), 0);
		SetItem(XMFLOAT3(-20.0f, 0.0f, 11950.0f), 0);	

		SetItem(XMFLOAT3(20.0f, 0.0f, 12600.0f), 0);
		SetItem(XMFLOAT3(20.0f, 0.0f, 12700.0f), 0);
		SetItem(XMFLOAT3(20.0f, 0.0f, 12800.0f), 0);
		SetItem(XMFLOAT3(20.0f, 0.0f, 12900.0f), 0);
		SetItem(XMFLOAT3(20.0f, 0.0f, 13000.0f), 0);	// 63

		SetItem(XMFLOAT3(CENTER, 0.0f, 14800.0f), 1);
		SetItem(XMFLOAT3(CENTER, 0.0f, 14800.0f), 1);
		SetItem(XMFLOAT3(CENTER, 0.0f, 14800.0f), 1);
		SetItem(XMFLOAT3(CENTER, 0.0f, 14800.0f), 1);
		SetItem(XMFLOAT3(CENTER, 0.0f, 14800.0f), 1);	// 68

		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 15500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-80, 0.0f, 15500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-20, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);

		SetDEnemy(XMFLOAT3(75.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-25.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-75.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(25.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);

		SetUEnemy(XMFLOAT3(75.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-25.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-75.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(25.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);

		SetCar(XMFLOAT3(0.0f, 0.0f, 20000.0f), XMFLOAT3(0.0f, 0.0f, -8.0f), 0);
		SetItem(XMFLOAT3(-70, 0.0f, 19000.0f), 0);
		SetHole(XMFLOAT3(70.0f, 0.1f, 19500.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(-70.0f, 0.1f, 19500.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetItem(XMFLOAT3(70, 0.0f, 20000.0f), 0); // 70
		SetCar(XMFLOAT3(0.0f, 0.0f, 21500.0f), XMFLOAT3(0.0f, 0.0f, -8.0f), 0);

		SetAllEnemyType(XMFLOAT2(0, 27), XMFLOAT4(8, 4, 4, 4), 24000.0f);
		SetItem(XMFLOAT3(0, 0.0f, 23400.0f), 0);
		SetItem(XMFLOAT3(40, 0.0f, 24000.0f), 0);
		SetItem(XMFLOAT3(80, 50.0f, 24500.0f), 0);
		SetAllEnemyType(XMFLOAT2(1, 27), XMFLOAT4(3, 3, 3, 3), 27000.0f);
		SetItem(XMFLOAT3(-80, 0.0f, 25750.0f), 0);
		SetItem(XMFLOAT3(-40, 50.0f, 26350.0f), 0);
		SetItem(XMFLOAT3(0, 0.0f, 27000.0f), 0);
		SetItem(XMFLOAT3(40, 50.0f, 27500.0f), 0);	// 77
		SetHole(XMFLOAT3(-70.0f, 0.1f, 23000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(-30.0f, 0.1f, 25000.0f), XMFLOAT3(1.5f, 1.5f, 1.5f));

		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-200.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-300.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-400.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-500.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-600.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-700.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-800.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-900.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-1000.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-1100.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-1200.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);

		SetCar(XMFLOAT3(-50.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, -12.0f), 0);
		SetCar(XMFLOAT3(-50.0f, 0.0f, 32300.0f), XMFLOAT3(0.0f, 0.0f, -12.0f), 1);
		SetItem(XMFLOAT3(90, 0.0f, 30200.0f), 0);
		SetItem(XMFLOAT3(40, 0.0f, 30500.0f), 0);
		SetHole(XMFLOAT3(-50.0f, 0.1f, 31200.0f), XMFLOAT3(1.5f, 1.5f, 1.5f));
		SetUEnemy(XMFLOAT3(70.0f, 0.0f, 32500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 32700.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetItem(XMFLOAT3(-50, 50.0f, 31200.0f), 1);	
		SetItem(XMFLOAT3(-50, 50.0f, 31200.0f), 1);
		SetItem(XMFLOAT3(-50, 50.0f, 31200.0f), 1);
		SetItem(XMFLOAT3(-50, 50.0f, 31200.0f), 1);
		SetItem(XMFLOAT3(-50, 50.0f, 31200.0f), 1);	// 84

		SetCar(XMFLOAT3(-50.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, -12.0f), 1);
		SetCar(XMFLOAT3(-50.0f, 0.0f, 34300.0f), XMFLOAT3(0.0f, 0.0f, -12.0f), 0);

		SetDEnemy(XMFLOAT3(90, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(90, 0.0f, 34050.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(90, 0.0f, 34100.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetItem(XMFLOAT3(90, 0.0f, 32600.0f), 0);
		SetItem(XMFLOAT3(90, 0.0f, 32650.0f), 0);
		SetItem(XMFLOAT3(90, 0.0f, 32700.0f), 0);

		SetDEnemy(XMFLOAT3(0, 0.0f, 34500.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(0, 0.0f, 34550.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(0, 0.0f, 34600.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetItem(XMFLOAT3(0, 0.0f, 33100.0f), 0);
		SetItem(XMFLOAT3(0, 0.0f, 33150.0f), 0);
		SetItem(XMFLOAT3(0, 0.0f, 33200.0f), 0);	// 90

		SetDEnemy(XMFLOAT3(-90, 0.0f, 35000.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35025.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35050.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35075.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35100.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35125.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35150.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35175.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33500.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33550.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33600.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33650.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33700.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33750.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33800.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33850.0f), 0);	// 98

		SetUEnemy(XMFLOAT3(30.0f, 0.0f, 36500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 36500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-30.0f, 0.0f, 36800.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 36800.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 37100.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-90.0f, 0.0f, 37100.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 37400.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 37400.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 37700.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 37700.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);

		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(200.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(300.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(400.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(500.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(600.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(700.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(800.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(900.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(1000.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(1100.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(1200.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);

		SetUEnemy(XMFLOAT3(-100.0f, 0.0f, 39500.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-200.0f, 0.0f, 39550.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-300.0f, 0.0f, 39600.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-400.0f, 0.0f, 39650.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-500.0f, 0.0f, 39700.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-600.0f, 0.0f, 39750.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-700.0f, 0.0f, 39800.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-800.0f, 0.0f, 39850.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-900.0f, 0.0f, 39900.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-1000.0f, 0.0f, 39950.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-1100.0f, 0.0f, 40000.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-1200.0f, 0.0f, 40050.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);

		SetItem(XMFLOAT3(0.0f, 0.0f, 41000.0f), 0);
		SetItem(XMFLOAT3(0.0f, 0.0f, 41200.0f), 0);

		SetCheckPoint(XMFLOAT3(CENTER, 25.0f, 21450.0f));
		SetGoal(XMFLOAT3(CENTER, 25.0f, 42900.0f));

		break;
	case SCENE_STAGE1_2:
		//SetItem(XMFLOAT3(-20.0f, 0.0f, 11950.0f), 0);
		//SetHole(XMFLOAT3(80.0f, 0.0f, 15500.0f), 1);
		//SetCar(XMFLOAT3(80.0f, 0.0f, 15500.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), 1);
		//SetUEnemy(XMFLOAT3(-20, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		//SetDEnemy(XMFLOAT3(-75.0f, 0.0f, 16500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetAllEnemyType(XMFLOAT2(0,  27), XMFLOAT4(3, 3, 3, 3), 1500.0f);
		SetAllEnemyType(XMFLOAT2(1,  27), XMFLOAT4(4, 4, 4, 4), 3500.0f);
		SetItemQuantity(5, XMFLOAT3(0, 0, 3500), 0);
		SetAllEnemyType(XMFLOAT2(2, 228), XMFLOAT4(3, 3, 3, 3), 5500.0f);
		SetItemQuantity(4, XMFLOAT3(-80, 0, 5500), 0);
		SetItem(XMFLOAT3(-80, 50.0f, 5800), 0);
		SetAllEnemyType(XMFLOAT2(3, 228), XMFLOAT4(4, 4, 4, 4), 7500.0f);
		SetItemQuantity(5, XMFLOAT3(80, 0, 7500), 0);
		SetAllEnemyType(XMFLOAT2(3, 34), XMFLOAT4(3, 4, 3, 4), 9500.0f);
		SetItemQuantity(10, XMFLOAT3(-40, 0, 9500), 0);
		SetAllEnemyType(XMFLOAT2(4, 34), XMFLOAT4(4, 3, 4, 3), 11500.0f);
		SetItemQuantity(10, XMFLOAT3(40, 0, 11500), 0);
		SetAllEnemyType(XMFLOAT2(0, 0), XMFLOAT4(3, 3, 3, 3), 13500.0f);
		SetAllEnemyType(XMFLOAT2(1, 0), XMFLOAT4(4, 4, 4, 4), 14000.0f);
		SetAllEnemyType(XMFLOAT2(0, 0), XMFLOAT4(3, 3, 3, 3), 14500.0f);
		SetItemQuantity(4, XMFLOAT3(0, 0, 14500), 0);
		SetItem(XMFLOAT3(0, 50.0f, 14800), 0);
		SetAllEnemyType(XMFLOAT2(1, 0), XMFLOAT4(4, 4, 4, 4), 1500.0f);
		SetAllEnemyType(XMFLOAT2(3, 0), XMFLOAT4(4, 0, 0, 4), 15500.0f);
		SetAllEnemyType(XMFLOAT2(3, 0), XMFLOAT4(0, 4, 4, 0), 16500.0f);
		SetAllEnemyType(XMFLOAT2(3, 0), XMFLOAT4(1, 4, 4, 1), 17500.0f);
		SetAllEnemyType(XMFLOAT2(3, 0), XMFLOAT4(4, 2, 2, 4), 18500.0f);
		SetItemQuantity(9, XMFLOAT3(0, 0, 19000), 1);
		SetAllEnemyType(XMFLOAT2(3, 228), XMFLOAT4(4, 4, 4, 4), 19500.0f);
		SetAllEnemyType(XMFLOAT2(3, 27), XMFLOAT4(4, 4, 4, 4), 19500.0f);
		SetItemQuantity(5, XMFLOAT3(0, 0, 20000), 0);
		SetAllEnemyType(XMFLOAT2(3, 228), XMFLOAT4(4, 4, 4, 4), 23000.0f);
		SetAllEnemyType(XMFLOAT2(3, 228), XMFLOAT4(4, 4, 4, 4), 23500.0f);
		SetItemQuantity(5, XMFLOAT3(40, 0, 23000), 0);
		SetItem(XMFLOAT3(40, 50.0f, 23300), 0);
		SetAllEnemyType(XMFLOAT2(3, 27), XMFLOAT4(3, 3, 3, 3), 25000.0f);
		SetAllEnemyType(XMFLOAT2(3, 27), XMFLOAT4(3, 3, 3, 3), 25400.0f);
		SetItemQuantity(5, XMFLOAT3(-80, 0, 25000), 0);
		SetAllEnemyType(XMFLOAT2(0, 0), XMFLOAT4(1, 4, 4, 4), 27500.0f);
		SetItemQuantity(5, XMFLOAT3(-80, 0, 27000), 0);
		SetAllEnemyType(XMFLOAT2(1, 0), XMFLOAT4(3, 3, 3, 2), 28000.0f);
		SetAllEnemyType(XMFLOAT2(0, 0), XMFLOAT4(4, 1, 4, 4), 28500.0f);
		SetAllEnemyType(XMFLOAT2(1, 0), XMFLOAT4(3, 3, 2, 3), 29000.0f);
		SetAllEnemyType(XMFLOAT2(3, 0), XMFLOAT4(4, 3, 4, 3), 29500.0f);
		SetAllEnemyType(XMFLOAT2(3, 0), XMFLOAT4(3, 4, 3, 4), 30000.0f);
		SetAllEnemyType(XMFLOAT2(3, 27), XMFLOAT4(1, 1, 1, 1), 31000.0f);
		SetAllEnemyType(XMFLOAT2(1, 0), XMFLOAT4(3, 3, 3, 3), 315000.0f);
		SetItemQuantity(10, XMFLOAT3(0, 0, 32000), 1);
		SetAllEnemyType(XMFLOAT2(1, 0), XMFLOAT4(3, 3, 3, 3), 32000.0f);
		SetAllEnemyType(XMFLOAT2(0, 0), XMFLOAT4(4, 4, 4, 4), 32500.0f);
		SetAllEnemyType(XMFLOAT2(0, 0), XMFLOAT4(4, 4, 4, 4), 33000.0f);
		SetAllEnemyType(XMFLOAT2(3, 40), XMFLOAT4(4, 3, 3, 4), 31000.0f);
		SetAllEnemyType(XMFLOAT2(1, 0), XMFLOAT4(3, 3, 3, 3), 34000.0f);
		SetItemQuantity(5, XMFLOAT3(80, 0, 34000), 0);
		SetAllEnemyType(XMFLOAT2(0, 0), XMFLOAT4(4, 4, 4, 4), 35000.0f);
		SetAllEnemyType(XMFLOAT2(3, 40), XMFLOAT4(4, 3, 4, 3), 36000.0f);
		SetAllEnemyType(XMFLOAT2(1, 27), XMFLOAT4(3, 4, 3, 4), 36500.0f);
		SetAllEnemyType(XMFLOAT2(0, 228), XMFLOAT4(4, 3, 4, 3), 39000.0f);
		SetItemQuantity(5, XMFLOAT3(0, 0, 39000), 0);
		SetAllEnemyType(XMFLOAT2(1, 27), XMFLOAT4(3, 4, 3, 4), 39000.0f);
		SetAllEnemyType(XMFLOAT2(1, 0), XMFLOAT4(3, 3, 3, 3), 398000.0f);
		SetAllEnemyType(XMFLOAT2(0, 0), XMFLOAT4(4, 4, 4, 4), 40800.0f);
		SetAllEnemyType(XMFLOAT2(3, 0), XMFLOAT4(1, 1, 1, 1), 41400.0f);
		SetItemQuantity(10, XMFLOAT3(0, 0, 41000), 1);
		SetCheckPoint(XMFLOAT3(CENTER, 25.0f, 21450.0f));
		SetGoal(XMFLOAT3(CENTER, 25.0f, 42900.0f));
		break;
	case SCENE_STAGE1_3:
		for (int i = 0; i < 60; i++)
		{
			switch (i / (60 / 3))
			{
			case(0):
				if (i % 3 != 0)SetCar(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 % 5), 0.0f, 3000.0f + 600.0f * i), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
				else SetHole(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 % 5), 0.1f, 2000.0f + 600.0f * i), XMFLOAT3(1.0f, 1.0f, 1.0f));
				if (i == 4)
				{
					for (int a = 0; a < 11; a++)
					{
						SetItem(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 % 5), 50.0f, 1000.0f + 600.0f * i), 1);
					}
				}
				else SetItem(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 % 5), 0.0f, 1000.0f + 600.0f * i), 0);
				break;
			case(1):
				if (i % 3 == 0)SetCar(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 * 7 % 5), 0.0f, 3000.0f + 600.0f * i), XMFLOAT3(0.0f, 0.0f, -7.0f), 1);
				else if (i % 3 == 1)SetUEnemy(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 * 7 % 5), 0.0f, 3000.0f + 600.0f * i), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
				else if (i % 3 == 2)SetDEnemy(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 * 7 % 5), 0.0f, 3000.0f + 600.0f * i), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
				if (i == 30)
				{
					for (int a = 0; a < 11; a++)
					{
						SetItem(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 * 7 % 5), 50.0f, 1000.0f + 600.0f * i), 1);
					}
				}
				else SetItem(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 * 7 % 5), 0.0f, 1000.0f + 600.0f * i), 0);
				break;
			case(2):
				if (i % 5 < 3)SetCar(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 * 7 % 5), 0.0f, 3000.0f + 600.0f * i), XMFLOAT3(0.0f, 0.0f, -7.0f), 1);
				else if (i % 5 == 3)SetUEnemy(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 * 7 % 5), 0.0f, 3000.0f + 600.0f * i), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
				else if (i % 5 == 4)SetDEnemy(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 * 7 % 5), 0.0f, 3000.0f + 600.0f * i), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
				if (i == 38 || i == 47)
				{
					for (int a = 0; a < 11; a++)
					{
						SetItem(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 * 7 * 7 % 5), 50.0f, 1000.0f + 600.0f * i), 1);
					}
				}
				else SetItem(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 * 7 * 7 % 5), 0.0f, 1000.0f + 600.0f * i), 0);
				break;
			default:
				SetItem(XMFLOAT3(80.0f - 40.0f * (float)(i * 7 * 7 % 5), 0.0f, 1500.0f + 400.0f * i), 0);
				break;
			}
			SetAllEnemyType(XMFLOAT2(0, 0), XMFLOAT4(3, 3, 3, 3), 3700.0f * i);
			SetAllEnemyType(XMFLOAT2(1, 0), XMFLOAT4(4, 4, 4, 4), 2300.0f * i);
			//SetAllEnemyType(XMFLOAT2(3, 0), XMFLOAT4(1, 1, 1, 1), 3000.0f * i);
		}
		SetItemQuantity(9,XMFLOAT3(0,0, 40000),0);
		SetItem(XMFLOAT3(0, 50, 41000), 0);
		SetCheckPoint(XMFLOAT3(CENTER, 25.0f, 21450.0f));
		SetGoal(XMFLOAT3(CENTER, 25.0f, 42900.0f));
		break;

	case SCENE_STAGE1_4:

		SetSign(XMFLOAT3(-140.0f, 0.0f, 1000.0f), XMFLOAT3(0.0f, -35.0f, 0.0f));
		SetHint(0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 1500.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 1700.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 1900.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 2100.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 2300.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 2500.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 2700.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 2900.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 3100.0f), 0);
		SetItem(XMFLOAT3(CENTER, 0.0f, 3300.0f), 0);
		SetHole(XMFLOAT3(0.0f, 0.1f, 3400.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));

		SetItem(XMFLOAT3(LEFT, 0.0f, 4000.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 4200.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 4400.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 4600.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 4800.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 5000.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 5200.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 5400.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 5600.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 5800.0f), 0);
		SetHole(XMFLOAT3(LEFT, 0.1f, 5900.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));

		SetItem(XMFLOAT3(RIGHT, 0.0f, 6500.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 6700.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 6900.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 7100.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 7300.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 7500.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 7700.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 7900.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 8100.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 8300.0f), 0);
		SetHole(XMFLOAT3(RIGHT, 0.1f, 8400.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));

		SetDEnemy(XMFLOAT3(25.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(75.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-25.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-75.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-75.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(25.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(75.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-25.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);

		SetItem(XMFLOAT3(RIGHT, 0.0f, 9400.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 9500.0f), 0);
		SetItem(XMFLOAT3(RIGHT, 0.0f, 9600.0f), 0);	// 33
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1);
		SetItem(XMFLOAT3(RIGHT, 50.0f, 9850.0f), 1); // 43
		SetHole(XMFLOAT3(0.0f, 0.1f, 10000.0f), XMFLOAT3(1.5f, 1.5f, 1.5f));

		SetItem(XMFLOAT3(LEFT, 0.0f, 10650.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 10700.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 10750.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 10800.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 10850.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 10900.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 10950.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 11000.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 11050.0f), 0);
		SetItem(XMFLOAT3(LEFT, 0.0f, 11100.0f), 0);	// 53

		SetItem(XMFLOAT3(-20.0f, 0.0f, 11550.0f), 0);
		SetItem(XMFLOAT3(-20.0f, 0.0f, 11650.0f), 0);
		SetItem(XMFLOAT3(-20.0f, 0.0f, 11750.0f), 0);
		SetItem(XMFLOAT3(-20.0f, 0.0f, 11850.0f), 0);
		SetItem(XMFLOAT3(-20.0f, 0.0f, 11950.0f), 0);
		SetHole(XMFLOAT3(-90.0f, 0.1f, 11000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));

		SetItem(XMFLOAT3(20.0f, 0.0f, 12600.0f), 0);
		SetItem(XMFLOAT3(20.0f, 0.0f, 12700.0f), 0);
		SetItem(XMFLOAT3(20.0f, 0.0f, 12800.0f), 0);
		SetItem(XMFLOAT3(20.0f, 0.0f, 12900.0f), 0);
		SetItem(XMFLOAT3(20.0f, 0.0f, 13000.0f), 0);	// 63

		SetItem(XMFLOAT3(CENTER, 0.0f, 14800.0f), 1);
		SetItem(XMFLOAT3(CENTER, 0.0f, 14800.0f), 1);
		SetItem(XMFLOAT3(CENTER, 0.0f, 14800.0f), 1);
		SetItem(XMFLOAT3(CENTER, 0.0f, 14800.0f), 1);
		SetItem(XMFLOAT3(CENTER, 0.0f, 14800.0f), 1);	// 68

		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 15500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-80, 0.0f, 15500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-20, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);

		SetDEnemy(XMFLOAT3(75.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-25.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-75.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(25.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);

		SetUEnemy(XMFLOAT3(75.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-25.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-75.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(25.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetHole(XMFLOAT3(0.0f, 0.1f, 18000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(50.0f, 0.1f, 18000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(-50.0f, 0.1f, 18000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));

		SetCar(XMFLOAT3(0.0f, 0.0f, 20000.0f), XMFLOAT3(0.0f, 0.0f, -8.0f), 0);
		SetItem(XMFLOAT3(-70, 0.0f, 19000.0f), 0);
		SetHole(XMFLOAT3(70.0f, 0.1f, 19500.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(-70.0f, 0.1f, 19500.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetItem(XMFLOAT3(70, 0.0f, 20000.0f), 0); // 70
		SetCar(XMFLOAT3(0.0f, 0.0f, 21500.0f), XMFLOAT3(0.0f, 0.0f, -8.0f), 0);

		SetAllEnemyType(XMFLOAT2(0, 27), XMFLOAT4(8, 4, 4, 4), 24000.0f);
		SetItem(XMFLOAT3(0, 0.0f, 23400.0f), 0);
		SetItem(XMFLOAT3(40, 0.0f, 24000.0f), 0);
		SetItem(XMFLOAT3(80, 50.0f, 24500.0f), 0);
		SetAllEnemyType(XMFLOAT2(1, 27), XMFLOAT4(3, 3, 3, 3), 27000.0f);
		SetItem(XMFLOAT3(-80, 0.0f, 25750.0f), 0);
		SetItem(XMFLOAT3(-40, 50.0f, 26350.0f), 0);
		SetItem(XMFLOAT3(0, 0.0f, 27000.0f), 0);
		SetItem(XMFLOAT3(40, 50.0f, 27500.0f), 0);	// 77
		SetHole(XMFLOAT3(-70.0f, 0.1f, 23000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(-30.0f, 0.1f, 25000.0f), XMFLOAT3(1.5f, 1.5f, 1.5f));

		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-200.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-300.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-400.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-500.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-600.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-700.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-800.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-900.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-1000.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-1100.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-1200.0f, 0.0f, 30000.0f), XMFLOAT3(1.5f, 0.0f, 0.0f), 0);
		SetHole(XMFLOAT3(-50.0f, 0.1f, 28000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));

		SetCar(XMFLOAT3(-50.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, -12.0f), 0);
		SetCar(XMFLOAT3(-50.0f, 0.0f, 32300.0f), XMFLOAT3(0.0f, 0.0f, -12.0f), 1);
		SetItem(XMFLOAT3(90, 0.0f, 30200.0f), 0);
		SetItem(XMFLOAT3(40, 0.0f, 30500.0f), 0);
		SetHole(XMFLOAT3(-50.0f, 0.1f, 31200.0f), XMFLOAT3(1.5f, 1.5f, 1.5f));
		SetUEnemy(XMFLOAT3(70.0f, 0.0f, 32500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 32700.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetItem(XMFLOAT3(-50, 50.0f, 31200.0f), 1);
		SetItem(XMFLOAT3(-50, 50.0f, 31200.0f), 1);
		SetItem(XMFLOAT3(-50, 50.0f, 31200.0f), 1);
		SetItem(XMFLOAT3(-50, 50.0f, 31200.0f), 1);
		SetItem(XMFLOAT3(-50, 50.0f, 31200.0f), 1);	// 84

		SetCar(XMFLOAT3(-50.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, -12.0f), 1);
		SetCar(XMFLOAT3(-50.0f, 0.0f, 34300.0f), XMFLOAT3(0.0f, 0.0f, -12.0f), 0);

		SetDEnemy(XMFLOAT3(90, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(90, 0.0f, 34050.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(90, 0.0f, 34100.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetItem(XMFLOAT3(90, 0.0f, 32600.0f), 0);
		SetItem(XMFLOAT3(90, 0.0f, 32650.0f), 0);
		SetItem(XMFLOAT3(90, 0.0f, 32700.0f), 0);
		SetHole(XMFLOAT3(0.0f, 0.1f, 34000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));

		SetDEnemy(XMFLOAT3(0, 0.0f, 34500.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(0, 0.0f, 34550.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(0, 0.0f, 34600.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetItem(XMFLOAT3(0, 0.0f, 33100.0f), 0);
		SetItem(XMFLOAT3(0, 0.0f, 33150.0f), 0);
		SetItem(XMFLOAT3(0, 0.0f, 33200.0f), 0);	// 90
		SetHole(XMFLOAT3(50.0f, 0.1f, 34800.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));

		SetDEnemy(XMFLOAT3(-90, 0.0f, 35000.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35025.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35050.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35075.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35100.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35125.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35150.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(-90, 0.0f, 35175.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33500.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33550.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33600.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33650.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33700.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33750.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33800.0f), 0);
		SetItem(XMFLOAT3(-90, 0.0f, 33850.0f), 0);	// 98

		SetUEnemy(XMFLOAT3(30.0f, 0.0f, 36500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 36500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-30.0f, 0.0f, 36800.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 36800.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 37100.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-90.0f, 0.0f, 37100.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 37400.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 37400.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 37700.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 37700.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);

		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(200.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(300.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(400.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(500.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(600.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(700.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(800.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(900.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(1000.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(1100.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(1200.0f, 0.0f, 38500.0f), XMFLOAT3(-2.5f, 0.0f, 0.0f), 0);

		SetUEnemy(XMFLOAT3(-100.0f, 0.0f, 39500.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-200.0f, 0.0f, 39550.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-300.0f, 0.0f, 39600.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-400.0f, 0.0f, 39650.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-500.0f, 0.0f, 39700.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-600.0f, 0.0f, 39750.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-700.0f, 0.0f, 39800.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-800.0f, 0.0f, 39850.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-900.0f, 0.0f, 39900.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-1000.0f, 0.0f, 39950.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-1100.0f, 0.0f, 40000.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-1200.0f, 0.0f, 40050.0f), XMFLOAT3(2.5f, 0.0f, 0.0f), 0);

		SetItem(XMFLOAT3(0.0f, 0.0f, 41000.0f), 0);
		SetItem(XMFLOAT3(0.0f, 0.0f, 41200.0f), 0);

		SetHole(XMFLOAT3(0.0f, 0.1f, 41500.0f), XMFLOAT3(1.0f, 1.0f, 2.0f));
		SetHole(XMFLOAT3(-50.0f, 0.1f, 41500.0f), XMFLOAT3(1.0f, 1.0f, 2.0f));
		SetHole(XMFLOAT3(50.0f, 0.1f, 41500.0f), XMFLOAT3(1.0f, 1.0f, 2.0f));

		SetGoal(XMFLOAT3(CENTER, 25.0f, 42900.0f));
;
		break;
	case SCENE_STAGE2_1:
		//1í«è],2ÉWÉÉÉìÉv,3Ç‡Çø,1â°,2èc,3Ç‡Çø
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 3000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 3500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 4000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 4500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 5000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 6000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 6500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 7000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 7500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 8000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 2);

		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 1);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 9500.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 1);
		SetDEnemy(XMFLOAT3(-10.0f, 0.0f, 10000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 10500.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 1);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 1);

		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 12500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 13500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);

		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 14500.0f), XMFLOAT3(-4.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 15000.0f), XMFLOAT3(-4.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 15500.0f), XMFLOAT3(4.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 16000.0f), XMFLOAT3(4.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 16500.0f), XMFLOAT3(4.0f, 0.0f, 0.0f), 1);

		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 18500.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-40.0f, 60.0f, 19000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 30.0f, 19500.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(40.0f, 20.0f, 20000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(80.0f, 70.0f, 20500.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);

		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 20000.0f), XMFLOAT3(0.0f, 0.0f, 3.0f), 1);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 20000.0f), XMFLOAT3(0.0f, 0.0f, 3.0f), 1);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 22200.0f), XMFLOAT3(0.0f, 0.0f, 7.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 24200.0f), XMFLOAT3(0.0f, 0.0f, 7.0f), 1);

		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 35000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);

		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 37000.0f), XMFLOAT3(-4.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 38000.0f), XMFLOAT3(-4.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 39000.0f), XMFLOAT3(4.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 40000.0f), XMFLOAT3(4.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 41000.0f), XMFLOAT3(4.0f, 0.0f, 0.0f), 1);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 5.0f), 1);
		for (int i = 0; i < 5; i++)
		{
			SetCar(XMFLOAT3(0.0f, 0.0f, 8000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, -15.0f), 2);
		}
		for (int i = 0; i < 7; i++)
		{
			SetHole(XMFLOAT3(0.0f, 0.1f, 6000.0f * (i + 1)), XMFLOAT3(10.0f, 1.0f, 1.5f));
			SetHole(XMFLOAT3(50.0f, 0.05f, 6000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, 0.0f));
			SetHole(XMFLOAT3(-50.0f, 0.05f, 6000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, 0.0f));
		}
		SetItemQuantity(10, XMFLOAT3(50.0f, 0.0f, 4000.0f),0);
		SetItemQuantity(10, XMFLOAT3(0.0f, 0.0f, 8000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-50.0f, 50.0f, 10000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(0.0f, 0.0f, 13000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(50.0f, 0.0f, 16000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-50.0f, 0.0f, 20000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 26000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-80.0f, 0.0f, 31000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 35000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(80.0f, 50.0f, 42000.0f), 1);
		SetCheckPoint(XMFLOAT3(CENTER, 25.0f, 21450.0f));
		SetGoal(XMFLOAT3(CENTER, 25.0f, 42900.0f));
		break;
	case SCENE_STAGE2_2:
		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 3000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 3000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 3500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 3500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 4000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 4000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 4500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 4500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 5000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 5000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);

		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 7000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 7000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(30.0f, 0.0f, 8000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(30.0f, 0.0f, 8000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(-70.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(-70.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 10000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 10000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);

		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 13000.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 13000.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 14000.0f), XMFLOAT3(0.5f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 14000.0f), XMFLOAT3(0.5f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 15000.0f), XMFLOAT3(0.8f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 15000.0f), XMFLOAT3(0.8f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-100.0f, 0.0f, 16000.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 16000.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 17000.0f), XMFLOAT3(-0.3f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 17000.0f), XMFLOAT3(-0.3f, 0.0f, 0.0f), 3);

		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 4);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 4);
		SetUEnemy(XMFLOAT3(30.0f, 0.0f, 20000.0f), XMFLOAT3(0.0f, 0.0f, 2.0f), 4);
		SetDEnemy(XMFLOAT3(30.0f, 0.0f, 20000.0f), XMFLOAT3(0.0f, 0.0f, 2.0f), 4);
		SetUEnemy(XMFLOAT3(-70.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, 3.0f), 4);
		SetDEnemy(XMFLOAT3(-70.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, 3.0f), 4);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 220000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 4);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 220000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 4);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 23000.0f), XMFLOAT3(0.0f, 0.0f, 5.0f), 4);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 23000.0f), XMFLOAT3(0.0f, 0.0f, 5.0f), 4);

		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), 4);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), 4);
		SetUEnemy(XMFLOAT3(30.0f, 0.0f, 26000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 4);
		SetDEnemy(XMFLOAT3(30.0f, 0.0f, 26000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 4);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 26000.0f), XMFLOAT3(-5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-70.0f, 0.0f, 27000.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 4);
		SetDEnemy(XMFLOAT3(-70.0f, 0.0f, 27000.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 4);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 4);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 4);
		SetUEnemy(XMFLOAT3(0.0f, 60.0f, 26000.0f), XMFLOAT3(-0.0f, 5.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 4);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 4);

		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-100.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 60.0f, 32000.0f), XMFLOAT3(-0.0f, 5.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 3);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 3);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 3);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 60.0f, 33000.0f), XMFLOAT3(-5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-40.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 60.0f, 34000.0f), XMFLOAT3(-5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 35000.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 35000.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 35000.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 35000.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(50.0f, 60.0f, 31000.0f), XMFLOAT3(-0.0f, 5.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-50.0f, 60.0f, 31000.0f), XMFLOAT3(-0.0f, 5.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 36000.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 36000.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-100.0f, 0.0f, 36000.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 36000.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), 3);

		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), 4);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), 4);
		SetUEnemy(XMFLOAT3(30.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, 2.0f), 4);
		SetDEnemy(XMFLOAT3(30.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, 2.0f), 4);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 38000.0f), XMFLOAT3(-5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-70.0f, 0.0f, 39000.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 4);
		SetDEnemy(XMFLOAT3(-70.0f, 0.0f, 39000.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 4);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 40000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 4);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 40000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 4);
		SetUEnemy(XMFLOAT3(0.0f, 60.0f, 41000.0f), XMFLOAT3(-0.0f, 5.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 41000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 4);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 41000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 4);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 40000.0f), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 40000.0f), XMFLOAT3(-5.0f, 0.0f, 0.0f), 1);
		for (int i = 0; i < 7; i++)
		{
			SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 6000.0f * (i + 1)), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
			SetUEnemy(XMFLOAT3(80.0f, 0.0f, 6000.0f * (i + 1)), XMFLOAT3(-5.0f, 0.0f, 0.0f), 1);
		}
		for (int i = 0; i < 5; i++)
		{
			SetCar(XMFLOAT3(-60.0f + (60.0f * (i % 3)), 0.0f, 8000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, -15.0f), 2);
		}
		SetItemQuantity(10, XMFLOAT3(50.0f, 0.0f, 4000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(0.0f, 0.0f, 8000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-50.0f, 50.0f, 12000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(0.0f, 0.0f, 16000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(50.0f, 0.0f, 20000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(-50.0f, 0.0f, 24000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 32000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-80.0f, 0.0f, 36000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 38000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(80.0f, 50.0f, 42000.0f), 1);
		SetCheckPoint(XMFLOAT3(CENTER, 25.0f, 21450.0f));
		SetGoal(XMFLOAT3(CENTER, 25.0f, 42900.0f));
		break;
	case SCENE_STAGE2_3:
		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 3000.0f), XMFLOAT3(-0.4f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 3000.0f), XMFLOAT3(-0.4f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(-100.0f, 0.0f, 3000.0f), XMFLOAT3(0.4f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 3000.0f), XMFLOAT3(0.4f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 4000.0f), XMFLOAT3(-0.3f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(40.0f, 0.0f, 4000.0f), XMFLOAT3(-0.3f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 4000.0f), XMFLOAT3(0.3f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-40.0f, 0.0f, 4000.0f), XMFLOAT3(0.3f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 5000.0f), XMFLOAT3(-0.3f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(40.0f, 0.0f, 5000.0f), XMFLOAT3(-0.3f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 5000.0f), XMFLOAT3(0.3f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-40.0f, 0.0f, 5000.0f), XMFLOAT3(0.3f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 5000.0f), XMFLOAT3(-0.3f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 5000.0f), XMFLOAT3(-0.3f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 5000.0f), XMFLOAT3(0.3f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 5000.0f), XMFLOAT3(0.3f, 0.0f, 0.0f), 3);

		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 8000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 8000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetUEnemy(XMFLOAT3(-100.0f, 0.0f, 9000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 9000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 10000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 4);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 10000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 4);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 11000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 11000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 12000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 12000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);

		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-40.0f, 60.0f, 13500.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 30.0f, 14000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(40.0f, 20.0f, 14500.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(80.0f, 70.0f, 15000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(40.0f, 60.0f, 13500.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(80.0f, 30.0f, 14000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-40.0f, 20.0f, 14500.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 70.0f, 15000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);

		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 15500.0f), XMFLOAT3(-0.0f, 4.0f, 1.0f), 2);
		SetUEnemy(XMFLOAT3(40.0f, 60.0f, 16500.0f), XMFLOAT3(0.0f, 4.0f, 1.0f), 2);
		SetUEnemy(XMFLOAT3(80.0f, 30.0f, 17000.0f), XMFLOAT3(0.0f, 4.0f, 1.0f), 2);
		SetUEnemy(XMFLOAT3(-40.0f, 20.0f, 17500.0f), XMFLOAT3(0.0f, 4.0f, 1.0f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 70.0f, 18000.0f), XMFLOAT3(0.0f, 4.0f, 1.0f), 2);
		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 15500.0f), XMFLOAT3(-0.0f, 4.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(40.0f, 60.0f, 16500.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(80.0f, 30.0f, 17000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-40.0f, 20.0f, 17500.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-80.0f, 70.0f, 18000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 1);

		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 4);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 4);
		SetUEnemy(XMFLOAT3(30.0f, 0.0f, 20000.0f), XMFLOAT3(0.0f, 0.0f, 2.0f), 4);
		SetDEnemy(XMFLOAT3(30.0f, 0.0f, 20000.0f), XMFLOAT3(0.0f, 0.0f, 2.0f), 4);
		SetUEnemy(XMFLOAT3(-70.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, 3.0f), 4);
		SetDEnemy(XMFLOAT3(-70.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, 3.0f), 4);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 220000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 4);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 220000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 4);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 23000.0f), XMFLOAT3(0.0f, 0.0f, 5.0f), 4);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 23000.0f), XMFLOAT3(0.0f, 0.0f, 5.0f), 4);
		
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 20000.0f), XMFLOAT3(0.0f, 0.0f, 3.0f), 1);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 20000.0f), XMFLOAT3(0.0f, 0.0f, 3.0f), 1);

		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, -15.0f), 0);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 22000.0f), XMFLOAT3(0.0f, 0.0f, -15.0f), 0);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 23000.0f), XMFLOAT3(0.0f, 0.0f, -15.0f), 0);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 0.0f, -15.0f), 0);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, 0.0f, -15.0f), 0);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, -15.0f), 0);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 22000.0f), XMFLOAT3(0.0f, 0.0f, -15.0f), 0);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 23000.0f), XMFLOAT3(0.0f, 0.0f, -15.0f), 0);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 0.0f, -15.0f), 0);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 22200.0f), XMFLOAT3(0.0f, 0.0f, 7.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 24200.0f), XMFLOAT3(0.0f, 0.0f, 7.0f), 1);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, 5.0f), 1);

		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 24000.0), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 25000.0), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-0.0f, 0.0f, 26000.0), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 27000.0), XMFLOAT3(5.0f, 0.0f, -3.0f), 1);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 28000.0), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 29000.0), XMFLOAT3(5.0f, 0.0f, -5.0f), 1);

		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 24500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 25500.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 2);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 26500.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 2);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 27500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 28500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 29500.0f), XMFLOAT3(0.0f, 0.0f, -8.0f), 2);

		SetUEnemy(XMFLOAT3(-100.0f, 0.0f, 30000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 30000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetDEnemy(XMFLOAT3(500.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetUEnemy(XMFLOAT3(-30.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetDEnemy(XMFLOAT3(-30.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 35000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetDEnemy(XMFLOAT3(40.0f, 0.0f, 35000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 36000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 36000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetUEnemy(XMFLOAT3(-70.0f, 0.0f, 39000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetDEnemy(XMFLOAT3(-70.0f, 0.0f, 39000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetUEnemy(XMFLOAT3(-10.0f, 0.0f, 40000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetDEnemy(XMFLOAT3(-10.0f, 0.0f, 40000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 41000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 41000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetUEnemy(XMFLOAT3(-70.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);
		SetDEnemy(XMFLOAT3(-70.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 3);


		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 30000.0f), XMFLOAT3(-0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 30000.0f), XMFLOAT3(-0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 34000.0f), XMFLOAT3(-0.0f, 0.0f, 2.0f), 4);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 34000.0f), XMFLOAT3(-0.0f, 0.0f, 2.0f), 4);
		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 38000.0f), XMFLOAT3(-0.0f, 0.0f, -2.0f), 4);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 38000.0f), XMFLOAT3(-0.0f, 0.0f, -2.0f), 4);

		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 30000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 0);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 36000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 0);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 40000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 0);
		SetDEnemy(XMFLOAT3(30.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 0);


		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 31000.0), XMFLOAT3(5.0f, 0.0f, -1.0f), 1);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 33000.0), XMFLOAT3(5.0f, 0.0f, 2.0f), 1);
		SetUEnemy(XMFLOAT3(-30.0f, 0.0f, 35000.0), XMFLOAT3(5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 37000.0), XMFLOAT3(5.0f, 0.0f, -1.0f), 1);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 39000.0), XMFLOAT3(5.0f, 0.0f, 1.0f), 1);
		SetUEnemy(XMFLOAT3(30.0f, 0.0f, 41000.0), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 5.0f), 1);
		for (int i = 0; i < 8; i++)
		{
			SetCar(XMFLOAT3(0.0f, 0.0f, 5000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, -15.0f), 2);
		}
		for (int i = 0; i < 10; i++)
		{
			SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 4000.0f * (i + 1)), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
			SetUEnemy(XMFLOAT3(80.0f, 0.0f, 4000.0f * (i + 1)), XMFLOAT3(-5.0f, 0.0f, 0.0f), 1);
		}
		for (int i = 0; i < 7; i++)
		{
			SetHole(XMFLOAT3(0.0f, 0.1f, 6000.0f * (i + 1)), XMFLOAT3(10.0f, 1.0f, 1.5f));
			SetHole(XMFLOAT3(50.0f, 0.05f, 6000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, 0.0f));
			SetHole(XMFLOAT3(-50.0f, 0.05f, 6000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, 0.0f));
		}
		SetItemQuantity(10, XMFLOAT3(-50.0f, 0.0f, 4000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(30.0f, 0.0f, 8000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-50.0f, 50.0f, 10000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(30.0f, 0.0f, 13000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(50.0f, 0.0f, 16000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-100.0f, 0.0f, 20000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 26000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-80.0f, 0.0f, 31000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 35000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(0.0f, 50.0f, 42000.0f), 1);
		SetCheckPoint(XMFLOAT3(CENTER, 25.0f, 21450.0f));
		SetGoal(XMFLOAT3(CENTER, 25.0f, 44000.0f));
		break;
	case SCENE_STAGE2_4:
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, GetPlayerPos(0).z + 2000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 5);

		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 6000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 6000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetUEnemy(XMFLOAT3(30.0f, 0.0f, 8000.0f), XMFLOAT3(-0.0f, 0.0f, -0.0f), 3);
		SetDEnemy(XMFLOAT3(30.0f, 0.0f, 8000.0f), XMFLOAT3(-0.0f, 0.0f, -0.0f), 3);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 11000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 11000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetUEnemy(XMFLOAT3(-30.0f, 0.0f, 13000.0f), XMFLOAT3(-0.0f, 0.0f, -0.0f), 3);
		SetDEnemy(XMFLOAT3(-30.0f, 0.0f, 13000.0f), XMFLOAT3(-0.0f, 0.0f, -0.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 21000.0f), XMFLOAT3(-0.0f, 0.0f, -0.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 21000.0f), XMFLOAT3(-0.0f, 0.0f, -0.0f), 3);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 23000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 23000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 28000.0f), XMFLOAT3(-0.0f, 0.0f, -0.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 28000.0f), XMFLOAT3(-0.0f, 0.0f, -0.0f), 3);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 32000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 32000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetUEnemy(XMFLOAT3(100.0f, 0.0f, 33000.0f), XMFLOAT3(-0.0f, 0.0f, -0.0f), 3);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 33000.0f), XMFLOAT3(-0.0f, 0.0f, -0.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 36000.0f), XMFLOAT3(-0.0f, 0.0f, -0.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 36000.0f), XMFLOAT3(-0.0f, 0.0f, -0.0f), 3);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 39000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(-40.0f, 0.0f, 39000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 41000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 41000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 3);

		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 6000.0f), XMFLOAT3(0.0f, 0.0f, -10.0f), 0);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 7000.0f), XMFLOAT3(0.0f, 0.0f, -10.0f), 0);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 7000.0f), XMFLOAT3(0.0f, 0.0f, -10.0f), 0);
		SetDEnemy(XMFLOAT3(-30.0f, 0.0f, 8000.0f), XMFLOAT3(0.0f, 0.0f, -10.0f), 0);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 0.0f, -10.0f), 0);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 0.0f, -10.0f), 0);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 10000.0f), XMFLOAT3(0.0f, 0.0f, -10.0f), 0);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 10000.0f), XMFLOAT3(0.0f, 0.0f, -10.0f), 0);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 1);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 1);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 1);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 1);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 2);
		SetDEnemy(XMFLOAT3(30.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 2);
		SetDEnemy(XMFLOAT3(-30.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 2);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 2);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 2);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 2);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 2);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 19500.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 2);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 19500.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 2);

		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 20000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 21000.0f), XMFLOAT3(-0.0f, 5.0f, -0.0f), 2);
		SetUEnemy(XMFLOAT3(30.0f, 0.0f, 22000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(-30.0f, 0.0f, 22000.0f), XMFLOAT3(5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 23000.0f), XMFLOAT3(-0.0f, 5.0f, -0.0f), 2);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 23000.0f), XMFLOAT3(-0.0f, 3.0f, -0.0f), 2);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 24000.0f), XMFLOAT3(-5.0f, 0.0f, -1.0f), 1);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 24000.0f), XMFLOAT3(5.0f, 0.0f, -1.0f), 1);
		SetUEnemy(XMFLOAT3(140.0f, 0.0f, 24000.0f), XMFLOAT3(-0.5f, 5.0f, -0.0f), 2);
		SetUEnemy(XMFLOAT3(180.0f, 0.0f, 24000.0f), XMFLOAT3(-0.5f, 3.0f, -0.0f), 2);

		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 26000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 28000.0f), XMFLOAT3(-0.0f, 4.0f, -0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 29000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 31000.0f), XMFLOAT3(-0.0f, 5.0f, -0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 32000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 33000.0f), XMFLOAT3(-0.0f, 2.0f, -0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 34000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 36000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(30.0f, 0.0f, 36000.0f), XMFLOAT3(-0.0f, 3.0f, -0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 37000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 37000.0f), XMFLOAT3(-0.0f, 4.0f, -0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 38000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 38000.0f), XMFLOAT3(5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 39000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 39000.0f), XMFLOAT3(-0.0f, 2.0f, -0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 40000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 40000.0f), XMFLOAT3(-0.0f, 5.0f, -0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 41000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 41000.0f), XMFLOAT3(5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 41000.0f), XMFLOAT3(-0.0f, 5.0f, -0.0f), 2);

		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 26000.0f), XMFLOAT3(0.0f, 0.0f, -10.0f), 0);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, 0.0f, -8.0f), 0);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 30000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 36000.0f), XMFLOAT3(0.0f, 0.0f, -10.0f), 0);
		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, -15.0f), 0);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 40000.0f), XMFLOAT3(0.0f, 0.0f, -10.0f), 0);
		SetDEnemy(XMFLOAT3(30.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, -10.0f), 0);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 27000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 41000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 1);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 26000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 2);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 2);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 2);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 2);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 2);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 2);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 2);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 39000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 2);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 40000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 2);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 41000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 2);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 41000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 2);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, -0.0f), 2);
		for (int i = 1; i < 9; i++)
		{
			if (i % 2 == 0)
			{
				SetHole(XMFLOAT3(0.0f, 0.1f, 5000.0f * i), XMFLOAT3(10.0f, 1.0f, 1.5f));
				SetHole(XMFLOAT3(50.0f, 0.05f, 5000.0f * i), XMFLOAT3(0.0f, 0.0f, 0.0f));
				SetHole(XMFLOAT3(-50.0f, 0.05f, 5000.0f * i), XMFLOAT3(0.0f, 0.0f, 0.0f));
				SetCar(XMFLOAT3(0.0f, 0.0f, 4000.0f * i), XMFLOAT3(0.0f, 0.0f, -15.0f), 2);
			}
			else
			{
				SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 5000.0f * i), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
				SetUEnemy(XMFLOAT3(80.0f, 0.0f, 5000.0f * i), XMFLOAT3(-5.0f, 0.0f, 0.0f), 1);
				SetCar(XMFLOAT3(80.0f, 0.0f, 4000.0f * i), XMFLOAT3(0.0f, 0.0f, -15.0f), 2);
				SetCar(XMFLOAT3(-80.0f, 0.0f, 4000.0f * i), XMFLOAT3(0.0f, 0.0f, -15.0f), 2);
			}
		}
		SetItemQuantity(10, XMFLOAT3(-50.0f, 0.0f, 4000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(-30.0f, 0.0f, 8000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(-50.0f, 0.0f, 11000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(0.0f, 0.0f, 13000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(50.0f, 0.0f, 16000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(100.0f, 0.0f, 21000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 26000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(-80.0f, 0.0f, 31000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 36000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(0.0f, 0.0f, 42000.0f), 1);
		SetCheckPoint(XMFLOAT3(CENTER, 25.0f, 21450.0f));
		SetGoal(XMFLOAT3(CENTER, 25.0f, 42900.0f));
		break;
	case SCENE_STAGE3_1:
		//0ïÅí 1í«è]2íµÇÀÇÈ3óéâ∫4í«è]óéâ∫6ñ≥ìG
		//0ïÅí 1â°2èc3óéâ∫4í«è]óéâ∫6ñ≥ìG
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 3000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 4000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 6000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 1);
		SetDEnemy(XMFLOAT3(-60.0f, 0.0f, 7000.0f), XMFLOAT3(0.0f, 3.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 8000.0f), XMFLOAT3(0.0f, 3.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 3000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 4000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 6000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 1);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 7000.0f), XMFLOAT3(0.0f, 3.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 8000.0f), XMFLOAT3(0.0f, 3.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);

		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 0);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 0);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 0);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 0);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 0);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 0);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 0);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 0);

		SetUEnemy(XMFLOAT3(-60.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 12000.0f), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 5.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 12000.0f), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 5.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(20.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 20000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 22000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 23000.0f), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 5.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 24500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 20000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(10.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 22000.0f), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 23000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 3.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 24500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 21000.0f), XMFLOAT3(5.0f, 0.0f, 2.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 22000.0f), XMFLOAT3(0.0f, 5.0f, 2.0f), 2);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 22000.0f), XMFLOAT3(0.0f, 5.0f, 2.0f), 2);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 23000.0f), XMFLOAT3(5.0f, 0.0f, 2.0f), 1);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 5.0f, 2.0f), 2);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 5.0f, 2.0f), 2);

		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, 0.0f, 3.0f), 7);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 26000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 27000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetUEnemy(XMFLOAT3(-10.0f, 0.0f, 29500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 27000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 0);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 27000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 0);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 0);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 0);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), 1);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 3.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 5.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 3.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 5.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, -5.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 5.0f, 0.0f), 2);
		SetDEnemy(XMFLOAT3(-60.0f, 0.0f, 31500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(30.0f, 0.0f, 32500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 33500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 34500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 39000.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), 1);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 35000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(40.0f, 0.0f, 36000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(-60.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(20.0f, 0.0f, 39000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 35000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 36000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 39000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		
		SetCar(XMFLOAT3(80.0f, 0.0f, 6000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);
		SetCar(XMFLOAT3(0.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);
		SetCar(XMFLOAT3(0.0f, 0.0f, 30000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);
		SetCar(XMFLOAT3(80.0f, 0.0f, 40000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);
		SetCar(XMFLOAT3(-80.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);
		SetCar(XMFLOAT3(-40.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);
		SetCar(XMFLOAT3(40.0f, 0.0f, 36000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);
		SetCar(XMFLOAT3(-80.0f, 0.0f, 40000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 40500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 40500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 41000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-60.0f, 0.0f, 41000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 41500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 41500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(30.0f, 0.0f, 41500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 41500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		for (int i = 0; i < 8; i++)
		{
			SetHole(XMFLOAT3(-50.0f + (50.0f * (i % 3)), 0.1f, 5000.0f * (i + 1)), XMFLOAT3(1.0f, 1.0f, 1.0f));
		}
		SetItemQuantity(10, XMFLOAT3(-50.0f, 0.0f, 3000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(30.0f, 0.0f, 8000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-50.0f, 50.0f, 10000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(30.0f, 0.0f, 13000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(50.0f, 0.0f, 16000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 20000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 26000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-80.0f, 0.0f, 31000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 35000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(0.0f, 50.0f, 42000.0f), 1);
		SetCheckPoint(XMFLOAT3(CENTER, 25.0f, 21450.0f));
		SetGoal(XMFLOAT3(CENTER, 25.0f, 42900.0f));
		break;
	case SCENE_STAGE3_2://2700+4000x
		for (int i = 0; i < 10; i++)
		{
			if (i % 3 == 0)
			{
				SetCar(XMFLOAT3(60.0f, 0.0f, 4000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);//-2200
				SetCar(XMFLOAT3(-60.0f, 0.0f, 4000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);//-2200
			}
			else SetCar(XMFLOAT3(0.0f, 0.0f, 4000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);//-2200
		}
		for (int i = 0; i < 8; i++)
		{
			SetDEnemy(XMFLOAT3(0.0f, 0.0f, 5000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		}

		SetDEnemy(XMFLOAT3(100.0f, 0.0f, 5000.0f), XMFLOAT3(-0.3f, 0.0f, -1.0f), 0);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 6000.0f), XMFLOAT3(-0.2f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-100.0f, 0.0f, 7000.0f), XMFLOAT3(0.3f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 5.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 11000.0f), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 12000.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 15000.0f), XMFLOAT3(0.0f, 0.0f, 0.3f), 3);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 15000.0f), XMFLOAT3(0.0f, 0.0f, 0.3f), 3);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(20.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 18000.0f), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-60.0f, 0.0f, 18000.0f), XMFLOAT3(-5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 5.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, 0.3f), 3);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, 0.3f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 22000.0f), XMFLOAT3(0.0f, 0.0f, 0.3f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 22000.0f), XMFLOAT3(0.0f, 0.0f, 0.3f), 3);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 23000.0f), XMFLOAT3(0.0f, 0.0f, 0.3f), 3);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 23000.0f), XMFLOAT3(0.0f, 0.0f, 0.3f), 3);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 0.0f, 0.3f), 3);
		SetDEnemy(XMFLOAT3(-40.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 0.0f, 0.3f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, 0.0f, 0.3f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, 0.0f, 0.3f), 3);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 27000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-60.0f, 0.0f, 27000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(-30.0f, 0.0f, 28000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 4);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 29000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-60.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 4);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 30000.0f), XMFLOAT3(-0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-60.0f, 0.0f, 30000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 3);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 7);
		SetCar(XMFLOAT3(100.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);
		SetCar(XMFLOAT3(-100.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(20.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(-60.0f, 0.0f, 36000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 36000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(-60.0f, 0.0f, 37000.0f), XMFLOAT3(5.0f, 0.0f, -5.0f), 1);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 37000.0f), XMFLOAT3(-5.0f, 0.0f, -5.0f), 1);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, -5.0f, -5.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 5.0f, -5.0f), 2);

		SetCar(XMFLOAT3(50.0f, 0.0f, 41000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);
		SetCar(XMFLOAT3(0.0f, 0.0f, 41000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);
		SetCar(XMFLOAT3(-50.0f, 0.0f, 41000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);
		SetCar(XMFLOAT3(50.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);
		SetCar(XMFLOAT3(0.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);

		SetUEnemy(XMFLOAT3(-60.0f, 0.0f, 41000.0f), XMFLOAT3(5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 41000.0f), XMFLOAT3(5.0f, 0.0f, -0.0f), 1);
		SetCar(XMFLOAT3(20.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetCar(XMFLOAT3(60.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetCar(XMFLOAT3(-20.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetCar(XMFLOAT3(-60.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);

		SetItemQuantity(10, XMFLOAT3(-50.0f, 0.0f, 4000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(30.0f, 0.0f, 8000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-50.0f, 50.0f, 10000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(30.0f, 0.0f, 13000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(50.0f, 0.0f, 16000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-100.0f, 0.0f, 20000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(-30.0f, 0.0f, 26000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-80.0f, 0.0f, 31000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 35000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(0.0f, 50.0f, 42000.0f), 1);
		SetCheckPoint(XMFLOAT3(CENTER, 25.0f, 21450.0f));
		SetGoal(XMFLOAT3(CENTER, 25.0f, 42900.0f));
		break;
	case SCENE_STAGE3_3:
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 3000.0f), XMFLOAT3(5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 3000.0f), XMFLOAT3(-5.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 4000.0f), XMFLOAT3(0.0f, 6.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 4000.0f), XMFLOAT3(0.0f, 3.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-60.0f, 0.0f, 4000.0f), XMFLOAT3(0.0f, 4.0f, 0.0f), 2);

		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 5000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 7);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 6000.0f), XMFLOAT3(5.0f, 0.0f, -1.0f), 1);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 6000.0f), XMFLOAT3(5.0f, 0.0f, -1.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 7000.0f), XMFLOAT3(0.0f, 5.0f, -2.0f), 2);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 7000.0f), XMFLOAT3(0.0f, -5.0f, -2.0f), 2);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 8000.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 0);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 8000.0f), XMFLOAT3(5.0f, 0.0f, -3.0f), 1);
		SetUEnemy(XMFLOAT3(70.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 0.0f, -4.0f), 0);
		SetUEnemy(XMFLOAT3(-70.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 6000.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 0);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 7000.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 0);
		SetDEnemy(XMFLOAT3(20.0f, 0.0f, 8000.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 0);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 0);
		SetDEnemy(XMFLOAT3(70.0f, 0.0f, 10000.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 0);

		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 12000.0f), XMFLOAT3(5.0f, 0.0f, -1.0f), 1);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 12000.0f), XMFLOAT3(-5.0f, 0.0f, -1.0f), 1);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(20.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(40.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, -5.0f, -2.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, -5.0f, -2.0f), 2);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, -5.0f, -2.0f), 2);
		SetUEnemy(XMFLOAT3(-60.0f, 0.0f, 15000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(-60.0f, 0.0f, 15000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 3);

		SetDEnemy(XMFLOAT3(-60.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(30.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(70.0f, 0.0f, 17500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 18500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(-50.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 19500.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 3);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 16000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, -5.0f, -0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 17000.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, -5.0f, -0.0f), 2);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 18500.0f), XMFLOAT3(-5.0f, 0.0f, -0.0f), 1);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 18500.0f), XMFLOAT3(0.0f, -5.0f, -0.0f), 2);

		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 20000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 7);
		SetUEnemy(XMFLOAT3(-50.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, -5.0f, -1.0f), 2);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, -5.0f, -1.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 22000.0f), XMFLOAT3(0.0f, -5.0f, -5.0f), 2);
		SetUEnemy(XMFLOAT3(50.0f, 0.0f, 23000.0f), XMFLOAT3(0.0f, -5.0f, -3.0f), 2);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, -5.0f, -2.0f), 2);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, -5.0f, -2.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 7);
		SetUEnemy(XMFLOAT3(70.0f, 0.0f, 26000.0f), XMFLOAT3(0.0f, -5.0f, -1.0f), 2);
		SetUEnemy(XMFLOAT3(-60.0f, 0.0f, 27000.0f), XMFLOAT3(0.0f, -5.0f, -4.0f), 2);
		SetUEnemy(XMFLOAT3(10.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, -5.0f, -3.0f), 2);
		SetUEnemy(XMFLOAT3(-60.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, -5.0f, -3.0f), 2);
		SetUEnemy(XMFLOAT3(-70.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, -5.0f, -2.0f), 2);
		SetCar(XMFLOAT3(50.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);
		SetCar(XMFLOAT3(0.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);
		SetCar(XMFLOAT3(50.0f, 0.0f, 26000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);
		SetCar(XMFLOAT3(-50.0f, 0.0f, 27000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);
		SetCar(XMFLOAT3(-50.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);
		SetCar(XMFLOAT3(50.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);
		SetCar(XMFLOAT3(0.0f, 0.0f, 30000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);
		SetCar(XMFLOAT3(0.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);
		SetDEnemy(XMFLOAT3(20.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(-60.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 27000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 30000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 7);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 35000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 7);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 30000.0f), XMFLOAT3(0.0f, 3.0f, 7.5f), 2);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 30000.0f), XMFLOAT3(0.0f, -3.0f, 7.5f), 2);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 3.0f, 7.3f), 2);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, -3.0f, 7.3f), 2);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 3.0f, 7.1f), 2);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, -3.0f, 7.1f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 36000.0f), XMFLOAT3(3.0f, 0.0f, 7.8f), 1);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 36000.0f), XMFLOAT3(-3.0f, 0.0f, 7.8f), 1);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 37000.0f), XMFLOAT3(3.0f, 0.0f, 7.5f), 1);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 37000.0f), XMFLOAT3(-3.0f, 0.0f, 7.5f), 1);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 38000.0f), XMFLOAT3(3.0f, 0.0f, 7.0f), 1);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 38000.0f), XMFLOAT3(-3.0f, 0.0f, 7.0f), 1);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(40.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-40.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 34000.0f), XMFLOAT3(-0.3f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 34000.0f), XMFLOAT3(-0.3f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 35000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 35000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 36000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 4);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 36000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 4);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 4);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 4);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 39000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 39000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(90.0f, 0.0f, 33000.0f), XMFLOAT3(-0.5f, 0.0f, -6.0f), 0);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, -6.0f), 0);
		SetDEnemy(XMFLOAT3(-90.0f, 0.0f, 40000.0f), XMFLOAT3(0.5f, 0.0f, -6.0f), 0);

		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, -3.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, -3.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, -3.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, -3.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, -3.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 36000.0f), XMFLOAT3(3.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 36000.0f), XMFLOAT3(-3.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 36000.0f), XMFLOAT3(3.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(40.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-40.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		for (int i = 0; i < 8; i++)
		{
			SetHole(XMFLOAT3(-60.0f, 0.1f, 5000.0f * (i + 1)), XMFLOAT3(1.0f, 1.0f, 1.0f));
			SetHole(XMFLOAT3(60.0f, 0.1f, 5000.0f * (i + 1)), XMFLOAT3(1.0f, 1.0f, 1.0f));
		}
		SetItemQuantity(10, XMFLOAT3(-50.0f, 0.0f, 3000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(30.0f, 0.0f, 8000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(0.0f, 50.0f, 10000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(30.0f, 0.0f, 13000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(50.0f, 0.0f, 16000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(0.0f, 50.0f, 20000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 26000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-80.0f, 0.0f, 31000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(0.0f, 0.0f, 35000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(60.0f, 0.0f, 42000.0f), 1);
		SetCheckPoint(XMFLOAT3(CENTER, 25.0f, 21450.0f));
		SetGoal(XMFLOAT3(CENTER, 25.0f, 42900.0f));
		break;
	case SCENE_STAGE3_4:
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 3000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 7);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 4000.0f), XMFLOAT3(0.0f, 3.0f, 7.5f), 2);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 4000.0f), XMFLOAT3(0.0f, -3.0f, 7.5f), 2);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 5000.0f), XMFLOAT3(0.0f, 3.0f, 7.3f), 2);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 5000.0f), XMFLOAT3(0.0f, -3.0f, 7.3f), 2);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 6000.0f), XMFLOAT3(0.0f, 3.0f, 7.1f), 2);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 6000.0f), XMFLOAT3(0.0f, -3.0f, 7.1f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 7000.0f), XMFLOAT3(3.0f, 0.0f, 7.8f), 1);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 7000.0f), XMFLOAT3(-3.0f, 0.0f, 7.8f), 1);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 8000.0f), XMFLOAT3(3.0f, 0.0f, 7.5f), 1);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 8000.0f), XMFLOAT3(-3.0f, 0.0f, 7.5f), 1);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 9000.0f), XMFLOAT3(3.0f, 0.0f, 7.0f), 1);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 9000.0f), XMFLOAT3(-3.0f, 0.0f, 7.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 3000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 0);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 4000.0f), XMFLOAT3(0.0f, 0.0f, 3.0f), 0);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 5000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 0);
		SetDEnemy(XMFLOAT3(40.0f, 0.0f, 6000.0f), XMFLOAT3(0.0f, 0.0f, 8.0f), 0);
		SetDEnemy(XMFLOAT3(90.0f, 0.0f, 7000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 0);
		SetDEnemy(XMFLOAT3(-30.0f, 0.0f, 8000.0f), XMFLOAT3(0.0f, 0.0f, 2.0f), 0);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 0);
		SetDEnemy(XMFLOAT3(10.0f, 0.0f, 10000.0f), XMFLOAT3(0.0f, 0.0f, 9.0f), 0);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, 0.0f, 2.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, 3.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 15000.0f), XMFLOAT3(0.0f, 0.0f, 5.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, 7.0f), 1);
		SetDEnemy(XMFLOAT3(50.0f, 0.0f, 11000.0f), XMFLOAT3(0.0f, 3.0f, 7.0f), 2);
		SetDEnemy(XMFLOAT3(20.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, 3.0f, 7.0f), 2);
		SetDEnemy(XMFLOAT3(-40.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, -3.0f, 7.0f), 2);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 3.0f, 7.0f), 2);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 3.0f, 7.0f), 2);
		SetDEnemy(XMFLOAT3(20.0f, 0.0f, 15000.0f), XMFLOAT3(0.0f, 3.0f, 7.0f), 2);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 15000.0f), XMFLOAT3(0.0f, -3.0f, 7.0f), 2);
		SetDEnemy(XMFLOAT3(-70.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, 3.0f, 7.0f), 2);
		SetDEnemy(XMFLOAT3(10.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 3.0f, 7.0f), 2);
		SetUEnemy(XMFLOAT3(-0.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 4);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 12000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 4);
		SetUEnemy(XMFLOAT3(-0.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 4);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 4);
		SetUEnemy(XMFLOAT3(-0.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 4);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 4);
		SetUEnemy(XMFLOAT3(-0.0f, 0.0f, 15000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 4);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 15000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 4);
		SetUEnemy(XMFLOAT3(-0.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, -8.0f), 4);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 16000.0f), XMFLOAT3(0.0f, 0.0f, -8.0f), 4);
		SetUEnemy(XMFLOAT3(-0.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 4);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 4);
		SetUEnemy(XMFLOAT3(-0.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 4);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 4);
		SetUEnemy(XMFLOAT3(-0.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(20.0f, 0.0f, 12000.0f), XMFLOAT3(3.0f, 0.0f, 7.8f), 1);
		SetUEnemy(XMFLOAT3(-0.0f, 0.0f, 14000.0f), XMFLOAT3(0.0f, 3.0f, 7.8f), 2);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 18000.0f), XMFLOAT3(3.0f, 0.0f, 7.8f), 1);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 18000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 7);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 0.0f, 6.1f), 7);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), 0);
		SetDEnemy(XMFLOAT3(20.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetDEnemy(XMFLOAT3(-40.0f, 0.0f, 23000.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), 0);
		SetDEnemy(XMFLOAT3(40.0f, 0.0f, 23000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 22000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 22000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 22000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 22000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 24000.0f), XMFLOAT3(-0.2f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 24000.0f), XMFLOAT3(-0.2f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 22000.0f), XMFLOAT3(0.0f, -3.0f, -5.0f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 22000.0f), XMFLOAT3(3.0f, 0.0f, -5.0f), 1);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 24000.0f), XMFLOAT3(0.0f, -3.0f, -5.0f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 24000.0f), XMFLOAT3(3.0f, 0.0f, -5.0f), 1);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 26000.0f), XMFLOAT3(0.0f, -3.0f, -5.0f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 26000.0f), XMFLOAT3(3.0f, 0.0f, -5.0f), 1);

		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, -3.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, -3.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, -3.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, -3.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, -3.0f, 0.0f), 2);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 26000.0f), XMFLOAT3(3.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 26000.0f), XMFLOAT3(-3.0f, 0.0f, 0.0f), 1);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 26000.0f), XMFLOAT3(3.0f, 0.0f, 0.0f), 1);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 26000.0f), XMFLOAT3(0.0f, 0.0f, 7.0f), 7);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 27000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 7);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, 0.0f, 5.0f), 7);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, 4.0f), 7);
		SetDEnemy(XMFLOAT3(-40.0f, 0.0f, 27000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 27000.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 0);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-60.0f, 0.0f, 28000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetDEnemy(XMFLOAT3(-70.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 0);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 30000.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), 0);
		SetDEnemy(XMFLOAT3(-40.0f, 0.0f, 30000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 0.0f, 5.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, 6.0f), 1);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 35000.0f), XMFLOAT3(0.0f, 0.0f, 7.0f), 1);
		SetUEnemy(XMFLOAT3(-60.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-60.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(60.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-0.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-0.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-0.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 3.0f, -3.0f), 2);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, -3.0f, -3.0f), 2);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 3.0f, -3.0f), 2);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 31000.0f), XMFLOAT3(3.0f, 0.0f, 7.8f), 1);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 33000.0f), XMFLOAT3(3.0f, 0.0f, 7.8f), 1);
		SetUEnemy(XMFLOAT3(-20.0f, 0.0f, 37000.0f), XMFLOAT3(3.0f, 0.0f, 7.8f), 1);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 36000.0f), XMFLOAT3(-0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 36000.0f), XMFLOAT3(-0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 38000.0f), XMFLOAT3(-0.0f, 0.0f, 0.0f), 4);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 38000.0f), XMFLOAT3(-0.0f, 0.0f, 0.0f), 4);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), 0);
		SetDEnemy(XMFLOAT3(-40.0f, 0.0f, 32000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, -2.0f), 0);
		SetDEnemy(XMFLOAT3(60.0f, 0.0f, 34000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		SetUEnemy(XMFLOAT3(30.0f, 0.0f, 35000.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), 0);
		SetDEnemy(XMFLOAT3(-20.0f, 0.0f, 36000.0f), XMFLOAT3(0.0f, 0.0f, -8.0f), 0);
		SetUEnemy(XMFLOAT3(10.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), 0);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 38000.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), 0);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 39000.0f), XMFLOAT3(0.0f, 0.0f, -3.0f), 0);
		SetDEnemy(XMFLOAT3(90.0f, 0.0f, 40000.0f), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);

		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 40500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetUEnemy(XMFLOAT3(0.0f, 0.0f, 41000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetDEnemy(XMFLOAT3(0.0f, 0.0f, 41500.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(-40.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(-40.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(40.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(40.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetUEnemy(XMFLOAT3(80.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetDEnemy(XMFLOAT3(80.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);

		SetHole(XMFLOAT3(-60.0f, 0.1f, 30000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(0.0f, 0.1f, 30000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(60.0f, 0.1f, 30000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(-60.0f, 0.1f, 34000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(0.0f, 0.1f, 34000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(-60.0f, 0.1f, 38000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(60.0f, 0.1f, 38000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(-60.0f, 0.1f, 40000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(0.0f, 0.1f, 40000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetHole(XMFLOAT3(60.0f, 0.1f, 40000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));
		SetCar(XMFLOAT3(0.0f, 0.0f, 31000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);	//-2200
		SetCar(XMFLOAT3(60.0f, 0.0f, 30000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);	//-2200
		SetCar(XMFLOAT3(0.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);	//-2200
		SetCar(XMFLOAT3(30.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);	//-2200
		SetCar(XMFLOAT3(0.0f, 0.0f, 35000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);	//-2200
		SetCar(XMFLOAT3(-30.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);	//-2200
		SetCar(XMFLOAT3(-40.0f, 0.0f, 39000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);	//-2200
		SetCar(XMFLOAT3(0.0f, 0.0f, 39000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);	//-2200
		SetCar(XMFLOAT3(50.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);	//-2200
		SetCar(XMFLOAT3(0.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);	//-2200
		SetCar(XMFLOAT3(-50.0f, 0.0f, 42000.0f), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);	//-2200
		for (int i = 0; i < 10; i++)
		{
			if (i % 3 == 0)
			{
				SetHole(XMFLOAT3(-60.0f, 0.1f, 4000.0f * (i + 1)), XMFLOAT3(1.0f, 1.0f, 1.0f));
				SetHole(XMFLOAT3(60.0f, 0.1f, 4000.0f * (i + 1)), XMFLOAT3(1.0f, 1.0f, 1.0f));
			}
			else SetHole(XMFLOAT3(0.0f, 0.1f, 4000.0f * (i + 1)), XMFLOAT3(1.0f, 1.0f, 1.0f));
		}
		for (int i = 0; i < 10; i++)
		{
			if (i % 3 == 0)
			{
				SetCar(XMFLOAT3(0.0f, 0.0f, 4000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, -20.0f), 3);//-2200
			}
			else
			{
				SetCar(XMFLOAT3(60.0f, 0.0f, 4000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);//-2200
				SetCar(XMFLOAT3(-60.0f, 0.0f, 4000.0f * (i + 1)), XMFLOAT3(0.0f, 0.0f, -20.0f), 4);//-2200
			}
		}
		for (int i = 0; i < 10; i++)
		{
			SetUEnemy(XMFLOAT3(80.0f, 0.0f, 4000.0f * (i + 1) - 1500), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
			SetDEnemy(XMFLOAT3(80.0f, 0.0f, 4000.0f * (i + 1) - 1500), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
			SetUEnemy(XMFLOAT3(0.0f, 0.0f, 4000.0f * (i + 1) - 1500), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
			SetDEnemy(XMFLOAT3(0.0f, 0.0f, 4000.0f * (i + 1) - 1500), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
			SetUEnemy(XMFLOAT3(-80.0f, 0.0f, 4000.0f * (i + 1) - 1500), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
			SetDEnemy(XMFLOAT3(-80.0f, 0.0f, 4000.0f * (i + 1) - 1500), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		}
		SetItemQuantity(10, XMFLOAT3(-50.0f, 0.0f, 4000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(30.0f, 0.0f, 8000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-50.0f, 50.0f, 10000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(30.0f, 0.0f, 13000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(50.0f, 0.0f, 16000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-100.0f, 0.0f, 20000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 26000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(-80.0f, 0.0f, 31000.0f), 1);
		SetItemQuantity(10, XMFLOAT3(80.0f, 0.0f, 35000.0f), 0);
		SetItemQuantity(10, XMFLOAT3(0.0f, 50.0f, 42000.0f), 1);
		SetCheckPoint(XMFLOAT3(CENTER, 25.0f, 21450.0f));
		SetGoal(XMFLOAT3(CENTER, 25.0f, 42900.0f));
		break;

	case SCENE_ENDING:
		SetText(XMFLOAT3(0.0f, 50.0f, 1000.0f), XMFLOAT3(2.5f, 2.5f, 2.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 0);
		SetText(XMFLOAT3(0.0f, 50.0f, 1500.0f), XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 1);


		SetText(XMFLOAT3(0.0f, 50.0f, 2500.0f),XMFLOAT3(2.0f, 2.0f, 2.0f), XMFLOAT3(0.0f, 0.0f, 0.0f), 2);
		SetText(XMFLOAT3(0.0f, 50.0f, 3000.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 3);
		SetText(XMFLOAT3(0.0f, 50.0f, 3500.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 4);
		SetText(XMFLOAT3(0.0f, 50.0f, 4000.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 5);

		SetText(XMFLOAT3(0.0f, 50.0f, 5000.0f), XMFLOAT3(2.5f, 2.5f, 2.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 6);

		SetText(XMFLOAT3(0.0f, 50.0f, 6000.0f),XMFLOAT3(2.5f, 2.5f, 2.5f),XMFLOAT3(0.0f, 0.0f, 0.0f), 7);
		SetText(XMFLOAT3(0.0f, 50.0f, 6500.0f),XMFLOAT3(1.5f, 1.5f, 1.5f),XMFLOAT3(0.0f, 0.0f, 0.0f), 8);
		SetText(XMFLOAT3(0.0f, 50.0f, 7000.0f),XMFLOAT3(1.5f, 1.5f, 1.5f),XMFLOAT3(0.0f, 0.0f, 0.0f), 9);

		SetText(XMFLOAT3(0.0f, 50.0f, 8000.0f),XMFLOAT3(2.5f, 2.5f, 2.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 10);
		SetText(XMFLOAT3(0.0f, 50.0f, 8500.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 11);
		SetText(XMFLOAT3(0.0f, 50.0f, 9000.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 12);
		SetText(XMFLOAT3(0.0f, 50.0f, 9500.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 13);

		SetText(XMFLOAT3(0.0f, 50.0f, 10500.0f),XMFLOAT3(2.5f, 2.5f, 2.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 14);
		SetText(XMFLOAT3(0.0f, 50.0f, 11000.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 15);

		SetText(XMFLOAT3(0.0f, 50.0f, 12000.0f),XMFLOAT3(2.5f, 2.5f, 2.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 16);
		SetText(XMFLOAT3(0.0f, 50.0f, 12500.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 17);
		SetText(XMFLOAT3(0.0f, 50.0f, 13000.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 18);
		SetText(XMFLOAT3(0.0f, 50.0f, 13500.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 19);
		SetText(XMFLOAT3(0.0f, 50.0f, 14000.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 20);

		SetText(XMFLOAT3(0.0f, 50.0f, 15000.0f),XMFLOAT3(2.5f, 2.5f, 2.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 21);
		SetText(XMFLOAT3(0.0f, 50.0f, 15500.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 22);
		SetText(XMFLOAT3(0.0f, 50.0f, 16000.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 23);
		SetText(XMFLOAT3(0.0f, 50.0f, 16500.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 24);
		SetText(XMFLOAT3(0.0f, 50.0f, 17000.0f),XMFLOAT3(1.5f, 1.5f, 1.5f), XMFLOAT3(0.0f, 0.0f, 0.0f), 25);

		SetText(XMFLOAT3(0.0f, 50.0f, 18000.0f), XMFLOAT3(2.8f, 2.8f, 2.8f), XMFLOAT3(0.0f, 0.0f, 0.0f), 26);
		break;
	}
}

void SetStageHint()
{
	switch (GetSceneNo())
	{
	case SCENE_STAGE1_1:
		if (GetPlayerPos(0).z >= 1000.0f && GetPlayerPos(0).z <= 1100.0f) {
			SetSign(XMFLOAT3(140.0f, 0.0f, 3500.0f), XMFLOAT3(0.0f, 35.0f, 0.0f));
			SetHint(6);
		}
		if (GetPlayerPos(0).z >= 3500.0f && GetPlayerPos(0).z <= 3600.0f) {
			SetSign(XMFLOAT3(-140.0f, 0.0f, 6000.0f), XMFLOAT3(0.0f, -35.0f, 0.0f));
			SetHint(7);
		}
		if (GetPlayerPos(0).z >= 6300.0f && GetPlayerPos(0).z <= 6400.0f) {
			SetSign(XMFLOAT3(140.0f, 0.0f, 9300.0f), XMFLOAT3(0.0f, 35.0f, 0.0f));
			SetHint(1);
		}
		if (GetPlayerPos(0).z >= 9500.0f && GetPlayerPos(0).z <= 9600.0f) {
			SetSign(XMFLOAT3(140.0f, 0.0f, 14200.0f), XMFLOAT3(0.0f, 35.0f, 0.0f));
			SetHint(2);
		}
		if (GetPlayerPos(0).z >= 14000.0f && GetPlayerPos(0).z <= 14100.0f) {
			SetSign(XMFLOAT3(140.0f, 0.0f, 19000.0f), XMFLOAT3(0.0f, 35.0f, 0.0f));
			SetHint(3);
		}

		break;
	case SCENE_STAGE1_2:
		break;
	case SCENE_STAGE1_3:
		break;
	case SCENE_STAGE1_4:
		break;
	case SCENE_STAGE2_1:
		break;
	case SCENE_STAGE2_2:
		break;
	case SCENE_STAGE2_3:
		break;
	case SCENE_STAGE2_4:
		break;
	case SCENE_STAGE3_1:
		break;
	case SCENE_STAGE3_2:
		break;
	case SCENE_STAGE3_3:
		break;
	case SCENE_STAGE3_4:
		break;
	}
}

void SetItemQuantity(int no, XMFLOAT3 pos,int type)
{
	//noÅcê›íuÇµÇΩÇ¢å¬êî
	//posÅcç≈èâÇÃà íu
	//typeÅcÇOÇÃéûÇÕèc1óÒÇ…ÇPÇÃéûÇÕ1Ç©èäÇ…Ç»ÇÈ
	for (int i = 0; i < no; i++)
	{
		if (type == 0)SetItem(XMFLOAT3(pos.x, pos.y, pos.z + 50.0f * (float)i), 0);
		if (type == 1)SetItem(XMFLOAT3(pos.x, pos.y, pos.z), 1);
	}
}

void SetAllEnemyType(XMFLOAT2 no/*XóÒ,ZóÒ*/ , XMFLOAT4 no2/*ìGÇÃéÌóﬁÅi1ëÃñ⁄,2ëÃñ⁄,3ëÃñ⁄,4ëÃñ⁄Åj*/,float pos/*(ç≈èâÇÃZÇÃà íu)*/)
{
	/*//////////////////////////////////////égÇ¢ï˚//////////////////////////////////////
	noÅc(Xé≤ÇÃíuÇ´ï˚,Zé≤ÇÃíuÇ´ï˚)

		Xé≤ÇÃíuÇ´ï˚(0Å`3)
		ÇOÅcÅ@Å¶Å¶Å¶Å¶
		ÇPÅcÅ¶Å¶Å¶Å¶Å@
		ÇQÅcÅ¶Å@Å¶Å¶Å¶
		ÇRÅcÅ¶Å¶Å@Å¶Å¶
		ÇSÅcÅ¶Å¶Å¶Å@Å¶

		Zé≤ÇÃíuÇ´ï˚(0Å`255)
		Å@Å@Å@Å¶3
		    Å¶Å@2
		Å@Å¶Å@Å@1
		Å¶Å@Å@Å@0
		ÅbÅbÅbÅb
		ÇOÇPÇQÇR
		Å~Å~Å~Å~
		6416 4 1
		Ç±ÇÃèÍçáÅu27ÅvÇ∆Ç»ÇÈ
		Å¶Å@Å@Å@
		  Å¶Å@Å@
		Å@Å@Å¶Å@
		Å@Å@Å@Å¶
		ÅbÅbÅbÅb
		ÇRÇQÇPÇO
		Å~Å~Å~Å~
		6416 4 1
		Ç±ÇÃèÍçáÅu228ÅvÇ∆Ç»ÇÈ

	no2(4ëÃï™ÇÃìGÇÃéÌóﬁÇåàÇﬂÇÁÇÍÇÈ)

		-1Åcèoåªñ≥Çµ
		ÇOÅcóéÇ∆Çµåä
		ÇPÅcé‘
		ÇQÅcÉ^ÉNÉVÅ[
		ÇRÅcÉXÉâÉCÉÄ
		ÇSÅcîÚÇÒÇ≈ÇÈìG

	pos(èoåªÇ∑ÇÈèÍèäÅcàÍî‘ç∂äÓèÄ)
	*/
	static XMFLOAT4 PosXAd;
	static XMFLOAT4 PosZAd;
	PosXAd = XMFLOAT4(0.0f, 0.0f, 0.0f,0.0f);
	PosZAd = XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f);
	if (no.x == 0)PosXAd.w = 40.0f;
	if (no.x == 2)PosXAd.x = 40.0f;
	if (no.x == 3)PosXAd.y = 40.0f;
	if (no.x == 4)PosXAd.z = 40.0f;
	PosZAd = XMFLOAT4((int)no.y / 64 % 4 * ENEMYRANGE, (int)no.y /16 % 4 * ENEMYRANGE, (int)no.y / 4 % 4 * ENEMYRANGE, (int)no.y % 4 * ENEMYRANGE);
	
	switch ((int)no2.x)
	{
	case(0):
		SetHole(XMFLOAT3(-80.0f + PosXAd.w, 0.0f + 0.1f, pos + PosZAd.x), XMFLOAT3(1.0f, 1.0f, 1.0f));
		break;
	case(1):
		SetCar(XMFLOAT3(-80.0f + PosXAd.w, 0.0f, pos + PosZAd.x), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		break;
	case(2):
		SetCar(XMFLOAT3(-80.0f + PosXAd.w, 0.0f, pos + PosZAd.x), XMFLOAT3(0.0f, 0.0f, -7.0f), 1);
		break;
	case(3):
		SetUEnemy(XMFLOAT3(-80.0f + PosXAd.w, 0.0f, pos + PosZAd.x), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		break;
	case(4):
		SetDEnemy(XMFLOAT3(-80.0f + PosXAd.w, 0.0f, pos + PosZAd.x), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		break;
	default:
		break;
	}
	switch ((int)no2.y)
	{
	case(0):
		SetHole(XMFLOAT3(-80.0f + 40.0f + PosXAd.w + PosXAd.x, 0.0f + 0.1f, pos + PosZAd.y), XMFLOAT3(1.0f, 1.0f, 1.0f));
		break;
	case(1):
		SetCar(XMFLOAT3(-80.0f + 40.0f + PosXAd.w + PosXAd.x, 0.0f, pos + PosZAd.y), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		break;
	case(2):
		SetCar(XMFLOAT3(-80.0f + 40.0f + PosXAd.w + PosXAd.x, 0.0f, pos + PosZAd.y), XMFLOAT3(0.0f, 0.0f, -7.0f), 1);
		break;
	case(3):
		SetUEnemy(XMFLOAT3(-80.0f + 40.0f + PosXAd.w + PosXAd.x, 0.0f, pos + PosZAd.y), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		break;
	case(4):
		SetDEnemy(XMFLOAT3(-80.0f + 40.0f + PosXAd.w + PosXAd.x, 0.0f, pos + PosZAd.y), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		break;
	default:
		break;
	}
	switch ((int)no2.z)
	{
	case(0):
		SetHole(XMFLOAT3(-80.0f + 80.0f + PosXAd.w + PosXAd.x + PosXAd.y, 0.0f + 0.1f, pos + PosZAd.z), XMFLOAT3(1.0f, 1.0f, 1.0f));
		break;
	case(1):
		SetCar(XMFLOAT3(-80.0f + 80.0f + PosXAd.w + PosXAd.x + PosXAd.y, 0.0f, pos + PosZAd.z), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		break;
	case(2):
		SetCar(XMFLOAT3(-80.0f + 80.0f + PosXAd.w + PosXAd.x + PosXAd.y, 0.0f, pos + PosZAd.z), XMFLOAT3(0.0f, 0.0f, -7.0f), 1);
		break;
	case(3):
		SetUEnemy(XMFLOAT3(-80.0f + 80.0f + PosXAd.w + PosXAd.x + PosXAd.y, 0.0f, pos + PosZAd.z), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		break;
	case(4):
		SetDEnemy(XMFLOAT3(-80.0f + 80.0f + PosXAd.w + PosXAd.x + PosXAd.y, 0.0f, pos + PosZAd.z), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		break;
	default:
		break;
	}
	switch ((int)no2.w)
	{
	case(0):
		SetHole(XMFLOAT3(-80.0f + 120.0f + PosXAd.w + PosXAd.x + PosXAd.y + PosXAd.z, 0.0f + 0.1f, pos + PosZAd.w), XMFLOAT3(1.0f, 1.0f, 1.0f));
		break;
	case(1):
		SetCar(XMFLOAT3(-80.0f + 120.0f + PosXAd.w + PosXAd.x + PosXAd.y + PosXAd.z, 0.0f, pos + PosZAd.w), XMFLOAT3(0.0f, 0.0f, -7.0f), 0);
		break;
	case(2):
		SetCar(XMFLOAT3(-80.0f + 120.0f + PosXAd.w + PosXAd.x + PosXAd.y + PosXAd.z, 0.0f, pos + PosZAd.w), XMFLOAT3(0.0f, 0.0f, -7.0f), 1);
		break;
	case(3):
		SetUEnemy(XMFLOAT3(-80.0f + 120.0f + PosXAd.w + PosXAd.x + PosXAd.y + PosXAd.z, 0.0f, pos + PosZAd.w), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		break;
	case(4):
		SetDEnemy(XMFLOAT3(-80.0f + 120.0f + PosXAd.w + PosXAd.x + PosXAd.y + PosXAd.z, 0.0f, pos + PosZAd.w), XMFLOAT3(0.0f, 0.0f, -5.0f), 0);
		break;
	default:
		break;
	}
}