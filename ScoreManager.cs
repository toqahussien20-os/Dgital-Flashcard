namespace DigitalFlashcardGUI2
{
    public class ScoreManager
    {
        public int Score { get; set; }

        public ScoreManager()
        {
            Score = 0;
        }

        public void IncreaseScore()
        {
            Score++;
        }

        public void ResetScore()
        {
            Score = 0;
        }
    }
}