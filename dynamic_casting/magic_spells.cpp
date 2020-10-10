// https://www.hackerrank.com/challenges/magic-spells/problem

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: 
        int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            std::cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: 
        int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            std::cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: 
        int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            std::cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: 
        int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            std::cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 

// initiliazing stativ variable
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string spell_class = typeid(*spell).name();
    while (isdigit(spell_class.front()))
        spell_class.erase(spell_class.begin());

    if (spell_class == "Fireball"){
        auto spell_base = dynamic_cast<Fireball*> (spell);
        spell_base->revealFirepower();
    }
    else if (spell_class == "Frostbite"){
        auto spell_base = dynamic_cast<Frostbite*> (spell);
        spell_base->revealFrostpower();
    }
    else if (spell_class == "Thunderstorm"){
        auto spell_base = dynamic_cast<Thunderstorm*> (spell);
        spell_base->revealThunderpower();
    }
    else if (spell_class == "Waterbolt"){
        auto spell_base = dynamic_cast<Waterbolt*> (spell);
        spell_base->revealWaterpower();
    }
    else {
        string s1 = spell->revealScrollName();
        string s2 = SpellJournal::read();
        int m = s1.size(), n = s2.size();

        int L[m + 1][n + 1];  
        int i, j;  
        
        for (i = 0; i <= m; i++)  
        {  
            for (j = 0; j <= n; j++)  
            {  
                if (i == 0 || j == 0)  
                    L[i][j] = 0;  
            
                else if (s1[i - 1] == s2[j - 1])  
                    L[i][j] = L[i - 1][j - 1] + 1;  
            
                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
            }  
        }
        std::cout << L[m][n] << endl;
    }
}

/*
Sample Input

3
fire 5
AquaVitae 999 AruTaVae
frost 7

Sample Output

Fireball: 5
6
Frostbite: 7
*/

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; 
            std::cin >> s;
            int power; 
            std::cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                std::cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    std::cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}