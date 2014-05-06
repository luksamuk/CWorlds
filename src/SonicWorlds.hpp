// SonicWorlds.hpp
// Main header file

#ifndef SONICWORLDS_H
#define SONICWORLDS_H

#define SONICWORLDS_VERSION "0.1"

#include "SW_Base.hpp"
#include "SW_CommonTypes.hpp"
#include "SW_TexturePool.hpp"

/// Tools for window management, such as window creation.
class SW_Window {
private:
	static SDL_Window*       m_window;
	static SDL_GLContext  m_glcontext,
	                      m_loadcontext;
public:
    class Screen {
    private:
        bool m_contentloaded = false,
             m_remove_me     = false,
             m_active        = false,
             m_visible       = false,
             m_initialized   = false;
    public:
        virtual ~Screen();
        virtual void init()   = 0; /**< \warning Call base class here */
        virtual void load()   = 0; /**< \warning Call base class here */
        virtual void unload() = 0; /**< \warning Call base class here */
        virtual void update() = 0;
        virtual void draw()   = 0;

        bool IsFlaggedForRemoval() const;
        bool IsContentLoaded()     const;
        bool IsActive()            const;
        bool IsVisible()           const;
        bool IsInitialized()       const;

        virtual void RemoveMe()             final;
        virtual void SetActive(bool state)  final;
        virtual void SetVisible(bool state) final;
        //virtual float GetDepth()            final;
        //virtual void  SetDepth(float depth) final;
    };

	class ScreenManager {
    private:
        static SDL_Thread* m_t_assetloading;

        static list<Screen*> m_screenlist;
        static queue<Screen*> m_loadqueue,
                              m_addqueue;
        static stack<Screen*> m_unloadstack,
                              m_disposestack;

        static bool     m_loadingthread_busy;

        //static int m_assetloading_update(void* unused);
    public:
        //static void init();
        //static void dispose();
        //static void add(SW_Window::Screen*);
        //static void remove(SW_Window::Screen*);
        //static void updateall();
        //static void drawall();

        //static bool IsLoadingThreadBusy();
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
