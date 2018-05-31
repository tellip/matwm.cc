#pragma once

#include <arpa/inet.h>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <thread>
#include <unistd.h>
#include <unordered_map>
#include <X11/Xlib.h>

#include "../public.hh"

namespace wm {
	namespace matrix {
		class Space;

		class Node;

		namespace node {
			class Branch;

			class Leaf;
		}
	}
}

#include "server.hh"
#include "matrix.hh"