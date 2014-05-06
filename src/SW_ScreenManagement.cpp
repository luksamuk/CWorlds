#include "SonicWorlds.hpp"

SW_Window::Screen::~Screen() {}

void SW_Window::Screen::init() {
    m_contentloaded = false;
    m_remove_me     = false;
    m_initialized   = true;
}

void SW_Window::Screen::load() {
    m_contentloaded = true;
}

void SW_Window::Screen::unload() {
    m_contentloaded = false;
}

bool SW_Window::Screen::IsFlaggedForRemoval() const { return m_remove_me;     }
bool SW_Window::Screen::IsActive()            const { return m_active;        }
bool SW_Window::Screen::IsContentLoaded()     const { return m_contentloaded; }
bool SW_Window::Screen::IsVisible()           const { return m_visible;       }
bool SW_Window::Screen::IsInitialized()       const { return m_initialized;   }

void SW_Window::Screen::RemoveMe()             { m_remove_me = true;  }
void SW_Window::Screen::SetActive(bool state)  { m_active    = state; }
void SW_Window::Screen::SetVisible(bool state) { m_visible   = state; }





SDL_Thread*               SW_Window::ScreenManager::m_t_assetloading = NULL;
list<SW_Window::Screen*>  SW_Window::ScreenManager::m_screenlist;
queue<SW_Window::Screen*> SW_Window::ScreenManager::m_loadqueue,
                          SW_Window::ScreenManager::m_addqueue;
stack<SW_Window::Screen*> SW_Window::ScreenManager::m_unloadstack,
                          SW_Window::ScreenManager::m_disposestack;
bool                      SW_Window::ScreenManager::m_loadingthread_busy = false;
