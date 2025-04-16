# Library Management System

**A C++ console-based LMS**  
*Developed for Computer Programming (CP) course*

## Features
- **User Roles**:
  - Admin (Password: `library123`)
  - Student (Registration required)
- **Admin Functions**:
  - View/Add/Search books
  - Manage student records
  - Track borrowed books
- **Student Functions**:
  - Browse available books
  - Borrow/Return books
  - View personal records
- **Automated Systems**:
  - Due date calculator (10-day borrow period)
  - Late return fines ($50)
  - Auto-generated student passwords

## Installation
1. **Prerequisites**:
   - C++ Compiler (GCC, MSVC, etc.)
   - Visual Studio

2. **Setup**:
   ```bash
   git clone https://github.com/naveenzk/Library-Management-System
.git
   cd Library-Management-System
   ```
3. **Required Files**:
   - `books.txt` (Already included in repo)
   - `main.cpp` (Main program file)
