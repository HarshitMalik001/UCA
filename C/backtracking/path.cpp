
#include <iostream>
#include <vector>
using namespace std;


void recursion( vector < vector <int> >all_path, int i, int j, int n, int m)
{
    if(i >= n || j>= m) return ;

    all_path.push_back({i,j});

    if(i==n - 1 && j==m - 1 ){
        for(int i = 0 ; i < all_path.size(); i++)
        {
            cout<<all_path[i][0] << " " << all_path[i][1] << "  ";
        }
        cout<<endl;
    }

    recursion(all_path, i+1, j, n, m);

    recursion(all_path, i, j + 1, n, m);

    all_path.pop_back();

}


int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector < vector <int> >all_path;

    recursion(all_path, 0 , 0, n, m);
}