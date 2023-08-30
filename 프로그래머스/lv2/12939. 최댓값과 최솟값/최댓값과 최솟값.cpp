// #include <string>
// #include <vector>
// #include <iostream>
// #include <sstream>

// using namespace std;

// string solution(string s) {
//     string answer = "";
    
//     vector<int> v;
    
    
//     istringstream iss(s);
//     string temp;
//     char delimeter = ' ';
    
//     while(iss >> temp) {
//         v.push_back(stoi(temp));
//     }
    
// //     string temp = "";
// //     for(int i = 0 ;i<s.size();i++) {
// //         if(s[i] == ' ') {
// //             v.push_back(stoi(temp));
// //         } else {
// //             temp += s[i];
// //         }
// //     }
    
// //     for(int i=0;i<v.size();i++) {
// //         cout<<v.at(i);
// //     }
    
    
//     if(v.capacity() > 0) {
//         int min = v.at(0);
//         int max = v.at(0);


//         for(int i=1 ; i<v.capacity(); i++) {
//             int vValue = v.at(i);
//             if(min > vValue) {
//                 min = vValue;
//             }
//             if(max < vValue) {
//                 max = vValue;
//             }
//         }


//         answer.append(to_string(min));
//         answer.append(" ");
//         answer.append(to_string(max));
        
//     }
    
//     return answer;
// }

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    string temp = "";
    vector <int> v;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ' ') {
            v.push_back(stoi(temp));
            temp = "";
        } else {
            temp += s[i];
        }
    }
    v.push_back(stoi(temp));
    sort(v.begin(), v.end());

    string min = to_string(v[0]);
    string max = to_string(v[v.size()-1]);

    answer = min + " " + max;

    return answer;
}