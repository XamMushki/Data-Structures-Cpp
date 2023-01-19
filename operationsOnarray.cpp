#include <iostream>
using namespace std;

const int array_size = 50;
int array[array_size];
int current_index = 0;

void show();

void insert(int item)
{
    array[current_index] = item;
    current_index++;
    cout << item << " inserted." << endl;
    show();
}

void deleteAt(int index)
{
    if (index < current_index)
    {
        cout << array[index] << " deleted." << endl;
        for (int i = index; i < current_index; i++)
        {
            array[i] = array[index + 1];
        }
        current_index--;
        show();
    }
    else
    {
        cout << "No item available/inserted at Index " << index << endl;
    }
}

void updateAt(int index, int item)
{
    if (index < current_index)
    {
        cout << "Update: " << array[index] << " --> " << item << endl;
        array[index] = item;
        show();
    }
    else
    {
        cout << "No item available/inserted at Index " << index << endl;
        cout << "Please use insert() method instead." << endl;
    }
}

void show()
{
    cout << "Array: {";
    for (int i = 0; i < current_index; i++)
    {
        cout << array[i];
        if (i < current_index - 1)
        {
            cout << ", ";
        }
    }
    cout << "}\n"
         << endl;
}

int main()
{
    insert(1); // INDEX 0
    insert(2); // INDEX 1
    insert(3); // INDEX 2
    insert(7); // INDEX 3
    insert(6); // INDEX 4
    updateAt(1, 4);
    deleteAt(2); // INDEX 4 ELEMENT REMOVED
    insert(5);   // INDEX 4 ADDED

    updateAt(5, 3);
    deleteAt(6);

    return (0);
}