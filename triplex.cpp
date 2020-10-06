// preprocesspr directive with hash, header file in carrots
#include <iostream>
#include <ctime>

void IntroText(int Difficulty)
{
    // std = standard, scope operator, character output 
    std::cout << std::endl;
    std::cout << "Hello there Stud Magician! Looks like your in a bit of a bind. The safe you locked yourself in is quickly filling with water.\n";
    std::cout << "You will need to enter the correct codes to escape and impress the audience!\n";
    std::cout << "If you fail to crack the codes, you will run out of breath and perish...\n";
    std::cout << "\nAct quickly and crack code " << Difficulty << std::endl;
}

bool PlayGame(int Difficulty)
{
 
    IntroText(Difficulty);
    // int = a number variable
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;
    // the value of sum will be a,b,c added together
    int CodeSum = CodeA + CodeB + CodeC;
    // value of product will be a,b,c multipled
    int CodeProduct = CodeA * CodeB * CodeC;
    // this will end the line, placing the following content on the line below in the output
    std::cout << std::endl;
    std::cout << "+ There are three digits in the code.\n";
    std::cout << "\n+ The digits in the code add-up to equal: " << CodeSum << std::endl;
    std::cout << "\n+ By multiplying the digits in the code, the result would equal: " << CodeProduct << std::endl;
    // will store the guess numbers made by the player
    int GuessA, GuessB, GuessC;
    std::cout << std::endl;
    std::cout << "Please enter the code: ";
    // cin = character unput
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "You have entered the code: " << GuessA << GuessB << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    // == equal to 
    if (GuessProduct == CodeProduct && GuessSum == CodeSum)
    {
        std::cout << std::endl;
        std::cout << "*** You've cracked the code! Keep going, time is running out! ***\n";
        return true;
    }
    else 
    {
        std::cout << "*** Oh No! You've run out of air and died... ***\n";
        std::cout << "*** Fortune has given you another chance, try again ***\n";
        return false;
    }
}

// use int because function returns a number
int main()
{
    srand(time(NULL)); // creates new random numbers depending on time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // loop game until completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clears errors
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "\n *** Congratulations! You've opened all the locks and escaped the safe! ***";
    std::cout << "\n *** The audience loves you! ***";
    return 0;
}