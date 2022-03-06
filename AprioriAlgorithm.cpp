#include <bits/stdc++.h>

using namespace std;

// prepare the C1 table
map<set<string>, int> prepareFirstCountTable(const vector<set<string>> &dataSet) {
    
    map<string, int> freq;
    for (int i = 0; i < dataSet.size(); ++i) {
        for (auto itr: dataSet[i]) {
            ++freq[itr];
        }
    }

    map<set<string>, int> table;
    for (auto &element: freq) {
        set<string> temp;
        temp.insert(element.first);
        table[temp] = element.second;
    }

    return table;
}

// remove those itemsets who have a support count less than minSupport
map<set<string>, int> prune(const map<set<string>, int> &table, int minSupport) {

    map<set<string>, int> result;
    for (auto &itemSetRow: table) {
        if (itemSetRow.second >= minSupport) {
            result[itemSetRow.first] = itemSetRow.second;
        }
    }
    return result;
}

// check if child is a subset of parent
bool isSubsetOf(const set<string> &parent, const set<string> &child) {

    if (child.size() > parent.size()) {
        return false;
    }

    for (auto element: child) {
        if (parent.find(element) == parent.end()) {
            return false;
        }
    }
    return true;
}

// join the given table with itself
map<set<string>, int> join(const map<set<string>, int> &table, const vector<set<string>> &dataSet) {

    map<set<string>, int> result;
    
    // prepare a list of elements which need to be appended for joining
    set<string> distinctElements;
    for (auto &itemSetRow: table) {
        for (auto &element: itemSetRow.first) {
            distinctElements.insert(element);
        }
    }

    for (auto &itemSetRow: table) {

        // keep the current itemSet in a temporary set
        set<string> temp = itemSetRow.first;
        for (auto &element: distinctElements) {

            // if element already exists in temp, move ahead
            if (temp.find(element) != temp.end()) {
                continue;
            }

            // add element to temp
            temp.insert(element);

            // if this new itemset does not exist in result,
            // find the count of this itemset in the original dataSet
            if (result.find(temp) == result.end()) {

                int count = 0;
                for (int i = 0; i < dataSet.size(); ++i) {
                    if (isSubsetOf(dataSet[i], temp)) {
                        ++count;
                    }
                }
                result[temp] = count;
            }

            // remove element from temp to keep it ready for next iteration
            temp.erase(element);
        }
    }

    return result;
}


// utility function to print a table
void printTable(const map<set<string>, int> &table) {

    if (table.size() == 0) {
        cout << "We've got nothing." << endl;
        return;
    }

    cout << "Below is the table containing itemset on left" << endl;
    cout << "and its support count on right." << endl;
    for (auto &mapelement: table) {
        
        cout << "{ ";
        for (auto &element: mapelement.first) {
            cout << element << " ";
        }
        cout << "} - ";
        cout << mapelement.second << endl;
    }
}

map<set<string>, int> applyApriori(const vector<set<string>> &dataSet, int minSupport) {

    map<set<string>, int> result;

    map<set<string>, int> table = prepareFirstCountTable(dataSet);
    table = prune(table, minSupport);
    
    // if nothing exists after the first prune, result is empty
    if (table.size() == 0) {
        return table;
    }

    // keeping joining and pruning
    while (true) {

        // store this before joining
        map<set<string>, int> previousTable = table;

        table = join(table, dataSet);
        map<set<string>, int> pruned = prune(table, minSupport);

        // if nothing exists after pruning, 
        // it means the table it was pruned from did not have any itemset
        // with support count >= minSupport. so we need to go a step back,
        // and make the previous table as our result
        if (pruned.size() == 0) {
            
            result = previousTable;
            break;
        }

        // if pruned table is not empty, it means we can try further
        table = pruned;
    }
    return result;
}

int main() {

    /*
        [bread, milk]
        [bread diaper beer eggs]
        [milk diaper beer coke]
        [bread milk diaper beer]
        [bread milk diaper coke]
    */
    vector<set<string>> dataSet;
    dataSet.resize(5);
    dataSet[0].insert("bread");
    dataSet[0].insert("milk");

    dataSet[1].insert("bread");
    dataSet[1].insert("diaper");
    dataSet[1].insert("beer");
    dataSet[1].insert("eggs");

    dataSet[2].insert("milk");
    dataSet[2].insert("diaper");
    dataSet[2].insert("beer");
    dataSet[2].insert("coke");

    dataSet[3].insert("bread");
    dataSet[3].insert("milk");
    dataSet[3].insert("diaper");
    dataSet[3].insert("beer");

    dataSet[4].insert("bread");
    dataSet[4].insert("milk");
    dataSet[4].insert("diaper");
    dataSet[4].insert("coke");
    
    int minSupport = 3;
    map<set<string>, int> table = applyApriori(dataSet, minSupport);
    printTable(table);
    return 0;
}