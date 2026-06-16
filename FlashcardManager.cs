using System.Collections.Generic;

namespace DigitalFlashcardGUI2
{
    public class FlashcardManager
    {
        public List<Flashcard> Flashcards { get; set; }

        public FlashcardManager()
        {
            Flashcards = new List<Flashcard>();
        }

        public void AddFlashcard(Flashcard flashcard)
        {
            Flashcards.Add(flashcard);
        }

        public void RemoveFlashcard(Flashcard flashcard)
        {
            Flashcards.Remove(flashcard);
        }
    }
}