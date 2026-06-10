#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
using namespace std;

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
            if (feedback == 'y' || feedback == 'Y') score++;
            else score = max(score - 1, 0);
            return true;
        } else {
            cout << "Incorrect. Correct Answer: " << answer << endl;
            score = max(score - 1, 0);
            return false;
        }
    }

    void saveToFile(ofstream& out) const {
        out << question << '\n' << answer << '\n' << score << '\n';
    }

    void loadFromFile(ifstream& in) {
        getline(in, question);
        getline(in, answer);
        in >> score;
        in.ignore();
    }

    string getQuestion() const { return question; }
    string getAnswer() const { return answer; }
};

class FlashCardManager {
private:
    vector<FlashCard> cards;
    const string filename = "flashcards.txt";

public:
    void addCard(const string& q, const string& a) {
        cards.emplace_back(q, a);
    }

    void deleteCard() {
        if (cards.empty()) {
            cout << "No flashcards to delete.\n";
            return;
        }

        for (size_t i = 0; i < cards.size(); ++i) {
            cout << i + 1 << ". " << cards[i].getQuestion() << endl;
        }

        cout << "Enter the number of the flashcard to delete: ";
        int index;
        cin >> index;
        cin.ignore();

        if (index >= 1 && index <= cards.size()) {
            cards.erase(cards.begin() + index - 1);
            cout << "Flashcard deleted.\n";
        } else {
            cout << "Invalid selection.\n";
        }
    }

    void reviewCards() {
        if (cards.empty()) {
            cout << "No flashcards to review.\n";
            return;
        }

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
            cout << "--- Reviewing Difficult Cards ---\n";
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
            cout << "Flashcards saved.\n";
        } else {
            cout << "Failed to open file.\n";
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
            cout << "Flashcards loaded.\n";
        } else {
            cout << "No saved flashcards found.\n";
        }
    }
};

int main() {
    FlashCardManager manager;
    int choice;
    string q, a;

    do {
        cout << "\n1. Add Flashcard\n";
        cout << "2. Review Cards\n";
        cout << "3. Delete Flashcard\n";
        cout << "4. Save Cards\n";
        cout << "5. Load Cards\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
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
                manager.deleteCard();
                break;
            case 4:
                manager.saveCards();
                break;
            case 5:
                manager.loadCards();
                break;
            case 6:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
