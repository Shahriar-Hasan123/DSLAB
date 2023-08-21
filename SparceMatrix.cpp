#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fixed(x) cout << fixed << setprecision(x)
#define endl '\n'
int main()
{
	cout << "Number of row and column: ";
	int n;
	cin >> n;
	int matrix[n][n];
	memset(matrix, 0, sizeof(matrix));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> matrix[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	int size = (n * (n + 1)) / 2;
	int B[size], k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
			B[k] = matrix[i][j], k++;

	for (int i = 0; i < size;i++)
		cout << B[i] << " ";
	cout << endl;

	return 0;
}