#include <iostream>
#include <fstream>
#include <windows.h>
#include "dynamic_array.h"
#include "double_linked_list.h"
#include "max_heap.h"
#include "red_black_tree.h"

void research();
void test();
void array();
void list();
void heap();
void tree();


int main() {
    int choice;
    bool error = true;
    std::fstream f;
    std::string path = "../txt_files/array.txt";
    f.open(path,std::ios::out);
    f << "uwu" << error << ' ' << "lol" << '\n' << "aaaa" << std::endl << "xD";
    f.close();

    while (error) {
        std::cout << "Wybierz funkcjonalnosc programu:\n1)Badania\n2)Testowanie funkcjonalnosci" << std::endl;

        std::cin >> choice;
        std::cout << std::endl;

        switch (choice) {
            case 1:
                research();
                error = false;
                break;
            case 2:
                test();
                error = false;
                break;
            default:
                std::cout << "Bledna wartosc" << std::endl;
                break;

        }
    }
    return 0;
}

void test(){
    int choice;
    while (true){
        std::cout << "Wybierz strukture ktora chcesz przetestowac\n1)Dynamiczna tablica\n2)lista dwukierunkowa\n3)Kopiec\n4)Drzewo czerwono-czarne\n5)Wyjscie" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                array();
                break;
            case 2:
                list();
                break;
            case 3:
                heap();
                break;
            case 4:
                tree();
                break;
            case 5:
                return;
            default:
                std::cout << "Bledna wartosc" << std::endl;
                break;
        }
    }
}

void array_research(){
    //setup
    const int number_of_tests = 100;
    int sizes []= {100,200, 500, 700, 1000, 2000, 5000, 7000, 10000};
    int size, value, index;
    long double times [7] = {0,0,0,0,0,0,0};
    long double elapsed_time_double;
    LARGE_INTEGER start_time, end_time, elapsed_time, frequency;
    dynamic_array* research_array;
    std::fstream f;
    std::string path = "../txt_files/array.txt";

    QueryPerformanceFrequency(&frequency);

    f.open(path,std::ios::out);
    f.close();

    //main loop with sizes
    for (int i = 0; i < 9; ++i) {
        //main loop setup
        size = sizes[i];

        //add_back loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new dynamic_array(size);
            value = rand();
            QueryPerformanceCounter(&start_time);
            research_array->add_back(value);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[0] += elapsed_time_double;
        }
        times[0] /= number_of_tests;

        //add_front loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new dynamic_array(size);
            value = rand();

            QueryPerformanceCounter(&start_time);
            research_array->add_front(value);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[1] += elapsed_time_double;
        }
        times[1] /= number_of_tests;

        //add loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new dynamic_array(size);
            value = rand();
            index = rand()%size;

            QueryPerformanceCounter(&start_time);
            research_array->add(value,index);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[2] += elapsed_time_double;
        }
        times[2] /= number_of_tests;

        //delete_front loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new dynamic_array(size);

            QueryPerformanceCounter(&start_time);
            research_array->delete_front();
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[3] += elapsed_time_double;
        }
        times[3] /= number_of_tests;

        //delete_back loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new dynamic_array(size);

            QueryPerformanceCounter(&start_time);
            research_array->delete_back();
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[4] += elapsed_time_double;
        }
        times[4] /= number_of_tests;

        //delete_with_index loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new dynamic_array(size);
            index = rand()%size;

            QueryPerformanceCounter(&start_time);
            research_array->delete_with_index(rand()%size);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[5] += elapsed_time_double;
        }
        times[5] /= number_of_tests;

        //search loop
        int value;
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new dynamic_array(size);
            value = rand();

            QueryPerformanceCounter(&start_time);
            research_array->select(value);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[6] += elapsed_time_double;
        }
        times[6] /= number_of_tests;

        // writing to file

        f.open(path,std::ios::app);
        f << size << ' ' << times[0] << ' ' << times[1] << ' ' << times[2] << ' '<< times[3] << ' '<< times[4] << ' '<< times[5] << ' '<< times[6] << ' ' << std::endl;
        f.close();
    }

}

