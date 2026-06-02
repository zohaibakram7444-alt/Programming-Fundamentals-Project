#include <iostream>
#include <cstdlib>
#include <ctime>
# include <string>
using namespace std;

int getCompChoice()
{

    return rand() % 3; // computer will chose random numbers between 0 and 2 included both
}
string numToName(int choice)  // i did this cz i wanted to show user his choice
                            //   and i cannot simply show him  number so i have to convert.
{

    if (choice == 0)
    {
        return "Rock";
    }
    else if (choice == 1)
    {
        return "Paper";
    }
    else
    {
        return "Scissors";
    }
}

int detWin(int player, int comp)   // this function determines the winner.
{

    if (player == comp)
    {
        return 0;      // if tie it will return 0
    }

    else if ((player == 0 && comp == 2) || (player == 1 && comp == 0) || (player == 2 && comp == 1))
    {
        return 1;    // if user win it will return 1
    }

    else
    {

        return -1;  // otherwise -1 it can return any int value but i chose -1 cz it is opposite of my winning
                    // return value yk
    }
}

void dispRes(int win, string player, string comp)
{
    cout << "Your choice : " << player << endl;  // as i mentioned above i want to show the choice of user and computer her i show them
    cout << "Computer choice : " << comp << endl; //as i have already converted integer values to strings.

    if (win == 0)
    {
        cout << "It's a tie! " << endl;       // and yeah this function also tells if i have won the round or lost or is it a tie?
    }

    else if (win == 1)
    {
        cout << "You win. " << endl;
    }

    else
    {

        cout << "Computer win." << endl;
    }
}
int main()
{

    srand(time(0));  // used this for seeding the value like after every 0 sec not nano seconds only simple second the value will be seeded 
                    //so that it give diffrent result everytime.
    int pChoice, compChoice, pScore = 0, compScore = 0;
    cout << "=== ROCK PAPER SCISSORS GAME ===" << endl;
    cout << " Toatal rounds = 5 " << endl;

    for (int i = 1; i <= 5; i++)
    {

        cout << "---- Round " << i << " ----" << endl;
        cout << "                              " << endl;
        cout << "Enter your choice : " << endl;
        cout << "0 = Rock " << endl;
        cout << "1 = Paper " << endl;
        cout << "2 = Scissors " << endl;
        cout << "Your choice :";
        cin >> pChoice;

        while ((pChoice < 0 || pChoice > 2) || (cin.fail())) // in this part i want to check both the thing if the choice is within the 
        {                                                    // range or not or if the input is valid here i want the user to enter int 
            if (cin.fail())                                  // value if it enters string or special chracters the program will crash 
            {                                                // so i used built in function cin.fail the compiler already knows the type i
                cin.clear();                                 // should write if i write the string cin.fail becomes true and will enter the loop
            }                                                // now i only want cin.clear() to work when there is some other value then integer one
            cin.ignore(1000, '\n');                         // so as the cin.fail is true now i want it to become false again to work again
                                                                        // for this cin.clear is used it makes this task done and make cin 
            cout << "Invalid input! Please enter 0, 1, or 2." << endl;  // healthy and good to go again and i also used cin.ignore() function
                                                                         // to clear the buffer value like if user write 5a it will clear 
                                                                        // the value after number or after point in case of float.
            cin >> pChoice;
        }
                           
        compChoice = getCompChoice();                        // simple function calls here

        string pChoiceStr = numToName(pChoice);            // first to convert user choice to string
        string compChoiceStr = numToName(compChoice);      // and the computer choice to string 

        int winner = detWin(pChoice, compChoice);

        if (winner == 1)                     // here the score is calculated to determine who won and lost and is it is a tie or not
        {                                    // using return values
            pScore++;
        }

        else if (winner == -1)
        {
            compScore++;
        }

        dispRes(winner, pChoiceStr, compChoiceStr);       // results of round r displayed
    }

    cout << "---RESULTS---" << endl;
    cout << "Your score : " << pScore << endl;
    cout << "Computer score : " << compScore << endl;
    if (pScore > compScore)
    {
        cout << "Congragulations! You won the game. ";         // displaying who won the game 
    }

    else if (pScore < compScore)
    {
        cout << "Computer won. Better luck next time.";
    }

    else if (compScore == pScore)
    {
        cout << "It is a tie!. Try again. ";
    }
}
