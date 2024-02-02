#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;
string record;


class restaurant
{
private:
    string rest_name; // m3ana
    string position;
public:
    void setData();
    void getData();
    void pack();
    void unpack();
    void insert();
    void search(string key);
    void update(string key);
    void deleteD(string key);
    void display();
};

void restaurant::setData()
{

    cout << "Enter restaurant name" << endl;
    cin >> rest_name;

    cout << "Enter restaurant position" << endl;
    cin >> position;
}
void restaurant::getData()
{
    cout << "restaurant Name: " << rest_name << endl;
    cout << "restaurant position: " << position << endl;
    cout << "_" << endl;
}
void restaurant::pack()
{
    record =  rest_name + "|"  + position + "#\n";
}
void restaurant::unpack()
{
    int pos;


    pos = record.find("|");
    rest_name = record.substr(0, pos);


    record = record.substr(pos + 1);
    pos = record.find("#");
    position = record.substr(0, pos);
}

void restaurant::insert()
{
    fstream file;
    file.open("restaurant.txt", ios::out | ios::app);
    setData();
    pack();
    file << record;
    file.close();
}
void restaurant::display()
{
    fstream file;
    file.open("restaurant.txt", ios::in);
    while (getline(file, record))
    {
        unpack();
        getData();
    }
    file.close();
}
void restaurant::search(string key)
{
    int pos = -1;
    int count = 0;
    fstream file;
    file.open("restaurant.txt", ios::in);

    while (!file.eof())
    {
        getline(file, record);
        count++;
        if (file.fail()) break;
        unpack();
        if (rest_name == key)
        {
            pos = count;
            break;
        }
    }
    file.close();

    if (pos == -1)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found at postion " << pos << endl;
        getData();
    }
}

void restaurant::update(string key)
{
    fstream in_file;
    fstream out_file;

    in_file.open("restaurant.txt", ios::in);
    out_file.open("temp.txt", ios::out);

    while(getline(in_file,record))
    {
        unpack();
        if(key == rest_name)
        {
            setData();
        }
    }


    in_file.close();
    out_file.close();

    remove("restaurant.txt");
    rename("temp.txt", "restaurant.txt");
}

void restaurant::deleteD(string key)
{
    fstream in_file;
    fstream out_file;
    in_file.open("restaurant.txt", ios::in);
    out_file.open("temp.txt", ios::out);

    while (getline(in_file, record))
    {
        unpack();
        if (key == rest_name)
        {
            continue;
        }
        pack();
        out_file << record;
    }
    in_file.close();
    out_file.close();

    remove("restaurant.txt");
    rename("temp.txt", "restaurant.txt");
}



class department
{
public:
    string depart_Name;
    string depart_id;


    void setData();
    void getData();
    void pack();
    void unpack();
    void insert();
    void search(string key);
    void update(string key);
    void deleteD(string key);
    void display();
};

void department::setData()
{
    cout << "Enter department name" << endl;
    cin >> depart_Name;
    cout << "Enter department id" << endl;
    cin >> depart_id;
}
void department::getData()
{
    cout << "department Name: " << depart_Name << endl;
    cout << "department ID: " << depart_id << endl;

    cout << "_" << endl;
}
void department::pack()
{
    record = depart_Name + "|" + depart_id  + "#\n";
}
void department::unpack()
{
    int pos;

    pos = record.find("|");
    depart_Name = record.substr(0, pos);

    record = record.substr(pos + 1);
    pos = record.find("#");
    depart_id = record.substr(0, pos);


}

void department::insert()
{
    fstream file;
    file.open("department.txt", ios::out | ios::app);
    setData();
    pack();
    file << record;
    file.close();
}
void department::display()
{
    fstream file;
    file.open("department.txt", ios::in);
    while (getline(file, record))
    {
        unpack();
        getData();
    }
    file.close();
}
void department::search(string key)
{
    int pos = -1;
    int count = 0;
    fstream file;
    file.open("department.txt", ios::in);

    while (!file.eof())
    {
        getline(file, record);
        count++;
        if (file.fail()) break;
        unpack();
        if (depart_Name == key)
        {
            pos = count;
            break;
        }
    }
    file.close();

    if (pos == -1)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found at postion " << pos << endl;
        getData();
    }
}

