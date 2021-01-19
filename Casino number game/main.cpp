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

TO-DO: Main decision code logic. If-else banker-player
select, and decision of winner.

===========================================================*/


#include <iostream>
#include <ctime>
#include <string>

int main(){

    std::string name;
    int money,bet, minimum = 100000;
    bool logic = true;
    int decision;

    std::cout << "==============================" << std::endl;
    std::cout << "To Start, please enter your card" << std::endl;

    //name input
    std::cout << "Enter your name: ";
    getline(std::cin, name);

    std::cout << std::endl;
    std::cout << "Good evening, " << name << std::endl;
    std::cout << std::endl;
    std::cout << "WELCOME TO VIRTUAL BACCARAT TABLE" << std::endl;
    std::cout << "==============================" << std::endl;

    do{
        if(minimum > 1000){

            srand(time(NULL));

            std::cout << "1-BANKER \n2- PLAYER \n";
            std::cout << "Place your bet ";
            std::cin >> decision;
            std::cout << std::endl << rand() % 10 + 1 << std::endl;

        }else{

        std::cout << "Minimum money is PHP 1000, please deposit";
        logic = false;
        break;
        }


    }while(logic != false);

}

int addMoney(int cash){

    int totalCash;
    totalCash += cash;
    return totalCash;
}

