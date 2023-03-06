#include "WinPrincipal.h"
#include "Distribuidora.h"
#include "Empresa.h"
#include "Ventas.h"
#include "Miscelanea.h"
#include "string_convertir.h"
#include "WinListaDistribuidoras.h"
#include "WinListaEmpresas.h"
#include "WinVenta.h"
#include "WinHistorial.h"
#include "WinEditarDistribuidora.h"
#include <wx/icon.h>

/// Tengo que llenar la grilla con los datos de las distribuidoras en el sistema.
WinPrincipal::WinPrincipal(Ventas *system) : WxfbPrincipal(nullptr), m_System(system) {
	
	SetIcon(wxIcon("icono.ico"));
	///Lo que quiero acá es que me muestre la distribuidora y los detalles del producto de más cantidad.
	int CantidadDeDistribuidoras = m_System->v_CantidadDeDistribuidoras();
	WinPrincipal_ListaD->AppendRows(CantidadDeDistribuidoras);
	for(int i=0;i<CantidadDeDistribuidoras;i++) CargarFilaDistribuidoras(i);
	WinPrincipal_ListaD->SetSelectionMode(wxGrid::wxGridSelectRows);
	
	std::string DiaDeHoy = mostrar_fecha();
	t_DiayMes->SetValue(std_to_wx(DiaDeHoy));
	
}
///Para cargar las distribuidoras y su producto con más stock en el principio
void WinPrincipal::CargarFilaDistribuidoras(int i){
	Distribuidora D = m_System->v_DarDistribuidora(i); // obtengo la distribuidora.
	WinPrincipal_ListaD->SetCellValue(i, 0, std_to_wx(D.d_VerNombre())); //Nombre de la distribuidora.
	WinPrincipal_ListaD->SetCellValue(i, 1, std_to_wx("-") ); //Nombre del producto.
	WinPrincipal_ListaD->SetCellValue(i, 2, std_to_wx("-") );	//Cantidad disponible del producto.
	WinPrincipal_ListaD->SetCellValue(i, 3, std_to_wx("-") );	//Precio con descuento del producto.
	WinPrincipal_ListaD->SetCellValue(i, 4, std_to_wx("-") );	//Precio sin descuento del producto.
	if(D.d_HayProductos()){
		int ProdMayorStock = D.d_VerProductoConMayorStock(); // obtengo la posición en el vector Productos de la distribuidora donde está el producto con mayor stock.
		std::string ProductoCantidad = std::to_string(D.d_VerProductoStock(ProdMayorStock));
		std::string ProductoConDescuento = std::to_string(D.d_VerPrecioProductoConDescuento(ProdMayorStock));
		std::string ProductoSinDescuento = std::to_string(D.d_VerProductoPrecio(ProdMayorStock));
		
		WinPrincipal_ListaD->SetCellValue(i, 1, std_to_wx(D.d_VerNombreProducto(ProdMayorStock)) ); //Nombre del producto.
		WinPrincipal_ListaD->SetCellValue(i, 2, std_to_wx(ProductoCantidad) );	//Cantidad disponible del producto.
		WinPrincipal_ListaD->SetCellValue(i, 3, std_to_wx("$"+ProductoConDescuento) );	//Precio con descuento del producto.
		WinPrincipal_ListaD->SetCellValue(i, 4, std_to_wx("$"+ProductoSinDescuento) );	//Precio sin descuento del producto.
	}
}
void WinPrincipal::ActualizarGrilla(){
	WinPrincipal_ListaD->ClearSelection();
	if(WinPrincipal_ListaD->GetNumberRows() != 0)	WinPrincipal_ListaD->DeleteRows(0,WinPrincipal_ListaD->GetNumberRows());
	
	for(int i=0;i<m_System->v_CantidadDeDistribuidoras();i++) { 
		WinPrincipal_ListaD->AppendRows();
		CargarFilaDistribuidoras(i);
	}
}
///															////
/// BOTONES QUE DIRIGEN A UN DIALOG DESDE EL FRAME PRINCIPAL ///
///															////

/// Cuando hago click en el botón "Lista de distribuidoras"
void WinPrincipal::OnClickDistribuidorasListMainPage( wxCommandEvent& event )  {
	WinListaDistribuidoras ventana_ListaD(this,m_System); 
	int viejasDistris = m_System->v_CantidadDeDistribuidoras(); // Numero de filas que tiene
	if(ventana_ListaD.ShowModal()){
		ActualizarGrilla();
	}
}
/// Cuando hago click en el botón "Lista de Empresas"
void WinPrincipal::OnClickEmpresasListMainPage( wxCommandEvent& event )  {
	WinListaEmpresas ventana_ListaE(this,m_System);
	ventana_ListaE.ShowModal();
}
/// Cuando hago click en el botón "Agregar venta"
void WinPrincipal::OnClickAgregarVentaMainPage( wxCommandEvent& event )  {
	int CantidadDeDistribuidoras = m_System->v_CantidadDeDistribuidoras();
	WinVenta ventana_Venta(this,m_System);
	if(ventana_Venta.ShowModal() == 1){
		for(int i=0;i<CantidadDeDistribuidoras;i++){
			CargarFilaDistribuidoras(i);
		}
	}
}
/// Cuando hago click en "Generar historial"
void WinPrincipal::OnClickGenerarHistorialMainPage( wxCommandEvent& event )  {
	WinHistorial ventana_Historial(this,m_System);
	ventana_Historial.ShowModal();
}

/// Cambia el tamaño de la grilla cuando se cambia el tamaño del frame
void WinPrincipal::OnCambiaTamanio( wxSizeEvent& event )  {
	Layout(); 
	int tamanios[5]; 
	int ancho_total_viejo=0; 
	for (int i=0;i<5;i++) { 
		tamanios[i] = WinPrincipal_ListaD->GetColSize(i);
		ancho_total_viejo += tamanios[i];
	}
	int ancho_total_nuevo = WinPrincipal_ListaD->GetSize().GetWidth();
	WinPrincipal_ListaD->BeginBatch();
	for (int i=0;i<5;i++) {
		WinPrincipal_ListaD->SetColSize(i,(tamanios[i]*ancho_total_nuevo)/ancho_total_viejo);
	}
	WinPrincipal_ListaD->EndBatch();
}
/// Cuando hago doble click en una distribuidora para poder editarla
void WinPrincipal::OnDoubleClickMainGrid( wxGridEvent& event )  {
	int fila_actual = WinPrincipal_ListaD->GetGridCursorRow();
	WinEditarDistribuidora ventana_EditarDistribuidora(this, m_System,fila_actual);
	if(ventana_EditarDistribuidora.ShowModal() == 1){
		CargarFilaDistribuidoras(fila_actual);
	}
}
/// Ordena las distribuidoras por nombre
void WinPrincipal::OnClickLabel( wxGridEvent& event )  {
	int columna = event.GetCol();
	int CantidadDistribuidoras = m_System->v_CantidadDeDistribuidoras();
	switch(columna){
	case 0:
		m_System->v_OrdenarDistribuidora(ORDEN_NOMBRE_D);
		break;
	}
	for (int i=0;i<CantidadDistribuidoras;i++) CargarFilaDistribuidoras(i); 
}

