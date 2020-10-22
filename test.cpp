#include "pch.h"
#include "sort_alg.cpp"
int* arr; // глобальный массив для тестов сортировки.


TEST(TestCaseSortArr, TestQsort) {
	init_arr(arr, 1000);
	int tmp_arr[1000];
	for (int i = 0; i < 1000; i++) {
		tmp_arr[i] = arr[i];
	}
	std::sort(tmp_arr, tmp_arr + 1000);
	Qsort(arr, 0, 999);
	for (size_t i = 0; i < 1000; i++) {
		ASSERT_EQ(tmp_arr[i], arr[i]);
	}
	delete[] arr;
}

TEST(TestCaseSortArr, TestInsertionSort) {
	init_arr(arr, 1000);
	int tmp_arr[1000];
	for (size_t i = 0; i < 1000; i++) {
		tmp_arr[i] = arr[i];
	}
	std::sort(tmp_arr, tmp_arr + 1000);
	InsertionSort(arr, 1000);
	for (size_t i = 0; i < 1000; i++) {
		ASSERT_EQ(tmp_arr[i], arr[i]);
	}
	delete[] arr;
}


TEST(TestCaseSortArr, TestCountingSort) {
	char* ch_arr = new char[100];
	char tmp_ch_arr[100];
	for (size_t i = 0; i < 100; i++) {
		ch_arr[i] = rand() % 10 + '0';
		tmp_ch_arr[i] = ch_arr[i];
	}
	std::sort(tmp_ch_arr, tmp_ch_arr + 100);
	CountingSort(ch_arr, 100);
	for (size_t i = 0; i < 100; i++) {
		ASSERT_EQ(tmp_ch_arr[i], ch_arr[i]);
	}
	delete[] ch_arr;
}

TEST(TestCaseSortArr, TestBogoSort) {
	init_arr(arr, 10);
	int tmp_arr[10];
	for (int i = 0; i < 10; i++) {
		tmp_arr[i] = arr[i];
	}
	std::sort(tmp_arr, tmp_arr + 10);
	bogosort(arr, 10);
	for (size_t i = 0; i < 10; i++) {
		ASSERT_EQ(tmp_arr[i], arr[i]);
	}
	delete[] arr;
}



TEST(TestCaseBinarySearch, TestNonFoundElem) {
	arr = new int[100];
	for (size_t i = 0; i < 100; i++) {
		arr[i] = i + 2;
	}
	ASSERT_EQ(-1, binary_search(arr, 0, 100, 1234));  // возвращение -1, если не нашел этого элемента
	
}

TEST(TestCaseBinarySearch, TestFoundElem) {
	// функция binary_search возвращает индекс элемента
	ASSERT_EQ(0, binary_search(arr, 0, 100, 2)); // поиск в начале
	ASSERT_EQ(99, binary_search(arr, 0, 100, 101)); // поиск в конце
	ASSERT_EQ(50, binary_search(arr, 0, 100, 52));  // поиск в середине
	delete[] arr;
}
