#pragma once
#include <typeinfo>

namespace vlp {
	struct Resource {
		virtual size_t getType() const noexcept = 0;
		bool loaded = false;
	};
}