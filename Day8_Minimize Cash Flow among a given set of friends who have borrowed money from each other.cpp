#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct AscendingComparator {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    }
};

struct DescendingComparator {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

class Solution {
private:
    priority_queue<pair<int, int>, vector<pair<int, int>>, DescendingComparator> maxHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, AscendingComparator> minHeap;

    void constructHeaps(const vector<int>& amounts) {
        for (int i = 0; i < amounts.size(); ++i) {
            if (amounts[i] == 0) continue;
            if (amounts[i] > 0) {
                maxHeap.emplace(i, amounts[i]);
            } else {
                minHeap.emplace(i, amounts[i]);
            }
        }
    }

    void resolveTransactions() {
        while (!minHeap.empty() && !maxHeap.empty()) {
            auto maxCredit = maxHeap.top();
            maxHeap.pop();

            auto maxDebit = minHeap.top();
            minHeap.pop();

            int transactionValue = maxCredit.second + maxDebit.second;
            int debtor = maxDebit.first;
            int creditor = maxCredit.first;
            int owedAmount = 0;

            if (transactionValue == 0) {
                owedAmount = maxCredit.second;
            } else if (transactionValue < 0) {
                owedAmount = maxCredit.second;
                minHeap.emplace(maxDebit.first, transactionValue);
            } else {
                owedAmount = -maxDebit.second;
                maxHeap.emplace(maxCredit.first, transactionValue);
            }

            cout << "Person " << debtor << " pays " << owedAmount << " to Person " << creditor << endl;
        }
    }

public:
    void minCashFlow(const vector<vector<int>>& graph) {
        int numPeople = graph.size();
        vector<int> amounts(numPeople, 0);

        for (int i = 0; i < numPeople; ++i) {
            for (int j = 0; j < numPeople; ++j) {
                int netTransaction = graph[j][i] - graph[i][j];
                amounts[i] += netTransaction;
            }
        }

        constructHeaps(amounts);
        resolveTransactions();
    }
};
