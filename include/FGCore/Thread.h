#ifndef FGCORE_THREAD_H
#define FGCORE_THREAD_H 1

#include <FGCore/Config.h>
#include <FGCore/Macros.h>
#include <FGCore/Types.h>


FG_NS_BEGIN

class Thread {
	
public:

	 typedef void(*)(void*) Handler;

	 explicit Thread();

	 explicit Thread(Handler handler);

	 virtual ~Thread(void);

	 void Start();

	 void Pause();

	 void Kill();

	 void SetHandler(Handler handler);
};

class Timer {	
private:
	FG_Timer pretime;


};

FG_NS_END

#endif