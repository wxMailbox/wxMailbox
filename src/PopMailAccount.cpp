#include "PopMailAccount.h"

PopMailAccount::PopMailAccount(SmtpServer& _smtpServer)
 : MailAccount(_smtpServer)
{
	//ctor
}

PopMailAccount::~PopMailAccount()
{
	//dtor
}
