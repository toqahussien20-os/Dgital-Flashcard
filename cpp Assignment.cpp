#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <map>

using namespace std;

// FlashCard class
class FlashCard {
public:
    string question;
    string answer;
    string category;
    int score;

    FlashCard(string q, string a, string c, int s = 0)
        : question(q), answer(a), category(c), score(s) {}

    void display() {
        cout << "Category: " << category << "\n";
        cout << "Q: " << question << "\n";
        cout << "A: " << answer << "\n";
        cout << "Score (memory level): " << score << "\n";
    }

    void updateScore(bool correct) {
        if (correct)
            score++;
        else if (score > 0)
            score--;
    }
};

// FlashCardManager class
class FlashCardManager {
private:
    vector<FlashCard> cards;

public:
    void addCard(string q, string a, string c, int s = 0) {
        cards.push_back(FlashCard(q, a, c, s));
        cout << "Flashcard added!\n";
    }

    void viewCards() {
        if (cards.empty()) {
            cout << "No flashcards to show.\n";
            return;
        }

        for (int i = 0; i < cards.size(); i++) {
            cout << "\nCard " << i + 1 << ":\n";
            cards[i].display();
        }
    }

    void saveToFile(string filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "Error saving file.\n";
            return;
        }

        for (FlashCard card : cards) {
            outFile << card.question << "\n";
            outFile << card.answer << "\n";
            outFile << card.category << "\n";
            outFile << card.score << "\n";
        }

        outFile.close();
        cout << "Flashcards saved to " << filename << "\n";
    }

    void loadFromFile(string filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "No saved file found.\n";
            return;
        }

        string q, a, cat, scoreLine;
        cards.clear();
        while (getline(inFile, q) && getline(inFile, a) &&
               getline(inFile, cat) && getline(inFile, scoreLine)) {
            int s = stoi(scoreLine);
            cards.push_back(FlashCard(q, a, cat, s));
        }

        inFile.close();
        cout << "Flashcards loaded from " << filename << "\n";
    }

    void reviewCards(string filterCategory = "") {
        vector<FlashCard*> toReview;

        for (auto& card : cards) {
            if (filterCategory.empty() || card.category == filterCategory) {
                // Lower score → higher chance to be included multiple times
                int frequency = max(1, 3 - card.score); // repeat low-score cards more
                for (int i = 0; i < frequency; i++)
                    toReview.push_back(&card);
            }
        }

        if (toReview.empty()) {
            cout << "No flashcards found in this category.\n";
            return;
        }

        srand(time(0));
        random_shuffle(toReview.begin(), toReview.end());

        int correct = 0, total = 0;

        for (auto* card : toReview) {
            cout << "\n[Category: " << card->category << "]\n";
            cout << "Question: " << card->question << "\n";
            cout << "Enter your answer: ";
            string userAnswer;
            getline(cin, userAnswer);

            total++;
            if (userAnswer == card->answer) {
                cout << "Correct!\n";
                card->updateScore(true);
                correct++;
            } else {
                cout << "Wrong. Correct answer: " << card->answer << "\n";
                card->updateScore(false);
            }
        }

        cout << "\nReview complete. Score: " << correct << "/" << total;
        cout << " (" << (int)((correct / (float)total) * 100) << "% correct)\n";
    }

    void listCategories() {
        map<string, int> categoryMap;
        for (auto& card : cards)
            categoryMap[card.category]++;

        cout << "\nAvailable Categories:\n";
        for (auto& [cat, count] : categoryMap)
            cout << "- " << cat << " (" << count << " cards)\n";
    }
};

// App class
class App {
private:
    FlashCardManager manager;
    string filename = "flashcards.txt";

public:
    void run() {
        int choice;
        do {
            cout << "\n==== Flashcard Menu ====\n";
            cout << "1. Add Flashcard\n";
            cout << "2. View All Flashcards\n";
            cout << "3. Review All Flashcards\n";
            cout << "4. Review By Category\n";
            cout << "5. Show Categories\n";
            cout << "6. Save Flashcards\n";
            cout << "7. Load Flashcards\n";
            cout << "8. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                string q, a, c;
                cout << "Enter question: ";
                getline(cin, q);
                cout << "Enter answer: ";
                getline(cin, a);
                cout << "Enter category (e.g. Math, History): ";
                getline(cin, c);
                manager.addCard(q, a, c);
            } else if (choice == 2) {
                manager.viewCards();
            } else if (choice == 3) {
                manager.reviewCards(); // review all
            } else if (choice == 4) {
                string cat;
                manager.listCategories();
                cout << "Enter category to review: ";
                getline(cin, cat);
                manager.reviewCards(cat);
            } else if (choice == 5) {
                manager.listCategories();
            } else if (choice == 6) {
                manager.saveToFile(filename);
            } else if (choice == 7) {
                manager.loadFromFile(filename);
            } else if (choice == 8) {
                cout << "Goodbye! Study smart.\n";
            } else {
                cout << "Invalid choice.\n";
            }

        } while (choice != 8);
    }
};

// Main function
int main() {
    App myApp;
    myApp.run();
    return 0;
}
