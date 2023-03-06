#include "WinEditarEmpresa.h"
#include "string_convertir.h"
#include "WinCambioPresupuesto.h"
#include "WinEmpresaAniadeDistribuidora.h"
#include <wx/msgdlg.h>

WinEditarEmpresa::WinEditarEmpresa(wxWindow *parent, Ventas *system, int Empresa_a_editar) : WxfbEmpresas(parent), m_System(system), m_indice_empresa(Empresa_a_editar) {
	
	Empresa &E = m_System->v_DarEmpresa(m_indice_empresa);
	E_Nombre->SetValue(std_to_wx(E.e_VerNombre())); E_Pais->SetValue(std_to_wx(E.e_VerPais())); E_Localidad->SetValue(std_to_wx(E.e_VerLocalidad()));
	
	int CantidadDistribuidoras = E.e_CantidadDistribuidoras();
	E_DistribAfiliadas->AppendRows(CantidadDistribuidoras);
	for(int i=0;i<CantidadDistribuidoras;i++) { 
		CargarFilaDistribuidora(m_indice_empresa,i);
	}
	E_DistribAfiliadas->SetSelectionMode(wxGrid::wxGridSelectRows);
	
	int CantidadProductos = E.e_VerCantidadProductos();
	E_StockDisponible->AppendRows(CantidadProductos);
	for(int i=0;i<CantidadProductos;i++) { 
		CargarFilaStock(m_indice_empresa,i);
	}
	E_StockDisponible->SetSelectionMode(wxGrid::wxGridSelectRows);
	
	E_ListaPresupuesto->AppendRows(1);
	for(int i=0;i<12;i++) { 
		CargarFilaPresupuestoMensual(m_indice_empresa,i);
	}
	E_ListaPresupuesto->SetSelectionMode(wxGrid::wxGridSelectColumns);
	
}
void WinEditarEmpresa::CargarFilaStock(int IndiceEmpresa, int IndiceProducto){
	Empresa &E = m_System->v_DarEmpresa(IndiceEmpresa);
	e_Producto p = E.e_VerProducto(IndiceProducto);
	
	std::string stock = std::to_string(p.Prod_stock);
	
	E_StockDisponible->SetCellValue(IndiceProducto, 0, c_to_wx(p.Prod_nombre));
	E_StockDisponible->SetCellValue(IndiceProducto, 1, std_to_wx(stock));
	
}
void WinEditarEmpresa::CargarFilaDistribuidora(int IndiceEmpresa, int IndiceDistribuidora){
	Empresa &E = m_System->v_DarEmpresa(IndiceEmpresa);
	Distrib_Socia d = E.e_VerDistribuidora(IndiceDistribuidora);
	
	E_DistribAfiliadas->SetCellValue(IndiceDistribuidora, 0, c_to_wx(d.NombreDistr) );
	if(d.RelContrato == true){
		E_DistribAfiliadas->SetCellValue(IndiceDistribuidora, 1, std_to_wx( "Contrato" ) );
	} else if (d.RelFamilia == true){
		E_DistribAfiliadas->SetCellValue(IndiceDistribuidora, 1, std_to_wx( "Grupo familiar" ) );
	} else{
		E_DistribAfiliadas->SetCellValue(IndiceDistribuidora, 1, std_to_wx( "-" ) );
	}
	
}
void WinEditarEmpresa::CargarFilaPresupuestoMensual(int IndiceEmpresa, int mes){
	Empresa &E = m_System->v_DarEmpresa(m_indice_empresa);
	float presupuesto = E.e_VerPresupuestoMensual(mes);
	
	std::string Pres = std::to_string(presupuesto);
	
	E_ListaPresupuesto->SetCellValue(0, mes, std_to_wx("$"+Pres) );
}


void WinEditarEmpresa::OnClickGuardar( wxCommandEvent& event )  {
	Empresa &e = m_System->v_DarEmpresa(m_indice_empresa);
	
	e.e_ModificarNombre( wx_to_std(E_Nombre->GetValue()) );
	e.e_ModificarPais( wx_to_std(E_Pais->GetValue()) );
	e.e_ModificarLocalidad( wx_to_std(E_Localidad->GetValue()) );
	
	std::string Errores = e.ValidarDatosEmpresa();
	if(Errores.size()){
		wxMessageBox(std_to_wx(Errores), "Error", wxOK|wxICON_ERROR,this);
	} else{
		m_System->v_Guardar("ArchivoConDistribuidoras.dat","ArchiConEmpresas.dat");
		EndModal(1);
	}
	
}

void WinEditarEmpresa::OnClickAgregarDistribuidora( wxCommandEvent& event )  {
	WinEmpresaAniadeDistribuidora ventana_AddDistribuidora(this,m_System,m_indice_empresa);
	if(ventana_AddDistribuidora.ShowModal() == 1){
		wxMessageBox(std_to_wx("Distribuidora agregada"),"Agregar distribuidora",wxOK|wxICON_INFORMATION,this);
		E_DistribAfiliadas->AppendRows(1);
		Empresa &e = m_System->v_DarEmpresa(m_indice_empresa);
		int nuevo = e.e_CantidadDistribuidoras()-1;
		CargarFilaDistribuidora(m_indice_empresa, nuevo);
		E_DistribAfiliadas->SetGridCursor(nuevo,0);
		E_DistribAfiliadas->SelectRow(nuevo);
	}
}

void WinEditarEmpresa::OnClickEliminarDistribuidora( wxCommandEvent& event )  {
	if(E_DistribAfiliadas->GetNumberRows() == 0){
		wxMessageBox(std_to_wx("No hay distribuidoras afiliadas."),"Error",wxOK|wxICON_ERROR,this);
	} else{
		int fila_actual = E_DistribAfiliadas->GetGridCursorRow();
		int Answer = wxMessageBox(std_to_wx("¿Eliminar distribuidora?"),E_DistribAfiliadas->GetCellValue(fila_actual,0),wxYES_NO);
		if (Answer == wxYES){
			E_DistribAfiliadas->DeleteRows(fila_actual,1);
			Empresa &E = m_System->v_DarEmpresa(m_indice_empresa);
			E.e_EliminarDistribuidoraPorIndice(fila_actual);
		}
	}
}

void WinEditarEmpresa::OnClickCambiarPresupuesto( wxCommandEvent& event )  {
	WinCambioPresupuesto ventana_Presupuesto(this,m_System, m_indice_empresa);
	if(ventana_Presupuesto.ShowModal() == 1){
		for(int i=0;i<12;i++) CargarFilaPresupuestoMensual(m_indice_empresa,i);
	}
}

void WinEditarEmpresa::OnClickVolver( wxCommandEvent& event )  {
	EndModal(0);
}
