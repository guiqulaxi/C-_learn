#pragma once
#include <map>
#include <cassert>
#include <string>


class BaseGameEntity;

//provide easy access
#define EntityMgr EntityManager::Instance()



class EntityManager
{
private:

	typedef std::map<int, BaseGameEntity*> EntityMap;

private:

	//to facilitate quick lookup the entities are stored in a std::map, in which
	//pointers to entities are cross referenced by their identifying number
	EntityMap m_EntityMap;

	EntityManager(){}

	//copy ctor and assignment should be private
	EntityManager(const EntityManager&);
	EntityManager& operator=(const EntityManager&);

public:

	static EntityManager* Instance();

	//ע��
	void RegisterEntity(BaseGameEntity* NewEntity);

	//��ѯ
	BaseGameEntity* GetEntityFromID(int id)const;

	//ɾ��
	void RemoveEntity(BaseGameEntity* pEntity);
};
