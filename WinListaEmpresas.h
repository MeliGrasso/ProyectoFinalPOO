#ifndef WINLISTAEMPRESAS_H
#define WINLISTAEMPRESAS_H
#include "wxfb_project.h"
#include "Ventas.h"

class WinListaEmpresas : public d_Lista_Empresas {
	
private:
	Ventas *m_System;
	void CargarFilaEmpresa(int i);
protected:
	void OnClickLabel( wxGridEvent& event )  override;
	void OnDobleClickGrid( wxGridEvent& event )  override;
	void OnClickAgregar( wxCommandEvent& event )  override;
	void OnClickEditar( wxCommandEvent& event )  override;
	void OnClickEliminar( wxCommandEvent& event )  override;
	
public:
	WinListaEmpresas(wxWindow *parent, Ventas *system);
};

#endif

