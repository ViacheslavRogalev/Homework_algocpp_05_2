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
    std::cout << "\nПирамида:\n";

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
        std::cout << "\nВы находитесь здесь: " << level << " root " << arr[element] << "\n";
    }
    else if (element % 2 == 1)
    {
        std::cout << "\nВы находитесь здесь: " << level << " left(" << parent << ") " << arr[element] << "\n";
    }
    else
    {
        std::cout << "\nВы находитесь здесь: " << level << " right(" << parent << ") " << arr[element] << "\n";
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

    std::cout << "\nДаны исходные массивы:\n";

    print_array(arr1, sizeof(arr1) / sizeof(arr1[0]));
    print_array(arr2, sizeof(arr2) / sizeof(arr2[0]));
    print_array(arr3, sizeof(arr3) / sizeof(arr3[0]));

    do
    {
        std::cout << "\nВыберите массив для путешествия: ";
        std::cin >> choice;
        if (choice < 1 || choice>3)
        {
            std::cout << "\nВведите корректное значение!\n";
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

    std::cout << "\nВы выбрали массив: { ";
    for (int i = 0; i < size; i++)
    {
        std::cout << choice_arr[i] << " ";
    }
    std::cout << "}\n";

    std::cout << "\nВыберите элемент в качестве отправной точки путешествия: ";
    std::cin >> choice;
    for (int i = 0; i < size; i++)
    {
        if (choice_arr[i] == choice) { sp = i; }
    }

    print_pyramid(choice_arr, size);

    std::cout << "\nКоманды для путешествия по пирамиде:" << std::endl;
    std::cout << "up — перейти к родителю;" << std::endl;
    std::cout << "left — перейти к левому потомку;" << std::endl;
    std::cout << "right — перейти к правому потомку;" << std::endl;
    std::cout << "exit — завершить работу программы." << std::endl;

    print_element(choice_arr, size, sp);
    do
    {
        std::cout << "\nВведите команду: ";
        std::cin >> action;

        if (action == "up")
        {
            if ((sp - 1 / 2) <= 0)
            {
                std::cout << "\nОшибка! Отсутствует родитель.";
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
                std::cout << "\nОшибка! Отсутствует левый потомок.";
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
                std::cout << "\nОшибка! Отсутствует правый потомок.";
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