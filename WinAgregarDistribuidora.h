#ifndef WINAGREGARDISTRIBUIDORA_H
#define WINAGREGARDISTRIBUIDORA_H
#include "wxfb_project.h"
#include "Ventas.h"

class WinAgregarDistribuidora : public WxfbDistribuidora {
private:
	Ventas *m_System;
protected:
	void OnClickGuardar( wxCommandEvent& event )  override;
	void OnClickVolver( wxCommandEvent& event )  override;
	
	void OnClickAgregarProducto( wxCommandEvent& event )  override;
	void OnClickDeleteProduct( wxCommandEvent& event )  override;
public:
	WinAgregarDistribuidora(wxWindow *parent, Ventas *system);

};

#endif

