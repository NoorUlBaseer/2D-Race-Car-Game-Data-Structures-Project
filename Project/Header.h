//Noor_Ul_Baseer_22i2405
//Muhammad_Saleh_22i2583

#pragma once
#include <iostream> // for cout and cin
#include <string> // for string
#include <cstdlib> // for rand and srand
#include <ctime> // for time
#include <windows.h> //for sleep function
#include <conio.h> //for _getch() function
#include<iomanip> //for setw() function
#include<fstream> //for file handling

using namespace std; // for cout and cin

//define colors for output or input text
#define RESET   "\033[0m" //for resetting the color
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class Graph_Node { //class for the nodes of the graph
public: //public variables and functions
	string data; //representaion of the vertex
	float weight; //weight of the edge
	int x, y; //coordinates of the vertex
	Graph_Node* next; //pointer to the next node

	Graph_Node() { //default constructor
		data = "";
		weight = 0;
		x = 0;
		y = 0;
		next = NULL;
	}

	Graph_Node(string data, float weight, int x, int y) { //parameterized constructor
		this->data = data;
		this->weight = weight;
		this->x = x;
		this->y = y;
		next = NULL;
	}
};

class Linked_List_Node { //class for the nodes of the linked list
public: //public variables and functions
	Graph_Node data; //data of the node
	Linked_List_Node* next; //pointer to the next node

	Linked_List_Node(Graph_Node data) { //parameterized constructor
		this->data = data;
		this->next = NULL;
	}
};

class Linked_List { //class for the linked list
private: //private variables and functions
	Linked_List_Node* head; //pointer to the head of the linked list

public: //public variables and functions
	Linked_List() { //default constructor
		this->head = NULL;
	}

	void set_head(Linked_List_Node* head) { //setter function for the head
		this->head = head;
	}

	Linked_List_Node* get_head() { //getter function for the head
		return this->head;
	}

	void insert(Graph_Node data) { //function to insert a node in the linked list
		Linked_List_Node* newNode = new Linked_List_Node(data); //create a new node

		if (this->head == nullptr) { //if the linked list is empty
			this->head = newNode; //set the head to the new node
		}

		else { //if the linked list is not empty
			Linked_List_Node* temp = this->head; //create a temporary node and set it to the head

			while (temp->next) { //traverse the linked list till the end
				temp = temp->next; //set the temporary node to the next node
			}
			temp->next = newNode; //set the next of the last node to the new node
		}
	}

	void display() { //function to display the linked list
		Linked_List_Node* temp = this->head; //create a temporary node and set it to the head

		while (temp) { //traverse the linked list till the end
			cout << temp->data.data << " "; //display the data of the node
			temp = temp->next; //set the temporary node to the next node
		}
		cout << endl;
	}
};

class Queue_Node { //class for the nodes of the queue
public:
	Graph_Node data; //data of the node
	Queue_Node* next; //pointer to the next node

	Queue_Node(Graph_Node data) { //parameterized constructor
		this->data = data;
		next = NULL;
	}

	Queue_Node() { //default constructor
		next = NULL;
	}
};

class Queue { //class for the queue
private:
	Queue_Node* front; //pointer to the front of the queue
	Queue_Node* rear; //pointer to the rear of the queue
	int size; //size of the queue

public:
	Queue() { //default constructor
		front = NULL;
		rear = NULL;
		size = 0;
	}

	void enqueue(Graph_Node data) { //function to insert a node in the queue
		Queue_Node* newNode = new Queue_Node(data); //create a new node

		if (front == NULL) { //if the queue is empty
			front = newNode;
			rear = newNode;
		}

		else { //if the queue is not empty
			rear->next = newNode; //set the next of the rear to the new node
			rear = newNode; //set the rear to the new node
		}

		size++; //increment the size of the queue
	}

	Queue_Node* dequeue() { //function to delete a node from the queue
		Queue_Node* temp = front; //create a temporary node and set it to the front

		if (front == NULL) { //if the queue is empty
			cout << "Queue is empty" << endl;
			//return Queue_Node();
		}

		else if (front == rear) { //if the queue has only one node
			front = NULL;
			rear = NULL;
		}

		else { //if the queue has more than one node
			front = front->next; //set the front to the next of the front
		}

		size--; //decrement the size of the queue
		return temp; //return the temporary node
	}

	bool is_empty() { //function to check if the queue is empty
		if (front == NULL) { //if the queue is empty, return true
			return true;
		}
		return false; //if the queue is not empty, return false
	}

	void display() { //function to display the queue
		Queue_Node* temp = front; //create a temporary node and set it to the front

		while (temp) { //traverse the queue till the end
			cout << temp->data.data << " "; //display the data of the node
			temp = temp->next; //set the temporary node to the next node
		}
		cout << endl;
	}

	int get_size() { //function to get the size of the queue
		return size;
	}

	Queue_Node* get_front() { //function to get the front of the queue
		return front;
	}

	Queue_Node* get_rear() { //function to get the rear of the queue
		return rear;
	}
};

class Graph { //class for the graph
private: //private variables and functions
	Linked_List* adjacency_list;
	int num_of_vertices, num_of_vertex;
	int start_x, start_y, end_x, end_y; // coordinates of the start and end positions
	int score; // score of the player

public: //public variables and functions
	Graph(int num_of_vertices) { //parameterized constructor
		this->num_of_vertices = num_of_vertices;
		num_of_vertex = 0;
		adjacency_list = new Linked_List[num_of_vertices];

		start_x = -1;
		start_y = -1;
		end_x = -1;
		end_y = -1;

		score = 10;
	}