void list_research(){
    //setup
    const int number_of_tests = 100;
    int sizes []= {100,200, 500, 700, 1000, 2000, 5000, 7000, 10000};
    int size, index, value;
    long double times [7] = {0,0,0,0,0,0,0};
    long double elapsed_time_double;
    LARGE_INTEGER start_time, end_time, elapsed_time, frequency;
    double_linked_list* research_array;
    std::fstream f;
    std::string path = "../txt_files/list.txt";

    QueryPerformanceFrequency(&frequency);

    f.open(path,std::ios::out);
    f.close();

    //main loop with sizes
    for (int i = 0; i < 9; ++i) {
        //main loop setup
        size = sizes[i];

        //add_back loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new double_linked_list(size);
            value = rand();
            QueryPerformanceCounter(&start_time);
            research_array->add_back(value);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[0] += elapsed_time_double;
        }
        times[0] /= number_of_tests;

        //add_front loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new double_linked_list(size);
            value = rand();

            QueryPerformanceCounter(&start_time);
            research_array->add_front(value);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[1] += elapsed_time_double;
        }
        times[1] /= number_of_tests;

        //add loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new double_linked_list(size);
            value = rand();
            index = rand()%size;

            QueryPerformanceCounter(&start_time);
            research_array->add(value,index);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[2] += elapsed_time_double;
        }
        times[2] /= number_of_tests;

        //delete_front loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new double_linked_list(size);

            QueryPerformanceCounter(&start_time);
            research_array->delete_front();
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            f.open("../txt_files/lisat.txt",std::ios::app);
            f << size << ' ' << j << ' ' << elapsed_time_double << std::endl;
            f.close();
            times[3] += elapsed_time_double;
        }
        times[3] /= number_of_tests;

        //delete_back loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new double_linked_list(size);

            QueryPerformanceCounter(&start_time);
            research_array->delete_back();
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[4] += elapsed_time_double;
        }
        times[4] /= number_of_tests;

        //delete_with_index loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new double_linked_list(size);
            index = rand()%size;

            QueryPerformanceCounter(&start_time);
            research_array->delete_with_index(index);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[5] += elapsed_time_double;
        }
        times[5] /= number_of_tests;

        //search loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new double_linked_list(size);
            value = rand();
            QueryPerformanceCounter(&start_time);
            research_array->select(value);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[6] += elapsed_time_double;
        }
        times[6] /= number_of_tests;

        // writing to file

        f.open(path,std::ios::app);
        f << size << ' ' << times[0] << ' ' << times[1] << ' ' << times[2] << ' '<< times[3] << ' '<< times[4] << ' '<< times[5] << ' '<< times[6] << ' ' << std::endl;
        f.close();
    }

}

void heap_research(){
    //setup
    const int number_of_tests = 100;
    int sizes []= {100,200, 500, 700, 1000, 2000, 5000, 7000, 10000};
    int size;
    int value;
    long double times [3] = {0,0,0};
    long double elapsed_time_double;
    LARGE_INTEGER start_time, end_time, elapsed_time, frequency;
    max_heap* research_array;
    std::fstream f;
    std::string path = "../txt_files/heap.txt";

    QueryPerformanceFrequency(&frequency);

    f.open(path,std::ios::out);
    f.close();

    //main loop with sizes
    for (int i = 0; i < 9; ++i) {
        //main loop setup
        size = sizes[i];

        //add loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new max_heap(size);
            value = rand();

            QueryPerformanceCounter(&start_time);
            research_array->add(value);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[0] += elapsed_time_double;
        }
        times[0] /= number_of_tests;

        //delete loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new max_heap(size);

            QueryPerformanceCounter(&start_time);
            research_array->delete_root();
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[1] += elapsed_time_double;
        }
        times[1] /= number_of_tests;

        //search loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new max_heap(size);
            value = rand();

            QueryPerformanceCounter(&start_time);
            research_array->search(value);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[2] += elapsed_time_double;
        }
        times[2] /= number_of_tests;

        // writing to file

        f.open(path,std::ios::app);
        f << size << ' ' << times[0] << ' ' << times[1] << ' ' << times[2] << ' ' << std::endl;
        f.close();
    }

}

