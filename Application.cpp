#include <wx/image.h>
#include "Application.h"
#include "WinPrincipal.h"

Application::Application() : m_System("ArchivoConDistribuidoras.dat","ArchiConEmpresas.dat"){
	
}

bool Application::OnInit() {
	WinPrincipal *win = new WinPrincipal(&m_System);
	win->Show();
	return true;
}


