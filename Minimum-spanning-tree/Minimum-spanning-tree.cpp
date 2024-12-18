﻿#include <chrono>
#include "Algorithms.h"
#include "DataGenerator.h"

using namespace std;

#define RUN(x, data) {\
    Run(#x, x, data);\
}

string dataset;

template<typename Method>
void Run(const string& method_name, Method method, vector<vector<int>>& data) {
    cout << "Запуск алгоритма: " << method_name << endl;

    vector<vector<int>> matrix = data;
    auto start = chrono::system_clock::now();
    int result = method(data);
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

    cout << "Время: " << time << " mcs" << endl;
    cout << "Вес минимального остовного дерева: " << result << endl << endl;
}


int main() {
    setlocale(LC_ALL, "ru-RU");
    vector<vector<int>> matrix;

    cout << "-------Тестирование на графе-дереве (82 вершины)-------";
    cout << "" << endl;
    matrix = GenerateData("Tree.txt");

    RUN(greedy_by_Gevorkyan, matrix);
    RUN(Kraskall_by_Vasukova, matrix);
    RUN(Prim_by_Chigladze, matrix);
    RUN(Boruvki_by_Merenkova, matrix);
    RUN(EdgeContact_by_Tishchenko, matrix);



    cout << "-------Тестирование на случайном графе (55 вершин)-------";
    cout << "" << endl;
    matrix = GenerateData("Random_Graph.txt");

    RUN(greedy_by_Gevorkyan, matrix);
    RUN(Kraskall_by_Vasukova, matrix);
    RUN(Prim_by_Chigladze, matrix);
    RUN(Boruvki_by_Merenkova, matrix);
    RUN(EdgeContact_by_Tishchenko, matrix);



    cout << "-------Тестирование на полном графе (20 вершин)-------";
    cout << "" << endl;
    matrix = GenerateData("Complete_Graph.txt");

    RUN(greedy_by_Gevorkyan, matrix);
    RUN(Kraskall_by_Vasukova, matrix);
    RUN(Prim_by_Chigladze, matrix);
    RUN(Boruvki_by_Merenkova, matrix);
    RUN(EdgeContact_by_Tishchenko, matrix);



    cout << "-------Тестирование на разреженном графе (50 вершин)-------";
    cout << "" << endl;
    matrix = GenerateData("Rareted_Graph.txt");

    RUN(greedy_by_Gevorkyan, matrix);
    RUN(Kraskall_by_Vasukova, matrix);
    RUN(Prim_by_Chigladze, matrix);
    RUN(Boruvki_by_Merenkova, matrix);
    RUN(EdgeContact_by_Tishchenko, matrix);



    cout << "-------Тестирование на графе-звезде (11 вершин)-------";
    cout << "" << endl;
    matrix = GenerateData("Star.txt");

    RUN(greedy_by_Gevorkyan, matrix);
    RUN(Kraskall_by_Vasukova, matrix);
    RUN(Prim_by_Chigladze, matrix);
    RUN(Boruvki_by_Merenkova, matrix);
    RUN(EdgeContact_by_Tishchenko, matrix);

    cout << "Нажмите Enter чтобы выйти...";
    cin.get();
    return 0;

}