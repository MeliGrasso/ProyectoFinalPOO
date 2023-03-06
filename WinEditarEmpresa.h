#ifndef WINEDITAREMPRESA_H
#define WINEDITAREMPRESA_H
#include "wxfb_project.h"
#include "Ventas.h"

class WinEditarEmpresa : public WxfbEmpresas {
private:
	Ventas *m_System;
	int m_indice_empresa;
	void CargarFilaStock(int IndiceEmpresa, int IndiceProducto);
	void CargarFilaDistribuidora(int IndiceEmpresa, int IndiceDistribuidora);
	void CargarFilaPresupuestoMensual(int IndiceEmpresa, int mes);
protected:
	void OnClickAgregarDistribuidora( wxCommandEvent& event )  override;
	void OnClickEliminarDistribuidora( wxCommandEvent& event )  override;
	void OnClickCambiarPresupuesto( wxCommandEvent& event )  override;
	void OnClickGuardar( wxCommandEvent& event )  override;
	void OnClickVolver( wxCommandEvent& event )  override;
public:
	WinEditarEmpresa(wxWindow *parent, Ventas *system, int Empresa_a_editar);
};

#endif

