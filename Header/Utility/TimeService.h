#pragma once
#include <chrono>

using namespace std;

namespace Utility 
{
	class TimeService 
	{
	private:
		chrono::steady_clock::time_point previous_time;
		float delta_time;

		void updateDeltaTime();
		float calculateDeltaTime();
		void calculatePreviousTime();

	public:
		void initialize();
		void update();
		float getDeltaTime();
	};
}