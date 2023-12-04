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
    char abc = ' ';
    char mode = '1'; //1 for manual, 2 for automatic
    int* a;
    int start_x, start_y, end_x, end_y;

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

    while (true) {
        //now update whole grid to store '*' in it
        for (char i = 0; i < 10; i++) {
            for (char j = 0; j < 10; j++) {
                string vertex = string(1, 'A' + i) + to_string(j);
                graph.update_vertex(i, j, "*");
                graph.update_weight(i, j, 1.0f);
            }
        }

        graph.generate_start();
        graph.generate_end();

        Queue obstacles; //queue to store obstacles
        Queue powerups; //queue to store power-ups

        graph.generate_obstacles(obstacles); //generate random obstacles
        graph.generate_powerups(powerups); //generate random power-ups

        //while (true) {
        system("cls");
        cout << RED << "Welcome to 2D Race Car Game!" << RESET << endl << endl;

        cout << RED << "Press 1 for Manual Mode" << RESET << endl;
        cout << RED << "Press 2 for Automatic Mode" << RESET << endl;
        cout << RED << "Press 3 to view Leaderboard" << RESET << endl;
        cout << RED << "Press 0 to Exit" << RESET << endl << endl;

        cout << RED << "Enter your choice: " << RESET;
        mode = _getch();
        cout << GREEN << mode << endl << endl;
        cout << RESET << endl;

        if (mode == '1') {
            //reset score to 10
            graph.set_score(10);

            cout << RED << "Loading..." << RESET << endl;
            Sleep(1000);

            system("cls");

            cout << RED << "Welcome to 2D Race Car Game - Manual Mode" << RESET << endl << endl;

            cout << RED << "Enter your name: " << RESET;
            string name;
            cout << GREEN;
            getline(cin, name);
            cout<< RESET << endl << endl;

            cout << RED << "Loading..." << RESET << endl;
            Sleep(1000);

            system("cls");

            cout << RED << "Welcome " << GREEN << name << RED << " to 2D Race Car Game - Manual Mode" << RESET << endl << endl;
            cout << RED << "Starting Score: " << RESET << GREEN << "10" << RESET << endl << endl;
            cout << RED << "Current Score: " << RESET << GREEN << graph.get_score() << RESET << endl << endl;

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

                //a[0] stores the value if player wins or not. 0 means player loses, 1 means player wins
                //a[1] stores the value if move is valid or not. 0 means move is invalid, 1 means move is valid

                if (a[0] == 1) {
                    cout << endl << endl << RED << "You Win!" << RESET << endl;
                    cout << RED << "Press any key to continue..." << RESET << endl;
                    abc = _getch();
                    break;
                }

                if (a[0] == 0 && a[1] == 1) { //if player does not win and move is valid
                    system("cls");

                    cout << RED << "Welcome " << GREEN << name << RED << " to 2D Race Car Game - Manual Mode" << RESET << endl << endl;
                    cout << RED << "Starting Score: " << RESET << GREEN << "10" << RESET << endl << endl;
                    cout << RED << "Current Score: " << RESET << GREEN << graph.get_score() << RESET << endl << endl;

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

            //now update whole grid to store '*' in it
            for (char i = 0; i < 10; i++) {
                for (char j = 0; j < 10; j++) {
                    string vertex = string(1, 'A' + i) + to_string(j);
                    graph.update_vertex(i, j, "*");
                    graph.update_weight(i, j, 1.0f);
                }
            }

            //display grid
            graph.display_grid();

            while (true) {
                //ask the user for the start and end coordinates
                cout << RED << "Enter the X coordinates of the start point: " << RESET;
                cout << GREEN;
                cin >> start_x;
                cout << RESET;

                cout << RED << "Enter the Y coordinates of the start point: " << RESET;
                cout << GREEN;
                cin >> start_y;
                cout << RESET;

                cout << endl;

                cout << RED << "Enter the X coordinates of the end point: " << RESET;
                cout << GREEN;
                cin >> end_x;
                cout << RESET;

                cout << RED << "Enter the Y coordinates of the end point: " << RESET;
                cout << GREEN;
                cin >> end_y;
                cout << RESET;

                cout << endl;

                if (start_x < 0 || start_x > 9 || start_y < 0 || start_y > 9 || end_x < 0 || end_x > 9 || end_y < 0 || end_y > 9) {
                    cout << "Invalid Input!" << endl << endl;
                    Sleep(1000);
                }
                else {
                    break;
                }
            }

            graph.update_vertex(start_x, start_y, "S");
            graph.update_weight(start_x, start_y, 0.0f);

            graph.update_vertex(end_x, end_y, "E");
            graph.update_weight(end_x, end_y, 0.0f);

            Queue obstacles_auto; //queue to store obstacles
            Queue powerups_auto; //queue to store power-ups

            graph.generate_obstacles(obstacles_auto); //generate random obstacles
            graph.generate_powerups(powerups_auto); //generate random power-ups

            //display grid
            graph.display_grid();

            //call function to find the shortest path
            cout << RED << "Press any key to continue..." << RESET << endl;
            abc = _getch();

            graph.Dijkstra(start_x, start_y, end_x, end_y);

            cout << endl << RED << "Press any key to continue..." << RESET << endl;
            abc = _getch();
        }

        else if (mode == '3') {
            cout << RED << "Loading..." << RESET << endl;
            Sleep(1000);

            system("cls");

            cout << RED << "2D Race Car Game - LeaderBoard" << RESET << endl << endl;

            string stop;
            cin >> stop;
        }

        else if (mode == '0') {
            //call function to dequeue all the obstacles
            graph.dequeue_obstacles(obstacles);

            //call function to dequeue all the power-ups
            graph.dequeue_powerups(powerups);

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