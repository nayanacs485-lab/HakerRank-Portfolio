#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string timeConversion(string s) {
    // Extract hour, minutes, seconds, and AM/PM
    string hourStr = s.substr(0, 2);
    int hour = stoi(hourStr);
    string minutesSeconds = s.substr(2, 6); // ":MM:SS"
    string ampm = s.substr(8, 2);           // "AM" or "PM"

    // Conversion logic
    if (ampm == "AM") {
        if (hour == 12) hour = 0; // midnight case
    } else { // PM
        if (hour != 12) hour += 12; // add 12 except for 12 PM
    }

    // Format back into string
    stringstream ss;
    ss << setw(2) << setfill('0') << hour << minutesSeconds;
    return ss.str();
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();
    return 0;
}
