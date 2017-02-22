#include "Locations.h"
#include "Miner.h"
#include "MinersWife.h"
#include "msg/MessageDispatcher.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"
#include "game/EntityManager.h"
#include "misc/FrameCounter.h"
int main()
{
	srand((unsigned)time(NULL));

	//create a miner
	Miner* Bob = new Miner(ent_Miner_Bob);

	//create his wife
	MinersWife* Elsa = new MinersWife(ent_Elsa);

	//register them with the entity manager
	EntityMgr->RegisterEntity(Bob);
	EntityMgr->RegisterEntity(Elsa);
	TickCounter->Reset();
	//run Bob and Elsa through a few Update calls
	for (int i = 0; i<300; ++i)
	{
		Bob->Update();
		Elsa->Update();

		//dispatch any delayed messages
		Dispatcher->DispatchDelayedMessages();
		
		TickCounter->Update();
		
	}
	TickCounter->Reset();
	//tidy up
	delete Bob;
	delete Elsa;
	//wait for a keypress before exiting
	PressAnyKeyToContinue();

	return 0;
}