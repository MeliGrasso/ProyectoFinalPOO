#ifndef WINLISTADISTRIBUIDORAS_H
#define WINLISTADISTRIBUIDORAS_H
#include "wxfb_project.h"
#include "Ventas.h"

class WinListaDistribuidoras : public d_Lista_Distribuidoras {
	
private:
	Ventas *m_System;
	void CargarFilaDistribuidoras(int i);
protected:
	void OnClickLabel( wxGridEvent& event )  override;
	void OnClickAgregarDistribuidora( wxCommandEvent& event )  override;
	void OnClickEditarDistribuidora( wxCommandEvent& event )  override;
	void OnClickEliminarDistribuidora( wxCommandEvent& event )  override;
	
public:
	WinListaDistribuidoras(wxWindow *parent, Ventas *system);
};

#endif

