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
        cout << "Sual limitin? çatýlýb!" << endl;
        return;
    }

    cout << "Yeni sual daxil edin: ";
    readInput(questions[qCount], 256);

    cout << "Cavabý daxil edin: ";
    readInput(answers[qCount], 256);

    qCount++;
}

void viewQuiz() {
    if (qCount == 0) {
        cout << "Heç bir quiz yoxdur!" << endl;
        return;
    }

    for (int i = 0; i < qCount; i++) {
        cout << i + 1 << ". " << questions[i] << " (Cavab: " << answers[i] << ")" << endl;
    }
}

void editQuiz() {
    if (qCount == 0) {
        cout << "Heç bir quiz yoxdur!" << endl;
        return;
    }

    viewQuiz();

    int idx;
    cout << "Düz?ltm?k ist?diyiniz sualýn nömr?sini daxil edin: ";
    cin >> idx;
    getchar();
    if (idx > 0 && idx <= qCount) {
        cout << "Yeni sual daxil edin: ";
        readInput(questions[idx - 1], 256);
        cout << "Yeni cavabý daxil edin: ";
        readInput(answers[idx - 1], 256);
    }
    else {
        cout << "Yanlýþ nömr?!" << endl;
    }
}

void deleteQuiz() {
    if (qCount == 0) {
        cout << "Heç bir quiz yoxdur!" << endl;
        return;
    }

    viewQuiz();

    int idx;
    cout << "Silm?k ist?diyiniz sualýn nömr?sini daxil edin: ";
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
        cout << "Yanlýþ nömr?!" << endl;
    }
}


void guestQuiz() {
    if (qCount == 0) {
        cout << "Heç bir quiz yoxdur!" << endl;
        return;
    }

    for (int i = 0; i < qCount; i++) {
        cout << i + 1 << ". " << questions[i] << endl;
    }

    int idx;
    cout << "Cavablandýrmaq ist?diyiniz sualýn nömr?sini daxil edin: ";
    cin >> idx;
    getchar();
    if (idx > 0 && idx <= qCount) {
        char userAnswer[256];
        cout << "Cavabýnýzý daxil edin: ";
        readInput(userAnswer, 256);


        int correct = 1;
        for (int i = 0; i < 256; i++) {
            if (userAnswer[i] != answers[idx - 1][i]) {
                correct = 0;
                break;
            }
        }

        if (correct) {
            cout << "Cavabýnýz düzgündür!" << endl;
        }
        else {
            cout << "Cavabýnýz s?hvdir. Doðru cavab: " << answers[idx - 1] << endl;
        }
    }
    else {
        cout << "Yanlýþ nömr?!" << endl;
    }
}


void adminMenu() {
    int choice;
    do {
        cout << "\nAdmin Menyusu:\n";
        cout << "1. Yeni quiz yarat\n";
        cout << "2. Quizl?r? bax\n";
        cout << "3. Quiz düz?lt\n";
        cout << "4. Quiz sil\n";
        cout << "5. Qonaq roluna keç\n";
        cout << "6. Çýxýþ\n";
        cout << "Seçiminizi daxil edin: ";
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
            cout << "Qonaq roluna keçirsiniz..." << endl;
            return;
        case 6:
            cout << "Çýxýþ edilir..." << endl;
            break;
        default:
            cout << "Yanlýþ seçim!" << endl;
        }
    } while (choice != 6);
}


void guestMenu() {
    int choice;
    do {
        cout << "\nQonaq Menyusu:\n";
        cout << "1. Quizl?ri cavablandýr\n";
        cout << "2. Çýxýþ\n";
        cout << "Seçiminizi daxil edin: ";
        cin >> choice;
        getchar();

        switch (choice) {
        case 1:
            guestQuiz();
            break;
        case 2:
            cout << "Çýxýþ edilir..." << endl;
            break;
        default:
            cout << "Yanlýþ seçim!" << endl;
        }
    } while (choice != 2);
}

int main() {
    int role;
    cout << "1. Admin\n";
    cout << "2. Guest\n";
    cout << "Seçiminizi daxil edin: ";
    cin >> role;
    getchar();

    if (role == 1) {
        adminMenu();
    }
    else if (role == 2) {
        guestMenu();
    }
    else {
        cout << "Yanlýþ seçim!" << endl;
    }

    return 0;
}