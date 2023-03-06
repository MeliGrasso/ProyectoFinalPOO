///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  6 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WXFB_PROJECT_H__
#define __WXFB_PROJECT_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/grid.h>
#include <wx/textctrl.h>
#include <wx/frame.h>
#include <wx/dialog.h>
#include <wx/valtext.h>
#include <wx/checkbox.h>
#include <wx/choice.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class WxfbPrincipal
///////////////////////////////////////////////////////////////////////////////
class WxfbPrincipal : public wxFrame 
{
	private:
	
	protected:
		wxButton* b_ListaDistribuidoras;
		wxButton* b_ListaEmpresas;
		wxButton* b_AgregarVenta;
		wxStaticText* m_staticText2;
		wxGrid* WinPrincipal_ListaD;
		wxButton* b_GenerarHistorial;
		wxTextCtrl* t_DiayMes;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCambiaTamanio( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnClickDistribuidorasListMainPage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEmpresasListMainPage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickAgregarVentaMainPage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDoubleClickMainGrid( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickLabel( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickGenerarHistorialMainPage( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		WxfbPrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Sistema de Gestión de Ventas"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~WxfbPrincipal();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_Lista_Distribuidoras
///////////////////////////////////////////////////////////////////////////////
class d_Lista_Distribuidoras : public wxDialog 
{
	private:
	
	protected:
		wxGrid* d_LD_ListaDistrib;
		wxButton* d_LD_AgregarDistrib;
		wxButton* d_LD_VerEditarDistrib;
		wxButton* d_LD_EliminarDistrib;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickLabel( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickAgregarDistribuidora( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEditarDistribuidora( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEliminarDistribuidora( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		d_Lista_Distribuidoras( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Lista de Distribuidoras"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,400 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_Lista_Distribuidoras();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class WxfbDistribuidora
///////////////////////////////////////////////////////////////////////////////
class WxfbDistribuidora : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* b_Distrib_Nombre;
		wxStaticText* m_staticText21;
		wxTextCtrl* b_Distrib_Pais;
		wxStaticText* m_staticText22;
		wxTextCtrl* b_Distrib_Localidad;
		wxStaticText* m_staticText23;
		wxTextCtrl* b_Distrib_CantMinCompra;
		wxStaticText* m_staticText24;
		wxStaticText* m_staticText9;
		wxTextCtrl* b_Distrib_CantMaxEnPromo;
		wxStaticText* m_staticText13;
		wxCheckBox* b_Distrib_50kDiscount_yesorno;
		wxStaticText* m_staticText14;
		wxChoice* b_Distrib_ElegirDescuentoPor;
		wxTextCtrl* b_Distrib_ContractDiscount_Valor;
		wxStaticText* m_staticText16;
		wxCheckBox* b_Distrib_PrecioBaseDescuento_yesorno;
		wxTextCtrl* b_Distrib_BasePriceSocios;
		wxStaticText* m_staticText15;
		wxCheckBox* b_Distrib_TarifaTraslado_yesorno;
		wxTextCtrl* b_Distrib_TarifaTraslado;
		wxButton* b_AddDistrib_EliminarProducto;
		wxButton* b_AddDistrib_AddProduct;
		wxStaticText* m_staticText3;
		wxGrid* AddDistrib_ListaStock;
		wxButton* b_AddDistrib_Volver;
		wxButton* b_AddDistrib_Guardar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickDeleteProduct( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickAgregarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickVolver( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickGuardar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		WxfbDistribuidora( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Distribuidora"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,400 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~WxfbDistribuidora();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class WxfbProducto
///////////////////////////////////////////////////////////////////////////////
class WxfbProducto : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText19;
		wxTextCtrl* AddProduct_Distrib_Name;
		wxStaticText* m_staticText191;
		wxTextCtrl* AddProduct_Distrib_Stock;
		wxStaticText* m_staticText192;
		wxTextCtrl* AddProduct_Distrib_Price;
		wxStaticText* m_staticText193;
		wxTextCtrl* AddProduct_Distrib_Discount;
		wxButton* b_Producto_Volver;
		wxButton* b_Producto_Guardar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickVolver( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickGuardar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		WxfbProducto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 442,215 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~WxfbProducto();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_Lista_Empresas
///////////////////////////////////////////////////////////////////////////////
class d_Lista_Empresas : public wxDialog 
{
	private:
	
	protected:
		wxGrid* d_LE_ListaEmp;
		wxButton* d_LE_AgregarEmp;
		wxButton* d_LE_VerEditarEmp;
		wxButton* d_LE_EliminarEmp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDobleClickGrid( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickLabel( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEditar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEliminar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		d_Lista_Empresas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Lista de Empresas"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,400 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_Lista_Empresas();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class WxfbEmpresas
///////////////////////////////////////////////////////////////////////////////
class WxfbEmpresas : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText19;
		wxTextCtrl* E_Nombre;
		wxStaticText* m_staticText20;
		wxTextCtrl* E_Pais;
		wxStaticText* m_staticText21;
		wxTextCtrl* E_Localidad;
		wxStaticText* m_staticText211;
		wxGrid* E_DistribAfiliadas;
		wxButton* E_AddDistrib;
		wxButton* E_DeleteDistrib;
		wxStaticText* m_staticText22;
		wxButton* E_CambiarPresupuesto;
		wxGrid* E_ListaPresupuesto;
		wxStaticText* m_staticText23;
		wxGrid* E_StockDisponible;
		wxButton* E_Volver;
		wxButton* E_Guardar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickAgregarDistribuidora( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEliminarDistribuidora( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCambiarPresupuesto( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickVolver( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickGuardar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		WxfbEmpresas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Empresa"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 578,629 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~WxfbEmpresas();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Empresa_AddDistrib
///////////////////////////////////////////////////////////////////////////////
class Empresa_AddDistrib : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_statictext;
		wxTextCtrl* E_AddDistrib_FindDistri;
		wxStaticText* m_staticText37;
		wxChoice* E_AddDistrib_ChooseRelationship;
		wxButton* E_AddDistrib_Volver;
		wxButton* E_AddDistrib_Guardar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickVolver( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickGuardar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Empresa_AddDistrib( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Añadir distribuidora a una empresa"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 384,148 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~Empresa_AddDistrib();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Empresa_CambiarPresupuesto
///////////////////////////////////////////////////////////////////////////////
class Empresa_CambiarPresupuesto : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText24;
		wxTextCtrl* E_Presupuesto_Enero;
		wxStaticText* m_staticText25;
		wxTextCtrl* E_Presupuesto_Febrero;
		wxStaticText* m_staticText26;
		wxTextCtrl* E_Presupuesto_Marzo;
		wxStaticText* m_staticText27;
		wxTextCtrl* E_Presupuesto_Abril;
		wxStaticText* m_staticText28;
		wxTextCtrl* E_Presupuesto_Mayo;
		wxStaticText* m_staticText241;
		wxTextCtrl* E_Presupuesto_Junio;
		wxStaticText* m_staticText251;
		wxTextCtrl* E_Presupuesto_Julio;
		wxStaticText* m_staticText261;
		wxTextCtrl* E_Presupuesto_Agosto;
		wxStaticText* m_staticText271;
		wxTextCtrl* E_Presupuesto_Septiembre;
		wxStaticText* m_staticText281;
		wxTextCtrl* E_Presupuesto_Octubre;
		wxStaticText* m_staticText39;
		wxTextCtrl* E_Presupuesto_Noviembre;
		wxStaticText* m_staticText40;
		wxTextCtrl* E_Presupuesto_Diciembre;
		wxButton* E_CambiarPres_Volver;
		wxButton* E_CambiarPres_Guardar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickVolver( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickGuardar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Empresa_CambiarPresupuesto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Cambiar Presupuesto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 507,400 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~Empresa_CambiarPresupuesto();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_AgregarVenta
///////////////////////////////////////////////////////////////////////////////
class d_AgregarVenta : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText48;
		wxTextCtrl* d_AddVenta_Dia;
		wxStaticText* m_staticText49;
		wxTextCtrl* d_AddVenta_Mes;
		wxStaticText* m_staticText38;
		wxTextCtrl* d_AddVenta_Empresa;
		wxStaticText* m_staticText39;
		wxTextCtrl* d_AddVenta_Distrib;
		wxStaticText* m_staticText40;
		wxTextCtrl* d_AddVenta_Product;
		wxStaticText* m_staticText50;
		wxTextCtrl* d_AddVenta_CantComprada;
		wxStaticText* m_statictext51;
		wxCheckBox* d_AddVenta_TransporteDistribuidora;
		wxButton* d_AddVenta_Volver;
		wxButton* d_AddVenta_Guardar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickVolver( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickGuardar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		d_AgregarVenta( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar venta"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 525,259 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_AgregarVenta();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_GenerarHistorial
///////////////////////////////////////////////////////////////////////////////
class d_GenerarHistorial : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText43;
		wxButton* Historial_Productos;
		wxButton* Historial_Mes;
		wxButton* Historial_VentasMayoresA;
		wxButton* OnClickHistorialRangoFechas;
		wxButton* Historial_Completo;
		wxStaticText* m_staticText53;
		wxButton* Historial_volver;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickHistorialPorMes( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickHistorialPorVentasMayoresA( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickRangoFechas( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickHistorialGenerico( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickVolver( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		d_GenerarHistorial( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Historial"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 649,150 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_GenerarHistorial();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_GenerarHistorial_PorMes
///////////////////////////////////////////////////////////////////////////////
class d_GenerarHistorial_PorMes : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText54;
		wxChoice* d_HistorialPorMes_Mes;
		wxButton* d_HistorialPorMes_Generate;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChoiceMes( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickGenerar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		d_GenerarHistorial_PorMes( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Historial según mes"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,105 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_GenerarHistorial_PorMes();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_GenerarHistorial_VentasMayores
///////////////////////////////////////////////////////////////////////////////
class d_GenerarHistorial_VentasMayores : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText50;
		wxTextCtrl* d_HistorialVentasMayores_Units;
		wxStaticText* m_staticText51;
		wxButton* d_HistorialVentasMayores_Generar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickGenerar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		d_GenerarHistorial_VentasMayores( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Ventas mayores a X unidades"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 330,100 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_GenerarHistorial_VentasMayores();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_GenerarHistorial_RangoFechas
///////////////////////////////////////////////////////////////////////////////
class d_GenerarHistorial_RangoFechas : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText48;
		wxTextCtrl* Dia_Inicio;
		wxStaticText* m_staticText49;
		wxTextCtrl* Mes_Inicio;
		wxStaticText* m_staticText481;
		wxTextCtrl* Dia_Final;
		wxStaticText* m_staticText491;
		wxTextCtrl* Mes_Final;
		wxButton* HistorialVolver;
		wxButton* HistorialGenerar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickVolver( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickGenerarRango( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		d_GenerarHistorial_RangoFechas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Historial por rango de fechas"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 412,167 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_GenerarHistorial_RangoFechas();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_GenerarHistorial_PorProducto
///////////////////////////////////////////////////////////////////////////////
class d_GenerarHistorial_PorProducto : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText50;
		wxTextCtrl* d_HistorialVentas_Producto;
		wxButton* d_HistorialVentas_Generar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickBuscarProducto( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		d_GenerarHistorial_PorProducto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Historial de ventas del producto..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_GenerarHistorial_PorProducto();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class WxfbVentas
///////////////////////////////////////////////////////////////////////////////
class WxfbVentas : public wxDialog 
{
	private:
	
	protected:
		wxGrid* VentasRealizadasVer;
		wxButton* d_Volver;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickVolver( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		WxfbVentas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Ventas realizadas"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~WxfbVentas();
	
};

#endif //__WXFB_PROJECT_H__
