#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Train {
    std::string place;
    int trainNumber;
    float departureTime;
};

int main() 
{
    setlocale(LC_ALL, "Russian");
    const int SIZE = 10;
    Train trains[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "\nEntering data for train " << (i + 1) << "\n";
        cout << "--------------------------------\n";
        cout << "Enter the train number: ";
        cin >> trains[i].trainNumber;
        
        cout << "Enter the city name: ";
        cin.ignore();
        getline(cin, trains[i].place);
        while (trains[i].place.empty()) {
            cout << "City name cannot be empty! Enter again: ";
            getline(cin, trains[i].place);
        }

        cout << "Enter the departure time: ";
        cin >> trains[i].departureTime;
    }

    for(int i = 0; i< SIZE;i ++){
        for (int j = i +1; j < SIZE;j++){
            if (trains[i].trainNumber > trains[j].trainNumber){
                swap(trains[i],trains[j]);
            }
        }
    }

 
    for(int i = 0; i < SIZE; i++) {
        cout << "\nПоезд #" << (i + 1) << ":" 
             << "\n Номер поезда: " << trains[i].trainNumber 
             << "\n Город: " << trains[i].place 
             << "\n Время отправления: " << trains[i].departureTime 
             << "\n------------------" << endl;
    }

    return 0;
}