	Graph() { //default constructor
			num_of_vertices = 100;
			num_of_vertex = 0;
			adjacency_list = new Linked_List[num_of_vertices];
	
			start_x = -1;
			start_y = -1;
			end_x = -1;
			end_y = -1;
	
			score = 10;
		}

	void set_score(int score) { //setter function for the score
		this->score = score;
	}

	int get_score() { //getter function for the score
		return score;
	}

	void add_vertex(string vertex, int x, int y) { //function to add a vertex in the graph
		Graph_Node* newNode = new Graph_Node(vertex, 0, x, y); //create a new node
		adjacency_list[num_of_vertex].insert(*newNode); //insert the new node in the adjacency linked list
		num_of_vertex++; //increment the number of vertices
	}

	void add_edge(string vertex1, string vertex2, float weight) { //function to add an edge in the graph
		int index1 = -1, index2 = -1;

		for (int i = 0; i < num_of_vertex; i++) { //traverse the adjacency list
			if (adjacency_list[i].get_head()->data.data == vertex1) { //if the vertex1 is found
				index1 = i;
			}
			if (adjacency_list[i].get_head()->data.data == vertex2) { //if the vertex2 is found
				index2 = i;
			}
		}

		if (index1 == -1 || index2 == -1) { //if any of the vertices is not found
			cout << "Vertex not found" << endl;
			return;
		}

		//create two new nodes
		Graph_Node* newNode1 = new Graph_Node(vertex2, weight, adjacency_list[index1].get_head()->data.x, adjacency_list[index1].get_head()->data.y);
		Graph_Node* newNode2 = new Graph_Node(vertex1, weight, adjacency_list[index2].get_head()->data.x, adjacency_list[index2].get_head()->data.y);

		adjacency_list[index1].insert(*newNode1); //insert the new node1 in the adjacency linked list of vertex1
		adjacency_list[index2].insert(*newNode2); //insert the new node2 in the adjacency linked list of vertex2
	}

	void display() { //function to display the graph
		for (int i = 0; i < num_of_vertex; i++) { //traverse the adjacency list
			adjacency_list[i].display(); //display the adjacency linked list
		}
	}

	void update_vertex(int x, int y, string new_vertex) { //function to update a vertex with the given x and y coordinates
		for (int i = 0; i < num_of_vertex; i++) { //traverse the adjacency list
			if (adjacency_list[i].get_head()->data.x == x && adjacency_list[i].get_head()->data.y == y) { //if the vertex is found
				adjacency_list[i].get_head()->data.data = new_vertex; //update the vertex
				break; //break the loop
			}
		}
	}
	
	void update_weight(int x, int y, float new_weight) { //function to update the weight of a vertex with the given x and y coordinates
		for (int i = 0; i < num_of_vertex; i++) { //traverse the adjacency list
			if (adjacency_list[i].get_head()->data.x == x && adjacency_list[i].get_head()->data.y == y) { //if the vertex is found
				adjacency_list[i].get_head()->data.weight = new_weight; //update the weight of the vertex
				break; //break the loop
			}
		}
	}

	int get_vertex_cordinates_x(string vertex) { //function to get the x coordinate of a vertex
		for (int i = 0; i < num_of_vertex; i++) { //traverse the adjacency list
			if (adjacency_list[i].get_head()->data.data == vertex) { //if the vertex is found
				return adjacency_list[i].get_head()->data.x; //return the x coordinate of the vertex
			}
		}
		return -1; //if the vertex is not found, return -1
	}

	int get_vertex_cordinates_y(string vertex) { //function to get the y coordinate of a vertex
		for (int i = 0; i < num_of_vertex; i++) { //traverse the adjacency list
			if (adjacency_list[i].get_head()->data.data == vertex) { //if the vertex is found
				return adjacency_list[i].get_head()->data.y; //return the y coordinate of the vertex
			}
		}
		return -1; //if the vertex is not found, return -1
	}

	Graph_Node get_vertex(int x, int y) { //function to get a vertex with the given x and y coordinates
		for (int i = 0; i < num_of_vertex; i++) { //traverse the adjacency list
			if (adjacency_list[i].get_head()->data.x == x && adjacency_list[i].get_head()->data.y == y) { //if the vertex is found
				return adjacency_list[i].get_head()->data; //return the vertex
			}
		}
		return Graph_Node(); //if the vertex is not found, return an empty vertex
	}

