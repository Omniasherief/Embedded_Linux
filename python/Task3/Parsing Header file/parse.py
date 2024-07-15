import re
import csv

def parse_headerfile(file_path):
    
        #read function prototype
        with open(file_path,'r') as file:
           content=file.read()


           pattern=r"(?ix)\b([^\s]+)\s*\(([^)]*)\)"
           prototypes=re.findall(pattern, content)   # stores those matched parts (function prototypes) in a list for further processing.
        return prototypes

def write_excelfile (prototypes, excel_file):
 try:
        with open(excel_file, 'w') as csvfile:
            csvwriter = csv.writer(csvfile)

            csvwriter.writerow(['Function Prototype', 'Unique ID'])

            for idx, prototype in enumerate(prototypes, start=1):
                unique_id = f'IDX{idx:03d}'
                csvwriter.writerow([prototype, unique_id])

 except :
        print("Error writing to CSV file")

if __name__ == "__main__":
    #headerfile_path = '/home/omnia/EL/python/Task3/Parsing Header file/headerfile.h' 
    #csvfile = '/home/omnia/EL/python/Task3/Parsing Header file/function_prototypes.csv'
    try:
        header_file_path = input("Enter the path to the header file: ")
        output_csv_path = input("Enter the path to the output CSV file: ")

        prototypes = parse_headerfile(header_file_path)
        write_excelfile(prototypes, output_csv_path)

        print("Data successfully written to CSV file.")

    except (FileNotFoundError, ValueError) as e:
        print(f"An error occurred: {e}")
    