#include "MailAccount.h"


vector<MailAccount*> MailAccount::accounts;

MailAccount::MailAccount()
{
	accounts.push_back(this);
}

MailAccount::MailAccount(const wxString& path)
{
	wxFileConfig* config;
	wxFileInputStream* stream;
	wxString file;
	wxString temp;
	int port;

	file = path + _("/config.ini");

	stream = new wxFileInputStream(file);
	config = new wxFileConfig(*stream);

	address = new wxIPV4address();

	config->Read(_("Mailbox/type"), &temp);

	if(temp == "imap")
	{
		type = IMAP;
	}
	else if(temp == "pop3")
	{
		type = POP3;
	}

	config->Read(_("Mailbox/mail"), &mail);
	config->Read(_("Mailbox/description"), &description);
	config->Read(_("Mailbox/fullName"), &fullName);
	config->Read(_("Mailbox/username"), &username);
	config->Read(_("Mailbox/password"), &password);

	config->Read(_("Mailbox/server"), &temp);
	setServer(temp);

	config->Read(_("Mailbox/port"), &port);
	setPort(port);

	delete config;
}

MailAccount::MailAccount(AccountType _type)
 : type(_type)
{
	address = new wxIPV4address();
}


MailAccount::~MailAccount()
{
	//dtor
}

bool MailAccount::connect()
{
	switch(type)
	{
		case POP3:
			connection = new Pop3Connection(address);
			break;

		case IMAP:
			connection = new ImapConnection(address);
			break;

		default:
			break;
	}

	return true;
}

void MailAccount::setMail(wxString _mail)
{
	mail = _mail;
}

void MailAccount::setDescription(wxString _description)
{
	description = _description;
}

void MailAccount::setFullName(wxString _fullName)
{
	fullName = _fullName;
}

void MailAccount::setServer(wxString server)
{
	address->Hostname(server);
}


void MailAccount::setPort(unsigned short port)
{
	address->Service(port);
}

void MailAccount::setUsername(wxString _username)
{
	username = _username;
}

void MailAccount::setPassword(wxString _password)
{
	password = _password;
}

void MailAccount::setSmtpServer(SmtpServer* _smtpServer)
{
	smtpServer = _smtpServer;
}

wxString MailAccount::getMail() const
{
	return mail;
}

wxString MailAccount::getDescription() const
{
	return description;
}

wxString MailAccount::getFullName() const
{
	return fullName;
}

wxString MailAccount::getServer() const
{
	return address->Hostname();
}

unsigned short MailAccount::getPort() const
{
	return address->Service();
}

wxString MailAccount::getUsername() const
{
	return username;
}

wxString MailAccount::getPassword() const
{
	return password;
}

SmtpServer* MailAccount::getSmtpServer() const
{
	return smtpServer;
}

void MailAccount::loadAccounts()
{
	//wxMessageDialog *msg;
	wxDir *dir;
	wxString path;
	wxString file;
	bool more;

	path = wxString::Format(_("%s/%s"), wxFileConfig::GetLocalFile("", wxCONFIG_USE_SUBDIR).GetPath(), _("Mailboxes"));
	dir = new wxDir(path);

	//msg = new wxMessageDialog(NULL, path);
	//msg->ShowModal();

	more = dir->GetFirst(&file, wxEmptyString, wxDIR_DIRS);
	while(more)
	{
		//msg = new wxMessageDialog(NULL, file);
		//msg->ShowModal();
		new MailAccount(wxString::Format(_("%s/%s"), path, file));

		more = dir->GetNext(&file);
	}
}