	void display_grid() { //function to display the grid
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				int x = i;
				int y = j;

				//get the head of the adjacency linked list of the vertex with the given x and y coordinates
				Linked_List_Node* temp = adjacency_list[y * 10 + x].get_head();

				if (temp == NULL) { //if the head is NULL
					cout << "  ";
				}

				else { //if the head is not NULL
					if (temp->data.data == "C") { //if the character is C, display it in blue color
						cout << BLUE << temp->data.data << RESET << "   ";
					}

					else if (temp->data.data == "S" || temp->data.data == "E") { //if the character is S or E, display it in red color
						cout << RED << temp->data.data << RESET << "   ";
					}

					else if (temp->data.data == "#") { //if the character is #, display it in yellow color
						cout << YELLOW << temp->data.data << RESET << "   ";
					}

					else if (temp->data.data == "+") { //if the character is +, display it in cyan color
						cout << CYAN << temp->data.data << RESET << "   ";
					}

					else { //if the character is * or empty, display it in magenta color
						cout << MAGENTA << temp->data.data << RESET << "   ";
					}
				}

				if (j != 9) { //if the column is not the last column
					string right = to_string(x) + to_string(y + 1); // Convert int to string for right neighbor vertex
					temp = adjacency_list[x * 10 + y].get_head()->next; //get the next node of the head

					while (temp) { //traverse the adjacency linked list
						if (temp->data.data == right) { //if the right neighbor is found
							cout << "  ";
							break; //break the loop
						}
						temp = temp->next; //set the temporary node to the next node
					}
				}
			}

			cout << endl;

