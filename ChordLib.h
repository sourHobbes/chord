#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#define PROTOCOL "CHORD";
#define VERSION "1.0";


struct Node {
	int keyID;
	char ipstr[INET6_ADDRSTRLEN];
	short int port;
	struct Node* next;
};

struct Msg {
	char method[15];
	char proto[6];
	char ver[4];
	short int keyID;
	char host[INET6_ADDRSTRLEN];
 	short int hostPort;
	char contact[INET6_ADDRSTRLEN];
	short int contactPort; 
	char* fileName;
	char* contentType;
	int contentLength;
	char* data;
};

int tcpConnect(struct Node* n);
struct Msg* initMsg(); //Allocates space for struct Msg ,initialises it and returns the struct Msg* .
char* framePacket(char* method, short int keyID, struct  Node* n, char* payload, struct Msg** m) ; //Returns a char * which is the packet to be sent.
struct Node * lookup(short int id); // Looks for the node responsible for the specific by executing chord algorithm for lookup .
int sendPkt(int sock,char *buf);
struct Msg* getKey(short int id); // Looks up for the key,finds the node responsible for the key,frames pkt,sends pkt ,receives response and return response in a struct.
struct Msg * tokenizePkt(char *pkt); // Tokenizes the pkt and converts to struct Msg.
char *recvPkt(int sock); // Receives the pkt and returns it as a string.
int action(struct Msg *m); //Takes action based on the values of struct Msg *m ,and returns 0 for pass and non-zero for failure.
int join();// Yet to think about it .
int leave();//Yet to think about it.

