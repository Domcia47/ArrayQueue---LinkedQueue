#include <iostream>
#include <vector>
#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"

int vectormaxcyfr(std::vector<int> &v){//funkcja obliczająca największą ilość cyfr elementu wektora
    int max = 0;
    int l_cyfr =0;
    for (auto it = v.begin(); it != v.end(); ++it) {
        int element = *it;
        
        if(element>max){
            max = element; //wyznaczenie największego elementu wektora
        }
    }
     while (max)
    {
        max = max /10; //dzielimy całkowicie przez 10 aż osiągnie 0
        l_cyfr++;
    }
    return l_cyfr;
}

void radix(std::vector<int> &v){//funkcja sortujaca

    int maxcyfr = vectormaxcyfr(v); //obbliczenie maksyamlanej ilości cyfr w wektorze
    ArrayQueue<int> kolejki[10]; //utworzenie 10 kolejek
    //LinkedQueue<int> kolejki[10]
    int dzielenie = 1;
    for(int i =0;i<maxcyfr;i++){
        
        for (auto it = v.begin(); it != v.end(); ++it) {
            int element = *it;
            int cyfra;
            cyfra = (element/dzielenie)%10; //obliczanie kolejnych cyfr
            kolejki[cyfra].push(element); //umieszczenie w odpowiedniej kolejce w zależności od cyfry
        }
        v.clear(); //wyczyszczenie wektora
        
        for(int i =0; i<10;i++){
            while(!kolejki[i].empty()){
                int element = kolejki[i].pop();
                v.push_back(element);//wpisanie elementów ze wszytskich kolejek do wektora
            }
        }

        dzielenie*=10;
    }

   
}



int main(){

    int x;
    std::vector<int> v;
    while(std::cin >> x) 
        v.push_back(x); //wczytywanie do wektora do końca danych
    radix(v); //wywołanie funkcji sortującej
    for(const auto& i : v) 
        std::cout << i << std::endl; //wypisanie posortowanego wektora
    
}