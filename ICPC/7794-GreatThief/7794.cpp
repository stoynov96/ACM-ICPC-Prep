//Niko's solution to "Great Thief" revised by Nick 
//to be more readable with comments.
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    long long n;
    long long * safeHousesInColumn;
        
    while (cin >> n) {        
        //Calculating this requires you find all possible combinations of 
        //(fractions i/j) i over j such that 1<=i<j && 1<j<=n. If you perform this 
        //calculation you will find the result is ((n^2 - n) / 2).
        //We first assume all houses are unsafe and subtract safe houses
        //from that total.
        long long unsafeHouses = (((n * n) - n) / 2);
        
        long long halfN = n/2;
        long long unsafeHousesInCurrentColumn = 1;
        long long * safeHousesInColumn;
        //Initiate number of safe houses in each column to 0 
        //(there are initially no safe houses).
        //NOTE: Safe houses refers to houses that have been marked "sticky".
        //Unsafe houses refers to hosues that have NOT been marked "sticky".
        safeHousesInColumn = (long long *) calloc(halfN+1, sizeof(long long));
        
        //This outer loop only needs to traverse half of "n" because
        //there are no integer multiples less than 2. It also starts at 
        //2 because we are only traversing columns that start from position
        //(1,2) which form a triangle within the square matrix of the entire field
        //and then using symmetry later on to calculate the total houses. 
        for (long long i = 2; i <= halfN; ++i) {
        
            //The number of unsafeHousesInCurrentColumn is equal to 
            //the number of houses in that column (i-1) minus the number of 
            //safeHousesInColumn[i].
            unsafeHousesInCurrentColumn = (i-1) - safeHousesInColumn[i];
            
            //This loop marks ONLY those houses less than or equal to column halfN
            //as marked safe so that those houses marked safe will not mark any 
            //other houses unsafe later on.
            int multiplier = 2;
            while (i * multiplier <= halfN) {
                safeHousesInColumn[i * multiplier] += unsafeHousesInCurrentColumn;
                multiplier++;
            }
            
            //numberOfPossibleHousesHitFromThisColumn multiplied by unsafeHousesInCurrentColumn
            //produces the number of safeHouses in all future columns and we subtract that from 
            //unsafeHouses which we initially assumed to be the entire array.
            int numberOfPossibleHousesHitFromThisColumn = (n/i - 1);
            unsafeHouses -= unsafeHousesInCurrentColumn * numberOfPossibleHousesHitFromThisColumn;
        }
        
        //Using symmetry to calculate the other half of the square matrix
        //and adding four to get the initial 4 unsafe houses 
        unsafeHouses *= 2;
        unsafeHouses += 4;
        cout << unsafeHouses << endl;
        delete [] safeHousesInColumn;
    }
}