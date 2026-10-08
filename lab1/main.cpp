#include <clocale>
#include <iostream>
#include <limits>
#include <string>

int ReadInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cout << "Ошибка: введите целое число.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

long ReadLong(const std::string& prompt) {
    long value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cout << "Ошибка: введите целое число.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double ReadDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cout << "Ошибка: введите число.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

char ReadDigit() {
    char value;
    while (true) {
        std::cout << "Введите цифру от 0 до 9: ";
        std::cin >> value;

        if (value >= '0' && value <= '9') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cout << "Ошибка: нужно ввести одну цифру от 0 до 9.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int ReadPositiveInt(const std::string& prompt) {
    int value = ReadInt(prompt);

    while (value <= 0) {
        std::cout << "Ошибка: число должно быть больше 0.\n";
        value = ReadInt(prompt);
    }

    return value;
}

int* ReadArray(const std::string& name) {
    int size = ReadPositiveInt(
        "Сколько элементов в массиве " + name + "? ");

    int* arr = new int[size + 1];
    arr[0] = size;

    for (int i = 1; i <= size; ++i) {
        arr[i] = ReadInt(
            "Массив " + name + ", элемент " + std::to_string(i) + ": ");
    }

    return arr;
}

void PrintArray(int arr[]) {
    for (int i = 1; i <= arr[0]; ++i) {
        if (i > 1) {
            std::cout << ", ";
        }
        std::cout << arr[i];
    }
    std::cout << "\n";
}

void ShowBool(bool result) {
    std::cout << "Результат: " << (result ? "true" : "false") << "\n";
}

// Задание 1.

// Задача 1. Fraction
double Fraction(double x) {
    int integer_part = static_cast<int>(x);
    return x - integer_part;
}

// Задача 3. CharToNum
int CharToNum(char x) {
    return x - '0';
}

// Задача 5. Is2Digits
bool Is2Digits(int x) {
    return (x >= 10 && x <= 99) || (x <= -10 && x >= -99);
}

// Задача 7. IsInRange
bool IsInRange(int a, int b, int num) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    return num >= a && num <= b;
}

// Задача 9. IsEqual
bool IsEqual(int a, int b, int c) {
    return a == b && b == c;
}

// Задание 2. 

// Задача 1. Abs
int Abs(int x) {
    if (x < 0) {
        return -x;
    }

    return x;
}

// Задача 3. Is35
bool Is35(int x) {
    return (x % 3 == 0) != (x % 5 == 0);
}

// Задача 5. Max3
int Max3(int x, int y, int z) {
    int max_value = x;

    if (y > max_value) {
        max_value = y;
    }

    if (z > max_value) {
        max_value = z;
    }

    return max_value;
}

// Задача 7. Sum2
int Sum2(int x, int y) {
    int sum = x + y;

    if (sum >= 10 && sum <= 19) {
        return 20;
    }

    return sum;
}

// Задача 9. Day
std::string Day(int x) {
    switch (x) {
    case 1:
        return "понедельник";
    case 2:
        return "вторник";
    case 3:
        return "среда";
    case 4:
        return "четверг";
    case 5:
        return "пятница";
    case 6:
        return "суббота";
    case 7:
        return "воскресенье";
    default:
        return "это не день недели";
    }
}

// Задание 3.

// Задача 1. ListNums
std::string ListNums(int x) {
    std::string result;

    for (int i = 0; i <= x; ++i) {
        if (!result.empty()) {
            result += " ";
        }
        result += std::to_string(i);
    }

    return result;
}

// Задача 3. Chet
std::string Chet(int x) {
    std::string result;

    for (int i = 0; i <= x; i += 2) {
        if (!result.empty()) {
            result += " ";
        }
        result += std::to_string(i);
    }

    return result;
}

// Задача 5. NumLen
int NumLen(long x) {
    if (x == 0) {
        return 1;
    }

    if (x < 0) {
        x = -x;
    }

    int length = 0;

    while (x > 0) {
        x /= 10;
        ++length;
    }

    return length;
}

// Задача 7. Square
void Square(int x) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

// Задача 9. RightTriangle
void RightTriangle(int x) {
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < x - i; ++j) {
            std::cout << ' ';
        }

        for (int j = 0; j < i; ++j) {
            std::cout << '*';
        }

        std::cout << '\n';
    }
}

