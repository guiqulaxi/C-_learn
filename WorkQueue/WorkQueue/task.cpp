#include "task.h"
//void Task::DoTask()
//{
//	std::cout << m_pParameter->a << std::endl;
//}
//int Task::DoTask(int & result)
//{
//	result = 1;
//}
int Task::DoTask()
{
	int j=0;
	for (int i = 0; i < 1; i++){
		j+=i;
	}
	return j;
}
