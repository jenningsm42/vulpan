#pragma once
#include <string>
#include "Task.h"

namespace vlp {
	class LoadResourceTask : public Task {
	public:
		LoadResourceTask(std::string&&);

		void run(Engine& engine) override;

	private:
		std::string m_path;
	};
}