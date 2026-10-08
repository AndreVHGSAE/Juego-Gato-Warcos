// Gato Warcos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

void Instructions();
void DisplayBoard(const std::vector<char>* board);

int MovePlayer(std::vector<char> board);
void MoveCPU();

void Winner();

char PlayerPiece();
char CPUPiece(char piece);

bool IsEmpty(int pos, const std::vector<char>* board);

const char EMPTY = ' ';
const char X = 'X';
const char O = 'O';
const char TIE = 'T';
const char NOTIE = 'N';
const int NUM_SPACE = 9;

int main()
{
    std::vector<char> board(NUM_SPACE, EMPTY);
    DisplayBoard(&board);
    char human = PlayerPiece();
    char CPU = CPUPiece(human);

    std::cout << "Player use: " << human << " CPU use: " << CPU << std::endl;

    board[MovePlayer(board)] = human;

    DisplayBoard(&board);
}

void DisplayBoard(const std::vector<char>* board)
{
    std::cout << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << (*board)[0] << "|" << (*board)[1] << "|" << (*board)[2] << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << (*board)[3] << "|" << (*board)[4] << "|" << (*board)[5] << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << (*board)[6] << "|" << (*board)[7] << "|" << (*board)[8] << std::endl;
    std::cout << "-----" << std::endl;
}

int MovePlayer(std::vector<char> board)
{
    int move;
    std::cout << "Where do you want to move?" << std::endl;
    std::cin >> move;
    while (!IsEmpty(move, &board))
    {
        std::cout << "Is already occupied" << std::endl;
        std::cin >> move;
    }

    return move;
}

char PlayerPiece()
{
    char answer;
    std::cout << "Do you want to go first? (Y/N)" << std::endl;
    std::cin >> answer;
    answer = toupper(answer);

    if (answer == 'Y')
    {
        return X;
    }
    else
    {
        return O;
    }
}

char CPUPiece(char piece)
{
    if (piece == X)
        return O;
    else
        return X;
}

bool IsEmpty(int pos, const std::vector<char>* board)
{
    return ((*board)[pos] == EMPTY);
}


