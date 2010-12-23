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

#include <iostream>
#include <exception>

#include <wx/app.h>
#include <wx/filename.h>
#include <wx/fileconf.h>
#include <wx/config.h>
#include <wx/msgdlg.h>

#include "wxMailboxMain.h"
#include "MailAccount.h"

#include <gnutls/gnutls.h>

#include "KompexSQLitePrerequisites.h"
#include "KompexSQLiteDatabase.h"
#include "KompexSQLiteStatement.h"
#include "KompexSQLiteException.h"
#include "KompexSQLiteStreamRedirection.h"

class wxMailboxApp : public wxApp
{
	public:
		~wxMailboxApp();
		virtual bool OnInit();
		long getConfigLong(const wxString &key);
		void setConfig(const wxString &key, long value);

	private:
		wxFileConfig *config;
		Kompex::SQLiteDatabase *sqlDatabase;
		Kompex::SQLiteStatement *sqlStmt;
};

#endif // WXMAILBOXAPP_H
