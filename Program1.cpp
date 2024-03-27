#include<iostream>
using namespace std;

struct Data{
    int userId;
    string name;
    int age;
    string address;
};
Data userInfo[50];
int userCount = 0;

void read();
void create();
void update();
void deleteUser();

int main(){
    int option;
    do {
        cout << "1. Create User" << endl;
        cout << "2. Read User" << endl;
        cout << "3. Update User" << endl;
        cout << "4. Delete USer" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your option :-> " ;
        cin >> option;
        if(option == 1){
            create();
        }else if (option == 2){
            read();
        }else if (option == 3){
            update();
        }else if (option == 4){
            deleteUser();
        }else {
            cout << "Invalid user Input! Please try again." << endl;
        }
    }while(option != 0);
    return 0;
}

void create(){
    int i = 0;
    if (userCount == 0){
        userInfo[userCount].userId = 1;
    }else{
        userInfo[userCount].userId = userInfo[userCount - 1].userId + 1;
    }
    cout << "Enter your name: ";
    getline(cin >> ws, userInfo[userCount].name);
    cout << "Enter your age: ";
    cin >> userInfo[userCount].age;
    cout << "Enter your address: ";
 getline(cin >> ws, userInfo[userCount].address);
    userCount++;
}

void read(){
    for (int i=0; i < userCount; i++) {
       cout << userInfo[i].userId << " ";
       cout << userInfo[i].name << " ";
       cout << userInfo[i].age << " ";
       cout << userInfo[i].address << endl;
    }
}

void update(){
    int id;
    bool foundId = false;
    do {
        cout << "Enter ID to update: ";
        cin >> id;
        for (int i = 0; i < userCount; i++) {
            if (id == userInfo[i].userId) {
                cout << "Enter new name to update: ";
                getline(cin >> ws, userInfo[i].name);
                cout << "Enter new age to update: ";
                cin >> userInfo[i].age;
                cout << "Enter new address to update: ";
                getline(cin >> ws, userInfo[i].address);
                foundId = true;
                break;
            }
        }
        if (!foundId) {
            cout << "Invalid input! Please try again." << endl;
        }
    }while(!foundId);
}
void deleteUser(){
    int id;
    int found = -1;
    bool foundId = false;
    int i = 0;
    do{
        cout << " Enter ID to delete: " ;
        cin >> id;
        for ( i = 0; i < userCount ; i++){
            if (userInfo[i].userId == id){
                found = i;
                foundId = true;
                break;
            }
        }
        if(foundId) {
            for (i = found; i < userCount - 1; i++) {
                userInfo[i].userId = userInfo[i + 1].userId;
                userInfo[i].name = userInfo[i + 1].name;
                userInfo[i].age = userInfo[i + 1].age;
                userInfo[i].address = userInfo[i + 1].address;
            }
            userCount--;
        }else{
            cout << "Invalid user input! Please try again." << endl;
        }
    }while(!foundId);
}
