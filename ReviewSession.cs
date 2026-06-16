namespace DigitalFlashcardGUI2
{
    public class ReviewSession
    {
        public int CurrentIndex { get; set; }

        public ReviewSession()
        {
            CurrentIndex = 0;
        }

        public void NextCard()
        {
            CurrentIndex++;
        }

        public void ResetSession()
        {
            CurrentIndex = 0;
        }
    }
}