
import csv
import os

file_name="employees.csv"

if not os.path.exists(file_name):
    with open(file_name, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(["ID", "Name", "Job", "Salary"])




def generate_id(rows):
   if len(rows)<=1:
      return "IDX001"
   else:
       last_id=rows[-1][0]
       if last_id and last_id[3:].isdigit():
           new_id_num=int(last_id[3:])+1
           return f"IDX{new_id_num:03}"
       else:
            return "IDX001"



def display_menu():
    print("\nEmployee Management System")
    print("1. Add new employee")
    print("2. Print employee data")
    print("3. Remove employee")
    print("4. Update employee")
    print("5. Exit")



while True:
    display_menu()
    choice = input("Enter your choice: ")

    with open(file_name, mode='r', newline='') as file:
        reader = csv.reader(file)# reader object that will iterate over lines
        rows = list(reader)

    if choice == '1':
        name = input("Enter employee name: ")
        job = input("Enter employee job: ")
        salary = float(input("Enter employee salary: "))

        new_id = generate_id(rows)
        rows.append([new_id, name, job, salary])

        with open(file_name, mode='w', newline='') as file:
            writer = csv.writer(file)
            writer.writerows(rows)

        print(f"Employee '{name}' added successfully with ID {new_id}.")

    elif choice == '2':
        if len(rows) == 1:
            print("No employees found.")
        else:
            for row in rows[1:]:
                print(f"ID: {row[0]}, Name: {row[1]}, Job: {row[2]}, Salary: {row[3]}")

    elif choice == '3':
        employee_id = input("Enter employee ID to remove: ")
        found = False
        for row in rows[1:]:
            if row[0] == employee_id: # employee ID in the current row
                rows.remove(row)
                found = True
                break

        with open(file_name, mode='w', newline='') as file:
            writer = csv.writer(file)
            writer.writerows(rows)

        if found:
            print(f"Employee with ID '{employee_id}' removed successfully.")
        else:
            print(f"No employee found with ID '{employee_id}'.")

    elif choice == '4':
        employee_id = input("Enter employee ID to update: ")
        found = False
        for row in rows[1:]:
            if row[0] == employee_id:
                name = input("Enter new name (leave blank to skip): ")
                job = input("Enter new job (leave blank to skip): ")
                salary = input("Enter new salary (leave blank to skip): ")

                if name:
                    row[1] = name
                if job:
                    row[2] = job
                if salary:
                    row[3] = float(salary)
                
                found = True
                break

        with open(file_name, mode='w', newline='') as file:
            writer = csv.writer(file)
            writer.writerows(rows)

        if found:
            print(f"Employee with ID '{employee_id}' updated successfully.")
        else:
            print(f"No employee found with ID '{employee_id}'.")

    elif choice == '5':
        print("Exiting the system.")
        break

    else:
        print("Invalid choice. Please try again.")
