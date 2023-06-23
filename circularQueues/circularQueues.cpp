#include <iostream>
using namespace std;

class queue {
	int front, rear, max = 5;
	int queue_array[5];
public:
	queue() {
		front = -1;
		rear = -1;
	}

	void insert() {
		int num;
		cout << "enter a number :";
		cin >> num;
		cout << endl;

		//cek apakah antrian penuh
		if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
			cout << "\nqueue overflow\n";
			return;
		}
		//cek apakah antrian kosong
		if (front == -1) {
			front = 0;
			rear = 0;
		}
		else {
			//jika rear berada di posisi terakhir array, maka kembali ke awal array
			if (rear == max - 1)
				rear = 0;
			else
				rear = rear + 1;
		}
		queue_array[rear] = num;
	}
	void remove() {
		// cek apakah antrian kosong
		if (front == -1) {
			cout << "queues underflow\n";
			return;
		}
		cout << "\nthe element deleted from the queue is:" << queue_array[front] << "\n";

		// cek jika antiran hanya memiliki satu elemen
		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else {
			//jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
			if (front == max - 1)
				front = 0;
			else
				front = front + 1;
		}

	}

	void display() {
		int front_position = front;
		int rear_position = rear;

		//cek apakah antrian kosong
		if (front == -1) {
			cout << "queue is empty\n";
			return;
		}

		cout << "\nelement in the queue are...\n";

		//jika front _position <= rear_position, iterasi dari front hingga rear
		if (front_position <= rear_position) {
			while (front_position <= rear_position) {
				cout << queue_array[front_position] << " ";
				front_position++;
			}
			cout << endl;
		}
		else {
			//jika front _position <= rear_position, iterasi dari front hingga akhir array
			while (front_position <= max - 1) {
				cout << queue_array[front_position] << " ";
				front_position++;
			}

			front_position = 0;

			//iterasi dari awal array hingga rear
			while (front_position <= rear_position) {
				cout << queue_array[front_position] << " ";
			}
		}
	}
};

int main() {
	queue q;
	char  ch;


}