// Задание 4. 

// Задача 1. FindFirst
int FindFirst(int arr[], int x) {
    for (int i = 1; i <= arr[0]; ++i) {
        if (arr[i] == x) {
            return i - 1;
        }
    }

    return -1;
}

// Задача 3. MaxAbs
int MaxAbs(int arr[]) {
    int max_value = arr[1];

    for (int i = 2; i <= arr[0]; ++i) {
        if (Abs(arr[i]) > Abs(max_value)) {
            max_value = arr[i];
        }
    }

    return max_value;
}

// Задача 5. Add
int* Add(int arr[], int ins[], int pos) {
    int size = arr[0] + ins[0];
    int* result = new int[size + 1];
    result[0] = size;

    int index = 1;

    for (int i = 1; i <= pos; ++i) {
        result[index] = arr[i];
        ++index;
    }

    for (int i = 1; i <= ins[0]; ++i) {
        result[index] = ins[i];
        ++index;
    }

    for (int i = pos + 1; i <= arr[0]; ++i) {
        result[index] = arr[i];
        ++index;
    }

    return result;
}

// Задача 7. ReverseBack
int* ReverseBack(int arr[]) {
    int* result = new int[arr[0] + 1];
    result[0] = arr[0];

    for (int i = 1; i <= arr[0]; ++i) {
        result[i] = arr[arr[0] - i + 1];
    }

    return result;
}

// Задача 9. FindAll
int* FindAll(int arr[], int x) {
    int count = 0;

    for (int i = 1; i <= arr[0]; ++i) {
        if (arr[i] == x) {
            ++count;
        }
    }

    int* result = new int[count + 1];
    result[0] = count;

    int index = 1;

    for (int i = 1; i <= arr[0]; ++i) {
        if (arr[i] == x) {
            result[index] = i - 1;
            ++index;
        }
    }

    return result;
}

void RunTask1(int task) {
    if (task == 1) {
        double x = ReadDouble("Введите x: ");
        std::cout << "Результат: " << Fraction(x) << "\n";
    }
    else if (task == 2) {
        char x = ReadDigit();
        std::cout << "Результат: " << CharToNum(x) << "\n";
    }
    else if (task == 3) {
        int x = ReadInt("Введите число: ");
        ShowBool(Is2Digits(x));
    }
    else if (task == 4) {
        int a = ReadInt("Введите a: ");
        int b = ReadInt("Введите b: ");
        int num = ReadInt("Введите num: ");
        ShowBool(IsInRange(a, b, num));
    }
    else {
        int a = ReadInt("Введите a: ");
        int b = ReadInt("Введите b: ");
        int c = ReadInt("Введите c: ");
        ShowBool(IsEqual(a, b, c));
    }
}

void RunTask2(int task) {
    if (task == 1) {
        int x = ReadInt("Введите x: ");
        std::cout << "Результат: " << Abs(x) << "\n";
    }
    else if (task == 2) {
        int x = ReadInt("Введите x: ");
        ShowBool(Is35(x));
    }
    else if (task == 3) {
        int x = ReadInt("Введите x: ");
        int y = ReadInt("Введите y: ");
        int z = ReadInt("Введите z: ");
        std::cout << "Результат: " << Max3(x, y, z) << "\n";
    }
    else if (task == 4) {
        int x = ReadInt("Введите x: ");
        int y = ReadInt("Введите y: ");
        std::cout << "Результат: " << Sum2(x, y) << "\n";
    }
    else {
        int x = ReadInt("Введите номер дня: ");
        std::cout << "Результат: " << Day(x) << "\n";
    }
}