void rb_tree_research(){
    //setup
    const int number_of_tests = 100;
    int sizes []= {100,200, 500, 700, 1000, 2000, 5000, 7000, 10000};
    int size, value;
    long double times [3] = {0,0,0};
    long double elapsed_time_double;
    LARGE_INTEGER start_time, end_time, elapsed_time, frequency;
    red_black_tree* research_array;
    std::fstream f;
    std::string path = "../txt_files/rb.txt";

    QueryPerformanceFrequency(&frequency);

    f.open(path,std::ios::out);
    f.close();

    //main loop with sizes
    for (int i = 0; i < 9; ++i) {
        //main loop setup
        size = sizes[i];

        //add loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new red_black_tree(size);
            value = rand();
            QueryPerformanceCounter(&start_time);
            research_array->add(value);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[0] += elapsed_time_double;
        }
        times[0] /= number_of_tests;

        //delete loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new red_black_tree(size);
            value = rand();
            QueryPerformanceCounter(&start_time);
            research_array->deleteNode(value);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[1] += elapsed_time_double;
        }
        times[1] /= number_of_tests;

        //search loop
        for (int j = 0; j < number_of_tests; ++j) {
            research_array = new red_black_tree(size);
            value = rand();

            QueryPerformanceCounter(&start_time);
            research_array->select(value);
            QueryPerformanceCounter(&end_time);

            elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
            elapsed_time_double = static_cast<long double>(elapsed_time.QuadPart);
            elapsed_time_double *= 1000000000; // result in nanoseconds
            elapsed_time_double /= frequency.QuadPart;

            times[2] += elapsed_time_double;
        }
        times[2] /= number_of_tests;

        // writing to file

        f.open(path,std::ios::app);
        f << size << ' ' << times[0] << ' ' << times[1] << ' ' << times[2] << ' ' << std::endl;
        f.close();
    }

}

void research(){
    array_research();
    list_research();
    heap_research();
    rb_tree_research();
}

void array(){
    int choice;
    int size;
    int temp;
    int* temp_p;
    int index;
    std::string file;
    bool run = true;
    dynamic_array* test;

    //Menu for creating array

    while (run){
        std::cout << "Wybierz dzialanie (tworzenie tablicy):\n1)Stworz tablice z pliku\n2)Stworz tablice losowo\n3)Powrot" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Podaj nazwe pliku w folderze \"input_files\"" << std::endl;
                std::cin >> file;
                test = new dynamic_array(file);
                run = false;
                break;
            case 2:
                std::cout << "Wpisz wielkosc tablicy" <<std::endl;
                std::cin >> size;
                test = new dynamic_array(size);
                run = false;
                break;
            case 3:
                return;
            default:
                std::cout << "Bledna wartosc";
                break;
        }
    }

    //Menu for array testing

    while (true){
        std::cout << "Wybierz dzialanie (tablica):\n1)Dodaj na poczatek\n2)Dodaj na koniec\n3)Dodaj (indeks)\n4)Usun z przodu\n5)Usun z konca\n6)Usun(indeks)\n7)Wyszukaj\n8)Pokaz\n9)Powrot" << std::endl;
        std::cin >> choice;
        switch (choice) {
            // Adding at front of the array
            case 1:
                std::cout << "Podaj wartosc do dodania" << std::endl;
                std::cin >> temp;
                test->add_front(temp);
                break;
            // Adding at back of the array
            case 2:
                std::cout << "Podaj wartosc do dodania" << std::endl;
                std::cin >> temp;
                test->add_back(temp);
                break;
            // Adding at specified index
            case 3:
                std::cout << "Podaj wartosc do dodania" << std::endl;
                std::cin >> temp;
                std::cout << "Podaj indeks" << std::endl;
                std::cin >> index;
                test->add(temp,index);
                break;
            // Delete from front of the array
            case 4:
                test->delete_front();
                break;
            // Delete from back of the array
            case 5:
                test->delete_back();
                break;
            // Delete from specified index
            case 6:
                std::cout << "Podaj indeks" << std::endl;
                std::cin >> index;
                test->delete_with_index(index);
                break;
            // Searching value
            case 7:
                std::cout << "Podaj wartosc" << std::endl;
                std::cin >> index;
                temp_p = test->select(index);
                if (temp_p){
                    std::cout << temp_p << ' ' << *temp_p << std::endl;
                }else{
                    std::cout << "Nie ma takiego elementu w tej tablicy" << std::endl;
                }
                break;
            // Showing the array
            case 8:
                test->show();
                break;
            // Exiting from menu
            case 9:
                delete test;
                return;
            // Catching invalid input
            default:
                std::cout << "Bledna wartosc" << std::endl;
                break;
        }
    }
}

