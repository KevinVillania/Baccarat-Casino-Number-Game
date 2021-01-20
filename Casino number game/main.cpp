/*=========================================================
BACCARAT - Casino number game
Third project by KEVIN VILLANIA

Player chooses between two sides either
'banker' or 'player'. After drawing two cards the one
who has the nearest number to 9 wins.

Whenever sum overboards to 9, 1 card will be drawn
from the deck. However if at the first two draw
results a sum of 8 and 9, the dealer won't draw
additional card anymore.

TO-DO: Winner decision code logic, money balance checker.

DONE: Banker and player random card generator.

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


int main(){

    system ("Color 2F"); //CLI color changer
    srand(time(NULL)); //random number initialization

    //variable declaration
    std::string name;
    int money,bet, decision;
    bool logic = true;

    std::cout << "==============================" << std::endl;
    std::cout << "To Start, please enter your card" << std::endl;

    //name input
    std::cout << "Enter your name: ";
    getline(std::cin, name);

    std::cout << "\nGood evening, " << name << std::endl;
    std::cout << "==============================\n\n";
    std::cout << "WELCOME TO VIRTUAL BACCARAT TABLE" << std::endl;
    std::cout << "=================================" << std::endl;

    do{

        std::cout << "1-BANKER \n2- PLAYER \n";
        std::cout << "Choose your bet "; std::cin >> decision;;
        std::cout << "Place your bet, PHP: "; std::cin >> bet;

        //BANKER CARDS
        std::cout << "\n\n==============================\n";
        std::cout << "      =" << " BANKER'S CARD  " << "=\n";
        std::cout << "==============================\n";

        //Random card generator
        struct Number banker;
        banker.num1 = rand() % 10 + 1;
        banker.num2 = rand() % 10 + 1;
        banker.sum = banker.num1 + banker.num2;

        //checks if card is natural win 8 or 9
        if(banker.sum != 9 || banker.sum != 8){

        banker.extraCard = rand() % 10 + 1; //Third and extra card
        banker.sum += banker.extraCard;
        banker.sum = banker.sum % 10;

        //prints banker's card
        printCard1(banker.num1, banker.num2, banker.extraCard, banker.sum);
        }
        else{
        //Natural win 8 or 9 and prints cards
        printCard2(banker.num1, banker.num2, banker.sum);
        }


        //PLAYER CARDS
        std::cout << "\n\n";
        std::cout << "==============================\n";
        std::cout << "      =" << " PLAYER'S CARD" << "  =\n";
        std::cout << "==============================\n";

        //random number generator for 2 cards
        struct Number player;
        player.num1 = rand() % 10 + 1;
        player.num2 = rand() % 10 + 1;
        player.sum = player.num1 + player.num2;

        //checks if 2 cards are natural win 8 or 9
        if(player.sum != 9 || player.sum != 8){

            player.extraCard = rand() % 10 + 1; //Third and extra card
            player.sum += player.extraCard;
            player.sum = player.sum % 10;

        //function to print card of players
        printCard1(player.num1,player.num2,player.extraCard,player.sum);
        }
        else{

        //natural win 8 or 9, print card of player
        printCard2(player.num1, player.num2, player.sum);
        }
    std::cout << "\n\n";


    }while(logic != false);

}

void printCard1(int num1,int num2, int num3, int sum){

    std::cout << "First Card " << num1 << "\n";
    std::cout << "Second Card " << num2 << "\n";
    std::cout << "Extra Card " << num3 << "\n";
    std::cout << "CARD "<< sum << "\n";
}
void printCard2(int num1,int num2, int sum){

    std::cout << "This is a natural win 8/9 \n";
    std::cout << "First Card " << num1 << "\n";
    std::cout << "Second Card " << num2 << "\n";
    std::cout << "CARD " << sum << "\n";
}




