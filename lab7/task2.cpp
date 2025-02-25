#include <iostream>
#include <string>

using namespace std;

enum carBrand { 
    BMW,
    Mercedes,
    Audi,
    Toyota
};
struct car { 
    carBrand brand;
    float loadCapacity;
    int passengerCount;
};

enum TrainType {
    COURIER,
    EXPRESS,
    PASSENGER
};
struct train {
    TrainType type;
    int speed;
    int numberOfCarriages;

};

enum PlaneType {
    Boeing,
    Airbus,
    Heinkel, 
    Junkers
};
struct plane {
    PlaneType type;
    int speed;
    int numberOfPassengers;
};


enum TransportType {
    CAR,
    TRAIN,
    PLANE
};


struct Transport {
    TransportType type;
    car carInfo;    
    train trainInfo;
    plane planeInfo;
};



void fillTransportDetails(Transport t) {
    int choice;
    cout << "Choose transport type:" << endl;
    cout << "1. Car" << endl;
    cout << "2. Train" << endl;
    cout << "3. Plane" << endl;
    cin >> choice;


    switch (choice) {
        case 1:
            t.type = CAR;
            cout << "Choose car brand:" << endl;
            cout << "1. BMW" << endl;
            cout << "2. Mercedes" << endl;
            cout << "3. Audi" << endl;
            cout << "4. Toyota" << endl;
            int carBrandChoice;
            cin >> carBrandChoice;
            t.carInfo.brand = static_cast<carBrand>(carBrandChoice - 1);
            //Это операция приведения типа в C++. Она преобразует результат carBrandChoice - 1 в тип enum carBrand
            cout << "Enter load capacity:" << endl;
            cin >> t.carInfo.loadCapacity;

            cout << "Enter passenger count:" << endl;
            cin >> t.carInfo.passengerCount;
            break;

        case 2:
            t.type = TRAIN;
            cout << "Choose train type:" << endl;
            cout << "1. Courier" << endl;
            cout << "2. Express" << endl;
            cout << "3. Passenger" << endl;
            int trainTypeChoice;
            cin >> trainTypeChoice;
            t.trainInfo.type = static_cast<TrainType>(trainTypeChoice - 1);

            cout << "Enter speed:" << endl;
            cin >> t.trainInfo.speed;

            cout << "Enter number of carriages:" << endl;
            cin >> t.trainInfo.numberOfCarriages;
            break;

        case 3:
            t.type = PLANE;
            cout << "Choose plane type:" << endl;
            cout << "1. Boeing" << endl;
            cout << "2. Airbus" << endl;
            cout << "3. Heinkel" << endl;
            cout << "4. Junkers" << endl;
            int planeTypeChoice;
            cin >> planeTypeChoice;
            t.planeInfo.type = static_cast<PlaneType>(planeTypeChoice - 1);

            cout << "Enter speed:" << endl;
            cin >> t.planeInfo.speed;

            cout << "Enter number of passengers:" << endl;
            cin >> t.planeInfo.numberOfPassengers;
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
    }
}



bool addToMassive(Transport transports[], int& currentSize, const int MaxSize = 5) {
    if (currentSize >= MaxSize) {
        cout << "Massive is full" << endl;
        return false;
    }
    fillTransportDetails(transports[currentSize]);
    currentSize++;
    return true;
}





void printTransport(const Transport& t) {
    switch (t.type) {
        case CAR:
            cout << "Марка машины: ";
            switch (t.carInfo.brand) 
            {
                case BMW:
                    cout << "BMW" << endl;
                    break;
                case Mercedes:
                    cout << "Mercedes" << endl;
                    break;
                case Audi:  
                    cout << "Audi" << endl;
                    break;
                case Toyota:
                    cout << "Toyota" << endl;
                    break;
            }
            cout << "Грузоподъемность машины: " << t.carInfo.loadCapacity << endl;
            cout << "Количество пассажиров в машине: " << t.carInfo.passengerCount << endl;
            break;

        case TRAIN:
            cout << "Тип поезда: ";
            switch (t.trainInfo.type) {
                case COURIER:
                    cout << "Courier" << endl;
                    break;
                case EXPRESS:
                    cout << "Express" << endl;
                    break;
                case PASSENGER:
                    cout << "Passenger" << endl;
                    break;
            }
            cout << "Скорость поезда: " << t.trainInfo.speed << endl;
            cout << "Количество вагонов в поезде: " << t.trainInfo.numberOfCarriages << endl;
            break;

        case PLANE:
            cout << "Тип самолета: ";
            switch (t.planeInfo.type) {
                case Boeing:
                    cout << "Boeing" << endl;
                    break;
                case Airbus:
                    cout << "Airbus" << endl;
                    break;
                case Heinkel:
                    cout << "Heinkel" << endl;
                    break;
                case Junkers:
                    cout << "Junkers" << endl;
                    break;
            }
            cout << "Скорость самолета: " << t.planeInfo.speed << endl;
            cout << "Количество пассажиров в самолете: " << t.planeInfo.numberOfPassengers << endl;
            break;
    }
}




int main() 
{
    setlocale(LC_ALL, "Russian");
    const int MAX_SIZE = 5;
    Transport transports[MAX_SIZE];
    int currentSize = 0;

    while (true) // выполняется бесконечно до тех пор пока не будет введено n или не будет достигнуто максимальное количество транспорта
    {
        if (addToMassive(transports, currentSize, MAX_SIZE)) 
        {
            cout << "Transport added successfully" << endl;
        } else 
        {
            cout << "Error adding transport" << endl;
        }
        cout << "Do you want to add another transport? (y/n)" << endl;
        char answer;
        cin >> answer;
        if (answer == 'n') {
            break;
        }
        if (answer == 'y'){
            if (currentSize >= MAX_SIZE){
                cout << "Massive is full" << endl;
                break;
            }
        }
    }

    return 0;
}













