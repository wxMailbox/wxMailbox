#ifndef MAILLISTCTRL_H
#define MAILLISTCTRL_H

#include "wx/listctrl.h"

class mailListCtrl : public wxListCtrl
{
	public:
		mailListCtrl(wxWindow* parent, wxWindowID id);
		virtual ~mailListCtrl();
		virtual wxString OnGetItemText(long item, long column) const;
	private:
		int currentID;

		void OnColumnDrag(wxListEvent& event);
		void OnColumnEndDrag(wxListEvent& event);
		void OnColumnBeginDrag(wxListEvent& event);

		DECLARE_EVENT_TABLE()
};

#endif // MAILLISTCTRL_H
