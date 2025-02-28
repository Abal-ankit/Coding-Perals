#include <bits/stdc++.h>

using namespace std;

template <class T>
class MaxPQ
{
    vector<T> maxpq;

    void heapify(int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < maxpq.size() && maxpq[l] > maxpq[largest])
            largest = l;

        if (r < maxpq.size() && maxpq[r] > maxpq[largest])
            largest = r;

        if (largest != i)
        {
            swap(maxpq[i], maxpq[largest]);
            heapify(largest);
        }
    }

public:
    bool empty()
    {
        return maxpq.empty();
    }

    T top()
    {
        return maxpq.front();
    }

    void pop()
    {
        if (maxpq.empty())
            return;

        if (maxpq.size() == 1)
        {
            maxpq.pop_back();
            return;
        }

        maxpq.front() = maxpq.back();
        maxpq.pop_back();

        heapify(0);
    }

    void push(T x)
    {
        maxpq.push_back(x);

        int i = maxpq.size() - 1;
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (maxpq[parent] < maxpq[i])
            {
                swap(maxpq[parent], maxpq[i]);
                i = parent;
            }
            else
            {
                break;
            }
        }
    }
};

string sortString(string &s)
{
    unordered_map<char, int> freq;
    for (char i : s)
        freq[i]++;

    MaxPQ<pair<int, char>> pq;
    for (auto i : freq)
        pq.push({i.second, i.first});

    string ans = "";
    while (!pq.empty())
    {
        ans += string(pq.top().first, pq.top().second);
        pq.pop();
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << sortString(s);
}
