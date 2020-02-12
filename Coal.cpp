/*This is a Railroad cost per SHORT TON script made by Harrison Lane, this will read info from a file, and then store the results into a new file! */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const float SURCHARGE_COST = .035;
const float CARS_WEIGHT = 74.5;
int main() {
    string RAIL_NAME, DESTINATION, SURCHARGE, line;
    int NUM_CARS;
    float TON_COST, TOTAL_VAL, TOTAL_WEIGHT, SURCHARGE_EST;
    float TOTAL_SUR;
    
    SURCHARGE_EST = 0.0;
    TOTAL_VAL = 0.0;
    TON_COST = 0.0;


    ifstream ORE_SHIPPING("/home/hlane/Documents/Homework/Railway1.txt");
    ofstream OUTPUTFILE("/home/hlane/Documents/Homework/Output2.txt");
    //Checking if the files are open.
    if (ORE_SHIPPING.is_open()){}
    else{
        cout << "FILE NOT FOUND";
    }

    getline(ORE_SHIPPING, RAIL_NAME);
    ORE_SHIPPING >> NUM_CARS >> TON_COST;
    /*The reason for the line there is because It kept getting whitespace after the 66.27 
    for whatever reason, so in order to store my DESTINATION variable, 
    I just stored it in a worthless variable, and kept going */
    getline(ORE_SHIPPING, line);
    getline(ORE_SHIPPING, DESTINATION);
    getline(ORE_SHIPPING, SURCHARGE);

    //The mathmatical equations
    TOTAL_WEIGHT = NUM_CARS * CARS_WEIGHT;
    TOTAL_VAL = TOTAL_WEIGHT * TON_COST;
    SURCHARGE_EST = TOTAL_VAL * SURCHARGE_COST;
    TOTAL_SUR = SURCHARGE_EST + TOTAL_VAL;


    //Where we output to the files! 
    OUTPUTFILE << "KERBAA&M COAL TRAIN REPORT - HARRISON LANE" << endl << endl;
    OUTPUTFILE << "Railroad name: " << left << setw(38) << setfill(' ') << right << RAIL_NAME << "\n";
    OUTPUTFILE << "Destination: " << left << setw(23) << setfill (' ') << right << DESTINATION << endl << endl;
    OUTPUTFILE << "Number of ore cars: " << left << setw(11) << setfill('.') << ' ' << right << setw(13) << setfill(' ') << NUM_CARS  << "\n";
    OUTPUTFILE << "Total weight of coal: " << left << setw(9) << setfill('.') << ' ' << right <<setw(13) << setfill(' ') << TOTAL_WEIGHT << " short tons" << "\n";
    OUTPUTFILE << "Current Cost per Short ton: " << left << setw(4) << setfill('.') << right << " " << '$'<< setw(10) << setfill(' ') << TON_COST << "\n";
    OUTPUTFILE << "Total Value of Shipment: " << left << setw(9) << setfill('.') << right << " $ " << setw(10) << setfill(' ') << TOTAL_VAL << "\n";
    //Checking if either file has a Y or an N for surcharge. 
    if(SURCHARGE == "y"){
        OUTPUTFILE << "Current Surcharge: " << left << setw(12) << setfill('.') << " " << right << setw(13) << setfill(' ') << "3.5" << " %" << endl << endl;
        OUTPUTFILE << "Surcharge(est): " << left << setw(15) << setfill('.') << right << " $ " << setw(13) << setfill(' ') << SURCHARGE_EST << "\n";
        OUTPUTFILE << "Total with Surcharge: " << left << setw(9) << setfill('.') << right << " $ " << setw(13) << setfill(' ') << TOTAL_SUR << "\n";
        return 0;
    }
    else if(SURCHARGE == "n"){
        OUTPUTFILE << "Current Surcharge: " << left << setw(12) << setfill('.') << " " << right << setw(13) << setfill(' ') << "0.0" << " %" << endl << endl;
        OUTPUTFILE << "Total: " << left << setw(27) << setfill('.') << right << " $ " << setw(10) << setfill(' ') << TOTAL_VAL << "\n";
        return 0;

    }


    
    return 0;
}
