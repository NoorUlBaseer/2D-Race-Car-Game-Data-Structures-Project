#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Header.h"
using namespace std;

int main() {
    Graph graph(100);
    char move = ' ';

    for (char i = 0; i < 10; i++) {
        for (char j = 0; j < 10; j++) {
            string vertex = string(1, 'A' + i) + to_string(j);
            graph.add_vertex(vertex, i, j);
        }
    }

    for (char i = 0; i < 10; i++) {
        for (char j = 0; j < 10; j++) {
            string vertex = string(1, 'A' + i) + to_string(j);
            if (i > 0) {
                string up = string(1, 'A' + i - 1) + to_string(j);
                graph.add_edge(vertex, up, 1.0f);
            }
            if (i < 9) {
                string down = string(1, 'A' + i + 1) + to_string(j);
                graph.add_edge(vertex, down, 1.0f);
            }
            if (j > 0) {
                string left = string(1, 'A' + i) + to_string(j - 1);
                graph.add_edge(vertex, left, 1.0f);
            }
            if (j < 9) {
                string right = string(1, 'A' + i) + to_string(j + 1);
                graph.add_edge(vertex, right, 1.0f);
            }
        }
    }

    //now update whole grid to store '*' in it
    for (char i = 0; i < 10; i++) {
        for (char j = 0; j < 10; j++) {
            string vertex = string(1, 'A' + i) + to_string(j);
            graph.update_vertex(i, j, "*");
        }
    }

    //now placve 'C' at (2, 5)
    graph.update_vertex(2, 5, "C");

    graph.update_vertex(0, 0, "S");

    graph.update_vertex(9, 9, "E");

    graph.update_vertex(5, 8, "X");

    graph.update_vertex(3, 2, "#");

    while (true) {
		graph.display_grid();
        
        char move = _getch();

		if (move == 27) { //ESC
			break;
		}
		else {
            system("cls");
            graph.move(move);
		}
	}

    return 0;
}