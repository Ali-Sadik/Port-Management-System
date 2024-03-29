#include <iostream>
#include <conio.h>
#include <windows.h>

void menu();
void arrivals();
void departures();
void wait();
void addvessel(void);
void updep(void);
void boatdetails(void);

using namespace std;

const int dockmanager = 3;

class dockman
{
private:
    string user[dockmanager];
    string pass[dockmanager];
public:
    string username, password;
    friend void menu();
    friend void wait();
    dockman()
    {
        user[0] = "sadik047";
        user[1] = "akib048";
        user[2] = "eesa049";

        pass[0] = "123";
        pass[1] = "456";
        pass[2] = "789";
    }
    void checklogin()
    {
        cout << "\n\n\n\t\t\tWelcome to the Teligati port management system\n\n"
             << "Enter your username: ";
        cin >> username;
        wait();
        cout << "\n\n\nEnter your password: ";
        cin >> password;
        wait();

        int validLogin = 0;
        for (int i = 0; i < dockmanager; ++i)
        {
            if (username == user[i] && password == pass[i])
            {
                validLogin = 1;
                break;
            }
        }

        if (validLogin == 1)
        {
            cout << "\n\n\nLogin successful! Welcome dockmanager " << username << "!\n\n";
            menu();
        }
        else
        {
            cout << "\n\nInvalid username or password. Please try again.\n";
            checklogin();
        }
    }
};

void menu(void)
{

    int menuoption, yesno;
    cout << "\n\n1.Arrivals\n2.Departures\n3.Update Arrival list\n4.Update Departure list\n5.Vessel info entry\n6.Exit\n\n";
    cin >> menuoption;
    wait();

    switch (menuoption)
    {
    case 1:
        arrivals();
        break;
    case 2:
        departures();
        break;
    case 3:
        addvessel();
        break;
    case 4:
        updep();
        break;
    case 5:
        boatdetails();
        break;
    case 6:
        exit(0);
    default:
        break;
    }
    cout << "\n\nContinue?\n1.Yes\n2.No\n";
    cin >> yesno;
    wait();
    if (yesno == 1)
        menu();
    else
        exit(0);
}

void arrivals()
{
    FILE *filearrive;

    filearrive = fopen("arrivals.txt", "r");
    if (filearrive == NULL)
    {
        printf("File doesn't exist");
    }
    else
    {
        cout << "\n\n_________________________________________List of Arrivals_________________________________________\n\n";
        char ch;
        while ((ch = fgetc(filearrive)) != EOF)
        {
            printf("%c", ch);
        }

        fclose(filearrive);
    }
}

void departures()
{
    FILE *filedep;

    filedep = fopen("departures.txt", "r");
    if (filedep == NULL)
    {
        printf("File doesn't exist");
    }
    else
    {
        cout << "\n\n_________________________________________List of Departures_________________________________________\n\n";
        char ch;
        while ((ch = fgetc(filedep)) != EOF)
        {
            printf("%c", ch);
        }

        fclose(filedep);
    }
}

void wait(void)
{
    cout << "\n\nPlease wait";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
}

class vessel
{
public:
    string vesselname, vtype, arrdeptime, captain;
    int portno;

    friend void wait();
    friend void boatdetails(void);

    void add()
    {
        cout << "\n\nEnter the vessel name: ";
        cin >> vesselname;
        wait();
        cout << "\n\nEnter the vessel type: ";
        cin >> vtype;
        wait();
        cout << "\n\nEnter the arrival time: ";
        cin >> arrdeptime;
        wait();
        cout << "\n\nEnter the captain's name: ";
        cin >> captain;
        wait();
        cout << "\n\nEnter the port's number: ";
        cin >> portno;
        wait();
    }

    void dept()
    {
        cout << "\n\nEnter the vessel name: ";
        cin >> vesselname;
        wait();
        cout << "\n\nEnter the vessel type: ";
        cin >> vtype;
        wait();
        cout << "\n\nEnter the departure time: ";
        cin >> arrdeptime;
        wait();
        cout << "\n\nEnter the captain's name: ";
        cin >> captain;
        wait();
        cout << "\n\nEnter the port's number: ";
        cin >> portno;
        wait();
    }
};

