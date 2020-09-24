// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// Example 1:

// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    vector<int> output;
    int height=matrix.size();
    if(height==0) return output;
    int length=matrix[0].size();
    int lb=0, rb=length-1, ub=0, db=height-1;
    int dir=0;
    int i=0;
    int j=0;
    while(lb<=rb && ub<=db){
        output.push_back(matrix[i][j]);
        switch(dir){
            case 0:
                if(j>=rb){ub++; i++; dir=1;} else j++;
                break;
            case 1:
                if(i>=db){rb--; j--; dir=2;} else i++;
                break;
            case 2:
                if(j<=lb){db--; i--; dir=3;} else j--;
                break;
            case 3:
                if(i<=ub){lb++; j++; dir=0;} else i--;
                break;
        }
    }
    cout<<output[4];
    return output;        
}

int main(int argc, char const *argv[])
{
	int a[3] = {1,2,3};
	vector<vector<int> > t;
	vector<int> a1(a,a+3);
	t.push_back(a1);
	t.push_back(a1);
	t.push_back(a1);
	spiralOrder(t);
	return 0;
}