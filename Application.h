#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "Ventas.h"


class Application : public wxApp {
private:
	Ventas m_System;
public:
	Application();
	virtual bool OnInit();
};

IMPLEMENT_APP(Application)

#endif