void department::update(string key)
{
    fstream in_file;
    fstream out_file;
    in_file.open("department.txt", ios::in);
    out_file.open("temp.txt", ios::out);

    while (getline(in_file, record))
    {
        unpack();
        if (key == depart_Name)
        {
            setData();
        }
        pack();
        out_file << record;
    }
    in_file.close();
    out_file.close();

    remove("department.txt");
    rename("temp.txt", "department.txt");
}

void department::deleteD(string key)
{
    fstream in_file;
    fstream out_file;
    in_file.open("department.txt", ios::in);
    out_file.open("temp.txt", ios::out);

    while (getline(in_file, record))
    {
        unpack();
        if (key == depart_Name)
        {
            continue;
        }
        pack();
        out_file << record;
    }
    in_file.close();
    out_file.close();

    remove("department.txt");
    rename("temp.txt", "department.txt");
}




class chief
{
private:
    string s_id;
    string type;
    string position;
    string Depart_ID;
public:
    void setData();
    void getData();
    void pack();
    void unpack();
    void insert();
    void search(string key);
    void update(string key);
    void deleteD(string key);
    void display();
};

void chief::setData()
{
    cout << "Enter ID" << endl;
    cin >> s_id;
    cout << "Enter Name" << endl;
    cin >> type;
    cout << "Enter position" << endl;
    cin >> position;
    cout << "Enter Department ID" << endl;
    cin >> Depart_ID;
}
void chief::getData()
{
    cout << "ID: " << s_id << endl;
    cout << "Name: " << type << endl;
    cout << "position: " << position << endl;
    cout << "Department ID: " << Depart_ID << endl;
    cout << "_" << endl;
}
void chief::pack()
{
    record = s_id + "|" + type + "|" + position + "|" + Depart_ID + "#\n";
}
void chief::unpack()
{
    int pos;

    pos = record.find("|");
    s_id = record.substr(0, pos);

    record = record.substr(pos + 1);
    pos = record.find("|");
    type = record.substr(0, pos);

    record = record.substr(pos + 1);
    pos = record.find("|");
    position = record.substr(0, pos);

    record = record.substr(pos + 1);
    pos = record.find("#");
    Depart_ID = record.substr(0, pos);
}

void chief::insert()
{
    fstream file, file1;
    department obj;
    file.open("chief.txt", ios::out | ios::app);
    file1.open("department.txt", ios::in);
    setData();
    while (getline(file1, record))
    {
        obj.unpack();
        if (obj.depart_id == Depart_ID)
        {
            pack();
            file << record;
        }
    }
    file.close();
}

void chief::display()
{
    fstream file;
    file.open("chief.txt", ios::in);
    while (getline(file, record))
    {
        unpack();
        getData();
    }
    file.close();
}
void chief::search(string key)
{
    int pos = -1;
    int count = 0;
    fstream file;
    file.open("chief.txt", ios::in);

    while (!file.eof())
    {
        getline(file, record);
        count++;
        if (file.fail()) break;
        unpack();
        if (s_id == key)
        {
            pos = count;
            break;
        }
    }
    file.close();

    if (pos == -1)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found at postion " << pos << endl;
        getData();
    }
}

void chief::update(string key)
{
    fstream in_file, file;
    fstream out_file;
    department obj;
    in_file.open("chief.txt", ios::in);
    file.open("department.txt", ios::in);
    out_file.open("temp.txt", ios::out);

    while (getline(in_file, record))
    {
        unpack();
        if (key == s_id)
        {
            setData();
        }
        while (getline(file, record))
        {
            if (obj.depart_id== Depart_ID)
            {
                pack();
                out_file << record;
            }
        }

    }
    in_file.close();
    out_file.close();

    remove("chief.txt");
    rename("temp.txt", "chief.txt");
}

