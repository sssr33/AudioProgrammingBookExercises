#include "Dodecaphonic_ex5.h"

namespace ex5 {
	Dodecaphonic::Dodecaphonic() {
		for (int i = 0; i < 12; i++) {
			this->series[i] = 0;
		}
	}

	Dodecaphonic::Dodecaphonic(int *notes) {
		for (int i = 0; i < 12; i++) {
			this->series[i] = this->mod12(notes[i]);
		}
	}

	int Dodecaphonic::get(int index) {
		return this->series[this->mod12(index)];
	}

	void Dodecaphonic::set(int note, int index) {
		this->series[this->mod12(index)] = this->mod12(note);
	}

	int Dodecaphonic::mod12(int note) {
		while (note >= 12) {
			note -= 12;
		}

		while (note < 0) {
			note += 12;
		}

		return note;
	}

	Dodecaphonic Dodecaphonic::transpose(int interval) {
		Dodecaphonic transp;

		for (int i = 0; i < 12; i++) {
			int note = this->mod12(this->series[i] + interval);
			transp.set(note, i);
		}

		return transp;
	}

	Dodecaphonic Dodecaphonic::invert() {
		Dodecaphonic inv;

		inv.set(this->series[0], 0);

		for (int i = 1; i < 12; i++) {
			int note = this->mod12(inv.get(i - 1) + this->series[i - 1] - series[i]);
			inv.set(note, i);
		}

		return inv;
	}

	Dodecaphonic Dodecaphonic::retrograde() {
		Dodecaphonic retr;

		for (int i = 0; i < 12; i++) {
			retr.set(this->series[i], 11 - i);
		}

		return retr;
	}
}