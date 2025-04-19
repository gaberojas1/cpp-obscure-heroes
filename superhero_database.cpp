#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

const int SIZE = 10;

string names[SIZE] = {
    "Squirrel Girl", "Arm-Fall-Off-Boy", "The Tick", "Superman", "Batman",
    "Moon Knight", "Spider-Man", "Venom", "Thor", "Loki"
};

string powers[SIZE] = {
    "Control Squirrels", "Detachable Limbs", "Super Strength", "Flight and Strength", "Genius Intelligence",
    "Lunar Empowerment", "Spider Abilities", "Symbiote Powers", "God of Thunder", "Shapeshifting"
};

string weaknesses[SIZE] = {
    "Time Limits", "Heavy Objects", "Poor Judgment", "Kryptonite", "Human Limitations",
    "Mental Illness", "Responsibility", "Sound and Fire", "Hubris", "Pride"
};

string info[SIZE][2] = {
    {"1992", "Marvel"},
    {"1989", "DC"},
    {"1986", "Other"},
    {"1938", "DC"},
    {"1939", "DC"},
    {"1975", "Marvel"},
    {"1962", "Marvel"},
    {"1984", "Marvel"},
    {"1962", "Marvel"},
    {"1949", "Marvel"}
};

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string toUpper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

void searchByName(string input) {
    string key = toLower(input);
    bool found = false;
    for (int i = 0; i < SIZE; ++i) {
        if (toLower(names[i]).find(key) != string::npos) {
            cout << "Found: " << names[i] << " | " << powers[i] << " | " << weaknesses[i]
                 << " | " << info[i][0] << " | " << info[i][1] << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No superhero found with name containing \"" << input << "\".\n";
}

void searchByPower(string input) {
    string key = toLower(input);
    bool found = false;
    for (int i = 0; i < SIZE; ++i) {
        if (toLower(powers[i]).find(key) != string::npos) {
            cout << "Found: " << names[i] << " | " << powers[i] << " | " << weaknesses[i]
                 << " | " << info[i][0] << " | " << info[i][1] << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No superhero found with power containing \"" << input << "\".\n";
}

void displayAll(bool upper) {
    for (int i = 0; i < SIZE; ++i) {
        string name = upper ? toUpper(names[i]) : toLower(names[i]);
        string power = upper ? toUpper(powers[i]) : toLower(powers[i]);
        string weak = upper ? toUpper(weaknesses[i]) : toLower(weaknesses[i]);
        string year = info[i][0];
        string uni = upper ? toUpper(info[i][1]) : toLower(info[i][1]);

        cout << name << " | " << power << " | " << weak << " | " << year << " | " << uni << endl;
    }
}

void sortAlphabetically() {
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = i + 1; j < SIZE; ++j) {
            if (names[i] > names[j]) {
                swap(names[i], names[j]);
                swap(powers[i], powers[j]);
                swap(weaknesses[i], weaknesses[j]);
                swap(info[i][0], info[j][0]);
                swap(info[i][1], info[j][1]);
            }
        }
    }
    cout << "Superheroes sorted alphabetically.\n";
}

void menu() {
    int choice;
    string input;
    do {
        cout << "\n🦸 Superhero Database Menu\n";
        cout << "1. Search by Name\n";
        cout << "2. Search by Superpower\n";
        cout << "3. Sort Alphabetically\n";
        cout << "4. Display All (Uppercase)\n";
        cout << "5. Display All (Lowercase)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter name to search: ";
            getline(cin, input);
            searchByName(input);
            break;
        case 2:
            cout << "Enter superpower to search: ";
            getline(cin, input);
            searchByPower(input);
            break;
        case 3:
            sortAlphabetically();
            break;
        case 4:
            displayAll(true);
            break;
        case 5:
            displayAll(false);
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}