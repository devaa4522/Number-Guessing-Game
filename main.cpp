#include<iostream>
#include <cstdlib>
#include <ctime>
// #include<random>

int difficulty(){
        while(true){
            std::cout << "Select the difficulty level:\n"
                     "1. Easy (10 tries)\n"
                     "2. Medium (5 tries)\n"
                     "3. Hard (3 tries)\n"
                     "Enter choice: ";

        int choice;
        std::cin >> choice;
        switch(choice){
            case 1: return 10;
            case 2: return 5;
            case 3: return 3;
            default: std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }
}

int get_random(){
    return rand() % 100 + 1;
}

void play(){
    int tries = difficulty();
    int attempts = tries;
    int secretNumber = get_random();
    int guess;
    bool correct = false;

    std::cout<< "\nYou have " << tries << " tries to guess the secret number between 1 and 100.\n\n";

    while(tries > 0){
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        
        tries--;

        if(guess == secretNumber){
            std::cout << "congratulations!, you guessed it in " << attempts - tries << " tries.\n";
            correct = true;
            break;
        }
        std::cout << (guess > secretNumber ? "Higher" : "Lower") << " than the secret number. You have " << tries << " tries left. Your guess was " << guess << ".\n";

    }
    if(!correct){
        std::cout << "You lost. The secret number was " << secretNumber << ".\n";
    }
}
int main(){
    std::srand(static_cast<unsigned>(std::time(nullptr))); 
    std::cout<<"=== Welcome to the Number Guessing Game! ===\n\n";
    char again;
    do{
        play();
        std::cout << "Wanna play again (y/n): ";
        std::cin >> again;
    } while(again == 'y' || again == 'Y');
    return 0;
}
