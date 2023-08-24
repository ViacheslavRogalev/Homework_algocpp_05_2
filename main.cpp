#include <iostream>
#include <string>

void print_array(int* arr, int size)
{
    static int count = 1;
    std::cout << count << ") - arr" << count << "[] {";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "};\n";
    count++;
}

void print_pyramid(int* arr, int size)
{
    int parent, level;
    std::cout << "\n��������:\n";

    for (int i = 0; i < size; i++)
    {
        level = log(i + 1) / log(2);
        parent = arr[(i - 1) / 2];

        if (i == 0)
        {
            std::cout << level << " root " << arr[0] << "\n";
        }
        else if (i % 2 == 1)
        {
            std::cout << level << " left(" << parent << ") " << arr[i] << "\n";
        }
        else
        {
            std::cout << level << " right(" << parent << ") " << arr[i] << "\n";
        }
    }
}

void print_element(int* arr, int size, int element)
{
    int level = log(element + 1) / log(2);
    int parent = arr[(element - 1) / 2];

    if (element == 0)
    {
        std::cout << "\n�� ���������� �����: " << level << " root " << arr[element] << "\n";
    }
    else if (element % 2 == 1)
    {
        std::cout << "\n�� ���������� �����: " << level << " left(" << parent << ") " << arr[element] << "\n";
    }
    else
    {
        std::cout << "\n�� ���������� �����: " << level << " right(" << parent << ") " << arr[element] << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int choice, size = 0, sp = 0;
    std::string action;
    int* choice_arr = nullptr;

    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

    std::cout << "\n���� �������� �������:\n";

    print_array(arr1, sizeof(arr1) / sizeof(arr1[0]));
    print_array(arr2, sizeof(arr2) / sizeof(arr2[0]));
    print_array(arr3, sizeof(arr3) / sizeof(arr3[0]));

    do
    {
        std::cout << "\n�������� ������ ��� �����������: ";
        std::cin >> choice;
        if (choice < 1 || choice>3)
        {
            std::cout << "\n������� ���������� ��������!\n";
        }
    } while (choice < 1 || choice>3);

    switch (choice)
    {
    case 1:
        size = sizeof(arr1) / sizeof(arr1[0]);
        choice_arr = new int[size];
        for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
        {
            choice_arr[i] = arr1[i];
        }
        break;
    case 2:
        size = sizeof(arr2) / sizeof(arr2[0]);
        choice_arr = new int[size];
        for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
        {
            choice_arr[i] = arr2[i];
        }
        break;
    case 3:
        size = sizeof(arr3) / sizeof(arr3[0]);
        choice_arr = new int[size];
        for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++)
        {
            choice_arr[i] = arr3[i];
        }
        break;
    }

    std::cout << "\n�� ������� ������: { ";
    for (int i = 0; i < size; i++)
    {
        std::cout << choice_arr[i] << " ";
    }
    std::cout << "}\n";

    std::cout << "\n�������� ������� � �������� ��������� ����� �����������: ";
    std::cin >> choice;
    for (int i = 0; i < size; i++)
    {
        if (choice_arr[i] == choice) { sp = i; }
    }

    print_pyramid(choice_arr, size);

    std::cout << "\n������� ��� ����������� �� ��������:" << std::endl;
    std::cout << "up � ������� � ��������;" << std::endl;
    std::cout << "left � ������� � ������ �������;" << std::endl;
    std::cout << "right � ������� � ������� �������;" << std::endl;
    std::cout << "exit � ��������� ������ ���������." << std::endl;

    print_element(choice_arr, size, sp);
    do
    {
        std::cout << "\n������� �������: ";
        std::cin >> action;

        if (action == "up")
        {
            if ((sp - 1 / 2) <= 0)
            {
                std::cout << "\n������! ����������� ��������.";
                print_element(choice_arr, size, sp);
            }
            else
            {
                sp = (sp - 1) / 2;
                std::cout << "\nOk!";
                print_element(choice_arr, size, sp);
            }
        }
        if (action == "left")
        {
            if ((sp * 2 + 1) >= size)
            {
                std::cout << "\n������! ����������� ����� �������.";
                print_element(choice_arr, size, sp);
            }
            else
            {
                sp = sp * 2 + 1;
                std::cout << "\nOk!";
                print_element(choice_arr, size, sp);
            }
        }
        if (action == "right")
        {
            if ((sp * 2 + 2) >= size)
            {
                std::cout << "\n������! ����������� ������ �������.";
                print_element(choice_arr, size, sp);
            }
            else
            {
                sp = sp * 2 + 2;
                std::cout << "\nOk!";
                print_element(choice_arr, size, sp);
            }
        }
    } while (action != "exit");

    delete[] choice_arr;
}