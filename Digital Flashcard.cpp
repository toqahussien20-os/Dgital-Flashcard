#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <map>
using namespace std;

// FlashCard class
class FlashCard {
private:
    string question;
    string answer;
    int score;

public:
    FlashCard(string q = "", string a = "", int s = 0) : question(q), answer(a), score(s) {}

    void display() const {
        cout << "Q: " << question << endl;
    }

    bool checkAnswer(const string& userAnswer) {
        if (userAnswer == answer) {
            char feedback;
            cout << "Correct! Was this easy to recall? (y/n): ";
            cin >> feedback;
            cin.ignore();
            if (feedback == 'y' || feedback == 'Y') {
                score++;
            } else {
                score = max(score - 1, 0);
            }
            return true;
        } else {
            score = max(score - 1, 0);
            cout << "Incorrect. Correct Answer: " << answer << endl;
            return false;
        }
    }

    string getQuestion() const { return question; }
    string getAnswer() const { return answer; }
    int getScore() const { return score; }

    void saveToFile(ofstream& out) const {
        out << question << '\n' << answer << '\n' << score << '\n';
    }

    void loadFromFile(ifstream& in) {
        getline(in, question);
        getline(in, answer);
        in >> score;
        in.ignore();
    }
};

// FlashCardManager class
class FlashCardManager {
private:
    vector<FlashCard> cards;
    const string filename = "flashcards.txt";

public:
    FlashCardManager() {
        loadCards();
    }

    ~FlashCardManager() {
        saveCards();
    }

    void addCard(const string& q, const string& a) {
        cards.emplace_back(q, a);
    }

    void reviewCards() {
        cout << "--- Review Flashcards ---" << endl;
        vector<FlashCard*> difficult;

        for (auto& card : cards) {
            card.display();
            cout << "Your answer: ";
            string userAnswer;
            getline(cin, userAnswer);
            if (!card.checkAnswer(userAnswer)) {
                difficult.push_back(&card);
            }
        }

        if (!difficult.empty()) {
            cout << "--- Reviewing Difficult Cards ---" << endl;
            for (auto* card : difficult) {
                card->display();
                cout << "Your answer: ";
                string userAnswer;
                getline(cin, userAnswer);
                card->checkAnswer(userAnswer);
            }
        }
    }

    void saveCards() {
        ofstream out(filename);
        if (out.is_open()) {
            out << cards.size() << '\n';
            for (auto& card : cards) {
                card.saveToFile(out);
            }
            out.close();
        }
    }

    void loadCards() {
        ifstream in(filename);
        if (in.is_open()) {
            size_t count;
            in >> count;
            in.ignore();
            cards.clear();
            for (size_t i = 0; i < count; ++i) {
                FlashCard card;
                card.loadFromFile(in);
                cards.push_back(card);
            }
            in.close();
        }
    }
};

// Main function
int main() {
    FlashCardManager manager;
    int choice;
    string q, a;

    do {
        cout << "\n1. Add Flashcard\n2. Review Flashcards\n3. Exit\nChoose: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter question: ";
                getline(cin, q);
                cout << "Enter answer: ";
                getline(cin, a);
                manager.addCard(q, a);
                break;
            case 2:
                manager.reviewCards();
                break;
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 3);

    return 0;
}
