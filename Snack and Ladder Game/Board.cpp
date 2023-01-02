#include<iostream>
#include<vector>
#include "Cell.cpp"
using namespace std;

class Board{
    public:
    vector<vector<Cell*>> cells;
    Board(int boardSize,int numberOfSnacks,int numberOfLadders){
        initializeCells(boardSize);
        addSnacksLadders(cells, numberOfSnacks, numberOfLadders, boardSize);
    }

    void initializeCells(int boardSize){
        cells.resize(boardSize,vector<Cell*>(boardSize));
        for(int i = 0; i < boardSize; i++){
            for(int j = 0; j < boardSize; j++){
                Cell* cellObj = new Cell();
                cells[i][j] = (cellObj);
            }
        }
    }

    void addSnacksLadders(vector<vector<Cell*>> cells, int numberOfSnacks, int numberOfLadders,int boardSize){
        while(numberOfSnacks--){
            int snackHead = 1 + (rand()%(boardSize*boardSize - 1));
            int snackTail = 1 + (rand()%(boardSize*boardSize - 1));
            if(snackHead <= snackTail){
                continue;
            }

            Jump* snackObj = new Jump();
            snackObj->start = snackHead;
            snackObj->end = snackTail;

            Cell* cell = getCell(snackHead);
            cell->jump = snackObj;
        }

        while(numberOfLadders--){
            int ladderHead = 1 + (rand()%(boardSize*boardSize - 1));
            int ladderTail = 1 + (rand()%(boardSize*boardSize - 1));
            if(ladderHead >= ladderTail){
                continue;
            }

            Jump* ladderObj = new Jump();
            ladderObj->start = ladderHead;
            ladderObj->end = ladderTail;

            Cell* cell = getCell(ladderHead);
            cell->jump = ladderObj;
        }
    }

    Cell* getCell(int playerPosition){
        int boardRow = playerPosition/cells.size();
        int boardCol = playerPosition%cells.size();
        return cells[boardRow][boardCol];
    }
};