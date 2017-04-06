#pragma once

namespace vlp {
	class Engine;

	class Task {
	public:
		Task() {}
		Task(Task&&) = default;
		virtual ~Task() = default;

		virtual void run(Engine& engine) = 0;
	};
}
