//
// Created by General on 20.08.2020.
//


#include <iostream>
#include <fstream>
#include <profile.h>
using namespace std;

// To break the link between cin and cout use cin.tie(nullptr)!!!!

// Also use ios_base::sync_with_stdio(false);
// call BEFORE first input or output!!!
// it will speed up program's input anf output about 20-30%

int main() {
    // It will speed up program input and output
    ios_base::sync_with_stdio(false);

    // ofstream and other Ostreams stores data in buffre and
    // AFTER buffer OVERFLOW puts it from buffer to screen or file.
    // endl manipulator FLUSHES the buffer immediately

    // endl should be used when time is not critical (TESTS)
    // or we need IMMEDIATE output (Logs or errors in DEBUG)

    // If speed is critical or whole output is important use '\n'
    // Tasks like stdin -> stdout or console apps
    // To break the link between cin and cout use cin.tie(nullptr)!!!!

    //

    // First part
    {
        LOG_DURATION("endl");
        ofstream out("output.txt");
        for (int i = 0; i < 150000; ++i) {
            out << "London is the capital of Great Britain." << endl;
        }
        out.close();
    }
    {
        LOG_DURATION("'\\n'");
        ofstream out("output.txt");
        for (int i = 0; i < 150000; ++i) {
            out << "London is the capital of Great Britain." << '\n';
        }
        out.close();
    }


    // Second part

    // It is somewhere in cmake-build-debug
    // run in console: iostream_buffering.exe < io_input.txt > io_output.txt

    // Results are VERY close (386 VS 372) because
    // cout and cerr linked with cin
    // Before every cin gets data, cout and cerr flushes the buffer

    // To break the link use cin.tie(nullptr)
    // After that we have: 358 ms VS 80 ms
//    {
//        LOG_DURATION("endl");
//        for (int i = 0; i < 100000; ++i) {
//            int x;
//            cin >> x;
//            cout << x << endl;
//        }
//    }
//    {
//        LOG_DURATION("'\\n'");
//        for (int i = 0; i < 100000; ++i) {
//            int x;
//            cin >> x;
//            cout << x << '\n';
//        }
//    }

    cin.tie(nullptr);
    cout << "Enter two integers: ";
    int x, y;
    // cout and cerr linked with cin
    // Before every cin gets data, cout and cerr flushes

    // To break the link use cin.tie(nullptr)
    // If we don't have cin then cout would be buffered
    cin >> x >> y;


    return 0;
}