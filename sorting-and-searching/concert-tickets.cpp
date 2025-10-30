#include "../stdc++.h"
using namespace std;

// incomplete
int binSearch(vector<int> &tickets, vector<bool> &visit, int maxPay)
{

    int l = 0;
    int h = tickets.size() - 1;
    int ans = -1;
    while (l <= h)
    {
        int mid = l + h / 2;
        if (tickets[mid] <= maxPay)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    tickets[ans]=1e9;
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> tickets(n);
    vector<bool> ticketsTaken(n);
    vector<int> maxpay(m);
    for (int i = 0; i < n; i++)
        cin >> tickets[i];
    sort(tickets.begin(), tickets.end());
    for (int i = 0; i < m; i++)
    {
        cin >> maxpay[i];
        cout << binSearch(tickets, ticketsTaken, maxpay[m]) << endl;
    }
}
/*

Input:

5 3
5 3 7 8 5
4 8 3

Output:

3
8
-1


3 5 5 7 8
4 8 3
*/