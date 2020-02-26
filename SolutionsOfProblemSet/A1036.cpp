#include <iostream>
#include <string>
using namespace std;
int main() {
    string max_female_name, min_male_name, max_female_id, min_male_id, temp_name, temp_id;
    int max_female_grade = -1, min_male_grade = 101, temp_grade;
    int N, grade;
    char gender;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp_name >> gender >> temp_id >> grade;
        if (gender == 'M') {
            if (grade < min_male_grade) {
                min_male_name = temp_name;
                min_male_id = temp_id;
                min_male_grade = grade;
            }
        } else {
            if (grade > max_female_grade) {
                max_female_name = temp_name;
                max_female_id = temp_id;
                max_female_grade = grade;
            }
        }
    }
    bool flag = true;
    if (max_female_grade != -1) {
        cout << max_female_name << " " << max_female_id << endl;
    } else {
        flag = false;
        cout << "Absent" << endl;
    }
    if (min_male_grade != 101) {
        cout << min_male_name << " " << min_male_id << endl;
    } else {
        flag = false;
        cout << "Absent" << endl;
    }
    if (flag) {
        cout << max_female_grade - min_male_grade;
    } else {
        cout << "NA";
    }
    return 0;
}