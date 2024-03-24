#include <iostream>
#include <stdlib.h>

using namespace std;

 string Ubah_Apa(string nama_item) {
    if (nama_item == "HP Potion"){
        return "HP";
    } else if (nama_item == "Mana Potion"){
        return "Mana";
    } else if (nama_item == "Herbs"){
        return "HP";
    } else if (nama_item == "Swords"){
        return "Damage";
    }
}

 int Use_potion(string nama_item) {
    if (nama_item == "HP Potion"){
        return 1;
    } else if (nama_item == "Mana Potion"){
        return 2;
    } else if (nama_item == "Herbs"){
        return 0;
    }
}

int main()
{
    int HP = 0;
    int Mana = 0;
    int Damage = 0;
    int Equip_Sword = 0;

    int potions[3] = {10,50,50};
    int Swords[5] = {100,200,300,400,500};

    int Inventory[4] = {5,5,5,5};
    string Inventory_Name[4] = {"HP Potion","Mana Potion","Herbs","Swords"};

    int OD = 1;
    int Input = 100;

    cout << "Input HP karakter : ";
    cin >> HP;
    cout << "Input Mana Karakter : ";
    cin >> Mana;
    cout << "Input Damage Karakter : ";
    cin >> Damage;
    cout << "Pilih pedang untuk Karakter : \n";
    for (int i = 0; i < sizeof(Swords) / sizeof(int); i++){
        cout << i+1 << ". Pedang " << i+1 << " : +" << Swords[i] << " Damage \n";
    }
    cout << "Pilih pedang : ";
    cin >> Equip_Sword;
    Equip_Sword = Equip_Sword - 1;
    while (Equip_Sword >= sizeof(Swords) / sizeof(int)){
        cout << "Pedang tidak ada \n";
        cout << "Pilih pedang : ";
        cin >> Equip_Sword;
        Equip_Sword = Equip_Sword - 1;
    }
    system("cls");

    while (OD > 0){
        if (OD == 1){
            cout << "Status Karakter : \n";
            cout << "HP : "<< HP <<" \n";sizeof(Swords) / sizeof(int);
            cout << "Mana : "<< Mana <<" \n";
            cout << "Damage : "<< Damage + Swords[Equip_Sword]<<" \n";
            cout << "Sword type : "<< Equip_Sword+1 <<" \n";
            cout << "Enter 1 untuk ke inventory ";
            cin >> Input;
            OD = 2;
            Input = 0;
            system("cls");
        } else {
            cout << "Inventory : \n";
            for (int i = 0; i < sizeof(Inventory) / sizeof(int); i++){
                cout << i+1 << ". "<< Inventory_Name[i] <<" sebanyak " << Inventory[i] << " buah \n";
            }
            cout << "Pilih salah satu untuk menggunakan item diatas : ";
            cin >> Input;
            Input = Input - 1;
            if (Input >= sizeof(Inventory) / sizeof(int)){
                cout << "Item tidak ada \n";
                cout << "Pilih salah satu untuk menggunakan item diatas : ";
                cin >> Input;
                Input = Input - 1;
            } else {
                if (Ubah_Apa(Inventory_Name[Input]) == "HP"){
                    HP += potions[Use_potion(Inventory_Name[Input])];
                    Inventory[Input] -= 1;
                } else if (Ubah_Apa(Inventory_Name[Input]) == "Mana"){
                    Mana += potions[Use_potion(Inventory_Name[Input])];
                    Inventory[Input] -= 1;
                } else if (Ubah_Apa(Inventory_Name[Input]) == "Damage"){
                    system("cls");
                    cout << "Pilih pedang untuk Karakter : \n";
                    for (int i = 0; i < Inventory[Input]; i++){
                        if (sizeof(Inventory[Input]) / sizeof(int)<sizeof(Swords) / sizeof(int)){
                            cout << i+1 << ". Pedang " << i+1 << " : +" << Swords[i] << " Damage \n";
                        }else {
                            cout << i+1 << ". Pedang " << i+1 << " : +" << Swords[i%sizeof(Swords) / sizeof(int)] << " Damage \n";
                        }
                    }
                    cout << "Pilih pedang : ";
                    cin >> Equip_Sword;
                    Equip_Sword = Equip_Sword - 1;
                    while (Equip_Sword >= Inventory[Input]){
                        cout << "Pedang tidak ada \n";
                        cout << "Pilih pedang : ";
                        cin >> Equip_Sword;
                        Equip_Sword = Equip_Sword - 1;
                    }
                    Equip_Sword = Equip_Sword%5;
                }
            }
            OD = 1;
            Input = 100;
            system("cls");
        }
    }
}
