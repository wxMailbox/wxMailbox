#ifndef IMAPMAILACCOUNT_H
#define IMAPMAILACCOUNT_H

#include "MailAccount.h"

class ImapMailAccount : public MailAccount
{
	public:
		ImapMailAccount(SmtpServer& _smtpServer);
		virtual ~ImapMailAccount();
	protected:
	private:
};

#endif // IMAPMAILACCOUNT_H
