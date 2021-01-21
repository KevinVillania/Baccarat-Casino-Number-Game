/*=========================================================
BACCARAT - Casino Number Game
Third project by KEVIN VILLANIA
villaniakevin07@gmail.com

Player chooses between two sides either
'banker' or 'player'. After drawing two cards the one
who has the nearest number to 9 wins.

Whenever sum overboards to 9, 1 card will be drawn
from the deck. However if at the first two draw
results a sum of 8 and 9, the dealer won't draw
additional card anymore.

===========================================================*/

#include <iostream>
#include <ctime>
#include <string>

struct Number{

    int num1,num2,sum,extraCard;
};

//function prototype
void printCard1(int num1,int num2, int num3, int sum);
void printCard2(int num1,int num2, int sum);
bool playAgain(char x,int money);
int winnerFunction(int bankerCard, int playerCard); //compares two cards
int declareWinner(int winner, int decision, int bet); //checks if user win or lose


int main(){

    system ("Color 2F"); //CLI color changer
    srand(time(NULL)); //random number initialization

    //variable declaration
    std::string name;
    int bet, decision, winner, prize;
    char play;
    bool logic = true;
    int money = 10000;

    std::cout << "==============================" << std::endl;
    std::cout << "To Start, please enter your card" << std::endl;

    //name input
    std::cout << "Enter your name: ";
    getline(std::cin, name);

    std::cout << "\nGood evening, " << name << std::endl;
    std::cout << "==============================\n\n";
    std::cout << "WELCOME TO VIRTUAL BACCARAT TABLE" << std::endl;
    std::cout << "=================================" << std::endl;

    do{ //main do-while loop

        std::cout << "Current balance, PHP " << money << std::endl;
        std::cout << "1-BANKER \n2- PLAYER \n";
        std::cout << "Choose your bet ";

        //Checks if input is 1 or 2
        while(!(std::cin >> decision)|| (decision < 1 || decision > 2)){
            std::cin.clear();
            std::cout << "\n" << "Choose your bet ";
            std::cout<< "\n" << "1-BANKER \n2-PLAYER \n";
        }

       do{
        //checks if bet is below balance money
        std::cout << "Place your bet, PHP: ";
        std::cin >> bet;
       }while(bet > money);



        //BANKER CARDS
        std::cout << "\n==============================\n";
        std::cout << "      =" << " BANKER'S CARD  " << "=\n";
        std::cout << "==============================\n";

        //Random card generator
        struct Number banker;
        banker.num1 = rand() % 10 + 1;
        banker.num2 = rand() % 10 + 1;
        banker.sum = banker.num1 + banker.num2;
        banker.sum = banker.sum % 10;

        //checks if card is natural win 8 or 9
        if(banker.sum != 9 && banker.sum != 8){

            banker.extraCard = rand() % 10 + 1; //Third and extra card
            banker.sum += banker.extraCard;
            banker.sum = banker.sum % 10; //gets remainder of 3 cards as final card

        //prints banker's card
        printCard1(banker.num1, banker.num2, banker.extraCard, banker.sum);
        }
        else{
        //Natural win 8 or 9 and prints cards
        printCard2(banker.num1, banker.num2, banker.sum);
        }


        //PLAYER CARDS
        std::cout << "\n";
        std::cout << "==============================\n";
        std::cout << "      =" << " PLAYER'S CARD" << "  =\n";
        std::cout << "==============================\n";

        //random number generator for 2 cards
        struct Number player;
        player.num1 = rand() % 10 + 1;
        player.num2 = rand() % 10 + 1;
        player.sum = player.num1 + player.num2;
        player.sum = player.sum % 10;

        //checks if 2 cards are natural win 8 or 9
        if(player.sum != 9 && player.sum != 8){

            player.extraCard = rand() % 10 + 1; //Third and extra card
            player.sum += player.extraCard;
            player.sum = player.sum % 10; //gets remainder of 3 cards as final card

        //function to print card of players
        printCard1(player.num1,player.num2,player.extraCard,player.sum);
        }
        else{

        //natural win 8 or 9, print card of player
        printCard2(player.num1, player.num2, player.sum);
        }

    //declaration of winner
    winner = winnerFunction(banker.sum, player.sum);

    //awards prize for winner, 1:1 for winner;
    prize = declareWinner(winner, decision, bet);
    std::cout<< "PHP " << prize << std::endl;
    money += prize;
    std::cout << "Current Money, PHP " << money << "\n\n";

    //Asks the user if he wants to play again
    std::cout << "PLAY AGAIN? Y/N ";
    std::cin >> play;
    logic = playAgain(play,money);

    }while(logic != false);

}

void printCard1(int num1,int num2, int num3, int sum){

    std::cout << "=======\n";
    std::cout << "|     |\n";
    std::cout << "|  " << sum  << "  |\n";
    std::cout << "|     |\n";
    std::cout << "=======\n";

    std::cout << "First Card " << num1 << "\n";
    std::cout << "Second Card " << num2 << "\n";
    std::cout << "Extra Card " << num3;
    //std::cout << "CARD "<< sum << "\n";
}
void printCard2(int num1,int num2, int sum){

    std::cout << "=======\n";
    std::cout << "|     |\n";
    std::cout << "|  " << sum  << "  |\n";
    std::cout << "|     |\n";
    std::cout << "=======\n";

    std::cout << "This is a natural win 8/9 \n";
    std::cout << "First Card " << num1 << "\n";
    std::cout << "Second Card " << num2;
    //std::cout << "CARD " << sum << "\n";
}

bool playAgain(char x,int money){

    if(money > 0){

        if(x == 'Y' || x == 'y'){

            return true;
        }else if(x == 'N' || x == 'n'){

            std::cout << "THANK YOU FOR PLAYING!";
            return false;
        }
    }else{

        std::cout << "Insufficient fund!";
        return false;
    }

}

int winnerFunction(int bankerCard, int playerCard){
    //function to determine nearest number to 9
    //returns 1,2,3 depending on condiiton met

    std::cout << "\n==================================\n";
    if(bankerCard > playerCard){

        std::cout << "\nBANKER WIN, ";
        return 1;
    }else if( bankerCard < playerCard){

        std::cout << "\nPLAYER WIN, ";
        return 2;

    }else if(bankerCard == playerCard){

        std::cout << "\nDRAW, ";
        return 3;
    }
}
int declareWinner(int winner, int decision, int bet){

    if(winner == decision){

        //win pays the bet
        std::cout << "YOU WIN!\n";
        return bet;
    }if (winner == 3){

        //draw
        std::cout << "Tie Game!" << std::endl;
        return 0;
    }else{

        std::cout << "YOU LOSE!\n";
        bet *= -1;
        return bet;
    }

}




