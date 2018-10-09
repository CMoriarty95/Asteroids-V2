#pragma once
#include <fstream>
class Score {

	int score;
	float hits;
	float shotzFired;
	float accuracy;
public:

	Score() {
		score = 0;
		hits = 0;
		shotzFired = 0;
		accuracy = 0;
	}

	void addHit() {
		hits++;
	}

	void addShot() {
		shotzFired++;
	}

	void displayStats(clock_t start) {
		int hitpts = hits * 100;
		int timepts = (clock() - start) / 100;
		int penalty = (shotzFired - hits) * 10;
		int score = hitpts + timepts - penalty;
		int highScore = 0;

		std::cout << "GAMEOVER" << std::endl << "Time: " << (clock() - start) / 1000 << std::endl << "Score: " <<
			score << std::endl << "Hits: " << hits << std::endl << "Shots Fired: " << shotzFired << std::endl;
		if (shotzFired == 0) { accuracy = 0; }
		else (accuracy = (float)(hits / shotzFired) * 100);
		std::cout << "Accuracy: " << accuracy << "%\n";

		std::fstream f;
		f.open("highscore.txt");

		if (f.fail()) {
			std::cerr << "Error Opening File" << std::endl;
			exit(1);
		}

		f >> highScore;

		
		if(score > highScore){
			std::ofstream out;
			out.open("highscore.txt");
			out << score;
			std::cout << "High Score: " << score << std::endl;
		}
		else std::cout << "High Score: " << highScore << std::endl;
	}

	

};