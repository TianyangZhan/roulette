#include "roulette.h"
#include "gambit.h"
#include <iostream>

void initiate_bet_on_odds(Roulette roulette, Gambit* player, int numTurns)
{
    //double bet starting from $5 if lose, once won start from 5, bet on odds.
    //Table limit = $500.
    int curBet = 5;
    int prevCapital = player->get_capital();
    for(int i = 0; (i < numTurns && player->get_capital() > 0); i++)
    {
        prevCapital = player->get_capital();
        roulette.spin();
        player->bet_on_odd(roulette, curBet);
        roulette.reset_slots();
        if(player->get_capital() < prevCapital)
            curBet *= 2;
        if(curBet > 500)
            curBet = 5;
        if(player->get_capital() == 0)
            cout << "Bankrupt from Odd" << endl;
    }
}

void initiate_bet_on_two_thirds(Roulette roulette, Gambit* player, int numTurns)
{
    int curBet = 5;
    int prevCapital = player->get_capital();
    for(int i = 0; (i < numTurns && player->get_capital() > 0); i++)
    {
        prevCapital = player->get_capital();
        roulette.spin();
        player->bet_on_first12(roulette, curBet);
        player->bet_on_second12(roulette, curBet);
        roulette.reset_slots();
        if(player->get_capital() < prevCapital)
            curBet *= 2;
        if(curBet > 250)
            curBet = 5;
        if(player->get_capital() == 0)
            cout << "Bankrupt from 2/3" << endl;
    }
}

int main()
{
    Roulette table1;
    int initial = 200;
    int numTurns = 500;
    
    Gambit player1 = Gambit(initial);
    initiate_bet_on_odds(table1, &player1, numTurns);
    int profitOdd = player1.get_profit(initial);

    Gambit player2 = Gambit(initial);
    initiate_bet_on_two_thirds(table1, &player2, numTurns);
    int profitTwoThirds = player2.get_profit(initial);

    cout << "profitOdd: " << profitOdd << endl;
    cout << "profitTwoThirds: " << profitTwoThirds << endl;

    return 0;
}