#ifndef POPMAILACCOUNT_H
#define POPMAILACCOUNT_H

#include "MailAccount.h"

class PopMailAccount : public MailAccount
{
	public:
		PopMailAccount(SmtpServer& _smtpServer);
		virtual ~PopMailAccount();
	protected:
	private:
};

#endif // POPMAILACCOUNT_H
