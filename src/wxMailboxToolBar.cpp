#include "wxMailboxToolBar.h"

wxMailboxToolBar::wxMailboxToolBar(wxWindow *parent, wxWindowID id)
 : wxToolBar(parent, id, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL | wxNO_BORDER | wxTB_TEXT)
{
	AddTool(0, _("Get Mail"), getIcon(_("mail_get"), 32));
	AddSeparator();AddSeparator();AddSeparator();

	AddTool(0, _("Delete"), getIcon(_("mail_delete"), 32));
	AddTool(0, _("Junk"), getIcon(_("anti_spam"), 32));
	AddSeparator();AddSeparator();AddSeparator();

	AddTool(0, _("Reply"), getIcon(_("mail_reply"), 32));
	AddTool(0, _("Reply All"), getIcon(_("mail_replyall"), 32));
	AddTool(0, _("Forward"), getIcon(_("mail_forward"), 32));
	AddSeparator();AddSeparator();AddSeparator();

	AddTool(0, _("Write"), getIcon(_("mail_new"), 32));

	Realize();
}

wxMailboxToolBar::~wxMailboxToolBar()
{
	//dtor
}

wxBitmap wxMailboxToolBar::getIcon(const wxString& label, int size)
{
	wxString path;
	wxBitmap *bitmap;

	path = wxString::Format(_("resources/%s_%d.png"), label, size);
	bitmap = new wxBitmap(path, wxBITMAP_TYPE_PNG);

	return *bitmap;
}
