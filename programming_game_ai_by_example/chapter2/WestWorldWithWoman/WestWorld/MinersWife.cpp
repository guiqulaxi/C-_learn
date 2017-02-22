#include"MinersWife.h"
void MinersWife::Update()
{
	SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	m_pStateMachine->Update();
}