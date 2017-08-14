#include "Locations.h"
#include "Miner.h"
#include "MinersWife.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"
class A
{
public:
	static int a;

};


int main()
{
	//create a miner
	Miner miner(ent_Miner_Bob);
	MinersWife Elsa(ent_Elsa);
	//simply run the miner through a few Update calls
	for (int i = 0; i<200; ++i)
	{
		miner.Update();
		Elsa.Update();
		//Sleep(500);
	}

	//wait for a keypress before exiting
	PressAnyKeyToContinue();

	return 0;
}