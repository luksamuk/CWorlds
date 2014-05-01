// SonicWorlds.hpp
// Main header file

#ifndef SONICWORLDS_H
#define SONICWORLDS_H

#define SONICWORLDS_VERSION "0.1"

#include "SW_Base.hpp"
#include "SW_CommonTypes.hpp"
#include "SW_TexturePool.hpp"

/// \brief Use this function to output debug to the screen.
int SW_Log(const char* fmt, ...);

/// Tools for window management, such as window creation.
class SW_Window {
private:
	static SDL_Window*       m_window;
	static SDL_GLContext  m_glcontext;
public:
	class SW_ScreenManager {
		// TO-DO
	};


	static void init(string name, bool vsync = false);
	static void update();
	static void dispose();
};

/// \brief Tools for core management, such as gameloop.
class SW_Core {
private:
	static bool m_run;
	static dword m_frametick,
	             m_frametick_old;
public:
	static void   init();
	static int    dogameloop();
	static double GetDeltaTime();
	static double GetRefreshRate();
};


#endif
