#include "MailAccount.h"

MailAccount::MailAccount(AccountType _type, SmtpServer& _smtpServer)
 : type(_type), smtpServer(_smtpServer)
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

void MailAccount::setSmtpServer(SmtpServer& _smtpServer)
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

SmtpServer& MailAccount::getSmtpServer() const
{
	return smtpServer;
}
