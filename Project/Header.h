#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

class Queue_Node {
public:
	Graph_Node data;
	Queue_Node* next;

	Queue_Node(Graph_Node data) {
		this->data = data;
		next = NULL;
	}

	Queue_Node() {
		next = NULL;
	}
};

class Queue {
private:
	Queue_Node* front;
	Queue_Node* rear;
	int size;

public:
	Queue() {
		front = NULL;
		rear = NULL;
		size = 0;
	}

	void enqueue(Graph_Node data) {
		Queue_Node* newNode = new Queue_Node(data);

		if (front == NULL) {
			front = newNode;
			rear = newNode;
		}

		else {
			rear->next = newNode;
			rear = newNode;
		}

		size++;
	}

	Queue_Node* dequeue() {
		Queue_Node* temp = front;

		if (front == NULL) {
			cout << "Queue is empty" << endl;
			//return Queue_Node();
		}

		else if (front == rear) {
			front = NULL;
			rear = NULL;
		}

		else {
			front = front->next;
		}

		size--;
		return temp;
	}

	bool is_empty() {
		if (front == NULL) {
			return true;
		}
		return false;
	}

	void display() {
		Queue_Node* temp = front;

		while (temp) {
			cout << temp->data.data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	int get_size() {
		return size;
	}

	Queue_Node* get_front() {
		return front;
	}

	Queue_Node* get_rear() {
		return rear;
	}
};

class Graph {
private:
	Linked_List* adjacency_list;
	int num_of_vertices, num_of_vertex;
	int start_x, start_y, end_x, end_y; // coordinates of the start and end positions
	int score; // score of the player

public:
	Graph(int num_of_vertices) {
		this->num_of_vertices = num_of_vertices;
		num_of_vertex = 0;
		adjacency_list = new Linked_List[num_of_vertices];

		start_x = -1;
		start_y = -1;
		end_x = -1;
		end_y = -1;

		score = 10;
	}

	void set_score(int score) {
		this->score = score;
	}

	int get_score() {
		return score;
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

	//function that returns a node with the given x and y coordinates
	Graph_Node get_vertex(int x, int y) {
		for (int i = 0; i < num_of_vertex; i++) {
			if (adjacency_list[i].get_head()->data.x == x && adjacency_list[i].get_head()->data.y == y) {
				return adjacency_list[i].get_head()->data;
			}
		}
		return Graph_Node();
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
						cout << BLUE << temp->data.data << RESET << "   ";
					}
					else if (temp->data.data == "S" || temp->data.data == "E") {
						cout << RED << temp->data.data << RESET << "   ";
					}
					else if (temp->data.data == "#") {
						cout << YELLOW << temp->data.data << RESET << "   ";
					}
					else if (temp->data.data == "+") {
						cout << CYAN << temp->data.data << RESET << "   ";
					}
					else {
						cout << MAGENTA << temp->data.data << RESET << "   ";
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

	int* move(char input) {
		int a[2] = { 0,-1 };

		int C_x = get_vertex_cordinates_x("C");
		//cout << C_x << endl;

		int C_y = get_vertex_cordinates_y("C");
		//cout << C_y << endl;

		if (input == 'w' || input == 72) { // 72 is up arrow
			if (C_y == 0) {
				cout << "Can't move up" << endl;
				a[1] = 0;
			}

			else {
				if (C_x == start_x && C_y == start_y) {
					update_vertex(C_x, C_y, "S");
					update_weight(C_x, C_y, 0.0f);
				}

				else {
					update_vertex(C_x, C_y, "*");
					update_weight(C_x, C_y, 1.0f);
				}

				string data = adjacency_list[C_x * 10 + (C_y - 1)].get_head()->data.data;

				if (data == "+") {
					if (score < 0) {
						score = 10;
					}
					else {
						score *= 2;
					}
				}

				else if (data == "#") {
					cout << "You hit an obstacle" << endl;
					Sleep(250);

					score -= 5;
				}

				update_vertex(C_x, C_y - 1, "C");
				update_weight(C_x, C_y - 1, 0.0f);

				a[1] = 1;

				if (data == "E") {
					a[0] = 1;
				}
			}
		}

		else if (input == 's' || input == 80) { // 80 is down arrow
			if (C_y == 9) {
				cout << "Can't move down" << endl;
				a[1] = 0;
			}

			else {
				if (C_x == start_x && C_y == start_y) {
					update_vertex(C_x, C_y, "S");
					update_weight(C_x, C_y, 0.0f);
				}

				else {
					update_vertex(C_x, C_y, "*");
					update_weight(C_x, C_y, 1.0f);
				}

				string data = adjacency_list[C_x * 10 + (C_y + 1)].get_head()->data.data;

				if (data == "+") {
					if (score < 0) {
						score = 10;
					}
					else {
						score *= 2;
					}
				}

				else if (data == "#") {
					cout << "You hit an obstacle" << endl;
					Sleep(250);

					score -= 5;
				}

				update_vertex(C_x, C_y + 1, "C");
				update_weight(C_x, C_y + 1, 0.0f);

				a[1] = 1;

				if (data == "E") {
					a[0] = 1;
				}
			}
		}

		else if (input == 'd' || input == 77) { // 77 is right arrow
			if (C_x == 9) {
				cout << "Can't move right" << endl;
				a[1] = 0;
			}

			else {
				if (C_x == start_x && C_y == start_y) {
					update_vertex(C_x, C_y, "S");
					update_weight(C_x, C_y, 0.0f);
				}

				else {
					update_vertex(C_x, C_y, "*");
					update_weight(C_x, C_y, 1.0f);
				}

				string data = adjacency_list[(C_x + 1) * 10 + C_y].get_head()->data.data;

				if (data == "+") {
					if (score < 0) {
						score = 10;
					}
					else {
						score *= 2;
					}
				}

				else if (data == "#") {
					cout << "You hit an obstacle" << endl;
					Sleep(250);

					score -= 5;
				}

				update_vertex(C_x + 1, C_y, "C");
				update_weight(C_x + 1, C_y, 0.0f);

				a[1] = 1;

				if (data == "E") {
					a[0] = 1;
				}
			}
		}

		else if (input == 'a' || input == 75) { // 75 is left arrow
			if (C_x == 0) {
				cout << "Can't move left" << endl;
				a[1] = 0;
			}

			else {
				if (C_x == start_x && C_y == start_y) {
					update_vertex(C_x, C_y, "S");
					update_weight(C_x, C_y, 0.0f);
				}

				else {
					update_vertex(C_x, C_y, "*");
					update_weight(C_x, C_y, 1.0f);
				}

				string data = adjacency_list[(C_x - 1) * 10 + C_y].get_head()->data.data;

				if (data == "+") {
					if (score < 0) {
						score = 10;
					}
					else {
						score *= 2;
					}
				}

				else if (data == "#") {
					cout << "You hit an obstacle" << endl;
					Sleep(250);

					score -= 5;
				}

				update_vertex(C_x - 1, C_y, "C");
				update_weight(C_x - 1, C_y, 0.0f);

				a[1] = 1;

				if (data == "E") {
					a[0] = 1;
				}
			}
		}

		/*else if (input != 'w' && input != 72 && input != 's' && input != 80 && input != 'd' && input != 77 && input != 'a' && input != 75) {
			cout << "Invalid input" << endl;
			a[1] = 0;
		}*/

		return a;
	}

	void generate_start() {
		int x = -1, y = -1;
		int count = 0;

		srand(time(0));

		while (count < 1) {
			x = rand() % 10;
			//cout << "X: " << x << endl;

			y = rand() % 10;
			//cout << "Y: " << y << endl;

			if (get_vertex(x, y).data != "C" && get_vertex(x, y).data != "S" && get_vertex(x, y).data != "E" && get_vertex(x, y).data != "#") {
				update_vertex(x, y, "C");
				update_weight(x, y, 0.0f);

				start_x = x;
				start_y = y;

				count++;
			}
		}
	}

	void generate_end() {
		int x = -1, y = -1;
		int count = 0;

		srand(time(0));

		while (count < 1) {
			x = rand() % 10;
			//cout << "X: " << x << endl;

			y = rand() % 10;
			//cout << "Y: " << y << endl;

			if (get_vertex(x, y).data != "C" && get_vertex(x, y).data != "S" && get_vertex(x, y).data != "E") {
				update_vertex(x, y, "E");
				update_weight(x, y, 0.0f);

				end_x = x;
				end_y = y;

				count++;
			}
		}
	}

	//generate 20 x and y coordinates for obstacles
	void generate_obstacles(Queue obstacles) {
		int x = -1, y = -1;
		int count = 0;

		srand(time(0));

		while (count < 20) {
			x = rand() % 10;
			//cout << "X: " << x << endl;

			y = rand() % 10;
			//cout << "Y: " << y << endl;

			//check if the coordinates are already in the queue or there is C, S, or E on that coordinate
			if (obstacles.get_size() == 0) {
				if (get_vertex(x, y).data != "C" && get_vertex(x, y).data != "S" && get_vertex(x, y).data != "E") {
					update_vertex(x, y, "#");
					update_weight(x, y, 20.0f);

					obstacles.enqueue(get_vertex(x, y));
					count++;
				}
			}

			else {
				Queue_Node* temp = obstacles.get_front();

				while (temp) {
					if (temp->data.x == x && temp->data.y == y) {
						break;
					}
					temp = temp->next;
				}

				if (temp == NULL) {
					if (get_vertex(x, y).data != "C" && get_vertex(x, y).data != "S" && get_vertex(x, y).data != "E") {
						update_vertex(x, y, "#");
						update_weight(x, y, 20.0f);

						obstacles.enqueue(get_vertex(x, y));
						count++;
					}
				}
			}
		}
	}

	void dequeue_obstacles(Queue obstacles) {
		while (obstacles.get_size() != 0) {
			Queue_Node* temp = obstacles.dequeue();
			delete temp;
		}
	}

	//generate 20 x and y coordinates for powerups
	void generate_powerups(Queue powerups) {
		int x = -1, y = -1;
		int count = 0;

		srand(time(0));

		while (count < 20) {
			x = rand() % 10;
			//cout << "X: " << x << endl;

			y = rand() % 10;
			//cout << "Y: " << y << endl;

			//check if the coordinates are already in the queue or there is C, S, or E on that coordinate
			if (powerups.get_size() == 0) {
				if (get_vertex(x, y).data != "C" && get_vertex(x, y).data != "S" && get_vertex(x, y).data != "E" && get_vertex(x, y).data != "#") {
					update_vertex(x, y, "+");
					update_weight(x, y, -5.0f);

					powerups.enqueue(get_vertex(x, y));
					count++;
				}
			}

			else {
				Queue_Node* temp = powerups.get_front();

				while (temp) {
					if (temp->data.x == x && temp->data.y == y) {
						break;
					}
					temp = temp->next;
				}

				if (temp == NULL) {
					if (get_vertex(x, y).data != "C" && get_vertex(x, y).data != "S" && get_vertex(x, y).data != "E" && get_vertex(x, y).data != "#") {
						update_vertex(x, y, "+");
						update_weight(x, y, -5.0f);

						powerups.enqueue(get_vertex(x, y));
						count++;
					}
				}
			}
		}
	}

	void dequeue_powerups(Queue powerups) {
		while (powerups.get_size() != 0) {
			Queue_Node* temp = powerups.dequeue();
			delete temp;
		}
	}
};