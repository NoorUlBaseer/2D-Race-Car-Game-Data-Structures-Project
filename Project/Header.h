#pragma once
#include <iostream>
#include <string>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
//#define WHITE   "\033[37m"

class Graph_Node {
public:
	string data;
	float weight;
	int x, y;
	Graph_Node* next;

	Graph_Node() {
		data = "";
		weight = 0;
		x = 0;
		y = 0;
		next = NULL;
	}

	Graph_Node(string data, float weight, int x, int y) {
		this->data = data;
		this->weight = weight;
		this->x = x;
		this->y = y;
		next = NULL;
	}
};

class Linked_List_Node {
public:
	Graph_Node data;
	Linked_List_Node* next;

	Linked_List_Node(Graph_Node data) {
		this->data = data;
		this->next = NULL;
	}
};

class Linked_List {
private:
	Linked_List_Node* head;

public:
	Linked_List() {
		this->head = NULL;
	}

	void set_head(Linked_List_Node* head) {
		this->head = head;
	}

	Linked_List_Node* get_head() {
		return this->head;
	}

	void insert(Graph_Node data) {
		Linked_List_Node* newNode = new Linked_List_Node(data);

		if (this->head == nullptr) {
			this->head = newNode;
		}

		else {
			Linked_List_Node* temp = this->head;

			while (temp->next) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	void display() {
		Linked_List_Node* temp = this->head;

		while (temp) {
			cout << temp->data.data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

class Graph {
private:
	Linked_List* adjacency_list;
	int num_of_vertices, num_of_vertex;

public:
	Graph(int num_of_vertices) {
		this->num_of_vertices = num_of_vertices;
		num_of_vertex = 0;
		adjacency_list = new Linked_List[num_of_vertices];
	}

	void add_vertex(string vertex, int x, int y) {
		Graph_Node* newNode = new Graph_Node(vertex, 0, x, y);
		adjacency_list[num_of_vertex].insert(*newNode);
		num_of_vertex++;
	}

	void add_edge(string vertex1, string vertex2, float weight) {
		int index1 = -1, index2 = -1;

		for (int i = 0; i < num_of_vertex; i++) {
			if (adjacency_list[i].get_head()->data.data == vertex1) {
				index1 = i;
			}
			if (adjacency_list[i].get_head()->data.data == vertex2) {
				index2 = i;
			}
		}

		if (index1 == -1 || index2 == -1) {
			cout << "Vertex not found" << endl;
			return;
		}

		Graph_Node* newNode1 = new Graph_Node(vertex2, weight, adjacency_list[index1].get_head()->data.x, adjacency_list[index1].get_head()->data.y);
		Graph_Node* newNode2 = new Graph_Node(vertex1, weight, adjacency_list[index2].get_head()->data.x, adjacency_list[index2].get_head()->data.y);

		adjacency_list[index1].insert(*newNode1);
		adjacency_list[index2].insert(*newNode2);
	}

	void display() {
		for (int i = 0; i < num_of_vertex; i++) {
			adjacency_list[i].display();
		}
	}

	void update_vertex(int x, int y, string new_vertex) {
		// x and y being the x and y coordinates
		for (int i = 0; i < num_of_vertex; i++) {
			if (adjacency_list[i].get_head()->data.x == x && adjacency_list[i].get_head()->data.y == y) {
				adjacency_list[i].get_head()->data.data = new_vertex;
				break;
			}
		}
	}
	
	void update_weight(int x, int y, float new_weight) {
		// x and y being the x and y coordinates
		for (int i = 0; i < num_of_vertex; i++) {
			if (adjacency_list[i].get_head()->data.x == x && adjacency_list[i].get_head()->data.y == y) {
				adjacency_list[i].get_head()->data.weight = new_weight;
				break;
			}
		}
	}

	//get_vertex_cordinates_x("C")
	int get_vertex_cordinates_x(string vertex) {
		for (int i = 0; i < num_of_vertex; i++) {
			if (adjacency_list[i].get_head()->data.data == vertex) {
				return adjacency_list[i].get_head()->data.x;
			}
		}
		return -1;
	}

	//get_vertex_cordinates_y("C")
	int get_vertex_cordinates_y(string vertex) {
		for (int i = 0; i < num_of_vertex; i++) {
			if (adjacency_list[i].get_head()->data.data == vertex) {
				return adjacency_list[i].get_head()->data.y;
			}
		}
		return -1;
	}

	void display_grid() {
		// Display grid in a 10x10 grid

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				int x = i;
				int y = j;
				Linked_List_Node* temp = adjacency_list[y * 10 + x].get_head();

				if (temp == NULL) {
					cout << "  ";
				}
				else {
					//cout << temp->data.data << "  ";
					if (temp->data.data == "C") {
						cout << YELLOW << temp->data.data << RESET << "   ";
					}
					else if (temp->data.data == "S" || temp->data.data == "E") {
						cout << RED << temp->data.data << RESET << "   ";
					}
					else if (temp->data.data == "#") {
						cout << MAGENTA << temp->data.data << RESET << "   ";
					}
					else if (temp->data.data == "X") {
						cout << GREEN << temp->data.data << RESET << "   ";
					}
					else {
						cout << CYAN << temp->data.data << RESET << "   ";
					}
				}

				// Check for right neighbor
				if (j != 9) {
					string right = to_string(x) + to_string(y + 1); // Convert int to string for right neighbor vertex
					temp = adjacency_list[x * 10 + y].get_head()->next;

					while (temp) {
						if (temp->data.data == right) {
							cout << "  ";
							break;
						}
						temp = temp->next;
					}
				}
			}

			cout << endl;

			// Check for bottom neighbor
			if (i != 9) {
				for (int j = 0; j < 10; j++) {
					string bottom = to_string(i + 1) + to_string(j); // Convert int to string for bottom neighbor vertex
					Linked_List_Node* temp = adjacency_list[i * 10 + j].get_head();

					if (temp == NULL) {
						cout << " ";
					}
					else {
						while (temp) {
							if (temp->data.data == bottom) {
								cout << " ";
								break;
							}
							temp = temp->next;
						}
					}
					cout << "  ";
				}
			}
			cout << endl;
		}
	}

	int move(char input) {
		int a = -1;

		int C_x = get_vertex_cordinates_x("C");
		//cout << C_x << endl;

		int C_y = get_vertex_cordinates_y("C");
		//cout << C_y << endl;

		if (input == 'w' || input == 72) { // 72 is up arrow
			if (C_y == 0) {
				cout << "Can't move up" << endl;

				a = 0;
			}

			else {
				update_vertex(C_x, C_y, "*");
				update_vertex(C_x, C_y - 1, "C");

				a = 1;
			}
		}

		else if (input == 's' || input == 80) { // 80 is down arrow
			if (C_y == 9) {
				cout << "Can't move down" << endl;

				a = 0;
			}

			else {
				update_vertex(C_x, C_y, "*");

				if (adjacency_list[C_x * 10 + (C_y + 1)].get_head()->data.data == "E") {
					
				}

				update_vertex(C_x, C_y + 1, "C");

				a = 1;
			}
		}

		else if (input == 'd' || input == 77) { // 77 is right arrow
			if (C_x == 9) {
				cout << "Can't move right" << endl;

				a = 0;
			}

			else {
				update_vertex(C_x, C_y, "*");
				update_vertex(C_x + 1, C_y, "C");

				a = 1;
			}
		}

		else if (input == 'a' || input == 75) { // 75 is left arrow
			if (C_x == 0) {
				cout << "Can't move left" << endl;

				a = 0;
			}

			else {
				update_vertex(C_x, C_y, "*");
				update_vertex(C_x - 1, C_y, "C");

				a = 1;
			}
		}

		else if (input != 'w' && input != 72 && input != 's' && input != 80 && input != 'd' && input != 77 && input != 'a' && input != 75) {
			cout << "Invalid input" << endl;

			a = 0;
		}

		return a;
	}
};