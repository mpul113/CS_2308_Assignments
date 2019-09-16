#include <iostream>
#include <iomanip>

using namespace std;

int minimum (int* minArray, int size) {
  int minIndex;
  int minValue = 9;

  for (int i = 0; i < size; i++){
    if (*minArray < minValue) {
      minValue = *minArray;
      minIndex = i;
    }
     minArray++;
  }

  return minIndex;
}

int swapTimesTen(int* x, int*y) {
  int temp = *x;

  *x = *y * 10;
  *y = temp * 10;

  return *x + *y;
}

int* doubleArray(int* doubleArray, int size) {
  int* newArray = NULL;
  int newSize = size * 2;
  newArray = new int[newSize];

  for (int i = 0; i < newSize; i++) {
    if (i < 9)
      newArray[i] = doubleArray[i];
    else
      newArray[i] = doubleArray[i-9] * 2;
  }
    return newArray;
}

int* subArray(int* array, int start, int length) {
  int* newArray = NULL;
  newArray = new int[length];

  for (int i = 0; i < length; i++) {
    newArray[i] = array[start + i];
  }
  return newArray;
}

int* duplicateArray (int *arr, int size) {
  int* newArray;
  if (size <= 0)
    return NULL;

  newArray = new int[size];

  for (int index = 0; index < size; index++)
    newArray[index] = arr[index];

  return newArray;
}

int* subArray2 (int* array, int start, int length) {
  int* result = duplicateArray(array, length);
  return result;
}

void displayArray (int* array, int size) {
  for (int i = 0; i < size; i++) {
    cout << *(array + i) << " ";
  }
}

int main () {

  const int SIZE1 = 10;
  const int SIZE2 = 9;
  int minArray[SIZE1] = {1, 2, 3, 4, 5, 6, 7, -8, 9, 0};
  int minArray2[SIZE1] = {1, 2, 3, 4, 5, 16, 7, 8, 9, 0};
  int singleArray[SIZE2] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int mainArray[SIZE1] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int* dupDouble = NULL;
  int* newArray = NULL;
  int* newNewArray = NULL;

  int a = 3,
    b = 5,
    swap;

  cout << "Testing minimum: \n"
       << "Test data: 1 2 3 4 5 6 7 -8 9 0 \n"
       << "Expected minimum: -8 \n"
       << "Actual minimum:   " << minArray[minimum(minArray, SIZE1)]
       << "\nTest data: 1 2 3 4 5 16 7 8 9 0 \n"
       << "Expected minimum: 0 \n"
       << "Actual minimum:   " << minArray[minimum(minArray2, SIZE1)];

  swap = swapTimesTen(&a, &b);

  cout << "\n\ntesting swapTimesTen \n"
       << "Expected Results: 80 a: 50 b: 30 \n"
       << "Actual Results  : " << swap << " a: " << a << " b: " << b;

  dupDouble = doubleArray(singleArray, SIZE2);

  cout << "\n\ntesting doubleArray: \n"
       << "test data:  1 2 3 4 5 6 7 8 9 \n"
       << "Expected results: 1 2 3 4 5 6 7 8 9 2 4 6 8 10 12 14 16 18 \n"
       << "Actual results:   ";
  displayArray(dupDouble, 18);

  newArray = subArray(mainArray, 5, 4);

  cout << "\n\ntesting subArray: \n"
       << "test data: 1 2 3 4 5 6 7 8 9 10 \n"
       << "start: 5 length: 4 \n"
       << "Expected result: 6 7 8 9 \n"
       << "Actual result:   ";
  displayArray(newArray, 4);

  newNewArray = subArray2(newArray, 5, 4);

  cout << "\n\ntesting subArray2: \n"
       << "test data: 1 2 3 4 5 6 7 8 9 10 \n"
       << "start: 5 length: 4 \n"
       << "Expected result: 6 7 8 9 \n"
       << "Actual result:   ";
  displayArray(newNewArray, 4);

  delete [] dupDouble;
  delete [] newArray;
  delete [] newNewArray;
  dupDouble = NULL;
  newArray = NULL;
  newNewArray = NULL;
}
