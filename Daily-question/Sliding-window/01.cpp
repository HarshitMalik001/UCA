// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <string>
using namespace std;

int find(string fr)
{
	int n = fr.size();
	map <char, int> mpp;
	
	int max_ = 0;
	int start = 0;
	int count = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(mpp.find(fr[i]) == mpp.end() || mpp[fr[i] == 0])
		{
			count++;
			mpp[fr[i]] = 1;
		}
		else mpp[fr[i]]++;
		if(count > 2)
		{
			while(count > 2)
			{
				mpp[fr[start]]--;
				if(mpp[fr[start]] == 0) count--;
				start++;		
			}
		}
		max_ = max(max_, (i - start + 1));
	}
	return max_;
}

int main() {
    // Write C++ code here
    string gg;
    cin >> gg;
    
    cout << find(gg);

    return 0;
}