#include "include/ResourceCache.h"
#include "include/ResourceLoader.h"

namespace vlp {
	ResourceCache::ResourceCache() {
	}

	ResourceCache::~ResourceCache() {
		for (auto& resource : m_resources) {
			delete resource.second;
		}
	}
}