void chief::deleteD(string key)
{
    fstream in_file;
    fstream out_file;
    in_file.open("chief.txt", ios::in);
    out_file.open("temp.txt", ios::out);

    while (getline(in_file, record))
    {
        unpack();
        if (key == s_id)
        {
            continue;
        }
        pack();
        out_file << record;
    }
    in_file.close();
    out_file.close();

    remove("chief.txt");
    rename("temp.txt", "chief.txt");
}

void introduction();


class meal
{
public:
    string meal_name;
    float price;


    void setData();
    void getData();
    void pack();
    void unpack();
    void insert();
    void search(string key);
    void update(string key);
    void deleteD(string key);
    void display();
};

void meal::setData()
{
    cout << "Enter meal name" << endl;
    cin >> meal_name;
    cout << "Enter Price" << endl;
    cin >> price;
}
void meal::getData()
{
    cout << "meal Name: " << meal_name << endl;
    cout << "price: " << price << endl;

    cout << "_" << endl;
}
void meal::pack()
{
    record = meal_name + "|" + to_string(price)  + "#\n";
}
void meal::unpack()
{
    int pos;

    pos = record.find("|");
    meal_name = record.substr(0, pos);

    record = record.substr(pos + 1);
    pos = record.find("#");
    price = stof(record.substr(0, pos));


}

void meal::insert()
{
    fstream file;
    file.open("meal.txt", ios::out | ios::app);
    setData();
    pack();
    file << record;
    file.close();
}
void meal::display()
{
    fstream file;
    file.open("meal.txt", ios::in);
    while (getline(file, record))
    {
        unpack();
        getData();
    }
    file.close();
}
void meal::search(string key)
{
    int pos = -1;
    int count = 0;
    fstream file;
    file.open("meal.txt", ios::in);

    while (!file.eof())
    {
        getline(file, record);
        count++;
        if (file.fail()) break;
        unpack();
        if (meal_name == key)
        {
            pos = count;
            break;
        }
    }
    file.close();

    if (pos == -1)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found at postion " << pos << endl;
        getData();
    }
}

void meal::update(string key)
{
    fstream in_file;
    fstream out_file;
    in_file.open("meal.txt", ios::in);
    out_file.open("temp.txt", ios::out);

    while (getline(in_file, record))
    {
        unpack();
        if (key == meal_name)
        {
            setData();
        }
        pack();
        out_file << record;
    }
    in_file.close();
    out_file.close();

    remove("meal.txt");
    rename("temp.txt", "meal.txt");
}

void meal::deleteD(string key)
{
    fstream in_file;
    fstream out_file;
    in_file.open("meal.txt", ios::in);
    out_file.open("temp.txt", ios::out);

    while (getline(in_file, record))
    {
        unpack();
        if (key == meal_name)
        {
            continue;
        }
        pack();
        out_file << record;
    }
    in_file.close();
    out_file.close();

    remove("meal.txt");
    rename("temp.txt", "meal.txt");
}

class menu
{
private:
    string type;
    string meal_id;
public:
    void setData();
    void getData();
    void pack();
    void unpack();
    void insert();
    void search(string key);
    void update(string key);
    void deleteD(string key);
    void display();
};

void menu::setData()
{

    cout << "Enter Type" << endl;
    cin >> type;

    cout << "Enter Meal ID" << endl;
    cin >> meal_id;
}
void menu::getData()
{
    cout << "Type Name: " << type << endl;

    cout << "Meal ID: " << meal_id << endl;
    cout << "_" << endl;
}
void menu::pack()
{
    record =  type + "|"  + meal_id + "#\n";
}
void menu::unpack()
{
    int pos;


    pos = record.find("|");
    type = record.substr(0, pos);


    record = record.substr(pos + 1);
    pos = record.find("#");
    meal_id = record.substr(0, pos);
}

void menu::insert()
{
    fstream file, file1;
    meal obj;
    file.open("menu.txt", ios::out | ios::app);
    file1.open("meal.txt", ios::in);
    setData();
    while (getline(file1, record))
    {
        obj.unpack();
        if (obj.meal_name == meal_id)
        {
            pack();
            file << record;
        }
    }
    file.close();
}

