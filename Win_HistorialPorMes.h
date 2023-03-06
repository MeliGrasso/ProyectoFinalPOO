#ifndef WIN_HISTORIALPORMES_H
#define WIN_HISTORIALPORMES_H
#include "wxfb_project.h"
#include "Ventas.h"

class Win_HistorialPorMes : public d_GenerarHistorial_PorMes {
private:
	Ventas *m_System;
	std::string m_Mes = "";
protected:
	void OnChoiceMes (wxCommandEvent & event);
	void OnClickGenerar (wxCommandEvent & event);
public:
	Win_HistorialPorMes(wxWindow *parent, Ventas *system);
};

#endif

