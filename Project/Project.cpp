//Noor_Ul_Baseer_22i2405
//Muhammad_Saleh_22i2583

#include <iostream> //for input and output
#include <string> //for string functions
#include <windows.h> //for sleep function
#include <conio.h> //for _getch() function
#include<iomanip> //for setw() function
#include<fstream> //for file handling

#include "Header.h" //for including header file

using namespace std; //for using standard library

//define colors for output or input text
#define RESET   "\033[0m" //for resetting the color
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main() { //main function 
    Graph graph(100); //create a graph object with 100 vertices

    char move = ' '; //to store the move key pressed by the user
    char abc = ' '; //to store the key pressed by the user
    char mode = '-1'; //to store the mode selected by the user
    int* a; //array to store the return values of move function
    int start_x, start_y, end_x, end_y; //to store the start and end coordinates of S and E

    BST leaderboard; //create a binary search tree object to store the leaderboard

    fstream file; //create a file object

    file.open("Leaderboard.csv", ios::in); //open the file for read

    if (!file) { //if file does not open
		cout << "Error in reading file!" << endl;
	}

    else { //if file opens successfully
        string line; //to store the line read from the file

        while (getline(file, line)) { //read the file line by line
            string temp = line; //store the line in a temporary string

            string name = temp.substr(0, temp.find(",")); //extract the name from the line and store it in name

            string score = temp.substr(temp.find(",") + 1, temp.length()); //extract the score from the line and store it in score

            int score_int = stoi(score); //convert the score from string to integer

            leaderboard.insert(name, score_int); //insert the name and score in the leaderboard
        }
    }

    //display leaderboard
    /*leaderboard.display(leaderboard.get_root());
    abc = _getch();*/

    file.close(); //close the file

    //represent all the vertices as A0, B0, A1, B1, and so on then add them to the graph
    for (char i = 0; i < 10; i++) { 
        for (char j = 0; j < 10; j++) {
            string vertex = string(1, 'A' + i) + to_string(j);
            graph.add_vertex(vertex, i, j);
        }
    }

    //add edges to the graph
    for (char i = 0; i < 10; i++) {
        for (char j = 0; j < 10; j++) {
            string vertex = string(1, 'A' + i) + to_string(j); //store the vertex representation in string
            if (i > 0) {
                string up = string(1, 'A' + i - 1) + to_string(j); //store the vertex representation of the vertex above the current vertex in string
                graph.add_edge(vertex, up, 1.0f); //add edge between the current vertex and the vertex above it
            }
            if (i < 9) {
                string down = string(1, 'A' + i + 1) + to_string(j); //store the vertex representation of the vertex below the current vertex in string
                graph.add_edge(vertex, down, 1.0f); //add edge between the current vertex and the vertex below it
            }
            if (j > 0) {
                string left = string(1, 'A' + i) + to_string(j - 1); //store the vertex representation of the vertex left to the current vertex in string
                graph.add_edge(vertex, left, 1.0f); //add edge between the current vertex and the vertex left to it
            }
            if (j < 9) {
                string right = string(1, 'A' + i) + to_string(j + 1); //store the vertex representation of the vertex right to the current vertex in string
                graph.add_edge(vertex, right, 1.0f); //add edge between the current vertex and the vertex right to it
            }
        }
    }

    while (true) {
        //represent all the vertices as * and assign weight 1 to them
        for (char i = 0; i < 10; i++) {
            for (char j = 0; j < 10; j++) {
                string vertex = string(1, 'A' + i) + to_string(j);
                graph.update_vertex(i, j, "*");
                graph.update_weight(i, j, 1.0f);
            }
        }

        graph.generate_start(); //randomly generate start position
        graph.generate_end(); //randomly generate end position

        Queue obstacles; //queue to store obstacles in the graph
        Queue powerups; //queue to store power-ups in the graph

        graph.generate_obstacles(obstacles); //generate random obstacles to be placed in the graph
        graph.generate_powerups(powerups); //generate random power-ups to be placed in the graph

        //while (true) {
        system("cls"); //clear the screen
        cout << RED << "Welcome to 2D Race Car Game!" << RESET << endl << endl;

        //menu
        cout << RED << "Press 1 for Manual Mode" << RESET << endl;
        cout << RED << "Press 2 for Automatic Mode" << RESET << endl;
        cout << RED << "Press 3 to view Leaderboard" << RESET << endl;
        cout << RED << "Press 0 to Exit" << RESET << endl << endl;

        cout << RED << "Enter your choice: " << RESET;
        mode = _getch(); //get the mode selected by the user without pressing enter
        cout << GREEN << mode << endl << endl;
        cout << RESET << endl; //reset the color

        if (mode == '1') { //if manual mode is selected
            graph.set_score(10); //reset the score to 10

            cout << RED << "Loading..." << RESET << endl;
            Sleep(1000); //wait for 1 second

            system("cls"); //clear the screen

            cout << RED << "Welcome to 2D Race Car Game - Manual Mode" << RESET << endl << endl;

            cout << RED << "Enter your name: " << RESET; //ask the user to enter his/her name
            string name;
            cout << GREEN;
            getline(cin, name);
            cout<< RESET << endl << endl;

            if (leaderboard.search(name) == true) { //if the name already exists in the leaderboard
                graph.set_score(leaderboard.get_score(name)); //set the score to the score of the player stored in the leaderboard
			}
            else { //if the name does not exist in the leaderboard
				leaderboard.insert(name, graph.get_score()); //insert the name and score in the leaderboard
			}

            cout << RED << "Loading..." << RESET << endl;
            Sleep(1000); //wait for 1 second

            system("cls"); //clear the screen

            //welcome message and score
            cout << RED << "Welcome " << GREEN << name << RED << " to 2D Race Car Game - Manual Mode" << RESET << endl << endl;
            cout << RED << "Starting Score: " << RESET << GREEN << "10" << RESET << endl << endl;
            cout << RED << "Current Score: " << RESET << GREEN << graph.get_score() << RESET << endl << endl;

            graph.display_grid(); //display the grid

            //controls
            cout << BLUE << "\tControls:" << RESET << endl;
            cout << RED << "W and up arrow " << RESET << "-" << RED << " Accelerate" << RESET << endl;
            cout << RED << "S and down arrow " << RESET << "-" << RED << " Brake and reverse" << RESET << endl;
            cout << RED << "A and left arrow " << RESET << "-" << RED << " Turn left" << RESET << endl;
            cout << RED << "D and right arrow " << RESET << "-" << RED << " Turn right" << RESET << endl;
            cout << RED << "ESC " << RESET << "-" << RED << " Exit" << RESET << endl << endl;

            //keys
            cout << BLUE << "Key:" << RESET << endl;
            cout << RED << "Car: " << RESET << GREEN << "C" << RESET << endl;
            cout << RED << "Start Line: " << RESET << GREEN << "S" << RESET << endl;
            cout << RED << "Finish Line: " << RESET << GREEN << "E" << RESET << endl;
            cout << RED << "Power-Ups: " << RESET << GREEN << "+" << RESET << endl;
            cout << RED << "Obstacles: " << RESET << GREEN << "#" << RESET << endl << endl;

            while (true) { //loop until the player wins or presses ESC
                move = _getch(); //get the move key pressed by the user without pressing enter

                if (move == 27) { //if ESC is pressed, exit the game
                    cout << endl << endl << RED << "Exiting..." << RESET << endl;
                    Sleep(1000); //wait for 1 second

                    break; //break the loop
                }

                else { //if any other key is pressed
                    a = graph.move(move); //call the move function to move the car
                }

                if (a[0] == 1) { //if player wins
                    cout << endl << endl << RED << "You Win!" << RESET << endl;
                    cout << RED << "Press any key to continue..." << RESET << endl;
                    abc = _getch();
                    break;
                }

                if (a[0] == 0 && a[1] == 1) { //if player does not win and move is invalid
                    system("cls"); //clear the screen

                    //welcome message and score
                    cout << RED << "Welcome " << GREEN << name << RED << " to 2D Race Car Game - Manual Mode" << RESET << endl << endl;
                    cout << RED << "Starting Score: " << RESET << GREEN << "10" << RESET << endl << endl;
                    cout << RED << "Current Score: " << RESET << GREEN << graph.get_score() << RESET << endl << endl;

                    graph.display_grid(); //display the grid

                    //controls
                    cout << BLUE << "\tControls:" << RESET << endl;
                    cout << RED << "W and up arrow " << RESET << "-" << RED << " Accelerate" << RESET << endl;
                    cout << RED << "S and down arrow " << RESET << "-" << RED << " Brake and reverse" << RESET << endl;
                    cout << RED << "A and left arrow " << RESET << "-" << RED << " Turn left" << RESET << endl;
                    cout << RED << "D and right arrow " << RESET << "-" << RED << " Turn right" << RESET << endl;
                    cout << RED << "ESC " << RESET << "-" << RED << " Exit" << RESET << endl << endl;

                    //keys
                    cout << BLUE << "Key:" << RESET << endl;
                    cout << RED << "Car: " << RESET << GREEN << "C" << RESET << endl;
                    cout << RED << "Start Line: " << RESET << GREEN << "S" << RESET << endl;
                    cout << RED << "Finish Line: " << RESET << GREEN << "E" << RESET << endl;
                    cout << RED << "Power-Ups: " << RESET << GREEN << "+" << RESET << endl;
                    cout << RED << "Obstacles: " << RESET << GREEN << "#" << RESET << endl << endl;
                }
            }

            leaderboard.update_score(name, graph.get_score()); //update the score of the player in the leaderboard

            file.open("Leaderboard.csv", ios::out); //open the file for write

            if (file.is_open()) { //if file opens successfully
				file.clear(); //clear the file
				file.seekg(0, ios::beg); //move the pointer to the beginning of the file

                leaderboard.write_file(file, leaderboard.get_root()); //write the leaderboard to the file
			}

			file.close(); //close the file
        }

        else if (mode == '2') { //if automatic mode is selected
            cout << RED << "Loading..." << RESET << endl;
            Sleep(1000); //wait for 1 second

            system("cls"); //clear the screen

            cout << RED << "2D Race Car Game - Automatic Mode" << RESET << endl << endl;

            //represent all the vertices as * and assign weight 1 to them
            for (char i = 0; i < 10; i++) { 
                for (char j = 0; j < 10; j++) {
                    string vertex = string(1, 'A' + i) + to_string(j);
                    graph.update_vertex(i, j, "*");
                    graph.update_weight(i, j, 1.0f);
                }
            }

            graph.display_grid(); //display the grid

            while (true) {
                //ask the user to enter the start and end coordinates of S and E
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

                //check if the coordinates entered by the user are valid
                if (start_x < 0 || start_x > 9 || start_y < 0 || start_y > 9 || end_x < 0 || end_x > 9 || end_y < 0 || end_y > 9) {
                    cout << "Invalid Input!" << endl << endl;
                    Sleep(1000); //wait for 1 second
                }
                else { //if the coordinates entered by the user are valid
                    break;
                }
            }

            graph.update_vertex(start_x, start_y, "S"); //update the start vertex
            graph.update_weight(start_x, start_y, 0.0f); //update the weight of the start vertex

            graph.update_vertex(end_x, end_y, "E"); //update the end vertex
            graph.update_weight(end_x, end_y, 0.0f); //update the weight of the end vertex

            Queue obstacles_auto; //queue to store obstacles
            Queue powerups_auto; //queue to store power-ups

            graph.generate_obstacles(obstacles_auto); //generate random obstacles
            graph.generate_powerups(powerups_auto); //generate random power-ups

            graph.display_grid(); //display the grid

            cout << RED << "Press any key to continue..." << RESET << endl;
            abc = _getch();

            graph.Dijkstra(start_x, start_y, end_x, end_y); //call the Dijkstra function to find the shortest path from S to E

            cout << endl << RED << "Press any key to continue..." << RESET << endl;
            abc = _getch();
        }

        else if (mode == '3') { //if leaderboard is selected
            cout << RED << "Loading..." << RESET << endl;
            Sleep(1000); //wait for 1 second

            system("cls"); //clear the screen

            cout << RED << "2D Race Car Game - LeaderBoard" << RESET << endl << endl;

            leaderboard.display(leaderboard.get_root()); //display the leaderboard
            
            cout << endl << RED << "Press any key to continue..." << RESET << endl;
            abc = _getch();
        }

        //else if (mode == '4') {
        //    cout << "Enter the name to be searched" << endl;
        //    string name;
        //    cin >> name;

        //    //leaderboard.display(leaderboard.get_root());

        //    cout << leaderboard.search(name) << endl;
        //    //cout << leaderboard.get_score(name) << endl;

        //    abc = _getch();
        //}

        else if (mode == '0') { //if exit is selected
            graph.dequeue_obstacles(obstacles); //dequeue the obstacles queue

            graph.dequeue_powerups(powerups); //dequeue the power-ups queue

            cout << RED << "Exiting..." << RESET << endl;
            Sleep(1000); //wait for 1 second
            return 0;
        }

        else { //if any other key is pressed instead of 0, 1, 2, or 3
            cout << "Invalid Input!" << endl;
            Sleep(1000); //wait for 1 second
        }
    }
    return 0; //return 0 to indicate successful termination of the program
}