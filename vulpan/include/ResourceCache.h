#pragma once
#include <unordered_map>
#include "Resource.h"
#include "Logger.h"

namespace vlp {
	class ResourceCache {
	public:
		ResourceCache();
		~ResourceCache();

		template <typename T>
		void add(const std::string& name, const T& resource) {
			if (m_resources.find(name) != m_resources.end()) {
				logger.log("Resource '%s' already exists", name.c_str());
				return;
			}

			auto copy = new T();
			memcpy(copy, &resource, sizeof(T));
			m_resources.emplace(name, copy);
		}

		template <typename T>
		const T get(const std::string& name) {
			if (m_resources.find(name) == m_resources.end()) {
				logger.log("Could not find resource '%s'", name.c_str());
				return T();
			}

			auto resource = m_resources[name];
			if (resource->getType() != typeid(T).hash_code()) {
				logger.log("Resource '%s' has type id %zu (expected %zu)",
				           name.c_str(),
				           resource->getType(),
				           typeid(T).hash_code());
				return T();
			}

			return *static_cast<T*>(resource);
		}

	private:
		std::unordered_map<std::string, Resource*> m_resources;
	};
}