import csv

with open('what.csv') as file:
    reader = csv.DictReader(file, delimiter=";")
    for line_dict in reader:
        Old_price = int(line_dict['Old price'])
        New_price = int(line_dict['New price'])
        if Old_price > New_price:
            print(f'{line_dict["Name"]}')
            