#include <iostream>
#include <random>

const int NUM_HORSES = 5;
const int TRACK_LENGTH = 15;

// Function prototypes
void advance(int horseNum, int* horses);
void printLane(int horseNum, int* horses);
bool isWinner(int horseNum, int* horses);

// Random number generation objects
std::random_device rd;
std::uniform_int_distribution<int> dist(0, 1);

int main()
{
    int horses[NUM_HORSES] = {0, 0, 0, 0, 0};
    bool winnerFound = false;

    std::cout << "=== Welcome to the Horse Race! ===" << std::endl;

    while (!winnerFound)
    {
        // Advance all horses
        for (int i = 0; i < NUM_HORSES; i++)
        {
            advance(i, horses);
        }

        // Print lanes and check for winners
        for (int i = 0; i < NUM_HORSES; i++)
        {
            printLane(i, horses);

            if (isWinner(i, horses))
            {
                std::cout << "Horse " << i << " WINS!!!" << std::endl;
                winnerFound = true;
            }
        }

        std::cout << "Press Enter for another turn";
        std::cin.get();
    }

    return 0;
}

void advance(int horseNum, int* horses)
{
    int coin = dist(rd);  // 0 or 1

    if (coin == 1)
    {
        horses[horseNum]++;
    }
}

void printLane(int horseNum, int* horses)
{
    for (int i = 0; i < TRACK_LENGTH; i++)
    {
        if (i == horses[horseNum])
        {
            std::cout << horseNum;
        }
        else
        {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

bool isWinner(int horseNum, int* horses)
{
    return horses[horseNum] >= TRACK_LENGTH - 1;
}