void menu::display()
{
    fstream file;
    file.open("menu.txt", ios::in);
    while (getline(file, record))
    {
        unpack();
        getData();
    }
    file.close();
}
void menu::search(string key)
{
    int pos = -1;
    int count = 0;
    fstream file;
    file.open("menu.txt", ios::in);

    while (!file.eof())
    {
        getline(file, record);
        count++;
        if (file.fail()) break;
        unpack();
        if (meal_id == key)
        {
            pos = count;
            break;
        }
    }
    file.close();

    if (pos == -1)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found at postion " << pos << endl;
        getData();
    }
}

void menu::update(string key)
{
    fstream in_file, file;
    fstream out_file;
    meal obj;
    in_file.open("menu.txt", ios::in);
    file.open("meal.txt", ios::in);
    out_file.open("temp.txt", ios::out);

    while (getline(in_file, record))
    {
        unpack();
        if (key == meal_id)
        {
            setData();
        }
        while (getline(file, record))
        {
            if (obj.meal_name== meal_id)
            {
                pack();
                out_file << record;
            }
        }

    }
    in_file.close();
    out_file.close();

    remove("menu.txt");
    rename("temp.txt", "menu.txt");
}

void menu::deleteD(string key)
{
    fstream in_file;
    fstream out_file;
    in_file.open("menu.txt", ios::in);
    out_file.open("temp.txt", ios::out);

    while (getline(in_file, record))
    {
        unpack();
        if (key == meal_id)
        {
            continue;
        }
        pack();
        out_file << record;
    }
    in_file.close();
    out_file.close();

    remove("menu.txt");
    rename("temp.txt", "menu.txt");
}

void introduction();





int main()
{
    system("color f5");
    department depart;
    chief chf;
    restaurant rest;
    meal me;
    menu mu;
    introduction();
    string key;
    int option;

   again: char chPass;
    string pass = "",username;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter Password: ";
    chPass = _getch();

    while(chPass != '\r')
    {
        pass += chPass;
        cout<<"*";
        chPass = _getch();
    }

    if(username == "admin" && pass == "1234")
    {
        system("cls");
Home:
        cout<<"1- department"<<endl;
        cout<<"2- restaurant"<<endl;
        cout<<"3- Chief"<<endl;
        cout<<"4- meal"<<endl;
        cout<<"5- menu"<<endl;
        cout<<"6- exit"<<endl;
        cout<<"enter your option"<<endl;
        cin>>option;

    }
    else
    {
        goto again;
    }





    if(option == 1)
    {
        goto D;
    }
    else if(option == 2)
    {
        goto S;
    }
    else if(option == 3)
    {
        goto C;
    }
    else if(option ==4 )
    {
        goto ml;
    }
        else if(option ==5 )
    {
        goto mgo;
    }
        else if(option ==6 )
    {
        exit(0);
    }
    else
    {
        cout<<"Invalid option!"<<endl;
    }




    char ch;
    cin >> ch;

D:
    do
    {
        system("cls");
        cout << "1- Insert" << endl;
        cout << "2- Search" << endl;
        cout << "3- Update" << endl;
        cout << "4- Delete" << endl;
        cout << "5- Display" << endl;
        cout << "6- Exit" << endl;
        int choice;
        cout << "\n\t\t Enter your choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            depart.insert();
            break;
        }
        case 2:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            depart.search(key);
            break;
        }
        case 3:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            depart.update(key);
            break;
        }

        case 4:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            depart.deleteD(key);
            break;
        }

        case 5:
        {
            system("cls");
            depart.display();
            break;
        }
        case 6:
        {
            system("cls");
            goto Home;
            break;
        }
        default:
        {
            system("cls");
            cout << "invalid choice" << endl;

        }
        }

        cout << "\n \t &&&&&&&&&&&&&&&&&&&&&& To return to a menu Enter (y,Y)" << endl;
        cin >> ch;
    }
    while (ch == 'Y' || ch == 'y');

