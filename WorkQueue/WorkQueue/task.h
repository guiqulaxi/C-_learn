#pragma once
#include<iostream>
#include "abstract_task.h"
#include "task_parameter.h"

class Task : public sun::AbstractTask<TaskParameter,int>
{
public:
	~Task(){
		if (m_pParameter != nullptr){
			delete m_pParameter;
			m_pParameter = nullptr;
			
		}
	};
	Task(const TaskParameter&  pParameter){
		m_pParameter = new TaskParameter(pParameter);
	}
	//void DoTask();
	int DoTask();

	AbstractTask<TaskParameter, int>* Clone(){
		 AbstractTask<TaskParameter, int> *p = new Task(*(this->m_pParameter));
		return p;
	}

private:
	TaskParameter * m_pParameter = nullptr;//参数类型 必须注意拷贝构造函数
};

