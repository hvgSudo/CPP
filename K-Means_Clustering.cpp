#include <bits/stdc++.h>

using namespace std;

// describe how a Cluster looks like
struct Cluster {

    set<pair<double, double>> elements;
    pair<double, double> centroid;
    double squareError;
};

void computeCentroid(Cluster &cluster) {

    pair<double, double> result;
    result.first = 0.0;
    result.second = 0.0;

    for (auto element: cluster.elements) {

        result.first += element.first;
        result.second += element.second;
    }

    result.first = result.first / (double)(cluster.elements.size());
    result.second = result.second / (double)(cluster.elements.size());

    cluster.centroid = result;
}

void computeSquareError(Cluster &cluster) {

    double result = 0.0;

    for (auto element: cluster.elements) {

        result += ((element.first - cluster.centroid.first) * (element.first - cluster.centroid.first));
        result += ((element.second - cluster.centroid.second) * (element.second - cluster.centroid.second));
    }

    cluster.squareError = result;
}

// check if child is subset of parent
bool isSubsetOf(const set<pair<double, double>> &parent, const set<pair<double, double>> &child) {

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

double computeTotalSquareError(vector<Cluster> &clusters) {

    double result;
    for (auto cluster: clusters) {
        result += cluster.squareError;
    }
    return result;
}

double computeDistance(pair<double, double> a, pair<double, double> b) {

    double x = a.first - b.first;
    double y = a.second - b.second;
    return sqrt((x*x) + (y*y));
}

// take all the elements and create a new list of clusters
// depending upon the distance between the cluster's centroid
// and the element
vector<Cluster> reAssign(vector<Cluster> &clusters) {

    vector<Cluster> result(clusters.size());

    for (int i = 0; i < result.size(); ++i) {
        result[i].centroid = clusters[i].centroid;
        result[i].squareError = clusters[i].squareError;
    }

    for (auto cluster: clusters) {
        for (auto element: cluster.elements) {

            int minIndex = 0;
            double minDistance = 99999999999999.99999;

            for (int i = 0; i < clusters.size(); ++i) {
                double distance = computeDistance(element, clusters[i].centroid);
                if (distance < minDistance) {
                    minDistance = distance;
                    minIndex = i;
                }
            }
            result[minIndex].elements.insert(element);
        }
    }

    return result;
}

// check if two lists of clusters are same
bool areTheySame(vector<Cluster> &oldClusters, vector<Cluster> &newClusters) {

    for (auto cluster : newClusters) {

        bool exists = false;
        // check if this cluster exists in newCluster
        for (auto compareWith: oldClusters) {
            bool match = isSubsetOf(cluster.elements, compareWith.elements) && isSubsetOf(compareWith.elements, cluster.elements);
            if (match) {
                exists = true;
            }            
        }
        if (!exists) {
            return false;
        }
    }
    return true;
}

void applyKMeans(vector<pair<double, double>> elements, int k) {

    // make K clusters
    vector<Cluster> clusters(k);
    int initialClusterSize = elements.size() / k;
    int clusterPointer = 0;

    int j = 0;
    for (int i = 0; i < k; ++i) {
        while (clusters[i].elements.size() < initialClusterSize) {
            clusters[i].elements.insert(elements[j]);
            ++j;
        }
    }
    int lastCluster = clusters.size() - 1;
    while (j < elements.size()) {
        clusters[lastCluster].elements.insert(elements[j]);
        ++j;
    }

    cout << "INITIAL CLUSTERS" << endl;
    for (auto cluster: clusters) {
        for (auto element: cluster.elements) {
            cout << "(" << element.first << "," << element.second << ") ";
        }
        cout << endl;
    }

    cout << endl;
    while (true) {

        cout << "NEW ITERATION" << endl;
        // for each set, compute centroid and square error
        for (int i = 0; i < clusters.size(); ++i) {
            computeCentroid(clusters[i]);
            computeSquareError(clusters[i]);
        }

        // find total square error and print it
        cout << "TOTAL SQUARE ERROR : " << computeTotalSquareError(clusters) << endl;

        // re-assign
        vector<Cluster> newClusters = reAssign(clusters);

        // compare reassignment with previous assignment
        if (areTheySame(newClusters, clusters)) {
            break;
        }

        clusters = newClusters;
    }

    cout << endl;
    cout << "FINAL CLUSTERS" << endl;
    for (auto cluster: clusters) {
        for (auto element: cluster.elements) {
            cout << "(" << element.first << "," << element.second << ") ";
        }
        cout << endl;
    }
}


int main() {

    pair<double, double> one = make_pair(1, 0);
    pair<double, double> two = make_pair(2, 1);
    pair<double, double> three = make_pair(0, 1);
    pair<double, double> four = make_pair(3, 3);

    vector<pair<double, double>> elements{one, two, three, four};

    applyKMeans(elements, 2);
    return 0;
}