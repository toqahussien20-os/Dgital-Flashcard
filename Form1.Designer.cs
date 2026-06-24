namespace DigitalFlashcardGUI2
{
    partial class Form1
    {
        
        private System.ComponentModel.IContainer components = null;

    
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

    
        private void InitializeComponent()
        {
            lblQuestion = new Label();
            txtQuestion = new TextBox();
            lblAnswer = new Label();
            Ib1Ctegory = new Label();
            txtAnswer = new TextBox();
            txtCategory = new TextBox();
            btnAdd = new Button();
            btnDisplay = new Button();
            btnSearch = new Button();
            btnSave = new Button();
            btnDelete = new Button();
            btnLoad = new Button();
            lstFlashcards = new ListBox();
            btneasy = new Button();
            btnHard = new Button();
            btnNext = new Button();
            SuspendLayout();
            
            lblQuestion.AutoSize = true;
            lblQuestion.Location = new Point(107, 45);
            lblQuestion.Name = "lblQuestion";
            lblQuestion.Size = new Size(71, 20);
            lblQuestion.TabIndex = 0;
            lblQuestion.Text = "Question:";
        
            txtQuestion.Location = new Point(211, 38);
            txtQuestion.Name = "txtQuestion";
            txtQuestion.Size = new Size(125, 27);
            txtQuestion.TabIndex = 1;
        
            lblAnswer.AutoSize = true;
            lblAnswer.Location = new Point(108, 82);
            lblAnswer.Name = "lblAnswer";
            lblAnswer.Size = new Size(60, 20);
            lblAnswer.TabIndex = 2;
            lblAnswer.Text = "Answer:";
            
            Ib1Ctegory.AutoSize = true;
            Ib1Ctegory.Location = new Point(109, 118);
            Ib1Ctegory.Name = "Ib1Ctegory";
            Ib1Ctegory.Size = new Size(72, 20);
            Ib1Ctegory.TabIndex = 3;
            Ib1Ctegory.Text = "Category:";
            
            txtAnswer.Location = new Point(211, 75);
            txtAnswer.Name = "txtAnswer";
            txtAnswer.Size = new Size(125, 27);
            txtAnswer.TabIndex = 4;
            
            txtCategory.Location = new Point(211, 115);
            txtCategory.Name = "txtCategory";
            txtCategory.Size = new Size(125, 27);
            txtCategory.TabIndex = 5;
            txtCategory.TextChanged += textBox2_TextChanged;
            
            btnAdd.Location = new Point(89, 171);
            btnAdd.Name = "btnAdd";
            btnAdd.Size = new Size(169, 29);
            btnAdd.TabIndex = 6;
            btnAdd.Text = "Add Flashcard";
            btnAdd.UseVisualStyleBackColor = true;
            btnAdd.Click += btnAdd_Click;
            
            btnDisplay.Location = new Point(264, 171);
            btnDisplay.Name = "btnDisplay";
            btnDisplay.Size = new Size(147, 29);
            btnDisplay.TabIndex = 7;
            btnDisplay.Text = "Display All";
            btnDisplay.UseVisualStyleBackColor = true;
            btnDisplay.Click += button2_Click;
            
            btnSearch.Location = new Point(89, 217);
            btnSearch.Name = "btnSearch";
            btnSearch.Size = new Size(169, 29);
            btnSearch.TabIndex = 8;
            btnSearch.Text = "Search";
            btnSearch.UseVisualStyleBackColor = true;
            btnSearch.Click += btnSearch_Click;
            
            btnSave.Location = new Point(89, 270);
            btnSave.Name = "btnSave";
            btnSave.Size = new Size(169, 29);
            btnSave.TabIndex = 9;
            btnSave.Text = "Save File";
            btnSave.UseVisualStyleBackColor = true;
            btnSave.Click += btnSave_Click;
            
            btnDelete.Location = new Point(264, 217);
            btnDelete.Name = "btnDelete";
            btnDelete.Size = new Size(147, 29);
            btnDelete.TabIndex = 10;
            btnDelete.Text = "Delete";
            btnDelete.UseVisualStyleBackColor = true;
            btnDelete.Click += btnDelete_Click;
            
            btnLoad.Location = new Point(264, 270);
            btnLoad.Name = "btnLoad";
            btnLoad.Size = new Size(147, 29);
            btnLoad.TabIndex = 11;
            btnLoad.Text = "Load File";
            btnLoad.UseVisualStyleBackColor = true;
            btnLoad.Click += btnLoad_Click;
            
            lstFlashcards.FormattingEnabled = true;
            lstFlashcards.Location = new Point(109, 330);
            lstFlashcards.Name = "lstFlashcards";
            lstFlashcards.Size = new Size(302, 104);
            lstFlashcards.TabIndex = 12;
        
            btneasy.Location = new Point(620, 88);
            btneasy.Name = "btneasy";
            btneasy.Size = new Size(94, 29);
            btneasy.TabIndex = 13;
            btneasy.Text = "Easy";
            btneasy.UseVisualStyleBackColor = true;
            btneasy.Click += btneasy_Click;
            
            btnHard.Location = new Point(620, 152);
            btnHard.Name = "btnHard";
            btnHard.Size = new Size(94, 29);
            btnHard.TabIndex = 14;
            btnHard.Text = "Hard";
            btnHard.UseVisualStyleBackColor = true;
            btnHard.Click += btnHard_Click;
            
            btnNext.Location = new Point(620, 217);
            btnNext.Name = "btnNext";
            btnNext.Size = new Size(94, 29);
            btnNext.TabIndex = 15;
            btnNext.Text = "Next Card";
            btnNext.UseVisualStyleBackColor = true;
            btnNext.Click += btnNext_Click;
            
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1335, 632);
            Controls.Add(btnNext);
            Controls.Add(btnHard);
            Controls.Add(btneasy);
            Controls.Add(lstFlashcards);
            Controls.Add(btnLoad);
            Controls.Add(btnDelete);
            Controls.Add(btnSave);
            Controls.Add(btnSearch);
            Controls.Add(btnDisplay);
            Controls.Add(btnAdd);
            Controls.Add(txtCategory);
            Controls.Add(txtAnswer);
            Controls.Add(Ib1Ctegory);
            Controls.Add(lblAnswer);
            Controls.Add(txtQuestion);
            Controls.Add(lblQuestion);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label lblQuestion;
        private TextBox txtQuestion;
        private Label lblAnswer;
        private Label Ib1Ctegory;
        private TextBox txtAnswer;
        private TextBox txtCategory;
        private Button btnAdd;
        private Button btnDisplay;
        private Button btnSearch;
        private Button btnSave;
        private Button btnDelete;
        private Button btnLoad;
        private ListBox lstFlashcards;
        private Button btneasy;
        private Button btnHard;
        private Button btnNext;
    }
}
