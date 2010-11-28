/***************************************************************
 * Name:      wxMailboxApp.h
 * Purpose:   Defines Application Class
 * Author:    Jan Mueller (webmaster@ita-forum.de)
 * Created:   2010-10-15
 * Copyright: Jan Mueller ()
 * License:
 **************************************************************/

#ifndef WXMAILBOXAPP_H
#define WXMAILBOXAPP_H

#include <wx/app.h>
#include <wx/filename.h>
#include <wx/fileconf.h>
#include <wx/config.h>

class wxMailboxApp : public wxApp
{
	public:
		~wxMailboxApp();
		virtual bool OnInit();
		long getConfigLong(const wxString &key);
		void setConfig(const wxString &key, long value);

	private:
		wxFileConfig *config;
};

#endif // WXMAILBOXAPP_H
