#pragma once

#include <arpa/inet.h>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <thread>
#include <tuple>
#include <unistd.h>
#include <unordered_map>
#include <X11/Xlib.h>

#include "config.hh"

namespace matrix_wm {
	typedef std::unordered_map<
			int,
			std::function<void(const XEvent &)>
	> EventHandlers;
	typedef std::unordered_map<
			std::string,
			std::function<void()>
	> CommandHandlers;

	auto error = [&](const char *const &fn) {
		std::cout << "ERROR on " << fn << '\n';
		throw true;
	};

	auto sendSock = [&](const char *const &msg) {
		auto sock_server = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
		if (sock_server < 0) matrix_wm::error("socket");
		else {
			sockaddr_in sai_server;
			bzero((char *) &sai_server, sizeof(sai_server));
			sai_server.sin_family = AF_INET;
			sai_server.sin_addr.s_addr = inet_addr(config::socket_host);
			sai_server.sin_port = htons(config::socket_port_base);
			if (connect(sock_server, (sockaddr *) &sai_server, sizeof(sai_server)) < 0) matrix_wm::error("connect");
			else {
				if (write(sock_server, msg, strlen(msg)) < 0) matrix_wm::error("write");
			}
			close(sock_server);
		}
	};
}

#include "sock.hh"
#include "conn.hh"
#include "control.hh"