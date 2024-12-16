#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int maxHealth, vector<vector<int>> attacks) 
{
    int castingTime = bandage[0];
    int healPerSec = bandage[1];
    int afterHeal = bandage[2];
    int health = maxHealth;
    
    int prevTime = 0;
    int curTime = 0;
    
    for (vector<int> attack : attacks)
    {
        int attackTime = attack[0];
        int attackDamage = attack[1];
        
        curTime = attackTime - prevTime - 1;
        prevTime = attackTime;
        //cout << "curTime: " << curTime << ", attackTime: " << attackTime << endl;
        health += curTime * healPerSec;
        //cout << "add: " << curTime * healPerSec;
        health += curTime / castingTime * afterHeal;
        //cout << "add: " << curTime / castingTime * afterHeal << endl;
        
        if (health > maxHealth)
            health = maxHealth;
        //cout << health << endl;
        
        health -= attackDamage;
        
        if (health <= 0)
            return -1;
        //cout << health << endl;
    }
    
    return health;
}