			if (i != 9) { //if the row is not the last row
				for (int j = 0; j < 10; j++) { //traverse the adjacency list
					string bottom = to_string(i + 1) + to_string(j); // Convert int to string for bottom neighbor vertex
					Linked_List_Node* temp = adjacency_list[i * 10 + j].get_head(); //get the head of the adjacency linked list

					if (temp == NULL) { //if the head is NULL
						cout << " ";
					}

					else { //if the head is not NULL
						while (temp) { //traverse the adjacency linked list
							if (temp->data.data == bottom) { //if the bottom neighbor is found
								cout << " ";
								break; //break the loop
							}
							temp = temp->next; //set the temporary node to the next node
						}
					}
					cout << "  ";
				}
			}
			cout << endl;
		}
	}

	int* move(char input) { //function to move the car
		int a[2] = { 0,-1 }; //a[0] is for checking if the car has reached the end, a[1] is for checking if the car has moved

		int C_x = get_vertex_cordinates_x("C"); //get the x coordinate of the car
		//cout << C_x << endl;

		int C_y = get_vertex_cordinates_y("C"); //get the y coordinate of the car
		//cout << C_y << endl;

		if (input == 'w' || input == 72) { //if the input is w or up arrow
			if (C_y == 0) { //if the car is in the first row
				cout << "Can't move up" << endl;
				a[1] = 0; //move is invalid
			}

			else { //if the car is not in the first row
				if (C_x == start_x && C_y == start_y) { //if the car is at the start position
					update_vertex(C_x, C_y, "S"); //update the vertex to S
					update_weight(C_x, C_y, 0.0f); //update the weight of the vertex to 0
				}

				else { //if the car is not at the start position
					update_vertex(C_x, C_y, "*"); //update the vertex to *
					update_weight(C_x, C_y, 1.0f); //update the weight of the vertex to 1
				}

				string data = adjacency_list[C_x * 10 + (C_y - 1)].get_head()->data.data; //get the data of the vertex above the car

				if (data == "+") { //if the vertex above the car is a powerup
					if (score < 0) { //if the score is less than 0
						score = 10; //set the score to 10
					}
					else { //if the score is not less than 0
						score *= 2; //double the score
					}
				}

				else if (data == "#") { //if the vertex above the car is an obstacle
					cout << "You hit an obstacle" << endl;
					Sleep(250); //pause the program for 250 milliseconds

					score -= 5; //decrement the score by 5
				}

				update_vertex(C_x, C_y - 1, "C"); //update the vertex above the car to C
				update_weight(C_x, C_y - 1, 0.0f); //update the weight of the vertex above the car to 0

				a[1] = 1; //move is valid

				if (data == "E") { //if the vertex above the car is the end position
					a[0] = 1; //car has reached the end and the game is over
				}
			}
		}

		else if (input == 's' || input == 80) { //if the input is s or down arrow
			if (C_y == 9) { //if the car is in the last row
				cout << "Can't move down" << endl;
				a[1] = 0; //move is invalid
			}

			else { //if the car is not in the last row
				if (C_x == start_x && C_y == start_y) { //if the car is at the start position
					update_vertex(C_x, C_y, "S"); //update the vertex to S
					update_weight(C_x, C_y, 0.0f); //update the weight of the vertex to 0
				}

				else { //if the car is not at the start position
					update_vertex(C_x, C_y, "*"); //update the vertex to *
					update_weight(C_x, C_y, 1.0f); //update the weight of the vertex to 1
				}

				string data = adjacency_list[C_x * 10 + (C_y + 1)].get_head()->data.data; //get the data of the vertex below the car

				if (data == "+") { //if the vertex below the car is a powerup
					if (score < 0) { //if the score is less than 0
						score = 10; //set the score to 10
					}
					else { //if the score is not less than 0
						score *= 2; //double the score
					}
				}

				else if (data == "#") { //if the vertex below the car is an obstacle
					cout << "You hit an obstacle" << endl;
					Sleep(250); //pause the program for 250 milliseconds

					score -= 5; //decrement the score by 5
				}

				update_vertex(C_x, C_y + 1, "C"); //update the vertex below the car to C
				update_weight(C_x, C_y + 1, 0.0f); //update the weight of the vertex below the car to 0

				a[1] = 1; //move is valid

				if (data == "E") { //if the vertex below the car is the end position
					a[0] = 1; //car has reached the end and the game is over
				}
			}
		}

		else if (input == 'd' || input == 77) { //if the input is d or right arrow
			if (C_x == 9) { //if the car is in the last column
				cout << "Can't move right" << endl;
				a[1] = 0; //move is invalid
			}

			else { //if the car is not in the last column
				if (C_x == start_x && C_y == start_y) { //if the car is at the start position
					update_vertex(C_x, C_y, "S"); //update the vertex to S
					update_weight(C_x, C_y, 0.0f); //update the weight of the vertex to 0
				}

				else { //if the car is not at the start position
					update_vertex(C_x, C_y, "*"); //update the vertex to *
					update_weight(C_x, C_y, 1.0f); //update the weight of the vertex to 1
				}

				string data = adjacency_list[(C_x + 1) * 10 + C_y].get_head()->data.data; //get the data of the vertex to the right of the car

				if (data == "+") { //if the vertex to the right of the car is a powerup
					if (score < 0) { //if the score is less than 0
						score = 10; //set the score to 10
					}
					else {
						score *= 2; //double the score
					}
				}

				else if (data == "#") { //if the vertex to the right of the car is an obstacle
					cout << "You hit an obstacle" << endl;
					Sleep(250); //pause the program for 250 milliseconds

					score -= 5; //decrement the score by 5
				}

				update_vertex(C_x + 1, C_y, "C"); //update the vertex to the right of the car to C
				update_weight(C_x + 1, C_y, 0.0f); //update the weight of the vertex to the right of the car to 0

				a[1] = 1; //move is valid

				if (data == "E") { //if the vertex to the right of the car is the end position
					a[0] = 1; //car has reached the end and the game is over
				}
			}
		}

		else if (input == 'a' || input == 75) { //if the input is a or left arrow
			if (C_x == 0) { //if the car is in the first column
				cout << "Can't move left" << endl;
				a[1] = 0; //move is invalid
			}

			else { //if the car is not in the first column
				if (C_x == start_x && C_y == start_y) { //if the car is at the start position
					update_vertex(C_x, C_y, "S"); //update the vertex to S
					update_weight(C_x, C_y, 0.0f); //update the weight of the vertex to 0
				}

				else { //if the car is not at the start position
					update_vertex(C_x, C_y, "*"); //update the vertex to *
					update_weight(C_x, C_y, 1.0f); //update the weight of the vertex to 1
				}

				string data = adjacency_list[(C_x - 1) * 10 + C_y].get_head()->data.data; //get the data of the vertex to the left of the car

				if (data == "+") { //if the vertex to the left of the car is a powerup
					if (score < 0) { //if the score is less than 0
						score = 10; //set the score to 10
					}
					else { //if the score is not less than 0
						score *= 2; //double the score
					}
				}

				else if (data == "#") { //if the vertex to the left of the car is an obstacle
					cout << "You hit an obstacle" << endl;
					Sleep(250); //pause the program for 250 milliseconds

					score -= 5; //decrement the score by 5
				}

				update_vertex(C_x - 1, C_y, "C"); //update the vertex to the left of the car to C
				update_weight(C_x - 1, C_y, 0.0f); //update the weight of the vertex to the left of the car to 0

				a[1] = 1; //move is valid

				if (data == "E") { //if the vertex to the left of the car is the end position
					a[0] = 1; //car has reached the end and the game is over
				}
			}
		}

		/*else if (input != 'w' && input != 72 && input != 's' && input != 80 && input != 'd' && input != 77 && input != 'a' && input != 75) {
			cout << "Invalid input" << endl;
			a[1] = 0;
		}*/

		return a; //return the array
	}

	void generate_start() { //function to generate the start position
		int x = -1, y = -1; //x and y coordinates of the start position
		int count = 0; //counter to check if the start position has been generated

		srand(time(0)); //seed the random number generator with the current time

		while (count < 1) { //generate the start position till the counter is less than 1
			x = rand() % 10; //generate a random number between 0 and 9
			//cout << "X: " << x << endl;

			y = rand() % 10; //generate a random number between 0 and 9
			//cout << "Y: " << y << endl;

			//check if the coordinates are already in the queue or there is C, S, or E on that coordinate
			if (get_vertex(x, y).data != "C" && get_vertex(x, y).data != "S" && get_vertex(x, y).data != "E" && get_vertex(x, y).data != "#") {
				update_vertex(x, y, "C"); //update the vertex to C
				update_weight(x, y, 0.0f); //update the weight of the vertex to 0

				start_x = x; //set the x coordinate of the start position to x
				start_y = y; //set the y coordinate of the start position to y

				count++; //increment the counter
			}
		}
	}

	void generate_end() { //function to generate the end position
		int x = -1, y = -1; //x and y coordinates of the end position
		int count = 0; //counter to check if the end position has been generated

		srand(time(0)); //seed the random number generator with the current time

		while (count < 1) { //generate the end position till the counter is less than 1
			x = rand() % 10; //generate a random number between 0 and 9
			//cout << "X: " << x << endl;

			y = rand() % 10; //generate a random number between 0 and 9
			//cout << "Y: " << y << endl;

			//check if the coordinates are already in the queue or there is C, S, or E on that coordinate
			if (get_vertex(x, y).data != "C" && get_vertex(x, y).data != "S" && get_vertex(x, y).data != "E") {
				update_vertex(x, y, "E"); //update the vertex to E
				update_weight(x, y, 0.0f); //update the weight of the vertex to 0

				end_x = x; //set the x coordinate of the end position to x
				end_y = y; //set the y coordinate of the end position to y

				count++; //increment the counter
			}
		}
	}

	void generate_obstacles(Queue obstacles) { //function to generate 20 x and y coordinates for obstacles
		int x = -1, y = -1; //x and y coordinates of the obstacle
		int count = 0; //counter to check if the obstacle has been generated

		srand(time(0)); //seed the random number generator with the current time

		while (count < 20) { //generate the obstacle till the counter is less than 20
			x = rand() % 10; //generate a random number between 0 and 9
			//cout << "X: " << x << endl;

			y = rand() % 10; //generate a random number between 0 and 9
			//cout << "Y: " << y << endl;

			//check if the coordinates are already in the queue or there is C, S, or E on that coordinate
			if (obstacles.get_size() == 0) { //if the queue is empty
				if (get_vertex(x, y).data != "C" && get_vertex(x, y).data != "S" && get_vertex(x, y).data != "E") {
					update_vertex(x, y, "#"); //update the vertex to #
					update_weight(x, y, 20.0f); //update the weight of the vertex to 20

					obstacles.enqueue(get_vertex(x, y)); //enqueue the vertex in the queue
					count++; //increment the counter
				}
			}

			else { //if the queue is not empty
				Queue_Node* temp = obstacles.get_front(); //create a temporary node and set it to the front of the queue

				while (temp) { //traverse the queue
					if (temp->data.x == x && temp->data.y == y) { //if the coordinates are already in the queue
						break; //break the loop
					}
					temp = temp->next;
				}

				if (temp == NULL) { //if the coordinates are not in the queue
					//check if there is C, S, or E on that coordinate
					if (get_vertex(x, y).data != "C" && get_vertex(x, y).data != "S" && get_vertex(x, y).data != "E") {
						update_vertex(x, y, "#"); //update the vertex to #
						update_weight(x, y, 20.0f); //update the weight of the vertex to 20

						obstacles.enqueue(get_vertex(x, y)); //enqueue the vertex in the queue
						count++; //increment the counter
					}
				}
			}
		}
	}

	void dequeue_obstacles(Queue obstacles) { //function to dequeue the obstacles
		while (obstacles.get_size() != 0) { //dequeue the obstacles till the queue is empty
			Queue_Node* temp = obstacles.dequeue(); //dequeue the obstacle
			delete temp; //delete the obstacle
		}
	}

	void generate_powerups(Queue powerups) { //function to generate 20 x and y coordinates for powerups
		int x = -1, y = -1; //x and y coordinates of the powerup
		int count = 0; //counter to check if the powerup has been generated

		srand(time(0)); //seed the random number generator with the current time

		while (count < 20) { //generate the powerup till the counter is less than 20
			x = rand() % 10; //generate a random number between 0 and 9
			//cout << "X: " << x << endl;

			y = rand() % 10; //generate a random number between 0 and 9
			//cout << "Y: " << y << endl;

			//check if the coordinates are already in the queue or there is C, S, or E on that coordinate
			if (powerups.get_size() == 0) { //if the queue is empty
				if (get_vertex(x, y).data != "C" && get_vertex(x, y).data != "S" && get_vertex(x, y).data != "E" && get_vertex(x, y).data != "#") {
					update_vertex(x, y, "+"); //update the vertex to +
					update_weight(x, y, -5.0f); //update the weight of the vertex to -5

					powerups.enqueue(get_vertex(x, y)); //enqueue the vertex in the queue
					count++; //increment the counter
				}
			}

			else { //if the queue is not empty
				Queue_Node* temp = powerups.get_front(); //create a temporary node and set it to the front of the queue

				while (temp) { //traverse the queue
					if (temp->data.x == x && temp->data.y == y) { //if the coordinates are already in the queue
						break; //break the loop
					}
					temp = temp->next;
				}

				if (temp == NULL) { //if the coordinates are not in the queue
					//check if there is C, S, or E on that coordinate
					if (get_vertex(x, y).data != "C" && get_vertex(x, y).data != "S" && get_vertex(x, y).data != "E" && get_vertex(x, y).data != "#") {
						update_vertex(x, y, "+"); //update the vertex to +
						update_weight(x, y, -5.0f); //update the weight of the vertex to -5

						powerups.enqueue(get_vertex(x, y)); //enqueue the vertex in the queue
						count++; //increment the counter
					}
				}
			}
		}
	}

	void dequeue_powerups(Queue powerups) { //function to dequeue the powerups
		while (powerups.get_size() != 0) { //dequeue the powerups till the queue is empty
			Queue_Node* temp = powerups.dequeue(); //dequeue the powerup
			delete temp; //delete the powerup
		}
	}

	void Dijkstra(int s_x, int s_y, int e_x, int e_y) { //function to find the shortest path from the start position to the end position
		Queue priority_queue; //create a priority queue

		//create arrays for distance and initialized them to 1000
		float* distance = new float[num_of_vertex];
		for (int i = 0; i < num_of_vertex; i++) {
			distance[i] = 1000.0f;
		}

		//create arrays for visited and initialized them to false
		bool* visited = new bool[num_of_vertex];
		for (int i = 0; i < num_of_vertex; i++) {
			visited[i] = false;
		}

		//create arrays for parent and initialized them to -1
		int* parent = new int[num_of_vertex];
		for (int i = 0; i < num_of_vertex; i++) {
			parent[i] = -1;
		}

		//create arrays for path and initialized them to empty string
		string* path = new string[num_of_vertex];
		for (int i = 0; i < num_of_vertex; i++) {
			path[i] = "";
		}

		//create arrays for cost and initialized them to 0
		float* cost = new float[num_of_vertex];
		for (int i = 0; i < num_of_vertex; i++) {
			cost[i] = 0.0f;
		}

		distance[s_x * 10 + s_y] = 0.0f; //set the distance of the start position to 0
		visited[s_x * 10 + s_y] = true; //set the visited of the start position to true
		path[s_x * 10 + s_y] = get_vertex(s_x, s_y).data; //set the path of the start position to the data of the start position
		cost[s_x * 10 + s_y] = 0.0f; //set the cost of the start position to 0

		priority_queue.enqueue(get_vertex(s_x, s_y)); //enqueue the start position in the priority queue

		while (!priority_queue.is_empty()) { //while the priority queue is not empty
			Queue_Node* temp = priority_queue.dequeue(); //dequeue the vertex at the front of the priority queue

			if (temp->data.y != 0 && get_vertex(temp->data.x, temp->data.y - 1).data != "#") { //if the vertex above the vertex at the front of the priority queue is not an obstacle
				//if the vertex above the vertex at the front of the priority queue is visited
				if (visited[(temp->data.x) * 10 + (temp->data.y - 1)] == true) {
					//if the distance of the vertex above the vertex at the front of the priority queue is greater than the distance of the vertex at the front of the priority queue plus 1
					if (distance[(temp->data.x) * 10 + (temp->data.y - 1)] > distance[(temp->data.x) * 10 + (temp->data.y)] + 1) {
						distance[(temp->data.x) * 10 + (temp->data.y - 1)] = distance[(temp->data.x) * 10 + (temp->data.y)] + 1;
						parent[(temp->data.x) * 10 + (temp->data.y - 1)] = (temp->data.x) * 10 + (temp->data.y);
						path[(temp->data.x) * 10 + (temp->data.y - 1)] = path[(temp->data.x) * 10 + (temp->data.y)] + " " + get_vertex(temp->data.x, temp->data.y - 1).data;
						cost[(temp->data.x) * 10 + (temp->data.y - 1)] = cost[(temp->data.x) * 10 + (temp->data.y)] + get_vertex(temp->data.x, temp->data.y - 1).weight;
					}
				}

				//if the vertex above the vertex at the front of the priority queue is not visited
				else if (visited[(temp->data.x) * 10 + (temp->data.y - 1)] == false) {
					priority_queue.enqueue(get_vertex(temp->data.x, temp->data.y - 1));

					distance[(temp->data.x) * 10 + (temp->data.y - 1)] = distance[(temp->data.x) * 10 + (temp->data.y)] + 1;
					visited[(temp->data.x) * 10 + (temp->data.y - 1)] = true;
					parent[(temp->data.x) * 10 + (temp->data.y - 1)] = (temp->data.x) * 10 + (temp->data.y);
					path[(temp->data.x) * 10 + (temp->data.y - 1)] = path[(temp->data.x) * 10 + (temp->data.y)] + " " + get_vertex(temp->data.x, temp->data.y - 1).data;
					cost[(temp->data.x) * 10 + (temp->data.y - 1)] = cost[(temp->data.x) * 10 + (temp->data.y)] + get_vertex(temp->data.x, temp->data.y - 1).weight;
				}
			}

			if (temp->data.x != 9 && get_vertex(temp->data.x + 1, temp->data.y).data != "#") { //if the vertex to the right of the vertex at the front of the priority queue is not an obstacle
				//if the vertex to the right of the vertex at the front of the priority queue is visited
				if (visited[(temp->data.x + 1) * 10 + (temp->data.y)] == true) {
					//if the distance of the vertex to the right of the vertex at the front of the priority queue is greater than the distance of the vertex at the front of the priority queue plus 1
					if (distance[(temp->data.x + 1) * 10 + (temp->data.y)] > distance[(temp->data.x) * 10 + (temp->data.y)] + 1) {
						distance[(temp->data.x + 1) * 10 + (temp->data.y)] = distance[(temp->data.x) * 10 + (temp->data.y)] + 1;
						parent[(temp->data.x + 1) * 10 + (temp->data.y)] = (temp->data.x) * 10 + (temp->data.y);
						path[(temp->data.x + 1) * 10 + (temp->data.y)] = path[(temp->data.x) * 10 + (temp->data.y)] + " " + get_vertex(temp->data.x + 1, temp->data.y).data;
						cost[(temp->data.x + 1) * 10 + (temp->data.y)] = cost[(temp->data.x) * 10 + (temp->data.y)] + get_vertex(temp->data.x + 1, temp->data.y).weight;
					}
				}

				//if the vertex above the vertex at the front of the priority queue is not visited
				else if (visited[(temp->data.x + 1) * 10 + (temp->data.y)] == false) {
					priority_queue.enqueue(get_vertex(temp->data.x + 1, temp->data.y));

					distance[(temp->data.x + 1) * 10 + (temp->data.y)] = distance[(temp->data.x) * 10 + (temp->data.y)] + 1;
					visited[(temp->data.x + 1) * 10 + (temp->data.y)] = true;
					parent[(temp->data.x + 1) * 10 + (temp->data.y)] = (temp->data.x) * 10 + (temp->data.y);
					path[(temp->data.x + 1) * 10 + (temp->data.y)] = path[(temp->data.x) * 10 + (temp->data.y)] + " " + get_vertex(temp->data.x + 1, temp->data.y).data;
					cost[(temp->data.x + 1) * 10 + (temp->data.y)] = cost[(temp->data.x) * 10 + (temp->data.y)] + get_vertex(temp->data.x + 1, temp->data.y).weight;
				}
			}

			if (temp->data.x != 0 && get_vertex(temp->data.x - 1, temp->data.y).data != "#") { //if the vertex to the left of the vertex at the front of the priority queue is not an obstacle
				//if the vertex to the left of the vertex at the front of the priority queue is visited
				if (visited[(temp->data.x - 1) * 10 + (temp->data.y)] == true) {
					//if the distance of the vertex to the left of the vertex at the front of the priority queue is greater than the distance of the vertex at the front of the priority queue plus 1
					if (distance[(temp->data.x - 1) * 10 + (temp->data.y)] > distance[(temp->data.x) * 10 + (temp->data.y)] + 1) {
						distance[(temp->data.x - 1) * 10 + (temp->data.y)] = distance[(temp->data.x) * 10 + (temp->data.y)] + 1;
						parent[(temp->data.x - 1) * 10 + (temp->data.y)] = (temp->data.x) * 10 + (temp->data.y);
						path[(temp->data.x - 1) * 10 + (temp->data.y)] = path[(temp->data.x) * 10 + (temp->data.y)] + " " + get_vertex(temp->data.x - 1, temp->data.y).data;
						cost[(temp->data.x - 1) * 10 + (temp->data.y)] = cost[(temp->data.x) * 10 + (temp->data.y)] + get_vertex(temp->data.x - 1, temp->data.y).weight;
					}
				}

				//if the vertex above the vertex at the front of the priority queue is not visited
				else if (visited[(temp->data.x - 1) * 10 + (temp->data.y)] == false) {
					priority_queue.enqueue(get_vertex(temp->data.x - 1, temp->data.y));

					distance[(temp->data.x - 1) * 10 + (temp->data.y)] = distance[(temp->data.x) * 10 + (temp->data.y)] + 1;
					visited[(temp->data.x - 1) * 10 + (temp->data.y)] = true;
					parent[(temp->data.x - 1) * 10 + (temp->data.y)] = (temp->data.x) * 10 + (temp->data.y);
					path[(temp->data.x - 1) * 10 + (temp->data.y)] = path[(temp->data.x) * 10 + (temp->data.y)] + " " + get_vertex(temp->data.x - 1, temp->data.y).data;
					cost[(temp->data.x - 1) * 10 + (temp->data.y)] = cost[(temp->data.x) * 10 + (temp->data.y)] + get_vertex(temp->data.x - 1, temp->data.y).weight;
				}
			}

			if (temp->data.y != 9 && get_vertex(temp->data.x, temp->data.y + 1).data != "#") { //if the vertex below the vertex at the front of the priority queue is not an obstacle
				//if the vertex below the vertex at the front of the priority queue is visited
				if (visited[(temp->data.x) * 10 + (temp->data.y + 1)] == true) {
					//if the distance of the vertex below the vertex at the front of the priority queue is greater than the distance of the vertex at the front of the priority queue plus 1
					if (distance[(temp->data.x) * 10 + (temp->data.y + 1)] > distance[(temp->data.x) * 10 + (temp->data.y)] + 1) {
						distance[(temp->data.x) * 10 + (temp->data.y + 1)] = distance[(temp->data.x) * 10 + (temp->data.y)] + 1;
						parent[(temp->data.x) * 10 + (temp->data.y + 1)] = (temp->data.x) * 10 + (temp->data.y);
						path[(temp->data.x) * 10 + (temp->data.y + 1)] = path[(temp->data.x) * 10 + (temp->data.y)] + " " + get_vertex(temp->data.x, temp->data.y + 1).data;
						cost[(temp->data.x) * 10 + (temp->data.y + 1)] = cost[(temp->data.x) * 10 + (temp->data.y)] + get_vertex(temp->data.x, temp->data.y + 1).weight;
					}
				}

				//if the vertex above the vertex at the front of the priority queue is not visited
				else if (visited[(temp->data.x) * 10 + (temp->data.y + 1)] == false) {
					priority_queue.enqueue(get_vertex(temp->data.x, temp->data.y + 1));

					distance[(temp->data.x) * 10 + (temp->data.y + 1)] = distance[(temp->data.x) * 10 + (temp->data.y)] + 1;
					visited[(temp->data.x) * 10 + (temp->data.y + 1)] = true;
					parent[(temp->data.x) * 10 + (temp->data.y + 1)] = (temp->data.x) * 10 + (temp->data.y);
					path[(temp->data.x) * 10 + (temp->data.y + 1)] = path[(temp->data.x) * 10 + (temp->data.y)] + " " + get_vertex(temp->data.x, temp->data.y + 1).data;
					cost[(temp->data.x) * 10 + (temp->data.y + 1)] = cost[(temp->data.x) * 10 + (temp->data.y)] + get_vertex(temp->data.x, temp->data.y + 1).weight;
				}
			}

			delete temp; //delete the vertex at the front of the priority queue
		}


		int index = e_x * 10 + e_y; //index of the end position

		while (parent[index] != -1) { //while the parent of the index is not -1
			system("cls"); //clear the screen

			cout << RED << "2D Race Car Game - Automatic Mode" << RESET << endl << endl;

			display_grid(); //display the grid

			update_vertex(index / 10, index % 10, "C"); //update the vertex to C
			index = parent[index]; //set the index to the parent of the index
		}

		system("cls"); //clear the screen

		cout << RED << "2D Race Car Game - Automatic Mode" << RESET << endl << endl;

		display_grid(); //display the grid

		cout << "Total cost: " << cost[e_x * 10 + e_y] << endl; //display the total cost
	}
};

