// Team Members: Nicholas Rosas, Raquel Figueroa, Maria Garcia, Thalia Villalobos
// Date: 10-30-15
// Project: Evaluating structual strength
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

double mean(vector<int> &v);
// ***********************************************************
// Precondition: Function recieves a vector of values
// PostCondition: Function returns the average of the values given in the vector
// Summary: Function calculates the average from the values within given vector
// ***********************************************************
int maxVal(vector<int> &v);
// ***********************************************************
// Precondition: Function recieves a vector of values
// PostCondition: Function returns the max value in the vector
// Summary: Function finds and returns the maximum value from a given vector
// ***********************************************************
int minVal(vector<int> &v);
// ***********************************************************
// Precondition: Function recieves a vector of values
// PostCondition: Function returns the min value in the vector
// Summary: Function finds and returns the minimum value from a given vector
// ***********************************************************
double variance(vector<int> &v, double a);
// ***********************************************************
// Precondition: Function recieves a vector of values and the average
// PostCondition: Function returns the variation of the values
// Summary: Function finds the variation of values from the given data within the vector
// ***********************************************************
double standardDev(vector<int> &v, double a);
// ***********************************************************
// Precondition: Function recieves the variance and the average
// PostCondition: Function returns the standard deviation
// Summary: Function finds the standard deviation of values from the given data within the vector
// ***********************************************************
int main()
{
    ifstream finSteel;
    ifstream finGraph;
    ofstream fout;
    vector<int> v1;
    vector<int> v2;
    int val;
    double avg1, avg2, var1, var2, stdDev1, stdDev2;

    finSteel.open("data1.txt");
    finGraph.open("data2.txt");
    fout.open("results.txt");

    if(finSteel.fail() || finGraph.fail() || fout.fail())
    {
        cout << "Error, failed to open file(s)\n";
        exit(1);
    }

    while(finSteel >> val)
    {
        v1.push_back(val);
    }
    while(finGraph >> val)
    {
        v2.push_back(val);
    }

    avg1 = mean(v1);
    avg2 = mean(v2);
    var1 = variance(v1, avg1);
    var2 = variance(v2, avg2);
    stdDev1 = standardDev(v1, avg1);
    stdDev2 = standardDev(v2, avg2);

    fout << "Team Members: Nicholas Rosas, Raquel Figueroa, Maria Garcia, Thalia Villalobos\n\n";
    fout << "Mean of coupon values for Steel: " << setw(20) << avg1 << endl;
    fout << "Mean of coupon values for Graphite: " << setw(17) << avg2 << endl;
    fout << "Max value of coupon values for Steel: " << setw(13) << maxVal(v1) << endl;
    fout << "Max value of coupon values for Graphite: " << setw(10) << maxVal(v2) << endl;
    
    fout << "Min value of coupon values for Steel: " << setw(13) << minVal(v1) << endl;
    fout << "Min value coupon values for Graphite: " << setw(13) << minVal(v2) << endl;
    fout << "Variance for Steel coupon values: " << setw(20) << var1 << endl;
    fout << "Variance for Graphite coupon values: " << setw(14) << var2 << endl;
    fout << "Standard Deviation for Steel coupon values: " << setw(10) << stdDev1 << endl;
    fout << "Standard Deviation for Graphite coupon values: " << setw(8) << stdDev2 << endl;

    fout << "\n\nUpon considering these two coupon data sets, we have concluded that neither material is suitable for the design consideration of an aircraft longeron construction. Although, both the steel and graphite coupons stress test results are above the necessary design factor of S = 2, not all of the data points of the design factor S = 2 or 16000N are within three standard deviations.\n";


    finSteel.close();
    finGraph.close();
    fout.close();

    return 0;
}
double mean(vector<int> &v)
{
    double sum = 0.0;
    double average;

    for (int i =0; i < v.size(); i ++)
    {
        sum += v[i];
    }
    average = sum / v.size();
    return average;  
} // end of mean()
int maxVal(vector<int> &v)
{
    int max = v[0];
    for(int ix = 0; ix < v.size(); ix++)
    {
        if (v[ix] > max)
        {
            max = v[ix];
        }
    }  
      return max;
} // end of maxVal()

int minVal(vector<int> &v)
{
    int min = v[0];
    
    for(int ix = 0; ix < v.size(); ix++)
    {
        if(min > v[ix])
        {
            min = v[ix];
        }
    }

    return min;

}  // end of minVal()

double variance(vector<int> &v, double a)
{
    double result(0);
    double mean(0), sum(0), vSum(0);
    
    for (int i = 0; i < v.size(); i++)
    {
        vSum += pow( fabs(v[i] - a), 2);
    }
    
    result = vSum / v.size();
    return result;
}
//End variance function
//********************************************************
//
double standardDev(vector<int> &v, double a)
{
    double result(0);
    result = sqrt(variance(v, a));
    return result;
}//End standardDev function

