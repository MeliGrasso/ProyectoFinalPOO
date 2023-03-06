#include "WinMostrarVentas.h"
#include "string_convertir.h"

WinMostrarVentas::WinMostrarVentas(wxWindow *parent, Ventas *system, std::vector<Registro_Venta> v) : WxfbVentas(parent), m_System(system), VentasPeriodo(v){
	sort(VentasPeriodo.begin(), VentasPeriodo.end(),Comparar_Registro_fecha);
	
	int CantidadVentasPeriodo = VentasPeriodo.size(); std::string stock,precio;
	VentasRealizadasVer->AppendRows(CantidadVentasPeriodo);
	
	for(int i=0;i<CantidadVentasPeriodo;i++) { 
		std::string fecha = std::to_string(VentasPeriodo[i].v_dia) + "/" + std::to_string(VentasPeriodo[i].v_mes);
		VentasRealizadasVer->SetCellValue( i, 0, std_to_wx(fecha) );
		VentasRealizadasVer->SetCellValue( i, 1, c_to_wx(VentasPeriodo[i].d_Nombre) );
		VentasRealizadasVer->SetCellValue( i, 2, c_to_wx(VentasPeriodo[i].e_Nombre) );
		VentasRealizadasVer->SetCellValue( i, 3, c_to_wx(VentasPeriodo[i].Producto) );
		
		stock = std::to_string(VentasPeriodo[i].StockVendido); precio = std::to_string(VentasPeriodo[i].Precio);
		VentasRealizadasVer->SetCellValue( i, 4, std_to_wx(stock) );
		VentasRealizadasVer->SetCellValue( i, 5, std_to_wx("$"+precio) );
	}
	VentasRealizadasVer->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void WinMostrarVentas::OnClickVolver( wxCommandEvent& event )  {
	EndModal(0);
}