class BST_Node { //class for the nodes of the binary search tree
public: //public access specifier
	string name; //name of the player
	int score; //score of the player

	BST_Node* left; //pointer to the left child
	BST_Node* right; //pointer to the right child

	BST_Node() { //default constructor
		name = "";
		score = 0;
		left = NULL;
		right = NULL;
	}

	BST_Node(string name, int score) { //parameterized constructor
		this->name = name;
		this->score = score;
		left = NULL;
		right = NULL;
	}
};

class BST { //class for the binary search tree
private: //private access specifier
	BST_Node* root; //pointer to the root node

public: //public access specifier
	BST() { //default constructor
		root = NULL;
	}

	void set_root(BST_Node* root) { //function to set the root node
		this->root = root;
	}

	BST_Node* get_root() { //function to get the root node
		return root;
	}

	void insert(string name, int score) { //function to insert a node in the binary search tree
		BST_Node* newNode = new BST_Node(name, score); //create a new node

		if (root == NULL) { //if the tree is empty
			root = newNode;
		}

		else { //if the tree is not empty
			BST_Node* temp = root; //create a temporary node and set it to the root node

			while (temp) { //traverse the tree
				if (name < temp->name) { //if the name is less than the name of the node
					if (temp->left == NULL) { //if the left child of the node is NULL
						temp->left = newNode; //set the left child of the node to the new node
						break; //break the loop
					}
					temp = temp->left; //set the temporary node to the left child of the node
				}

				else if (name > temp->name) { //if the name is greater than the name of the node
					if (temp->right == NULL) { //if the right child of the node is NULL
						temp->right = newNode; //set the right child of the node to the new node
						break; //break the loop
					}
					temp = temp->right; //set the temporary node to the right child of the node
				}

				else { //if the name is equal to the name of the node
					cout << "Name already exists" << endl;
					break; //break the loop
				}
			}
		}
	}

