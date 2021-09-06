#include <sstream>

#include "ED.h"


ED::ED()
{

}
ED::ED(string n, string m)
{
    stringN = n;
    stringM = m;
    vector<int> t;
    t.resize(m.length()+1,0);
    
    matrix.resize(n.length()+1, t);

    ed = OptDistance();
    aligned = Alignment();
}
ED::~ED()
{

}

int ED::penalty(char a, char b) 
{
  if(a == b)
    return 0;
  return 1;
}
int ED::min(int a, int b, int c) 
{
  if(a <= b && a <= c)
    return a;
  else if(b <= c)
    return b;
  else
    return c;
}

int ED::OptDistance()
{
    int maxIndexI = (int)matrix.size()-1;
    for(int i = maxIndexI; i >= 0; i--)
    {
        int maxIndexJ = (int)matrix[i].size()-1;
        for(int j = maxIndexJ; j >= 0; j--)
        {
            //-- DEBUG --

            if(j == maxIndexJ && i == maxIndexI)
                matrix[i][j] = 0; //bottom right corner set at 0
            else if (i == maxIndexI) {
                matrix[i][j] = matrix[i][j+1] + 2; //bottom edge set
            }
            else if (j == maxIndexJ)
                matrix[i][j] = matrix[i+1][j] + 2; //right edge set
            else
                matrix[i][j] = min(matrix[i+1][j+1]+penalty(stringN[i], stringM[j]), matrix[i+1][j]+2, matrix[i][j+1] + 2);
            
        }
    }

    
    return matrix[0][0];
   
    
}
string ED::Alignment()
{
    stringstream output;
    int i = 0;
    int j = 0;
    while(i < (int)matrix.size()-1 && j < (int)matrix[0].size()-1)
    {
        if(matrix[i][j] - matrix[i][j+1] == 2){     
           
            output <<  "- " << stringM[j] << " " << matrix[i][j] - matrix[i][j+1] << endl;
            j++;
        }
        else if(matrix[i][j] - matrix[i+1][j] == 2){
            output << stringN[i] << " - " << matrix[i][j] - matrix[i+1][j] << endl;
            i++;
        }
        else if((matrix[i][j] - matrix[i+1][j+1] == 1) || (matrix[i][j] - matrix[i+1][j+1] == 0)){
            output << stringN[i] << " " << stringM[j] << " " << matrix[i][j] - matrix[i+1][j+1] << endl;
            i++;
            j++;
        }
        else
            output << "ALIGNMENT ERROR";


    }
    
    return output.str();
}
int ED::getED()
{
    return ed;
}
string ED::getAlignedStrings()
{
    return aligned;
}