#pragma once
#include<queue>
#include<mutex>
#include<thread>
#include<memory>
#include<atomic>
#include<condition_variable>
template<class P, class R >//参数，返回类型
class AbstractTask;

namespace sun{

	template<class P, class R >//参数，返回类型
	class ThreadPool{

		
		using work_thread_ptr = std::shared_ptr<std::thread>;
		using task_ptr = std::shared_ptr<AbstractTask<P, R>>;
		
	public:
		ThreadPool(size_t thread_num, size_t max_task_num=100, size_t max_result_num=100)
		{
			m_bControl = true;
			m_nMaxTaskNum = max_task_num;
			m_nMaxResultNum = max_result_num;
			for (std::size_t i = 0; i < thread_num; ++i)
			{
				work_thread_ptr t = std::make_shared<std::thread>(std::bind(&ThreadPool::RunTask, this));
				m_vThreads.emplace_back(t);
			}
			
		}
		//void RunTask()
		//{
		//	
		//	while (true)
		//	{
		//		task_ptr tp;
		//		{
		//			
		//			std::unique_lock<std::mutex> locker(m_mutexTaskQueue);

		//			m_cvTaskGet.wait(locker, [&]{
		//				return !m_qTasks.empty() || !m_bControl;
		//			});

		//			//只要是 停止运行 不管队列中是否有任务 立即退出
		//			if (!m_bControl){
		//				return;
		//			}
		//			tp = m_qTasks.front();
		//			m_qTasks.pop();


		//		}
		//		if (tp)//不为空
		//		{
		//			
		//			R result=tp->DoTask();
		//			{
		//				
		//				std::lock_guard<std::mutex> locker(m_mutexResultQueue);
		//				m_qResults.push(result);
		//				//std::cout << "处理任务" << tp->GetId()<< std::endl;
		//				m_cvResultGet.notify_one();
		//			}
		//		}
		//	}

		//}
		//添加任务
		//void AddTask( AbstractTask<P, R> *ptask)
		//{
		//	
		//	std::lock_guard<std::mutex> locker(m_mutexTaskQueue);

		//		 AbstractTask<P, R> *p = ptask->Clone();//复制任务
		//		 
		//		std::shared_ptr<AbstractTask<P, R>> shar_ptr(p);
		//		if (shar_ptr){
		//			m_qTasks.push(shar_ptr);
		//			// 向任务队列插入了一个任务并提示线程池可以来取任务了
		//			//std::cout << "向任务队列插入了" << shar_ptr->GetId()<< std::endl;
		//			m_cvTaskGet.notify_one();
		//		}
		//			
		//}


		////获得结果
		//bool GetResult(R& result, int wait_time){
		//	std::unique_lock<std::mutex> locker(m_mutexResultQueue);
		//	m_cvResultGet.wait_for(locker, std::chrono::milliseconds(wait_time), [&]{
		//		return !m_qResults.empty() || !m_bControl;
		//	});
		//	/*m_cvResultGet.wait(locker,  [&]{
		//	return !m_qResults.empty() || !m_bControl;
		//	});*/
		//	if (!m_bControl){//只要是 停止运行 不管队列中是否有任务 立即退出
		//		return false;
		//	}
		//	if (!m_qResults.empty()){
		//		result = m_qResults.front();
		//		m_qResults.pop();
		//		return true;
		//	}
		//	return false;
		//}

		void RunTask()
		{

			while (true)
			{
				task_ptr tp;
				{

					std::unique_lock<std::mutex> locker(m_mutexTaskQueue);
					//任务队列为空则阻塞
					m_cvTaskGet.wait(locker, [&]{
						return !m_qTasks.empty() || !m_bControl;
					});

					//只要是 停止运行 不管队列中是否有任务 立即退出
					if (!m_bControl){
						return;
					}

					//取任务
					tp = m_qTasks.front();
					m_qTasks.pop();

					//
					//通知放任务
					m_cvTaskPut.notify_one();

				}
				if (tp)//不为空
				{

					R result = tp->DoTask();
					{

						std::unique_lock<std::mutex> locker(m_mutexResultQueue);

						//结果队列过满则等待
						m_cvResultPut.wait(locker, [&]
						{
							return (m_qResults.size() < m_nMaxResultNum) || !m_bControl;
						});

						//只要是 停止运行 不管队列中是否有任务 立即退出
						if (!m_bControl){
							return;
						}

						m_qResults.push(result);
						//std::cout << "处理任务" << tp->GetId()<< std::endl;

						//通知来取结果
						m_cvResultGet.notify_one();
					}
				}
			}

		}



		void AddTask(AbstractTask<P, R> *ptask)
		{
			AbstractTask<P, R> *p = ptask->Clone();//复制任务

			std::shared_ptr<AbstractTask<P, R>> shar_ptr(p);

			std::unique_lock<std::mutex> locker(m_mutexTaskQueue);

			//任务队列过满则等待
			m_cvTaskPut.wait(locker, [&]{
				return (m_qTasks.size() < m_nMaxTaskNum) || !m_bControl;
			});

			//只要是 停止运行 不管队列中是否有任务 立即退出
			if (!m_bControl){
				return;
			}


			if (shar_ptr){
				m_qTasks.push(shar_ptr);
				// 向任务队列插入了一个任务并提示线程池可以来取任务了
				//std::cout << "向任务队列插入了" << shar_ptr->GetId()<< std::endl;
				
				//通知放任务
				m_cvTaskGet.notify_one();
			}

		}
		//获得结果
		bool GetResult(R& result,int wait_time){
				std::unique_lock<std::mutex> locker(m_mutexResultQueue);
				m_cvResultGet.wait_for(locker, std::chrono::milliseconds(wait_time), [&]{
					return !m_qResults.empty() || !m_bControl;
				});
				/*m_cvResultGet.wait(locker,  [&]{
					return !m_qResults.empty() || !m_bControl;
				});*/
				if (!m_bControl){//只要是 停止运行 不管队列中是否有任务 立即退出
					return false;
				}
				if (!m_qResults.empty()){
					result = m_qResults.front();
					m_qResults.pop();

					//通知放结果
					m_cvResultPut.notify_one();
					return true;
				}
			return false;
		}
		//获得当前任务队列的数目
		int GetCurrentTaskNumber(){
			std::lock_guard<std::mutex> locker(m_mutexTaskQueue);
			return m_qTasks.size();
		}
		//获得当前结果队列的大小
		int GetCurrentResultNumber(){
			std::lock_guard<std::mutex> locker(m_mutexTaskQueue);
			return m_qResults.size();
		}
		
		~ThreadPool()
		{
			m_bControl = false;
			m_cvTaskGet.notify_all();
			m_cvResultGet.notify_all();
			m_cvTaskPut.notify_all();
			m_cvResultPut.notify_all();

			for (std::size_t i = 0; i < m_vThreads.size(); ++i)
			{
				m_vThreads[i]->join();
			}
			
		}
	private:
		
		std::queue<task_ptr> m_qTasks;
		std::mutex m_mutexTaskQueue;//任务队列互斥锁
		std::condition_variable m_cvTaskGet;//取任务
		std::condition_variable m_cvTaskPut;//放任务

		std::queue<R> m_qResults;
		std::mutex m_mutexResultQueue;//结果队列互斥锁
		std::condition_variable m_cvResultGet;//取结果
		std::condition_variable m_cvResultPut;//放结果

		std::vector<work_thread_ptr> m_vThreads;

		std::once_flag terminal_flag;
		std::atomic_bool m_bControl;

		size_t m_nMaxTaskNum;
		size_t m_nMaxResultNum;

		
	};
}
