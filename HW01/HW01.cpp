#include <iostream>

using namespace std;

int sum(int arr[], int size)
{
	float sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum;
}

float mean(int arr[], int size)
{
	return sum(arr, size) / size;
}



void sort(int arr[], int size, bool ascending)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j]))
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		cout << arr[i] << " ";
	}
}
int main()
{
	int arr[5] = { 0,0,0,0,0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int select = 0;
	bool ascending = true;

	cout << size << "개의 숫자를 입력해주세요." << endl;

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "번째 숫자 : ";
		cin >> arr[i];
		if (cin.fail()) {
			cerr << "오류: 정수가 아닌 값이 입력되었습니다." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			--i;
		}


	}
	cout << "합계 : " << sum(arr, size) << endl;
	cout << "평균 : " << mean(arr, size) << endl;

	cout << "1:오름차순 정렬  2:내림차순 정렬  아무 키:종료" << endl;
	cin >> select;

	if (select == 1)
	{
		ascending = true;
		sort(arr, size, ascending);
	}
	else if (select == 2)
	{
		ascending = false;
		sort(arr, size, ascending);
	}
	else
	{

	}

	return 0;
}