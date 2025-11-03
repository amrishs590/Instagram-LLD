# 📱 Instagram Console Application (C++)

**Instagram Console App** is a mini console-based social networking application built using **C++**.  
It simulates the core functionalities of Instagram — such as **account creation**, **login**, **follow/unfollow**, and **profile viewing** — all within a simple text-based interface.  

This project demonstrates the use of **Object-Oriented Programming (OOP)** principles in C++ such as **classes**, **encapsulation**, **data structures (vectors, maps)**, and **static functions**.

---

## 🚀 Features

- 👤 **User Account System**
  
  - Create a new user account with a unique username and password  
  - Login authentication using stored credentials  

- 🔗 **Follow / Unfollow Functionality**
  
  - Follow other users and increase following count  
  - Unfollow existing users easily  

- 👥 **Profile View**
  
  - Display followers and following lists  
  - Shows live count of followers and following  

- 🔒 **Basic Validation**
  
  - Prevents users from following themselves  
  - Handles duplicate follows, unfollows, and invalid users gracefully  

- 💾 **In-Memory Storage**
  
  - Uses STL containers like `unordered_map` and `vector` to store users and relationships  

---

## 🧩 Tech Stack

| Layer | Technology Used |
|--------|------------------|
| **Programming Language** | C++ |
| **Libraries Used** | `<bits/stdc++.h>`, STL (`vector`, `unordered_map`, `find`) |
| **Paradigm** | Object-Oriented Programming (OOP) |
| **Environment** | Console Application |
| **Compiler (Recommended)** | g++ / MinGW / GCC |
| **IDE (Optional)** | VS Code / Code::Blocks / CLion |

---

## 🗂️ Class Structure

### `class NewUser`
    Represents each registered user and stores:
    - `userId`, `userName`, `userPassword`
    - Number of followers & following
    - Lists of followers and following usernames  

**Key Methods:**
  - `follow(NewUser* other)` – Follow another user  
  - `unfollow(NewUser* other)` – Unfollow a user  
  - `viewProfile()` – Display current user’s profile  
  - `static login()` – Authenticate existing user  

---

## ⚙️ How It Works

1. Run the program in terminal or IDE.
   
2. Choose:
   - **1 → Login**
   - **2 → Create Account**
   - **3 → Exit**
     
3. Once logged in, users can:
   - Follow or unfollow other users  
   - View their own profile  
   - Logout anytime  

All actions are displayed in real-time using console output.

---

