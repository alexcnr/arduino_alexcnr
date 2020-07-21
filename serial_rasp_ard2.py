import serial
import re
import csv


from threading import Thread

ser = serial.Serial('/dev/ttyACM0',9600)
d = []
s2 = []

pattern = r"(\d{1,3})"

def convert_data(text):
    result = re.findall(pattern, text)
    return result
  
def receive_data():
    data = ser.readline()  #read data from serial
    print(data)
    if data:
        strdata = str(data)
        #print(strdata)

        return strdata
n = 0
limit = 30

while n < limit:
    n += 1 
    strdata = receive_data()
    rez = convert_data(strdata)
    d.append(rez)

print(d)
    
with open("result_file.csv", 'w+') as output_file:
    writer = csv.writer(output_file)
    writer.writerows(d)
    output_file.close()



    

