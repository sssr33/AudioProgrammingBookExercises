#pragma once

namespace ex5 {
	class Dodecaphonic {
	public:
		Dodecaphonic();
		Dodecaphonic(int *notes);

		int get(int index);
		void set(int note, int index);

		Dodecaphonic transpose(int interval);

		Dodecaphonic invert();
		Dodecaphonic retrograde();

	protected:
		int series[12];

		int mod12(int note);
	};
}