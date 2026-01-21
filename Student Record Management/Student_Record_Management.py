students_db = {}

def add_student():
    print("--- Add New Student ---")
    std_id = input("Enter Student ID: ")
    if std_id in students_db:
        print("Error: Student ID already exists!")
        return
    
    name = input("Enter Name: ")
    age = input("Enter Age: ")
    grade = input("Enter Grade: ")
    
    students_db[std_id] = {"name": name, "age": age, "grade": grade}
    print(f"\nStudent {name} added successfully!")

def view_students():
    print("--- Student Records ---")
    if not students_db:
        print("No records found.")
        return
    
    print(f"{'ID':<10} {'Name':<20} {'Age':<10} {'Grade':<10}")
    print("-" * 50)
    for std_id, info in students_db.items():
        print(f"{std_id:<10} {info['name']:<20} {info['age']:<10} {info['grade']:<10}")

def update_student():
    print("--- Update Student ---")
    std_id = input("Enter Student ID to update: ")
    if std_id in students_db:
        print("Leave blank to keep current value.")
        name = input(f"New Name ({students_db[std_id]['name']}): ")
        age = input(f"New Age ({students_db[std_id]['age']}): ")
        grade = input(f"New Grade ({students_db[std_id]['grade']}): ")
        
        if name: students_db[std_id]['name'] = name
        if age: students_db[std_id]['age'] = age
        if grade: students_db[std_id]['grade'] = grade
        print("Record updated!")
    else:
        print("Student ID not found.")

def delete_student():
    print("--- Delete Student ---")
    std_id = input("Enter Student ID to delete: ")
    if std_id in students_db:
        del students_db[std_id]
        print("Student record deleted.")
    else:
        print("Student ID not found.")

def main():
    while True:
        print("\n===== STUDENT RECORD SYSTEM =====")
        print("1. Add Student")
        print("2. View All Students")
        print("3. Update Student")
        print("4. Delete Student")
        print("5. Exit")
        
        choice = input("\nSelect an option (1-5): ")
        
        if choice == '1': add_student()
        elif choice == '2': view_students()
        elif choice == '3': update_student()
        elif choice == '4': delete_student()
        elif choice == '5': break
        else: print("Invalid choice, please try again.")

if __name__ == "__main__":
    main()