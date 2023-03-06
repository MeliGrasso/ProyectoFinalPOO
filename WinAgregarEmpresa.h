#ifndef WINAGREGAREMPRESA_H
#define WINAGREGAREMPRESA_H
#include "wxfb_project.h"
#include "Ventas.h"

class WinAgregarEmpresa : public WxfbEmpresas {
private:
	Ventas *m_System;
protected:
	void OnClickAgregarDistribuidora( wxCommandEvent& event )  override;
	void OnClickEliminarDistribuidora( wxCommandEvent& event )  override;
	void OnClickCambiarPresupuesto( wxCommandEvent& event )  override;
	void OnClickGuardar( wxCommandEvent& event )  override;
	void OnClickVolver( wxCommandEvent& event )  override;
public:
	WinAgregarEmpresa(wxWindow *parent, Ventas *system);
};

#endif