	void display(BST_Node* root) { //function to display the binary search tree
		if (root == NULL) { //if the tree is empty
			return;
		}

		else {	//if the tree is not empty
			display(root->left); //traverse left subtree

			//display the name and score of the node
			cout << RED << "Name: " << GREEN << root->name << RED << "\tScore: " << GREEN << root->score << RESET << endl; 

			display(root->right); //traverse right subtree
		}
	}

	bool searchName(BST_Node* root, const string& name) { //function to search for a name in the binary search tree
		if (root == NULL) { //if the tree is empty
			return false;
		}

		if (name == root->name) { //if the name is equal to the name of the node
			return true;
		}

		else if (name < root->name) { //if the name is less than the name of the node
			return searchName(root->left, name); //search the left subtree
		}

		else { //if the name is greater than the name of the node
			return searchName(root->right, name); //search the right subtree
		}
	}

	bool search(string name) { //function to search for a name in the binary search tree
		return searchName(root, name); //call the searchName function
	}

	int get_score(string name) { //function to get the score of a player
		BST_Node* temp = root; //create a temporary node and set it to the root node

		while (temp) { //traverse the tree
			if (name < temp->name) { //if the name is less than the name of the node
				temp = temp->left; //set the temporary node to the left child of the node
			}

			else if (name > temp->name) { //if the name is greater than the name of the node
				temp = temp->right; //set the temporary node to the right child of the node
			}

			else { //if the name is equal to the name of the node
				return temp->score; //return the score of the node
			}
		}
		return -1; //return -1 if the name is not found
	}

	void update_score(string name, int score) { //function to update the score of a player
		BST_Node* temp = root; //create a temporary node and set it to the root node

		while (temp) { //traverse the tree
			if (name < temp->name) { //if the name is less than the name of the node
				temp = temp->left; //set the temporary node to the left child of the node
			}

			else if (name > temp->name) { //if the name is greater than the name of the node
				temp = temp->right; //set the temporary node to the right child of the node
			}

			else { //if the name is equal to the name of the node
				temp->score = score; //update the score of the node
				break; //break the loop
			}
		}
	}

	void write_file(fstream& file, BST_Node* root) { //function to write the binary search tree to a file
		if (root == NULL) { //if the tree is empty
			return;
		}

		else { //if the tree is not empty
			write_file(file, root->left); //traverse left subtree

			file << root->name << "," << root->score << endl; //write the name and score of the node to the file

			write_file(file, root->right); //traverse right subtree
		}
	}
};