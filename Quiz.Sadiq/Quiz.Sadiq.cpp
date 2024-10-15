#include <iostream>
using namespace std;

char questions[100][256];
char answers[100][256];
int qCount = 0;


void readInput(char arr[], int maxLength) {
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < maxLength - 1) {
        arr[i++] = ch;
    }
    arr[i] = '\0';
}

void createQuiz() {
    if (qCount >= 100) {
        cout << "Sual limitin? �at�l�b!" << endl;
        return;
    }

    cout << "Yeni sual daxil edin: ";
    readInput(questions[qCount], 256);

    cout << "Cavab� daxil edin: ";
    readInput(answers[qCount], 256);

    qCount++;
}

void viewQuiz() {
    if (qCount == 0) {
        cout << "He� bir quiz yoxdur!" << endl;
        return;
    }

    for (int i = 0; i < qCount; i++) {
        cout << i + 1 << ". " << questions[i] << " (Cavab: " << answers[i] << ")" << endl;
    }
}

void editQuiz() {
    if (qCount == 0) {
        cout << "He� bir quiz yoxdur!" << endl;
        return;
    }

    viewQuiz();

    int idx;
    cout << "D�z?ltm?k ist?diyiniz sual�n n�mr?sini daxil edin: ";
    cin >> idx;
    getchar();
    if (idx > 0 && idx <= qCount) {
        cout << "Yeni sual daxil edin: ";
        readInput(questions[idx - 1], 256);
        cout << "Yeni cavab� daxil edin: ";
        readInput(answers[idx - 1], 256);
    }
    else {
        cout << "Yanl�� n�mr?!" << endl;
    }
}

void deleteQuiz() {
    if (qCount == 0) {
        cout << "He� bir quiz yoxdur!" << endl;
        return;
    }

    viewQuiz();

    int idx;
    cout << "Silm?k ist?diyiniz sual�n n�mr?sini daxil edin: ";
    cin >> idx;
    getchar();
    if (idx > 0 && idx <= qCount) {
        for (int i = idx - 1; i < qCount - 1; i++) {
            for (int j = 0; j < 256; j++) {
                questions[i][j] = questions[i + 1][j];
                answers[i][j] = answers[i + 1][j];
            }
        }
        qCount--;
        cout << "Sual silindi!" << endl;
    }
    else {
        cout << "Yanl�� n�mr?!" << endl;
    }
}


void guestQuiz() {
    if (qCount == 0) {
        cout << "He� bir quiz yoxdur!" << endl;
        return;
    }

    for (int i = 0; i < qCount; i++) {
        cout << i + 1 << ". " << questions[i] << endl;
    }

    int idx;
    cout << "Cavabland�rmaq ist?diyiniz sual�n n�mr?sini daxil edin: ";
    cin >> idx;
    getchar();
    if (idx > 0 && idx <= qCount) {
        char userAnswer[256];
        cout << "Cavab�n�z� daxil edin: ";
        readInput(userAnswer, 256);


        int correct = 1;
        for (int i = 0; i < 256; i++) {
            if (userAnswer[i] != answers[idx - 1][i]) {
                correct = 0;
                break;
            }
        }

        if (correct) {
            cout << "Cavab�n�z d�zg�nd�r!" << endl;
        }
        else {
            cout << "Cavab�n�z s?hvdir. Do�ru cavab: " << answers[idx - 1] << endl;
        }
    }
    else {
        cout << "Yanl�� n�mr?!" << endl;
    }
}


void adminMenu() {
    int choice;
    do {
        cout << "\nAdmin Menyusu:\n";
        cout << "1. Yeni quiz yarat\n";
        cout << "2. Quizl?r? bax\n";
        cout << "3. Quiz d�z?lt\n";
        cout << "4. Quiz sil\n";
        cout << "5. Qonaq roluna ke�\n";
        cout << "6. ��x��\n";
        cout << "Se�iminizi daxil edin: ";
        cin >> choice;
        getchar();

        switch (choice) {
        case 1:
            createQuiz();
            break;
        case 2:
            viewQuiz();
            break;
        case 3:
            editQuiz();
            break;
        case 4:
            deleteQuiz();
            break;
        case 5:
            cout << "Qonaq roluna ke�irsiniz..." << endl;
            return;
        case 6:
            cout << "��x�� edilir..." << endl;
            break;
        default:
            cout << "Yanl�� se�im!" << endl;
        }
    } while (choice != 6);
}


void guestMenu() {
    int choice;
    do {
        cout << "\nQonaq Menyusu:\n";
        cout << "1. Quizl?ri cavabland�r\n";
        cout << "2. ��x��\n";
        cout << "Se�iminizi daxil edin: ";
        cin >> choice;
        getchar();

        switch (choice) {
        case 1:
            guestQuiz();
            break;
        case 2:
            cout << "��x�� edilir..." << endl;
            break;
        default:
            cout << "Yanl�� se�im!" << endl;
        }
    } while (choice != 2);
}

int main() {
    int role;
    cout << "1. Admin\n";
    cout << "2. Guest\n";
    cout << "Se�iminizi daxil edin: ";
    cin >> role;
    getchar();

    if (role == 1) {
        adminMenu();
    }
    else if (role == 2) {
        guestMenu();
    }
    else {
        cout << "Yanl�� se�im!" << endl;
    }

    return 0;
}