void RunTask3(int task) {
    if (task == 1) {
        int x = ReadPositiveInt("Введите x: ");
        std::cout << "Результат: " << ListNums(x) << "\n";
    }
    else if (task == 2) {
        int x = ReadPositiveInt("Введите x: ");
        std::cout << "Результат: " << Chet(x) << "\n";
    }
    else if (task == 3) {
        long x = ReadLong("Введите x: ");
        std::cout << "Результат: " << NumLen(x) << "\n";
    }
    else if (task == 4) {
        int x = ReadPositiveInt("Введите x: ");
        Square(x);
    }
    else {
        int x = ReadPositiveInt("Введите x: ");
        RightTriangle(x);
    }
}

void RunTask4(int task) {
    if (task == 1) {
        int* arr = ReadArray("arr");
        int x = ReadInt("Введите x: ");

        std::cout << "Результат: " << FindFirst(arr, x) << "\n";
        delete[] arr;
    }
    else if (task == 2) {
        int* arr = ReadArray("arr");

        std::cout << "Результат: " << MaxAbs(arr) << "\n";
        delete[] arr;
    }
    else if (task == 3) {
        int* arr = ReadArray("arr");
        int* ins = ReadArray("ins");

        int pos = ReadInt(
            "Введите позицию вставки от 0 до " +
            std::to_string(arr[0]) + ": ");

        while (pos < 0 || pos > arr[0]) {
            std::cout << "Ошибка: позиция должна быть от 0 до "
                << arr[0] << ".\n";
            pos = ReadInt("Введите позицию: ");
        }

        int* result = Add(arr, ins, pos);

        std::cout << "Результат: ";
        PrintArray(result);

        delete[] result;
        delete[] arr;
        delete[] ins;
    }
    else if (task == 4) {
        int* arr = ReadArray("arr");
        int* result = ReverseBack(arr);

        std::cout << "Результат: ";
        PrintArray(result);

        delete[] result;
        delete[] arr;
    }
    else {
        int* arr = ReadArray("arr");
        int x = ReadInt("Введите x: ");
        int* result = FindAll(arr, x);

        std::cout << "Индексы: ";
        PrintArray(result);

        delete[] result;
        delete[] arr;
    }
}

void RunSet(int set) {
    while (true) {
        std::cout << "\n";

        if (set == 1) {
            std::cout << "Задание 1. Методы\n"
                "1. Fraction\n"
                "2. CharToNum\n"
                "3. Is2Digits\n"
                "4. IsInRange\n"
                "5. IsEqual\n";
        }
        else if (set == 2) {
            std::cout << "Задание 2. Условия\n"
                "1. Abs\n"
                "2. Is35\n"
                "3. Max3\n"
                "4. Sum2\n"
                "5. Day\n";
        }
        else if (set == 3) {
            std::cout << "Задание 3. Циклы\n"
                "1. ListNums\n"
                "2. Chet\n"
                "3. NumLen\n"
                "4. Square\n"
                "5. RightTriangle\n";
        }
        else {
            std::cout << "Задание 4. Массивы\n"
                "1. FindFirst\n"
                "2. MaxAbs\n"
                "3. Add\n"
                "4. ReverseBack\n"
                "5. FindAll\n";
        }

        std::cout << "0. Назад\n";

        int task = ReadInt("Выберите задачу: ");

        if (task == 0) {
            return;
        }

        if (task < 1 || task > 5) {
            std::cout << "Такой задачи нет.\n";
            continue;
        }

        if (set == 1) {
            RunTask1(task);
        }
        else if (set == 2) {
            RunTask2(task);
        }
        else if (set == 3) {
            RunTask3(task);
        }
        else {
            RunTask4(task);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    while (true) {
        std::cout << "1. Задание 1. Методы\n"
            "2. Задание 2. Условия\n"
            "3. Задание 3. Циклы\n"
            "4. Задание 4. Массивы\n"
            "0. Выход\n";
            

        int set = ReadInt("Выберите задание: ");

        if (set == 0) {
            return 0;
        }

        if (set < 1 || set > 4) {
            std::cout << "Такого задания нет.\n";
            continue;
        }

        RunSet(set);
    }
}
