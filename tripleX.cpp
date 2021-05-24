#include "tripleX.h"
#include <ctime>

bool tripleX::PlayGameAtDifficulty(int difficulty)
{
    std::cout << "You are a secret agent breaking into a secure server room" << std::endl;
    std::cout << "YOU NEED TO ENTER THE CORRECT CODES TO CONTINUE ..." << difficulty << std::endl;

    const int CodeA = rand() % 2 + difficulty;
    const int CodeB = rand() % 2 + difficulty;
    const int CodeC = rand() % 2 + difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "Enter three numbers to decipher the code\n";
    std::cout << "The code which unlocks the server has numbers that add-up to: " << CodeSum << std::endl;
    std::cout << "The codes multiplied yields " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    std::cout << "You enter " << GuessA << " " << GuessB << " " << GuessC << std::endl;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessProduct == CodeProduct && GuessSum == CodeSum)
    {
        std::cout << "You have won the first round, be aware of the constraints ahead" << std::endl;
        return true;
    } else 
    {
        std::cout << "Try hard the next time" << std::endl;
        return false;
    }

}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool GamePassed = tripleX::PlayGameAtDifficulty(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (GamePassed)
        {
            LevelDifficulty++;
        }

    }

    std::cout << "You have won\n";
    return EXIT_SUCCESS;
}