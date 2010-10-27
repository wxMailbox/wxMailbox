#include "ImapMailAccount.h"

ImapMailAccount::ImapMailAccount(SmtpServer& _smtpServer)
 : MailAccount(_smtpServer)
{
	//ctor
}

ImapMailAccount::~ImapMailAccount()
{
	//dtor
}
