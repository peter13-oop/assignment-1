//TASK 1 as a integer:
#include <iostream>
#include <string>
using namespace std;
const int ITEM_COUNT = 10;
int nextCode = 3123;
struct InventoryItem
{
    int code;
    string name;
    double cost;
    double sellingPrice;
};
InventoryItem insertItem()
{
    InventoryItem item;
    item.code = nextCode;
    nextCode++;
    cout << "Enter item name: ";
    getline(cin, item.name);
    cout << "Enter item cost: ";
    cin >> item.cost;
    cin.ignore();
    item.sellingPrice = item.cost + item.cost * 0.40;
    return item;
}
void displayStock(const InventoryItem* items)
{
    cout << "Name\Cost\Price" << endl;
    for (int i = 0; i < ITEM_COUNT; i++)
    {
        cout<<items[i].code <<endl;
           cout<<items[i].name <<endl;
             cout<<items[i].cost <<endl;
               cout<<items[i].sellingPrice <<endl;
    }
}
int main()
{
    InventoryItem items[ITEM_COUNT];
    for (int i=0;i<ITEM_COUNT;i++)
    {
        cout<<"Item"<< i+1<<endl;
        items[i]=insertItem();
    }
    displayStock(items);
    return 0;
}
//complete TASK 1 as a string:
#include <iostream>
#include <string>
using namespace std;
const int ITEM_COUNT = 10;
int runningNumber = 31203;
struct InventoryItem
{
    string code;
    string name;
    double cost;
    double sellingPrice;
};
InventoryItem insertItem()
{
    InventoryItem item;
    cout << "Enter item name: ";
    getline(cin, item.name);
    cout << "Enter item cost: ";
    cin >> item.cost;
    cin.ignore();
    string prefix=item.name.substr(0,3);
    for (int i=0; i<prefix.length();i++)
    {
        if (prefix[i]>="a"&&prefix[i]<="z")
        {
            prefix[i]=prefix[i]-32;
        }
    }
    item.code = prefix +"_"+ to_string(runningNumber);
    runningNumber++;
    item.sellingPrice=item.cost+item.cost*0.40;
    return item;
}
void displayStock(const InventoryItem*items)
{
    cout << "code\Name\Cost\Price"<<endl;
    for (int i=0;i<ITEM_COUNT;i++)
    {
        cout<<items[i].code<<endl;
          cout<<items[i].name<<endl;
          cout<<items[i].cost<<endl;
          cout<<items[i].sellingPrice<<endl;
    }
}
int main()
{
    InventoryItem items[ITEM_COUNT];
    for (int i=0;i<ITEM_COUNT;i++)
    {
        cout <<"Item"<<i+1<<endl;
        items[i]=insertItem();
    }
    displayStock(items);
    return 0;
}
//TASK 2: 
#include <iostream>
using namespace std;
const int PRICE_PER_SQUARE_FOOT = 18;
struct FeetInches
{
    int feet;
    int inches;
};
struct RoomDimension
{
    FeetInches length;
    FeetInches Width;
};
int computeTheCarpetingCost(const RoomDimension& room)
{
    double length=room.length.feet+room.length.inches/12.0;
    double width=room.Width.feet+room.Width.inches/12.0;
    double area=length*width;
    return area*PRICE_PER_SQUARE_FOOT;
}
int main()
{
    int roomCount;
    cout << "enter the number of rooms in the house:";
    cin >> roomCount;
    RoomDimension*rooms=new RoomDimension[roomCount];
    for (int i=0;i<roomCount;i++)
    {
        cout<<"Room"<<i+1<<endl;
        cout<<"Length (feet):";
        cin>>rooms[i].length.feet;
        cout<<"Length(inches):";
        cin>>rooms[i].length.inches;
        cout<<"Width (feet):";
        cin >> rooms[i].Width.feet;
        cout <<"Width(inches):";
        cin >>rooms[i].Width.inches;
    }
    int choice;
    do
    {
        cout<<endl;
        cout<<"1.total carpeting cost of the house"<<endl;
        cout<<"2.Carpeting cost of each room"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"enter your choice:";
        cin>>choice;

        if (choice==1)
        {
            int total = 0;
            for (int i=0;i<roomCount;i++)
            {
                total=total+computeTheCarpetingCost(rooms[i]);
            }
            cout<<"Total cost: Rs."<< total<<endl;
        }
        else if (choice==2)
        {
            for (int i=0;i<roomCount;i++)
            {
                cout <<"Room "<<i+1<<": Rs"
                     << computeTheCarpetingCost(rooms[i]) << endl;
            }
        }
        else if (choice != 3)
        {
            cout << "invalid choice try again" << endl;
        }
    } while (choice !=3);
    return 0;
}
