namespace DigitalFlashcardGUI2
{
    public class Flashcard
    {
        public string Question { get; set; }
        public string Answer { get; set; }
        public string Category { get; set; }

        public Flashcard(string question, string answer, string category)
        {
            Question = question;
            Answer = answer;
            Category = category;
        }

        public override string ToString()
        {
            return $"Question: {Question} | Answer: {Answer} | Category: {Category}";
        }
    }
}