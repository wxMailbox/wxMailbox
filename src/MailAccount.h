#ifndef MAILACCOUNT_H
#define MAILACCOUNT_H

#include <iostream>
#include <vector>

#include <wx/socket.h>
#include <wx/string.h>
#include <wx/filename.h>
#include <wx/fileconf.h>
#include <wx/config.h>
#include <wx/dir.h>
#include <wx/wfstream.h>

#include "SmtpServer.h"
#include "IncomingConnection.h"
#include "Pop3Connection.h"
#include "ImapConnection.h"

using namespace std;

class MailAccount
{
	public:
		enum AccountType
		{
			POP3,
			IMAP
		};

		MailAccount();
		MailAccount(const wxString& path);
		MailAccount(AccountType _type);
		//MailAccount(const wxString& path);
		virtual ~MailAccount();
		bool connect();

		void setMail(wxString _mail);
		void setDescription(wxString _description);
		void setFullName(wxString _fullName);
		void setServer(wxString server);
		void setPort(unsigned short port);
		void setUsername(wxString _username);
		void setPassword(wxString _password);
		void setSmtpServer(SmtpServer* _smtpServer);
		wxString getMail() const;
		wxString getDescription() const;
		wxString getFullName() const;
		wxString getServer() const;
		unsigned short getPort() const;
		wxString getUsername() const;
		wxString getPassword() const;
		SmtpServer* getSmtpServer() const;

		static vector<MailAccount*> accounts;
		static void loadAccounts();

	private:
		AccountType type;

		wxString mail;
		wxString description;
		wxString fullName;

		wxIPV4address* address;
		wxString username;
		wxString password;

		SmtpServer* smtpServer;
		IncomingConnection* connection;
};

#endif // MAILACCOUNT_H
