using System.IO;
namespace DigitalFlashcardGUI2
{
    public partial class Form1 : Form
    {
        List<Flashcard> flashcards = new List<Flashcard>();


        ScoreManager scoreManager = new ScoreManager();
        ReviewSession reviewSession = new ReviewSession();


        public Form1()
        {
            InitializeComponent();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (lstFlashcards.Items.Count == 0)
            {
                MessageBox.Show("No flashcards available.");
            }
            else
            {
                string allCards = "";

                foreach (var item in lstFlashcards.Items)
                {
                    allCards += item.ToString() + "\n";
                }

                MessageBox.Show(allCards);
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (File.Exists("flashcards.txt"))
            {
                lstFlashcards.Items.Clear();

                string[] lines = File.ReadAllLines("flashcards.txt");

                foreach (string line in lines)
                {
                    lstFlashcards.Items.Add(line);
                }

                MessageBox.Show("Flashcards loaded successfully!");
            }
            else
            {
                MessageBox.Show("File not found.");
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            if (txtQuestion.Text == "" || txtAnswer.Text == "" || txtCategory.Text == "")
            {
                MessageBox.Show("Please fill in all fields.");
                return;
            }

            Flashcard flashcard = new Flashcard(
             txtQuestion.Text,
             txtAnswer.Text,
             txtCategory.Text);

            flashcards.Add(flashcard);
            lstFlashcards.Items.Add(flashcard);

            txtQuestion.Clear();
            txtAnswer.Clear();
            txtCategory.Clear();

            txtQuestion.Focus();
        }

        private void btnLoad_Click(object sender, EventArgs e)
        {


            lstFlashcards.Items.Clear();

            string[] lines = File.ReadAllLines("flashcards.txt");

            foreach (string line in lines)
            {
                lstFlashcards.Items.Add(line);
            }

            MessageBox.Show("Flashcards loaded successfully!");
        }


        private void btnSearch_Click(object sender, EventArgs e)
        {
            string keyword = txtQuestion.Text;

            foreach (var item in lstFlashcards.Items)
            {
                if (item.ToString().Contains(keyword))
                {
                    MessageBox.Show(item.ToString());
                    return;
                }
            }

            MessageBox.Show("Flashcard not found.");
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            if (lstFlashcards.SelectedIndex != -1)
            {
                lstFlashcards.Items.RemoveAt(lstFlashcards.SelectedIndex);
            }
            else
            {
                MessageBox.Show("Select a flashcard first.");
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            StreamWriter writer = new StreamWriter("flashcards.txt");

            foreach (var item in lstFlashcards.Items)
            {
                writer.WriteLine(item.ToString());
            }

            writer.Close();

            MessageBox.Show("Flashcards saved successfully!");
        }

        private void btnHard_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Incorrect. Try again!");
        }


        private void btneasy_Click(object sender, EventArgs e)
        {
            scoreManager.IncreaseScore();
            MessageBox.Show("Score: " + scoreManager.Score);
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            reviewSession.NextCard();
            MessageBox.Show("Current Card: " + reviewSession.CurrentIndex);
        }
    }
}