class cargoship : public vessel
{
public:
    friend void cargodetails(cargoship);
    friend void boatdetails(void);
    int capacity;
    string type;
    void cargoshipdet()
    {
        cout << "\nCargoship Name: ";
        cin >> vesselname;
        wait();
        cout << "\nCaptain's name: ";
        cin >> captain;
        wait();
        cout << "\nVessel Capacity: ";
        cin >> capacity;
        wait();
        cout << "\nCargo type:";
        cin >> type;
        wait();
    }
};

class containership : public cargoship
{
public:
    friend void containerdetails(containership);
    friend void boatdetails(void);
    int container_number;
    containership()
    {
       cout << "\nVessel Name: ";
        cin >> vesselname;
        wait();
        cout << "\nCaptain's name: ";
        cin >> captain;
        wait();
        cout << "\nVessel Capacity: ";
        cin >> capacity;
        wait();
        cout << "\nContainer ship type: ";
        cin >> type;
        wait(); 
        cout << "\nNumber of containers: ";
        cin >> container_number;
        wait();
    }
};

class cruise : public vessel
{
    public:
    int passengers_num;
    friend void boatdetails(void);
    friend void cruisedetails(cruise);

    cruise()
    {
        cout << "\nCruise Name: ";
        cin >> vesselname;
        wait();
        cout << "\nCaptain's name: ";
        cin >> captain;
        wait();
        cout << "\nCruise Capacity: ";
        cin >> passengers_num;
        wait();

    }
};
class yacht : public vessel
{
    public:
    string luxury_type;
    string owners_name;
    friend void boatdetails(void);
    friend void yachtdetails(yacht);

    yacht()
    {
        cout << "\nYacht Name: ";
        cin >> vesselname;
        wait();
        cout << "\nCaptain's name: ";
        cin >> captain;
        wait();
        cout << "\nOwner's name: ";
        cin >> owners_name;
        wait();
        cout << "\nLuxury level: ";
        cin >> luxury_type;
        wait();
    }
};

class fishing_boat : public vessel
{
    public:
    int fisherman_num;
    string area;
    friend void boatdetails(void);
    friend void fishdetails(fishing_boat);
    fishing_boat()
    {
        cout << "\nBoat Name: ";
        cin >> vesselname;
        wait();
        cout << "\nBoatman's name: ";
        cin >> captain;
        wait();
        cout << "\nNumber of fisherman: ";
        cin >> fisherman_num;
        wait();
        cout << "\nCoverage Area:";
        cin >> area;
        wait();
    }

};

class navalboat : public vessel
{
    public:
    int boat_id;
    friend void boatdetails(void);
    friend void navaldetails(navalboat);

    navalboat()
    {
        cout << "\nBoat Name: ";
        cin >> vesselname;
        wait();
        cout << "\nCaptain's name: ";
        cin >> captain;
        wait();
        cout << "\nBoat id: ";
        cin >> boat_id;
        wait();
    }
};

void addvessel(void)
{
    vessel v1;
    v1.add();
    FILE *addvessel;
    addvessel = fopen("arrivals.txt", "a");

    if (addvessel == NULL)
    {
        cout << "Unable to open file." << endl;
        return;
    }

    fprintf(addvessel, "\n%-25s%-25s%-25s%-25s%d\n", v1.vesselname.c_str(), v1.vtype.c_str(), v1.arrdeptime.c_str(), v1.captain.c_str(), v1.portno);

    fclose(addvessel);
    cout << "\n\n*****************Arrived Vessel information has been saved to the file.*****************" << endl;
}

void updep(void)
{
    vessel v2;
    v2.dept();
    FILE *deptvessel;
    deptvessel = fopen("departures.txt", "a");

    if (deptvessel == NULL)
    {
        cout << "Unable to open file." << endl;
        return;
    }

    fprintf(deptvessel, "\n%-25s%-25s%-25s%-25s%d\n", v2.vesselname.c_str(), v2.vtype.c_str(), v2.arrdeptime.c_str(), v2.captain.c_str(), v2.portno);

    fclose(deptvessel);
    cout << "\n\n*****************Departed Vessel information has been saved to the file.*****************" << endl;
}


