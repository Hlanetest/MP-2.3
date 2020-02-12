#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

const float SURCHARGE_COST = .035;
const int CARS_WEIGHT = 74.5;
int main() {
    string RAIL_NAME, DESTINATION, SURCHARGE, line;
    int NUM_CARS;
    float TON_COST, TOTAL_VAL, TOTAL_WEIGHT, SURCHARGE_EST;
    ifstream ORE_SHIPPING("/home/hadrian/Desktop/Railway1.txt");
    getline(ORE_SHIPPING, RAIL_NAME);
    ORE_SHIPPING >> NUM_CARS >> TON_COST;
    getline(ORE_SHIPPING, DESTINATION);
    getline(ORE_SHIPPING, SURCHARGE);
    cout << RAIL_NAME << "\n";
    //ORE_SHIPPING >> RAIL_NAME >> NUM_CARS >> TON_COST >> DESTINATION >> SURCHARGE;
    cout << NUM_CARS << "\n";
    cout << TON_COST << "\n";
    cout << DESTINATION << "\n";
    
    //The equations to get the numbers we need for later.
    TOTAL_WEIGHT = NUM_CARS * CARS_WEIGHT;
    TOTAL_VAL = TOTAL_WEIGHT * TON_COST;
    SURCHARGE_EST = TOTAL_VAL * SURCHARGE_COST;

    return 0;
}
http://www.cplusplus.com/reference/string/string/getline/
http://www.cplusplus.com/reference/string/string/substr/