S:
    do
    {
        system("cls");
        cout << "1- Insert" << endl;
        cout << "2- Search" << endl;
        cout << "3- Update" << endl;
        cout << "4- Delete" << endl;
        cout << "5- Display" << endl;
        cout << "6- Exit" << endl;
        int choice;
        cout << "\n\t\t Enter your choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            rest.insert();
            break;
        }
        case 2:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            rest.search(key);
            break;
        }
        case 3:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            rest.update(key);
            break;
        }

        case 4:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            rest.deleteD(key);
            break;
        }

        case 5:
        {
            system("cls");
            rest.display();
            break;
        }
        case 6:
        {
            system("cls");
            goto Home;
            break;
        }
        default:
        {
            system("cls");
            cout << "invalid choice" << endl;

        }
        }

        cout << "\n \t &&&&&&&&&&&&&&&&&&&&&& To return to a menu Enter (y,Y)" << endl;
        cin >> ch;
    }
    while (ch == 'Y' || ch == 'y');


    C:
    do
    {
        system("cls");
        cout << "1- Insert" << endl;
        cout << "2- Search" << endl;
        cout << "3- Update" << endl;
        cout << "4- Delete" << endl;
        cout << "5- Display" << endl;
        cout << "6- Exit" << endl;
        int choice;
        cout << "\n\t\t Enter your choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            chf.insert();
            break;
        }
        case 2:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            chf.search(key);
            break;
        }
        case 3:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            chf.update(key);
            break;
        }

        case 4:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            chf.deleteD(key);
            break;
        }

        case 5:
        {
            system("cls");
            chf.display();
            break;
        }
        case 6:
        {
            system("cls");
            goto Home;
            break;
        }
        default:
        {
            system("cls");
            cout << "invalid choice" << endl;

        }
        }

        cout << "\n \t &&&&&&&&&&&&&&&&&&&&&& To return to a menu Enter (y,Y)" << endl;
        cin >> ch;
    }
    while (ch == 'Y' || ch == 'y');

    ml:
    do
    {
        system("cls");
        cout << "1- Insert" << endl;
        cout << "2- Search" << endl;
        cout << "3- Update" << endl;
        cout << "4- Delete" << endl;
        cout << "5- Display" << endl;
        cout << "6- Exit" << endl;
        int choice;
        cout << "\n\t\t Enter your choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            me.insert();
            break;
        }
        case 2:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            me.search(key);
            break;
        }
        case 3:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            me.update(key);
            break;
        }

        case 4:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            me.deleteD(key);
            break;
        }

        case 5:
        {
            system("cls");
            me.display();
            break;
        }
        case 6:
        {
            system("cls");
            goto Home;
            break;
        }
        default:
        {
            system("cls");
            cout << "invalid choice" << endl;

        }
        }

        cout << "\n \t &&&&&&&&&&&&&&&&&&&&&& To return to a menu Enter (y,Y)" << endl;
        cin >> ch;
    }
    while (ch == 'Y' || ch == 'y');

    mgo:
    do
    {
        system("cls");
        cout << "1- Insert" << endl;
        cout << "2- Search" << endl;
        cout << "3- Update" << endl;
        cout << "4- Delete" << endl;
        cout << "5- Display" << endl;
        cout << "6- Exit" << endl;
        int choice;
        cout << "\n\t\t Enter your choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            mu.insert();
            break;
        }
        case 2:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            mu.search(key);
            break;
        }
        case 3:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            mu.update(key);
            break;
        }

        case 4:
        {
            system("cls");
            cout << "Enter Key" << endl;
            cin >> key;
            mu.deleteD(key);
            break;
        }

        case 5:
        {
            system("cls");
            mu.display();
            break;
        }
        case 6:
        {
            system("cls");
            goto Home;
            break;
        }
        default:
        {
            system("cls");
            cout << "invalid choice" << endl;

        }
        }

        cout << "\n \t &&&&&&&&&&&&&&&&&&&&&& To return to a menu Enter (y,Y)" << endl;
        cin >> ch;
    }
    while (ch == 'Y' || ch == 'y');


    return 0;
}

//definition function "introduction"
void introduction()
{
    cout << "\n\t <3 Username: admin , Password: 1234" << endl;}
