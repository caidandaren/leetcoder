#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
	int n = prices.size();
    int maxint = 0;
    int min_stock = prices[0];
    for(int i=1; i<n; i++){
    	if(prices[i]-min_stock>maxint) maxint = prices[i]-min_stock;
    	if(prices[i]<min_stock) min_stock = prices[i];
    }
    return maxint;
}