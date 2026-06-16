using System.Collections.Generic;
using System.IO;

namespace DigitalFlashcardGUI2
{
    public class FileManager
    {
        public void SaveToFile(List<Flashcard> flashcards, string fileName)
        {
            StreamWriter writer = new StreamWriter(fileName);

            foreach (Flashcard flashcard in flashcards)
            {
                writer.WriteLine(flashcard.ToString());
            }

            writer.Close();
        }

        public List<string> LoadFromFile(string fileName)
        {
            List<string> flashcards = new List<string>();

            if (File.Exists(fileName))
            {
                string[] lines = File.ReadAllLines(fileName);

                foreach (string line in lines)
                {
                    flashcards.Add(line);
                }
            }

            return flashcards;
        }
    }
}