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
    int TON_COST;
    ifstream ORE_SHIPPING("/home/hadrian/Desktop/Railway1.txt");
    
    getline(ORE_SHIPPING, RAIL_NAME);
    cin.ignore();
    ORE_SHIPPING >> NUM_CARS >> TON_COST;
    getline(ORE_SHIPPING, DESTINATION);
    getline(ORE_SHIPPING, SURCHARGE);
    cout << RAIL_NAME << "\n";
    //ORE_SHIPPING >> RAIL_NAME >> NUM_CARS >> TON_COST >> DESTINATION >> SURCHARGE;
    cout << NUM_CARS << "\n";
    cout << TON_COST << "\n";
    
    cout << SURCHARGE << "\n";
    return 0;
}
