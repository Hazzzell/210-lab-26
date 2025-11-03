
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

int main() {
    string fileName = "codes.txt";

    vector<string> v;
    list<string> l;
    set<string> s;

    cout << "Measurement in Microseconds: " << endl;
    cout << setw(10) << "Operation" 
         << setw(10) << "Vector"
         << setw(10) << "List" 
         << setw(10) << "Set" << endl;

    // first race: READING
    auto start = high_resolution_clock::now();
    ifstream f1(fileName); string code;
    while(f1 >> code) v.push_back(code);
    f1.close();
    auto end = high_resolution_clock::now();
    long long v_read = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    ifstream f2(fileName);
    while(f2 >> code) l.push_back(code);
    f2.close();
    end = high_resolution_clock::now();
    long long l_read = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    ifstream f3(fileName);
    while(f3 >> code) s.insert(code);
    f3.close();
    end = high_resolution_clock::now();
    long long s_read = duration_cast<microseconds>(end - start).count();

    cout << setw(10) << "Read" 
         << setw(10) << v_read 
         << setw(10) << l_read 
         << setw(10) << s_read << endl;

    // second race: SORTING
    start = high_resolution_clock::now();
    sort(v.begin(), v.end());
    end = high_resolution_clock::now();
    long long v_sort = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    l.sort();
    end = high_resolution_clock::now();
    long long l_sort = duration_cast<microseconds>(end - start).count();

    long long s_sort = -1; // set is already sorted
    cout << setw(10) << "Sort" 
         << setw(10) << v_sort 
         << setw(10) << l_sort 
         << setw(10) << s_sort << endl;

    // third race: INSERTING
    start = high_resolution_clock::now();
    v.insert(v.begin() + v.size()/2, "TESTCODE");
    end = high_resolution_clock::now();
    long long v_ins = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    auto itl = l.begin(); advance(itl, l.size()/2); l.insert(itl, "TESTCODE");
    end = high_resolution_clock::now();
    long long l_ins = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    s.insert("TESTCODE");
    end = high_resolution_clock::now();
    long long s_ins = duration_cast<microseconds>(end - start).count();

    cout << setw(10) << "Insert"
         << setw(10) << v_ins 
         << setw(10) << l_ins 
         << setw(10) << s_ins << endl;

    // fourth race: DELETING
    start = high_resolution_clock::now();
    v.erase(v.begin() + v.size()/2);
    end = high_resolution_clock::now();
    long long v_del = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    itl = l.begin(); advance(itl, l.size()/2); l.erase(itl);
    end = high_resolution_clock::now();
    long long l_del = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    auto its = s.begin(); advance(its, s.size()/2); s.erase(its);
    end = high_resolution_clock::now();
    long long s_del = duration_cast<microseconds>(end - start).count();

    cout << setw(10) << "Delete" 
         << setw(10) << v_del 
         << setw(10) << l_del 
         << setw(10) << s_del << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
   