//TASK 1:
#include <iostream>
using namespace std;
int* resizeArray(int inArray[], const int size)
{
    int*newArray = new int[size*2];

    for (int i=0; i<size;i++)
    {
        newArray[i] = inArray[i];
        newArray[i+size] = inArray[i]*2;
    }
    return newArray;
}
int main()
{
    int size;
    cout << "enter size of the array: ";
    cin >> size;
    int* original = new int[size];
    cout << "Enter elements of array: ";
    for (int i=0; i<size;i++)
    {
        cin >> original[i];
    }
    int* resized = resizeArray(original,size);
    cout << "resized array: ";
    for (int i=0; i<size*2;i++)
    {
        cout << resized[i];
        if (i<size*2-1)
        {
            cout <<endl;
        }
    }
    cout << endl;
    return 0;
}

TASK 2:
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
bool isDiagonalMatrix(int matrix[MAX_SIZE][MAX_SIZE],const int size)
{
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            if (i !=j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;
    do
    {
        cout <<"enter size of the square matrix(1 to"<< MAX_SIZE <<"):";
        cin >> size;
    } while (size < 1 || size>MAX_SIZE);

    cout << "Enter the matrix values:" << endl;
    for (int i=0; i<size;i++)
    {
        for (int j=0; j<size;j++)
        {
            cout << "element ["<< i <<"][" << j <<"]:";
            cin >> matrix[i][j];
        }
    }
    if (isDiagonalMatrix(matrix,size))
    {
        cout <<"the matrix is a diagonal matrix" << endl;
    }
    else
    {
        cout <<"the matrix is not a diagonal matrix" << endl;
    }
    return 0;
}
//TASK 3:
#include <iostream>
using namespace std;
char* left(const char*target,const int count)
{
    char*result = new char[count + 1];

    for (int i=0; i<count;i++)
    {
        result[i]=target[i];
    }
    result[count] = '\0';
    return result;
}
void Destructor(char*p)
{
    delete[] p;
}
int main()
{
    char text[30];
    int count;
    cout << "Enter a string: ";
    cin.getline(text,30);
    cout <<"enter count:";
    cin >> count;
    int length = 0;
    while (text[length] != '\0')
    {
        length++;
    }

    if (count < 0 || count > length)
    {
        cout << "count is out of range"<<endl;
    }
    else
    {
        char* substring = left(text,count);
        cout <<"Left substring:"<<substring << endl;
        Destructor(substring);
    }
    return 0;
}
//TASK 4:
#include <iostream>
using namespace std;
int findMin(int inArray[], const int size)
{
    int min = inArray[0];
    for (int i = 1; i < size; i++)
    {
        if (inArray[i] < min)
        {
            min = inArray[i];
        }
    }
    return min;
}
int findMax(int inArray[], const int size)
{
    int max = inArray[0];
    for (int i = 1; i < size; i++)
    {
        if (inArray[i] > max)
        {
            max = inArray[i];
        }
    }
    return max;
}
int computeAverage(int inArray[], const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + inArray[i];
    }
    return sum / size;
}
int computeMedian(int inArray[], const int size)
{
    for (int i=0; i<size-1;i++)
    {
        for (int j=0; j<size-1-i;j++)
        {
            if (inArray[j]>inArray[j+1])
            {
                int temp=inArray[j];
                inArray[j]=inArray[j+1];
                inArray[j+1]=temp;
            }
        }
    }
    if (size % 2 == 0)
    {
        return (inArray[size/2-1] + inArray[size/2])/2;
    }
    else
    {
        return inArray[size/2];
    }
}
int main()
{
    int numStudents;
    do
    {
        cout << "enter the number of students: ";
        cin >> numStudents;
    } while (numStudents <= 0);

    int*marks=new int[numStudents];

    for (int i=0;i<numStudents;i++)
    {
        do
        {
            cout <<"enter marks of student"<< i+1 << ":";
            cin >> marks[i];
            if (marks[i] < 0)
            {
                cout <<"marks cannot be negative Try again" << endl;
            }
        } while (marks[i] < 0);
    }
    cout<<"Maximum:"<<findMax(marks,numStudents)<<endl;
    cout<<"Minimum:"<<findMin(marks,numStudents)<<endl;
    cout<<"Average:"<<computeAverage(marks,numStudents)<< endl;
    cout<<"Median:"<<computeMedian(marks,numStudents)<< endl;
    return 0;
}
