#pragma once
#include <atomic>
#include <thread>
#include<iostream>
#include "util.h"
#include"thread_pool.h"

namespace sun{
	template<class P, class R >//参数，返回类型
	class AbstractTask :public NoneCopyable
	{
	private:
		static std::atomic<long> sm_nId;
		long m_nId;
		static void IncreaseId()
		{
			sm_nId.fetch_add(1, std::memory_order_relaxed);
		}
	public:
		AbstractTask()
		{
			m_nId = sm_nId;
			IncreaseId();
		}

		

		virtual ~AbstractTask(){

		}
		//virtual void  DoTask() = 0;
		//virtual void  DoTask(int&) = 0;
		virtual R  DoTask() = 0;

		virtual  AbstractTask<P, R>* Clone() = 0;


		/*void AddResult(ThreadPool<P, R> &pool, R & result)
		{
			std::lock_guard<std::mutex> locker(pool.m_qResults);
			pool.m_qResults.push(result);
		}*/
		long GetId(){
			return m_nId;
		}
		static long GetNextId(){
			return sm_nId;
		}
	};

	template<class P, class R >//参数，返回类型
	std::atomic<long> AbstractTask<P, R>::sm_nId = 0;
}
