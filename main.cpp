//
//  main.cpp
//  KOP
//
//  Created by Erich Winkler on 12.12.2022.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <chrono>

#include "Formula.h"
#include "3SAT.h"
#include "Annealing.h"



using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

using namespace std;
int main(int argc, const char * argv[]) {
    string srcFile = argv[1];
    string dstFile = argv[2];
    string Package = argv[3];
    std::stringstream sstrm(argv[4]);
    double CoolingFactor;
    sstrm >> CoolingFactor;
    //cout << "CCCCC " << CoolingFactor <<endl;
    ifstream input;
    ifstream output;
    
    SAT sat(srcFile);
    
    if(!sat.readFormulas()){
        cout << "Err - main" << endl;
        return -1;
    }
    auto t1 = high_resolution_clock::now();
    //cout << sat.ExtractName() << endl;
    //cout << sat.getMaxWeight() <<endl;

    Annealing a(sat.NumberOfVariables * 10,sat.NumberofClausule * sat.NumberOfVariables * 10, CoolingFactor, dstFile, Package);

 
    a.simulation(sat);
    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<std::chrono::milliseconds>(t2 - t1);
    cout << ms_int.count() << endl;
    a.WriteSolutionIntoFile();
    //a.CreateCSV();
    a.CSVTime(ms_int.count());
    
    cout <<"PEND"<< endl;
    return 0;
}
