#include <iostream>
#include "dynamic_array.h"
#include "double_linked_list.h"
#include "max_heap.h"
#include "red_black_tree.h"
#include "avl.h"

void research();
void test();
void array();
void list();
void heap();
void tree();
void avl();

int main() {
    int choice;
    bool error = true;
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
        std::cout << "Wybierz strukture ktora chcesz przetestowac\n1)Dynamiczna tablica\n2)lista dwukierunkowa\n3)Kopiec\n4)Drzewo czerwono-czarne\n5)Drzewo AVL\n6)Powrot" << std::endl;
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
                avl();
                break;
            case 6:
                return;
            default:
                std::cout << "Bledna wartosc" << std::endl;
                break;
        }
    }
}

void research(){
    ;
}

void array(){
    int choice;
    int size;
    int temp;
    int index;
    bool run = true;
    dynamic_array* test;

    //Menu for creating array

    while (run){
        std::cout << "Wybierz dzialanie (tworzenie tablicy):\n1)Stworz tablice z pliku\n2)Stworz tablice losowo\n3)Powrot" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                //TODO zrob obsluge plikow
                break;
            case 2:
                std::cout << "Wpisz wielkosc tablicy";
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
            // Searching at specified index
            case 7:
                std::cout << "Podaj indeks" << std::endl;
                std::cin >> index;
                test->select(index);
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
    int index;
    bool run = true;
    double_linked_list* test;

    //Menu for creating array

    while (run){
        std::cout << "Wybierz dzialanie (tworzenie listy):\n1)Stworz liste z pliku\n2)Stworz liste losowo\n3)Powrot" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                //TODO zrob obsluge plikow
                break;
            case 2:
                std::cout << "Wpisz wielkosc tablicy";
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

    //Menu for array testing

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
                std::cout << "Podaj indeks" << std::endl;
                std::cin >> index;
                test->select(index);
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

void avl(){
    int choice;
    int size;
    int* temp;
    int value;
    bool run = true;
    class avl* test;

    //Menu for creating avl tree

    while (run){
        std::cout << "Wybierz dzialanie (tworzenie drzeva avl):\n1)Stworz drzewo z pliku\n2)Stworz drzewo losowo\n3)Powrot" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                //TODO zrob obsluge plikow
                break;
            case 2:
                std::cout << "Wpisz wielkosc drzewa";
                std::cin >> size;
                test = new class avl(size);
                run = false;
                break;
            case 3:
                return;
            default:
                std::cout << "Bledna wartosc";
                break;
        }
    }

    //Menu for avl tree testing

    while (true){
        std::cout << "Wybierz dzialanie (drzewo avl):\n1)Dodaj\n2)Usun\n3)Wyszukaj\n4)Pokaz\n5)Powrot" << std::endl;
        std::cin >> choice;
        switch (choice) {
            // Adding
            case 1:
                std::cout << "Podaj wartosc do dodania" << std::endl;
                std::cin >> value;
                test->add(value);
                break;
            //Deleting
            case 2:
                std::cout << "Podaj wartosc do usuniecia" << std::endl;
                std::cin >> value;
                test->remove(value);
                break;

            // Searching specified value
            case 3:
                std::cout << "Podaj wartosc" << std::endl;
                std::cin >> value;
                temp = test->select(value);
                if (temp) {
                    std::cout << temp << " " << *temp << std::endl;
                }
                break;
            // Showing the avl tree
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

void tree(){
    int choice;
    int size;
    int * temp;
    int value;
    bool run = true;
    red_black_tree* test;

    //Menu for creating rb tree

    while (run){
        std::cout << "Wybierz dzialanie (tworzenie drzewa czerwono-czarnego):\n1)Stworz drzewo z pliku\n2)Stworz drzewo losowo\n3)Powrot" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                //TODO zrob obsluge plikow
                break;
            case 2:
                std::cout << "Wpisz wielkosc drzewa";
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
                std::cout << temp << " " << *temp << std::endl;
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
    max_heap* test;

    //Menu for creating heap

    while (run){
        std::cout << "Wybierz dzialanie (tworzenie kopca):\n1)Stworz kopiec z pliku\n2)Stworz kopiec losowo\n3)Powrot" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                //TODO zrob obsluge plikow
                break;
            case 2:
                std::cout << "Wpisz wielkosc kopca";
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
                std::cout << temp << " " << *temp << std::endl;
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