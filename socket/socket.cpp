#include <sys/socket.h>
#include <sys/event.h>
#include <sys/time.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <map>
#include <vector>

# define PORT 9090

void	error_exit(std::string message)
{
	std::cout << message << "\n";
	exit(1);
}

int main(/*int argc, char** argv*/)
{
	int server_sock;
	struct sockaddr_in server_addr;

	if ((server_sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		error_exit("socket() error");

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	// NEED FIX: temp port for debug (atoi(argv))
	server_addr.sin_port=htons(PORT);

	if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
		error_exit("bind() error");
	if (listen(server_sock, 5) == -1)
		error_exit("listen() error");

	fcntl(server_sock, F_SETFL, O_NONBLOCK);

	int	kq;
	kq = kqueue();
	if (kq == -1)
		error_exit("kqueue() error");

	std::map<int, std::string> client_list;
	std::vector<struct kevent> change_list;
	struct kevent event_list[8];

	/* add event for server socket */
	struct kevent temp_event;
	EV_SET(&temp_event, server_sock, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	change_list.push_back(temp_event);

	/* main loop */
	int	new_event;
	struct kevent* curr_event;
	while (1)
	{
		new_event = kevent(kq, &change_list[0], change_list.size(), event_list, 8, NULL);
		if (new_event == -1)
			error_exit("kevent() error");
		sleep(5);
		for (int i = 0; i< new_event; ++i)
		{
			curr_event = &event_list[i];
			std::cout << "print info\n";
			//std::cout << curr_event->flags << curr_event->ident << curr_event->filter << "\n";
		}
	}
}
