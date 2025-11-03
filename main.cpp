// COMSC-210 | Lab 26 | Keng C Chan
// IDE used: Visual Studio Code (VS Code)
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <algorithm>
#include <iomanip>
using namespace std;
using namespace std::chrono;

const int NUM_RUNS = 15;
const int NUM_OPS = 4;      // Read, Sort, Insert, Delete
const int NUM_STRUCTS = 3;  // Vector, List, Set

int main() {
    // Seed random (if needed)
    srand(time(0));

    // 3D array: results[run][operation][structure]
    int results[NUM_RUNS][NUM_OPS][NUM_STRUCTS] = {0};
    // accumulator array for running totals
    int accum[NUM_OPS][NUM_STRUCTS] = {0};
    // names of operations (for reference)
    string ops[NUM_OPS] = {"Read", "Sort", "Insert", "Delete"};

    vector<string> names;
    ifstream infile("names.txt");
    string name;
    while (infile >> name) names.push_back(name);
    infile.close();

    list<string> l;
    set<string> s;

    cout << "Measurement in Microseconds: " << endl;
    cout << setw(10) << "Operation" 
         << setw(10) << "Vector"
         << setw(10) << "List" 
         << setw(10) << "Set" << endl;

    for (int run = 0; run < NUM_RUNS; ++run) {
        // --- Vector ---
        vector<string> v;

        auto start = high_resolution_clock::now();
        v.assign(names.begin(), names.end()); // Read
        auto end = high_resolution_clock::now();
        results[run][0][0] = duration_cast<microseconds>(end - start).count();
        accum[0][0] += results[run][0][0];

        start = high_resolution_clock::now();
        sort(v.begin(), v.end()); // Sort
        end = high_resolution_clock::now();
        results[run][1][0] = duration_cast<microseconds>(end - start).count();
        accum[1][0] += results[run][1][0];

        start = high_resolution_clock::now();
        v.push_back("NewName"); // Insert
        end = high_resolution_clock::now();
        results[run][2][0] = duration_cast<microseconds>(end - start).count();
        accum[2][0] += results[run][2][0];

        start = high_resolution_clock::now();
        v.pop_back(); // Delete
        end = high_resolution_clock::now();
        results[run][3][0] = duration_cast<microseconds>(end - start).count();
        accum[3][0] += results[run][3][0];

        // --- List ---
        list<string> l;

        start = high_resolution_clock::now();
        l.assign(names.begin(), names.end()); // Read
        end = high_resolution_clock::now();
        results[run][0][1] = duration_cast<microseconds>(end - start).count();
        accum[0][1] += results[run][0][1];

        start = high_resolution_clock::now();
        l.sort(); // Sort
        end = high_resolution_clock::now();
        results[run][1][1] = duration_cast<microseconds>(end - start).count();
        accum[1][1] += results[run][1][1];

        start = high_resolution_clock::now();
        l.push_back("NewName"); // Insert
        end = high_resolution_clock::now();
        results[run][2][1] = duration_cast<microseconds>(end - start).count();
        accum[2][1] += results[run][2][1];

        start = high_resolution_clock::now();
        l.pop_back(); // Delete
        end = high_resolution_clock::now();
        results[run][3][1] = duration_cast<microseconds>(end - start).count();
        accum[3][1] += results[run][3][1];

        // --- Set ---
        set<string> s;

        start = high_resolution_clock::now();
        for (const auto &n : names) s.insert(n); // Read
        end = high_resolution_clock::now();
        results[run][0][2] = duration_cast<microseconds>(end - start).count();
        accum[0][2] += results[run][0][2];

        results[run][1][2] = 0; // Set cannot sort
        accum[1][2] += 0;

        start = high_resolution_clock::now();
        s.insert("NewName"); // Insert
        end = high_resolution_clock::now();
        results[run][2][2] = duration_cast<microseconds>(end - start).count();
        accum[2][2] += results[run][2][2];

        start = high_resolution_clock::now();
        s.erase("NewName"); // Delete
        end = high_resolution_clock::now();
        results[run][3][2] = duration_cast<microseconds>(end - start).count();
        accum[3][2] += results[run][3][2];

    }

    return 0;
}
