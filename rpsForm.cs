using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Program6_10
{
    public partial class rpsForm : Form
    {
        public rpsForm()
        {
            InitializeComponent();
        }

        //Define and apply values to constants
        const int ROCK = 1;
        const int PAPER = 2;
        const int SCISSORS = 3;

        //define message constants
        const string messageWin = "You win!";
        const string messageLose = "Sorry, you loose.";
        const string messageTie = "It's a tie.";
        const string message2 = "Choose again to keep playing or 'Clear Scores to Start Over'";

        //define and assign values to global variables
        private int winsUser = 0;
        private int winsComputer = 0;

        //If user selects ROCK
        private void rockButton_Click(object sender, EventArgs e)
        {
            //set user choice variable to ROCK and show picture and highlight choice
            int userChoice = ROCK;
            userPictureBox.Image = Properties.Resources.photorock;

            //clear visual highlighting for computer choice
            rockLabel.BackColor = Color.White;
            paperLabel.BackColor = Color.White;
            scissorsLabel.BackColor = Color.White;

            //generate random number and store in variable
            Random randomNumberGenerator = new Random();
            int computerChoice = randomNumberGenerator.Next(1, 4);

            //the go through possible computer choices for use choosing ROCK
            switch (computerChoice)
            {
                //if computer chooses ROCK, tie
                //Fixed bug in the switch statement, an Added 's' would have caused it too 
                //call a null value. e.g. ROCKS instead of the constant int ROCK
                case ROCK:
                    rockLabel.BackColor = Color.PeachPuff;
                    computerPictureBox.Image = Properties.Resources.photorock;
                    break;
                //if computer chooses PAPER, user loses
                //Fixed
                case PAPER:
                    paperLabel.BackColor = Color.PeachPuff;
                    computerPictureBox.Image = Properties.Resources.photopaper;
                    message1Label.Text = messageLose;
                    message2Label.Text = message2;
                    winsComputer += 1;
                    break;
                //if computer chooses SCISSORS, computer wins
                case SCISSORS:
                    scissorsLabel.BackColor = Color.PeachPuff;
                    computerPictureBox.Image = Properties.Resources.photoscissors;
                    message1Label.Text = messageWin;
                    message2Label.Text = message2;
                    winsUser += 1;
                    break;
            }
            //end if

            //if user and computer make the same choice
            if (userChoice == computerChoice)
            {
                message1Label.Text = messageTie;
                message2Label.Text = message2;
            }
            //add winner's points to running total
            userWinsLabel.Text = winsUser.ToString();
            computerWinsLabel.Text = winsComputer.ToString();
        }

        //Else if user selects PAPER
        private void paperButton_Click(object sender, EventArgs e)
        {
            //set user choice variable to PAPER and show picture
            int userChoice = PAPER;
            userPictureBox.Image = Properties.Resources.photopaper;

            //clear visual highlighting on computer choice
            rockLabel.BackColor = Color.White;
            paperLabel.BackColor = Color.White;
            scissorsLabel.BackColor = Color.White;

            //generate random number and store in variable
            Random randomNumberGenerator = new Random();
            int computerChoice = randomNumberGenerator.Next(1, 4);

            //go through possible computer choices for user choosing  PAPER
            switch (computerChoice)
            {
                //if computer chooses ROCK, user wins
                //Fixed
                case ROCK:
                    rockLabel.BackColor = Color.PeachPuff;
                    computerPictureBox.Image = Properties.Resources.photorock;
                    message1Label.Text = messageWin;
                    message2Label.Text = message2;
                    winsUser += 1;
                    break;
                //else if computer chooses PAPER, tie
                //Fixed
                case PAPER:
                    paperLabel.BackColor = Color.PeachPuff;
                    computerPictureBox.Image = Properties.Resources.photopaper;
                    break;
                //else if computer chooses SCISSORS, user loses
                case SCISSORS:
                    scissorsLabel.BackColor = Color.PeachPuff;
                    computerPictureBox.Image = Properties.Resources.photoscissors;
                    message1Label.Text = messageLose;
                    message2Label.Text = message2;
                    scissorsLabel.BackColor = Color.PeachPuff;
                    winsComputer += 1;
                    break;
            }
            //end if

            //if user and computer make the same choice
            if (userChoice == computerChoice)
            {
                message1Label.Text = messageTie;
                message2Label.Text = message2;
            }

            //add winner's points to running total
            userWinsLabel.Text = winsUser.ToString();
            computerWinsLabel.Text = winsComputer.ToString();
        }

        //else if user selects SCISSORS
        private void scissorsButton_Click(object sender, EventArgs e)
        {
            //set user choice variable to SCISSORS and show picture
            int userChoice = SCISSORS;
            userPictureBox.Image = Properties.Resources.photoscissors;

            //clear visual highlighting for computer choice
            rockLabel.BackColor = Color.White;
            paperLabel.BackColor = Color.White;
            scissorsLabel.BackColor = Color.White;

            //genrate random number and store in variable
            Random randomNumberGenerator = new Random();
            int computerChoice = randomNumberGenerator.Next(1, 4);

            //go through possible computer choices for use choosing SCISSORS

            switch (computerChoice)
            {
                //if computer chooses ROCK, user loses
                case ROCK:
                    rockLabel.BackColor = Color.PeachPuff;
                    computerPictureBox.Image = Properties.Resources.photorock;
                    message1Label.Text = messageLose;
                    message2Label.Text = message2;
                    winsComputer += 1;
                    break;
                //if Computer chooses PAPER, user wins
                case PAPER:
                    paperLabel.BackColor = Color.PeachPuff;
                    computerPictureBox.Image = Properties.Resources.photopaper;
                    message1Label.Text = messageWin;
                    message2Label.Text = message2;
                    winsUser += 1;
                    break;
                //if computer chooses SCISSORS, tie
                case SCISSORS:
                    scissorsLabel.BackColor = Color.PeachPuff;
                    computerPictureBox.Image = Properties.Resources.photoscissors;
                    break;
            }
            //end if

            //if user and computer make the same choice
            if (userChoice == computerChoice)
            {
                message1Label.Text = messageTie;
                message2Label.Text = message2;
            }

            //store winner's points in running total
            userWinsLabel.Text = winsUser.ToString();
            computerWinsLabel.Text = winsComputer.ToString();
        }
        //end if

        //Clear running scores, labels and images
        private void playAgainButton_Click(object sender, EventArgs e)
        {
            winsUser = 0;
            winsComputer = 0;
            userWinsLabel.Text = "";
            computerWinsLabel.Text = "";
            computerPictureBox.Image = null;
            userPictureBox.Image = null;
        }

        //Exit game
        private void exitButton_Click(object sender, EventArgs e)
        {
            Close();
        }

    }
}
