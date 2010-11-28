#ifndef WXMAILBOXTOOLBAR_H
#define WXMAILBOXTOOLBAR_H

#include "wx/toolbar.h"
#include "wx/bitmap.h"

class wxMailboxToolBar : public wxToolBar
{
	public:
		wxMailboxToolBar(wxWindow *parent, wxWindowID id);
		virtual ~wxMailboxToolBar();
	protected:
	private:
		wxBitmap getIcon(const wxString& label, int size);
};

#endif // WXMAILBOXTOOLBAR_H
