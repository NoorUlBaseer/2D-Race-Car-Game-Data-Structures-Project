#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include<iomanip>
#include "Header.h"
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
//#define WHITE   "\033[37m"

int main() {
    Graph graph(100);

    char move = ' ';
    int a = -1; //to check if move is valid or not
    char mode = '1'; //1 for manual, 2 for automatic

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

    //place power-ups
    graph.update_vertex(5, 8, "X"); //power-up
    graph.update_weight(5, 8, -5.0f); //power-up

    graph.update_vertex(5, 5, "X"); //power-up
    graph.update_weight(5, 5, -5.0f); //power-up

    graph.update_vertex(9, 5, "X"); //power-up
    graph.update_weight(9, 5, -5.0f); //power-up

    graph.update_vertex(5, 1, "X"); //power-up
    graph.update_weight(5, 1, -5.0f); //power-up

    graph.update_vertex(0, 2, "X"); //power-up
    graph.update_weight(0, 2, -5.0f); //power-up

    graph.update_vertex(0, 6, "X"); //power-up
    graph.update_weight(0, 6, -5.0f); //power-up

    //place obstacles
    graph.update_vertex(3, 2, "#"); //obstacle 
    graph.update_weight(3, 2, 20.0f); //obstacle

    graph.update_vertex(3, 3, "#"); //obstacle
    graph.update_weight(3, 3, 20.0f); //obstacle

    graph.update_vertex(3, 4, "#"); //obstacle
    graph.update_weight(3, 4, 20.0f); //obstacle

    graph.update_vertex(3, 5, "#"); //obstacle
    graph.update_weight(3, 5, 20.0f); //obstacle


    graph.update_vertex(4, 4, "#"); //obstacle
    graph.update_weight(4, 4, 20.0f); //obstacle

    graph.update_vertex(5, 4, "#"); //obstacle
    graph.update_weight(5, 4, 20.0f); //obstacle

    while (true) {
        system("cls");
        cout << RED << "Welcome to 2D Race Car Game!" << RESET << endl << endl;

        cout << RED << "Press 1 for Manual Mode" << RESET << endl;
        cout << RED << "Press 2 for Automatic Mode" << RESET << endl;
        cout << RED << "Press 0 to Exit" << RESET << endl << endl;

        cout << RED << "Enter your choice: ";
        mode = _getch();
        cout << mode << endl << endl;
        cout << RESET << endl;

        if (mode == '1') {
            cout << RED << "Loading..." << RESET << endl;
            Sleep(1000);

            system("cls");

            cout << RED << "2D Race Car Game - Manual Mode" << RESET << endl << endl;
            graph.display_grid();

            //controls
            cout << BLUE << "\tControls:" << RESET << endl;
            cout << RED << "W and up arrow " << RESET << "-" << RED << " Accelerate" << RESET << endl;
            cout << RED << "S and down arrow " << RESET << "-" << RED << " Brake and reverse" << RESET << endl;
            cout << RED << "A and left arrow " << RESET << "-" << RED << " Turn left" << RESET << endl;
            cout << RED << "D and right arrow " << RESET << "-" << RED << " Turn right" << RESET << endl;
            cout << RED << "ESC " << RESET << "-" << RED << " Exit" << RESET << endl << endl;

            //key
            cout << BLUE << "Key:" << RESET << endl;
            cout << RED << "Car: " << RESET << GREEN << "C" << RESET << endl;
            cout << RED << "Start Line: " << RESET << GREEN << "S" << RESET << endl;
            cout << RED << "Finish Line: " << RESET << GREEN << "E" << RESET << endl;
            cout << RED << "Power-Ups: " << RESET << GREEN << "+" << RESET << endl;
            cout << RED << "Obstacles: " << RESET << GREEN << "#" << RESET << endl << endl;

            while (true) {
                move = _getch();

                if (move == 27) { //ESC
                    cout << endl << endl << RED << "Exiting..." << RESET << endl;
                    Sleep(1000);

                    break;
                }
                else {

                    a = graph.move(move);
                }

                if (a == 1) { //if move is valid
                    system("cls");

                    cout << RED << "2D Race Car Game - Manual Mode" << RESET << endl << endl;
                    graph.display_grid();

                    //controls
                    cout << BLUE << "\tControls:" << RESET << endl;
                    cout << RED << "W and up arrow " << RESET << "-" << RED << " Accelerate" << RESET << endl;
                    cout << RED << "S and down arrow " << RESET << "-" << RED << " Brake and reverse" << RESET << endl;
                    cout << RED << "A and left arrow " << RESET << "-" << RED << " Turn left" << RESET << endl;
                    cout << RED << "D and right arrow " << RESET << "-" << RED << " Turn right" << RESET << endl;
                    cout << RED << "ESC " << RESET << "-" << RED << " Exit" << RESET << endl << endl;

                    //key
                    cout << BLUE << "Key:" << RESET << endl;
                    cout << RED << "Car: " << RESET << GREEN << "C" << RESET << endl;
                    cout << RED << "Start Line: " << RESET << GREEN << "S" << RESET << endl;
                    cout << RED << "Finish Line: " << RESET << GREEN << "E" << RESET << endl;
                    cout << RED << "Power-Ups: " << RESET << GREEN << "+" << RESET << endl;
                    cout << RED << "Obstacles: " << RESET << GREEN << "#" << RESET << endl << endl;
                }
            }
        }

        else if (mode == '2') {
            cout << RED << "Loading..." << RESET << endl;
            Sleep(1000);

            system("cls");

            cout << RED << "2D Race Car Game - Automatic Mode" << RESET << endl << endl;

            string stop;
            cin >> stop;
        }

        else if (mode == '0') {
            cout << RED << "Exiting..." << RESET << endl;
            Sleep(1000);
            return 0;
        }

        else {
			cout << "Invalid Input!" << endl;
			Sleep(1000);
		}
    }
    return 0;
}