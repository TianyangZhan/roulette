#include "gambit.h"

void Gambit::bet_on_odd(Roulette roulette, int amount)
{
    if(roulette.get_strike() % 2)
        capital += amount;
    else   
        capital -= amount;
}

void Gambit::bet_on_even(Roulette roulette, int amount)
{
    if(roulette.get_strike() % 2)
        capital -= amount;
    else   
        capital += amount;
}

void Gambit::bet_on_blacks(Roulette roulette, int amount)
{
    if(roulette.get_color(roulette.get_strike()) == "black")
        capital += amount;
    else
        capital -= amount;
}

void Gambit::bet_on_reds(Roulette roulette, int amount)
{
    if(roulette.get_color(roulette.get_strike()) == "red")
        capital += amount;
    else
        capital -= amount;
}

void Gambit::bet_on_first18(Roulette roulette, int amount)
{
    if(roulette.get_strike() <= 18 && roulette.get_strike() >= 1)
        capital += amount;
    else
        capital -= amount;
}

void Gambit::bet_on_second18(Roulette roulette, int amount)
{
    if(roulette.get_strike() <= 36 && roulette.get_strike() >= 19)
        capital += amount;
    else
        capital -= amount;
}

void Gambit::bet_on_first12(Roulette roulette, int amount)
{
    if(roulette.get_strike() <= 12 && roulette.get_strike() >= 1)
        capital += 2*amount;
    else
        capital -= amount;
}

void Gambit::bet_on_second12(Roulette roulette, int amount)
{
    if(roulette.get_strike() <= 24 && roulette.get_strike() >= 13)
        capital += 2*amount;
    else
        capital -= amount;
}

void Gambit::bet_on_third12(Roulette roulette, int amount)
{
    if(roulette.get_strike() <= 36 && roulette.get_strike() >= 25)
        capital += 2*amount;
    else
        capital -= amount;
}

void Gambit::bet_on_3n_plus1(Roulette roulette, int amount)
{
    if(roulette.get_strike() % 3 == 1)
        capital += 2*amount;
    else
        capital -= amount;
}

void Gambit::bet_on_3n_plus2(Roulette roulette, int amount)
{
    if(roulette.get_strike() % 3 == 2)
        capital += 2*amount;
    else
        capital -= amount;
}

void Gambit::bet_on_3n(Roulette roulette, int amount)
{
    if(roulette.get_strike() % 3 == 0)
        capital += 2*amount;
    else
        capital -= amount;
}

void Gambit::bet_on_number(Roulette roulette, int amount, int number)
{
    if(roulette.get_strike() == number)
        capital += 36*amount;
    else
        capital -= amount;
}

int Gambit::get_profit(int initial)
{
    return capital - initial;
}

int Gambit::get_capital()
{
    return capital;
}