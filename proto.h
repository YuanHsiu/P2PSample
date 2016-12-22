

#pragma once
#include <list>

// define iMessageType 
#define LOGIN 1
#define LOGOUT 2
#define P2PTRANS 3
#define GETALLUSER  4

// service port
#define SERVER_PORT 2280

// Client login structure
struct stLoginMessage
{
	char userName[10];
	char password[10];
};

// Client logout structure
struct stLogoutMessage
{
	char userName[10];
};

// Client translate structure
struct stP2PTranslate
{
	char userName[10];
};

// Client message structure
struct stMessage
{
	int iMessageType;
	union _message
	{
		stLoginMessage loginmember;
		stLogoutMessage logoutmember;
		stP2PTranslate translatemessage;
	}message;
};

// User list structure
struct stUserListNode
{
	char userName[10];
	unsigned int ip;
	unsigned short port;
};

// Server to Client message structure
struct stServerToClient
{
	int iMessageType;
	union _message
	{
		stUserListNode user;
	}message;

};


#define P2PMESSAGE 100               
#define P2PMESSAGEACK 101            
#define P2PSOMEONEWANTTOCALLYOU 102  
                                     
#define P2PTRASH        103          

struct stP2PMessage
{
	int iMessageType;
	int iStringLen;         // or IP address
	unsigned short Port; 
};

using namespace std;
typedef list<stUserListNode *> UserList;

