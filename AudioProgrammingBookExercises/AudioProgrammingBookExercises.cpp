// AudioProgrammingBookExercises.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdio>
#include <string>
#include <conio.h>

/*
Calculates the interval between two notes and prints its semitone length and name.
*/
int ex0();
int ex0_nameToPc(char name);

/*
Classic Fahrenheit-to-Celsius conversion table.
*/
int ex1();

/*
Prints the notes of a major scale in ascending steps.
*/
int ex2();
int ex2_v1();

int main() {
	int res = 0;

	res = ex2_v1();

	_getch();
	return res;
}

int ex0() {
	// dummy used for 'enter'
	char note1, note2, dummy;
	int pc1, pc2, interval;

	printf("Please enter two natural notes.\nfirst note: ");
	scanf("%c%c", &note1, &dummy);

	printf("second node: ");
	scanf("%c", &note2);

	pc1 = ex0_nameToPc(note1);
	if (pc1 < 0) {
		printf("error: %c is not a natural note\n", note1); return 1;
	}

	pc2 = ex0_nameToPc(note2);
	if (pc2 < 0) {
		printf("error: %c is not a natural note\n", note2); return 1;
	}

	interval = pc2 - pc1;

	if (interval < 0) {
		interval += 12;
	}
	else if (interval > 11) {
		interval -= 12;
	}

	printf("%d semitones up or %d semitones down\n", interval, interval ? 12 - interval : 0);

	switch (interval) {
	case 1:
		printf("minor 2nd up or major 7th down\n");
		break;
	case 2:
		printf("major 2nd up or minor 7th down\n");
		break;
	case 3:
		printf("minor 3rd up or major 6th down\n");
		break;
	case 4:
		printf("major 3rd up or minor 6th down\n");
		break;
	case 5:
		printf("perfect 4th up or perfect 5th down\n");
		break;
	case 6:
		printf("augmented 4th\n");
		break;
	case 7:
		printf("perfect 5th up or perfect 4th down\n");
		break;
	case 8:
		printf("minor 6th up or major 3rd down\n");
		break;
	case 9:
		printf("major 6th up or minor 3rd down\n");
		break;
	case 10:
		printf("minor 7th up or major 2nd down\n");
		break;
	case 11:
		printf("major 7th up or minor 2nd down\n");
		break;
	default:
		printf("unison\n");
		break;
	}

	return 0;
}

int ex0_nameToPc(char name) {
	switch (name) {
	case 'C':
	case 'c':
		return 0;
		break;
	case 'D':
	case 'd':
		return 2;
		break;
	case 'E':
	case 'e':
		return 4;
		break;
	case 'F':
	case 'f':
		return 5;
		break;
	case 'G':
	case 'g':
		return 7;
		break;
	case 'A':
	case 'a':
		return 9;
		break;
	case 'B':
	case 'b':
		return 11;
		break;
	default:
		return -1;
		break;
	}
}

int ex1() {
	for (int fahr = 0; fahr <= 300; fahr += 20) {
		printf("%4d, %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
	}

	return 0;
}

int ex2() {
	int note, i;

	printf("Please enter the key (in pitch-class number, 0-11): ");
	scanf("%d", &note);

	while (note < 0) note += 12;

	for (i = 0; i < 7; i++) {
		if (note % 12 == 0) {
			printf("C");
		}
		else if (note % 12 == 1) {
			printf("Db");
		}
		else if (note % 12 == 2) {
			printf("D");
		}
		else if (note % 12 == 3) {
			printf("Eb");
		}
		else if (note % 12 == 4) {
			printf("E");
		}
		else if (note % 12 == 5) {
			printf("F");
		}
		else if (note % 12 == 6) {
			printf("Gb");
		}
		else if (note % 12 == 7) {
			printf("G");
		}
		else if (note % 12 == 8) {
			printf("Ab");
		}
		else if (note % 12 == 9) {
			printf("A");
		}
		else if (note % 12 == 10) {
			printf("Bb");
		}
		else {
			printf("B");
		}

		printf(" ");

		if (i != 2) {
			note += 2;
		}
		else {
			note++;
		}
	}

	return 0;
}

int ex2_v1() {
	int note, i;
	char key[3];
	char *scale[12] = { "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B" };

	printf("Please enter the key(capitals only, use b for flats, eg. Eb): ");
	scanf("%s", key);

	for (i = 0; i < 12; i++) {
		if (strcmp(scale[i], key) == 0) {
			note = i;
			printf("== %s major scale ==\n", key);
			break;
		}
		else {
			note = -1;
		}
	}

	if (note >= 0) {
		for (i = 0; i < 7; i++) {
			printf("%s ", scale[note % 12]);

			if (i != 2) {
				note += 2;
			}
			else {
				note++;
			}
		}
	}
	else {
		printf("%s: invalid key\n", key);
		return 1;
	}

	return 0;
}