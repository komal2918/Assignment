#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

// Logger Class
class Logger {
public:
    static void log_api_call(const string& algorithm, const string& input, const string& output) {
        ofstream logFile("logs.txt", ios::app);
        logFile << "Algorithm: " << algorithm << "\n";
        logFile << "Input: " << input << "\n";
        logFile << "Output: " << output << "\n";
        logFile << "----------------------\n";
        logFile.close();
    }
};

// Binary Search Class
class BinarySearch {
public:
    static int search(const vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};

// Quick Sort Class
class QuickSort {
public:
    static vector<int> sort(vector<int> arr) {
        if (arr.size() <= 1) return arr;
        int pivot = arr[arr.size() / 2];
        vector<int> left, middle, right;
        for (int num : arr) {
            if (num < pivot) left.push_back(num);
            else if (num == pivot) middle.push_back(num);
            else right.push_back(num);
        }
        left = sort(left);
        right = sort(right);
        left.insert(left.end(), middle.begin(), middle.end());
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};

// BFS Traversal Class
class BFS {
public:
    static vector<string> traverse(unordered_map<string, vector<string>>& graph, const string& start_node) {
        vector<string> visited;
        queue<string> q;
        unordered_map<string, bool> visited_map;
        q.push(start_node);
        while (!q.empty()) {
            string node = q.front(); q.pop();
            if (!visited_map[node]) {
                visited.push_back(node);
                visited_map[node] = true;
                for (const string& neighbor : graph[node]) {
                    if (!visited_map[neighbor]) q.push(neighbor);
                }
            }
        }
        return visited;
    }
};

// User Interaction Menu
class Menu {
public:
    static void display() {
        while (true) {
            cout << "\nSelect an operation:" << endl;
            cout << "1. Binary Search" << endl;
            cout << "2. Quick Sort" << endl;
            cout << "3. BFS Traversal" << endl;
            cout << "4. View Logs" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter choice: ";
            int choice;
            cin >> choice;

            if (choice == 1) handle_binary_search();
            else if (choice == 2) handle_quick_sort();
            else if (choice == 3) handle_bfs();
            else if (choice == 4) display_logs();
            else if (choice == 5) break;
            else cout << "Invalid choice!" << endl;
        }
    }

private:
    static void handle_binary_search() {
        cout << "Enter sorted array elements (space-separated, end with -1): ";
        vector<int> arr;
        int num, count = 0;
        bool isArrayValid = true;
        do {
            arr.clear();
            isArrayValid = true;
            while (cin >> num && num != -1) {
                arr.push_back(num);
                count++;
                if (count > 1 && arr[count - 1] < arr[count - 2]) {
                    isArrayValid = false;
                }
            }
            if (isArrayValid == false) {
                cout << "Invalid array\nPls re-enter the sorted array elements (space-separated, end with -1):";
            }
        } while(isArrayValid == false);
        cout << "Enter target value: ";
        int target;
        cin >> target;
        int index = BinarySearch::search(arr, target);
        stringstream input, output;
        input << "Array: "; for (int x : arr) input << x << " ";
        input << "| Target: " << target;
        output << "Index: " << index;
        Logger::log_api_call("Binary Search", input.str(), output.str());
        cout << output.str() << endl;
    }

    static void handle_quick_sort() {
        cout << "Enter array elements to sort (space-separated, end with -1): ";
        vector<int> arr;
        int num;
        while (cin >> num && num != -1) arr.push_back(num);
        vector<int> sorted_arr = QuickSort::sort(arr);
        stringstream input, output;
        input << "Array: "; for (int x : arr) input << x << " ";
        output << "Sorted: "; for (int x : sorted_arr) output << x << " ";
        Logger::log_api_call("Quick Sort", input.str(), output.str());
        cout << output.str() << endl;
    }

    static void handle_bfs() {
        unordered_map<string, vector<string>> graph;
        int edges;
        cout << "Enter number of edges: ";
        cin >> edges;
        cout << "Enter edges (format: node1 node2):\n";
        for (int i = 0; i < edges; ++i) {
            string u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cout << "Enter start node: ";
        string start_node;
        bool isValidStartNode;
        do {
            isValidStartNode = true;
            cin >> start_node;
            if (graph.find(start_node) == graph.end()) {
                isValidStartNode = false;
                cout << "Invalid start node. \nPls re-enter the start node : ";
            }
        } while (isValidStartNode == false);
        cin >> start_node;
        vector<string> traversal = BFS::traverse(graph, start_node);
        stringstream input, output;
        input << "Graph edges: " << edges << " | Start Node: " << start_node;
        output << "BFS Order: "; for (const auto& node : traversal) output << node << " ";
        Logger::log_api_call("BFS", input.str(), output.str());
        cout << output.str() << endl;
    }

    static void display_logs() {
        ifstream logFile("logs.txt");
        string line;
        while (getline(logFile, line)) {
            cout << line << endl;
        }
        logFile.close();
    }
};

int main() {
    Menu::display();
    return 0;
}