void list(){
    int choice;
    int size;
    int temp;
    int* temp_p;
    int index;
    bool run = true;
    std::string file;
    double_linked_list* test;

    //Menu for creating array

    while (run){
        std::cout << "Wybierz dzialanie (tworzenie listy):\n1)Stworz liste z pliku\n2)Stworz liste losowo\n3)Powrot" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Podaj nazwe pliku w folderze \"input_files\"" << std::endl;
                std::cin >> file;
                test = new double_linked_list(file);
                run = false;
                break;
            case 2:
                std::cout << "Wpisz wielkosc listy"<<std::endl;
                std::cin >> size;
                test = new double_linked_list(size);
                run = false;
                break;
            case 3:
                return;
            default:
                std::cout << "Bledna wartosc";
                break;
        }
    }

    //Menu for list testing

    while (true){
        std::cout << "Wybierz dzialanie (lista):\n1)Dodaj na poczatek\n2)Dodaj na koniec\n3)Dodaj (indeks)\n4)Usun z przodu\n5)Usun z konca\n6)Usun(indeks)\n7)Wyszukaj\n8)Pokaz\n9)Powrot" << std::endl;
        std::cin >> choice;
        switch (choice) {
            // Adding at the front of the list
            case 1:
                std::cout << "Podaj wartosc do dodania" << std::endl;
                std::cin >> temp;
                test->add_front(temp);
                break;
            // Adding at the back of the list
            case 2:
                std::cout << "Podaj wartosc do dodania" << std::endl;
                std::cin >> temp;
                test->add_back(temp);
                break;
            // Adding at the specified index
            case 3:
                std::cout << "Podaj wartosc do dodania" << std::endl;
                std::cin >> temp;
                std::cout << "Podaj indeks" << std::endl;
                std::cin >> index;
                test->add(temp,index);
                break;
            // Deleting from front of the list
            case 4:
                test->delete_front();
                break;
            // Deleting from back of the list
            case 5:
                test->delete_back();
                break;
            // Deleting from index
            case 6:
                std::cout << "Podaj indeks" << std::endl;
                std::cin >> index;
                test->delete_with_index(index);
                break;
            // Searching with index
            case 7:
                std::cout << "Podaj wartosc" << std::endl;
                std::cin >> index;
                temp_p = test->select(index);
                if (temp_p){
                    std::cout << temp_p << ' ' << *temp_p << std::endl;
                }else{
                    std::cout << "Taka wartosc nie istnieje w tej liscie" << std::endl;
                }
                break;
            // Showing the list
            case 8:
                test->show();
                break;
            // Exiting the menu
            case 9:
                delete test;
                return;
            // Catching invalid input
            default:
                std::cout << "Bledna wartosc" << std::endl;
                break;
        }
    }

}

