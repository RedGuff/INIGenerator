#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <cassert>
using namespace std;

int main() {
    srand(time(NULL));       // No need for better init.
    string fileOut = "out.ini";
    int nbNames = 42;
    int nbVars = 42;
    int minData = 0;
    int maxData = 1024;
    if(maxData < minData) {    // Usually, the minimum is before the maximum, and sometimes it is not the default value.
        auto temp = maxData;
        maxData = minData;
        minData = temp;
        }
    ofstream outfile(fileOut.c_str());
    if(!outfile) {
        cerr << "Impossible to write the file: " << fileOut << endl;
        }
    else {
        for(int a = 1; a < nbNames + 1; a++) {
            cout << "[Name" << a << "]" << endl;
            outfile << "[Name" << a << "]" << endl;
            for(int b = 1; b < nbVars + 1; b++) {
                cout << "var" << b << " = " << rand() % (maxData - minData + 1) + minData   << endl;
                outfile << "var" << b << " = " << rand() % (maxData - minData + 1) + minData   << endl;
                }
            cout << "" << endl;
            outfile << "" << endl;
            }
        }
    cout << "Ok!" << endl;
    return 0;
    }
