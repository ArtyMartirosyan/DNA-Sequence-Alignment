#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ED{
public:
    ED();
    ED(string, string);
    ~ED();
    static int penalty(char, char);
    static int min(int, int, int);
    int OptDistance();
    string Alignment();
    int getED();
    string getAlignedStrings();
private:
    //int rows;
    //int col;
    int ed;
    string aligned;
    string stringN;
    string stringM;

    vector<vector<int>> matrix;
    
};