#ifndef WINEMPRESAANIADEDISTRIBUIDORA_H
#define WINEMPRESAANIADEDISTRIBUIDORA_H
#include "wxfb_project.h"
#include "WinEmpresaAniadeDistribuidora.h"
#include "Ventas.h"

class WinEmpresaAniadeDistribuidora : public Empresa_AddDistrib {
	
private:
	Ventas *m_System;
	int m_indice_empresa;
protected:
	void OnClickGuardar( wxCommandEvent& event )  override;
	void OnClickVolver( wxCommandEvent& event )  override;
public:
	WinEmpresaAniadeDistribuidora(wxWindow *parent, Ventas *system, int Empresa_a_editar);
};

#endif

