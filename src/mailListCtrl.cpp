#include "mailListCtrl.h"

BEGIN_EVENT_TABLE(mailListCtrl, wxListCtrl)
	EVT_LIST_COL_BEGIN_DRAG(wxID_ANY, mailListCtrl::OnColumnBeginDrag)
	EVT_LIST_COL_DRAGGING(wxID_ANY, mailListCtrl::OnColumnDrag)
	EVT_LIST_COL_END_DRAG(wxID_ANY, mailListCtrl::OnColumnEndDrag)
END_EVENT_TABLE()

mailListCtrl::mailListCtrl(wxWindow* parent, wxWindowID id)
 : wxListCtrl(parent, id, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxBORDER_SUNKEN | wxVSCROLL | wxHSCROLL | wxALWAYS_SHOW_SB | wxLC_VIRTUAL | wxFULL_REPAINT_ON_RESIZE)
{
	SetItemCount(100000000);
}

mailListCtrl::~mailListCtrl()
{
	//dtor
}

wxString mailListCtrl::OnGetItemText(long item, long column) const
{
	return wxString::Format(_("%d, %d"), item, column);
}

void mailListCtrl::OnColumnDrag(wxListEvent& event)
{
	const wxListItem& item = event.GetItem();

	if(item.GetWidth() < 20)
	{
		SetColumnWidth(event.GetColumn(), 20);
		event.Veto();
	}
}

void mailListCtrl::OnColumnEndDrag(wxListEvent& event)
{
	if(GetColumnWidth(event.GetColumn()) < 20)
	{
		SetColumnWidth(event.GetColumn(), 20);
		event.Veto();
	}
}

void mailListCtrl::OnColumnBeginDrag(wxListEvent& event)
{
}
