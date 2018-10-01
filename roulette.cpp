#include <cstdlib>
#include <string>
using namespace std;

class Roulette
{
    public:
    Roulette()
    {
        for(int i = 0; i < 38; i++)
            slot[i] = false;
        for(int i = 0; i < 38; i++)
            colors[i] = "black";
        colors[0] = "none";
        colors[1] = "red";
        colors[3] = "red";
        colors[5] = "red";
        colors[7] = "red";
        colors[9] = "red";
        colors[12] = "red";
        colors[14] = "red";
        colors[16] = "red";
        colors[18] = "red";
        colors[19] = "red";
        colors[21] = "red";
        colors[23] = "red";
        colors[25] = "red";
        colors[27] = "red";
        colors[30] = "red";
        colors[32] = "red";
        colors[34] = "red";
        colors[36] = "red";
        colors[38] = "none"; //00
    }
    void reset_slots();
    void spin();
    int get_strike();
    string get_color(int index);
    private:
    bool slot [38]; // 00 corresponds to index 37
    string colors [38];
    int strike;
};

string Roulette::get_color(int index)
{
    return colors[index];
}

int Roulette::get_strike()
{
    return strike;
}

void Roulette::reset_slots()
{
    for(int i = 0; i < 38; i++)
        slot[i] = false;
}

void Roulette::spin()
{
    int hit = rand() % 38;
    slot[hit] = true;
    strike = hit;
}

class Gambit
{
    public:
    Gambit(int amount) 
    {
        capital = amount;
    }
    void bet_on_odd(Roulette roulette, int amount);
    void bet_on_even(Roulette roulette, int amount);
    void bet_on_blacks(Roulette roulette, int amount);
    void bet_on_reds(Roulette roulette, int amount);
    void bet_on_first18(Roulette roulette, int amount);
    void bet_on_second18(Roulette roulette, int amount);
    void bet_on_first12(Roulette roulette, int amount);
    void bet_on_second12(Roulette roulette, int amount);
    void bet_on_third12(Roulette roulette, int amount);
    void bet_on_3n_plus1(Roulette roulette, int amount);
    void bet_on_3n_plus2(Roulette roulette, int amount);
    void bet_on_3n(Roulette roulette, int amount);
    void bet_on_number(Roulette roulette, int amount, int number);
    private:
    int capital;
};

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