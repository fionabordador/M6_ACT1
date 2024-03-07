#include <iostream>
#include <string>
using namespace std;

struct Player {
    string nickname;
    int age;
    double score1;
    double score2;
};

struct Node {
    Player player;
    Node* next;
};

Node* head = nullptr;

void addRecord(const Player& player) {
    Node* newNode = new Node;
    newNode->player = player;
    newNode->next = head;
    head = newNode;
}

void viewRecords() {
    Node* current = head;
    while (current != nullptr) {
        cout << "Nickname: " << current->player.nickname << endl;
        cout << "Age: " << current->player.age << endl;
        cout << "Score 1: " << current->player.score1 << endl;
        cout << "Score 2: " << current->player.score2 << endl;
        cout << "  " << endl;
        current = current->next;
    }
}

void computeAverage() {
    Node* current = head;
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        cout << "Nickname: " << current->player.nickname << endl;
        cout << "Average Score: " << average << endl;
        cout << "  " << endl;
        current = current->next;
    }
}

void showMaxAverage() {
    Node* current = head;
    double maxAverage = -1;
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        if (average > maxAverage) {
            maxAverage = average;
        }
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        if (average == maxAverage) {
            cout << "Nickname: " << current->player.nickname << endl;
            cout << "Average Score: " << average << endl;
            cout << "  " << endl;
        }
        current = current->next;
    }
}

void showMinAverage() {
    Node* current = head;
    double minAverage = 999999;
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        if (average < minAverage) {
            minAverage = average;
        }
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        if (average == minAverage) {
            cout << "Nickname: " << current->player.nickname << endl;
            cout << "Average Score: " << average << endl;
            cout << "  " << endl;
        }
        current = current->next;
    }
}

int main() {
    int choice;
    Player newPlayer;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add a record" << endl;
        cout << "2. View records" << endl;
        cout << "3. Compute average" << endl;
        cout << "4. Show player(s) with maximum average" << endl;
        cout << "5. Show player(s) with minimum average" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter player's nickname: ";
            cin >> newPlayer.nickname;
            cout << "Enter player's age: ";
            cin >> newPlayer.age;
            cout << "Enter player's score 1: ";
            cin >> newPlayer.score1;
            cout << "Enter player's score 2: ";
            cin >> newPlayer.score2;
            addRecord(newPlayer);
            break;
        case 2:
            viewRecords();
            break;
        case 3:
            computeAverage();
            break;
        case 4:
            showMaxAverage();
            break;
        case 5:
            showMinAverage();
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
