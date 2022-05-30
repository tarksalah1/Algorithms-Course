//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <thread>
//#include "naive_inversion.hpp"
//#include "dandsQ_inversion.hpp"
//using namespace std;
//
//
///**
// * driving stress test for both algorithms
// *
// * generate a 1d-vector with fixed size 128*128
// * compare their output and runnig time
//*/
//int main(int argc, char** argv)
//{
//    int naive_result, dandq_result;
//    int n;
//    cout << "enter Array Size :";
//    cin >> n;
//    int* Array = new int[n];
//    int values;
//    int i = 0;
//    while (true) {
//        cout << "enter " << i << "- Value : ";
//        cin >> Array[i];
//        cout << endl;
//        if (i < n - 1) {
//            i++;
//            continue;
//        }
//        else break;
//    }
//
//    while (true)
//    {
//
//        auto naive_start = std::chrono::high_resolution_clock::now();
//        naive_result = getInvCount(Array, n);
//        auto naive_finish = std::chrono::high_resolution_clock::now();
//
//        auto dandq_start = std::chrono::high_resolution_clock::now();
//        dandq_result = mergeSort(Array, n);
//        auto dandq_finish = std::chrono::high_resolution_clock::now();
//
//        auto naive_time = (naive_finish - naive_start).count();
//        auto dandq_time = (dandq_finish - dandq_start).count();
//
//        if (dandq_result == naive_result)
//        {
//            cout << "equivalent " << endl;
//            cout << "naive_time ==> " << naive_time << endl;
//            cout << "dandq_time ==> " << dandq_time << endl;
//            cout << "performance enhancment ==> " << float(naive_time) / dandq_time << endl;
//            cout << dandq_result << endl;
//            break;
//        }
//        else
//        {
//            cout << "error, check your inputs and algortihms " << endl;
//            // you may want to store your variables in a file to re-run the test on the same inputs;
//            break;
//        }
//    }
//    return 0;
//}