// SonicWorlds.cpp
// Main code file

#include "SonicWorlds.hpp"


// class SW_Window
SDL_Window*   SW_Window::m_window;
SDL_GLContext SW_Window::m_glcontext,
              SW_Window::m_loadcontext;

void SW_Window::init(string name, bool vsync)
{
	int winsize_x = 800,
	    winsize_y = 600;
	// Create a window
	m_window = SDL_CreateWindow(name.c_str(),
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		winsize_x, winsize_y, SDL_WINDOW_OPENGL);
	if(!m_window) {
		SW_Log("Error on window creation: %s\n", SDL_GetError());
		return; /* todo: throw exception instead */
	}

	/*todo: icon setup*/

	// OpenGL context creation
	SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);
	m_loadcontext = SDL_GL_CreateContext(m_window);
	m_glcontext   = SDL_GL_CreateContext(m_window);

	// Set VSync
	if(vsync && SDL_GL_SetSwapInterval(1))
		SW_Log("Warning: Could not enable VSync.\n");

	// Setup OpenGL projection
	// This will also invert the plane; Y axis grows top-bottom.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float AspectRatio = float(winsize_x) / float(winsize_y);
	glViewport(0, 0, winsize_x, -winsize_y);
	if(AspectRatio >= 1.0f)
		glOrtho(0, float(winsize_x) * AspectRatio, float(winsize_y),
			0, -1, 1);
	else
		glOrtho(0, float(winsize_x), float(winsize_y) / AspectRatio,
			0, -1 / AspectRatio, 1 / AspectRatio);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Setup OpenGL attributes
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,     8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,   8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,   8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

//Test variables
float triangle_angle = 0.0f;
const float triangle_width  = 200.0f,
	            triangle_height = 200.0f;
void SW_Window::update()
{
	if(!m_window) return;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// test: draw a triangle rotating around its
	// baricenter
	glPushMatrix();
	glTranslatef(400.0f, 300.0f, 0.0f);
	glRotatef(triangle_angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, -200.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(200.0f, 100.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(-200.0f, 100.0f);
	glEnd();
	glPopMatrix();

	// rotation
	triangle_angle += 5.0f;
	if(triangle_angle >= 360.0f) triangle_angle -= 360.0f;


	SDL_GL_SwapWindow(m_window);
}

void SW_Window::dispose()
{
    SDL_GL_DeleteContext(m_loadcontext);
	SDL_GL_DeleteContext(m_glcontext);
	SDL_DestroyWindow(m_window);
}



// class SW_Core
bool SW_Core::m_run = true;
dword SW_Core::m_frametick,
      SW_Core::m_frametick_old;

void SW_Core::init()
{
	SW_Window::init("Sonic Worlds (C++/OpenGL backend) v" SONICWORLDS_VERSION,
		            true); // vsync
}

int SW_Core::dogameloop()
{
	while(m_run) {
		// FPS - Related
		m_frametick_old = m_frametick;
		m_frametick = SDL_GetTicks();

		SW_Window::update();

		// Testing!
		SDL_Event event;
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
			case SDL_QUIT:
				m_run = false;
				break;
			default: break;
			}
		}

		SW_Log("FPS: %0.04f\n", GetRefreshRate());

		// -- Testing!


	}

	SW_Window::dispose();
	return 0;
}

double SW_Core::GetDeltaTime() {
	return (m_frametick - m_frametick_old) / 1000.0;
}
double SW_Core::GetRefreshRate() {
	return 1.0 / GetDeltaTime();
}
