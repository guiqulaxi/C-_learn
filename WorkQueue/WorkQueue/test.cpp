#include<vector>
#include <memory>
#include<iostream>
#include <atomic>
#include <thread>
#include <vector>
#include "task.h"
#include "task_parameter.h"
#include "thread_pool.h"


void TesTask()
{
	using work_thread_ptr = std::shared_ptr<std::thread>;
	std::vector<work_thread_ptr> _thread_vec;
	for (int i = 0; i < 4; i++){
		work_thread_ptr ptr = std::make_shared<std::thread>([&]{
			for (int i = 0; i < 10; i++){
				TaskParameter aa;
				Task t(aa);
				
			}
		});
		
		_thread_vec.push_back(ptr);
		
	}
	for (int i = 0; i <_thread_vec.size(); i++){
		_thread_vec[i]->join();
	}
	
}


void TestThreadPool()
{
	using work_thread_ptr = std::shared_ptr<std::thread>;
	sun::ThreadPool<TaskParameter, int> pool(2);

	int getres_threads_num = 2;
	std::vector<std::thread> getres_threads(getres_threads_num);
	for (int i = 0; i < getres_threads_num; i++){
		getres_threads[i] = std::thread([&]{
			//for (int j = 0; j < 15; j++)
			while (true)
			{
				int a = 0;
				if (pool.GetResult(a, 1000)){}
				//std::cout << "取得任务结果" << a << std::endl;
			}
		});
	}


	int puttask_threads_num = 2;
	std::vector<std::thread> puttask_threads(puttask_threads_num);
	for (int i = 0; i < puttask_threads_num; i++){
		puttask_threads[i] = std::thread([&]{
			//for (int j = 0; j < 5; j++)
			while (true)
			{
				//std::this_thread::sleep_for(std::chrono::milliseconds(100));
				TaskParameter aa;
				Task t(aa);
				pool.AddTask(&t);
			}
		});
	}

	
	for (int i = 0; i <puttask_threads.size(); i++){
		puttask_threads[i].join();
	}
	for (int i = 0; i < getres_threads.size(); i++){
		getres_threads[i].join();
	}

}



int main(){
	
	TestThreadPool();
	

	return 0;
}