#include "EntityManager.h"
#include "BaseGameEntity.h"
EntityManager * EntityManager::Instance()
{
	static EntityManager instance;
	return &instance;
}

//ע��
void EntityManager::RegisterEntity(BaseGameEntity* NewEntity)
{
	m_EntityMap.insert(std::make_pair(NewEntity->ID(), NewEntity));
}

//��ѯ
BaseGameEntity* EntityManager::GetEntityFromID(int id)const
{
	EntityMap::const_iterator ent = m_EntityMap.find(id);
	assert((ent != m_EntityMap.end()) && "<EntityManager::GetEntityFromID>: invalid ID");
	return ent->second;
}

//ɾ��
void EntityManager::RemoveEntity(BaseGameEntity* pEntity)
{
	m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
}