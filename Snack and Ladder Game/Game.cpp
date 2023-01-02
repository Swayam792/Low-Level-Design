#include<iostream>
#include<deque>
#include "Board.cpp"
#include "Dice.cpp"
#include "Player.cpp"
using namespace std;

class Game{
    public:
    Board* board;
    Dice* dice;
    deque<Player*> playerList;
    Player* winner;
    Game(){
        initializeGame();
    }
    
    void initializeGame(){
        board = new Board(10,5,4);
        dice = new Dice(1);
        winner = nullptr;
        addPlayers();
    }

    void addPlayers(){
        Player *player1 = new Player("p1",0);
        Player *player2 = new Player("p2",0);
        playerList.push_back(player1);
        playerList.push_back(player2);
    }

    void startGame(){
        while(winner == nullptr){
            // check whose turn is this
            Player* playerTurn = findPlayerTurn();
            cout<<"Player turn is: "<<playerTurn->id<<" current position is: "<<playerTurn->currPosition<<endl;

            // roll the dice
            int diceNumbers = dice->rollDice();

            // get the new position
            int playerNewPosition = playerTurn->currPosition + diceNumbers;
            playerNewPosition = jumpCheck(playerNewPosition,playerTurn->currPosition);
            playerTurn->currPosition = playerNewPosition;

            cout<<"Player turn is: "<<playerTurn->id<<" new Position is: "<<playerNewPosition<<endl;

            if(playerNewPosition == board->cells.size()*board->cells.size()-1){
                winner = playerTurn;
            }
        }
        cout<<"Winner is: "<<winner->id<<endl;
    }

    private:
    Player* findPlayerTurn(){
        Player* playerTurn = playerList.front();
        playerList.pop_front();
        playerList.push_back(playerTurn);
        return playerTurn;
    }

    int jumpCheck(int playerNewPosition,int playerOldPosition){
        if(playerNewPosition > board->cells.size()*board->cells.size()-1){
            return playerOldPosition;
        }

        Cell* cell = board->getCell(playerNewPosition);
        if(cell->jump != nullptr and cell->jump->start == playerNewPosition){
            string jumpBy = ((cell->jump->end > cell->jump->start)? "Ladder": "Snack");
            cout<<"Jump done by: "<<jumpBy<<endl;
            return cell->jump->end;
        }
        return playerNewPosition;
    }
};

int main(){
    Game * obj = new Game();
    obj->startGame();
}