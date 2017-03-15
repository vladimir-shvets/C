#include <iostream>
using namespace std;
 
struct Car
{
        char *number;       //Номер
        char *name;         //Марка
        char *owner;        //Владелец
        bool safe;          //Техосмотр
};
 
void FindByName(const char *name, Car *arr, int size)
{
        for(int i = 0; i < size; i++)
            {
                    if(!strcmp(arr[i].name, name))
                        {
                                cout << "CAR # " << i << ": OWNER IS " << arr[i].owner << ", NUMBER IS " << arr[i].number << endl;
                            }
                }
}
 
int FindCount(const char *name, Car *arr, int size)
{
        int result = 0;
     
        for(int i = 0; i < size; i++)
            {
                    if(!strcmp(arr[i].name, name))
                        {
                                result++;
                            }
                }
     
        return result;
}
 
int main()
{
        int n;
        cout << "INPUT SIZE OF ARRAY: ";
        cin>>n;
     
        Car *arr = new Car[n];
     
        cout << endl;
     
        //Fill data
        for(int i = 0; i < n; i++)
            {
                    arr[i].name = new char[64];
                    arr[i].number = new char[16];
                    arr[i].owner = new char[64];
                    int safe;
             
                    cout << "CAR # " << i << ":" << endl;
                    cout << "    NAME  : ";
                    cin>>arr[i].name;
                    cout << "    NUMBER: ";
                    cin>>arr[i].number;
                    cout << "    OWNER : ";
                    cin>>arr[i].owner;
                    cout << "    SAFE (1/0) : ";
                    cin>>safe;
                    
                    if(safe == 1)
                            arr[i].safe = true;
                    else
                            arr[i].safe = false;
                }
     
        cout << endl;
     
        char name[64];
        cout << "INPUT NAME TO FIND IN ARRAY: ";
        cin >> name;
     
        FindByName(name, arr, n);
        cout << "COUNT OF " << name << " IN ARRAY = " << FindCount(name, arr, n) << endl;
     
        //Clear
        for(int i = 0; i < n; i++)
            {
                    delete [] arr[i].name;
                    delete [] arr[i].number;
                    delete [] arr[i].owner;
                }
     
        delete [] arr;
     
        return 0;
}
