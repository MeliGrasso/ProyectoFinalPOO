#ifndef WINCAMBIOPRESUPUESTO_H
#define WINCAMBIOPRESUPUESTO_H
#include "wxfb_project.h"
#include "Ventas.h"

class WinCambioPresupuesto : public Empresa_CambiarPresupuesto {
	
private:
	Ventas *m_System;
	int m_indice_empresa;
protected:
	void OnClickGuardar( wxCommandEvent& event )  override;
	void OnClickVolver( wxCommandEvent& event )  override;
public:
	WinCambioPresupuesto(wxWindow *parent, Ventas *system, int Empresa_a_cambiar_presupuesto);
};

#endif

