#ifndef __FGCORE_THREAD_H
#define __FGCORE_THREAD_H 1

namespace FGCore {

	class Thread {

	protected:

		explicit Thread(TheadHandler handler);

		virtual ~Thread(void);

	public:

		typedef void(*TheadHandler)(void *);

		virtual ~Thread(void)

		void start();

		//tools
		static Thread *create(TheadHandler handler);

		static void kill(Thread * thread);

		static void sleep(long ms);

		static void lock();
	};
}

#endif