void boatdetails(void)
{
    int vesselmenu;
    cout << "\n\nEnter the type of the vessel:\n1.Cargo\n2.Container\n3.Cruise\n4.Yacht\n5.Fishing Boat\n6.Naval Boat\n\n";
    cin >> vesselmenu;
    wait();
    switch (vesselmenu)
    {
    case 1:
        {
            cargoship c1;
            c1.cargoshipdet();
            cargodetails(c1);
            break;
        }
    case 2:
        {
            containership cn1;
            containerdetails(cn1);
            break;
        }
    case 3:
        {
            cruise cr1;
            cruisedetails(cr1);
            break;
        }
    case 4:
        {
            yacht y1;
            yachtdetails(y1);
            break;
        }
    case 5:
        {
            fishing_boat f1;
            fishdetails(f1);
            break;
        }
    case 6:
        {
            navalboat n1;
            navaldetails(n1);
            break;
        }
    default:
        break;
    }


}

void cargodetails(cargoship c)
{
    string filename = c.vesselname + "_cargo" + ".txt";
    FILE *shipdet;

    shipdet = fopen(filename.c_str(), "w");

    if (shipdet == NULL)
    {
        cout << "Unable to open file." << endl;
        return;
    }

    fprintf(shipdet, "\nCargo Name: %s\nCaptain: %s\nCapacity: %dtons\n Cargo type: %s", c.vesselname.c_str(), c.captain.c_str(), c.capacity, c.type.c_str());

    fclose(shipdet);
    cout << "\n\n*****************Cargo information has been saved to a file.*****************" << endl;

}

void containerdetails(containership c)
{
    string filename = c.vesselname + "_container" + ".txt";
    FILE *shipdet;

    shipdet = fopen(filename.c_str(), "w");

    if (shipdet == NULL)
    {
        cout << "Unable to open file." << endl;
        return;
    }

    fprintf(shipdet, "\nContainer Ship Name: %s\nCaptain: %s\nCapacity: %dtons\n Container ship type: %s\nNumber of Containers: %d", c.vesselname.c_str(), c.captain.c_str(), c.capacity, c.type.c_str(), c.container_number);

    fclose(shipdet);
    cout << "\n\n*****************Container ship information has been saved to a file.*****************" << endl;

}

void cruisedetails(cruise c)
{
    string filename = c.vesselname + "_cruise" + ".txt";
    FILE *shipdet;

    shipdet = fopen(filename.c_str(), "w");

    if (shipdet == NULL)
    {
        cout << "Unable to open file." << endl;
        return;
    }

    fprintf(shipdet, "\nCruise Ship Name: %s\nCaptain: %s\nCapacity: %d peoples", c.vesselname.c_str(), c.captain.c_str(), c.passengers_num);

    fclose(shipdet);
    cout << "\n\n*****************Cruise ship information has been saved to a file.*****************" << endl;

}


void yachtdetails(yacht c)
{
    string filename = c.vesselname + "_yacht" + ".txt";
    FILE *shipdet;

    shipdet = fopen(filename.c_str(), "w");

    if (shipdet == NULL)
    {
        cout << "Unable to open file." << endl;
        return;
    }

    fprintf(shipdet, "\nYacht Name: %s\nCaptain: %s\nOwner: %s\nLuxury level: %s", c.vesselname.c_str(), c.captain.c_str(), c.owners_name.c_str(), c.luxury_type.c_str());

    fclose(shipdet);
    cout << "\n\n*****************Yacht information has been saved to a file.*****************" << endl;

}


void fishdetails(fishing_boat c)
{
    string filename = c.vesselname + "_fishing" + ".txt";
    FILE *shipdet;

    shipdet = fopen(filename.c_str(), "w");

    if (shipdet == NULL)
    {
        cout << "Unable to open file." << endl;
        return;
    }

    fprintf(shipdet, "\nBoat Name: %s\nBoatman: %s\nNumber of fisherman: %d\nCoverage area of fishing: %s", c.vesselname.c_str(), c.captain.c_str(), c.fisherman_num, c.area.c_str());

    fclose(shipdet);
    cout << "\n\n*****************Fishing boat information has been saved to a file.*****************" << endl;

}


void navaldetails(navalboat c)
{
    string filename = c.vesselname + "_navy" + ".txt";
    FILE *shipdet;

    shipdet = fopen(filename.c_str(), "w");

    if (shipdet == NULL)
    {
        cout << "Unable to open file." << endl;
        return;
    }

    fprintf(shipdet, "\nNaval boat Name: %s\nCaptain: %s\nBoat id: %d", c.vesselname.c_str(), c.captain.c_str(), c.boat_id);

    fclose(shipdet);
    cout << "\n\n*****************Naval boat information has been saved to a file.*****************" << endl;

}



int main()
{
    dockman D;
    D.checklogin();
    getch();
    return 0;
}