void tree(){
    int choice;
    int size;
    int * temp;
    int value;
    bool run = true;
    std::string file;
    red_black_tree* test;

    //Menu for creating rb tree

    while (run){
        std::cout << "Wybierz dzialanie (tworzenie drzewa czerwono-czarnego):\n1)Stworz drzewo z pliku\n2)Stworz drzewo losowo\n3)Powrot" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Podaj nazwe pliku w folderze \"input_files\"" << std::endl;
                std::cin >> file;
                test = new red_black_tree(file);
                run = false;
                break;
            case 2:
                std::cout << "Wpisz wielkosc drzewa"<<std::endl;
                std::cin >> size;
                test = new red_black_tree(size);
                run = false;
                break;
            case 3:
                return;
            default:
                std::cout << "Bledna wartosc";
                break;
        }
    }

    //Menu for rb tree  testing

    while (true){
        std::cout << "Wybierz dzialanie (drzewo czerwono-czarne):\n1)Dodaj\n2)Usun\n3)Wyszukaj\n4)Pokaz\n5)Powrot" << std::endl;
        std::cin >> choice;
        switch (choice) {
            // Adding
            case 1:
                std::cout << "Podaj wartosc do dodania" << std::endl;
                std::cin >> value;
                test->add(value);
                break;
            // Deleting
            case 2:
                std::cout << "Podaj wartosc do usuniecia" << std::endl;
                std::cin >> value;
                test->deleteNode(value);
                break;

            // Searching specified value
            case 3:
                std::cout << "Podaj wartosc" << std::endl;
                std::cin >> value;
                temp = test->select(value);
                if (temp != &test->NIL->data){
                    std::cout << temp << " " << *temp << std::endl;
                }else{
                    std::cout << "Nie znaleziono wartosci w drzewie" << std::endl;
                }

                break;
            // Showing the tree
            case 4:
                test->show();
                break;
            // Exiting from menu
            case 5:
                delete test;
                return;
            // Catching invalid input
            default:
                std::cout << "Bledna wartosc" << std::endl;
                break;
        }
    }


}

void heap(){
    int choice;
    int size;
    int* temp;
    int value;
    bool run = true;
    std::string file;
    max_heap* test;

    //Menu for creating heap

    while (run){
        std::cout << "Wybierz dzialanie (tworzenie kopca):\n1)Stworz kopiec z pliku\n2)Stworz kopiec losowo\n3)Powrot" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Podaj nazwe pliku w folderze \"input_files\"" << std::endl;
                std::cin >> file;
                test = new max_heap(file);
                run = false;
                break;
            case 2:
                std::cout << "Wpisz wielkosc kopca"<<std::endl;
                std::cin >> size;
                test = new max_heap(size);
                run = false;
                break;
            case 3:
                return;
            default:
                std::cout << "Bledna wartosc";
                break;
        }
    }

    //Menu for heap testing

    while (true){
        std::cout << "Wybierz dzialanie (heap):\n1)Dodaj\n2)Usun korzen\n3)Wyszukaj\n4)Pokaz\n5)Powrot" << std::endl;
        std::cin >> choice;
        switch (choice) {
            // Adding
            case 1:
                std::cout << "Podaj wartosc do dodania" << std::endl;
                std::cin >> value;
                test->add(value);
                break;
            case 2:
                test->delete_root();
                break;

                // Searching specified value
            case 3:
                std::cout << "Podaj wartosc" << std::endl;
                std::cin >> value;
                temp = test->search(value);
                if(!temp){
                    std::cout << "Nie znaleziono takiej wartosci w kopcu" << std::endl;
                }else{
                    std::cout << temp << " " << *temp << std::endl;
                }

                break;
                // Showing the heap
            case 4:
                test->show();
                break;
                // Exiting from menu
            case 5:
                delete test;
                return;
                // Catching invalid input
            default:
                std::cout << "Bledna wartosc" << std::endl;
                break;
        }
    }

}