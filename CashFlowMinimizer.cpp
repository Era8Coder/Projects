// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <queue>
// #include <set>
// #include <tuple>

// using namespace std;

// class Bank {
// public:
//     string name;
//     int netAmount;
//     multiset<string> paymentTypes;
// };

// void addTransaction(unordered_map<string, unordered_map<string, int>>& graph, const string& u, const string& v, int amount) {
//     graph[u][v] += amount;
// }

// unordered_map<string, int> calculateNetAmounts(const unordered_map<string, unordered_map<string, int>>& graph) {
//     unordered_map<string, int> netAmounts;
//     for (const auto& u : graph) {
//         for (const auto& v : u.second) {
//             netAmounts[u.first] -= v.second;
//             netAmounts[v.first] += v.second;
//         }
//     }
//     return netAmounts;
// }

// vector<tuple<string, string, int, string>> minimizeTransactions(const unordered_map<string, int>& netAmounts, const vector<Bank>& banks) {
//     priority_queue<pair<int, string>> maxHeap;
//     priority_queue<pair<int, string>> minHeap;

//     for (const auto& person : netAmounts) {
//         if (person.second > 0) {
//             maxHeap.push(make_pair(person.second, person.first));
//         } else if (person.second < 0) {
//             minHeap.push(make_pair(-person.second, person.first));
//         }
//     }

//     vector<tuple<string, string, int, string>> transactions;

//     while (!maxHeap.empty() && !minHeap.empty()) {
//         auto maxCredit = maxHeap.top(); maxHeap.pop();
//         auto maxDebit = minHeap.top(); minHeap.pop();

//         int settledAmount = min(maxCredit.first, maxDebit.first);

//         string paymentMethod;
//         for (const auto& bank : banks) {
//             if (bank.name == maxCredit.second) {
//                 for (const auto& type : bank.paymentTypes) {
//                     if (banks[netAmounts.at(maxDebit.second)].paymentTypes.count(type)) {
//                         paymentMethod = type;
//                         break;
//                     }
//                 }
//                 break;
//             }
//         }

//         transactions.push_back(make_tuple(maxDebit.second, maxCredit.second, settledAmount, paymentMethod));

//         if (maxCredit.first > settledAmount) {
//             maxHeap.push(make_pair(maxCredit.first - settledAmount, maxCredit.second));
//         }
//         if (maxDebit.first > settledAmount) {
//             minHeap.push(make_pair(maxDebit.first - settledAmount, maxDebit.second));
//         }
//     }

//     return transactions;
// }

// void printTransactions(const vector<tuple<string, string, int, string>>& transactions) {
//     for (const auto& t : transactions) {
//         cout << get<0>(t) << " pays " << get<1>(t) << " amount " << get<2>(t) << " via " << get<3>(t) << endl;
//     }
// }

// int main() {
//     unordered_map<string, unordered_map<string, int>> graph;
    
//     vector<Bank> banks = {
//         {"A", 0, {"Type1", "Type2"}},
//         {"B", 0, {"Type1"}},
//         {"C", 0, {"Type2"}},
//         {"D", 0, {"Type1"}},
//         {"E", 0, {"Type2"}}
//     };
    
//     addTransaction(graph, "A", "B", 50);
//     addTransaction(graph, "A", "C", 30);
//     addTransaction(graph, "B", "C", 20);
//     addTransaction(graph, "D", "B", 40);
//     addTransaction(graph, "E", "B", 70);

//     unordered_map<string, int> netAmounts = calculateNetAmounts(graph);
//     vector<tuple<string, string, int, string>> transactions = minimizeTransactions(netAmounts, banks);
    
//     printTransactions(transactions);

//     return 0;
// }
