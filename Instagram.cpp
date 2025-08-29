#include<bits/stdc++.h>
using namespace std;
int cnt = 0;

class NewUser {
public:
    int userId;
    string userName;
    string userPassword;
    int No_Of_Followers;
    int No_Of_Following;
    vector<string> Followers_name;
    vector<string> Following_name;

    NewUser(string name, string pass) {
        userId = ++cnt;
        userName = name;
        userPassword = pass;
        No_Of_Followers = 0;
        No_Of_Following = 0;
        cout << "Account Created Successfully for " << name << "\n";
    }

    void follow(NewUser* other) {
        if(other->userName == this->userName) {
            cout << "You cannot follow yourself!\n";
            return;
        }
        if(find(Following_name.begin(), Following_name.end(), other->userName) != Following_name.end()) {
            cout << "You are already following " << other->userName << "\n";
            return;
        }
        Following_name.push_back(other->userName);
        No_Of_Following++;
        other->Followers_name.push_back(this->userName);
        other->No_Of_Followers++;
        cout << this->userName << " is now following " << other->userName << "\n";
    }

    void unfollow(NewUser* other) {
        auto it = find(Following_name.begin(), Following_name.end(), other->userName);
        if(it == Following_name.end()) {
            cout << "You are not following " << other->userName << "\n";
            return;
        }
        Following_name.erase(it);
        No_Of_Following--;
        auto it2 = find(other->Followers_name.begin(), other->Followers_name.end(), this->userName);
        if(it2 != other->Followers_name.end()) {
            other->Followers_name.erase(it2);
            other->No_Of_Followers--;
        }
        cout << this->userName << " unfollowed " << other->userName << "\n";
    }

    void viewProfile() {
        cout << "\n Profile of " << userName << "\n";
        cout << "Followers (" << No_Of_Followers << "): ";
        for(auto &f : Followers_name) cout << f << " ";
        cout << "\nFollowing (" << No_Of_Following << "): ";
        for(auto &f : Following_name) cout << f << " ";
        cout << "\n";
    }

    static NewUser* login(string name, string pass, unordered_map<string, NewUser*>& users) {
        if(users.find(name) != users.end()) {
            if(users[name]->userPassword == pass) {
                cout << "Login Successful! Welcome " << name << "\n";
                return users[name];
            } else {
                cout << " Wrong password!\n";
                return nullptr;
            }
        }
        cout << "User not found!\n";
        return nullptr;
    }
};

int main() {
    unordered_map<string, NewUser*> users;
    NewUser* currentUser = nullptr;

    while(true) {
        cout << "\n--- Instagram Console App ---\n";
        cout << "1. Login\n";
        cout << "2. Create Account\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        if(choice == 3) break;
        else if(choice == 1) {
            string name, pass;
            cout << "Enter Username: ";
            cin >> name;
            cout << "Enter Password: ";
            cin >> pass;
            currentUser = NewUser::login(name, pass, users);
            while(currentUser) {
                cout << "\n--- Welcome " << currentUser->userName << " ---\n";
                cout << "1. Follow User\n";
                cout << "2. Unfollow User\n";
                cout << "3. View Profile\n";
                cout << "4. Logout\n";
                cout << "Enter choice: ";
                int c;
                cin >> c;
                if(c == 4) {
                    cout << " Logged out!\n";
                    currentUser = nullptr;
                    break;
                } else if(c == 1) {
                    string uname;
                    cout << "Enter username to follow: ";
                    cin >> uname;
                    if(users.find(uname) != users.end())
                        currentUser->follow(users[uname]);
                    else
                        cout << "User not found!\n";
                } else if(c == 2) {
                    string uname;
                    cout << "Enter username to unfollow: ";
                    cin >> uname;
                    if(users.find(uname) != users.end())
                        currentUser->unfollow(users[uname]);
                    else
                        cout << "User not found!\n";
                } else if(c == 3) {
                    currentUser->viewProfile();
                }
            }

        } else if(choice == 2) {
            string name, pass;
            cout << "Choose Username: ";
            cin >> name;
            cout << "Choose Password: ";
            cin >> pass;
            if(users.find(name) == users.end()) {
                users[name] = new NewUser(name, pass);
            } else {
                cout << "Username already exists!\n";
            }
        }
    }

    cout << "👋 Exiting Instagram Console App!\n";
    return 0;
}
