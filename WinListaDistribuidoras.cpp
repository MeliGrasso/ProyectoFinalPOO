#include "WinListaDistribuidoras.h"
#include "string_convertir.h"
#include <wx/msgdlg.h>
#include "WinAgregarDistribuidora.h"
#include "WinEditarDistribuidora.h"

WinListaDistribuidoras::WinListaDistribuidoras(wxWindow *parent, Ventas *system) : d_Lista_Distribuidoras(parent), m_System(system) {
	
	int CantidadDistribuidoras = m_System->v_CantidadDeDistribuidoras();
	d_LD_ListaDistrib->AppendRows(CantidadDistribuidoras);
	for(int i=0;i<CantidadDistribuidoras;i++) {
		CargarFilaDistribuidoras(i);
	}
	d_LD_ListaDistrib->SetSelectionMode(wxGrid::wxGridSelectRows);
	
}
void WinListaDistribuidoras::CargarFilaDistribuidoras(int i){
	Distribuidora &Distri = m_System->v_DarDistribuidora(i); // obtengo la distribuidora.
	
	std::string PorcentajeDescuento; std::string PorcentajeDescuentoAliados; std::string TarifaTransporte;
	std::string CantidadMinima = std::to_string(Distri.d_VerCantidadMinAComprarNormal());
	std::string CantidadMaxima = std::to_string(Distri.d_VerCantidadMaxAComprarEnPromo());
	
	d_LD_ListaDistrib->SetCellValue(i, 0, std_to_wx(Distri.d_VerNombre()));
	d_LD_ListaDistrib->SetCellValue(i, 1, std_to_wx(Distri.d_VerPais()) );
	d_LD_ListaDistrib->SetCellValue(i, 2, std_to_wx(Distri.d_VerLocalidad()) );
	d_LD_ListaDistrib->SetCellValue(i, 3, std_to_wx("No") ); // Si no hay descuento cuando se superan las 50k unidades, muestra "No"
	d_LD_ListaDistrib->SetCellValue(i, 4, std_to_wx("No") ); // Si no hay descuento por contrato, muestra "No"
	d_LD_ListaDistrib->SetCellValue(i, 5, std_to_wx("No") ); // Si no hay descuento por familia, muestra "No"
	d_LD_ListaDistrib->SetCellValue(i, 6, std_to_wx("No") ); // Si no hay un menor precio para socios, muestra "No"
	d_LD_ListaDistrib->SetCellValue(i, 7, std_to_wx("No") ); // Si no hay tarifa por transporte, muestra "No"
	
	
	if(Distri.d_HayDescuentoPor50k()){
		d_LD_ListaDistrib->SetCellValue(i, 3, std_to_wx("10%") );
	}
	
	if(Distri.d_VerDescuentoContrato()){
		PorcentajeDescuento = std::to_string(Distri.d_HayDescuentoSocio());
		d_LD_ListaDistrib->SetCellValue(i, 4, std_to_wx(PorcentajeDescuento+"%") );
	} else if(Distri.d_VerDescuentoFamilia()){
		PorcentajeDescuento = std::to_string(Distri.d_HayDescuentoSocio());
		d_LD_ListaDistrib->SetCellValue(i, 5, std_to_wx(PorcentajeDescuento+"%") );
	}
	
	if(Distri.d_PrecioBaseMenorAliados()){
		PorcentajeDescuentoAliados = std::to_string(Distri.d_VerCuantoMasBarato());
		d_LD_ListaDistrib->SetCellValue(i,6,std_to_wx(PorcentajeDescuentoAliados+"%") );
	}
	
	if(Distri.d_HayTarifaPorTransporte() ){
		TarifaTransporte = std::to_string(Distri.d_MostrarTarifaTransporte());
		d_LD_ListaDistrib->SetCellValue(i,7,std_to_wx("$"+TarifaTransporte) );
	}
	
	d_LD_ListaDistrib->SetCellValue(i, 8, std_to_wx(CantidadMinima) );	// Cantidad mínima a comprar de un producto normal.
	d_LD_ListaDistrib->SetCellValue(i, 9, std_to_wx(CantidadMaxima) );	// Cantidad máxima a comprar de un producto con descuento.
	
}
/// Agregar una distribuidora.	//////////
void WinListaDistribuidoras::OnClickAgregarDistribuidora( wxCommandEvent& event )  {
	WinAgregarDistribuidora ventana_AddDistri(this,m_System);
	if(ventana_AddDistri.ShowModal() == 1){
		wxMessageBox(std_to_wx("Distribuidora agregada."),"Agregar distribuidora",wxOK|wxICON_INFORMATION,this);
		d_LD_ListaDistrib->AppendRows(1);
		int nuevo = m_System->v_CantidadDeDistribuidoras()-1;
		CargarFilaDistribuidoras(nuevo);
		d_LD_ListaDistrib->SetGridCursor(nuevo,0);
		d_LD_ListaDistrib->SelectRow(nuevo);
	}
}
/// Editar una distribuidora.	//////////
void WinListaDistribuidoras::OnClickEditarDistribuidora( wxCommandEvent& event )  {
	if(d_LD_ListaDistrib->GetNumberRows() == 0){
		wxMessageBox(std_to_wx("No hay distribuidoras."),"Error",wxOK|wxICON_ERROR,this);
	} else{
		int Distribuidora_actual = d_LD_ListaDistrib->GetGridCursorRow();
		WinEditarDistribuidora ventana_Editar(this,m_System,Distribuidora_actual);
		if(ventana_Editar.ShowModal() == 1) CargarFilaDistribuidoras(Distribuidora_actual);
	}
	
}
/// Eliminar una distribuidora.	//////////
void WinListaDistribuidoras::OnClickEliminarDistribuidora( wxCommandEvent& event )  {
	if(d_LD_ListaDistrib->GetNumberRows() == 0){
		wxMessageBox(std_to_wx("No hay distribuidoras a eliminar."),"Error",wxOK|wxICON_ERROR,this);
	} else{
		int Fila_Actual = d_LD_ListaDistrib->GetGridCursorRow();
		int DecisionUsuario = wxMessageBox(std_to_wx("¿Eliminar distribuidora?"),d_LD_ListaDistrib->GetCellValue(Fila_Actual,0),wxYES_NO);
		if(DecisionUsuario==wxYES){
			d_LD_ListaDistrib->DeleteRows(Fila_Actual,1); //Eliminar la fila que contiene la distribuidora
			m_System->v_EliminarDistribuidora(Fila_Actual); //Eliminar la distribuidora del sistema
			m_System->v_Guardar("ArchivoConDistribuidoras.dat","ArchiConEmpresas.dat"); //Actualizar el binario
		} 
	}
}
/// Re-ordenar según el label clickeado //////////
void WinListaDistribuidoras::OnClickLabel( wxGridEvent& event )  {
	int columna = event.GetCol();
	int CantidadDistribuidoras = m_System->v_CantidadDeDistribuidoras();
	switch(columna){
	case 0:
		m_System->v_OrdenarDistribuidora(ORDEN_NOMBRE_D);
		break;
	case 1:
		m_System->v_OrdenarDistribuidora(ORDEN_PAIS_D);
		break;
	case 2:
		m_System->v_OrdenarDistribuidora(ORDEN_LOCALIDAD_D);
		break;
	case 8:
		m_System->v_OrdenarDistribuidora(ORDEN_COMPRA_MIN);
		break;
	case 9:
		m_System->v_OrdenarDistribuidora(ORDEN_COMPRA_MAX);
		break;
	}
	for (int i=0;i<CantidadDistribuidoras;i++) CargarFilaDistribuidoras(i); 
}

